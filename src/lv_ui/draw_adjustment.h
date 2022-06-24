#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    lv_obj_t *btn_feed;
    lv_obj_t *btn_spindle;
    lv_obj_t *btn_rapid;
    lv_obj_t *btn_add;
    lv_obj_t *btn_reduce;
    lv_obj_t *btn_step;
    lv_obj_t *btn_back;
    lv_obj_t *btn_confirm;

    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;


    lv_obj_t *label_feed;
    lv_obj_t *label_spindle;
    lv_obj_t *label_rapid;
    lv_obj_t *label_add;
    lv_obj_t *label_reduce;
    lv_obj_t *label_step;
    lv_obj_t *label_back;
    lv_obj_t *label_confirm;

    lv_obj_t *label_add_pic;
    lv_obj_t *label_reduce_pic;
    lv_obj_t *label_back_pic;
    lv_obj_t *label_confirm_pic;



}ui_adjustment_t;

#define ADJUSTMENT_BTN1_X (70-60)

#define ADJUSTMENT_BTN1_Y1 (60-50)
#define ADJUSTMENT_BTN1_Y2 (105-50)
#define ADJUSTMENT_BTN1_Y3 (150-50)

#define ADJUSTMENT_BTN1_W 270
#define ADJUSTMENT_BTN1_H 40


#define ADJUSTMENT_BTN2_X1 (240-60)
#define adjustment_BTN2_X2 (70-60)

#define adjustment_BTN2_Y (200-50)

#define adjustment_BTN2_W 100
#define adjustment_BTN2_H 60


#define ADJUSTMENT_BTN3_X (350-60)

#define ADJUSTMENT_BTN3_Y1 (60-50)
#define ADJUSTMENT_BTN3_Y2 (130-50)
#define ADJUSTMENT_BTN3_Y3 (200-50)

#define ADJUSTMENT_BTN3_W 60
#define ADJUSTMENT_BTN3_H 60

/***************************************************************************
 *                              extern
***************************************************************************/

void draw_adjustment(void);
void clean_adjustment_page(void);