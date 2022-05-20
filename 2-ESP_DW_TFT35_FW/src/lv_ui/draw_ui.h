#pragma once

#include "../main.h"

LV_FONT_DECLARE(dlc32_gb2312);
LV_FONT_DECLARE(dlc_font_40x40);



typedef struct {

    lv_obj_t    *src;               // 作为主页
    lv_obj_t    *src_1;               

    lv_style_t  src_style;          // 主页样式
    lv_style_t  src_1_style;

    uint8_t     page_list;     

    lv_style_t di_font;             // 自定义字库类型         

}_ui_t;
extern _ui_t ui;

typedef struct {

    lv_color_t font_pre_color;
    lv_color_t font_rel_color;

    lv_color_t btn_pre_color;
    lv_color_t btn_rel_color;

    // ....
}ui_theme_t;




void ui_init_style(void);


lv_obj_t* lv_btn_set(lv_obj_t* scr, lv_obj_t* btn, lv_coord_t btn_w, lv_coord_t btn_h, lv_coord_t x, lv_coord_t y, lv_event_cb_t event_cb);

lv_obj_t* lv_label_set(lv_obj_t* scr, lv_obj_t* label, lv_coord_t x, lv_coord_t y, const char *text);
lv_obj_t* lv_label_set_btn(lv_obj_t* scr, lv_obj_t* label, lv_obj_t* base, lv_coord_t x, lv_coord_t y, const char *text);
