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


void setup_scr_logo_page(lv_ui *ui){

	//Write codes logo_page
	ui->logo_page = lv_obj_create(NULL);
	lv_obj_set_scrollbar_mode(ui->logo_page, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_logo_page_main_main_default
	static lv_style_t style_logo_page_main_main_default;
	if (style_logo_page_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_logo_page_main_main_default);
	else
		lv_style_init(&style_logo_page_main_main_default);
	lv_style_set_bg_color(&style_logo_page_main_main_default, lv_color_make(0xFF, 0xFF, 0xFf));
	lv_style_set_bg_opa(&style_logo_page_main_main_default, 255);
	lv_obj_add_style(ui->logo_page, &style_logo_page_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes logo_page_logo_label
	ui->logo_page_logo_label = lv_label_create(ui->logo_page);
	lv_obj_set_pos(ui->logo_page_logo_label, 155, 133);
	lv_obj_set_size(ui->logo_page_logo_label, 186, 45);
	lv_obj_set_scrollbar_mode(ui->logo_page_logo_label, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->logo_page_logo_label, "MakeGo");
	lv_label_set_long_mode(ui->logo_page_logo_label, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_logo_page_logo_label_main_main_default
	static lv_style_t style_logo_page_logo_label_main_main_default;
	if (style_logo_page_logo_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_logo_page_logo_label_main_main_default);
	else
		lv_style_init(&style_logo_page_logo_label_main_main_default);
	lv_style_set_radius(&style_logo_page_logo_label_main_main_default, 0);
	lv_style_set_bg_color(&style_logo_page_logo_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_logo_page_logo_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_logo_page_logo_label_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_logo_page_logo_label_main_main_default, 255);
	lv_style_set_shadow_width(&style_logo_page_logo_label_main_main_default, 0);
	lv_style_set_shadow_color(&style_logo_page_logo_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_logo_page_logo_label_main_main_default, 255);
	lv_style_set_shadow_spread(&style_logo_page_logo_label_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_logo_page_logo_label_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_logo_page_logo_label_main_main_default, 0);
	lv_style_set_text_color(&style_logo_page_logo_label_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_logo_page_logo_label_main_main_default, &lv_font_montserratMedium_20);
	lv_style_set_text_letter_space(&style_logo_page_logo_label_main_main_default, 2);
	lv_style_set_text_line_space(&style_logo_page_logo_label_main_main_default, 0);
	lv_style_set_text_align(&style_logo_page_logo_label_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_logo_page_logo_label_main_main_default, 0);
	lv_style_set_pad_right(&style_logo_page_logo_label_main_main_default, 0);
	lv_style_set_pad_top(&style_logo_page_logo_label_main_main_default, 8);
	lv_style_set_pad_bottom(&style_logo_page_logo_label_main_main_default, 0);
	lv_obj_add_style(ui->logo_page_logo_label, &style_logo_page_logo_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Init events for screen
	events_init_logo_page(ui);
}