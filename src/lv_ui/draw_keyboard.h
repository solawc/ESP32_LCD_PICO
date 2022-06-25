#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    lv_obj_t *ta;
    lv_obj_t *kb;

    lv_style_t ta_bg_style;
    lv_style_t ta_cursor_style;

    lv_style_t kb_bg_style;
    lv_style_t kb_rel_style;
    lv_style_t kb_pr_style;

}ui_keyboard_t;

#define KEYBOARD_TA_X 6
#define KEYBOARD_TA_Y 10
#define KEYBOARD_TA_W 468
#define KEYBOARD_TA_H 40

#define KEYBOARD_KB_X 6
#define KEYBOARD_KB_Y 60
#define KEYBOARD_KB_W 468
#define KEYBOARD_KB_H 254

/***************************************************************************
 *                              extern
***************************************************************************/

void draw_keyboard(void);
void clean_keyboard_page(void);