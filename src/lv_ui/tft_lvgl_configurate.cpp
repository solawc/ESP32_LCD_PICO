#include "tft_lvgl_configurate.h"

#define LV_BUF_SIZE             10 * LV_HOR_RES_MAX
static lv_disp_buf_t    disp_buf;
static lv_color_t       bmp_public_buf[LV_BUF_SIZE];
static lv_color_t       bmp_private_buf1[LV_BUF_SIZE]; 

#define DISP_TASK_STACK                 4096*2
#define DISP_TASK_PRO                   4
#define DISP_TASK_CORE                  1

TaskHandle_t lv_disp_tcb = NULL;
LVGL_UI_PAGE_t mks_ui_page;
/* Function */
void my_disp_flush(lv_disp_drv_t * disp, const lv_area_t * area, lv_color_t * color_p);
bool my_indev_touch(struct _lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
void mks_page_data_updata(void);
void lvgl_freertos_task(void *parg);

void lvgl_task_init(void) {

    tft_TS35_init();

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
    
    const TickType_t xDisplayFrequency = 1;   

    xLastWakeTime = xTaskGetTickCount();  

    draw_logo_init();

    draw_home();
    
    while(1) {
        lv_task_handler();
        mks_page_data_updata();
        vTaskDelayUntil(&xLastWakeTime, xDisplayFrequency); //使用相对延时，保证时间精准
    }
}

uint32_t count_updata = 0;
void mks_page_data_updata(void) { 
<<<<<<< HEAD
    
    if(mks_ui_page.mks_ui_page == MKS_UI_PAGE_SD_LIST)
    {
         if((count_updata >= 200) ) { 
                // disp_open_file();
=======

    if(mks_ui_page.mks_ui_page == MKS_UI_PAGE_SD_LIST)
    {
         if((count_updata >= 200) ) { 
>>>>>>> cb5f09ac69d4aa9827ecc96315e0f03b397e0f00
                if((sd_content.gain_all_name) && (ui_file_list_page_updata.updata_flag))
                {
                    ui_file_list_page_updata.updata_flag = false;
                    // serial_sendf(CLIENT_SERIAL,"hiuu %d\n",sd_content.file_num);
                    disp_file_name(sd_content.file_num , 1);
                    // for(int i = 0; i < sd_content.file_num;i++)
                    // {
                    //     serial_sendf(CLIENT_SERIAL, "file %d %s %s\n", sd_content.filetype[i],sd_content.filename[i],sd_content.filesize[i]);
                    // }
                }
                count_updata = 0;
            }
    }
    if(mks_ui_page.mks_ui_page == MKS_UI_PAGE_HOME)
    {
<<<<<<< HEAD
        if((count_updata >= 200) ) {
=======
        if((count_updata >= 500) ) {
>>>>>>> cb5f09ac69d4aa9827ecc96315e0f03b397e0f00
            disp_home_data_updata();
            count_updata = 0;
        }
    }
<<<<<<< HEAD
    if(mks_ui_page.mks_ui_page == MKS_UI_PAGE_CONTROL)
    {
        if((count_updata >= 200) ) {
            disp_control_data_updata();
            count_updata = 0;
        }
    }
    if(mks_ui_page.mks_ui_page == MKS_UI_PAGE_PRINT)
    {
    if((count_updata >= 200) ) {
            disp_printing_bar();
            count_updata = 0;
        }
    }
=======
>>>>>>> cb5f09ac69d4aa9827ecc96315e0f03b397e0f00
    count_updata++;
}
