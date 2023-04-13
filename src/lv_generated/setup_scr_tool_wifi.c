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
#include "./custom/wifi_grid.h"

void setup_scr_tool_wifi(lv_ui *ui){

	//Write codes tool_wifi
	ui->tool_wifi = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->tool_wifi, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_wifi_main_main_default
	static lv_style_t style_tool_wifi_main_main_default;
	if (style_tool_wifi_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_wifi_main_main_default);
	else
		lv_style_init(&style_tool_wifi_main_main_default);
	lv_style_set_bg_color(&style_tool_wifi_main_main_default, lv_color_make(0x1d, 0x23, 0x32));
	lv_style_set_bg_opa(&style_tool_wifi_main_main_default, 255);
	lv_obj_add_style(ui->tool_wifi, &style_tool_wifi_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_wifi_label_1
	ui->tool_wifi_label_1 = lv_label_create(ui->tool_wifi);
	lv_obj_set_pos(ui->tool_wifi_label_1, 15, 28);
	lv_obj_set_size(ui->tool_wifi_label_1, 60, 18);
	lv_obj_set_scrollbar_mode(ui->tool_wifi_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->tool_wifi_label_1, "Wifi");
	lv_label_set_long_mode(ui->tool_wifi_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_wifi_label_1_main_main_default
	static lv_style_t style_tool_wifi_label_1_main_main_default;
	if (style_tool_wifi_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_wifi_label_1_main_main_default);
	else
		lv_style_init(&style_tool_wifi_label_1_main_main_default);
	lv_style_set_radius(&style_tool_wifi_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_wifi_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_wifi_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_wifi_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_wifi_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_tool_wifi_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_wifi_label_1_main_main_default, &lv_font_montserratMedium_18);
	lv_style_set_text_letter_space(&style_tool_wifi_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_wifi_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_tool_wifi_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_tool_wifi_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_wifi_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_wifi_label_1_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_wifi_label_1_main_main_default, 0);
	lv_obj_add_style(ui->tool_wifi_label_1, &style_tool_wifi_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_wifi_imgbtn_3
	ui->tool_wifi_imgbtn_3 = lv_imgbtn_create(ui->tool_wifi);
	lv_obj_set_pos(ui->tool_wifi_imgbtn_3, 420, 17);
	lv_obj_set_size(ui->tool_wifi_imgbtn_3, 25, 21);
	lv_obj_set_scrollbar_mode(ui->tool_wifi_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_wifi_imgbtn_3_main_main_default
	static lv_style_t style_tool_wifi_imgbtn_3_main_main_default;
	if (style_tool_wifi_imgbtn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_wifi_imgbtn_3_main_main_default);
	else
		lv_style_init(&style_tool_wifi_imgbtn_3_main_main_default);
	lv_style_set_text_color(&style_tool_wifi_imgbtn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_tool_wifi_imgbtn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_wifi_imgbtn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_wifi_imgbtn_3_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_wifi_imgbtn_3_main_main_default, 255);
	lv_obj_add_style(ui->tool_wifi_imgbtn_3, &style_tool_wifi_imgbtn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_tool_wifi_imgbtn_3_main_main_pressed
	static lv_style_t style_tool_wifi_imgbtn_3_main_main_pressed;
	if (style_tool_wifi_imgbtn_3_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_tool_wifi_imgbtn_3_main_main_pressed);
	else
		lv_style_init(&style_tool_wifi_imgbtn_3_main_main_pressed);
	lv_style_set_text_color(&style_tool_wifi_imgbtn_3_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_wifi_imgbtn_3_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_wifi_imgbtn_3_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_wifi_imgbtn_3_main_main_pressed, 0);
	lv_style_set_img_opa(&style_tool_wifi_imgbtn_3_main_main_pressed, 255);
	lv_obj_add_style(ui->tool_wifi_imgbtn_3, &style_tool_wifi_imgbtn_3_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_tool_wifi_imgbtn_3_main_main_checked
	static lv_style_t style_tool_wifi_imgbtn_3_main_main_checked;
	if (style_tool_wifi_imgbtn_3_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_tool_wifi_imgbtn_3_main_main_checked);
	else
		lv_style_init(&style_tool_wifi_imgbtn_3_main_main_checked);
	lv_style_set_text_color(&style_tool_wifi_imgbtn_3_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_tool_wifi_imgbtn_3_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_tool_wifi_imgbtn_3_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_tool_wifi_imgbtn_3_main_main_checked, 0);
	lv_style_set_img_opa(&style_tool_wifi_imgbtn_3_main_main_checked, 255);
	lv_obj_add_style(ui->tool_wifi_imgbtn_3, &style_tool_wifi_imgbtn_3_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->tool_wifi_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &_return_alpha_25x21, NULL);
	lv_obj_add_flag(ui->tool_wifi_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);

	ui->tool_wifi_management_table = wifi_grid_init(ui->tool_wifi);
	lv_obj_set_size(ui->tool_wifi_management_table, 480, 237);

	// lv_obj_set_align(ui->tool_wifi_management_table, LV_ALIGN_CENTER);
	// lv_obj_align(ui->tool_wifi_management_table, LV_ALIGN_CENTER, 0, 10);
	lv_obj_set_pos(ui->tool_wifi_management_table, 0, 10);

    ui->tool_wifi_management_btn_next_page = lv_obj_create(ui->tool_wifi);
    lv_obj_set_size(ui->tool_wifi_management_btn_next_page, 29, 29);
    lv_obj_align(ui->tool_wifi_management_btn_next_page, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_set_style_bg_img_src(ui->tool_wifi_management_btn_next_page, LV_SYMBOL_RIGHT, 0);

    ui->tool_wifi_management_btn_last_page = lv_obj_create(ui->tool_wifi);
    lv_obj_set_size(ui->tool_wifi_management_btn_last_page, 29, 29);
    lv_obj_align_to(ui->tool_wifi_management_btn_last_page, ui->tool_wifi_management_btn_next_page, LV_ALIGN_OUT_LEFT_MID, -66, 0);
    lv_obj_set_style_bg_img_src(ui->tool_wifi_management_btn_last_page, LV_SYMBOL_LEFT, 0);	

}