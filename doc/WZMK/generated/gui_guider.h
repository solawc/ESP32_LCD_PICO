/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *logo_page;
	bool logo_page_del;
	lv_obj_t *logo_page_logo_label;
	lv_obj_t *main_page;
	bool main_page_del;
	lv_obj_t *main_page_imgbtn_1;
	lv_obj_t *main_page_imgbtn_1_label;
	lv_obj_t *main_page_imgbtn_2;
	lv_obj_t *main_page_imgbtn_2_label;
	lv_obj_t *main_page_imgbtn_3;
	lv_obj_t *main_page_imgbtn_3_label;
	lv_obj_t *main_page_label_1;
	lv_obj_t *main_page_label_2;
	lv_obj_t *main_page_label_3;
	lv_obj_t *engraving_page;
	bool engraving_page_del;
	lv_obj_t *engraving_page_btn_frame;
	lv_obj_t *engraving_page_btn_frame_label;
	lv_obj_t *engraving_page_btn_home;
	lv_obj_t *engraving_page_btn_home_label;
	lv_obj_t *engraving_page_btn_position;
	lv_obj_t *engraving_page_btn_position_label;
	lv_obj_t *engraving_page_btn_start;
	lv_obj_t *engraving_page_btn_start_label;
	lv_obj_t *engraving_page_label_1;
	lv_obj_t *engraving_page_label_2;
	lv_obj_t *engraving_page_btn_back;
	lv_obj_t *engraving_page_btn_back_label;
	lv_obj_t *engraving_page_img_1;
	lv_obj_t *engraving_page_imgbtn_1;
	lv_obj_t *engraving_page_imgbtn_1_label;
	lv_obj_t *engraving_page_btn_6;
	lv_obj_t *engraving_page_btn_6_label;
	lv_obj_t *engraving_page_btn_7;
	lv_obj_t *engraving_page_btn_7_label;
	lv_obj_t *engraving_page_btn_8;
	lv_obj_t *engraving_page_btn_8_label;
	lv_obj_t *engraving_page_btn_9;
	lv_obj_t *engraving_page_btn_9_label;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_logo_page(lv_ui *ui);
void setup_scr_main_page(lv_ui *ui);
void setup_scr_engraving_page(lv_ui *ui);
LV_IMG_DECLARE(_pic_control_alpha_114x114);
LV_IMG_DECLARE(_png_move_step_10mm_alpha_222x38);
LV_IMG_DECLARE(_pic_engraving_114x114);
LV_IMG_DECLARE(_pic_tool_alpha_114x114);
LV_IMG_DECLARE(_move_184x185);

#ifdef __cplusplus
}
#endif
#endif