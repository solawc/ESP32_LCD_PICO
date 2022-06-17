#pragma once

#include "../main.h"



typedef struct {

    lv_obj_t *btn_write;
    lv_obj_t *btn_green;
    lv_obj_t *btn_red;
    lv_obj_t *btn_orange;
    lv_obj_t *btn_pink;
    lv_obj_t *btn_back;

    lv_obj_t *label_write;
    lv_obj_t *label_green;
    lv_obj_t *label_red;
    lv_obj_t *label_orange;
    lv_obj_t *label_pink;
    lv_obj_t *label_back;

    lv_style_t style_write;
    lv_style_t style_green;
    lv_style_t style_red;
    lv_style_t style_orange;
    lv_style_t style_pink;

    lv_style_t style_write_pre;
    lv_style_t style_green_pre;
    lv_style_t style_red_pre;
    lv_style_t style_orange_pre;
    lv_style_t style_pink_pre;

    lv_obj_t *label_back_pic;

}ui_style_t;

#define STYLE_BTN_LIST_X1 8
#define STYLE_BTN_LIST_X2 126
#define STYLE_BTN_LIST_X3 244
#define STYLE_BTN_LIST_X4 362

#define STYLE_BTN_LIST_Y1 84
#define STYLE_BTN_LIST_Y2 202

#define STYLE_BTN_BACK_X 8
#define STYLE_BTN_BACK_Y 8

void draw_style(void);
void clean_theme_page(void);
