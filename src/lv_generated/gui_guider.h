/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "./guider_fonts/guider_fonts.h"

typedef struct
{
	lv_obj_t *home;
	bool home_del;
	lv_obj_t *home_imgbtn_engraving;
	lv_obj_t *home_imgbtn_engraving_label;
	lv_obj_t *home_imgbtn_control;
	lv_obj_t *home_imgbtn_control_label;
	lv_obj_t *home_imgbtn_tools;
	lv_obj_t *home_imgbtn_tools_label;
	lv_obj_t *home_label_1;
	lv_obj_t *home_label_3;
	lv_obj_t *home_label_2;
	lv_obj_t *home_label_4;
	lv_obj_t *logo;
	bool logo_del;
	lv_obj_t *logo_image_logo;
	lv_obj_t *engraving;
	bool engraving_del;
	lv_obj_t *engraving_imgbtn_1;
	lv_obj_t *engraving_imgbtn_1_label;
	lv_obj_t *engraving_imgbtn_2;
	lv_obj_t *engraving_imgbtn_2_label;
	lv_obj_t *engraving_imgbtn_3;
	lv_obj_t *engraving_imgbtn_3_label;
	lv_obj_t *engraving_imgbtn_4;
	lv_obj_t *engraving_imgbtn_4_label;
	lv_obj_t *engraving_imgbtn_5;
	lv_obj_t *engraving_imgbtn_5_label;
	lv_obj_t *engraving_img_1;
	lv_obj_t *engraving_imgbtn_6;
	lv_obj_t *engraving_imgbtn_6_label;
	lv_obj_t *file_management;
	bool file_management_del;
	lv_obj_t *file_management_label_1;
	lv_obj_t *file_management_imgbtn_1;
	lv_obj_t *file_management_table;
	lv_obj_t *file_management_btn_next_page;
	lv_obj_t *file_management_btn_last_page;
	lv_obj_t *incarving;
	bool incarving_del;
	lv_obj_t *incarving_imgbtn_1;
	lv_obj_t *incarving_imgbtn_1_label;
	lv_obj_t *incarving_imgbtn_2;
	lv_obj_t *incarving_imgbtn_2_label;
	lv_obj_t *incarving_imgbtn_3;
	lv_obj_t *incarving_imgbtn_3_label;
	lv_obj_t *incarving_imgbtn_4;
	lv_obj_t *incarving_imgbtn_4_label;
	lv_obj_t *incarving_imgbtn_5;
	lv_obj_t *incarving_imgbtn_5_label;
	lv_obj_t *control;
	bool control_del;
	lv_obj_t *control_imgbtn_1;
	lv_obj_t *control_imgbtn_1_label;
	lv_obj_t *control_imgbtn_2;
	lv_obj_t *control_imgbtn_2_label;
	lv_obj_t *control_imgbtn_3;
	lv_obj_t *control_imgbtn_3_label;
	lv_obj_t *control_imgbtn_4;
	lv_obj_t *control_imgbtn_4_label;
	lv_obj_t *control_imgbtn_5;
	lv_obj_t *control_imgbtn_5_label;
	lv_obj_t *control_img_1;
	lv_obj_t *control_imgbtn_6;
	lv_obj_t *control_imgbtn_6_label;
	lv_obj_t *control_imgbtn_7;
	lv_obj_t *control_imgbtn_7_label;
	lv_obj_t *control_imgbtn_8;
	lv_obj_t *control_imgbtn_8_label;
	lv_obj_t *control_imgbtn_9;
	lv_obj_t *control_imgbtn_9_label;
	lv_obj_t *control_imgbtn_10;
	lv_obj_t *control_imgbtn_10_label;	
	lv_obj_t *tool;
	bool tool_del;
	lv_obj_t *tool_imgbtn_1;
	lv_obj_t *tool_imgbtn_1_label;
	lv_obj_t *tool_imgbtn_2;
	lv_obj_t *tool_imgbtn_2_label;
	lv_obj_t *tool_label_1;
	lv_obj_t *tool_imgbtn_3;
	lv_obj_t *tool_imgbtn_3_label;
	lv_obj_t *tool_info;
	bool tool_info_del;
	lv_obj_t *tool_info_label_1;
	lv_obj_t *tool_info_label_3;
	lv_obj_t *tool_info_label_7;
	lv_obj_t *tool_info_label_6;
	lv_obj_t *tool_info_label_5;
	lv_obj_t *tool_info_label_4;
	lv_obj_t *tool_info_label_2;
	lv_obj_t *tool_info_imgbtn_3;
	lv_obj_t *tool_info_imgbtn_3_label;
	lv_obj_t *tool_wifi;
	bool tool_wifi_del;
	lv_obj_t * tool_wifi_keyboard;
	lv_obj_t * tool_wifi_textare;
	lv_obj_t *tool_wifi_label_1;
	lv_obj_t *tool_wifi_imgbtn_3;
	lv_obj_t *tool_wifi_imgbtn_3_label;
	lv_obj_t *tool_wifi_msgbox;
}lv_ui;

void init_scr_del_flag(lv_ui *ui);
void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_home(lv_ui *ui);
void setup_scr_logo(lv_ui *ui);
void setup_scr_engraving(lv_ui *ui);
void setup_scr_file_management(lv_ui *ui);
void setup_scr_incarving(lv_ui *ui);
void setup_scr_control(lv_ui *ui);
void setup_scr_tool(lv_ui *ui);
void setup_scr_tool_info(lv_ui *ui);
void setup_scr_tool_wifi(lv_ui *ui);
LV_IMG_DECLARE(_position_label_alpha_222x38);
LV_IMG_DECLARE(_unlock_alpha_206x33);
LV_IMG_DECLARE(_MakeGo_Logo_460x320);
LV_IMG_DECLARE(_home_alpha_157x26);
LV_IMG_DECLARE(_posite_pane_alpha_184x184);
LV_IMG_DECLARE(_file_alpha_206x33);
LV_IMG_DECLARE(_position_alpha_206x33);
LV_IMG_DECLARE(_emptypane_alpha_150x150);
LV_IMG_DECLARE(_control_alpha_109x109);
LV_IMG_DECLARE(_Frame_alpha_151x23);
LV_IMG_DECLARE(_start_alpha_175x50);
LV_IMG_DECLARE(_position_alpha_154x24);
LV_IMG_DECLARE(_tool_wifi_alpha_114x114);
LV_IMG_DECLARE(_tool_alpha_109x109);
LV_IMG_DECLARE(_return_alpha_25x21);
LV_IMG_DECLARE(_Engraving_alpha_109x109);
LV_IMG_DECLARE(_wifi_icon_15x9);
LV_IMG_DECLARE(_stop_alpha_150x32);
LV_IMG_DECLARE(_tool_info_alpha_114x114);
LV_IMG_DECLARE(_larse_power_206x33);
LV_IMG_DECLARE(_home_alpha_206x33);
LV_IMG_DECLARE(_sub_alpha_25x25);
LV_IMG_DECLARE(_plus_alpha_25x25);
LV_IMG_DECLARE(_wifi_disconnect_76x58);
LV_IMG_DECLARE(_Slice_41_alpha_184x184);
LV_IMG_DECLARE(_y_up_alpha_15x30);
LV_IMG_DECLARE(_y_down_alpha_15x30);
LV_IMG_DECLARE(_x_left_alpha_28x15);
LV_IMG_DECLARE(_x_right_alpha_28x15);


#ifdef __cplusplus
}
#endif
#endif