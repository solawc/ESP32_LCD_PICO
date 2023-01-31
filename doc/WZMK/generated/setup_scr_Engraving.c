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


void setup_scr_Engraving(lv_ui *ui){

	//Write codes Engraving
	ui->Engraving = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->Engraving, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_main_main_default
	static lv_style_t style_engraving_main_main_default;
	if (style_engraving_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_main_main_default);
	else
		lv_style_init(&style_engraving_main_main_default);
	lv_style_set_bg_color(&style_engraving_main_main_default, lv_color_make(0x1D, 0x23, 0x32));
	lv_style_set_bg_opa(&style_engraving_main_main_default, 255);
	lv_obj_add_style(ui->Engraving, &style_engraving_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Engraving_btn_1
	ui->Engraving_btn_1 = lv_btn_create(ui->Engraving);
	lv_obj_set_pos(ui->Engraving_btn_1, 252, 80);
	lv_obj_set_size(ui->Engraving_btn_1, 212, 37);
	lv_obj_set_scrollbar_mode(ui->Engraving_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_btn_1_main_main_default
	static lv_style_t style_engraving_btn_1_main_main_default;
	if (style_engraving_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_btn_1_main_main_default);
	else
		lv_style_init(&style_engraving_btn_1_main_main_default);
	lv_style_set_radius(&style_engraving_btn_1_main_main_default, 20);
	lv_style_set_bg_color(&style_engraving_btn_1_main_main_default, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&style_engraving_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_btn_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_engraving_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_btn_1_main_main_default, 0);
	lv_style_set_shadow_spread(&style_engraving_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_btn_1_main_main_default, lv_color_make(0xFF, 0x57, 0x00));
	lv_style_set_border_width(&style_engraving_btn_1_main_main_default, 1);
	lv_style_set_border_opa(&style_engraving_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_btn_1_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_engraving_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->Engraving_btn_1, &style_engraving_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->Engraving_btn_1_label = lv_label_create(ui->Engraving_btn_1);
	lv_label_set_text(ui->Engraving_btn_1_label, "Frame");
	lv_obj_set_style_pad_all(ui->Engraving_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Engraving_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes Engraving_btn_2
	ui->Engraving_btn_2 = lv_btn_create(ui->Engraving);
	lv_obj_set_pos(ui->Engraving_btn_2, 252, 134);
	lv_obj_set_size(ui->Engraving_btn_2, 212, 37);
	lv_obj_set_scrollbar_mode(ui->Engraving_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_btn_2_main_main_default
	static lv_style_t style_engraving_btn_2_main_main_default;
	if (style_engraving_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_btn_2_main_main_default);
	else
		lv_style_init(&style_engraving_btn_2_main_main_default);
	lv_style_set_radius(&style_engraving_btn_2_main_main_default, 20);
	lv_style_set_bg_color(&style_engraving_btn_2_main_main_default, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&style_engraving_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_btn_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_btn_2_main_main_default, 255);
	lv_style_set_shadow_width(&style_engraving_btn_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_btn_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_btn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_btn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_btn_2_main_main_default, lv_color_make(0xFF, 0x57, 0x00));
	lv_style_set_border_width(&style_engraving_btn_2_main_main_default, 1);
	lv_style_set_border_opa(&style_engraving_btn_2_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_btn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_btn_2_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_engraving_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->Engraving_btn_2, &style_engraving_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->Engraving_btn_2_label = lv_label_create(ui->Engraving_btn_2);
	lv_label_set_text(ui->Engraving_btn_2_label, "Home");
	lv_obj_set_style_pad_all(ui->Engraving_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Engraving_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes Engraving_btn_3
	ui->Engraving_btn_3 = lv_btn_create(ui->Engraving);
	lv_obj_set_pos(ui->Engraving_btn_3, 252, 188);
	lv_obj_set_size(ui->Engraving_btn_3, 212, 37);
	lv_obj_set_scrollbar_mode(ui->Engraving_btn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_btn_3_main_main_default
	static lv_style_t style_engraving_btn_3_main_main_default;
	if (style_engraving_btn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_btn_3_main_main_default);
	else
		lv_style_init(&style_engraving_btn_3_main_main_default);
	lv_style_set_radius(&style_engraving_btn_3_main_main_default, 20);
	lv_style_set_bg_color(&style_engraving_btn_3_main_main_default, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&style_engraving_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_btn_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_btn_3_main_main_default, 255);
	lv_style_set_shadow_width(&style_engraving_btn_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_btn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_btn_3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_btn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_btn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_btn_3_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_btn_3_main_main_default, lv_color_make(0xFF, 0x57, 0x00));
	lv_style_set_border_width(&style_engraving_btn_3_main_main_default, 1);
	lv_style_set_border_opa(&style_engraving_btn_3_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_btn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_btn_3_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_engraving_btn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->Engraving_btn_3, &style_engraving_btn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->Engraving_btn_3_label = lv_label_create(ui->Engraving_btn_3);
	lv_label_set_text(ui->Engraving_btn_3_label, "Position");
	lv_obj_set_style_pad_all(ui->Engraving_btn_3, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Engraving_btn_3_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes Engraving_btn_4
	ui->Engraving_btn_4 = lv_btn_create(ui->Engraving);
	lv_obj_set_pos(ui->Engraving_btn_4, 270, 240);
	lv_obj_set_size(ui->Engraving_btn_4, 175, 50);
	lv_obj_set_scrollbar_mode(ui->Engraving_btn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_btn_4_main_main_default
	static lv_style_t style_engraving_btn_4_main_main_default;
	if (style_engraving_btn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_btn_4_main_main_default);
	else
		lv_style_init(&style_engraving_btn_4_main_main_default);
	lv_style_set_radius(&style_engraving_btn_4_main_main_default, 25);
	lv_style_set_bg_color(&style_engraving_btn_4_main_main_default, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&style_engraving_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_btn_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_btn_4_main_main_default, 255);
	lv_style_set_shadow_width(&style_engraving_btn_4_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_btn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_btn_4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_btn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_btn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_btn_4_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_btn_4_main_main_default, lv_color_make(0xff, 0x57, 0x00));
	lv_style_set_border_width(&style_engraving_btn_4_main_main_default, 2);
	lv_style_set_border_opa(&style_engraving_btn_4_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_btn_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_btn_4_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_engraving_btn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->Engraving_btn_4, &style_engraving_btn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->Engraving_btn_4_label = lv_label_create(ui->Engraving_btn_4);
	lv_label_set_text(ui->Engraving_btn_4_label, "Start");
	lv_obj_set_style_pad_all(ui->Engraving_btn_4, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Engraving_btn_4_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes Engraving_label_1
	ui->Engraving_label_1 = lv_label_create(ui->Engraving);
	lv_obj_set_pos(ui->Engraving_label_1, 10, 22);
	lv_obj_set_size(ui->Engraving_label_1, 135, 33);
	lv_obj_set_scrollbar_mode(ui->Engraving_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->Engraving_label_1, "Engraving-");
	lv_label_set_long_mode(ui->Engraving_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_engraving_label_1_main_main_default
	static lv_style_t style_engraving_label_1_main_main_default;
	if (style_engraving_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_label_1_main_main_default);
	else
		lv_style_init(&style_engraving_label_1_main_main_default);
	lv_style_set_radius(&style_engraving_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_engraving_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_engraving_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_label_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_engraving_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_engraving_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_label_1_main_main_default, &lv_font_montserratMedium_20);
	lv_style_set_text_letter_space(&style_engraving_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_engraving_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_engraving_label_1_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_engraving_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_engraving_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_engraving_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_engraving_label_1_main_main_default, 0);
	lv_obj_add_style(ui->Engraving_label_1, &style_engraving_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Engraving_label_2
	ui->Engraving_label_2 = lv_label_create(ui->Engraving);
	lv_obj_set_pos(ui->Engraving_label_2, 141, 26);
	lv_obj_set_size(ui->Engraving_label_2, 110, 25);
	lv_obj_set_scrollbar_mode(ui->Engraving_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->Engraving_label_2, "Filename");
	lv_label_set_long_mode(ui->Engraving_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_engraving_label_2_main_main_default
	static lv_style_t style_engraving_label_2_main_main_default;
	if (style_engraving_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_label_2_main_main_default);
	else
		lv_style_init(&style_engraving_label_2_main_main_default);
	lv_style_set_radius(&style_engraving_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_engraving_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_engraving_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_label_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_engraving_label_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_label_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_engraving_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_label_2_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_engraving_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_engraving_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_engraving_label_2_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_engraving_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_engraving_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_engraving_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_engraving_label_2_main_main_default, 0);
	lv_obj_add_style(ui->Engraving_label_2, &style_engraving_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Engraving_btn_5
	ui->Engraving_btn_5 = lv_btn_create(ui->Engraving);
	lv_obj_set_pos(ui->Engraving_btn_5, 364, 13);
	lv_obj_set_size(ui->Engraving_btn_5, 100, 50);
	lv_obj_set_scrollbar_mode(ui->Engraving_btn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_btn_5_main_main_default
	static lv_style_t style_engraving_btn_5_main_main_default;
	if (style_engraving_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_btn_5_main_main_default);
	else
		lv_style_init(&style_engraving_btn_5_main_main_default);
	lv_style_set_radius(&style_engraving_btn_5_main_main_default, 20);
	lv_style_set_bg_color(&style_engraving_btn_5_main_main_default, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&style_engraving_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_btn_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_btn_5_main_main_default, 255);
	lv_style_set_shadow_width(&style_engraving_btn_5_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_btn_5_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_btn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_btn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_engraving_btn_5_main_main_default, 1);
	lv_style_set_border_opa(&style_engraving_btn_5_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_btn_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_btn_5_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_engraving_btn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->Engraving_btn_5, &style_engraving_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->Engraving_btn_5_label = lv_label_create(ui->Engraving_btn_5);
	lv_label_set_text(ui->Engraving_btn_5_label, "Back");
	lv_obj_set_style_pad_all(ui->Engraving_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->Engraving_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_Engraving(ui);
}