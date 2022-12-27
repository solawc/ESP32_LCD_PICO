#ifndef __main_h
#define __main_h

#define DEBUG_MODE
#ifdef DEBUG_MODE
    // #define DEBUG_TASK_STACK
#endif

#include <Arduino.h>

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

#include <SPI.h>

#include "CommonMarco.h"

#include <driver/rmt.h>
#include <esp_task_wdt.h>
#include "esp32-hal.h"
#include <driver/timer.h>

#include "vantins.h"
#include "bsp_lcd/tft_lcd.h"
#include "bsp_lcd/FT6336U.h"

#include "hal/hal_uart.h"
#include "hal/hal_wdt.h"
#include "hal/hal_info.h"
#include "hal/hal_sdcard.h"

#include "mid/serial.h"
#include "mid/report.h"
#include "mid/input_buffer.h"
#include "mid/settings.h"
#include "mid/setttingDefinitions.h"
#include "mid/cmd_grbl_protocol.h"
#include "mid/cmd_protocol.h"
#include "mid/error.h"

#include "lvgl.h"
#include "lv_ui/tft_lvgl_configurate.h"
#include "lv_ui/lv_port/lv_port_init.h"

#endif
