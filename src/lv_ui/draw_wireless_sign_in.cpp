/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_wireless_sign_in.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_wireless_sign_in_t wireless_sign_in_page;

/***************************************************************************
 *                          static function
 * - static void set_wireless_sign_in_font_pic_color(uint8_t id, bool status) 
 * - static void draw_wireless_sign_in_bar(void)
 * 
***************************************************************************/
static void set_wireless_sign_in_font_pic_color(uint8_t id, bool status);
static void draw_wireless_sign_in_bar(void);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    ID_WIRELESS_NAME,
    ID_WIRELESS_PASSWORD,
    ID_WIRELESS_SIGN_IN_BACK,
};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {
   if(obj == wireless_sign_in_page.btn_wreless_name) return ID_WIRELESS_NAME;
   else if(obj == wireless_sign_in_page.btn_wreless_password) return ID_WIRELESS_PASSWORD;
   else if(obj == wireless_sign_in_page.btn_back) return ID_WIRELESS_SIGN_IN_BACK;

}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        
        set_wireless_sign_in_font_pic_color(id, true);

        switch(id) {
            case ID_WIRELESS_NAME: 
                
            break;

            case ID_WIRELESS_PASSWORD:
                
            break;


        }
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        set_wireless_sign_in_font_pic_color(id, false);
        

        switch(id) {
            case ID_WIRELESS_NAME: 
                clean_wireless_sign_in_page();
                draw_keyboard();
            break;

            case ID_WIRELESS_PASSWORD:

            break;


                
            break;


            case ID_WIRELESS_SIGN_IN_BACK: 
                clean_wireless_sign_in_page();
                draw_wifi_list();
            break; 
            }
    }
}

static void draw_wireless_sign_in_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 76);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

#define WIFI_NAME_EN "WIFI Name:"
#define PASSWORD_EN  "Password:"
#define ABOUT_MACHINE_TYPE_EN  "TP_LINK 12345"
#define ABOUT_AXES_EN  "123456abc"
#define BLUETOOTH_NAME_EN  "Bluetooth name:"



#define ABOUT_BACK_EN  "Back"



