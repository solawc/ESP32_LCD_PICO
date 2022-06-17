#include "draw_ui.h"

_ui_t ui;


void ui_init_style(void) {

    // reset all style here
    ui_theme_reset();

    // get theme color form eeprom;
    ui.ui_theme.theme_type =  get_default_theme();

    // set all style here
    ui_theme_set();
}

void ui_theme_set(void) {

    uint32_t get_color;

    if(ui.ui_theme.theme_type == THEME_WRITE)            {
        get_color = F_THEME_WRITE;
    }    
    else if(ui.ui_theme.theme_type == THEME_GREEN)       {
        get_color = F_THEME_GREEN;
    }    
    else if(ui.ui_theme.theme_type == THEME_RED)         {
        get_color = F_THEME_RED;
    }    
    else if(ui.ui_theme.theme_type == THEME_ORANGE)      {
        get_color = F_THEME_ORANGE;
    }  
    else if(ui.ui_theme.theme_type == THEME_PINK)      {
        get_color = F_THEME_PINK;
    }      

    
    ui.ui_theme.btn_pre_color = get_color;
    ui.ui_theme.btn_rel_color = F_THEME_BTN_REL_COLOR;
    ui.ui_theme.font_pre_color = F_THEME_BTN_REL_COLOR;
    ui.ui_theme.font_rel_color = get_color;

    serial_sendf(CLIENT_SERIAL, "color:0x%x\n", get_color);
    serial_sendf(CLIENT_SERIAL, "color2:0x%x\n", ui.ui_theme.font_rel_color);

    /********************************* 主页样式****************************************************/
    lv_style_copy(&ui.src_style , &lv_style_scr);
    ui.src_style .body.grad_color = LV_COLOR_MAKE(0x19, 0x19, 0x19);
	ui.src_style .body.main_color = LV_COLOR_MAKE(0x19, 0x19, 0x19);
    ui.src_style.text.font = &dlc32_gb2312;
    ui.src_style.text.color = lv_color_hex(ui.ui_theme.font_rel_color);
    /*********************************************************************************************/

    /********************************* 状态栏样式*************************************************/
    lv_style_copy(&ui.src_1_style , &lv_style_scr);
    ui.src_1_style .body.grad_color = lv_color_hex(ui.ui_theme.font_rel_color); 
	ui.src_1_style .body.main_color = lv_color_hex(ui.ui_theme.font_rel_color); 

    lv_style_copy(&ui.src_2_style , &lv_style_scr);
    ui.src_2_style .body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR); 
	ui.src_2_style .body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR); 
    /*********************************************************************************************/

    /********************************* 40x40字库的样式********************************************/
    lv_style_copy(&ui.di_font_40_40 , &lv_style_scr);
    ui.di_font_40_40.text.font = &dlc_font_40x40;
    ui.di_font_40_40.text.color = lv_color_hex(ui.ui_theme.font_rel_color); //lv_color_hex(0x4DE585);

    lv_style_copy(&ui.di_font_40_40_pre , &lv_style_scr);
    ui.di_font_40_40_pre.text.font = &dlc_font_40x40;
    ui.di_font_40_40_pre.text.color = lv_color_hex(0x191919);
    /*********************************************************************************************/

    /********************************* 60x60字库的样式********************************************/
    lv_style_copy(&ui.di_font_60_60 , &lv_style_scr);
    ui.di_font_60_60.text.font = &dlc_font_70x70;
    ui.di_font_60_60.text.color = lv_color_hex(ui.ui_theme.font_rel_color); //lv_color_hex(0x4DE585);

    lv_style_copy(&ui.di_font_60_60_pre , &lv_style_scr);
    ui.di_font_60_60_pre.text.font = &dlc_font_70x70;
    ui.di_font_60_60_pre.text.color = lv_color_hex(0x191919);
    /*********************************************************************************************/

    /********************************* 70x70字库的样式********************************************/
    lv_style_copy(&ui.di_font_70_70 , &lv_style_scr);
    ui.di_font_70_70.text.font = &dlc_font_70x70;
    ui.di_font_70_70.text.color = lv_color_hex(ui.ui_theme.font_rel_color); //lv_color_hex(0x4DE585);

    lv_style_copy(&ui.di_font_70_70_pre , &lv_style_scr);
    ui.di_font_70_70_pre.text.font = &dlc_font_70x70;
    ui.di_font_70_70_pre.text.color = lv_color_hex(0x191919);
    /*********************************************************************************************/

    /********************************* back的样式********************************************/
    lv_style_copy(&ui.com_back , &lv_style_scr);
    ui.com_back.body.border.color = lv_color_hex(ui.ui_theme.font_rel_color);
    ui.com_back.body.border.width = 1;
    ui.com_back.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    ui.com_back.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    ui.com_back.body.radius = 8;
    ui.com_back.text.color = lv_color_hex(ui.ui_theme.font_rel_color);

    lv_style_copy(&ui.com_back_pre , &lv_style_scr);
    ui.com_back_pre.body.border.color = lv_color_hex(ui.ui_theme.font_rel_color);
    ui.com_back_pre.body.border.width = 1;
    ui.com_back_pre.body.grad_color = lv_color_hex(ui.ui_theme.font_rel_color);
    ui.com_back_pre.body.main_color = lv_color_hex(ui.ui_theme.font_rel_color);
    ui.com_back_pre.body.radius = 8;
    ui.com_back_pre.text.color = lv_color_hex(F_THEME_BTN_REL_COLOR);

    /*********************************************************************************************/
}

