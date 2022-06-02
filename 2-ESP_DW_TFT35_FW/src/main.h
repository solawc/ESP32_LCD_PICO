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

#include <driver/rmt.h>
#include <esp_task_wdt.h>
#include "esp32-hal.h"
#include <driver/timer.h>

#include "vantins.h"
#include "bsp_lcd/tft_lcd_35.h"
#include "bsp_lcd/FT6336U.h"

#include "hal/hal_uart.h"
#include "hal/hal_wdt.h"
#include "hal/hal_info.h"

#include "mid/serial.h"
#include "mid/report.h"
#include "mid/input_buffer.h"
#include "mid/settings.h"
#include "mid/setttingDefinitions.h"
#include "mid/cmd_grbl_protocol.h"
#include "mid/cmd_protocol.h"
#include "mid/error.h"

#include "lvgl.h"
#include "lv_ui/font_pic.h"
#include "lv_ui/draw_test.h"
#include "lv_ui/tft_lvgl_configurate.h"
#include "lv_ui/draw_ui.h"
#include "lv_ui/draw_logo.h"
#include "lv_ui/draw_home.h"
#include "lv_ui/draw_style.h"
#include "lv_ui/draw_control.h"

#endif
