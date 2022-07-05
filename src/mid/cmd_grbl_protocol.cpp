#include "cmd_grbl_protocol.h"


grbl_cmd_t grbl_cmd;
extern SEND_STATE_TYPE_t cur_send_state;
char public1_buff[60];
char public2_buff[60];
char public3_buff[60];

#define LINE_BUFFER_SIZE 1024
static char    line[LINE_BUFFER_SIZE];     // Line to be executed. Zero-terminated.

typedef struct {
    char buffer[LINE_BUFFER_SIZE];
    int  len;
    int  line_number;
} client_line_t;
client_line_t client_lines[CLIENT_COUNT];

static void empty_line(uint8_t client) {
    client_line_t* cl = &client_lines[client];
    cl->len           = 0;
    cl->buffer[0]     = '\0';
}

static void empty_lines() {
    for (uint8_t client = 0; client < CLIENT_COUNT; client++) {
        empty_line(client);
    }
}

Error add_char_to_line(char c, uint8_t client) {
    client_line_t* cl = &client_lines[client];
    // Simple editing for interactive input
    if (c == '\b') {
        // Backspace erases
        if (cl->len) {
            --cl->len;
            cl->buffer[cl->len] = '\0';
        }
        return Error::Ok;
    }
    if (cl->len == (LINE_BUFFER_SIZE - 1)) {
        return Error::Overflow;
    }
    if (c == '\r' || c == '\n') {
        cl->len = 0;
        cl->line_number++;
        return Error::Eol;
    }
    cl->buffer[cl->len++] = c;
    cl->buffer[cl->len]   = '\0';
    return Error::Ok;
}

void grbl_protocol_main_loop(void) {

    empty_lines();

    // debug_line_received("loop\n", CLIENT_SERIAL);
    // Uart0.write("loop\n");
    int c;
    
    for(;;) {

        uint8_t client = CLIENT_SERIAL;
        char*   line;

        for (client = 0; client < CLIENT_COUNT; client++) {
            while ((c = client_read(client)) != -1) {

                Error res = add_char_to_line(c, client);

                switch (res) {
                    case Error::Ok:
                        break;
                    case Error::Eol:

                        line = client_lines[client].buffer;
#ifdef DEBUG_MODE
                        debug_line_received(line, CLIENT_SERIAL);
#endif
                        /* 指令解析在这里,基于事件驱动 */
                        excute_grbl_report_back(line);

                        empty_line(client);
                        break;
                    case Error::Overflow:
                        empty_line(client);
                        break;
                    default:
                        break;
                }
            }  // while serial read
        }      // for clients
    }
}


char* normalize_key(char* start) {
    char c;

    // In the usual case, this loop will exit on the very first test,
    // because the first character is likely to be non-white.
    // Null ('\0') is not considered to be a space character.
    while (isspace(c = *start) && c != '\0') {
        ++start;
    }

    // start now points to either a printable character or end of string
    if (c == '\0') {
        return start;
    }

    // Having found the beginning of the printable string,
    // we now scan forward until we find a space character.
    char* end;
    for (end = start; (c = *end) != '\0' && !isspace(c); end++) {}

    // end now points to either a whitespace character of end of string
    // In either case it is okay to place a null there
    *end = '\0';

    return start;
}


uint16_t is_grbl_error(char *line) {

    

    return 255;
}

// static void excute_event_wait_ok() {

// }
void event_ok_the_pre_mode()
{
    switch (grbl_cmd.grbl_rec_mode)
    {
    case REC_SD_LIST:
        sd_content.gain_all_name = true;
        // for(int i = 0; i < 7;i++)
        // {
        //     serial_sendf(CLIENT_SERIAL, "file %d %s %s\n", sd_content.filetype[i],sd_content.filename[i],sd_content.filesize[i]);
        // }
        break;
    case REC_POS:
        grbl_cmd.grbl_flag.is_connect = true;
        break;
    // case REC_OPEN_FILE:
    //     sd_content.open_file_flag = true;
    //     break;
    default:
        break;
    }
}
void excute_event_wait_error(char *line)
{
        memset(public2_buff,0,sizeof(public2_buff));
        char *p = public2_buff;
        bool flag = false;

        if(strstr(line,"error"))
        {
            flag = true;
        }
        if(flag)
        {
            while (*line != '\0')
            {
                if(*line >= 48 && *line < 58)
                {
                    *p++ = *line;
                }
                line++;
            }
            serial_sendf(CLIENT_SERIAL,"ErrorCode %s\n",public2_buff);
            grbl_cmd.grbl_rec_mode = REC_IDLE;
            grbl_cmd.grbl_event = GRBL_EVENT_EMPTY;
            cur_send_state = SEND_IDLE;
        }

        
        
}


