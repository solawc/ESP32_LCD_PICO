#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    lv_obj_t *obj_ver;
    lv_obj_t *obj_fw;
    lv_obj_t *obj_machine_type;
    lv_obj_t *obj_axes;
    lv_obj_t *obj_rate;
    lv_obj_t *obj_type;
    // lv_obj_t *btn_customize2;
    // lv_obj_t *btn_customize3;

    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;
    lv_style_t obj_style;

    // lv_obj_t *label_ver_pic;
    // lv_obj_t *label_fw_pic;
    // lv_obj_t *label_machine_type_pic;
    // lv_obj_t *label_axis_pic;
    // lv_obj_t *label_rate_pic;
    // lv_obj_t *label_type_pic;
    // lv_obj_t *label_customize2_pic;
    // lv_obj_t *label_customize3_pic;


    lv_obj_t *label_ver;
    lv_obj_t *label_fw;
    lv_obj_t *label_machine_type;
    lv_obj_t *label_axis;
    lv_obj_t *label_rate;
    lv_obj_t *label_type;

    lv_obj_t *label_ver_text;
    lv_obj_t *label_fw_text;
    lv_obj_t *label_machine_type_text;
    lv_obj_t *label_axis_text;
    lv_obj_t *label_rate_text;
    lv_obj_t *label_type_text;
    // lv_obj_t *label_customize2;
    // lv_obj_t *label_customize3;

    lv_obj_t *btn_back;
    lv_obj_t *label_back_pic;
    lv_obj_t *label_back;
    // lv_obj_t *btn_about;
    // lv_obj_t *label_about_pic;
    // lv_obj_t *label_about;

}ui_about_t;

#define ABOUT_OBJ_X 8
#define ABOUT_OBJ_W 464
#define ABOUT_OBJ_H 30


#define ABOUT_OBJ_Y1 84
#define ABOUT_OBJ_Y2 122
#define ABOUT_OBJ_Y3 160
#define ABOUT_OBJ_Y4 198
#define ABOUT_OBJ_Y5 236
#define ABOUT_OBJ_Y6 274



/***************************************************************************
 *                              extern
***************************************************************************/

void draw_about(void);
void clean_about_page(void);