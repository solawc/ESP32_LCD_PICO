#ifndef __draw_ready_h
#define __draw_ready_h

#include "../main.h"

typedef struct {

    lv_obj_t *Label_M_Xpos;
    lv_obj_t *Label_M_Ypos;
    lv_obj_t *Label_M_Zpos;

    lv_obj_t *Label_Pwr; 

    lv_obj_t *imgbtn_engraving;
    lv_obj_t *imgbtn_control;
    lv_obj_t *imgbtn_tool;

    lv_obj_t *label_engraving;
    lv_obj_t *label_control;
    lv_obj_t *label_tool;

    lv_style_t style_def;
    lv_style_t style_pr;

}src_ready_t;;

void draw_ready(void);

#endif
