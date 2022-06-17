#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    lv_obj_t *btn_cancel;
    lv_obj_t *btn_finish;
    lv_obj_t *btn_next;


    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;



    lv_obj_t *label_next;
    lv_obj_t *label_finish;
    lv_obj_t *label_cancel;
    lv_obj_t *label_text;


}ui_init_set_t;

#define INIT_SET_BTN_X1 8
#define INIT_SET_BTN_X2 322

#define INIT_SET_BTN_Y 252

#define INIT_SET_BTN_W 150
#define INIT_SET_BTN_H 60



/***************************************************************************
 *                              extern
***************************************************************************/

void draw_init_set_complete(void);
void draw_init_set_Initialize(void);
void clean_init_set_page(void);