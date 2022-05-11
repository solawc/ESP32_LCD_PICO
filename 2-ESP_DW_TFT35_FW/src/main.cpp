#include "main.h"


void app_task_init(void) {

    // 初始化串口， 开启串口任务
    client_init();

    // task init lvgl
    lvgl_task_init();
}

void setup() {

    wdt_set_disable();

    // tunr off the lcd and wait the logo is OK
    tft_backlight_disable(); 

    tft_TS35_init();

    app_task_init();

    // int test
    lv_draw_test();

    // turn on the lcd and finish Init
    tft_backlight_enable();
}

void loop() {
    // lv_task_handler();
    // delay(5);
}



