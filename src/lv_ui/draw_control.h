#pragma once 


#include "../main.h"

typedef struct {

    lv_obj_t *btn_x_n;
    lv_obj_t *btn_x_p;
    lv_obj_t *btn_y_n;
    lv_obj_t *btn_y_p;
    lv_obj_t *btn_z_n;
    lv_obj_t *btn_z_p;

    lv_obj_t *btn_xy_clear;
    lv_obj_t *btn_z_clear;

    lv_obj_t *btn_xy_home;
    lv_obj_t *btn_z_home;

    lv_obj_t *btn_knife;
    lv_obj_t *btn_next;
    lv_obj_t *btn_back;

    lv_obj_t *btn_len;
    lv_obj_t *btn_speed;
    lv_obj_t *btn_spindle;
    
    lv_obj_t *label_x_n_pic;
    lv_obj_t *label_x_p_pic;
    lv_obj_t *label_y_n_pic;
    lv_obj_t *label_y_p_pic;
    lv_obj_t *label_z_n_pic;
    lv_obj_t *label_z_p_pic;

    lv_obj_t *label_bakc_pic;
    lv_obj_t *label_back;
    lv_obj_t *label_xyclear_pic;
    lv_obj_t *label_xyclear;
    lv_obj_t *label_zclear_pic;
    lv_obj_t *label_zclear;
    lv_obj_t *label_knife_pic;
    lv_obj_t *label_knife;
    lv_obj_t *label_next_pic;
    lv_obj_t *label_next;

    lv_obj_t *label_xy_home_pic;
    lv_obj_t *label_xy_home;

    lv_obj_t *label_z_home_pic;
    lv_obj_t *label_z_home;

    /*up*/  
    lv_obj_t *btn_cool;
    lv_obj_t *label_cool_pic;
    lv_obj_t *label_cool;
    lv_obj_t *btn_position;
    lv_obj_t *label_position_pic;
    lv_obj_t *label_position;
    lv_obj_t *btn_up;
    lv_obj_t *label_up_pic;
    lv_obj_t *label_up;

    lv_obj_t *label_x_pos;
    lv_obj_t *label_y_pos;
    lv_obj_t *label_z_pos;

    lv_obj_t *label_len;
    lv_obj_t *label_speed;
    lv_obj_t *label_spindle;

    lv_style_t btn_move;            // 移动按钮的样式
    lv_style_t btn_move_pre;        // 移动按钮的样式
    lv_style_t btn_feture;          // 顶部栏的按键样式 
    lv_style_t btn_feture_pre;      // 顶部栏的按键样式 
    lv_style_t label_pos;           // 用于顶部栏坐标点的样式

}ui_ctrl_t;



void disp_step_len(uint8_t len);
void disp_step_speed(uint8_t speed);
void draw_control(void);
void clear_control_page();
void disp_control_data_updata();
void draw_next();
void draw_up();

