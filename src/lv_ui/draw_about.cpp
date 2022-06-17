/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_about.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_about_t about_page;

/***************************************************************************
 *                          static function
 * - static void set_about_font_pic_color(uint8_t id, bool status) 
 * - static void draw_about_bar(void)
 * 
***************************************************************************/
static void set_about_font_pic_color(uint8_t id, bool status);
static void draw_about_bar(void);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    ID_LANGUAGE_CN,
    ID_LANGUAGE_EN,
    ID_LANGUAGE_RU,
    ID_LANGUAGE_DE,
    ID_LANGUAGE_BACK,
};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {
   if(obj == about_page.obj_ver) return ID_LANGUAGE_CN;
   else if(obj == about_page.obj_fw) return ID_LANGUAGE_EN;
   else if(obj == about_page.obj_machine_type) return ID_LANGUAGE_RU;
   else if(obj == about_page.obj_axes) return ID_LANGUAGE_DE;
   else if(obj == about_page.btn_back) return ID_LANGUAGE_BACK;
}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        
        set_about_font_pic_color(id, true);

        switch(id) {
            case ID_LANGUAGE_CN: 
                
            break;

            case ID_LANGUAGE_EN:
                
            break;

            case ID_LANGUAGE_RU: 

            break; 
            case ID_LANGUAGE_DE:
                
            break;

        }
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        set_about_font_pic_color(id, false);
        

        switch(id) {
            case ID_LANGUAGE_CN: 
                
            break;

            case ID_LANGUAGE_EN:

            break;

            case ID_LANGUAGE_RU: 

            break; 
            case ID_LANGUAGE_DE:
                
            break;


            case ID_LANGUAGE_BACK: 
                clean_about_page();
                draw_tool();
            break; 
            }
    }
}

static void draw_about_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 76);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

#define ABOUT_VER_EN "Screen firmware version:"
#define ABOUT_WF_EN  "Lower computer firmware:"
#define ABOUT_MACHINE_TYPE_EN  "Machine type:"
#define ABOUT_AXES_EN  "Number of axes:"
#define ABOUT_RATE_EN  "Baud rate:"
#define ABOUT_TYPE_EN  "Wireless type:"

#define ABOUT_VER_TEXT_EN "V1.1.0"
#define ABOUT_WF_TEXT_EN  "GRBL V0.9"
#define ABOUT_MACHINE_TYPE_TEXT_EN  "CNC"
#define ABOUT_AXES_TEXT_EN  "2 axes"
#define ABOUT_RATE_TEXT_EN  "115200"
#define ABOUT_TYPE_TEXT_EN  "AP ESP32_2763"

#define ABOUT_BACK_EN  "Back"



