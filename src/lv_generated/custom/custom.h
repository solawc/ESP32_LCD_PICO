// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/*
 * custom.h
 *
 *  Created on: July 29, 2020
 *      Author: nxf53801
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "../gui_guider.h"

#define LV_HOR_RES_MAX          (480)
#define LV_VER_RES_MAX          (320)

/* declare the enum for every screen */
enum SCR_ID {
    SCR_LOGO                = 0,
	SCR_HOME                = 1,
	SCR_ENGRAING_POSITION   = 2,
	SCR_TOOL                = 3,
    SCR_CONTROL             = 4,
	SCR_TOOL_INFO           = 5,
    SCR_TOOL_WIFI           = 6,
    SCR_ENGRAING_FILE       = 7,
    SCR_INCARVING            = 8,
};

extern int cur_scr;

void custom_init(lv_ui *ui);
void guider_load_screen(int scr_id);

#ifdef __cplusplus
}
#endif
#endif /* EVENT_CB_H_ */
