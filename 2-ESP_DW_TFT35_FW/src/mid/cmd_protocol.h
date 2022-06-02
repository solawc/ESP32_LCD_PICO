#pragma once

#include "main.h"

typedef enum {

    X_AXIS,
    Y_AXIS,
    Z_AXIS,

    // for GRBL
    A_AXIS,
    B_AXIS,
    C_AXIS, 
    D_AXIS,

    // for 3D printer
    E0_AXIS,
    // E1_AXIS,
    // E2_AXIS,
}axix_t;

// 获取当前打印机状态
typedef enum {

    GC_OK,
    GC_MC_IS_BUSY,

}gc_report_t;

typedef enum {
    GRBL_IDLE,
    GRBL_ALARM,
    GRBL_CHECK_MODE,
    GRBL_HOMING,
    GRBL_CYCLE,
    GRBL_HOLD,
    GRBL_JOG,
    GRBL_SAFEDOOR,
    GRBL_SLEEP,
}gc_grbl_status_t;

typedef enum {

    MARLIN_RUN,
    MARLIN_BUSY,

}gc_marlin_status_t;


typedef struct {

    axix_t                  axis;                       // 用于选择轴控制
    gc_report_t             gc_report;                  // 用于检测gcode返回信息报错类型
    gc_grbl_status_t        grbl_status;                // 用于GRBL状态检测
    
    uint8_t gcode_send_buff[96];
    uint8_t gcode_receive_buff[255];
}gcode_cmd_t;


void grbl_cmd_send(uint8_t client, const char *text);