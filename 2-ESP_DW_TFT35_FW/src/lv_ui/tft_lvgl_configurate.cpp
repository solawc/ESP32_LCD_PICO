#include "tft_lvgl_configurate.h"

#define LV_BUF_SIZE             10 * LV_HOR_RES_MAX
static lv_disp_buf_t    disp_buf;
static lv_color_t       bmp_public_buf[LV_BUF_SIZE];
static lv_color_t       bmp_private_buf1[LV_BUF_SIZE]; 

#define DISP_TASK_STACK                 4096*2
#define DISP_TASK_PRO                   2
#define DISP_TASK_CORE                  1

TaskHandle_t lv_disp_tcb = NULL;

/* Function */
void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);
bool my_indev_touch(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data);

void lvgl_freertos_task(void *parg);

void lvgl_task_init(void) {

    lv_init();
    lv_disp_buf_init(&disp_buf, bmp_public_buf, bmp_private_buf1, LV_BUF_SIZE); // Initialize the display buffer

    /* display driver register */
    lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = LV_HOR_RES_MAX;
    disp_drv.ver_res = LV_VER_RES_MAX;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.buffer = &disp_buf;
    lv_disp_drv_register(&disp_drv);

    lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);  
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_indev_touch;
    lv_indev_drv_register(&indev_drv);

    xTaskCreatePinnedToCore(lvgl_freertos_task,     // task
                            "lvglTask",         // name for task
                            DISP_TASK_STACK,    // size of task stack
                            NULL,               // parameters
                            DISP_TASK_PRO,      // priority
                            // nullptr,
                            &lv_disp_tcb,
                            DISP_TASK_CORE      // must run the task on same core
                                                // core
    );
}


void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p) {

    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    
#if defined(USE_LCD_DMA)
    tft.pushColorsDMA(&color_p->full, w * h, true);
#else 
    tft.pushColors(&color_p->full, w * h, true);
#endif

    tft.endWrite();
    lv_disp_flush_ready(disp);
}

bool my_indev_touch(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data) {

    uint16_t touchX=0, touchY=0;
    static uint16_t last_x = 0;
    static uint16_t last_y = 0;
    // boolean touched = tft.getTouch(&touchY, &touchX);

    boolean touched = tp_read_task(&touchY, &touchX);

    char tempString[128]; 
    

    if(touchX > 480) { touchX = 480;}
    if(touchY > 320) { touchY = 320;}

    touchY = 320 - touchY;

    if( touched != false ) {
        last_x = touchX;
        last_y = touchY;
        data->point.x = last_x;
        data->point.y = last_y;
        data->state = LV_INDEV_STATE_PR;
    }
    else {
        data->point.x = last_x;
        data->point.y = last_y;
        data->state = LV_INDEV_STATE_REL;
    }
    return false;
}


void lvgl_freertos_task(void *parg) {

    TickType_t       xLastWakeTime;
    const TickType_t xDisplayFrequency = 5;                  
    xLastWakeTime = xTaskGetTickCount();   

    debug_send(CLIENT_SERIAL, "enter lvgl task\n");

    while(1) {

        lv_task_handler();

        vTaskDelayUntil(&xLastWakeTime, xDisplayFrequency); //使用相对延时，保证时间精准

    }
}


