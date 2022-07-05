/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_home.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_home_t home_page;

/***************************************************************************
 *                          static function
 * - static void set_font_pic_color(uint8_t id, bool status) 
 * - static void draw_bar(void)
 * 
***************************************************************************/
static void set_font_pic_color(uint8_t id, bool status);
static void draw_bar(void);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    ID_HOME_CONTROL,
    ID_HOME_SCULPTRUE,
    ID_HOME_TOOL,
    ID_HOME_NONE,
};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {

    if(obj == home_page.btn_control) return ID_HOME_CONTROL;
    else if(obj == home_page.btn_sculpture) return ID_HOME_SCULPTRUE;
    else if(obj == home_page.btn_tool) return ID_HOME_TOOL;
    else if(obj == home_page.reg_m || obj == home_page.reg_w)  return ID_HOME_NONE;
}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        
        set_font_pic_color(id, true);

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

        set_font_pic_color(id, false);
        
         switch(id) {
            case ID_HOME_CONTROL: 
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                clean_home_page();
                draw_control();
            break;

            case ID_HOME_SCULPTRUE:
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                clean_home_page();
                MKS_PICO_CMD_SEND("[ESP210]\n");
                draw_file_list();
            break;

            case ID_HOME_TOOL: 
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                clean_home_page();
                draw_tool();
            break;
        }
    }
}

static void draw_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 40);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

