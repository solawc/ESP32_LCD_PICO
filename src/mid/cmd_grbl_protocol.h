#pragma once

#include "../main.h"
#include "error.h"

/***************************************
 * 用于确定会触发的事件
 * ************************************/
typedef enum {

    GRBL_EVENT_WAIT_OK,             // 等待返回OK
    GRBL_EVENT_CHECK,               // 等待"?"返回的信息
    GRBL_EVENT_INFO,                // 等待$I的返回信息

}grbl_event_t;


/***************************************
 * 用于描述GRBL的机器状态
 * ************************************/
typedef enum {

    GRBL_IDLE,
    GRBL_RUN,
    GRBL_HOLD,
    GRBL_JOG,
    GRBL_HOME,
    GRBL_ALARM,
    GRBL_CHECK,
    GRBL_DOOR,
    GRBL_SLEEP,

}grbl_mode_t;

/***************************************
 * 用于描述GRBL的机器返回的错误
 * ************************************/
typedef enum {
   GRBL_BAD_GCODE_FORMAT,
   GRBL_SETTING_DISABLE,
   GRBL_NEGATIVE_VALUE,
   GRBL_SETTING_PLUSE_MIN,
   GRBL_FALT_TO_READ_SETTINGS,
}grbl_err_t;

typedef enum {
    


}grbl_alarm_t;

/*********************************************
 * 这个值用来限制gcode数量
 * ******************************************/
#define OK_LIMT_NUM         5

/*********************************************
 * 这个结构体用于解析Gcode返回来的数据
 * - 使用事件驱动类型，忽略发送顺序
 * ******************************************/
typedef struct {
    grbl_event_t    grbl_event;
    grbl_mode_t     grbl_mode;
    grbl_err_t      grbl_error;

    bool            is_connect = false;            // 用于标志GRBL是否已经连接上 

    uint8_t         recive_ok_num;

    char            send_grbl_cmd[96];             // GRBL的指令从这里发出
    char            get_grbl_cmd[255];             // GRBL返回的指令从这里解析 
}grbl_cmd_t;


/*********************************************
 *                Function
 * ******************************************/

void grbl_protocol_main_loop(void);

char* normalize_key(char* start);

void excute_grbl_report_back(char *line);
