#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/
typedef struct {

// for grbl page;
    lv_obj_t *label_wifi_ip;
    lv_obj_t *label_w_pos;
    lv_obj_t *label_m_pos;

    lv_obj_t *label_x_mpos;
    lv_obj_t *label_y_mpos;
    lv_obj_t *label_z_mpos;

    lv_obj_t *label_x_wpos;
    lv_obj_t *label_y_wpos;
    lv_obj_t *label_z_wpos;



    lv_obj_t *btn_control;
    lv_obj_t *btn_sculpture;
    lv_obj_t *btn_tool;

    lv_obj_t *label_control;
    lv_obj_t *label_sculpture;
    lv_obj_t *label_tool;

    lv_obj_t *label_control_pic;
    lv_obj_t *label_sculpture_pic;
    lv_obj_t *label_tool_pic;

    lv_obj_t *reg_w;
    lv_obj_t *reg_m;

    lv_obj_t *label_w;
    lv_obj_t *label_m;

    lv_obj_t *label_w_pic;
    lv_obj_t *label_m_pic;

    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;

    lv_style_t btn_reg_style;


}ui_home_t; 


/***************************************************************************
 *                              extern
***************************************************************************/

void draw_home(void);
void clean_home_page(void);
void disp_home_data_updata();
