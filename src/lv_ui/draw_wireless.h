#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    lv_obj_t *btn_file0;
    lv_obj_t *btn_file1;
    lv_obj_t *btn_file2;
    lv_obj_t *btn_file3;
    lv_obj_t *btn_file4;
    lv_obj_t *btn_file5;
    lv_obj_t *btn_file6;
    lv_obj_t *btn_file7;

    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;

    // lv_obj_t *label_file0_pic;
    // lv_obj_t *label_file1_pic;
    // lv_obj_t *label_file2_pic;
    // lv_obj_t *label_file3_pic;
    // lv_obj_t *label_file4_pic;
    // lv_obj_t *label_file5_pic;
    // lv_obj_t *label_file6_pic;
    // lv_obj_t *label_file7_pic;


    lv_obj_t *label_file0;
    lv_obj_t *label_file1;
    lv_obj_t *label_file2;
    lv_obj_t *label_file3;
    lv_obj_t *label_file4;
    lv_obj_t *label_file5;
    lv_obj_t *label_file6;
    lv_obj_t *label_file7;

    lv_obj_t *btn_back;
    lv_obj_t *label_back_pic;
    lv_obj_t *label_back;

    lv_obj_t *btn_up;
    lv_obj_t *label_up_pic;
    lv_obj_t *label_up;

    lv_obj_t *btn_next;
    lv_obj_t *label_next_pic;
    lv_obj_t *label_next;
    
    lv_obj_t *btn_refresh;
    lv_obj_t *label_refresh_pic;
    lv_obj_t *label_refresh;

}ui_wifi_list_t;

#define WIFI_LIST_BTN_LIST_X1 8
#define WIFI_LIST_BTN_LIST_X2 244

#define WIFI_LIST_BTN_LIST_W 228
#define WIFI_LIST_BTN_LIST_H 51

#define WIFI_LIST_BTN_LIST_Y1 84
#define WIFI_LIST_BTN_LIST_Y2 143
#define WIFI_LIST_BTN_LIST_Y3 202
#define WIFI_LIST_BTN_LIST_Y4 261

#define WIFI_LIST_BTN_BACK_X 8
#define WIFI_LIST_BTN_BACK_Y 8

#define WIFI_LIST_BTN_UP_X 354
#define WIFI_LIST_BTN_UP_Y 8

#define WIFI_LIST_BTN_NEXT_X 422
#define WIFI_LIST_BTN_NEXT_Y 8

#define WIFI_LIST_BTN_REFRESH_X 286
#define WIFI_LIST_BTN_REFRESH_Y 8

/***************************************************************************
 *                              extern
***************************************************************************/

void draw_wifi_list(void);
void clean_wifi_list_page(void);