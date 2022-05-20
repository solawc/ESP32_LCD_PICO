#include "draw_home.h"

ui_home_t home_page;

enum{

    ID_HOME_CONTROL,
    ID_HOME_SCULPTRUE,
    ID_HOME_TOOL,
    ID_HOME_NONE,
};

static uint8_t get_event(lv_obj_t* obj) {

    if(obj == home_page.btn_control) return ID_HOME_CONTROL;
    else if(obj == home_page.btn_sculpture) return ID_HOME_SCULPTRUE;
    else if(obj == home_page.btn_tool) return ID_HOME_TOOL;
    else if(obj == home_page.reg_m || obj == home_page.reg_w)  return ID_HOME_NONE;
}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {

        switch(id) {
            case ID_HOME_CONTROL: 

            break;

            case ID_HOME_SCULPTRUE:
                
            break;

            case ID_HOME_TOOL: 

            break; 
        }
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

         switch(id) {
             case ID_HOME_CONTROL: 

            break;

            case ID_HOME_SCULPTRUE:

            break;

            case ID_HOME_TOOL: 

            break;
        }
    }
}



void draw_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 40);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

void draw_home(void) {
    
    draw_bar();

    lv_style_copy(&home_page.btn_pre_style , &lv_style_scr);
    home_page.btn_pre_style.body.grad_color = lv_color_hex(0x4DE585);;
	home_page.btn_pre_style.body.main_color = lv_color_hex(0x4DE585);;
    home_page.btn_pre_style.body.radius = 10;
    home_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&home_page.btn_rel_style , &lv_style_scr);
    home_page.btn_rel_style.body.grad_color = lv_color_hex(0x333333);
	home_page.btn_rel_style.body.main_color = lv_color_hex(0x333333);
    home_page.btn_rel_style.body.radius = 10;
    home_page.btn_rel_style.text.color = lv_color_hex(0x4DE585);

    lv_style_copy(&home_page.btn_reg_style , &lv_style_scr);
    home_page.btn_reg_style.body.grad_color = lv_color_hex(0x191919);
	home_page.btn_reg_style.body.main_color = lv_color_hex(0x191919);
    home_page.btn_reg_style.body.border.color = lv_color_hex(0x4DE585);
    home_page.btn_reg_style.body.border.width = 1;
    home_page.btn_reg_style.body.radius = 8;
    home_page.btn_reg_style.text.color = lv_color_hex(0x4DE585);

    home_page.btn_control =  lv_btn_set(ui.src, home_page.btn_control, 150, 104, 8, 208, event_handler);
    home_page.btn_sculpture =  lv_btn_set(ui.src, home_page.btn_sculpture, 150, 104, 165, 208, event_handler);
    home_page.btn_tool =  lv_btn_set(ui.src, home_page.btn_tool, 150, 104, 322, 208, event_handler);

    home_page.reg_w =  lv_btn_set(ui.src, home_page.reg_w, 228, 152, 8, 48, event_handler);
    home_page.reg_m =  lv_btn_set(ui.src, home_page.reg_m, 228, 152, 244, 48, event_handler);

    lv_btn_set_style(home_page.btn_control, LV_BTN_STYLE_PR, &home_page.btn_pre_style);
    lv_btn_set_style(home_page.btn_control, LV_BTN_STYLE_REL, &home_page.btn_rel_style);

    lv_btn_set_style(home_page.btn_sculpture, LV_BTN_STYLE_PR, &home_page.btn_pre_style);
    lv_btn_set_style(home_page.btn_sculpture, LV_BTN_STYLE_REL, &home_page.btn_rel_style);

    lv_btn_set_style(home_page.btn_tool, LV_BTN_STYLE_PR, &home_page.btn_pre_style);
    lv_btn_set_style(home_page.btn_tool, LV_BTN_STYLE_REL, &home_page.btn_rel_style);

    lv_btn_set_style(home_page.reg_w, LV_BTN_STYLE_PR, &home_page.btn_reg_style);
    lv_btn_set_style(home_page.reg_w, LV_BTN_STYLE_REL, &home_page.btn_reg_style);

    lv_btn_set_style(home_page.reg_m, LV_BTN_STYLE_PR, &home_page.btn_reg_style);
    lv_btn_set_style(home_page.reg_m, LV_BTN_STYLE_REL, &home_page.btn_reg_style);

    lv_label_set(ui.src, home_page.label_m_pos, 292, 63, "Mechanical coordinates");
    lv_label_set(ui.src, home_page.label_m_pos, 56, 63, "Working coordinates");

    home_page.label_x_mpos = lv_label_set(ui.src, home_page.label_x_mpos, 56, 104, "X:0.0");
    home_page.label_y_mpos = lv_label_set(ui.src, home_page.label_y_mpos, 56, 136, "Y:0.0");
    home_page.label_z_mpos = lv_label_set(ui.src, home_page.label_z_mpos, 56, 168, "Z:0.0");

    home_page.label_x_wpos = lv_label_set(ui.src, home_page.label_x_wpos, 292, 104, "X:0.0");
    home_page.label_y_wpos = lv_label_set(ui.src, home_page.label_y_wpos, 292, 136, "Y:0.0");
    home_page.label_z_wpos = lv_label_set(ui.src, home_page.label_z_wpos, 292, 168, "Z:0.0");

    // lv_label_set_btn( ui.src, home_page.label_control, home_page.btn_control, 0, -40, "Control");

    home_page.label_control_pic = lv_label_create(home_page.btn_control, NULL);
    lv_label_set_text(home_page.label_control_pic, FONT_PIC_BACK);
    lv_label_set_style(home_page.label_control_pic, LV_LABEL_STYLE_MAIN, &ui.di_font);

    home_page.label_control = lv_label_create(home_page.btn_control, NULL);
    lv_obj_align(home_page.label_control, home_page.label_control_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(home_page.label_control, "Control");

    lv_label_set_btn( ui.src, home_page.label_sculpture, home_page.btn_sculpture, 0, -40, "Sculpture");
    lv_label_set_btn( ui.src, home_page.label_tool, home_page.btn_tool, 0, -40, "Tool");
}

static void set_font_pic_color(uint8_t id) {

    switch(id) {

        case ID_HOME_CONTROL: 

        break;

        case ID_HOME_SCULPTRUE:

        break;

        case ID_HOME_TOOL: 

        break;
    }

}




