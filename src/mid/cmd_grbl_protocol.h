#pragma once

#include "../main.h"
#include "error.h"

/***************************************
 * 用于确定会触发的事件
 * ************************************/
typedef enum {
    GRBL_EVENT_EMPTY,               // 无事件需要等待
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
    GRBL_ALAMR_LOCK,                    // GRBL上锁，需要发送￥$X解锁
}grbl_alarm_t;


/*****************************************************************
 * 这个结构体用于保存GRBL的标志
 * -is_connect          // 用于检测是否连接上GRBL
 * -is_had_ask          // 用于问号的应答检测
 * -is_had_ok           // 用于检测发送指令后，是否有OK返回
 * 
 * default:false        // 所有参数在上电时默认都是false
 * **************************************************************/
typedef struct {
    bool is_connect = false;                    
    bool is_had_ask = false;                    
    bool is_had_ok = false;                     
}grbl_flag_t;


typedef struct {
    uint32_t x_m_pos;
    uint32_t y_m_pos;
    uint32_t z_m_pos;
    uint32_t a_m_pos;

    uint32_t x_w_pos;
    uint32_t y_w_pos;
    uint32_t z_w_pos;
    uint32_t a_w_pos;

}grbl_parg_t;


/*****************************************************************
 * 这个值用来限制gcode数量
 * **************************************************************/
#define OK_LIMT_NUM         5

/*****************************************************************
 * 这个结构体用于解析Gcode返回来的数据
 * - 使用事件驱动类型，忽略发送顺序
 * **************************************************************/
typedef struct {
    grbl_event_t    grbl_event;                     // GRBL需要等待的事件
    grbl_mode_t     grbl_mode;                      // GRBL当前机器执行的模式
    grbl_err_t      grbl_error;                     // GRBL的报错类型
    grbl_flag_t     grbl_flag;                      // GRBL连接过程返回标志           
    char            send_grbl_cmd[96];              // GRBL的指令从这里发出
    char            get_grbl_cmd[255];              // GRBL返回的指令从这里解析 
}grbl_cmd_t;
extern grbl_cmd_t grbl_cmd;

/*****************************************************************
 *                Function
 * **************************************************************/
void grbl_protocol_main_loop(void);
char* normalize_key(char* start);
void excute_grbl_report_back(char *line);
