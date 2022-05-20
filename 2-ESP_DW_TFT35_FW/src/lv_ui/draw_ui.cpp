#include "draw_ui.h"

_ui_t ui;


void ui_init_style(void) {

    // 背景页面style
    lv_style_copy(&ui.src_style , &lv_style_scr);
    ui.src_style .body.grad_color = LV_COLOR_MAKE(0x19, 0x19, 0x19);
	ui.src_style .body.main_color = LV_COLOR_MAKE(0x19, 0x19, 0x19);
    ui.src_style.text.font = &dlc32_gb2312;
    ui.src_style.text.color = lv_color_hex(0x4DE585);

    lv_style_copy(&ui.src_1_style , &lv_style_scr);
    ui.src_1_style .body.grad_color = LV_COLOR_MAKE(0x26, 0x26, 0x26);
	ui.src_1_style .body.main_color = LV_COLOR_MAKE(0x26, 0x26, 0x26);


    lv_style_copy(&ui.di_font , &lv_style_scr);
    ui.di_font.text.font = &dlc_font_40x40;
    ui.di_font.text.color = lv_color_hex(0x4DE585);
}


lv_obj_t* lv_btn_set(lv_obj_t* scr, lv_obj_t* btn, lv_coord_t btn_w, lv_coord_t btn_h, lv_coord_t x, lv_coord_t y, lv_event_cb_t event_cb) {

    btn = lv_btn_create(scr, NULL);
    lv_obj_set_size(btn, btn_w, btn_h);
    lv_obj_set_pos(btn, x, y);
    lv_obj_set_event_cb(btn, event_cb);
    return btn;
}


lv_obj_t* lv_label_set(lv_obj_t* scr, lv_obj_t* label, lv_coord_t x, lv_coord_t y, const char *text) {

    label = lv_label_create(scr, NULL);
    lv_obj_set_pos(label, x, y);
    lv_label_set_long_mode(label, LV_LABEL_LONG_EXPAND);
    lv_label_set_text(label, text);
    return  label;
}

lv_obj_t* lv_label_set_btn(lv_obj_t* scr, lv_obj_t* label, lv_obj_t* base, lv_coord_t x, lv_coord_t y, const char *text) {

    label = lv_label_create(scr, NULL);
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);
    lv_label_set_recolor(label, true);
    lv_obj_set_size(label, 130, 32);
    lv_obj_align(label, base, LV_ALIGN_OUT_BOTTOM_MID, x, y);
    lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
    lv_label_set_text(label, text);
    return  label;
}

