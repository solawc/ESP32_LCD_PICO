/****************************************************************
 *                      Include
****************************************************************/
#include "cmd_protocol.h"



/****************************************************************
 *                      grbl_cmd_send
****************************************************************/
void grbl_cmd_send(uint8_t client, const char *text) {
    send_cmd(client, text);
}


/****************************************************************
 *                      grbl_send_run
****************************************************************/
void grbl_send_run(uint8_t client, const char *text) {

    // 检测当前事件是否为空
    if(grbl_cmd.grbl_event != GRBL_EVENT_EMPTY) return;  

    grbl_cmd.grbl_event = GRBL_EVENT_WAIT_OK;

    grbl_cmd_send(client, text);
}





