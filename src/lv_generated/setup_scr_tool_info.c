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


void setup_scr_tool_info(lv_ui *ui){

	//Write codes tool_info
	ui->tool_info = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->tool_info, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_info_main_main_default
	static lv_style_t style_tool_info_main_main_default;
	if (style_tool_info_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_info_main_main_default);
	else
		lv_style_init(&style_tool_info_main_main_default);
	lv_style_set_bg_color(&style_tool_info_main_main_default, lv_color_make(0x1d, 0x23, 0x32));
	lv_style_set_bg_opa(&style_tool_info_main_main_default, 255);
	lv_obj_add_style(ui->tool_info, &style_tool_info_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_info_label_1
	ui->tool_info_label_1 = lv_label_create(ui->tool_info);
	lv_obj_set_pos(ui->tool_info_label_1, 15, 28);
	lv_obj_set_size(ui->tool_info_label_1, 60, 18);
	lv_obj_set_scrollbar_mode(ui->tool_info_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_info_label_1, "Info");
	lv_label_set_long_mode(ui->tool_info_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_info_label_1_main_main_default
	static lv_style_t style_tool_info_label_1_main_main_default;
	if (style_tool_info_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_info_label_1_main_main_default);
	else
		lv_style_init(&style_tool_info_label_1_main_main_default);
	lv_style_set_radius(&style_tool_info_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_info_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_info_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_info_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_info_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_tool_info_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_info_label_1_main_main_default, &lv_font_montserratMedium_18);
	lv_style_set_text_letter_space(&style_tool_info_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_info_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_tool_info_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_tool_info_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_info_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_info_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_info_label_1_main_main_default, 0);
	lv_obj_add_style(ui->tool_info_label_1, &style_tool_info_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_info_label_3
	ui->tool_info_label_3 = lv_label_create(ui->tool_info);
	lv_obj_set_pos(ui->tool_info_label_3, 22, 111);
	lv_obj_set_size(ui->tool_info_label_3, 115, 26);
	lv_obj_set_scrollbar_mode(ui->tool_info_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_info_label_3, "Machine Size：");
	lv_label_set_long_mode(ui->tool_info_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_info_label_3_main_main_default
	static lv_style_t style_tool_info_label_3_main_main_default;
	if (style_tool_info_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_info_label_3_main_main_default);
	else
		lv_style_init(&style_tool_info_label_3_main_main_default);
	lv_style_set_radius(&style_tool_info_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_info_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_info_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_info_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_info_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_tool_info_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_info_label_3_main_main_default, &lv_font_Acme_Regular_12);
	lv_style_set_text_letter_space(&style_tool_info_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_info_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_tool_info_label_3_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_tool_info_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_info_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_info_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_info_label_3_main_main_default, 0);
	lv_obj_add_style(ui->tool_info_label_3, &style_tool_info_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_info_label_7
	ui->tool_info_label_7 = lv_label_create(ui->tool_info);
	lv_obj_set_pos(ui->tool_info_label_7, 22, 236);
	lv_obj_set_size(ui->tool_info_label_7, 100, 32);
	lv_obj_set_scrollbar_mode(ui->tool_info_label_7, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_info_label_7, "default");
	lv_label_set_long_mode(ui->tool_info_label_7, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_info_label_7_main_main_default
	static lv_style_t style_tool_info_label_7_main_main_default;
	if (style_tool_info_label_7_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_info_label_7_main_main_default);
	else
		lv_style_init(&style_tool_info_label_7_main_main_default);
	lv_style_set_radius(&style_tool_info_label_7_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_info_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_info_label_7_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_info_label_7_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_info_label_7_main_main_default, 0);
	lv_style_set_text_color(&style_tool_info_label_7_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_info_label_7_main_main_default, &lv_font_Acme_Regular_12);
	lv_style_set_text_letter_space(&style_tool_info_label_7_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_info_label_7_main_main_default, 0);
	lv_style_set_text_align(&style_tool_info_label_7_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_tool_info_label_7_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_info_label_7_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_info_label_7_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_info_label_7_main_main_default, 0);
	lv_obj_add_style(ui->tool_info_label_7, &style_tool_info_label_7_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_info_label_6
	ui->tool_info_label_6 = lv_label_create(ui->tool_info);
	lv_obj_set_pos(ui->tool_info_label_6, 22, 204);
	lv_obj_set_size(ui->tool_info_label_6, 100, 32);
	lv_obj_set_scrollbar_mode(ui->tool_info_label_6, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_info_label_6, "E-mail：");
	lv_label_set_long_mode(ui->tool_info_label_6, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_info_label_6_main_main_default
	static lv_style_t style_tool_info_label_6_main_main_default;
	if (style_tool_info_label_6_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_info_label_6_main_main_default);
	else
		lv_style_init(&style_tool_info_label_6_main_main_default);
	lv_style_set_radius(&style_tool_info_label_6_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_info_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_info_label_6_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_info_label_6_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_info_label_6_main_main_default, 0);
	lv_style_set_text_color(&style_tool_info_label_6_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_info_label_6_main_main_default, &lv_font_Acme_Regular_12);
	lv_style_set_text_letter_space(&style_tool_info_label_6_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_info_label_6_main_main_default, 0);
	lv_style_set_text_align(&style_tool_info_label_6_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_tool_info_label_6_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_info_label_6_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_info_label_6_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_info_label_6_main_main_default, 0);
	lv_obj_add_style(ui->tool_info_label_6, &style_tool_info_label_6_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_info_label_5
	ui->tool_info_label_5 = lv_label_create(ui->tool_info);
	lv_obj_set_pos(ui->tool_info_label_5, 22, 175);
	lv_obj_set_size(ui->tool_info_label_5, 76, 26);
	lv_obj_set_scrollbar_mode(ui->tool_info_label_5, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_info_label_5, "IP：");
	lv_label_set_long_mode(ui->tool_info_label_5, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_info_label_5_main_main_default
	static lv_style_t style_tool_info_label_5_main_main_default;
	if (style_tool_info_label_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_info_label_5_main_main_default);
	else
		lv_style_init(&style_tool_info_label_5_main_main_default);
	lv_style_set_radius(&style_tool_info_label_5_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_info_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_info_label_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_info_label_5_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_info_label_5_main_main_default, 0);
	lv_style_set_text_color(&style_tool_info_label_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_info_label_5_main_main_default, &lv_font_Acme_Regular_12);
	lv_style_set_text_letter_space(&style_tool_info_label_5_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_info_label_5_main_main_default, 0);
	lv_style_set_text_align(&style_tool_info_label_5_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_tool_info_label_5_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_info_label_5_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_info_label_5_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_info_label_5_main_main_default, 0);
	lv_obj_add_style(ui->tool_info_label_5, &style_tool_info_label_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_info_label_4
	ui->tool_info_label_4 = lv_label_create(ui->tool_info);
	lv_obj_set_pos(ui->tool_info_label_4, 22, 143);
	lv_obj_set_size(ui->tool_info_label_4, 100, 32);
	lv_obj_set_scrollbar_mode(ui->tool_info_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_info_label_4, "Version：");
	lv_label_set_long_mode(ui->tool_info_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_info_label_4_main_main_default
	static lv_style_t style_tool_info_label_4_main_main_default;
	if (style_tool_info_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_info_label_4_main_main_default);
	else
		lv_style_init(&style_tool_info_label_4_main_main_default);
	lv_style_set_radius(&style_tool_info_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_info_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_info_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_info_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_info_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_tool_info_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_info_label_4_main_main_default, &lv_font_Acme_Regular_12);
	lv_style_set_text_letter_space(&style_tool_info_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_info_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_tool_info_label_4_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_tool_info_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_info_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_info_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_info_label_4_main_main_default, 0);
	lv_obj_add_style(ui->tool_info_label_4, &style_tool_info_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_info_label_2
	ui->tool_info_label_2 = lv_label_create(ui->tool_info);
	lv_obj_set_pos(ui->tool_info_label_2, 15, 81);
	lv_obj_set_size(ui->tool_info_label_2, 131, 16);
	lv_obj_set_scrollbar_mode(ui->tool_info_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_info_label_2, "Machine name：");
	lv_label_set_long_mode(ui->tool_info_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_info_label_2_main_main_default
	static lv_style_t style_tool_info_label_2_main_main_default;
	if (style_tool_info_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_info_label_2_main_main_default);
	else
		lv_style_init(&style_tool_info_label_2_main_main_default);
	lv_style_set_radius(&style_tool_info_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_info_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_info_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_info_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_info_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_tool_info_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_info_label_2_main_main_default, &lv_font_Acme_Regular_12);
	lv_style_set_text_letter_space(&style_tool_info_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_info_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_tool_info_label_2_main_main_default, LV_TEXT_ALIGN_LEFT);
	lv_style_set_pad_left(&style_tool_info_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_info_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_info_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_info_label_2_main_main_default, 0);
	lv_obj_add_style(ui->tool_info_label_2, &style_tool_info_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_info_imgbtn_3
	ui->tool_info_imgbtn_3 = lv_imgbtn_create(ui->tool_info);
	lv_obj_set_pos(ui->tool_info_imgbtn_3, 420, 17);
	lv_obj_set_size(ui->tool_info_imgbtn_3, 25, 21);
	lv_obj_set_scrollbar_mode(ui->tool_info_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_info_imgbtn_3_main_main_default
	static lv_style_t style_tool_info_imgbtn_3_main_main_default;
	if (style_tool_info_imgbtn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_info_imgbtn_3_main_main_default);
	else
		lv_style_init(&style_tool_info_imgbtn_3_main_main_default);
	lv_style_set_text_color(&style_tool_info_imgbtn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_info_imgbtn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_info_imgbtn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_info_imgbtn_3_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_info_imgbtn_3_main_main_default, 255);
	lv_obj_add_style(ui->tool_info_imgbtn_3, &style_tool_info_imgbtn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_info_imgbtn_3_main_main_pressed
	static lv_style_t style_tool_info_imgbtn_3_main_main_pressed;
	if (style_tool_info_imgbtn_3_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_info_imgbtn_3_main_main_pressed);
	else
		lv_style_init(&style_tool_info_imgbtn_3_main_main_pressed);
	lv_style_set_text_color(&style_tool_info_imgbtn_3_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_info_imgbtn_3_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_info_imgbtn_3_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_info_imgbtn_3_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_info_imgbtn_3_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_info_imgbtn_3, &style_tool_info_imgbtn_3_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_info_imgbtn_3_main_main_checked
	static lv_style_t style_tool_info_imgbtn_3_main_main_checked;
	if (style_tool_info_imgbtn_3_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_info_imgbtn_3_main_main_checked);
	else
		lv_style_init(&style_tool_info_imgbtn_3_main_main_checked);
	lv_style_set_text_color(&style_tool_info_imgbtn_3_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_info_imgbtn_3_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_info_imgbtn_3_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_info_imgbtn_3_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_info_imgbtn_3_main_main_checked, 255);
	lv_obj_add_style(ui->tool_info_imgbtn_3, &style_tool_info_imgbtn_3_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_info_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_25x21, NULL);
	lv_obj_add_flag(ui->tool_info_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);
}