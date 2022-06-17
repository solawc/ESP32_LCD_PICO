#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    lv_obj_t *btn_cn;
    lv_obj_t *btn_en;
    lv_obj_t *btn_ru;
    lv_obj_t *btn_de;
    // lv_obj_t *btn_console;
    // lv_obj_t *btn_customize1;
    // lv_obj_t *btn_customize2;
    // lv_obj_t *btn_customize3;

    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;

    lv_obj_t *label_cn_pic;
    lv_obj_t *label_en_pic;
    lv_obj_t *label_ru_pic;
    lv_obj_t *label_de_pic;
    // lv_obj_t *label_console_pic;
    // lv_obj_t *label_customize1_pic;
    // lv_obj_t *label_customize2_pic;
    // lv_obj_t *label_customize3_pic;


    lv_obj_t *label_cn;
    lv_obj_t *label_en;
    lv_obj_t *label_ru;
    lv_obj_t *label_de;
    // lv_obj_t *label_console;
    // lv_obj_t *label_customize1;
    // lv_obj_t *label_customize2;
    // lv_obj_t *label_customize3;

    lv_obj_t *btn_back;
    lv_obj_t *label_back_pic;
    lv_obj_t *label_back;
    // lv_obj_t *btn_about;
    // lv_obj_t *label_about_pic;
    // lv_obj_t *label_about;

}ui_language_t;

#define LANGUAGE_BTN_LIST_X1 8
#define LANGUAGE_BTN_LIST_X2 126
#define LANGUAGE_BTN_LIST_X3 244
#define LANGUAGE_BTN_LIST_X4 362

#define LANGUAGE_BTN_LIST_Y1 84
#define LANGUAGE_BTN_LIST_Y2 202

#define LANGUAGE_BTN_BACK_X 8
#define LANGUAGE_BTN_BACK_Y 8

/***************************************************************************
 *                              extern
***************************************************************************/

void draw_language(void);
void clean_language_page(void);