void draw_wireless_sign_in(void) {
    
    draw_wireless_sign_in_bar();

    lv_style_copy(&wireless_sign_in_page.btn_pre_style , &lv_style_scr);
    wireless_sign_in_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	wireless_sign_in_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    wireless_sign_in_page.btn_pre_style.body.radius = 10;
    wireless_sign_in_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&wireless_sign_in_page.btn_rel_style , &lv_style_scr);
    wireless_sign_in_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	wireless_sign_in_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    wireless_sign_in_page.btn_rel_style.body.radius = 10;
    wireless_sign_in_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    lv_style_copy(&wireless_sign_in_page.new_btn_style , &lv_style_scr);
    wireless_sign_in_page.new_btn_style.body.grad_color = LV_COLOR_WHITE;
	wireless_sign_in_page.new_btn_style.body.main_color = LV_COLOR_WHITE;
    wireless_sign_in_page.new_btn_style.body.radius = 5;
    wireless_sign_in_page.new_btn_style.text.color = LV_COLOR_BLACK; //ui.ui_theme.font_rel_color  

    wireless_sign_in_page.obj_wreless_name =  lv_obj_set(ui.src, wireless_sign_in_page.obj_wreless_name, ABOUT_OBJ_W, ABOUT_OBJ_H, ABOUT_OBJ_X, ABOUT_OBJ_Y1);
    wireless_sign_in_page.obj_wreless_password =  lv_obj_set(ui.src, wireless_sign_in_page.obj_wreless_password, ABOUT_OBJ_W, ABOUT_OBJ_H, ABOUT_OBJ_X, ABOUT_OBJ_Y2);

    wireless_sign_in_page.btn_wreless_name =  lv_btn_set(ui.src, wireless_sign_in_page.btn_wreless_name, ABOUT_BTN_W, ABOUT_BTN_H, ABOUT_BTN_X, ABOUT_BTN_Y1, event_handler);
    wireless_sign_in_page.btn_wreless_password =  lv_btn_set(ui.src, wireless_sign_in_page.btn_wreless_name, ABOUT_BTN_W, ABOUT_BTN_H, ABOUT_BTN_X, ABOUT_BTN_Y2, event_handler);

    wireless_sign_in_page.btn_back =  lv_btn_set(ui.src, wireless_sign_in_page.btn_back, 60, 60, LANGUAGE_BTN_BACK_X, LANGUAGE_BTN_BACK_Y, event_handler);

    lv_obj_set_style(wireless_sign_in_page.obj_wreless_name, &wireless_sign_in_page.btn_rel_style);  // 按下

    lv_obj_set_style(wireless_sign_in_page.obj_wreless_password, &wireless_sign_in_page.btn_rel_style);

    lv_btn_set_style(wireless_sign_in_page.btn_wreless_name, LV_BTN_STYLE_PR, &wireless_sign_in_page.new_btn_style);
    lv_btn_set_style(wireless_sign_in_page.btn_wreless_name, LV_BTN_STYLE_REL, &wireless_sign_in_page.new_btn_style);

    lv_btn_set_style(wireless_sign_in_page.btn_wreless_password, LV_BTN_STYLE_PR, &wireless_sign_in_page.new_btn_style);
    lv_btn_set_style(wireless_sign_in_page.btn_wreless_password, LV_BTN_STYLE_REL, &wireless_sign_in_page.new_btn_style);

    lv_btn_set_style(wireless_sign_in_page.btn_back, LV_BTN_STYLE_PR, &wireless_sign_in_page.btn_pre_style);
    lv_btn_set_style(wireless_sign_in_page.btn_back, LV_BTN_STYLE_REL, &wireless_sign_in_page.btn_pre_style);


    wireless_sign_in_page.label_back_pic = lv_label_create(wireless_sign_in_page.btn_back, NULL);
    lv_label_set_text(wireless_sign_in_page.label_back_pic, FONT_PIC_BACK);
    lv_label_set_style(wireless_sign_in_page.label_back_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    wireless_sign_in_page.label_wireless_name = lv_label_create(wireless_sign_in_page.obj_wreless_name, NULL);
    lv_obj_align(wireless_sign_in_page.label_wireless_name, wireless_sign_in_page.obj_wreless_name, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_text(wireless_sign_in_page.label_wireless_name, WIFI_NAME_EN);

    wireless_sign_in_page.label_wireless_password = lv_label_create(wireless_sign_in_page.obj_wreless_password, NULL);
    lv_obj_align(wireless_sign_in_page.label_wireless_password, wireless_sign_in_page.obj_wreless_password, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_text(wireless_sign_in_page.label_wireless_password, PASSWORD_EN);

    wireless_sign_in_page.label_wireless_name_text = lv_label_create(wireless_sign_in_page.btn_wreless_name, NULL);
    lv_obj_align(wireless_sign_in_page.label_wireless_name_text, wireless_sign_in_page.btn_wreless_name, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_style(wireless_sign_in_page.label_wireless_name_text,LV_LABEL_STYLE_MAIN,&wireless_sign_in_page.new_btn_style);
    lv_label_set_text(wireless_sign_in_page.label_wireless_name_text, ABOUT_MACHINE_TYPE_EN);

    wireless_sign_in_page.label_wireless_password_text = lv_label_create(wireless_sign_in_page.btn_wreless_password, NULL);
    lv_obj_align(wireless_sign_in_page.label_wireless_password_text, wireless_sign_in_page.btn_wreless_password, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_style(wireless_sign_in_page.label_wireless_password_text,LV_LABEL_STYLE_MAIN,&wireless_sign_in_page.new_btn_style);
    lv_label_set_text(wireless_sign_in_page.label_wireless_password_text,ABOUT_AXES_EN);

    wireless_sign_in_page.label_back = lv_label_create(wireless_sign_in_page.btn_back, NULL);
    lv_obj_align(wireless_sign_in_page.label_back, wireless_sign_in_page.label_back_pic, LV_ALIGN_IN_LEFT_MID, -30, 0);
    lv_label_set_text(wireless_sign_in_page.label_back,ABOUT_BACK_EN);


}

/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_wireless_sign_in_font_pic_color(uint8_t id, bool status) {

    // switch(id) {
    //     case ID_WIRELESS_NAME: 
    //         if(status) lv_label_set_style(wireless_sign_in_page.label_ver_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(wireless_sign_in_page.label_ver_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_WIRELESS_PASSWORD: 
    //         if(status) lv_label_set_style(wireless_sign_in_page.label_fw_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(wireless_sign_in_page.label_fw_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_LANGUAGE_RU: 
    //         if(status) lv_label_set_style(wireless_sign_in_page.label_machine_type_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(wireless_sign_in_page.label_machine_type_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_LANGUAGE_DE: 
    //         if(status) lv_label_set_style(wireless_sign_in_page.label_axis_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(wireless_sign_in_page.label_axis_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    // }

}





void clean_wireless_sign_in_page(void) {

    lv_obj_clean(ui.src);
}

