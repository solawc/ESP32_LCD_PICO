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
	lv_obj_set_pos(ui->incarving_imgbtn_1, 27, 80);
	lv_obj_set_size(ui->incarving_imgbtn_1, 207, 207);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_1_main_main_default
	static lv_style_t style_incarving_imgbtn_1_main_main_default;
	if (style_incarving_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_1_main_main_default);
	lv_style_set_shadow_width(&style_incarving_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_1_main_main_default, 0);
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
	lv_style_set_shadow_width(&style_incarving_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_1_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_1_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_1_main_main_pressed, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
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
	lv_style_set_shadow_width(&style_incarving_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_1_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_1_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_1_main_main_checked, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_incarving_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_1, &style_incarving_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_emptypane_alpha_207x207, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes incarving_imgbtn_2
	ui->incarving_imgbtn_2 = lv_imgbtn_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_imgbtn_2, 254, 80);
	lv_obj_set_size(ui->incarving_imgbtn_2, 200, 37);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_2_main_main_default
	static lv_style_t style_incarving_imgbtn_2_main_main_default;
	if (style_incarving_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_2_main_main_default);
	lv_style_set_shadow_width(&style_incarving_imgbtn_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_2_main_main_default, 0);
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
	lv_style_set_shadow_width(&style_incarving_imgbtn_2_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_2_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_2_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_2_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_2_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_2_main_main_pressed, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
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
	lv_style_set_shadow_width(&style_incarving_imgbtn_2_main_main_checked, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_2_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_2_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_2_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_2_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_2_main_main_checked, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_incarving_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_2_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_2, &style_incarving_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_Frame_alpha_200x37, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);

	//Write codes incarving_imgbtn_3
	ui->incarving_imgbtn_3 = lv_imgbtn_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_imgbtn_3, 254, 132);
	lv_obj_set_size(ui->incarving_imgbtn_3, 200, 37);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_3_main_main_default
	static lv_style_t style_incarving_imgbtn_3_main_main_default;
	if (style_incarving_imgbtn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_3_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_3_main_main_default);
	lv_style_set_shadow_width(&style_incarving_imgbtn_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_3_main_main_default, 0);
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
	lv_style_set_shadow_width(&style_incarving_imgbtn_3_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_3_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_3_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_3_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_3_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_3_main_main_pressed, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_3_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
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
	lv_style_set_shadow_width(&style_incarving_imgbtn_3_main_main_checked, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_3_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_3_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_3_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_3_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_3_main_main_checked, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_3_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_incarving_imgbtn_3_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_3_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_3_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_3, &style_incarving_imgbtn_3_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_home_alpha_200x37, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);

	//Write codes incarving_imgbtn_4
	ui->incarving_imgbtn_4 = lv_imgbtn_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_imgbtn_4, 254, 189);
	lv_obj_set_size(ui->incarving_imgbtn_4, 200, 37);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_4_main_main_default
	static lv_style_t style_incarving_imgbtn_4_main_main_default;
	if (style_incarving_imgbtn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_4_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_4_main_main_default);
	lv_style_set_shadow_width(&style_incarving_imgbtn_4_main_main_default, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_4_main_main_default, 0);
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
	lv_style_set_shadow_width(&style_incarving_imgbtn_4_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_4_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_4_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_4_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_4_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_4_main_main_pressed, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_4_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
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
	lv_style_set_shadow_width(&style_incarving_imgbtn_4_main_main_checked, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_4_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_4_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_4_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_4_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_4_main_main_checked, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_4_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_incarving_imgbtn_4_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_4_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_4_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_4, &style_incarving_imgbtn_4_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_position_alpha_200x37, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);

	//Write codes incarving_imgbtn_5
	ui->incarving_imgbtn_5 = lv_imgbtn_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_imgbtn_5, 267, 237);
	lv_obj_set_size(ui->incarving_imgbtn_5, 175, 50);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_5_main_main_default
	static lv_style_t style_incarving_imgbtn_5_main_main_default;
	if (style_incarving_imgbtn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_5_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_5_main_main_default);
	lv_style_set_shadow_width(&style_incarving_imgbtn_5_main_main_default, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_5_main_main_default, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_5_main_main_default, 0);
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
	lv_style_set_shadow_width(&style_incarving_imgbtn_5_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_5_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_5_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_5_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_5_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_5_main_main_pressed, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_5_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
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
	lv_style_set_shadow_width(&style_incarving_imgbtn_5_main_main_checked, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_5_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_5_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_5_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_5_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_5_main_main_checked, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_5_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_incarving_imgbtn_5_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_5_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_5_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_5, &style_incarving_imgbtn_5_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_stop_alpha_175x50, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);

	//Write codes incarving_label_1
	ui->incarving_label_1 = lv_label_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_label_1, 94, 123);
	lv_obj_set_size(ui->incarving_label_1, 71, 61);
	lv_obj_set_scrollbar_mode(ui->incarving_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->incarving_label_1, "00\n");
	lv_label_set_long_mode(ui->incarving_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_incarving_label_1_main_main_default
	static lv_style_t style_incarving_label_1_main_main_default;
	if (style_incarving_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_label_1_main_main_default);
	else
		lv_style_init(&style_incarving_label_1_main_main_default);
	lv_style_set_radius(&style_incarving_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_incarving_label_1_main_main_default, lv_color_make(0x1D, 0x23, 0x32));
	lv_style_set_bg_grad_color(&style_incarving_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_incarving_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_incarving_label_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_incarving_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_incarving_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_incarving_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_incarving_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_incarving_label_1_main_main_default, &lv_font_FontAwesome5_58);
	lv_style_set_text_letter_space(&style_incarving_label_1_main_main_default, 0);
	lv_style_set_text_line_space(&style_incarving_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_incarving_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_incarving_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_incarving_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_incarving_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_incarving_label_1_main_main_default, 0);
	lv_obj_add_style(ui->incarving_label_1, &style_incarving_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes incarving_label_2
	// ui->incarving_label_2 = lv_label_create(ui->incarving);
	// lv_obj_set_pos(ui->incarving_label_2, 173, 144);
	// lv_obj_set_size(ui->incarving_label_2, 20, 33);
	// lv_obj_set_scrollbar_mode(ui->incarving_label_2, LV_SCROLLBAR_MODE_OFF);
	// lv_label_set_text(ui->incarving_label_2, str);
	// lv_label_set_long_mode(ui->incarving_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_incarving_label_2_main_main_default
	// static lv_style_t style_incarving_label_2_main_main_default;
	// if (style_incarving_label_2_main_main_default.prop_cnt > 1)
	// 	lv_style_reset(&style_incarving_label_2_main_main_default);
	// else
	// 	lv_style_init(&style_incarving_label_2_main_main_default);
	// lv_style_set_radius(&style_incarving_label_2_main_main_default, 0);
	// lv_style_set_bg_color(&style_incarving_label_2_main_main_default, lv_color_make(0x1D, 0x23, 0x32));
	// lv_style_set_bg_grad_color(&style_incarving_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_bg_grad_dir(&style_incarving_label_2_main_main_default, LV_GRAD_DIR_NONE);
	// lv_style_set_bg_opa(&style_incarving_label_2_main_main_default, 255);
	// lv_style_set_shadow_width(&style_incarving_label_2_main_main_default, 0);
	// lv_style_set_shadow_color(&style_incarving_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	// lv_style_set_shadow_opa(&style_incarving_label_2_main_main_default, 255);
	// lv_style_set_shadow_spread(&style_incarving_label_2_main_main_default, 0);
	// lv_style_set_shadow_ofs_x(&style_incarving_label_2_main_main_default, 0);
	// lv_style_set_shadow_ofs_y(&style_incarving_label_2_main_main_default, 0);
	// lv_style_set_text_color(&style_incarving_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	// lv_style_set_text_font(&style_incarving_label_2_main_main_default, &lv_font_FontAwesome5_20);
	// lv_style_set_text_letter_space(&style_incarving_label_2_main_main_default, 2);
	// lv_style_set_text_line_space(&style_incarving_label_2_main_main_default, 0);
	// lv_style_set_text_align(&style_incarving_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	// lv_style_set_pad_left(&style_incarving_label_2_main_main_default, 0);
	// lv_style_set_pad_right(&style_incarving_label_2_main_main_default, 0);
	// lv_style_set_pad_top(&style_incarving_label_2_main_main_default, 8);
	// lv_style_set_pad_bottom(&style_incarving_label_2_main_main_default, 0);
	// lv_obj_add_style(ui->incarving_label_2, &style_incarving_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes incarving_label_3
	ui->incarving_label_3 = lv_label_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_label_3, 102, 189);
	lv_obj_set_size(ui->incarving_label_3, 55, 27);
	lv_obj_set_scrollbar_mode(ui->incarving_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->incarving_label_3, "Time");
	lv_label_set_long_mode(ui->incarving_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_incarving_label_3_main_main_default
	static lv_style_t style_incarving_label_3_main_main_default;
	if (style_incarving_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_label_3_main_main_default);
	else
		lv_style_init(&style_incarving_label_3_main_main_default);
	lv_style_set_radius(&style_incarving_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_incarving_label_3_main_main_default, lv_color_make(0x1D, 0x23, 0x32));
	lv_style_set_bg_grad_color(&style_incarving_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_incarving_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_incarving_label_3_main_main_default, 255);
	lv_style_set_shadow_width(&style_incarving_label_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_incarving_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_label_3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_incarving_label_3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_label_3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_incarving_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_incarving_label_3_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_incarving_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_incarving_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_incarving_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_incarving_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_incarving_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_incarving_label_3_main_main_default, 8);
	lv_style_set_pad_bottom(&style_incarving_label_3_main_main_default, 0);
	lv_obj_add_style(ui->incarving_label_3, &style_incarving_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes incarving_label_4
	ui->incarving_label_4 = lv_label_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_label_4, 79, 216);
	lv_obj_set_size(ui->incarving_label_4, 100, 32);
	lv_obj_set_scrollbar_mode(ui->incarving_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->incarving_label_4, "01:20:30");
	lv_label_set_long_mode(ui->incarving_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_incarving_label_4_main_main_default
	static lv_style_t style_incarving_label_4_main_main_default;
	if (style_incarving_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_label_4_main_main_default);
	else
		lv_style_init(&style_incarving_label_4_main_main_default);
	lv_style_set_radius(&style_incarving_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_incarving_label_4_main_main_default, lv_color_make(0x1D, 0x23, 0x32));
	lv_style_set_bg_grad_color(&style_incarving_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_incarving_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_incarving_label_4_main_main_default, 255);
	lv_style_set_shadow_width(&style_incarving_label_4_main_main_default, 0);
	lv_style_set_shadow_color(&style_incarving_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_label_4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_incarving_label_4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_label_4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_incarving_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_incarving_label_4_main_main_default, &lv_font_montserratMedium_20);
	lv_style_set_text_letter_space(&style_incarving_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_incarving_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_incarving_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_incarving_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_incarving_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_incarving_label_4_main_main_default, 8);
	lv_style_set_pad_bottom(&style_incarving_label_4_main_main_default, 0);
	lv_obj_add_style(ui->incarving_label_4, &style_incarving_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes incarving_label_5
	ui->incarving_label_5 = lv_label_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_label_5, 15, 27);
	lv_obj_set_size(ui->incarving_label_5, 119, 31);
	lv_obj_set_scrollbar_mode(ui->incarving_label_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->incarving_label_5, "In caving");
	lv_label_set_long_mode(ui->incarving_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_incarving_label_5_main_main_default
	static lv_style_t style_incarving_label_5_main_main_default;
	if (style_incarving_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_label_5_main_main_default);
	else
		lv_style_init(&style_incarving_label_5_main_main_default);
	lv_style_set_radius(&style_incarving_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_incarving_label_5_main_main_default, lv_color_make(0x1D, 0x23, 0x32));
	lv_style_set_bg_grad_color(&style_incarving_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_incarving_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_incarving_label_5_main_main_default, 255);
	lv_style_set_shadow_width(&style_incarving_label_5_main_main_default, 0);
	lv_style_set_shadow_color(&style_incarving_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_label_5_main_main_default, 255);
	lv_style_set_shadow_spread(&style_incarving_label_5_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_label_5_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_incarving_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_incarving_label_5_main_main_default, &lv_font_montserratMedium_20);
	lv_style_set_text_letter_space(&style_incarving_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_incarving_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_incarving_label_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_incarving_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_incarving_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_incarving_label_5_main_main_default, 8);
	lv_style_set_pad_bottom(&style_incarving_label_5_main_main_default, 0);
	lv_obj_add_style(ui->incarving_label_5, &style_incarving_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes incarving_imgbtn_6
	ui->incarving_imgbtn_6 = lv_imgbtn_create(ui->incarving);
	lv_obj_set_pos(ui->incarving_imgbtn_6, 420, 17);
	lv_obj_set_size(ui->incarving_imgbtn_6, 25, 21);
	lv_obj_set_scrollbar_mode(ui->incarving_imgbtn_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_incarving_imgbtn_6_main_main_default
	static lv_style_t style_incarving_imgbtn_6_main_main_default;
	if (style_incarving_imgbtn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_6_main_main_default);
	else
		lv_style_init(&style_incarving_imgbtn_6_main_main_default);
	lv_style_set_shadow_width(&style_incarving_imgbtn_6_main_main_default, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_6_main_main_default, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_6_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_6_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_6_main_main_default, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_incarving_imgbtn_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_incarving_imgbtn_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_6_main_main_default, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_6_main_main_default, 255);
	lv_obj_add_style(ui->incarving_imgbtn_6, &style_incarving_imgbtn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_incarving_imgbtn_6_main_main_pressed
	static lv_style_t style_incarving_imgbtn_6_main_main_pressed;
	if (style_incarving_imgbtn_6_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_6_main_main_pressed);
	else
		lv_style_init(&style_incarving_imgbtn_6_main_main_pressed);
	lv_style_set_shadow_width(&style_incarving_imgbtn_6_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_6_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_6_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_6_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_6_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_6_main_main_pressed, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_6_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_incarving_imgbtn_6_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_6_main_main_pressed, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_6_main_main_pressed, 255);
	lv_obj_add_style(ui->incarving_imgbtn_6, &style_incarving_imgbtn_6_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_incarving_imgbtn_6_main_main_checked
	static lv_style_t style_incarving_imgbtn_6_main_main_checked;
	if (style_incarving_imgbtn_6_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_incarving_imgbtn_6_main_main_checked);
	else
		lv_style_init(&style_incarving_imgbtn_6_main_main_checked);
	lv_style_set_shadow_width(&style_incarving_imgbtn_6_main_main_checked, 0);
	lv_style_set_shadow_color(&style_incarving_imgbtn_6_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_incarving_imgbtn_6_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_incarving_imgbtn_6_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_incarving_imgbtn_6_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_incarving_imgbtn_6_main_main_checked, 0);
	lv_style_set_text_color(&style_incarving_imgbtn_6_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_incarving_imgbtn_6_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_incarving_imgbtn_6_main_main_checked, 0);
	lv_style_set_img_opa(&style_incarving_imgbtn_6_main_main_checked, 255);
	lv_obj_add_style(ui->incarving_imgbtn_6, &style_incarving_imgbtn_6_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->incarving_imgbtn_6, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_25x21, NULL);
	lv_obj_add_flag(ui->incarving_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
}