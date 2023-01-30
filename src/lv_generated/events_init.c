/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"

void events_init(lv_ui *ui)
{
}

static void home_imgbtn_engraving_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		guider_load_screen(SCR_ENGRAING_POSITION);
	}
		break;
	default:
		break;
	}
}

static void home_imgbtn_control_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		guider_load_screen(SCR_CONTROL);
	}
		break;
	default:
		break;
	}
}

static void home_imgbtn_tools_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		guider_load_screen(SCR_TOOL);
	}
		break;
	default:
		break;
	}
}

void events_init_home(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->home_imgbtn_engraving, home_imgbtn_engraving_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_imgbtn_control, home_imgbtn_control_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_imgbtn_tools, home_imgbtn_tools_event_handler, LV_EVENT_ALL, NULL);
}
