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

typedef enum {
    GRBL_MPOS,
    GRBL_FS,
    GRBL_PN,
    GRBL_WCO,
    GRBL_OV,
    GRBL_SD,
};

typedef enum {

}grbl_error_code_t;

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
 * 发送指令后对接收指令的筛选
 * ************************************/
typedef enum {
    REC_IDLE,
    REC_SD_LIST,
    REC_POS,
    REC_MOVE,
    REC_OPEN_FILE,
    REC_PAUSE,
    REC_CONTINUE,

}grbl_rec_mode_t;

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
    float x_m_pos = 1;
    float y_m_pos = 1;
    float z_m_pos = 1;
    float a_m_pos = 1;

    float x_w_pos = 1;
    float y_w_pos = 1;
    float z_w_pos = 1;
    float a_w_pos = 1;
    float per_val;

    uint32_t current_speed;
    uint32_t spindle_speed;
    uint32_t f_override;
    uint32_t r_override;
    uint32_t spindle_speed_ovr;
    int16_t pin_state;
    char print_fname[60];

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
    grbl_rec_mode_t     grbl_rec_mode;              // GRBL发送指令后对接收指令的筛选
    grbl_error_code_t   grbl_error_code;
    grbl_parg_t     grbl_basic_info;                // GRBL的基本信息
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

extern char public1_buff[60];
extern char public2_buff[60];
extern char public3_buff[60];