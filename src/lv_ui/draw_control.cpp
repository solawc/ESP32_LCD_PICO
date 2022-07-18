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

enum{
    MOVE_LEN_1MM,
    MOVE_LEN_5MM,
    MOVE_LEN_10MM,
};
uint16_t current_len = MOVE_LEN_5MM;

enum{
    MOVE_HIGH_SPEED,
    MOVE_MID_SPEED,
    MOVE_LOW_SPEED,
};
uint16_t current_speed = MOVE_MID_SPEED;

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
    ID_C_COOL,
    ID_C_POSITION,
    ID_C_UP,

    ID_C_XY_HOME,
    ID_C_Z_HOME,
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
    else if(obj == ui_ctrl.btn_x_n) return ID_C_X_P;
    else if(obj == ui_ctrl.btn_x_p) return ID_C_X_N;
    else if(obj == ui_ctrl.btn_y_n) return ID_C_Y_N;
    else if(obj == ui_ctrl.btn_y_p) return ID_C_Y_P;
    else if(obj == ui_ctrl.btn_z_n) return ID_C_Z_N;
    else if(obj == ui_ctrl.btn_z_p) return ID_C_Z_P;
    else if(obj == ui_ctrl.btn_xy_home) return ID_C_XY_HOME;
    else if(obj == ui_ctrl.btn_z_home) return ID_C_Z_HOME;
    else if(obj == ui_ctrl.btn_xy_clear) return ID_C_XY_CLEAR;
    else if(obj == ui_ctrl.btn_z_clear) return ID_C_Z_CLEAR;
    else if(obj == ui_ctrl.btn_knife) return ID_C_KNIFE;
    else if(obj == ui_ctrl.btn_next) return ID_C_NEXT;
    else if(obj == ui_ctrl.btn_len) return ID_C_LEN;
    else if(obj == ui_ctrl.btn_speed) return ID_C_SPEED;
    else if(obj == ui_ctrl.btn_spindle) return ID_C_SPINDLE;
    else if(obj == ui_ctrl.btn_next) return ID_C_NEXT;
    else if(obj == ui_ctrl.btn_cool) return ID_C_COOL;
    else if(obj == ui_ctrl.btn_position) return ID_C_POSITION;
    else if(obj == ui_ctrl.btn_up) return ID_C_UP;
}


char common_cmd[96];