void draw_about(void) {
    
    draw_about_bar();

    lv_style_copy(&about_page.btn_pre_style , &lv_style_scr);
    about_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	about_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    about_page.btn_pre_style.body.radius = 10;
    about_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&about_page.btn_rel_style , &lv_style_scr);
    about_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	about_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    about_page.btn_rel_style.body.radius = 10;
    about_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    lv_style_copy(&about_page.obj_style , &lv_style_scr);
    about_page.obj_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	about_page.obj_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    about_page.obj_style.body.radius = 10;
    about_page.obj_style.text.color = LV_COLOR_WHITE; //ui.ui_theme.font_rel_color  

    about_page.obj_ver =  lv_obj_set(ui.src, about_page.obj_ver, ABOUT_OBJ_W, ABOUT_OBJ_H, ABOUT_OBJ_X, ABOUT_OBJ_Y1);
    about_page.obj_fw =  lv_obj_set(ui.src, about_page.obj_fw, ABOUT_OBJ_W, ABOUT_OBJ_H, ABOUT_OBJ_X, ABOUT_OBJ_Y2);
    about_page.obj_machine_type =  lv_obj_set(ui.src, about_page.obj_machine_type, ABOUT_OBJ_W, ABOUT_OBJ_H, ABOUT_OBJ_X, ABOUT_OBJ_Y3);
    about_page.obj_axes =  lv_obj_set(ui.src, about_page.obj_axes, ABOUT_OBJ_W, ABOUT_OBJ_H, ABOUT_OBJ_X, ABOUT_OBJ_Y4);
    about_page.obj_rate =  lv_obj_set(ui.src, about_page.obj_rate, ABOUT_OBJ_W, ABOUT_OBJ_H, ABOUT_OBJ_X, ABOUT_OBJ_Y5);
    about_page.obj_type =  lv_obj_set(ui.src, about_page.obj_type, ABOUT_OBJ_W, ABOUT_OBJ_H, ABOUT_OBJ_X, ABOUT_OBJ_Y6);

    about_page.btn_back =  lv_btn_set(ui.src, about_page.btn_back, 60, 60, LANGUAGE_BTN_BACK_X, LANGUAGE_BTN_BACK_Y, event_handler);

    // lv_btn_set_style(about_page.obj_ver, LV_BTN_STYLE_PR, &about_page.btn_pre_style);   // 松开
    lv_obj_set_style(about_page.obj_ver, &about_page.btn_rel_style);  // 按下

    // lv_btn_set_style(about_page.obj_fw, LV_BTN_STYLE_PR, &about_page.btn_pre_style);
    lv_obj_set_style(about_page.obj_fw, &about_page.btn_rel_style);

    // lv_btn_set_style(about_page.obj_machine_type, LV_BTN_STYLE_PR, &about_page.btn_pre_style);
    lv_obj_set_style(about_page.obj_machine_type, &about_page.btn_rel_style);

    // lv_btn_set_style(about_page.obj_axes, LV_BTN_STYLE_PR, &about_page.btn_pre_style);
    lv_obj_set_style(about_page.obj_axes, &about_page.btn_rel_style);

    lv_obj_set_style(about_page.obj_rate, &about_page.btn_rel_style);

    lv_obj_set_style(about_page.obj_type, &about_page.btn_rel_style);


    lv_btn_set_style(about_page.btn_back, LV_BTN_STYLE_PR, &about_page.btn_pre_style);
    lv_btn_set_style(about_page.btn_back, LV_BTN_STYLE_REL, &about_page.btn_pre_style);

    about_page.label_back_pic = lv_label_create(about_page.btn_back, NULL);
    lv_label_set_text(about_page.label_back_pic, FONT_PIC_BACK);
    lv_label_set_style(about_page.label_back_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    about_page.label_ver = lv_label_create(about_page.obj_ver, NULL);
    lv_obj_align(about_page.label_ver, about_page.obj_ver, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_style(about_page.label_ver,LV_LABEL_STYLE_MAIN,&about_page.obj_style);
    lv_label_set_text(about_page.label_ver, ABOUT_VER_EN);

    about_page.label_fw = lv_label_create(about_page.obj_fw, NULL);
    lv_obj_align(about_page.label_fw, about_page.obj_fw, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_style(about_page.label_fw,LV_LABEL_STYLE_MAIN,&about_page.obj_style);
    lv_label_set_text(about_page.label_fw, ABOUT_WF_EN);

    about_page.label_machine_type = lv_label_create(about_page.obj_machine_type, NULL);
    lv_obj_align(about_page.label_machine_type, about_page.obj_machine_type, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_style(about_page.label_machine_type,LV_LABEL_STYLE_MAIN,&about_page.obj_style);
    lv_label_set_text(about_page.label_machine_type, ABOUT_MACHINE_TYPE_EN);

    about_page.label_axis = lv_label_create(about_page.obj_axes, NULL);
    lv_obj_align(about_page.label_axis, about_page.obj_axes, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_style(about_page.label_axis,LV_LABEL_STYLE_MAIN,&about_page.obj_style);
    lv_label_set_text(about_page.label_axis,ABOUT_AXES_EN);

    about_page.label_rate = lv_label_create(about_page.obj_rate, NULL);
    lv_obj_align(about_page.label_rate, about_page.obj_rate, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_style(about_page.label_rate,LV_LABEL_STYLE_MAIN,&about_page.obj_style);
    lv_label_set_text(about_page.label_rate,ABOUT_RATE_EN);

    about_page.label_type = lv_label_create(about_page.obj_type, NULL);
    lv_obj_align(about_page.label_type, about_page.obj_type, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_style(about_page.label_type,LV_LABEL_STYLE_MAIN,&about_page.obj_style);
    lv_label_set_text(about_page.label_type,ABOUT_TYPE_EN);


    about_page.label_ver_text = lv_label_create(about_page.obj_ver, NULL);
    lv_obj_align(about_page.label_ver_text, about_page.obj_ver, LV_ALIGN_IN_RIGHT_MID, -100, 0);
    lv_label_set_align(about_page.label_ver_text,LV_LABEL_ALIGN_RIGHT);
    lv_label_set_text(about_page.label_ver_text, ABOUT_VER_TEXT_EN);

    about_page.label_fw_text = lv_label_create(about_page.obj_fw, NULL);
    lv_obj_align(about_page.label_fw_text, about_page.obj_fw, LV_ALIGN_IN_RIGHT_MID, -100, 0);
    lv_label_set_align(about_page.label_fw_text,LV_LABEL_ALIGN_RIGHT);
    lv_label_set_text(about_page.label_fw_text, ABOUT_WF_TEXT_EN);

    about_page.label_machine_type_text = lv_label_create(about_page.obj_machine_type, NULL);
    lv_obj_align(about_page.label_machine_type_text, about_page.obj_machine_type, LV_ALIGN_IN_RIGHT_MID, -100, 0);
    lv_label_set_align(about_page.label_machine_type_text,LV_LABEL_ALIGN_RIGHT);
    lv_label_set_text(about_page.label_machine_type_text, ABOUT_MACHINE_TYPE_TEXT_EN);

    about_page.label_axis_text = lv_label_create(about_page.obj_axes, NULL);
    lv_obj_align(about_page.label_axis_text, about_page.obj_axes, LV_ALIGN_IN_RIGHT_MID, -100, 0);
    lv_label_set_align(about_page.label_axis_text,LV_LABEL_ALIGN_RIGHT);
    lv_label_set_text(about_page.label_axis_text,ABOUT_AXES_TEXT_EN);

    about_page.label_rate_text = lv_label_create(about_page.obj_rate, NULL);
    lv_obj_align(about_page.label_rate_text, about_page.obj_rate, LV_ALIGN_IN_RIGHT_MID, -100, 0);
    lv_label_set_align(about_page.label_rate_text,LV_LABEL_ALIGN_RIGHT);
    lv_label_set_text(about_page.label_rate_text,ABOUT_RATE_TEXT_EN);

    about_page.label_type_text = lv_label_create(about_page.obj_type, NULL);
    lv_obj_align(about_page.label_type_text, about_page.obj_type, LV_ALIGN_IN_RIGHT_MID, -100, 0);
    lv_label_set_align(about_page.label_type_text,LV_LABEL_ALIGN_RIGHT);
    lv_label_set_text(about_page.label_type_text,ABOUT_TYPE_TEXT_EN);

    about_page.label_back = lv_label_create(about_page.btn_back, NULL);
    lv_obj_align(about_page.label_back, about_page.label_back_pic, LV_ALIGN_IN_LEFT_MID, -30, 0);
    lv_label_set_text(about_page.label_back,ABOUT_BACK_EN);


}

/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_about_font_pic_color(uint8_t id, bool status) {

    // switch(id) {
    //     case ID_LANGUAGE_CN: 
    //         if(status) lv_label_set_style(about_page.label_ver_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(about_page.label_ver_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_LANGUAGE_EN: 
    //         if(status) lv_label_set_style(about_page.label_fw_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(about_page.label_fw_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_LANGUAGE_RU: 
    //         if(status) lv_label_set_style(about_page.label_machine_type_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(about_page.label_machine_type_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_LANGUAGE_DE: 
    //         if(status) lv_label_set_style(about_page.label_axis_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(about_page.label_axis_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    // }

}





void clean_about_page(void) {

    lv_obj_clean(ui.src);
}

