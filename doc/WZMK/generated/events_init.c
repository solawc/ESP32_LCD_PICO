/*
 * Copyright 2023 NXP
 * SPDX-License-Identifier: MIT
 * The auto-generated can only be used on NXP devices
 */

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

void events_init(lv_ui *ui)
{
}

void video_play(lv_ui *ui)
{

}

static void logo_page_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_PRESSED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			lv_obj_clean(act_scr);
			if (guider_ui.main_page_del == true)
				setup_scr_main_page(&guider_ui);
			lv_scr_load_anim(guider_ui.main_page, LV_SCR_LOAD_ANIM_NONE, 100, 100, true);
			guider_ui.logo_page_del = true;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_logo_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->logo_page, logo_page_event_handler, LV_EVENT_ALL, ui);
}

static void main_page_imgbtn_1_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			lv_obj_clean(act_scr);
			if (guider_ui.engraving_page_del == true)
				setup_scr_engraving_page(&guider_ui);
			lv_scr_load_anim(guider_ui.engraving_page, LV_SCR_LOAD_ANIM_OVER_LEFT, 100, 100, true);
			guider_ui.main_page_del = true;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_main_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->main_page_imgbtn_1, main_page_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
}

static void engraving_page_btn_back_event_handler(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);
	switch (code)
	{
	case LV_EVENT_RELEASED:
	{
		lv_obj_t * act_scr = lv_scr_act();
		lv_disp_t * d = lv_obj_get_disp(act_scr);
		if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
		{
			lv_obj_clean(act_scr);
			if (guider_ui.main_page_del == true)
				setup_scr_main_page(&guider_ui);
			lv_scr_load_anim(guider_ui.main_page, LV_SCR_LOAD_ANIM_OVER_RIGHT, 100, 100, true);
			guider_ui.engraving_page_del = true;
		}
	}
		break;
	default:
		break;
	}
}

void events_init_engraving_page(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->engraving_page_btn_back, engraving_page_btn_back_event_handler, LV_EVENT_ALL, ui);
}
