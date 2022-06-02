#include "cmd_grbl_protocol.h"


grbl_cmd_t grbl_cmd;

#define LINE_BUFFER_SIZE 256
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

static void excute_event_wait_ok() {

}


void excute_grbl_report_back(char *line) {

/*********************************
 * step1:
 * 
**********************************/

}








void grbl_connect_task(void *parg) {

    while(1) {
        
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