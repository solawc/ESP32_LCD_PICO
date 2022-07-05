#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    uint16_t hour;
    uint16_t min;
    uint16_t sec;
    bool flag;
}PRINT_TIME_t;

typedef struct{
    lv_obj_t *btn_start;
    lv_obj_t *btn_stop;
    lv_obj_t *btn_adjustment;

    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;

    lv_style_t bar_bg_style;
    lv_style_t bar_indic_style;

    lv_obj_t *label_start_pic;
    lv_obj_t *label_stop_pic;
    lv_obj_t *label_adjustment_pic;

    lv_obj_t *label_start;
    lv_obj_t *label_stop;
    lv_obj_t *label_adjustment;

    lv_obj_t *obj_work_region;
    lv_obj_t *obj_mechang_region;
    lv_obj_t *obj_speed_region;

    lv_obj_t *label_work_region_pic;
    lv_obj_t *label_mechang_region_pic;
    lv_obj_t *label_speed_region_pic;

    lv_obj_t *label_work_region;
    lv_obj_t *label_mechang_region;
    lv_obj_t *label_speed_region;

    lv_obj_t *label_work_x;
    lv_obj_t *label_work_y;
    lv_obj_t *label_work_z;

    lv_obj_t *label_mechang_x;
    lv_obj_t *label_mechang_y;
    lv_obj_t *label_mechang_z;


    lv_obj_t *label_speed_f;
    lv_obj_t *label_speed_s;
    lv_obj_t *label_speed_r;


    lv_obj_t *bar;
    lv_obj_t *label_bar_percen;
    lv_obj_t *label_bar_time;
    lv_style_t label_bar_style;

    lv_obj_t *label_file_name;
    lv_obj_t *label_file_name_pic;


}ui_print_t;

#define PRINT_BTN_X1 8
#define PRINT_BTN_X2 165
#define PRINT_BTN_X3 322


#define PRINT_BTN_Y 252

#define PRINT_BTN_W 150
#define PRINT_BTN_H 60

#define PRINT_REGION_W 144
#define PRINT_REGION_H 152

#define PRINT_REGION_X1 8
#define PRINT_REGION_X2 168
#define PRINT_REGION_X3 328

#define PRINT_REGION_Y 48

#define PRINT_BAR_X 8
#define PRINT_BAR_Y 208
#define PRINT_BAR_W 464
#define PRINT_BAR_H 36
/***************************************************************************
 *                              extern
***************************************************************************/

void draw_print(void);
void clean_print_page(void);
void disp_printing_bar();

void print_time_init();
void print_time_enable();
void print_time_disable();
void print_time_change_pro();