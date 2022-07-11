#include "serial_cmd_send.h"

static TaskHandle_t clientSendTaskHandle = 0;
portMUX_TYPE mysMutex = portMUX_INITIALIZER_UNLOCKED;


WebUI::InputBuffer send_buffer;  // create a buffer for each client
SEND_STATE_TYPE_t cur_send_state = SEND_IDLE;

SEND_OVERTIME_t send_overtime;
 
static char send_buff[20];
static bool flag = false;
void send_data_com_and_state_chang(char *line);
void clientSendTask(void* pvParameters) {
    
    while (true) {  // run continuously
        send_buffer_out_serila();
        vTaskDelay(1 / portTICK_RATE_MS);  // Yield to other tasks
    }
}

void send_buff_init()
{
    send_buffer.begin();
    memset(send_buff,0,sizeof(send_buff));;
    xTaskCreatePinnedToCore(clientSendTask,    // task
                            "clientCheckTask",  // name for task
                            2048,               // size of task stack
                            NULL,               // parameters
                            1,                  // priority
                            &clientSendTaskHandle,
                            SUPPORT_TASK_CORE  // must run the task on same core
                                               // core
    );

}
void serila_write_send_buffer(uint8_t *data)
{
    vTaskEnterCritical(&mysMutex);
    send_buffer.push((const char *)data);
    vTaskExitCritical(&mysMutex);
}

void send_buffer_out_serila()
{
    if(cur_send_state == SEND_IDLE)
    {
        // serial_send(CLIENT_SERIAL,"sd list1\n");
        if(send_buffer.available() > 0)
        {
            // serial_send(CLIENT_SERIAL,"sd list2\n");
            send_data_analysis();
        }
        else
        {

        }
    }
    else
    {
        // serial_send(CLIENT_SERIAL,"Serial port sending busy, please wait\n");
    }
}

void send_data_analysis()
{
    static char *str_p = send_buff;
    char c = send_buffer.read();
    if(c == '\n')
    {
            *str_p++ = '\n';
            *str_p = '\0';
            flag = false;
            send_data_com_and_state_chang(send_buff);
            // serial_sendf(CLIENT_SERIAL_LCD,"%s\n",send_buff);
            // serial_sendf(CLIENT_SERIAL,"%s\n",send_buff);
            serial_send(CLIENT_SERIAL_LCD,send_buff);
            serial_send(CLIENT_SERIAL,send_buff);
            send_overtime_init();
            send_overtime.start_time = millis();
            memset(send_buff,0,sizeof(send_buff));
            str_p = send_buff;
    }
    else
    {
        *str_p++ = c;
    }
    // static char *str_p = send_buff;
    // char c = send_buffer.read();
    // // serial_sendf(CLIENT_SERIAL,"%c\n",c);
    // if(c == '[')
    // {
    //     flag = true;
    // }
    // if(c == ']')
    // {
    //     *str_p++ = c;
    //     flag = false;
    //     cur_send_state = SEND_WAIT;
    //     send_data_com_and_state_chang(send_buff);
    //     serial_sendf(CLIENT_SERIAL_LCD,"%s\n",send_buff);
    //     memset(send_buff,0,sizeof(send_buff));;
    //     str_p = send_buff;
    //     }
    // if(flag)
    // {
    //     *str_p++ = c;
    // }
}

void send_data_com_and_state_chang(char *line)
{
    if(!strcmp(line,"[ESP210]\n"))
    {
        sd_content.file_num = 0;
        sd_content.gain_all_name = false;
        cur_send_state = SEND_WAIT;
        grbl_cmd.grbl_event = GRBL_EVENT_WAIT_OK;
        grbl_cmd.grbl_rec_mode = REC_SD_LIST;
    }
    else if(!strcmp(line,"?\n"))
    {
        cur_send_state = SEND_WAIT;
        grbl_cmd.grbl_event = GRBL_EVENT_WAIT_OK;
        grbl_cmd.grbl_rec_mode = REC_POS;
        // serial_send(CLIENT_SERIAL,"hipp\n");
    }
    else if(strstr(line,"$J=G91"))
    {
        cur_send_state = SEND_WAIT;
        grbl_cmd.grbl_event = GRBL_EVENT_WAIT_OK;
        grbl_cmd.grbl_rec_mode = REC_MOVE;
        // serial_send(CLIENT_SERIAL,"hipp\n");
    }
    else if(!strcmp(line,"!\n"))
    {
        serial_send(CLIENT_SERIAL,"hipp\n");
        cur_send_state = SEND_WAIT;
        grbl_cmd.grbl_event = GRBL_EVENT_WAIT_OK;
        grbl_cmd.grbl_rec_mode = REC_PAUSE;
    }
    else if(!strcmp(line,"~\n"))
    {
        
        cur_send_state = SEND_WAIT;
        grbl_cmd.grbl_event = GRBL_EVENT_WAIT_OK;
        grbl_cmd.grbl_rec_mode = REC_CONTINUE;
    }
    else
    {
        cur_send_state = SEND_WAIT;
        grbl_cmd.grbl_event = GRBL_EVENT_WAIT_OK;
        grbl_cmd.grbl_rec_mode = REC_IDLE;
    }
    // else if(strstr(line,"[ESP220]"))
    // {
    //     cur_send_state = SEND_WAIT;
    //     grbl_cmd.grbl_event = GRBL_EVENT_WAIT_OK;
    //     grbl_cmd.grbl_rec_mode = REC_OPEN_FILE;
    //     // serial_send(CLIENT_SERIAL,"hipp\n");
    // }
}

void send_overtime_init()
{
    send_overtime.end_time = 0;
    send_overtime.start_time = 0;
}

void event_overtime_the_pre_mode()
{
    switch (grbl_cmd.grbl_rec_mode)
    {
    case REC_SD_LIST:

        break;
    case REC_POS:
        grbl_cmd.grbl_flag.is_connect = false;
        break;
    default:
        break;
    }
}

void send_overtime_check()
{
    send_overtime.check_time++;
    if(send_overtime.check_time > 3)
    {
        send_overtime.end_time = millis();
        if(send_overtime.end_time - send_overtime.start_time >= 10000)
        {
            event_overtime_the_pre_mode();
            cur_send_state = SEND_IDLE;
            grbl_cmd.grbl_event = GRBL_EVENT_EMPTY;
            grbl_cmd.grbl_rec_mode = REC_IDLE;
        }
        send_overtime.check_time = 0;
    }

}
