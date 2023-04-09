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


void setup_scr_control(lv_ui *ui){

	//Write codes control
	ui->control = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->control, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_main_main_default
	static lv_style_t style_control_main_main_default;
	if (style_control_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_main_main_default);
	else
		lv_style_init(&style_control_main_main_default);
	lv_style_set_bg_color(&style_control_main_main_default, lv_color_make(0x1d, 0x23, 0x32));
	lv_style_set_bg_opa(&style_control_main_main_default, 255);
	lv_obj_add_style(ui->control, &style_control_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes control_imgbtn_1
	ui->control_imgbtn_1 = lv_imgbtn_create(ui->control);
	lv_obj_set_pos(ui->control_imgbtn_1, 30, 62);
	lv_obj_set_size(ui->control_imgbtn_1, 184, 184);
	lv_obj_set_scrollbar_mode(ui->control_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_imgbtn_1_main_main_default
	static lv_style_t style_control_imgbtn_1_main_main_default;
	if (style_control_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_control_imgbtn_1_main_main_default);
	lv_style_set_shadow_width(&style_control_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_1_main_main_default, 0);
	lv_style_set_text_color(&style_control_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_control_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_control_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_control_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->control_imgbtn_1, &style_control_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_control_imgbtn_1_main_main_pressed
	static lv_style_t style_control_imgbtn_1_main_main_pressed;
	if (style_control_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_control_imgbtn_1_main_main_pressed);
	lv_style_set_shadow_width(&style_control_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_1_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_1_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_1_main_main_pressed, 0);
	lv_style_set_text_color(&style_control_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_control_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->control_imgbtn_1, &style_control_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_control_imgbtn_1_main_main_checked
	static lv_style_t style_control_imgbtn_1_main_main_checked;
	if (style_control_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_control_imgbtn_1_main_main_checked);
	lv_style_set_shadow_width(&style_control_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_1_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_1_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_1_main_main_checked, 0);
	lv_style_set_text_color(&style_control_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_control_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->control_imgbtn_1, &style_control_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->control_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_Slice_41_alpha_184x184, NULL);
	lv_obj_add_flag(ui->control_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes control_imgbtn_2
	ui->control_imgbtn_2 = lv_imgbtn_create(ui->control);
	lv_obj_set_pos(ui->control_imgbtn_2, 255, 80);
	lv_obj_set_size(ui->control_imgbtn_2, 206, 33);
	lv_obj_set_scrollbar_mode(ui->control_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_imgbtn_2_main_main_default
	static lv_style_t style_control_imgbtn_2_main_main_default;
	if (style_control_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_control_imgbtn_2_main_main_default);
	lv_style_set_shadow_width(&style_control_imgbtn_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_2_main_main_default, 0);
	lv_style_set_text_color(&style_control_imgbtn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_control_imgbtn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_control_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_2_main_main_default, 0);
	lv_style_set_img_opa(&style_control_imgbtn_2_main_main_default, 255);
	lv_obj_add_style(ui->control_imgbtn_2, &style_control_imgbtn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_control_imgbtn_2_main_main_pressed
	static lv_style_t style_control_imgbtn_2_main_main_pressed;
	if (style_control_imgbtn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_2_main_main_pressed);
	else
		lv_style_init(&style_control_imgbtn_2_main_main_pressed);
	lv_style_set_shadow_width(&style_control_imgbtn_2_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_2_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_2_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_2_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_2_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_2_main_main_pressed, 0);
	lv_style_set_text_color(&style_control_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_2_main_main_pressed, 0);
	lv_style_set_img_opa(&style_control_imgbtn_2_main_main_pressed, 255);
	lv_obj_add_style(ui->control_imgbtn_2, &style_control_imgbtn_2_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_control_imgbtn_2_main_main_checked
	static lv_style_t style_control_imgbtn_2_main_main_checked;
	if (style_control_imgbtn_2_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_2_main_main_checked);
	else
		lv_style_init(&style_control_imgbtn_2_main_main_checked);
	lv_style_set_shadow_width(&style_control_imgbtn_2_main_main_checked, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_2_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_2_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_2_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_2_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_2_main_main_checked, 0);
	lv_style_set_text_color(&style_control_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_control_imgbtn_2_main_main_checked, 255);
	lv_obj_add_style(ui->control_imgbtn_2, &style_control_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->control_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_unlock_alpha_206x33, NULL);
	lv_obj_add_flag(ui->control_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);

	//Write codes control_imgbtn_3
	ui->control_imgbtn_3 = lv_imgbtn_create(ui->control);
	lv_obj_set_pos(ui->control_imgbtn_3, 255, 139);
	lv_obj_set_size(ui->control_imgbtn_3, 206, 33);
	lv_obj_set_scrollbar_mode(ui->control_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_imgbtn_3_main_main_default
	static lv_style_t style_control_imgbtn_3_main_main_default;
	if (style_control_imgbtn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_3_main_main_default);
	else
		lv_style_init(&style_control_imgbtn_3_main_main_default);
	lv_style_set_shadow_width(&style_control_imgbtn_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_3_main_main_default, 0);
	lv_style_set_text_color(&style_control_imgbtn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_control_imgbtn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_control_imgbtn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_3_main_main_default, 0);
	lv_style_set_img_opa(&style_control_imgbtn_3_main_main_default, 255);
	lv_obj_add_style(ui->control_imgbtn_3, &style_control_imgbtn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_control_imgbtn_3_main_main_pressed
	static lv_style_t style_control_imgbtn_3_main_main_pressed;
	if (style_control_imgbtn_3_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_3_main_main_pressed);
	else
		lv_style_init(&style_control_imgbtn_3_main_main_pressed);
	lv_style_set_shadow_width(&style_control_imgbtn_3_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_3_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_3_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_3_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_3_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_3_main_main_pressed, 0);
	lv_style_set_text_color(&style_control_imgbtn_3_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_3_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_3_main_main_pressed, 0);
	lv_style_set_img_opa(&style_control_imgbtn_3_main_main_pressed, 255);
	lv_obj_add_style(ui->control_imgbtn_3, &style_control_imgbtn_3_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_control_imgbtn_3_main_main_checked
	static lv_style_t style_control_imgbtn_3_main_main_checked;
	if (style_control_imgbtn_3_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_3_main_main_checked);
	else
		lv_style_init(&style_control_imgbtn_3_main_main_checked);
	lv_style_set_shadow_width(&style_control_imgbtn_3_main_main_checked, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_3_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_3_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_3_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_3_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_3_main_main_checked, 0);
	lv_style_set_text_color(&style_control_imgbtn_3_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_3_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_3_main_main_checked, 0);
	lv_style_set_img_opa(&style_control_imgbtn_3_main_main_checked, 255);
	lv_obj_add_style(ui->control_imgbtn_3, &style_control_imgbtn_3_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->control_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_home_alpha_206x33, NULL);
	lv_obj_add_flag(ui->control_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);

	//Write codes control_imgbtn_4
	ui->control_imgbtn_4 = lv_imgbtn_create(ui->control);
	lv_obj_set_pos(ui->control_imgbtn_4, 255, 198);
	lv_obj_set_size(ui->control_imgbtn_4, 206, 33);
	lv_obj_set_scrollbar_mode(ui->control_imgbtn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_imgbtn_4_main_main_default
	static lv_style_t style_control_imgbtn_4_main_main_default;
	if (style_control_imgbtn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_4_main_main_default);
	else
		lv_style_init(&style_control_imgbtn_4_main_main_default);
	lv_style_set_shadow_width(&style_control_imgbtn_4_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_4_main_main_default, 0);
	lv_style_set_text_color(&style_control_imgbtn_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_control_imgbtn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_control_imgbtn_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_4_main_main_default, 0);
	lv_style_set_img_opa(&style_control_imgbtn_4_main_main_default, 255);
	lv_obj_add_style(ui->control_imgbtn_4, &style_control_imgbtn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_control_imgbtn_4_main_main_pressed
	static lv_style_t style_control_imgbtn_4_main_main_pressed;
	if (style_control_imgbtn_4_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_4_main_main_pressed);
	else
		lv_style_init(&style_control_imgbtn_4_main_main_pressed);
	lv_style_set_shadow_width(&style_control_imgbtn_4_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_4_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_4_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_4_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_4_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_4_main_main_pressed, 0);
	lv_style_set_text_color(&style_control_imgbtn_4_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_4_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_4_main_main_pressed, 0);
	lv_style_set_img_opa(&style_control_imgbtn_4_main_main_pressed, 255);
	lv_obj_add_style(ui->control_imgbtn_4, &style_control_imgbtn_4_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_control_imgbtn_4_main_main_checked
	static lv_style_t style_control_imgbtn_4_main_main_checked;
	if (style_control_imgbtn_4_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_4_main_main_checked);
	else
		lv_style_init(&style_control_imgbtn_4_main_main_checked);
	lv_style_set_shadow_width(&style_control_imgbtn_4_main_main_checked, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_4_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_4_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_4_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_4_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_4_main_main_checked, 0);
	lv_style_set_text_color(&style_control_imgbtn_4_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_4_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_4_main_main_checked, 0);
	lv_style_set_img_opa(&style_control_imgbtn_4_main_main_checked, 255);
	lv_obj_add_style(ui->control_imgbtn_4, &style_control_imgbtn_4_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->control_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_position_alpha_206x33, NULL);
	lv_obj_add_flag(ui->control_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);

	//Write codes control_imgbtn_5
	ui->control_imgbtn_5 = lv_imgbtn_create(ui->control);
	lv_obj_set_pos(ui->control_imgbtn_5, 14, 255);
	lv_obj_set_size(ui->control_imgbtn_5, 222, 38);
	lv_obj_set_scrollbar_mode(ui->control_imgbtn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_imgbtn_5_main_main_default
	static lv_style_t style_control_imgbtn_5_main_main_default;
	if (style_control_imgbtn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_5_main_main_default);
	else
		lv_style_init(&style_control_imgbtn_5_main_main_default);
	lv_style_set_shadow_width(&style_control_imgbtn_5_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_5_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_5_main_main_default, 0);
	lv_style_set_text_color(&style_control_imgbtn_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_control_imgbtn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_control_imgbtn_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_5_main_main_default, 0);
	lv_style_set_img_opa(&style_control_imgbtn_5_main_main_default, 255);
	lv_obj_add_style(ui->control_imgbtn_5, &style_control_imgbtn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_control_imgbtn_5_main_main_pressed
	static lv_style_t style_control_imgbtn_5_main_main_pressed;
	if (style_control_imgbtn_5_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_5_main_main_pressed);
	else
		lv_style_init(&style_control_imgbtn_5_main_main_pressed);
	lv_style_set_shadow_width(&style_control_imgbtn_5_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_5_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_5_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_5_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_5_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_5_main_main_pressed, 0);
	lv_style_set_text_color(&style_control_imgbtn_5_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_5_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_5_main_main_pressed, 0);
	lv_style_set_img_opa(&style_control_imgbtn_5_main_main_pressed, 255);
	lv_obj_add_style(ui->control_imgbtn_5, &style_control_imgbtn_5_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_control_imgbtn_5_main_main_checked
	static lv_style_t style_control_imgbtn_5_main_main_checked;
	if (style_control_imgbtn_5_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_5_main_main_checked);
	else
		lv_style_init(&style_control_imgbtn_5_main_main_checked);
	lv_style_set_shadow_width(&style_control_imgbtn_5_main_main_checked, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_5_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_5_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_5_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_5_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_5_main_main_checked, 0);
	lv_style_set_text_color(&style_control_imgbtn_5_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_5_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_5_main_main_checked, 0);
	lv_style_set_img_opa(&style_control_imgbtn_5_main_main_checked, 255);
	lv_obj_add_style(ui->control_imgbtn_5, &style_control_imgbtn_5_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->control_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_position_label_alpha_222x38, NULL);
	lv_obj_add_flag(ui->control_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);

	//Write codes control_img_1
	ui->control_img_1 = lv_img_create(ui->control);
	lv_obj_set_pos(ui->control_img_1, 255, 256);
	lv_obj_set_size(ui->control_img_1, 206, 33);
	lv_obj_set_scrollbar_mode(ui->control_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_img_1_main_main_default
	static lv_style_t style_control_img_1_main_main_default;
	if (style_control_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_img_1_main_main_default);
	else
		lv_style_init(&style_control_img_1_main_main_default);
	lv_style_set_img_recolor(&style_control_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_control_img_1_main_main_default, 255);
	lv_obj_add_style(ui->control_img_1, &style_control_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->control_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->control_img_1,&_larse_power_206x33);
	lv_img_set_pivot(ui->control_img_1, 0,0);
	lv_img_set_angle(ui->control_img_1, 0);

	//Write codes control_imgbtn_6
	ui->control_imgbtn_6 = lv_imgbtn_create(ui->control);
	lv_obj_set_pos(ui->control_imgbtn_6, 420, 17);
	lv_obj_set_size(ui->control_imgbtn_6, 25, 21);
	lv_obj_set_scrollbar_mode(ui->control_imgbtn_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_imgbtn_6_main_main_default
	static lv_style_t style_control_imgbtn_6_main_main_default;
	if (style_control_imgbtn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_6_main_main_default);
	else
		lv_style_init(&style_control_imgbtn_6_main_main_default);
	lv_style_set_shadow_width(&style_control_imgbtn_6_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_6_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_6_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_6_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_6_main_main_default, 0);
	lv_style_set_text_color(&style_control_imgbtn_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_control_imgbtn_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_control_imgbtn_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_6_main_main_default, 0);
	lv_style_set_img_opa(&style_control_imgbtn_6_main_main_default, 255);
	lv_obj_add_style(ui->control_imgbtn_6, &style_control_imgbtn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_control_imgbtn_6_main_main_pressed
	static lv_style_t style_control_imgbtn_6_main_main_pressed;
	if (style_control_imgbtn_6_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_6_main_main_pressed);
	else
		lv_style_init(&style_control_imgbtn_6_main_main_pressed);
	lv_style_set_shadow_width(&style_control_imgbtn_6_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_6_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_6_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_6_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_6_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_6_main_main_pressed, 0);
	lv_style_set_text_color(&style_control_imgbtn_6_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_6_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_6_main_main_pressed, 0);
	lv_style_set_img_opa(&style_control_imgbtn_6_main_main_pressed, 255);
	lv_obj_add_style(ui->control_imgbtn_6, &style_control_imgbtn_6_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_control_imgbtn_6_main_main_checked
	static lv_style_t style_control_imgbtn_6_main_main_checked;
	if (style_control_imgbtn_6_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_6_main_main_checked);
	else
		lv_style_init(&style_control_imgbtn_6_main_main_checked);
	lv_style_set_shadow_width(&style_control_imgbtn_6_main_main_checked, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_6_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_6_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_6_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_6_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_6_main_main_checked, 0);
	lv_style_set_text_color(&style_control_imgbtn_6_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_6_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_6_main_main_checked, 0);
	lv_style_set_img_opa(&style_control_imgbtn_6_main_main_checked, 255);
	lv_obj_add_style(ui->control_imgbtn_6, &style_control_imgbtn_6_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->control_imgbtn_6, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_25x21, NULL);
	lv_obj_add_flag(ui->control_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);

	//Write codes control_imgbtn_7
	ui->control_imgbtn_7 = lv_imgbtn_create(ui->control);
	lv_obj_set_pos(ui->control_imgbtn_7, 112, 86);
	lv_obj_set_size(ui->control_imgbtn_7, 15, 30);
	lv_obj_set_scrollbar_mode(ui->control_imgbtn_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_imgbtn_7_main_main_default
	static lv_style_t style_control_imgbtn_7_main_main_default;
	if (style_control_imgbtn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_7_main_main_default);
	else
		lv_style_init(&style_control_imgbtn_7_main_main_default);
	lv_style_set_shadow_width(&style_control_imgbtn_7_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_7_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_7_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_7_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_7_main_main_default, 0);
	lv_style_set_text_color(&style_control_imgbtn_7_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_control_imgbtn_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_control_imgbtn_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_7_main_main_default, 0);
	lv_style_set_img_opa(&style_control_imgbtn_7_main_main_default, 255);
	lv_obj_add_style(ui->control_imgbtn_7, &style_control_imgbtn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_control_imgbtn_7_main_main_pressed
	static lv_style_t style_control_imgbtn_7_main_main_pressed;
	if (style_control_imgbtn_7_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_7_main_main_pressed);
	else
		lv_style_init(&style_control_imgbtn_7_main_main_pressed);
	lv_style_set_shadow_width(&style_control_imgbtn_7_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_7_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_7_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_7_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_7_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_7_main_main_pressed, 0);
	lv_style_set_text_color(&style_control_imgbtn_7_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_7_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_7_main_main_pressed, 0);
	lv_style_set_img_opa(&style_control_imgbtn_7_main_main_pressed, 255);
	lv_obj_add_style(ui->control_imgbtn_7, &style_control_imgbtn_7_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_control_imgbtn_7_main_main_checked
	static lv_style_t style_control_imgbtn_7_main_main_checked;
	if (style_control_imgbtn_7_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_7_main_main_checked);
	else
		lv_style_init(&style_control_imgbtn_7_main_main_checked);
	lv_style_set_shadow_width(&style_control_imgbtn_7_main_main_checked, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_7_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_7_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_7_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_7_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_7_main_main_checked, 0);
	lv_style_set_text_color(&style_control_imgbtn_7_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_7_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_7_main_main_checked, 0);
	lv_style_set_img_opa(&style_control_imgbtn_7_main_main_checked, 255);
	lv_obj_add_style(ui->control_imgbtn_7, &style_control_imgbtn_7_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->control_imgbtn_7, LV_IMGBTN_STATE_RELEASED, NULL, &_y_up_alpha_15x30, NULL);
	lv_obj_add_flag(ui->control_imgbtn_7, LV_OBJ_FLAG_CHECKABLE);

	//Write codes control_imgbtn_8
	ui->control_imgbtn_8 = lv_imgbtn_create(ui->control);
	lv_obj_set_pos(ui->control_imgbtn_8, 112, 189);
	lv_obj_set_size(ui->control_imgbtn_8, 15, 30);
	lv_obj_set_scrollbar_mode(ui->control_imgbtn_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_imgbtn_8_main_main_default
	static lv_style_t style_control_imgbtn_8_main_main_default;
	if (style_control_imgbtn_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_8_main_main_default);
	else
		lv_style_init(&style_control_imgbtn_8_main_main_default);
	lv_style_set_shadow_width(&style_control_imgbtn_8_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_8_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_8_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_8_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_8_main_main_default, 0);
	lv_style_set_text_color(&style_control_imgbtn_8_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_control_imgbtn_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_control_imgbtn_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_8_main_main_default, 0);
	lv_style_set_img_opa(&style_control_imgbtn_8_main_main_default, 255);
	lv_obj_add_style(ui->control_imgbtn_8, &style_control_imgbtn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_control_imgbtn_8_main_main_pressed
	static lv_style_t style_control_imgbtn_8_main_main_pressed;
	if (style_control_imgbtn_8_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_8_main_main_pressed);
	else
		lv_style_init(&style_control_imgbtn_8_main_main_pressed);
	lv_style_set_shadow_width(&style_control_imgbtn_8_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_8_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_8_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_8_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_8_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_8_main_main_pressed, 0);
	lv_style_set_text_color(&style_control_imgbtn_8_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_8_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_8_main_main_pressed, 0);
	lv_style_set_img_opa(&style_control_imgbtn_8_main_main_pressed, 255);
	lv_obj_add_style(ui->control_imgbtn_8, &style_control_imgbtn_8_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_control_imgbtn_8_main_main_checked
	static lv_style_t style_control_imgbtn_8_main_main_checked;
	if (style_control_imgbtn_8_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_8_main_main_checked);
	else
		lv_style_init(&style_control_imgbtn_8_main_main_checked);
	lv_style_set_shadow_width(&style_control_imgbtn_8_main_main_checked, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_8_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_8_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_8_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_8_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_8_main_main_checked, 0);
	lv_style_set_text_color(&style_control_imgbtn_8_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_8_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_8_main_main_checked, 0);
	lv_style_set_img_opa(&style_control_imgbtn_8_main_main_checked, 255);
	lv_obj_add_style(ui->control_imgbtn_8, &style_control_imgbtn_8_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->control_imgbtn_8, LV_IMGBTN_STATE_RELEASED, NULL, &_y_down_alpha_15x30, NULL);
	lv_obj_add_flag(ui->control_imgbtn_8, LV_OBJ_FLAG_CHECKABLE);

	//Write codes control_imgbtn_9
	ui->control_imgbtn_9 = lv_imgbtn_create(ui->control);
	lv_obj_set_pos(ui->control_imgbtn_9, 53, 145);
	lv_obj_set_size(ui->control_imgbtn_9, 28, 15);
	lv_obj_set_scrollbar_mode(ui->control_imgbtn_9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_imgbtn_9_main_main_default
	static lv_style_t style_control_imgbtn_9_main_main_default;
	if (style_control_imgbtn_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_9_main_main_default);
	else
		lv_style_init(&style_control_imgbtn_9_main_main_default);
	lv_style_set_shadow_width(&style_control_imgbtn_9_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_9_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_9_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_9_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_9_main_main_default, 0);
	lv_style_set_text_color(&style_control_imgbtn_9_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_control_imgbtn_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_control_imgbtn_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_9_main_main_default, 0);
	lv_style_set_img_opa(&style_control_imgbtn_9_main_main_default, 255);
	lv_obj_add_style(ui->control_imgbtn_9, &style_control_imgbtn_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_control_imgbtn_9_main_main_pressed
	static lv_style_t style_control_imgbtn_9_main_main_pressed;
	if (style_control_imgbtn_9_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_9_main_main_pressed);
	else
		lv_style_init(&style_control_imgbtn_9_main_main_pressed);
	lv_style_set_shadow_width(&style_control_imgbtn_9_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_9_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_9_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_9_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_9_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_9_main_main_pressed, 0);
	lv_style_set_text_color(&style_control_imgbtn_9_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_9_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_9_main_main_pressed, 0);
	lv_style_set_img_opa(&style_control_imgbtn_9_main_main_pressed, 255);
	lv_obj_add_style(ui->control_imgbtn_9, &style_control_imgbtn_9_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_control_imgbtn_9_main_main_checked
	static lv_style_t style_control_imgbtn_9_main_main_checked;
	if (style_control_imgbtn_9_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_9_main_main_checked);
	else
		lv_style_init(&style_control_imgbtn_9_main_main_checked);
	lv_style_set_shadow_width(&style_control_imgbtn_9_main_main_checked, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_9_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_9_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_9_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_9_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_9_main_main_checked, 0);
	lv_style_set_text_color(&style_control_imgbtn_9_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_9_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_9_main_main_checked, 0);
	lv_style_set_img_opa(&style_control_imgbtn_9_main_main_checked, 255);
	lv_obj_add_style(ui->control_imgbtn_9, &style_control_imgbtn_9_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->control_imgbtn_9, LV_IMGBTN_STATE_RELEASED, NULL, &_x_left_alpha_28x15, NULL);
	lv_obj_add_flag(ui->control_imgbtn_9, LV_OBJ_FLAG_CHECKABLE);

	//Write codes control_imgbtn_10
	ui->control_imgbtn_10 = lv_imgbtn_create(ui->control);
	lv_obj_set_pos(ui->control_imgbtn_10, 159, 145);
	lv_obj_set_size(ui->control_imgbtn_10, 28, 15);
	lv_obj_set_scrollbar_mode(ui->control_imgbtn_10, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_imgbtn_10_main_main_default
	static lv_style_t style_control_imgbtn_10_main_main_default;
	if (style_control_imgbtn_10_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_10_main_main_default);
	else
		lv_style_init(&style_control_imgbtn_10_main_main_default);
	lv_style_set_shadow_width(&style_control_imgbtn_10_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_10_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_10_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_10_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_10_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_10_main_main_default, 0);
	lv_style_set_text_color(&style_control_imgbtn_10_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_control_imgbtn_10_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_control_imgbtn_10_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_10_main_main_default, 0);
	lv_style_set_img_opa(&style_control_imgbtn_10_main_main_default, 255);
	lv_obj_add_style(ui->control_imgbtn_10, &style_control_imgbtn_10_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_control_imgbtn_10_main_main_pressed
	static lv_style_t style_control_imgbtn_10_main_main_pressed;
	if (style_control_imgbtn_10_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_10_main_main_pressed);
	else
		lv_style_init(&style_control_imgbtn_10_main_main_pressed);
	lv_style_set_shadow_width(&style_control_imgbtn_10_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_10_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_10_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_10_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_10_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_10_main_main_pressed, 0);
	lv_style_set_text_color(&style_control_imgbtn_10_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_10_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_10_main_main_pressed, 0);
	lv_style_set_img_opa(&style_control_imgbtn_10_main_main_pressed, 255);
	lv_obj_add_style(ui->control_imgbtn_10, &style_control_imgbtn_10_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_control_imgbtn_10_main_main_checked
	static lv_style_t style_control_imgbtn_10_main_main_checked;
	if (style_control_imgbtn_10_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_control_imgbtn_10_main_main_checked);
	else
		lv_style_init(&style_control_imgbtn_10_main_main_checked);
	lv_style_set_shadow_width(&style_control_imgbtn_10_main_main_checked, 0);
	lv_style_set_shadow_color(&style_control_imgbtn_10_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_imgbtn_10_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_control_imgbtn_10_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_control_imgbtn_10_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_control_imgbtn_10_main_main_checked, 0);
	lv_style_set_text_color(&style_control_imgbtn_10_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_control_imgbtn_10_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_control_imgbtn_10_main_main_checked, 0);
	lv_style_set_img_opa(&style_control_imgbtn_10_main_main_checked, 255);
	lv_obj_add_style(ui->control_imgbtn_10, &style_control_imgbtn_10_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->control_imgbtn_10, LV_IMGBTN_STATE_RELEASED, NULL, &_x_right_alpha_28x15, NULL);
	lv_obj_add_flag(ui->control_imgbtn_10, LV_OBJ_FLAG_CHECKABLE);

	//Write codes control_label_1
	ui->control_label_1 = lv_label_create(ui->control);
	lv_obj_set_pos(ui->control_label_1, 10, 5);
	lv_obj_set_size(ui->control_label_1, 80, 20);
	lv_obj_set_scrollbar_mode(ui->control_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->control_label_1, "MakeGo");
	lv_label_set_long_mode(ui->control_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_control_label_1_main_main_default
	static lv_style_t style_control_label_1_main_main_default;
	if (style_control_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_label_1_main_main_default);
	else
		lv_style_init(&style_control_label_1_main_main_default);
	lv_style_set_radius(&style_control_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_control_label_1_main_main_default, lv_color_make(0x1D, 0x23, 0x32));
	lv_style_set_bg_grad_color(&style_control_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_control_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_control_label_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_control_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_control_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_control_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_control_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_control_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_control_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_control_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_control_label_1_main_main_default, &lv_font_montserratMedium_10);
	lv_style_set_text_letter_space(&style_control_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_control_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_control_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_control_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_control_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_control_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_control_label_1_main_main_default, 0);
	lv_obj_add_style(ui->control_label_1, &style_control_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes control_img_2
	ui->control_img_2 = lv_img_create(ui->control);
	lv_obj_set_pos(ui->control_img_2, 103, 12);
	lv_obj_set_size(ui->control_img_2, 15, 9);
	lv_obj_set_scrollbar_mode(ui->control_img_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_control_img_2_main_main_default
	static lv_style_t style_control_img_2_main_main_default;
	if (style_control_img_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_control_img_2_main_main_default);
	else
		lv_style_init(&style_control_img_2_main_main_default);
	lv_style_set_img_recolor(&style_control_img_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_control_img_2_main_main_default, 0);
	lv_style_set_img_opa(&style_control_img_2_main_main_default, 255);
	lv_obj_add_style(ui->control_img_2, &style_control_img_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->control_img_2, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->control_img_2,&_wifi_icon_15x9);
	lv_img_set_pivot(ui->control_img_2, 0,0);
	lv_img_set_angle(ui->control_img_2, 0);

}