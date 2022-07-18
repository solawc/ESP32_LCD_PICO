#pragma once

#include "../main.h"
#include "../vantins.h"
#include <freertos/FreeRTOS.h>

typedef enum{
    SEND_WAIT,
    SEND_IDLE,
}SEND_STATE_TYPE_t;

typedef struct{
    uint32_t start_time;
    uint32_t end_time;
    uint32_t check_time;
}SEND_OVERTIME_t;

extern SEND_OVERTIME_t send_overtime;



void serila_write_send_buffer(uint8_t *data);
void send_buffer_out_serila();
void send_data_analysis();
void send_buff_init();
void send_overtime_init();
void send_overtime_check();

#define MKS_PICO_CMD_SEND(A)            serila_write_send_buffer((uint8_t *)A)   

