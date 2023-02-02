#ifndef __draw_engraving_h
#define __draw_engraving_h

#include "../main.h"

typedef struct  
{
    lv_obj_t *btn_frame;
    lv_obj_t *btn_home;
    lv_obj_t *btn_position;
    lv_obj_t *btn_start;
    lv_obj_t *btn_back;

    lv_obj_t *label_frame;
    lv_obj_t *label_home;
    lv_obj_t *label_position;
    lv_obj_t *label_start;
    lv_obj_t *label_back;
    
    lv_style_t btn_style_1;




}src_engraving_t;

void draw_engraving(void);
#endif