void draw_home(void) {
    char buff[50];
    draw_bar();
    lv_style_copy(&home_page.btn_pre_style , &lv_style_scr);
    home_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	home_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    home_page.btn_pre_style.body.radius = 10;
    home_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&home_page.btn_rel_style , &lv_style_scr);
    home_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	home_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    home_page.btn_rel_style.body.radius = 10;
    home_page.btn_rel_style.text.color = lv_color_hex(get_current_color());

    lv_style_copy(&home_page.btn_reg_style , &lv_style_scr);
    home_page.btn_reg_style.body.grad_color = lv_color_hex(F_THEME_FONR_REL_COLOR);
	home_page.btn_reg_style.body.main_color = lv_color_hex(F_THEME_FONR_REL_COLOR);
    home_page.btn_reg_style.body.border.color = lv_color_hex(get_current_color());
    home_page.btn_reg_style.body.border.width = 1;
    home_page.btn_reg_style.body.radius = 8;
    home_page.btn_reg_style.text.color = lv_color_hex(get_current_color());

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
    lv_label_set(ui.src, home_page.label_w_pos, 56, 63, "Working coordinates");

    home_page.label_w_pic = lv_label_set(ui.src, home_page.label_w_pic, 16, 52, FONT_PIC_WORKING_COORDINATES);
    home_page.label_m_pic = lv_label_set(ui.src, home_page.label_m_pic, 252, 52, FONT_PIC_MECHANICAL_COORDINATES_1);

    lv_label_set_style(home_page.label_w_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_label_set_style(home_page.label_m_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);

    FD_ZERO(buff);
    sprintf(buff,"X:%0.2f",grbl_cmd.grbl_basic_info.x_m_pos);
    home_page.label_x_mpos = lv_label_set(ui.src, home_page.label_x_mpos, 56, 104, buff);
    FD_ZERO(buff);
    sprintf(buff,"Y:%0.2f",grbl_cmd.grbl_basic_info.y_m_pos);
    home_page.label_y_mpos = lv_label_set(ui.src, home_page.label_y_mpos, 56, 136, buff);
    FD_ZERO(buff);
    sprintf(buff,"Z:%0.2f",grbl_cmd.grbl_basic_info.z_m_pos);
    home_page.label_z_mpos = lv_label_set(ui.src, home_page.label_z_mpos, 56, 168, buff);

    FD_ZERO(buff);
    sprintf(buff,"X:%0.2f",grbl_cmd.grbl_basic_info.x_w_pos);
    home_page.label_x_wpos = lv_label_set(ui.src, home_page.label_x_wpos, 292, 104, buff);
    FD_ZERO(buff);
    sprintf(buff,"X:%0.2f",grbl_cmd.grbl_basic_info.y_w_pos);
    home_page.label_y_wpos = lv_label_set(ui.src, home_page.label_y_wpos, 292, 136, buff);
    FD_ZERO(buff);
    sprintf(buff,"X:%0.2f",grbl_cmd.grbl_basic_info.z_w_pos);
    home_page.label_z_wpos = lv_label_set(ui.src, home_page.label_z_wpos, 292, 168, buff);

    home_page.label_control_pic = lv_label_create(home_page.btn_control, NULL);
    lv_label_set_text(home_page.label_control_pic, FONT_PIC_CONTROL);

    home_page.label_sculpture_pic = lv_label_create(home_page.btn_sculpture, NULL);
    lv_label_set_text(home_page.label_sculpture_pic, FONT_PIC_TOOLS);

    home_page.label_tool_pic = lv_label_create(home_page.btn_tool, NULL);
    lv_label_set_text(home_page.label_tool_pic, FONT_PIC_SCULPTURE);

    lv_label_set_style(home_page.label_control_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_70_70);
    lv_label_set_style(home_page.label_sculpture_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_70_70);
    lv_label_set_style(home_page.label_tool_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_70_70);

    home_page.label_control = lv_label_create(home_page.btn_control, NULL);
    lv_obj_align(home_page.label_control, home_page.label_control_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(home_page.label_control, "Control");

    home_page.label_sculpture = lv_label_create(home_page.btn_sculpture, NULL);
    lv_obj_align(home_page.label_sculpture, home_page.label_sculpture_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(home_page.label_sculpture, "Sculpture");

    home_page.label_tool = lv_label_create(home_page.btn_tool, NULL);
    lv_obj_align(home_page.label_tool, home_page.label_tool_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(home_page.label_tool, "Tool");

    mks_ui_page.mks_ui_page = MKS_UI_PAGE_HOME;
}

/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_font_pic_color(uint8_t id, bool status) {

    switch(id) {

        case ID_HOME_CONTROL: 
            if(status) lv_label_set_style(home_page.label_control_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_70_70_pre);
            else lv_label_set_style(home_page.label_control_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_70_70);
        break;

        case ID_HOME_SCULPTRUE:
            if(status) lv_label_set_style(home_page.label_sculpture_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_70_70_pre);
            else lv_label_set_style(home_page.label_sculpture_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_70_70);
        break;

        case ID_HOME_TOOL: 
            if(status) lv_label_set_style(home_page.label_tool_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_70_70_pre);
            else lv_label_set_style(home_page.label_tool_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_70_70);
        break;
    }

}

void disp_home_data_updata()
{
    
    char buff[50];
    FD_ZERO(buff);
    sprintf(buff,"X:%0.2f",grbl_cmd.grbl_basic_info.x_m_pos);
    lv_label_set_text(home_page.label_x_mpos,buff);
    FD_ZERO(buff);
    sprintf(buff,"Y:%0.2f",grbl_cmd.grbl_basic_info.y_m_pos);
    lv_label_set_text(home_page.label_y_mpos,buff);
    FD_ZERO(buff);
    sprintf(buff,"Z:%0.2f",grbl_cmd.grbl_basic_info.z_m_pos);
    lv_label_set_text(home_page.label_z_mpos,buff);


    FD_ZERO(buff);
    sprintf(buff,"X:%0.2f",grbl_cmd.grbl_basic_info.x_w_pos);
    lv_label_set_text(home_page.label_x_wpos,buff);
    FD_ZERO(buff);
    sprintf(buff,"X:%0.2f",grbl_cmd.grbl_basic_info.y_w_pos);
    lv_label_set_text(home_page.label_y_wpos,buff);
    FD_ZERO(buff);
    sprintf(buff,"X:%0.2f",grbl_cmd.grbl_basic_info.z_w_pos);
    lv_label_set_text(home_page.label_z_wpos,buff);

}

void clean_home_page(void) {

    lv_obj_clean(ui.src);
}




