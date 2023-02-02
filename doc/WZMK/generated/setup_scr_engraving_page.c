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


void setup_scr_engraving_page(lv_ui *ui){

	//Write codes engraving_page
	ui->engraving_page = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->engraving_page, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_main_main_default
	static lv_style_t style_engraving_page_main_main_default;
	if (style_engraving_page_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_main_main_default);
	else
		lv_style_init(&style_engraving_page_main_main_default);
	lv_style_set_bg_color(&style_engraving_page_main_main_default, lv_color_make(0x1D, 0x23, 0x32));
	lv_style_set_bg_opa(&style_engraving_page_main_main_default, 255);
	lv_obj_add_style(ui->engraving_page, &style_engraving_page_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes engraving_page_btn_frame
	ui->engraving_page_btn_frame = lv_btn_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_btn_frame, 252, 80);
	lv_obj_set_size(ui->engraving_page_btn_frame, 212, 37);
	lv_obj_set_scrollbar_mode(ui->engraving_page_btn_frame, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_btn_frame_main_main_default
	static lv_style_t style_engraving_page_btn_frame_main_main_default;
	if (style_engraving_page_btn_frame_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_btn_frame_main_main_default);
	else
		lv_style_init(&style_engraving_page_btn_frame_main_main_default);
	lv_style_set_radius(&style_engraving_page_btn_frame_main_main_default, 20);
	lv_style_set_bg_color(&style_engraving_page_btn_frame_main_main_default, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&style_engraving_page_btn_frame_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_btn_frame_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_btn_frame_main_main_default, 255);
	lv_style_set_shadow_width(&style_engraving_page_btn_frame_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_btn_frame_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_btn_frame_main_main_default, 0);
	lv_style_set_shadow_spread(&style_engraving_page_btn_frame_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_btn_frame_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_btn_frame_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_page_btn_frame_main_main_default, lv_color_make(0xFF, 0x57, 0x00));
	lv_style_set_border_width(&style_engraving_page_btn_frame_main_main_default, 1);
	lv_style_set_border_opa(&style_engraving_page_btn_frame_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_page_btn_frame_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_page_btn_frame_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_engraving_page_btn_frame_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->engraving_page_btn_frame, &style_engraving_page_btn_frame_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->engraving_page_btn_frame_label = lv_label_create(ui->engraving_page_btn_frame);
	lv_label_set_text(ui->engraving_page_btn_frame_label, "Frame");
	lv_obj_set_style_pad_all(ui->engraving_page_btn_frame, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->engraving_page_btn_frame_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes engraving_page_btn_home
	ui->engraving_page_btn_home = lv_btn_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_btn_home, 252, 134);
	lv_obj_set_size(ui->engraving_page_btn_home, 212, 37);
	lv_obj_set_scrollbar_mode(ui->engraving_page_btn_home, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_btn_home_main_main_default
	static lv_style_t style_engraving_page_btn_home_main_main_default;
	if (style_engraving_page_btn_home_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_btn_home_main_main_default);
	else
		lv_style_init(&style_engraving_page_btn_home_main_main_default);
	lv_style_set_radius(&style_engraving_page_btn_home_main_main_default, 20);
	lv_style_set_bg_color(&style_engraving_page_btn_home_main_main_default, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&style_engraving_page_btn_home_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_btn_home_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_btn_home_main_main_default, 255);
	lv_style_set_shadow_width(&style_engraving_page_btn_home_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_btn_home_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_btn_home_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_btn_home_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_btn_home_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_btn_home_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_page_btn_home_main_main_default, lv_color_make(0xFF, 0x57, 0x00));
	lv_style_set_border_width(&style_engraving_page_btn_home_main_main_default, 1);
	lv_style_set_border_opa(&style_engraving_page_btn_home_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_page_btn_home_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_page_btn_home_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_engraving_page_btn_home_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->engraving_page_btn_home, &style_engraving_page_btn_home_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->engraving_page_btn_home_label = lv_label_create(ui->engraving_page_btn_home);
	lv_label_set_text(ui->engraving_page_btn_home_label, "Home");
	lv_obj_set_style_pad_all(ui->engraving_page_btn_home, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->engraving_page_btn_home_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes engraving_page_btn_position
	ui->engraving_page_btn_position = lv_btn_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_btn_position, 252, 188);
	lv_obj_set_size(ui->engraving_page_btn_position, 212, 37);
	lv_obj_set_scrollbar_mode(ui->engraving_page_btn_position, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_btn_position_main_main_default
	static lv_style_t style_engraving_page_btn_position_main_main_default;
	if (style_engraving_page_btn_position_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_btn_position_main_main_default);
	else
		lv_style_init(&style_engraving_page_btn_position_main_main_default);
	lv_style_set_radius(&style_engraving_page_btn_position_main_main_default, 20);
	lv_style_set_bg_color(&style_engraving_page_btn_position_main_main_default, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&style_engraving_page_btn_position_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_btn_position_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_btn_position_main_main_default, 255);
	lv_style_set_shadow_width(&style_engraving_page_btn_position_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_btn_position_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_btn_position_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_btn_position_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_btn_position_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_btn_position_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_page_btn_position_main_main_default, lv_color_make(0xFF, 0x57, 0x00));
	lv_style_set_border_width(&style_engraving_page_btn_position_main_main_default, 1);
	lv_style_set_border_opa(&style_engraving_page_btn_position_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_page_btn_position_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_page_btn_position_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_engraving_page_btn_position_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->engraving_page_btn_position, &style_engraving_page_btn_position_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->engraving_page_btn_position_label = lv_label_create(ui->engraving_page_btn_position);
	lv_label_set_text(ui->engraving_page_btn_position_label, "Position");
	lv_obj_set_style_pad_all(ui->engraving_page_btn_position, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->engraving_page_btn_position_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes engraving_page_btn_start
	ui->engraving_page_btn_start = lv_btn_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_btn_start, 270, 240);
	lv_obj_set_size(ui->engraving_page_btn_start, 175, 50);
	lv_obj_set_scrollbar_mode(ui->engraving_page_btn_start, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_btn_start_main_main_default
	static lv_style_t style_engraving_page_btn_start_main_main_default;
	if (style_engraving_page_btn_start_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_btn_start_main_main_default);
	else
		lv_style_init(&style_engraving_page_btn_start_main_main_default);
	lv_style_set_radius(&style_engraving_page_btn_start_main_main_default, 25);
	lv_style_set_bg_color(&style_engraving_page_btn_start_main_main_default, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&style_engraving_page_btn_start_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_btn_start_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_btn_start_main_main_default, 255);
	lv_style_set_shadow_width(&style_engraving_page_btn_start_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_btn_start_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_btn_start_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_btn_start_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_btn_start_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_btn_start_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_page_btn_start_main_main_default, lv_color_make(0xff, 0x57, 0x00));
	lv_style_set_border_width(&style_engraving_page_btn_start_main_main_default, 2);
	lv_style_set_border_opa(&style_engraving_page_btn_start_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_page_btn_start_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_page_btn_start_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_engraving_page_btn_start_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->engraving_page_btn_start, &style_engraving_page_btn_start_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->engraving_page_btn_start_label = lv_label_create(ui->engraving_page_btn_start);
	lv_label_set_text(ui->engraving_page_btn_start_label, "Start");
	lv_obj_set_style_pad_all(ui->engraving_page_btn_start, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->engraving_page_btn_start_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes engraving_page_label_1
	ui->engraving_page_label_1 = lv_label_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_label_1, 10, 22);
	lv_obj_set_size(ui->engraving_page_label_1, 135, 33);
	lv_obj_set_scrollbar_mode(ui->engraving_page_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->engraving_page_label_1, "Engraving-");
	lv_label_set_long_mode(ui->engraving_page_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_label_1_main_main_default
	static lv_style_t style_engraving_page_label_1_main_main_default;
	if (style_engraving_page_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_label_1_main_main_default);
	else
		lv_style_init(&style_engraving_page_label_1_main_main_default);
	lv_style_set_radius(&style_engraving_page_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_engraving_page_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_engraving_page_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_label_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_engraving_page_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_engraving_page_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_page_label_1_main_main_default, &lv_font_montserratMedium_20);
	lv_style_set_text_letter_space(&style_engraving_page_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_engraving_page_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_engraving_page_label_1_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_engraving_page_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_engraving_page_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_engraving_page_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_engraving_page_label_1_main_main_default, 0);
	lv_obj_add_style(ui->engraving_page_label_1, &style_engraving_page_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes engraving_page_label_2
	ui->engraving_page_label_2 = lv_label_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_label_2, 141, 26);
	lv_obj_set_size(ui->engraving_page_label_2, 110, 25);
	lv_obj_set_scrollbar_mode(ui->engraving_page_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->engraving_page_label_2, "Filename");
	lv_label_set_long_mode(ui->engraving_page_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_label_2_main_main_default
	static lv_style_t style_engraving_page_label_2_main_main_default;
	if (style_engraving_page_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_label_2_main_main_default);
	else
		lv_style_init(&style_engraving_page_label_2_main_main_default);
	lv_style_set_radius(&style_engraving_page_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_engraving_page_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_engraving_page_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_label_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_engraving_page_label_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_label_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_engraving_page_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_page_label_2_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_letter_space(&style_engraving_page_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_engraving_page_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_engraving_page_label_2_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_engraving_page_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_engraving_page_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_engraving_page_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_engraving_page_label_2_main_main_default, 0);
	lv_obj_add_style(ui->engraving_page_label_2, &style_engraving_page_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes engraving_page_btn_5
	ui->engraving_page_btn_5 = lv_btn_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_btn_5, 364, 13);
	lv_obj_set_size(ui->engraving_page_btn_5, 100, 50);
	lv_obj_set_scrollbar_mode(ui->engraving_page_btn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_btn_5_main_main_default
	static lv_style_t style_engraving_page_btn_5_main_main_default;
	if (style_engraving_page_btn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_btn_5_main_main_default);
	else
		lv_style_init(&style_engraving_page_btn_5_main_main_default);
	lv_style_set_radius(&style_engraving_page_btn_5_main_main_default, 20);
	lv_style_set_bg_color(&style_engraving_page_btn_5_main_main_default, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&style_engraving_page_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_btn_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_btn_5_main_main_default, 255);
	lv_style_set_shadow_width(&style_engraving_page_btn_5_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_btn_5_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_btn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_btn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_btn_5_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_page_btn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_engraving_page_btn_5_main_main_default, 1);
	lv_style_set_border_opa(&style_engraving_page_btn_5_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_page_btn_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_engraving_page_btn_5_main_main_default, &lv_font_montserratMedium_16);
	lv_style_set_text_align(&style_engraving_page_btn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->engraving_page_btn_5, &style_engraving_page_btn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->engraving_page_btn_5_label = lv_label_create(ui->engraving_page_btn_5);
	lv_label_set_text(ui->engraving_page_btn_5_label, "Back");
	lv_obj_set_style_pad_all(ui->engraving_page_btn_5, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->engraving_page_btn_5_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes engraving_page_img_1
	ui->engraving_page_img_1 = lv_img_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_img_1, 30, 62);
	lv_obj_set_size(ui->engraving_page_img_1, 184, 185);
	lv_obj_set_scrollbar_mode(ui->engraving_page_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_img_1_main_main_default
	static lv_style_t style_engraving_page_img_1_main_main_default;
	if (style_engraving_page_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_img_1_main_main_default);
	else
		lv_style_init(&style_engraving_page_img_1_main_main_default);
	lv_style_set_img_recolor(&style_engraving_page_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_engraving_page_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_engraving_page_img_1_main_main_default, 255);
	lv_obj_add_style(ui->engraving_page_img_1, &style_engraving_page_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(ui->engraving_page_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(ui->engraving_page_img_1,&_move_184x185);
	lv_img_set_pivot(ui->engraving_page_img_1, 50,50);
	lv_img_set_angle(ui->engraving_page_img_1, 0);

	//Write codes engraving_page_imgbtn_1
	ui->engraving_page_imgbtn_1 = lv_imgbtn_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_imgbtn_1, 11, 262);
	lv_obj_set_size(ui->engraving_page_imgbtn_1, 222, 38);
	lv_obj_set_scrollbar_mode(ui->engraving_page_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_imgbtn_1_main_main_default
	static lv_style_t style_engraving_page_imgbtn_1_main_main_default;
	if (style_engraving_page_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_engraving_page_imgbtn_1_main_main_default);
	lv_style_set_shadow_width(&style_engraving_page_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_imgbtn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_imgbtn_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_imgbtn_1_main_main_default, 0);
	lv_style_set_text_color(&style_engraving_page_imgbtn_1_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_engraving_page_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_page_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_engraving_page_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_engraving_page_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->engraving_page_imgbtn_1, &style_engraving_page_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_engraving_page_imgbtn_1_main_main_pressed
	static lv_style_t style_engraving_page_imgbtn_1_main_main_pressed;
	if (style_engraving_page_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_engraving_page_imgbtn_1_main_main_pressed);
	lv_style_set_shadow_width(&style_engraving_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_engraving_page_imgbtn_1_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_imgbtn_1_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_engraving_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_text_color(&style_engraving_page_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_engraving_page_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_engraving_page_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->engraving_page_imgbtn_1, &style_engraving_page_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_engraving_page_imgbtn_1_main_main_checked
	static lv_style_t style_engraving_page_imgbtn_1_main_main_checked;
	if (style_engraving_page_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_engraving_page_imgbtn_1_main_main_checked);
	lv_style_set_shadow_width(&style_engraving_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_color(&style_engraving_page_imgbtn_1_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_imgbtn_1_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_engraving_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_text_color(&style_engraving_page_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_engraving_page_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_engraving_page_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->engraving_page_imgbtn_1, &style_engraving_page_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->engraving_page_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_png_move_step_10mm_alpha_222x38, NULL);
	lv_obj_add_flag(ui->engraving_page_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes engraving_page_btn_6
	ui->engraving_page_btn_6 = lv_btn_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_btn_6, 75, 70);
	lv_obj_set_size(ui->engraving_page_btn_6, 95, 47);
	lv_obj_set_scrollbar_mode(ui->engraving_page_btn_6, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_btn_6_main_main_default
	static lv_style_t style_engraving_page_btn_6_main_main_default;
	if (style_engraving_page_btn_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_btn_6_main_main_default);
	else
		lv_style_init(&style_engraving_page_btn_6_main_main_default);
	lv_style_set_radius(&style_engraving_page_btn_6_main_main_default, 5);
	lv_style_set_bg_color(&style_engraving_page_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_engraving_page_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_btn_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_btn_6_main_main_default, 0);
	lv_style_set_shadow_width(&style_engraving_page_btn_6_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_btn_6_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_btn_6_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_btn_6_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_btn_6_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_page_btn_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_engraving_page_btn_6_main_main_default, 0);
	lv_style_set_border_opa(&style_engraving_page_btn_6_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_page_btn_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_engraving_page_btn_6_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->engraving_page_btn_6, &style_engraving_page_btn_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->engraving_page_btn_6_label = lv_label_create(ui->engraving_page_btn_6);
	lv_label_set_text(ui->engraving_page_btn_6_label, "");
	lv_obj_set_style_pad_all(ui->engraving_page_btn_6, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->engraving_page_btn_6_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes engraving_page_btn_7
	ui->engraving_page_btn_7 = lv_btn_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_btn_7, 75, 196);
	lv_obj_set_size(ui->engraving_page_btn_7, 95, 47);
	lv_obj_set_scrollbar_mode(ui->engraving_page_btn_7, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_btn_7_main_main_default
	static lv_style_t style_engraving_page_btn_7_main_main_default;
	if (style_engraving_page_btn_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_btn_7_main_main_default);
	else
		lv_style_init(&style_engraving_page_btn_7_main_main_default);
	lv_style_set_radius(&style_engraving_page_btn_7_main_main_default, 5);
	lv_style_set_bg_color(&style_engraving_page_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_engraving_page_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_btn_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_btn_7_main_main_default, 0);
	lv_style_set_shadow_width(&style_engraving_page_btn_7_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_btn_7_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_btn_7_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_btn_7_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_btn_7_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_page_btn_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_engraving_page_btn_7_main_main_default, 0);
	lv_style_set_border_opa(&style_engraving_page_btn_7_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_page_btn_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_engraving_page_btn_7_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->engraving_page_btn_7, &style_engraving_page_btn_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->engraving_page_btn_7_label = lv_label_create(ui->engraving_page_btn_7);
	lv_label_set_text(ui->engraving_page_btn_7_label, "");
	lv_obj_set_style_pad_all(ui->engraving_page_btn_7, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->engraving_page_btn_7_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes engraving_page_btn_8
	ui->engraving_page_btn_8 = lv_btn_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_btn_8, 30, 127);
	lv_obj_set_size(ui->engraving_page_btn_8, 55, 66);
	lv_obj_set_scrollbar_mode(ui->engraving_page_btn_8, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_btn_8_main_main_default
	static lv_style_t style_engraving_page_btn_8_main_main_default;
	if (style_engraving_page_btn_8_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_btn_8_main_main_default);
	else
		lv_style_init(&style_engraving_page_btn_8_main_main_default);
	lv_style_set_radius(&style_engraving_page_btn_8_main_main_default, 5);
	lv_style_set_bg_color(&style_engraving_page_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_engraving_page_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_btn_8_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_btn_8_main_main_default, 0);
	lv_style_set_shadow_width(&style_engraving_page_btn_8_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_btn_8_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_btn_8_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_btn_8_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_btn_8_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_page_btn_8_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_engraving_page_btn_8_main_main_default, 0);
	lv_style_set_border_opa(&style_engraving_page_btn_8_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_page_btn_8_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_engraving_page_btn_8_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->engraving_page_btn_8, &style_engraving_page_btn_8_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->engraving_page_btn_8_label = lv_label_create(ui->engraving_page_btn_8);
	lv_label_set_text(ui->engraving_page_btn_8_label, "");
	lv_obj_set_style_pad_all(ui->engraving_page_btn_8, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->engraving_page_btn_8_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes engraving_page_btn_9
	ui->engraving_page_btn_9 = lv_btn_create(ui->engraving_page);
	lv_obj_set_pos(ui->engraving_page_btn_9, 157, 127);
	lv_obj_set_size(ui->engraving_page_btn_9, 53, 61);
	lv_obj_set_scrollbar_mode(ui->engraving_page_btn_9, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_engraving_page_btn_9_main_main_default
	static lv_style_t style_engraving_page_btn_9_main_main_default;
	if (style_engraving_page_btn_9_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_page_btn_9_main_main_default);
	else
		lv_style_init(&style_engraving_page_btn_9_main_main_default);
	lv_style_set_radius(&style_engraving_page_btn_9_main_main_default, 5);
	lv_style_set_bg_color(&style_engraving_page_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_engraving_page_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_engraving_page_btn_9_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_engraving_page_btn_9_main_main_default, 0);
	lv_style_set_shadow_width(&style_engraving_page_btn_9_main_main_default, 0);
	lv_style_set_shadow_color(&style_engraving_page_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_engraving_page_btn_9_main_main_default, 255);
	lv_style_set_shadow_spread(&style_engraving_page_btn_9_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_engraving_page_btn_9_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_engraving_page_btn_9_main_main_default, 0);
	lv_style_set_border_color(&style_engraving_page_btn_9_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_engraving_page_btn_9_main_main_default, 0);
	lv_style_set_border_opa(&style_engraving_page_btn_9_main_main_default, 255);
	lv_style_set_text_color(&style_engraving_page_btn_9_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_align(&style_engraving_page_btn_9_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(ui->engraving_page_btn_9, &style_engraving_page_btn_9_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	ui->engraving_page_btn_9_label = lv_label_create(ui->engraving_page_btn_9);
	lv_label_set_text(ui->engraving_page_btn_9_label, "");
	lv_obj_set_style_pad_all(ui->engraving_page_btn_9, 0, LV_STATE_DEFAULT);
	lv_obj_align(ui->engraving_page_btn_9_label, LV_ALIGN_CENTER, 0, 0);

	//Init events for screen
	events_init_engraving_page(ui);
}