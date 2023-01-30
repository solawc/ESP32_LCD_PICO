/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"

lv_ui guider_ui;

void init_scr_del_flag(lv_ui *ui){
	ui->home_del = true;
	ui->logo_del = true;
	ui->engraving_del = true;
	ui->file_management_del = true;
	ui->incarving_del = true;
	ui->control_del = true;
	ui->tool_del = true;
	ui->tool_info_del = true;
	ui->tool_wifi_del = true;
}

void setup_ui(lv_ui *ui){
	init_scr_del_flag(ui);
	setup_scr_home(ui);
	lv_scr_load(ui->home);
}
