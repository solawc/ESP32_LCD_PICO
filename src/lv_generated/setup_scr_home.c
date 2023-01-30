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


void setup_scr_home(lv_ui *ui){

	//Write codes home
	ui->home = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->home, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_main_main_default
	static lv_style_t style_home_main_main_default;
	if (style_home_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_main_main_default);
	else
		lv_style_init(&style_home_main_main_default);
	lv_style_set_bg_color(&style_home_main_main_default, lv_color_make(0x1d, 0x23, 0x32));
	lv_style_set_bg_opa(&style_home_main_main_default, 255);
	lv_obj_add_style(ui->home, &style_home_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_imgbtn_engraving
	ui->home_imgbtn_engraving = lv_imgbtn_create(ui->home);
	lv_obj_set_pos(ui->home_imgbtn_engraving, 38, 112);
	lv_obj_set_size(ui->home_imgbtn_engraving, 109, 109);
	lv_obj_set_scrollbar_mode(ui->home_imgbtn_engraving, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtn_engraving_main_main_default
	static lv_style_t style_home_imgbtn_engraving_main_main_default;
	if (style_home_imgbtn_engraving_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtn_engraving_main_main_default);
	else
		lv_style_init(&style_home_imgbtn_engraving_main_main_default);
	lv_style_set_text_color(&style_home_imgbtn_engraving_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_home_imgbtn_engraving_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtn_engraving_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgbtn_engraving_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgbtn_engraving_main_main_default, 255);
	lv_obj_add_style(ui->home_imgbtn_engraving, &style_home_imgbtn_engraving_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtn_engraving_main_main_pressed
	static lv_style_t style_home_imgbtn_engraving_main_main_pressed;
	if (style_home_imgbtn_engraving_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtn_engraving_main_main_pressed);
	else
		lv_style_init(&style_home_imgbtn_engraving_main_main_pressed);
	lv_style_set_text_color(&style_home_imgbtn_engraving_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_home_imgbtn_engraving_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtn_engraving_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtn_engraving_main_main_pressed, 0);
	lv_style_set_img_opa(&style_home_imgbtn_engraving_main_main_pressed, 255);
	lv_obj_add_style(ui->home_imgbtn_engraving, &style_home_imgbtn_engraving_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtn_engraving_main_main_checked
	static lv_style_t style_home_imgbtn_engraving_main_main_checked;
	if (style_home_imgbtn_engraving_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtn_engraving_main_main_checked);
	else
		lv_style_init(&style_home_imgbtn_engraving_main_main_checked);
	lv_style_set_text_color(&style_home_imgbtn_engraving_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_home_imgbtn_engraving_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtn_engraving_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtn_engraving_main_main_checked, 0);
	lv_style_set_img_opa(&style_home_imgbtn_engraving_main_main_checked, 255);
	lv_obj_add_style(ui->home_imgbtn_engraving, &style_home_imgbtn_engraving_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->home_imgbtn_engraving, LV_IMGBTN_STATE_RELEASED, NULL, &_Engraving_alpha_109x109, NULL);
	lv_obj_add_flag(ui->home_imgbtn_engraving, LV_OBJ_FLAG_CHECKABLE);

	//Write codes home_imgbtn_control
	ui->home_imgbtn_control = lv_imgbtn_create(ui->home);
	lv_obj_set_pos(ui->home_imgbtn_control, 183, 112);
	lv_obj_set_size(ui->home_imgbtn_control, 109, 109);
	lv_obj_set_scrollbar_mode(ui->home_imgbtn_control, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtn_control_main_main_default
	static lv_style_t style_home_imgbtn_control_main_main_default;
	if (style_home_imgbtn_control_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtn_control_main_main_default);
	else
		lv_style_init(&style_home_imgbtn_control_main_main_default);
	lv_style_set_text_color(&style_home_imgbtn_control_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_home_imgbtn_control_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtn_control_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgbtn_control_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgbtn_control_main_main_default, 255);
	lv_obj_add_style(ui->home_imgbtn_control, &style_home_imgbtn_control_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtn_control_main_main_pressed
	static lv_style_t style_home_imgbtn_control_main_main_pressed;
	if (style_home_imgbtn_control_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtn_control_main_main_pressed);
	else
		lv_style_init(&style_home_imgbtn_control_main_main_pressed);
	lv_style_set_text_color(&style_home_imgbtn_control_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_home_imgbtn_control_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtn_control_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtn_control_main_main_pressed, 0);
	lv_style_set_img_opa(&style_home_imgbtn_control_main_main_pressed, 255);
	lv_obj_add_style(ui->home_imgbtn_control, &style_home_imgbtn_control_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtn_control_main_main_checked
	static lv_style_t style_home_imgbtn_control_main_main_checked;
	if (style_home_imgbtn_control_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtn_control_main_main_checked);
	else
		lv_style_init(&style_home_imgbtn_control_main_main_checked);
	lv_style_set_text_color(&style_home_imgbtn_control_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_home_imgbtn_control_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtn_control_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtn_control_main_main_checked, 0);
	lv_style_set_img_opa(&style_home_imgbtn_control_main_main_checked, 255);
	lv_obj_add_style(ui->home_imgbtn_control, &style_home_imgbtn_control_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->home_imgbtn_control, LV_IMGBTN_STATE_RELEASED, NULL, &_control_alpha_109x109, NULL);
	lv_obj_add_flag(ui->home_imgbtn_control, LV_OBJ_FLAG_CHECKABLE);

	//Write codes home_imgbtn_tools
	ui->home_imgbtn_tools = lv_imgbtn_create(ui->home);
	lv_obj_set_pos(ui->home_imgbtn_tools, 323.5, 112);
	lv_obj_set_size(ui->home_imgbtn_tools, 109, 109);
	lv_obj_set_scrollbar_mode(ui->home_imgbtn_tools, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtn_tools_main_main_default
	static lv_style_t style_home_imgbtn_tools_main_main_default;
	if (style_home_imgbtn_tools_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtn_tools_main_main_default);
	else
		lv_style_init(&style_home_imgbtn_tools_main_main_default);
	lv_style_set_text_color(&style_home_imgbtn_tools_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_home_imgbtn_tools_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtn_tools_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_home_imgbtn_tools_main_main_default, 0);
	lv_style_set_img_opa(&style_home_imgbtn_tools_main_main_default, 255);
	lv_obj_add_style(ui->home_imgbtn_tools, &style_home_imgbtn_tools_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtn_tools_main_main_pressed
	static lv_style_t style_home_imgbtn_tools_main_main_pressed;
	if (style_home_imgbtn_tools_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtn_tools_main_main_pressed);
	else
		lv_style_init(&style_home_imgbtn_tools_main_main_pressed);
	lv_style_set_text_color(&style_home_imgbtn_tools_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_home_imgbtn_tools_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtn_tools_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtn_tools_main_main_pressed, 0);
	lv_style_set_img_opa(&style_home_imgbtn_tools_main_main_pressed, 255);
	lv_obj_add_style(ui->home_imgbtn_tools, &style_home_imgbtn_tools_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtn_tools_main_main_checked
	static lv_style_t style_home_imgbtn_tools_main_main_checked;
	if (style_home_imgbtn_tools_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_home_imgbtn_tools_main_main_checked);
	else
		lv_style_init(&style_home_imgbtn_tools_main_main_checked);
	lv_style_set_text_color(&style_home_imgbtn_tools_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_home_imgbtn_tools_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_home_imgbtn_tools_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_home_imgbtn_tools_main_main_checked, 0);
	lv_style_set_img_opa(&style_home_imgbtn_tools_main_main_checked, 255);
	lv_obj_add_style(ui->home_imgbtn_tools, &style_home_imgbtn_tools_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->home_imgbtn_tools, LV_IMGBTN_STATE_RELEASED, NULL, &_tool_alpha_109x109, NULL);
	lv_obj_add_flag(ui->home_imgbtn_tools, LV_OBJ_FLAG_CHECKABLE);

	//Write codes home_label_1
	ui->home_label_1 = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_1, 24, 239);
	lv_obj_set_size(ui->home_label_1, 137, 20);
	lv_obj_set_scrollbar_mode(ui->home_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_1, "Engraving");
	lv_label_set_long_mode(ui->home_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_1_main_main_default
	static lv_style_t style_home_label_1_main_main_default;
	if (style_home_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_1_main_main_default);
	else
		lv_style_init(&style_home_label_1_main_main_default);
	lv_style_set_radius(&style_home_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_1_main_main_default, &lv_font_montserratMedium_15);
	lv_style_set_text_letter_space(&style_home_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_1_main_main_default, 0);
	lv_obj_add_style(ui->home_label_1, &style_home_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_3
	ui->home_label_3 = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_3, 328, 238);
	lv_obj_set_size(ui->home_label_3, 100, 23);
	lv_obj_set_scrollbar_mode(ui->home_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_3, "Tools");
	lv_label_set_long_mode(ui->home_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_3_main_main_default
	static lv_style_t style_home_label_3_main_main_default;
	if (style_home_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_3_main_main_default);
	else
		lv_style_init(&style_home_label_3_main_main_default);
	lv_style_set_radius(&style_home_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_3_main_main_default, &lv_font_montserratMedium_15);
	lv_style_set_text_letter_space(&style_home_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_3_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_3_main_main_default, 0);
	lv_obj_add_style(ui->home_label_3, &style_home_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_2
	ui->home_label_2 = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_2, 187.5, 239);
	lv_obj_set_size(ui->home_label_2, 100, 22);
	lv_obj_set_scrollbar_mode(ui->home_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_2, "Control");
	lv_label_set_long_mode(ui->home_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_2_main_main_default
	static lv_style_t style_home_label_2_main_main_default;
	if (style_home_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_2_main_main_default);
	else
		lv_style_init(&style_home_label_2_main_main_default);
	lv_style_set_radius(&style_home_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_2_main_main_default, &lv_font_montserratMedium_15);
	lv_style_set_text_letter_space(&style_home_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_2_main_main_default, 0);
	lv_obj_add_style(ui->home_label_2, &style_home_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes home_label_4
	ui->home_label_4 = lv_label_create(ui->home);
	lv_obj_set_pos(ui->home_label_4, 158, 50);
	lv_obj_set_size(ui->home_label_4, 170, 35);
	lv_obj_set_scrollbar_mode(ui->home_label_4, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->home_label_4, "MakeGo");
	lv_label_set_long_mode(ui->home_label_4, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_home_label_4_main_main_default
	static lv_style_t style_home_label_4_main_main_default;
	if (style_home_label_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_home_label_4_main_main_default);
	else
		lv_style_init(&style_home_label_4_main_main_default);
	lv_style_set_radius(&style_home_label_4_main_main_default, 0);
	lv_style_set_bg_color(&style_home_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_home_label_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_home_label_4_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_home_label_4_main_main_default, 0);
	lv_style_set_text_color(&style_home_label_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_home_label_4_main_main_default, &lv_font_Acme_Regular_30);
	lv_style_set_text_letter_space(&style_home_label_4_main_main_default, 2);
	lv_style_set_text_line_space(&style_home_label_4_main_main_default, 0);
	lv_style_set_text_align(&style_home_label_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_home_label_4_main_main_default, 0);
	lv_style_set_pad_right(&style_home_label_4_main_main_default, 0);
	lv_style_set_pad_top(&style_home_label_4_main_main_default, 0);
	lv_style_set_pad_bottom(&style_home_label_4_main_main_default, 0);
	lv_obj_add_style(ui->home_label_4, &style_home_label_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_home(ui);
}