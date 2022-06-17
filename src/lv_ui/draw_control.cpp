/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_control.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_ctrl_t ui_ctrl;

/***************************************************************************
 *                          static function
 * - static void update_font_icon_color(uint8_t id, bool status)
 * - static void action_step(char axis, int len, uint32_t speed)
***************************************************************************/
static void update_font_icon_color(uint8_t id, bool status);


static void action_step(char axis, int len, uint32_t speed);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/

enum {
    ID_C_X_N,
    ID_C_X_P,
    ID_C_Y_N,
    ID_C_Y_P,
    ID_C_Z_N,
    ID_C_Z_P,

    ID_C_XY_CLEAR,
    ID_C_Z_CLEAR,
    ID_C_KNIFE,
    ID_C_NEXT,

    ID_C_LEN,
    ID_C_SPEED,
    ID_C_SPINDLE,

    ID_C_BACK,
};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {

    if(obj == ui_ctrl.btn_back) return ID_C_BACK;
    else if(obj == ui_ctrl.btn_x_n) return ID_C_X_N;
    else if(obj == ui_ctrl.btn_x_p) return ID_C_X_P;
    else if(obj == ui_ctrl.btn_y_n) return ID_C_Y_N;
    else if(obj == ui_ctrl.btn_y_p) return ID_C_Y_P;
    else if(obj == ui_ctrl.btn_z_n) return ID_C_Z_N;
    else if(obj == ui_ctrl.btn_z_p) return ID_C_Z_P;
    else if(obj == ui_ctrl.btn_len) return ID_C_LEN;
    else if(obj == ui_ctrl.btn_speed) return ID_C_SPEED;
    else if(obj == ui_ctrl.btn_spindle) return ID_C_SPINDLE;
}


char common_cmd[96];

static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        update_font_icon_color(id, true);
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        update_font_icon_color(id, false);

        switch(id) {
            
            case ID_C_X_N: 
                action_step('X', 10, 1000);
            break;

            case ID_C_X_P: 
                action_step('X', -10, 1000);
            break;

            case ID_C_Y_N:
                action_step('Y', 10, 1000);
            break;

            case ID_C_Y_P: 
                action_step('Y', -10, 1000);
            break;

            case ID_C_Z_N: 
                action_step('Z', 10, 1000);
            break;

            case ID_C_Z_P: 
                action_step('Z', -10, 1000);
            break;



            case ID_C_BACK: 
                clear_control_page();
                draw_home();
            break;
        }
    }
}



static void draw_bar() {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 76);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_2_style);
}

static void init_control_style() {

    lv_style_copy(&ui_ctrl.btn_move , &lv_style_scr);
    ui_ctrl.btn_move.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	ui_ctrl.btn_move.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    ui_ctrl.btn_move.body.border.color = lv_color_hex(get_current_color());
    ui_ctrl.btn_move.body.border.width = 1;
    ui_ctrl.btn_move.body.radius = 10;
    ui_ctrl.btn_move.text.color = lv_color_hex(get_current_color());

    lv_style_copy(&ui_ctrl.btn_move_pre , &lv_style_scr);
    ui_ctrl.btn_move_pre.body.grad_color = lv_color_hex(get_current_color());
	ui_ctrl.btn_move_pre.body.main_color = lv_color_hex(get_current_color());
    ui_ctrl.btn_move_pre.body.border.color = lv_color_hex(get_current_color());
    ui_ctrl.btn_move_pre.body.border.width = 1;
    ui_ctrl.btn_move_pre.body.radius = 10;
    ui_ctrl.btn_move_pre.text.color = lv_color_hex(F_THEME_FONR_REL_COLOR);

    lv_style_copy(&ui_ctrl.label_pos , &lv_style_scr);
    ui_ctrl.label_pos.text.color = LV_COLOR_WHITE;// lv_color_hex(get_current_color());

}

