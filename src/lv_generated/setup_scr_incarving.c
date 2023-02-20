/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "./custom/custom.h"

void setup_scr_incarving(lv_ui *ui){

	//Write codes incarving
	ui->incarving = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->incarving, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_main_main_default
	static lv_style_t style_incarving_main_main_default;
	if (style_incarving_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_main_main_default);
	else
		lv_style_init(&style_incarving_main_main_default);
	lv_style_set_bg_color(&style_incarving_main_main_default, lv_color_make(0x1d, 0x23, 0x32));
	lv_style_set_bg_opa(&style_incarving_main_main_default, 255);
	lv_obj_add_style(ui->incarving, &style_incarving_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes incarving_imgbtn_1
	ui->incarving_imgbtn_1 = lv_imgbtn_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_imgbtn_1, 63, 85);
	lv_obj_set_size(ui->incarving_imgbtn_1, 150, 150);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_1_main_main_default
	static lv_style_t style_incarving_imgbtn_1_main_main_default;
	if (style_incarving_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_incarving_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_incarving_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->incarving_imgbtn_1, &style_incarving_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_incarving_imgbtn_1_main_main_pressed
	static lv_style_t style_incarving_imgbtn_1_main_main_pressed;
	if (style_incarving_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_incarving_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_incarving_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_incarving_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->incarving_imgbtn_1, &style_incarving_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_incarving_imgbtn_1_main_main_checked
	static lv_style_t style_incarving_imgbtn_1_main_main_checked;
	if (style_incarving_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_incarving_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_incarving_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_incarving_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_1, &style_incarving_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_emptypane_alpha_150x150, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes incarving_imgbtn_2
	ui->incarving_imgbtn_2 = lv_imgbtn_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_imgbtn_2, 254, 62);
	lv_obj_set_size(ui->incarving_imgbtn_2, 151, 23);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_2_main_main_default
	static lv_style_t style_incarving_imgbtn_2_main_main_default;
	if (style_incarving_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_2_main_main_default);
	lv_style_set_text_color(&style_incarving_imgbtn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_incarving_imgbtn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_2_main_main_default, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_2_main_main_default, 255);
	lv_obj_add_style(ui->incarving_imgbtn_2, &style_incarving_imgbtn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_incarving_imgbtn_2_main_main_pressed
	static lv_style_t style_incarving_imgbtn_2_main_main_pressed;
	if (style_incarving_imgbtn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_2_main_main_pressed);
	else
		lv_style_init(&style_incarving_imgbtn_2_main_main_pressed);
	lv_style_set_text_color(&style_incarving_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_incarving_imgbtn_2_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_2_main_main_pressed, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_2_main_main_pressed, 255);
	lv_obj_add_style(ui->incarving_imgbtn_2, &style_incarving_imgbtn_2_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_incarving_imgbtn_2_main_main_checked
	static lv_style_t style_incarving_imgbtn_2_main_main_checked;
	if (style_incarving_imgbtn_2_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_2_main_main_checked);
	else
		lv_style_init(&style_incarving_imgbtn_2_main_main_checked);
	lv_style_set_text_color(&style_incarving_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_incarving_imgbtn_2_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_2_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_2, &style_incarving_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_Frame_alpha_151x23, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);

	//Write codes incarving_imgbtn_3
	ui->incarving_imgbtn_3 = lv_imgbtn_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_imgbtn_3, 260, 132);
	lv_obj_set_size(ui->incarving_imgbtn_3, 157, 26);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_3_main_main_default
	static lv_style_t style_incarving_imgbtn_3_main_main_default;
	if (style_incarving_imgbtn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_3_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_3_main_main_default);
	lv_style_set_text_color(&style_incarving_imgbtn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_incarving_imgbtn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_3_main_main_default, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_3_main_main_default, 255);
	lv_obj_add_style(ui->incarving_imgbtn_3, &style_incarving_imgbtn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_incarving_imgbtn_3_main_main_pressed
	static lv_style_t style_incarving_imgbtn_3_main_main_pressed;
	if (style_incarving_imgbtn_3_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_3_main_main_pressed);
	else
		lv_style_init(&style_incarving_imgbtn_3_main_main_pressed);
	lv_style_set_text_color(&style_incarving_imgbtn_3_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_incarving_imgbtn_3_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_3_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_3_main_main_pressed, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_3_main_main_pressed, 255);
	lv_obj_add_style(ui->incarving_imgbtn_3, &style_incarving_imgbtn_3_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_incarving_imgbtn_3_main_main_checked
	static lv_style_t style_incarving_imgbtn_3_main_main_checked;
	if (style_incarving_imgbtn_3_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_3_main_main_checked);
	else
		lv_style_init(&style_incarving_imgbtn_3_main_main_checked);
	lv_style_set_text_color(&style_incarving_imgbtn_3_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_incarving_imgbtn_3_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_3_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_3_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_3_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_3, &style_incarving_imgbtn_3_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_home_alpha_157x26, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);

	//Write codes incarving_imgbtn_4
	ui->incarving_imgbtn_4 = lv_imgbtn_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_imgbtn_4, 263, 189);
	lv_obj_set_size(ui->incarving_imgbtn_4, 154, 24);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_4_main_main_default
	static lv_style_t style_incarving_imgbtn_4_main_main_default;
	if (style_incarving_imgbtn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_4_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_4_main_main_default);
	lv_style_set_text_color(&style_incarving_imgbtn_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_incarving_imgbtn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_4_main_main_default, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_4_main_main_default, 255);
	lv_obj_add_style(ui->incarving_imgbtn_4, &style_incarving_imgbtn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_incarving_imgbtn_4_main_main_pressed
	static lv_style_t style_incarving_imgbtn_4_main_main_pressed;
	if (style_incarving_imgbtn_4_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_4_main_main_pressed);
	else
		lv_style_init(&style_incarving_imgbtn_4_main_main_pressed);
	lv_style_set_text_color(&style_incarving_imgbtn_4_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_incarving_imgbtn_4_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_4_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_4_main_main_pressed, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_4_main_main_pressed, 255);
	lv_obj_add_style(ui->incarving_imgbtn_4, &style_incarving_imgbtn_4_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_incarving_imgbtn_4_main_main_checked
	static lv_style_t style_incarving_imgbtn_4_main_main_checked;
	if (style_incarving_imgbtn_4_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_4_main_main_checked);
	else
		lv_style_init(&style_incarving_imgbtn_4_main_main_checked);
	lv_style_set_text_color(&style_incarving_imgbtn_4_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_incarving_imgbtn_4_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_4_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_4_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_4_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_4, &style_incarving_imgbtn_4_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_position_alpha_154x24, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);

	//Write codes incarving_imgbtn_5
	ui->incarving_imgbtn_5 = lv_imgbtn_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_imgbtn_5, 250, 249);
	lv_obj_set_size(ui->incarving_imgbtn_5, 150, 32);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_5_main_main_default
	static lv_style_t style_incarving_imgbtn_5_main_main_default;
	if (style_incarving_imgbtn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_5_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_5_main_main_default);
	lv_style_set_text_color(&style_incarving_imgbtn_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_incarving_imgbtn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_5_main_main_default, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_5_main_main_default, 255);
	lv_obj_add_style(ui->incarving_imgbtn_5, &style_incarving_imgbtn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_incarving_imgbtn_5_main_main_pressed
	static lv_style_t style_incarving_imgbtn_5_main_main_pressed;
	if (style_incarving_imgbtn_5_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_5_main_main_pressed);
	else
		lv_style_init(&style_incarving_imgbtn_5_main_main_pressed);
	lv_style_set_text_color(&style_incarving_imgbtn_5_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_incarving_imgbtn_5_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_5_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_5_main_main_pressed, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_5_main_main_pressed, 255);
	lv_obj_add_style(ui->incarving_imgbtn_5, &style_incarving_imgbtn_5_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_incarving_imgbtn_5_main_main_checked
	static lv_style_t style_incarving_imgbtn_5_main_main_checked;
	if (style_incarving_imgbtn_5_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_5_main_main_checked);
	else
		lv_style_init(&style_incarving_imgbtn_5_main_main_checked);
	lv_style_set_text_color(&style_incarving_imgbtn_5_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_incarving_imgbtn_5_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_5_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_5_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_5_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_5, &style_incarving_imgbtn_5_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_stop_alpha_150x32, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
}