void excute_event_wait_ok(char *line)
{
    if(grbl_cmd.grbl_event == GRBL_EVENT_WAIT_OK)
    {
        if(!strcmp(line,"ok"))
        {
            event_ok_the_pre_mode();
            grbl_cmd.grbl_rec_mode = REC_IDLE;
            grbl_cmd.grbl_event = GRBL_EVENT_EMPTY;
            cur_send_state = SEND_IDLE;
        }
    }
}
/*
功能：获取到grbl工作模式
参数：*data
返回：true 成功 
      false 失败
*/
bool get_grbl_mode(char *data)    
{
    // serial_sendf(CLIENT_SERIAL,"mode %s\n",data);

    if(strcmp(data,"Idle") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_IDLE;
    }
    else if(strcmp(data,"Run") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_RUN;
    }
    else if(strcmp(data,"Hold:0") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_HOLD;
    }
    else if(strcmp(data,"Hold:1") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_HOLD;
    }
    else if(strcmp(data,"Jog") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_JOG;
    }
    else if(strcmp(data,"Home") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_HOME;
    }
    else if(strcmp(data,"Alarm") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_ALARM;
    }
    else if(strcmp(data,"Check") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_CHECK;
    }
    else if(strcmp(data,"Door:0") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_DOOR;
    }
    else if(strcmp(data,"Door:1") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_DOOR;
    }
    else if(strcmp(data,"Door:2") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_DOOR;
    }
    else if(strcmp(data,"Door:3") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_DOOR;
    }
    else if(strcmp(data,"Sleep") == 0)
    {
        grbl_cmd.grbl_mode = GRBL_SLEEP;
    }
    else
    {
        return false;
    }
    return true;
}
uint16_t get_grbl_basic_data_type(char *data)
{
    if(strcmp(data,"MPos") == 0)
    {
        return GRBL_MPOS;
    }
    else if(strcmp(data,"FS") == 0)
    {
        return GRBL_FS;
    }
    else if(strcmp(data,"Pn") == 0)
    {
        return GRBL_PN;
    }
    else if(strcmp(data,"WCO") == 0)
    {
        return GRBL_WCO;
    }
    else if(strcmp(data,"Ov") == 0)
    {
        return GRBL_OV;
    }
    else if(strcmp(data,"SD") == 0)
    {
        return GRBL_SD;
    }
}
void get_pin_state(char *data)
{
    grbl_cmd.grbl_basic_info.pin_state = 0;
    uint16_t   counter= 0;
    /*
    0000 0000 0000 0000
    4321 0SHR DCBA ZYXP
    */
    while (*data != '\0')
    {
        switch (*data)
        {
        case 'P':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 0);
            break;
        case 'X':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 1);
            break;
        case 'Y':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 2);
            break;
        case 'Z':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 3);
            break;
        case 'A':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 4);
            break;
        case 'B':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 5);
            break;
        case 'C':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 6);
            break;
        case 'D':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 7);
            break;
        case 'R':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 8);
            break;
        case 'H':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 9);
            break;
        case 'S':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 10);
            break;
        case '0':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 11);
            break;
        case '1':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 12);
            break;
        case '2':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 13);
            break;
        case '3':
            grbl_cmd.grbl_basic_info.pin_state |= (1 << 14);
            break;
        default:
            break;
        }
        data++;
    }

    // serial_sendf(CLIENT_SERIAL,"state %d\n",grbl_cmd.grbl_basic_info.pin_state);
    
}
void get_grbl_basic_data_num(char *data,uint16_t type,uint16_t num)
{
    // serial_sendf(CLIENT_SERIAL,"num %d\n",num);
    char buff[50];
    memset(buff,0,sizeof(buff));
    strcpy(buff,data);
    // serial_sendf(CLIENT_SERIAL,"buff %s\n",buff);
    switch (type)
    {
    case GRBL_MPOS:
        if(num == 0)
        {
            grbl_cmd.grbl_basic_info.x_m_pos = strtof(buff,NULL);
            // serial_sendf(CLIENT_SERIAL,"XX %s %.2f\n",data,grbl_cmd.grbl_basic_info.x_m_pos);
        }
        else if(num == 1)
        {
            grbl_cmd.grbl_basic_info.y_m_pos = strtof(buff,NULL);
            // serial_sendf(CLIENT_SERIAL,"YY %s %.2f\n",data,grbl_cmd.grbl_basic_info.y_m_pos);
        }
        else if(num == 2)
        {
            grbl_cmd.grbl_basic_info.z_m_pos = strtof(buff,NULL);
            // serial_sendf(CLIENT_SERIAL,"ZZ %s %.2f\n",data,grbl_cmd.grbl_basic_info.z_m_pos);
        }
        else if(num == 3)
        {
            grbl_cmd.grbl_basic_info.a_m_pos = strtof(buff,NULL);
            // serial_sendf(CLIENT_SERIAL,"AA %s %.2f\n",data,grbl_cmd.grbl_basic_info.a_m_pos);
        }
        break;
    case GRBL_FS:
        if(num == 0)
        {
            grbl_cmd.grbl_basic_info.current_speed = atoi(buff);
            // serial_sendf(CLIENT_SERIAL,"CUR %s %d\n",data,grbl_cmd.grbl_basic_info.current_speed);
        }
        else if(num == 1)
        {
            grbl_cmd.grbl_basic_info.spindle_speed = atoi(buff);
            // serial_sendf(CLIENT_SERIAL,"SPI %s %d\n",data,grbl_cmd.grbl_basic_info.spindle_speed);
        }
        break;
    case GRBL_PN:
        if(num == 0)
        {
            // grbl_cmd.grbl_basic_info.current_speed = atoi(buff);
            // serial_sendf(CLIENT_SERIAL,"PN %s\n",data);
            get_pin_state(data);
        }
        break;
    case GRBL_WCO:
        if(num == 0)
        {
            grbl_cmd.grbl_basic_info.x_w_pos = strtof(buff,NULL);
            // serial_sendf(CLIENT_SERIAL,"XX %s %.2f\n",data,grbl_cmd.grbl_basic_info.x_w_pos);
        }
        else if(num == 1)
        {
            grbl_cmd.grbl_basic_info.y_w_pos = strtof(buff,NULL);
            // serial_sendf(CLIENT_SERIAL,"YY %s %.2f\n",data,grbl_cmd.grbl_basic_info.y_w_pos);
        }
        else if(num == 2)
        {
            grbl_cmd.grbl_basic_info.z_w_pos = strtof(buff,NULL);
            // serial_sendf(CLIENT_SERIAL,"ZZ %s %.2f\n",data,grbl_cmd.grbl_basic_info.z_w_pos);
        }
        else if(num == 3)
        {
            grbl_cmd.grbl_basic_info.a_w_pos = strtof(buff,NULL);
            // serial_sendf(CLIENT_SERIAL,"AA %s %.2f\n",data,grbl_cmd.grbl_basic_info.a_w_pos);
        }
        break;
    case GRBL_OV:
        if(num == 0)
        {
            grbl_cmd.grbl_basic_info.f_override = atoi(buff);
            // serial_sendf(CLIENT_SERIAL,"f %s %d f\n",data,grbl_cmd.grbl_basic_info.f_override);
        }
        else if(num == 1)
        {
            grbl_cmd.grbl_basic_info.r_override = atoi(buff);
            // serial_sendf(CLIENT_SERIAL,"r %s %d r\n",data,grbl_cmd.grbl_basic_info.r_override);
        }
        else if(num == 2)
        {
            grbl_cmd.grbl_basic_info.spindle_speed_ovr = atoi(buff);
            // serial_sendf(CLIENT_SERIAL,"ovr %s %d ovr\n",data,grbl_cmd.grbl_basic_info.spindle_speed_ovr);
        }
        break;
    case GRBL_SD:
        if(num == 0)
        {
            grbl_cmd.grbl_basic_info.per_val = strtof(buff,NULL);
            // serial_sendf(CLIENT_SERIAL,"per %s %.2f\n",data,grbl_cmd.grbl_basic_info.per_val);
            // serial_sendf(CLIENT_SERIAL,"f %s %d f\n",data,grbl_cmd.grbl_basic_info.f_override);
        }
        if(num == 1)
        {
            // grbl_cmd.grbl_basic_info.per_val = atoi(buff);
            memset(grbl_cmd.grbl_basic_info.print_fname,0,sizeof(grbl_cmd.grbl_basic_info.print_fname));
            strcpy(grbl_cmd.grbl_basic_info.print_fname,buff);
        }
    break;
    default:
        break;
    }
}
            