static void event_handler_next(lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_PRESSED) {
        lv_label_set_style(ui_ctrl.label_next_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
    }
    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {
        lv_label_set_style(ui_ctrl.label_next_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        draw_next();
    }
}
static void event_handler_up(lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_PRESSED) {
        lv_label_set_style(ui_ctrl.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
    }
    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {
        lv_label_set_style(ui_ctrl.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        draw_up();
    }
}
static void event_handler_cool(lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_PRESSED) {
        lv_label_set_style(ui_ctrl.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
    }
    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {
        lv_label_set_style(ui_ctrl.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        // draw_up();
        if(grbl_cmd.grbl_basic_info.apin_state & (1 << 2))
        {
            MKS_PICO_CMD_SEND("M9\n");
        }
        else
        {
            MKS_PICO_CMD_SEND("M8\n");
        }
    }
}
static void event_handler_pos(lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_PRESSED) {
        lv_label_set_style(ui_ctrl.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
    }
    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {
        lv_label_set_style(ui_ctrl.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        // draw_up();
        MKS_PICO_CMD_SEND("G92X0Y0Z0\n");
    }
}
static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {

        update_font_icon_color(id, true);
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        update_font_icon_color(id, false);

        switch(id) {
            
            case ID_C_X_N: 
                move_ctrl('X', 1);
            break;

            case ID_C_X_P: 
                move_ctrl('X', 0);
            break;

            case ID_C_Y_N:
                move_ctrl('Y', 1);
            break;

            case ID_C_Y_P: 
                move_ctrl('Y', 0);
            break;

            case ID_C_Z_N: 
                move_ctrl('Z', 1);
            break;

            case ID_C_Z_P: 
                move_ctrl('Z', 0);
            break;
            
            case ID_C_LEN:
                if(current_len == MOVE_LEN_1MM)
                {
                    current_len = MOVE_LEN_5MM;
                }
                else if (current_len == MOVE_LEN_5MM)
                {
                    current_len = MOVE_LEN_10MM;
                }
                else
                {
                    current_len = MOVE_LEN_1MM;
                }
                disp_step_len(current_len);
                break;
            case ID_C_SPEED:
                if(current_speed == MOVE_HIGH_SPEED)
                {
                    current_speed = MOVE_LOW_SPEED;
                }
                else if(current_speed == MOVE_MID_SPEED)
                {
                    current_speed = MOVE_HIGH_SPEED;
                }
                else
                {
                    current_speed = MOVE_MID_SPEED;
                }
                disp_step_speed(current_speed);
                break;
            case ID_C_XY_HOME:
                MKS_PICO_CMD_SEND("M5\n");
                MKS_PICO_CMD_SEND("$J=G90X0Y0F2000\n");
            break;
            case ID_C_Z_HOME:
                MKS_PICO_CMD_SEND("M5\n");
                MKS_PICO_CMD_SEND("$J=G90Z0F1000\n");
            break;
            case ID_C_XY_CLEAR:
                MKS_PICO_CMD_SEND("G92X0Y0\n");
            break;
            case ID_C_Z_CLEAR:
                MKS_PICO_CMD_SEND("G92Z0\n");
            break;
            case ID_C_SPINDLE:
                if(grbl_cmd.grbl_basic_info.apin_state & (1 << 0))
                {
                    MKS_PICO_CMD_SEND("M5\n");
                    grbl_cmd.grbl_basic_info.apin_state = 0;
                    lv_btn_set_style(ui_ctrl.btn_spindle, LV_BTN_STYLE_PR, &ui_ctrl.btn_move);
                    lv_btn_set_style(ui_ctrl.btn_spindle, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
                }
                else
                {
                    MKS_PICO_CMD_SEND("M3 S500\n");
                    MKS_PICO_CMD_SEND("G1 F1000\n");
                    lv_btn_set_style(ui_ctrl.btn_spindle, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
                    lv_btn_set_style(ui_ctrl.btn_spindle, LV_BTN_STYLE_REL, &ui_ctrl.btn_move_pre);
                }
            break;
            case ID_C_KNIFE:

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
    // ui_ctrl.btn_move.body.border.color = lv_color_hex(get_current_color());
    // ui_ctrl.btn_move.body.border.width = 1;
    ui_ctrl.btn_move.body.radius = 10;
    ui_ctrl.btn_move.text.color = lv_color_hex(get_current_color());

    lv_style_copy(&ui_ctrl.btn_move_pre , &lv_style_scr);
    ui_ctrl.btn_move_pre.body.grad_color = lv_color_hex(get_current_color());
	ui_ctrl.btn_move_pre.body.main_color = lv_color_hex(get_current_color());
    // ui_ctrl.btn_move_pre.body.border.color = lv_color_hex(get_current_color());
    // ui_ctrl.btn_move_pre.body.border.width = 1;
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

    if(grbl_cmd.grbl_basic_info.apin_state & (1 << 0))
    {
        lv_btn_set_style(ui_ctrl.btn_spindle, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
        lv_btn_set_style(ui_ctrl.btn_spindle, LV_BTN_STYLE_REL, &ui_ctrl.btn_move_pre);
    }
    else
    {
        lv_btn_set_style(ui_ctrl.btn_spindle, LV_BTN_STYLE_PR, &ui_ctrl.btn_move);
        lv_btn_set_style(ui_ctrl.btn_spindle, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    }



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

    lv_label_set_style(ui_ctrl.label_next_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_xy_home_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_z_home_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);

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

        case ID_C_XY_HOME: 
            if(status) lv_label_set_style(ui_ctrl.label_xy_home_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_xy_home_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;

        case ID_C_Z_HOME: 
            if(status) lv_label_set_style(ui_ctrl.label_z_home_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_z_home_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;

        case ID_C_XY_CLEAR: 
            if(status) lv_label_set_style(ui_ctrl.label_xyclear_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_xyclear_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;

        case ID_C_Z_CLEAR: 
            if(status) lv_label_set_style(ui_ctrl.label_zclear_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_zclear_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_C_KNIFE: 
            if(status) lv_label_set_style(ui_ctrl.label_knife_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_knife_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        // case ID_C_NEXT: 
        //     if(status) lv_label_set_style(ui_ctrl.label_next_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
        //     else lv_label_set_style(ui_ctrl.label_next_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        // break;

        case ID_C_COOL: 
            if(status) lv_label_set_style(ui_ctrl.label_cool_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_cool_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_C_POSITION: 
            if(status) lv_label_set_style(ui_ctrl.label_position_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(ui_ctrl.label_position_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        // case ID_C_UP: 
        //     if(status) lv_label_set_style(ui_ctrl.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
        //     else lv_label_set_style(ui_ctrl.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        // break;
    }
}

#define CONTROL_XY_CLEAR_EN            "XY Clear"
#define CONTROL_Z_CLEAR_EN             "Z Clear"
#define CONTROL_KNIFE_EN               "Knife"
#define CONTROL_NEXT_EN                "Next"
#define CONTROL_SPINDLE_EN             "Spindle"
#define CONTROL_BACK_EN                "Back"

#define CONTROL_COOLING_EN                "Cooling"
#define CONTROL_POSITION_EN                "Position"
#define CONTROL_UP_EN                "Up"

#define CONTROL_HIGH_SPEED_EN              "High Speed"
#define CONTROL_MID_SPEED_EN               "Mid Speed"
#define CONTROL_LOW_SPEED_EN               "Low Speed"


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
    ui_ctrl.btn_next =  lv_btn_set(ui.src, ui_ctrl.btn_next, 60, 60, 412, 8, event_handler_next);
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
    lv_label_set_text(ui_ctrl.label_back, CONTROL_BACK_EN);

    ui_ctrl.label_xyclear_pic = lv_label_create(ui_ctrl.btn_xy_clear, NULL);
    lv_label_set_text(ui_ctrl.label_xyclear_pic, FONT_PIC_XY_CLEAR);

    ui_ctrl.label_xyclear = lv_label_create(ui_ctrl.btn_xy_clear, NULL);
    lv_label_set_text(ui_ctrl.label_xyclear, CONTROL_XY_CLEAR_EN);

    ui_ctrl.label_zclear_pic = lv_label_create(ui_ctrl.btn_z_clear, NULL);
    lv_label_set_text(ui_ctrl.label_zclear_pic, FONT_PIC_Z_CLEAR);

    ui_ctrl.label_zclear = lv_label_create(ui_ctrl.btn_z_clear, NULL);
    lv_label_set_text(ui_ctrl.label_zclear, CONTROL_Z_CLEAR_EN);

    ui_ctrl.label_knife_pic = lv_label_create(ui_ctrl.btn_knife, NULL);
    lv_label_set_text(ui_ctrl.label_knife_pic, FONT_PIC_KNIFE);
    
    ui_ctrl.label_next_pic = lv_label_create(ui_ctrl.btn_next, NULL);
    lv_label_set_text(ui_ctrl.label_next_pic, FONT_PIC_NEXT);

    ui_ctrl.label_xy_home_pic = lv_label_create(ui_ctrl.btn_xy_home, NULL);
    lv_label_set_text(ui_ctrl.label_xy_home_pic, FONT_PIC_HOME);

    ui_ctrl.label_z_home_pic = lv_label_create(ui_ctrl.btn_z_home, NULL);
    lv_label_set_text(ui_ctrl.label_z_home_pic, FONT_PIC_HOME);

    ui_ctrl.label_xy_home = lv_label_create(ui_ctrl.btn_xy_home, NULL);
    lv_label_set_text(ui_ctrl.label_xy_home, "X/Y");

    ui_ctrl.label_z_home = lv_label_create(ui_ctrl.btn_z_home, NULL);
    lv_label_set_text(ui_ctrl.label_z_home, "Z0");

    ui_ctrl.label_knife = lv_label_create(ui_ctrl.btn_knife, NULL);
    lv_label_set_text(ui_ctrl.label_knife, CONTROL_KNIFE_EN);

    ui_ctrl.label_next = lv_label_create(ui_ctrl.btn_next, NULL);
    lv_label_set_text(ui_ctrl.label_next, CONTROL_NEXT_EN);

    ui_ctrl.label_len = lv_label_create(ui_ctrl.btn_len, NULL);
    disp_step_len(current_len);
    // lv_label_set_text(ui_ctrl.label_len, "10mm");

    ui_ctrl.label_speed = lv_label_create(ui_ctrl.btn_speed, NULL);
    disp_step_speed(current_speed);

    ui_ctrl.label_spindle = lv_label_create(ui_ctrl.btn_spindle, NULL);
    lv_label_set_text(ui_ctrl.label_spindle, CONTROL_SPINDLE_EN);


    ui_ctrl.label_x_pos = lv_label_create(ui.src, NULL);
    ui_ctrl.label_y_pos = lv_label_create(ui.src, NULL);
    ui_ctrl.label_z_pos = lv_label_create(ui.src, NULL);

    lv_obj_set_pos(ui_ctrl.label_x_pos, 88, 8);
    lv_obj_set_pos(ui_ctrl.label_y_pos, 88, 30);
    lv_obj_set_pos(ui_ctrl.label_z_pos, 88, 51);
    // char buff[20];
    // memset(buff,0,sizeof(buff));
    // sprintf(buff,"X:%0.2f",grbl_cmd.grbl_basic_info.x_m_pos);
    // lv_label_set_text(ui_ctrl.label_x_pos, buff);
    // memset(buff,0,sizeof(buff));
    // sprintf(buff,"Y:%0.2f",grbl_cmd.grbl_basic_info.y_m_pos);
    // lv_label_set_text(ui_ctrl.label_y_pos, buff);
    // memset(buff,0,sizeof(buff));
    // sprintf(buff,"Z:%0.2f",grbl_cmd.grbl_basic_info.z_m_pos);
    // lv_label_set_text(ui_ctrl.label_z_pos, buff);

    disp_control_data_updata();
    
    set_font_style();
    set_control_style();
}


void disp_step_len(uint8_t len) {

    if(len == MOVE_LEN_1MM)
    {
        lv_label_set_text(ui_ctrl.label_len, "1mm");
    }
    else if (len == MOVE_LEN_5MM)
    {
        lv_label_set_text(ui_ctrl.label_len, "5mm");
    }
    else
    {
        lv_label_set_text(ui_ctrl.label_len, "10mm");
    }
    
}


void disp_step_speed(uint8_t speed) {
    if(speed == MOVE_HIGH_SPEED)
    {
        lv_label_set_text(ui_ctrl.label_speed, CONTROL_HIGH_SPEED_EN);
    }
    else if(speed == MOVE_MID_SPEED)
    {
        lv_label_set_text(ui_ctrl.label_speed, CONTROL_MID_SPEED_EN);
    }
    else
    {
        lv_label_set_text(ui_ctrl.label_speed, CONTROL_LOW_SPEED_EN);
    }
}

static void set_spindle_rate() {

}

void draw_next()
{
    lv_obj_del(ui_ctrl.btn_xy_clear);
    lv_obj_del(ui_ctrl.btn_z_clear);
    lv_obj_del(ui_ctrl.btn_knife);
    lv_obj_del(ui_ctrl.btn_next);



    ui_ctrl.btn_cool =  lv_btn_set(ui.src, ui_ctrl.btn_cool, 60, 60, 276, 8, event_handler_cool);
    ui_ctrl.btn_position =  lv_btn_set(ui.src, ui_ctrl.btn_position, 60, 60, 344, 8, event_handler_pos);
    ui_ctrl.btn_up =  lv_btn_set(ui.src, ui_ctrl.btn_up, 60, 60, 412, 8, event_handler_up);

    lv_btn_set_style(ui_ctrl.btn_cool, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_cool, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_position, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_position, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_up, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_up, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    ui_ctrl.label_cool_pic = lv_label_create(ui_ctrl.btn_cool, NULL);
    lv_label_set_text(ui_ctrl.label_cool_pic, FONT_PIC_COOLING);

    ui_ctrl.label_position_pic = lv_label_create(ui_ctrl.btn_position, NULL);
    lv_label_set_text(ui_ctrl.label_position_pic, FONT_PIC_POSITION);

    ui_ctrl.label_up_pic = lv_label_create(ui_ctrl.btn_up, NULL);
    lv_label_set_text(ui_ctrl.label_up_pic, FONT_PIC_UP);


    ui_ctrl.label_cool= lv_label_create(ui_ctrl.btn_cool, NULL);
    lv_label_set_text(ui_ctrl.label_cool, CONTROL_COOLING_EN);

    ui_ctrl.label_position= lv_label_create(ui_ctrl.btn_position, NULL);
    lv_label_set_text(ui_ctrl.label_position, CONTROL_POSITION_EN);

    ui_ctrl.label_up= lv_label_create(ui_ctrl.btn_up, NULL);
    lv_label_set_text(ui_ctrl.label_up, CONTROL_UP_EN);

    lv_label_set_style(ui_ctrl.label_cool_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_position_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);

}
void draw_up()
{
    lv_obj_del(ui_ctrl.btn_cool);
    lv_obj_del(ui_ctrl.btn_position);
    lv_obj_del(ui_ctrl.btn_up);

    ui_ctrl.btn_knife =  lv_btn_set(ui.src, ui_ctrl.btn_knife, 60, 60, 344, 8, event_handler);
    ui_ctrl.btn_next =  lv_btn_set(ui.src, ui_ctrl.btn_next, 60, 60, 412, 8, event_handler_next);
    ui_ctrl.btn_xy_clear =  lv_btn_set(ui.src, ui_ctrl.btn_xy_clear, 60, 60, 208, 8, event_handler);
    ui_ctrl.btn_z_clear =  lv_btn_set(ui.src, ui_ctrl.btn_z_clear, 60, 60, 276, 8, event_handler);

    lv_btn_set_style(ui_ctrl.btn_knife, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_knife, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_next, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_next, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_xy_clear, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_xy_clear, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);
    lv_btn_set_style(ui_ctrl.btn_z_clear, LV_BTN_STYLE_PR, &ui_ctrl.btn_move_pre);
    lv_btn_set_style(ui_ctrl.btn_z_clear, LV_BTN_STYLE_REL, &ui_ctrl.btn_move);

    ui_ctrl.label_xyclear_pic = lv_label_create(ui_ctrl.btn_xy_clear, NULL);
    lv_label_set_text(ui_ctrl.label_xyclear_pic, FONT_PIC_XY_CLEAR);
    ui_ctrl.label_zclear_pic = lv_label_create(ui_ctrl.btn_z_clear, NULL);
    lv_label_set_text(ui_ctrl.label_zclear_pic, FONT_PIC_Z_CLEAR);
    ui_ctrl.label_knife_pic = lv_label_create(ui_ctrl.btn_knife, NULL);
    lv_label_set_text(ui_ctrl.label_knife_pic, FONT_PIC_KNIFE);
    ui_ctrl.label_next_pic = lv_label_create(ui_ctrl.btn_next, NULL);
    lv_label_set_text(ui_ctrl.label_next_pic, FONT_PIC_NEXT);

    ui_ctrl.label_xyclear = lv_label_create(ui_ctrl.btn_xy_clear, NULL);
    lv_label_set_text(ui_ctrl.label_xyclear, CONTROL_XY_CLEAR_EN);
    ui_ctrl.label_zclear = lv_label_create(ui_ctrl.btn_z_clear, NULL);
    lv_label_set_text(ui_ctrl.label_zclear, CONTROL_Z_CLEAR_EN);
    ui_ctrl.label_knife = lv_label_create(ui_ctrl.btn_knife, NULL);
    lv_label_set_text(ui_ctrl.label_knife, CONTROL_KNIFE_EN);
    ui_ctrl.label_next = lv_label_create(ui_ctrl.btn_next, NULL);
    lv_label_set_text(ui_ctrl.label_next, CONTROL_NEXT_EN);

    lv_label_set_style(ui_ctrl.label_xyclear_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_zclear_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_knife_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(ui_ctrl.label_next_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);

}

void move_ctrl(char axis, uint8_t dir)
{
	float step;
	uint32_t speed;
    if(current_len == MOVE_LEN_1MM)
    {
        step = 1;
    }
    else if (current_len == MOVE_LEN_5MM)
    {
        step = 5;
    }
    else
    {
        step = 10;
    }
    if(current_speed == MOVE_HIGH_SPEED)
    {
        speed = 2000;
    }
    else if(current_speed == MOVE_MID_SPEED)
    {
        speed = 1000;
    }
    else
    {
        speed = 500;
    }
    if(dir == 0)
        action_step(axis, -step, speed);
    else
        action_step(axis, step, speed);
}


static void action_step(char axis, int len, uint32_t speed) {
    char cmd[96];
    sprintf(cmd, "$J=G91%c%dF%d\n", axis, len, speed);
    // grbl_cmd_send(CLIENT_SERIAL_LCD, cmd);
    MKS_PICO_CMD_SEND(cmd);
}



void draw_control(void) {

    draw_bar();

    set_btn();

    mks_ui_page.mks_ui_page = MKS_UI_PAGE_CONTROL;

}

void disp_control_data_updata()
{
    char buff[50];
    memset(buff,0,sizeof(buff));
    sprintf(buff,"X:%0.2f",grbl_cmd.grbl_basic_info.x_m_pos);
    lv_label_set_text(ui_ctrl.label_x_pos,buff);
    memset(buff,0,sizeof(buff));
    sprintf(buff,"Y:%0.2f",grbl_cmd.grbl_basic_info.y_m_pos);
    lv_label_set_text(ui_ctrl.label_y_pos,buff);
    memset(buff,0,sizeof(buff));
    sprintf(buff,"Z:%0.2f",grbl_cmd.grbl_basic_info.z_m_pos);
    lv_label_set_text(ui_ctrl.label_z_pos,buff);
}

void clear_control_page() {

    lv_obj_clean(ui.src);
}



