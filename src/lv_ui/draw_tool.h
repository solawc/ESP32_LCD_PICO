#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    lv_obj_t *btn_language;
    lv_obj_t *btn_style;
    lv_obj_t *btn_sound;
    lv_obj_t *btn_wifi;
    lv_obj_t *btn_console;
    lv_obj_t *btn_customize1;
    lv_obj_t *btn_customize2;
    lv_obj_t *btn_customize3;

    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;

    lv_obj_t *label_language_pic;
    lv_obj_t *label_style_pic;
    lv_obj_t *label_sound_pic;
    lv_obj_t *label_wifi_pic;
    lv_obj_t *label_console_pic;
    lv_obj_t *label_customize1_pic;
    lv_obj_t *label_customize2_pic;
    lv_obj_t *label_customize3_pic;


    lv_obj_t *label_language;
    lv_obj_t *label_style;
    lv_obj_t *label_sound;
    lv_obj_t *label_wifi;
    lv_obj_t *label_console;
    lv_obj_t *label_customize1;
    lv_obj_t *label_customize2;
    lv_obj_t *label_customize3;

    lv_obj_t *btn_back;
    lv_obj_t *label_back_pic;
    lv_obj_t *label_back;
    lv_obj_t *btn_about;
    lv_obj_t *label_about_pic;
    lv_obj_t *label_about;

}ui_tool_t;

#define TOOL_BTN_LIST_X1 8
#define TOOL_BTN_LIST_X2 126
#define TOOL_BTN_LIST_X3 244
#define TOOL_BTN_LIST_X4 362

#define TOOL_BTN_LIST_Y1 84
#define TOOL_BTN_LIST_Y2 202

#define TOOL_BTN_BACK_X 8
#define TOOL_BTN_BACK_Y 8

#define TOOL_BTN_ABOUT_X 412
#define TOOL_BTN_ABOUT_Y 8
/***************************************************************************
 *                              extern
***************************************************************************/

void draw_tool(void);
void clean_tool_page(void);