bool get_grbl_basic_data(char *line)
{
    memset(public2_buff,0,sizeof(public2_buff));
    char *p = public2_buff;
    uint16_t counter = 0;
    uint16_t type;
    while(*line != '\0')
    {
        if(*line == ':')
        {
            line++;
            *p = '\0';
            // serial_sendf(CLIENT_SERIAL,"pos %s\n",public2_buff);
            type = get_grbl_basic_data_type(public2_buff);
            memset(public2_buff,0,sizeof(public2_buff));
            p = public2_buff;
        }
        if(*line == ',')
        {
            line++;
            *p = '\0';
            // serial_sendf(CLIENT_SERIAL,"num %s\n",public2_buff);
            get_grbl_basic_data_num(public2_buff,type,counter);
            memset(public2_buff,0,sizeof(public2_buff));
            p = public2_buff;
            counter++;
        }
        if(*line == '#')
        {
            line++;
            *p = '\0';
            get_grbl_basic_data_num(public2_buff,type,counter);
            // serial_sendf(CLIENT_SERIAL,"num %s\n",public2_buff);
            memset(public2_buff,0,sizeof(public2_buff));
            memset(public1_buff,0,sizeof(public1_buff));
            break;
        }
        
        *p++ = *line;
        line++;
    }

}
void get_xyz_pos(char *line)
{
    char *p = NULL;
    bool mode_flag = false;
    memset(public1_buff,0,sizeof(public1_buff));
    p = public1_buff;
    while(*line != '\0')
    {
        if(*line == '<')
        {
          line++;
        }
        if(*line == '|' || *line == '>')
        {
            if(!mode_flag)
            {
                *p = '\0';
                mode_flag = true;
                if(get_grbl_mode(public1_buff))
                {
                    // serial_sendf(CLIENT_SERIAL,"mode %d\n",grbl_cmd.grbl_mode);
                    memset(public1_buff,0,sizeof(public1_buff));
                    p = public1_buff;
                }
                else
                {
                    serial_send(CLIENT_SERIAL,"error: grbl mode!\n");
                }
            }
            else
            {
                *p++ = '#';
                *p = '\0';
                // serial_sendf(CLIENT_SERIAL,"ls %s\n",public1_buff);
                get_grbl_basic_data(public1_buff);
                memset(public1_buff,0,sizeof(public1_buff));
                p = public1_buff;
            }
            line++;
        }
        *p++ = *line;
        line++;
    }
}

void excute_grbl_report_back(char *line) {

/*********************************
 * step1:
 * 
**********************************/
    excute_event_wait_ok(line);
    excute_event_wait_error(line);
    if(grbl_cmd.grbl_rec_mode == REC_SD_LIST)
    {
        get_sd_filename(line);  
    }
    else if(grbl_cmd.grbl_rec_mode == REC_POS)
    {
        get_xyz_pos(line);  
    }
}


void grbl_connect_task(void *parg) {

    while(1) {
        // MKS_PICO_CMD_SEND("?\n");
        delay(500);  // 500ms 
    }
}

#define DISP_TASK_STACK                 4096
#define DISP_TASK_PRO                   2
#define DISP_TASK_CORE                  1

TaskHandle_t grbl_connect_task_tcb = NULL;

void grbl_parg_task_init() {

    xTaskCreatePinnedToCore(grbl_connect_task,     // task
                            "grbl connect task",         // name for task
                            DISP_TASK_STACK,    // size of task stack
                            NULL,               // parameters
                            DISP_TASK_PRO,      // priority
                            // nullptr,
                            &grbl_connect_task_tcb,
                            DISP_TASK_CORE      // must run the task on same core
                                                // core
    );
}