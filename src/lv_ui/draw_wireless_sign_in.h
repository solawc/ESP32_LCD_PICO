#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    lv_obj_t *obj_wreless_name;
    lv_obj_t *obj_wreless_password;
    lv_obj_t *btn_wreless_name;
    lv_obj_t *btn_wreless_password;

    // lv_obj_t *btn_customize2;
    // lv_obj_t *btn_customize3;

    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;
    lv_style_t new_btn_style;

    // lv_obj_t *label_wireless_name_pic;
    // lv_obj_t *label_wireless_password_pic;
    // lv_obj_t *label_machine_type_pic;
    // lv_obj_t *label_axis_pic;
    // lv_obj_t *label_rate_pic;
    // lv_obj_t *label_type_pic;
    // lv_obj_t *label_customize2_pic;
    // lv_obj_t *label_customize3_pic;


    lv_obj_t *label_wireless_name;
    lv_obj_t *label_wireless_password;


    lv_obj_t *label_wireless_name_text;
    lv_obj_t *label_wireless_password_text;

    // lv_obj_t *label_customize2;
    // lv_obj_t *label_customize3;

    lv_obj_t *btn_back;
    lv_obj_t *label_back_pic;
    lv_obj_t *label_back;
    // lv_obj_t *btn_wireless_sign_in;
    // lv_obj_t *label_wireless_sign_in_pic;
    // lv_obj_t *label_wireless_sign_in;

}ui_wireless_sign_in_t;



#define ABOUT_BTN_W 335
#define ABOUT_BTN_H 30
#define ABOUT_BTN_X 120
#define ABOUT_BTN_Y1 94
#define ABOUT_BTN_Y2 152


#define ABOUT_OBJ_X 8
#define ABOUT_OBJ_Y1 84
#define ABOUT_OBJ_Y2 142
#define ABOUT_OBJ_W 464
#define ABOUT_OBJ_H 50

#define WIRELESS_SIGN_IN_BTN_BACK_X 8
#define WIRELESS_SIGN_IN_BTN_BACK_Y 8

/***************************************************************************
 *                              extern
***************************************************************************/

void draw_wireless_sign_in(void);
void clean_wireless_sign_in_page(void);