static void set_control_style(void) {

    lv_btn_set_style(ui_ctrl.btn_x_n, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_x_n, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_x_p, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_x_p, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_y_n, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_y_n, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_y_p, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_y_p, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_z_n, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_z_n, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_z_p, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_z_p, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);

    lv_btn_set_style(ui_ctrl.btn_xy_home, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_xy_home, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_z_home, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_z_home, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);

    lv_btn_set_style(ui_ctrl.btn_len, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_len, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_speed, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_speed, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_spindle, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_spindle, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);

    lv_btn_set_style(ui_ctrl.btn_knife, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_knife, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_next, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_next, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_xy_clear, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_xy_clear, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_z_clear, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_z_clear, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);

    lv_btn_set_style(ui_ctrl.btn_back, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_back, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
}

static void set_font_style(void) {

    lv_label_set_style(ui_ctrl.label_x_n_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_x_p_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_y_n_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_y_p_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_z_n_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_z_p_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_bakc_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_xyclear_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_zclear_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_knife_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);

    lv_label_set_style(ui_ctrl.label_x_pos, LV_LABEL_STYLE_MAIN, &ui_ctrl.label_pos);
    lv_label_set_style(ui_ctrl.label_y_pos, LV_LABEL_STYLE_MAIN, &ui_ctrl.label_pos);
    lv_label_set_style(ui_ctrl.label_z_pos, LV_LABEL_STYLE_MAIN, &ui_ctrl.label_pos);
}

static void update_font_icon_color(uint8_t id, bool status) {

    switch(id) {

        case ID_C_X_N: 
            if(status) lv_label_set_style(ui_ctrl.label_x_n_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_x_n_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;

        case ID_C_X_P: 
            if(status) lv_label_set_style(ui_ctrl.label_x_p_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_x_p_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;

        case ID_C_Y_N: 
            if(status) lv_label_set_style(ui_ctrl.label_y_n_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_y_n_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;

        case ID_C_Y_P: 
            if(status) lv_label_set_style(ui_ctrl.label_y_p_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_y_p_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;

        case ID_C_Z_N: 
            if(status) lv_label_set_style(ui_ctrl.label_z_n_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_z_n_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;

        case ID_C_Z_P: 
            if(status) lv_label_set_style(ui_ctrl.label_z_p_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_z_p_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;

        case ID_C_BACK:
            if(status) lv_label_set_style(ui_ctrl.label_bakc_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_bakc_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
    }
}

static void set_btn(void) {

    init_control_style();

    ui_ctrl.btn_x_n =  lv_btn_set(ui.src, ui_ctrl.btn_x_n, 66, 68, 8, 164, event_handler);
    ui_ctrl.btn_x_p =  lv_btn_set(ui.src, ui_ctrl.btn_x_p, 66, 68, 164, 164, event_handler);
    ui_ctrl.btn_y_n =  lv_btn_set(ui.src, ui_ctrl.btn_y_n, 66, 68, 86, 84, event_handler);
    ui_ctrl.btn_y_p =  lv_btn_set(ui.src, ui_ctrl.btn_y_p, 66, 68, 86, 244, event_handler);
    ui_ctrl.btn_z_n =  lv_btn_set(ui.src, ui_ctrl.btn_z_n, 66, 68, 242, 84, event_handler);
    ui_ctrl.btn_z_p =  lv_btn_set(ui.src, ui_ctrl.btn_z_p, 66, 68, 242, 244, event_handler);

    ui_ctrl.btn_xy_home =  lv_btn_set(ui.src, ui_ctrl.btn_xy_home, 66, 68, 86, 164, event_handler);
    ui_ctrl.btn_z_home =  lv_btn_set(ui.src, ui_ctrl.btn_z_home, 66, 68, 242, 164, event_handler);

    ui_ctrl.btn_len =  lv_btn_set(ui.src, ui_ctrl.btn_len, 152, 68, 320, 84, event_handler);
    ui_ctrl.btn_speed =  lv_btn_set(ui.src, ui_ctrl.btn_speed, 152, 68, 320, 164, event_handler);
    ui_ctrl.btn_spindle =  lv_btn_set(ui.src, ui_ctrl.btn_spindle, 152, 68, 320, 244, event_handler);

    ui_ctrl.btn_knife =  lv_btn_set(ui.src, ui_ctrl.btn_knife, 60, 60, 344, 8, event_handler);
    ui_ctrl.btn_next =  lv_btn_set(ui.src, ui_ctrl.btn_next, 60, 60, 412, 8, event_handler);
    ui_ctrl.btn_xy_clear =  lv_btn_set(ui.src, ui_ctrl.btn_xy_clear, 60, 60, 208, 8, event_handler);
    ui_ctrl.btn_z_clear =  lv_btn_set(ui.src, ui_ctrl.btn_z_clear, 60, 60, 276, 8, event_handler);

    ui_ctrl.btn_back =  lv_btn_set(ui.src, ui_ctrl.btn_back, 60, 60, 8, 8, event_handler);

    ui_ctrl.label_x_n_pic = lv_label_set(ui.src, ui_ctrl.label_x_n_pic, 0, 0, FONT_PIC_MECHANICAL_COORDINATES_1);

    ui_ctrl.label_x_n_pic = lv_label_create(ui_ctrl.btn_x_n, NULL);
    lv_label_set_text(ui_ctrl.label_x_n_pic, FONT_PIC_X_P);

    ui_ctrl.label_x_p_pic = lv_label_create(ui_ctrl.btn_x_p, NULL);
    lv_label_set_text(ui_ctrl.label_x_p_pic, FONT_PIC_X_N);

    ui_ctrl.label_y_n_pic = lv_label_create(ui_ctrl.btn_y_n, NULL);
    lv_label_set_text(ui_ctrl.label_y_n_pic, FONT_PIC_Y_N);

    ui_ctrl.label_y_p_pic = lv_label_create(ui_ctrl.btn_y_p, NULL);
    lv_label_set_text(ui_ctrl.label_y_p_pic, FONT_PIC_Y_P);

    ui_ctrl.label_z_n_pic = lv_label_create(ui_ctrl.btn_z_n, NULL);
    lv_label_set_text(ui_ctrl.label_z_n_pic, FONT_PIC_Z_N);

    ui_ctrl.label_z_p_pic = lv_label_create(ui_ctrl.btn_z_p, NULL);
    lv_label_set_text(ui_ctrl.label_z_p_pic, FONT_PIC_Z_P);

    ui_ctrl.label_bakc_pic = lv_label_create(ui_ctrl.btn_back, NULL);
    lv_label_set_text(ui_ctrl.label_bakc_pic, FONT_PIC_BACK);

    ui_ctrl.label_back = lv_label_create(ui_ctrl.btn_back, NULL);
    lv_label_set_text(ui_ctrl.label_back, "Back");

    ui_ctrl.label_xyclear_pic = lv_label_create(ui_ctrl.btn_xy_clear, NULL);
    lv_label_set_text(ui_ctrl.label_xyclear_pic, FONT_PIC_XY_CLEAR);

    ui_ctrl.label_xyclear = lv_label_create(ui_ctrl.btn_xy_clear, NULL);
    lv_label_set_text(ui_ctrl.label_xyclear, "XY Pos");

    ui_ctrl.label_zclear_pic = lv_label_create(ui_ctrl.btn_z_clear, NULL);
    lv_label_set_text(ui_ctrl.label_zclear_pic, FONT_PIC_Z_CLEAR);

    ui_ctrl.label_zclear = lv_label_create(ui_ctrl.btn_z_clear, NULL);
    lv_label_set_text(ui_ctrl.label_zclear, "Z Pos");

    ui_ctrl.label_knife_pic = lv_label_create(ui_ctrl.btn_knife, NULL);
    lv_label_set_text(ui_ctrl.label_knife_pic, FONT_PIC_KNIFE);

    ui_ctrl.label_knife = lv_label_create(ui_ctrl.btn_knife, NULL);
    lv_label_set_text(ui_ctrl.label_knife, "Knife");


    ui_ctrl.label_len = lv_label_create(ui_ctrl.btn_len, NULL);
    lv_label_set_text(ui_ctrl.label_len, "10mm");

    ui_ctrl.label_speed = lv_label_create(ui_ctrl.btn_speed, NULL);
    lv_label_set_text(ui_ctrl.label_speed, "Higj Speed");

    ui_ctrl.label_spindle = lv_label_create(ui_ctrl.btn_spindle, NULL);
    lv_label_set_text(ui_ctrl.label_spindle, "Spindle");


    ui_ctrl.label_x_pos = lv_label_create(ui.src, NULL);
    ui_ctrl.label_y_pos = lv_label_create(ui.src, NULL);
    ui_ctrl.label_z_pos = lv_label_create(ui.src, NULL);

    lv_obj_set_pos(ui_ctrl.label_x_pos, 88, 8);
    lv_obj_set_pos(ui_ctrl.label_y_pos, 88, 30);
    lv_obj_set_pos(ui_ctrl.label_z_pos, 88, 51);

    lv_label_set_text(ui_ctrl.label_x_pos, "X:0.00");
    lv_label_set_text(ui_ctrl.label_y_pos, "Y:0.00");
    lv_label_set_text(ui_ctrl.label_z_pos, "Z:0.00");

    
    set_font_style();
    set_control_style();
}


static void set_step_len(uint8_t len) {

}

static void set_step_speed() {


}

static void set_spindle_rate() {

}

static void action_step(char axis, int len, uint32_t speed) {
    char cmd[96];
    sprintf(cmd, "$J=G91%c%dF%d\n", axis, len, speed);
    grbl_cmd_send(CLIENT_SERIAL_LCD, cmd);
}



void draw_control(void) {

    draw_bar();

    set_btn();
}


void clear_control_page() {

    lv_obj_clean(ui.src);
}



