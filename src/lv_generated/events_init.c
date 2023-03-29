/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "./custom/custom.h"
#include "./custom/popview.h"
#include "../wrapper/SdCardWrapper.h"
#include "../wrapper/WifiWrapper.h"

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
		// guider_load_screen(SCR_CONTROL);
		printf("TestCase4: button callback\n");
		uint8_t sd_state = get_sd_state(true);
		bool wifi_state = get_wifi_state();

		lv_obj_t* objmask = objmask_init();
		if ((sd_state == 0) &&(wifi_state == true) )
		{
			lv_obj_t* obj = msg_popview_init(objmask, "All initial Successful");
		}
		else
		{
			if (wifi_state == true)
			{
				lv_obj_t* obj = msg_popview_init(objmask, "Wifi is Ok,SD card Failed");
			}
			else
			{
				lv_obj_t* obj = msg_popview_init(objmask, "SD Card is Ok,Wifi Failed");
			}
		}
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
	// lv_obj_add_event_cb(ui->home_imgbtn_engraving, home_imgbtn_engraving_event_handler, LV_EVENT_ALL, NULL);
	lv_obj_add_event_cb(ui->home_imgbtn_control, home_imgbtn_control_event_handler, LV_EVENT_ALL, NULL);
	// lv_obj_add_event_cb(ui->home_imgbtn_tools, home_imgbtn_tools_event_handler, LV_EVENT_ALL, NULL);
}
