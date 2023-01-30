/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_scr_engraving(lv_ui *ui){

	//Write codes engraving
	ui->engraving = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->engraving, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_main_main_default
	static lv_style_t style_engraving_main_main_default;
	if (style_engraving_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_main_main_default);
	else
		lv_style_init(&style_engraving_main_main_default);
	lv_style_set_bg_color(&style_engraving_main_main_default, lv_color_make(0x1d, 0x23, 0x32));
	lv_style_set_bg_opa(&style_engraving_main_main_default, 255);
	lv_obj_add_style(ui->engraving, &style_engraving_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes engraving_imgbtn_1
	ui->engraving_imgbtn_1 = lv_imgbtn_create(ui->engraving);
	lv_obj_set_pos(ui->engraving_imgbtn_1, 30, 62);
	lv_obj_set_size(ui->engraving_imgbtn_1, 184, 184);
	lv_obj_set_scrollbar_mode(ui->engraving_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_imgbtn_1_main_main_default
	static lv_style_t style_engraving_imgbtn_1_main_main_default;
	if (style_engraving_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_engraving_imgbtn_1_main_main_default);
	lv_style_set_text_color(&style_engraving_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_engraving_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->engraving_imgbtn_1, &style_engraving_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_engraving_imgbtn_1_main_main_pressed
	static lv_style_t style_engraving_imgbtn_1_main_main_pressed;
	if (style_engraving_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_engraving_imgbtn_1_main_main_pressed);
	lv_style_set_text_color(&style_engraving_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_1_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->engraving_imgbtn_1, &style_engraving_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_engraving_imgbtn_1_main_main_checked
	static lv_style_t style_engraving_imgbtn_1_main_main_checked;
	if (style_engraving_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_engraving_imgbtn_1_main_main_checked);
	lv_style_set_text_color(&style_engraving_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_1_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->engraving_imgbtn_1, &style_engraving_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->engraving_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_posite_pane_alpha_184x184, NULL);
	lv_obj_add_flag(ui->engraving_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes engraving_imgbtn_2
	ui->engraving_imgbtn_2 = lv_imgbtn_create(ui->engraving);
	lv_obj_set_pos(ui->engraving_imgbtn_2, 255, 82);
	lv_obj_set_size(ui->engraving_imgbtn_2, 206, 33);
	lv_obj_set_scrollbar_mode(ui->engraving_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_imgbtn_2_main_main_default
	static lv_style_t style_engraving_imgbtn_2_main_main_default;
	if (style_engraving_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_engraving_imgbtn_2_main_main_default);
	lv_style_set_text_color(&style_engraving_imgbtn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_engraving_imgbtn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_2_main_main_default, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_2_main_main_default, 255);
	lv_obj_add_style(ui->engraving_imgbtn_2, &style_engraving_imgbtn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_engraving_imgbtn_2_main_main_pressed
	static lv_style_t style_engraving_imgbtn_2_main_main_pressed;
	if (style_engraving_imgbtn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_2_main_main_pressed);
	else
		lv_style_init(&style_engraving_imgbtn_2_main_main_pressed);
	lv_style_set_text_color(&style_engraving_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_2_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_2_main_main_pressed, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_2_main_main_pressed, 255);
	lv_obj_add_style(ui->engraving_imgbtn_2, &style_engraving_imgbtn_2_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_engraving_imgbtn_2_main_main_checked
	static lv_style_t style_engraving_imgbtn_2_main_main_checked;
	if (style_engraving_imgbtn_2_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_2_main_main_checked);
	else
		lv_style_init(&style_engraving_imgbtn_2_main_main_checked);
	lv_style_set_text_color(&style_engraving_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_2_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_2_main_main_checked, 255);
	lv_obj_add_style(ui->engraving_imgbtn_2, &style_engraving_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->engraving_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_file_alpha_206x33, NULL);
	lv_obj_add_flag(ui->engraving_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);

	//Write codes engraving_imgbtn_3
	ui->engraving_imgbtn_3 = lv_imgbtn_create(ui->engraving);
	lv_obj_set_pos(ui->engraving_imgbtn_3, 255, 137);
	lv_obj_set_size(ui->engraving_imgbtn_3, 206, 33);
	lv_obj_set_scrollbar_mode(ui->engraving_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_imgbtn_3_main_main_default
	static lv_style_t style_engraving_imgbtn_3_main_main_default;
	if (style_engraving_imgbtn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_3_main_main_default);
	else
		lv_style_init(&style_engraving_imgbtn_3_main_main_default);
	lv_style_set_text_color(&style_engraving_imgbtn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_engraving_imgbtn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_3_main_main_default, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_3_main_main_default, 255);
	lv_obj_add_style(ui->engraving_imgbtn_3, &style_engraving_imgbtn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_engraving_imgbtn_3_main_main_pressed
	static lv_style_t style_engraving_imgbtn_3_main_main_pressed;
	if (style_engraving_imgbtn_3_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_3_main_main_pressed);
	else
		lv_style_init(&style_engraving_imgbtn_3_main_main_pressed);
	lv_style_set_text_color(&style_engraving_imgbtn_3_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_3_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_3_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_3_main_main_pressed, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_3_main_main_pressed, 255);
	lv_obj_add_style(ui->engraving_imgbtn_3, &style_engraving_imgbtn_3_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_engraving_imgbtn_3_main_main_checked
	static lv_style_t style_engraving_imgbtn_3_main_main_checked;
	if (style_engraving_imgbtn_3_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_3_main_main_checked);
	else
		lv_style_init(&style_engraving_imgbtn_3_main_main_checked);
	lv_style_set_text_color(&style_engraving_imgbtn_3_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_3_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_3_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_3_main_main_checked, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_3_main_main_checked, 255);
	lv_obj_add_style(ui->engraving_imgbtn_3, &style_engraving_imgbtn_3_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->engraving_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_home_alpha_206x33, NULL);
	lv_obj_add_flag(ui->engraving_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);

	//Write codes engraving_imgbtn_4
	ui->engraving_imgbtn_4 = lv_imgbtn_create(ui->engraving);
	lv_obj_set_pos(ui->engraving_imgbtn_4, 255, 191);
	lv_obj_set_size(ui->engraving_imgbtn_4, 206, 33);
	lv_obj_set_scrollbar_mode(ui->engraving_imgbtn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_imgbtn_4_main_main_default
	static lv_style_t style_engraving_imgbtn_4_main_main_default;
	if (style_engraving_imgbtn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_4_main_main_default);
	else
		lv_style_init(&style_engraving_imgbtn_4_main_main_default);
	lv_style_set_text_color(&style_engraving_imgbtn_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_engraving_imgbtn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_4_main_main_default, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_4_main_main_default, 255);
	lv_obj_add_style(ui->engraving_imgbtn_4, &style_engraving_imgbtn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_engraving_imgbtn_4_main_main_pressed
	static lv_style_t style_engraving_imgbtn_4_main_main_pressed;
	if (style_engraving_imgbtn_4_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_4_main_main_pressed);
	else
		lv_style_init(&style_engraving_imgbtn_4_main_main_pressed);
	lv_style_set_text_color(&style_engraving_imgbtn_4_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_4_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_4_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_4_main_main_pressed, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_4_main_main_pressed, 255);
	lv_obj_add_style(ui->engraving_imgbtn_4, &style_engraving_imgbtn_4_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_engraving_imgbtn_4_main_main_checked
	static lv_style_t style_engraving_imgbtn_4_main_main_checked;
	if (style_engraving_imgbtn_4_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_4_main_main_checked);
	else
		lv_style_init(&style_engraving_imgbtn_4_main_main_checked);
	lv_style_set_text_color(&style_engraving_imgbtn_4_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_4_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_4_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_4_main_main_checked, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_4_main_main_checked, 255);
	lv_obj_add_style(ui->engraving_imgbtn_4, &style_engraving_imgbtn_4_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->engraving_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_position_alpha_206x33, NULL);
	lv_obj_add_flag(ui->engraving_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);

	//Write codes engraving_imgbtn_5
	ui->engraving_imgbtn_5 = lv_imgbtn_create(ui->engraving);
	lv_obj_set_pos(ui->engraving_imgbtn_5, 270, 240);
	lv_obj_set_size(ui->engraving_imgbtn_5, 175, 50);
	lv_obj_set_scrollbar_mode(ui->engraving_imgbtn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_imgbtn_5_main_main_default
	static lv_style_t style_engraving_imgbtn_5_main_main_default;
	if (style_engraving_imgbtn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_5_main_main_default);
	else
		lv_style_init(&style_engraving_imgbtn_5_main_main_default);
	lv_style_set_text_color(&style_engraving_imgbtn_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_engraving_imgbtn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_5_main_main_default, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_5_main_main_default, 255);
	lv_obj_add_style(ui->engraving_imgbtn_5, &style_engraving_imgbtn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_engraving_imgbtn_5_main_main_pressed
	static lv_style_t style_engraving_imgbtn_5_main_main_pressed;
	if (style_engraving_imgbtn_5_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_5_main_main_pressed);
	else
		lv_style_init(&style_engraving_imgbtn_5_main_main_pressed);
	lv_style_set_text_color(&style_engraving_imgbtn_5_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_5_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_5_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_5_main_main_pressed, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_5_main_main_pressed, 255);
	lv_obj_add_style(ui->engraving_imgbtn_5, &style_engraving_imgbtn_5_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_engraving_imgbtn_5_main_main_checked
	static lv_style_t style_engraving_imgbtn_5_main_main_checked;
	if (style_engraving_imgbtn_5_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_5_main_main_checked);
	else
		lv_style_init(&style_engraving_imgbtn_5_main_main_checked);
	lv_style_set_text_color(&style_engraving_imgbtn_5_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_5_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_5_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_5_main_main_checked, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_5_main_main_checked, 255);
	lv_obj_add_style(ui->engraving_imgbtn_5, &style_engraving_imgbtn_5_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->engraving_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_start_alpha_175x50, NULL);
	lv_obj_add_flag(ui->engraving_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);

	//Write codes engraving_img_1
	ui->engraving_img_1 = lv_img_create(ui->engraving);
	lv_obj_set_pos(ui->engraving_img_1, 103, 12);
	lv_obj_set_size(ui->engraving_img_1, 15, 9);
	lv_obj_set_scrollbar_mode(ui->engraving_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_img_1_main_main_default
	static lv_style_t style_engraving_img_1_main_main_default;
	if (style_engraving_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_img_1_main_main_default);
	else
		lv_style_init(&style_engraving_img_1_main_main_default);
	lv_style_set_img_recolor(&style_engraving_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_engraving_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_engraving_img_1_main_main_default, 255);
	lv_obj_add_style(ui->engraving_img_1, &style_engraving_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->engraving_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->engraving_img_1,&_wifi_icon_15x9);
	lv_img_set_pivot(ui->engraving_img_1, 0,0);
	lv_img_set_angle(ui->engraving_img_1, 0);

	//Write codes engraving_imgbtn_6
	ui->engraving_imgbtn_6 = lv_imgbtn_create(ui->engraving);
	lv_obj_set_pos(ui->engraving_imgbtn_6, 420, 17);
	lv_obj_set_size(ui->engraving_imgbtn_6, 25, 21);
	lv_obj_set_scrollbar_mode(ui->engraving_imgbtn_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_imgbtn_6_main_main_default
	static lv_style_t style_engraving_imgbtn_6_main_main_default;
	if (style_engraving_imgbtn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_6_main_main_default);
	else
		lv_style_init(&style_engraving_imgbtn_6_main_main_default);
	lv_style_set_text_color(&style_engraving_imgbtn_6_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_engraving_imgbtn_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_6_main_main_default, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_6_main_main_default, 255);
	lv_obj_add_style(ui->engraving_imgbtn_6, &style_engraving_imgbtn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_engraving_imgbtn_6_main_main_pressed
	static lv_style_t style_engraving_imgbtn_6_main_main_pressed;
	if (style_engraving_imgbtn_6_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_6_main_main_pressed);
	else
		lv_style_init(&style_engraving_imgbtn_6_main_main_pressed);
	lv_style_set_text_color(&style_engraving_imgbtn_6_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_6_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_6_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_6_main_main_pressed, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_6_main_main_pressed, 255);
	lv_obj_add_style(ui->engraving_imgbtn_6, &style_engraving_imgbtn_6_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_engraving_imgbtn_6_main_main_checked
	static lv_style_t style_engraving_imgbtn_6_main_main_checked;
	if (style_engraving_imgbtn_6_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_6_main_main_checked);
	else
		lv_style_init(&style_engraving_imgbtn_6_main_main_checked);
	lv_style_set_text_color(&style_engraving_imgbtn_6_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_6_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_6_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_6_main_main_checked, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_6_main_main_checked, 255);
	lv_obj_add_style(ui->engraving_imgbtn_6, &style_engraving_imgbtn_6_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->engraving_imgbtn_6, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_25x21, NULL);
	lv_obj_add_flag(ui->engraving_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
}