void ui_theme_reset(void) {

    // 背景页面style
    lv_style_copy(&ui.src_style , &lv_style_scr);
    ui.src_style .body.grad_color = LV_COLOR_MAKE(0x19, 0x19, 0x19);
	ui.src_style .body.main_color = LV_COLOR_MAKE(0x19, 0x19, 0x19);
    ui.src_style.text.font = &dlc32_gb2312;
    ui.src_style.text.color = lv_color_hex(0x4DE585);

    lv_style_copy(&ui.src_1_style , &lv_style_scr);
    ui.src_1_style .body.grad_color = LV_COLOR_MAKE(0x26, 0x26, 0x26);
	ui.src_1_style .body.main_color = LV_COLOR_MAKE(0x26, 0x26, 0x26);

    lv_style_copy(&ui.di_font_70_70 , &lv_style_scr);
    ui.di_font_70_70.text.font = &dlc_font_70x70;
    ui.di_font_70_70.text.color = lv_color_hex(0x4DE585);

    lv_style_copy(&ui.di_font_70_70_pre , &lv_style_scr);
    ui.di_font_70_70_pre.text.font = &dlc_font_70x70;
    ui.di_font_70_70_pre.text.color = lv_color_hex(0x191919);
}

theme_type_t get_default_theme(void) {

    if(Machine_theme->get() == 0) return THEME_WRITE;
    else if(Machine_theme->get() == 1) return THEME_GREEN;
    else if(Machine_theme->get() == 2) return THEME_RED;
    else if(Machine_theme->get() == 3) return THEME_ORANGE;
    else if(Machine_theme->get() == 4) return THEME_PINK;
    else return THEME_GREEN;
}

void set_current_color(theme_type_t color) {

    char set_mc_val[2];
    uint8_t set_value;

    ui.ui_theme.theme_type = color;

    if(color == THEME_WRITE) {set_value = 0;}
    else if(color == THEME_GREEN) {set_value = 1;}
    else if(color == THEME_RED) {set_value = 2;}
    else if(color == THEME_ORANGE) {set_value = 3;}
    else if(color == THEME_PINK) {set_value = 4;}

    sprintf(set_mc_val, "%d", set_value);
    Machine_theme->setStringValue(set_mc_val);
}

uint32_t get_current_color(void) {

    return ui.ui_theme.font_rel_color;
}




lv_obj_t* lv_btn_set(lv_obj_t* scr, lv_obj_t* btn, lv_coord_t btn_w, lv_coord_t btn_h, lv_coord_t x, lv_coord_t y, lv_event_cb_t event_cb) {

    btn = lv_btn_create(scr, NULL);
    lv_obj_set_size(btn, btn_w, btn_h);
    lv_obj_set_pos(btn, x, y);
    lv_obj_set_event_cb(btn, event_cb);
    return btn;
}


lv_obj_t* lv_label_set(lv_obj_t* scr, lv_obj_t* label, lv_coord_t x, lv_coord_t y, const char *text) {

    label = lv_label_create(scr, NULL);
    lv_obj_set_pos(label, x, y);
    lv_label_set_long_mode(label, LV_LABEL_LONG_EXPAND);
    lv_label_set_text(label, text);
    return  label;
}

lv_obj_t* lv_label_set_btn(lv_obj_t* scr, lv_obj_t* label, lv_obj_t* base, lv_coord_t x, lv_coord_t y, const char *text) {

    label = lv_label_create(scr, NULL);
    lv_label_set_long_mode(label, LV_LABEL_LONG_BREAK);
    lv_label_set_recolor(label, true);
    lv_obj_set_size(label, 130, 32);
    lv_obj_align(label, base, LV_ALIGN_OUT_BOTTOM_MID, x, y);
    lv_label_set_align(label, LV_LABEL_ALIGN_CENTER);
    lv_label_set_text(label, text);
    return  label;
}

