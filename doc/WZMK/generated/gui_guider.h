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
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_imgbtn_1;
	lv_obj_t *screen_imgbtn_1_label;
	lv_obj_t *screen_imgbtn_2;
	lv_obj_t *screen_imgbtn_2_label;
	lv_obj_t *screen_imgbtn_3;
	lv_obj_t *screen_imgbtn_3_label;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_label_3;
	lv_obj_t *Engraving;
	bool Engraving_del;
	lv_obj_t *Engraving_btn_1;
	lv_obj_t *Engraving_btn_1_label;
	lv_obj_t *Engraving_btn_2;
	lv_obj_t *Engraving_btn_2_label;
	lv_obj_t *Engraving_btn_3;
	lv_obj_t *Engraving_btn_3_label;
	lv_obj_t *Engraving_btn_4;
	lv_obj_t *Engraving_btn_4_label;
	lv_obj_t *Engraving_label_1;
	lv_obj_t *Engraving_label_2;
	lv_obj_t *Engraving_btn_5;
	lv_obj_t *Engraving_btn_5_label;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_screen(lv_ui *ui);
void setup_scr_Engraving(lv_ui *ui);
LV_IMG_DECLARE(_pic_control_alpha_114x114);
LV_IMG_DECLARE(_pic_engraving_114x114);
LV_IMG_DECLARE(_pic_tool_alpha_114x114);

#ifdef __cplusplus
}
#endif
#endif