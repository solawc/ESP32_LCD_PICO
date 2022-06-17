/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_tool.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_tool_t tool_page;

/***************************************************************************
 *                          static function
 * - static void set_tool_font_pic_color(uint8_t id, bool status) 
 * - static void draw_tool_bar(void)
 * 
***************************************************************************/
static void set_tool_font_pic_color(uint8_t id, bool status);
static void draw_tool_bar(void);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    ID_TOOL_LANGUAGE,
    ID_TOOL_STYLE,
    ID_TOOL_SOUND,
    ID_TOOL_WIRELESS,
    ID_TOOL_CONSOLE,
    ID_TOOL_BACK,
    ID_TOOL_ABOUT,
};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {
   if(obj == tool_page.btn_language) return ID_TOOL_LANGUAGE;
   else if(obj == tool_page.btn_style) return ID_TOOL_STYLE;
   else if(obj == tool_page.btn_sound) return ID_TOOL_SOUND;
   else if(obj == tool_page.btn_wifi) return ID_TOOL_WIRELESS;
   else if(obj == tool_page.btn_console) return ID_TOOL_CONSOLE;
   else if(obj == tool_page.btn_back) return ID_TOOL_BACK;
   else if(obj == tool_page.btn_about) return ID_TOOL_ABOUT;
}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        
        set_tool_font_pic_color(id, true);

        switch(id) {
            case ID_TOOL_LANGUAGE: 
                
            break;

            case ID_TOOL_STYLE:
                
            break;

            case ID_TOOL_SOUND: 

            break; 
            case ID_TOOL_WIRELESS:
                
            break;

            case ID_TOOL_CONSOLE: 

            break; 
        }
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        set_tool_font_pic_color(id, false);
        

        switch(id) {
            case ID_TOOL_LANGUAGE: 
                clean_tool_page();
                draw_language();
            break;

            case ID_TOOL_STYLE:
                clean_tool_page();
                draw_style();
            break;
            case ID_TOOL_ABOUT: 
                clean_tool_page();
                draw_about();
            break; 
            case ID_TOOL_SOUND: 

            break; 
            case ID_TOOL_WIRELESS:
                clean_tool_page();
                draw_wifi_list();
            break;

            case ID_TOOL_CONSOLE: 
                clean_tool_page();
                draw_init_set_Initialize();
            break; 
            case ID_TOOL_BACK: 
                clean_tool_page();
                draw_home();
            break; 
            }
    }
}

static void draw_tool_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 76);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

#define TOOL_LANGUAGE_EN "Language"
#define TOOL_STYLE_EN  "Style"
#define TOOL_SOUND_EN  "Sound"
#define TOOL_WIRELESS_EN  "Wireless"
#define TOOL_CONSOLE_EN "Console"
#define TOOL_BACK_EN  "Back"
#define TOOL_ABOUT_EN "About"


void draw_tool(void) {
    
    draw_tool_bar();

    lv_style_copy(&tool_page.btn_pre_style , &lv_style_scr);
    tool_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	tool_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    tool_page.btn_pre_style.body.radius = 10;
    tool_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&tool_page.btn_rel_style , &lv_style_scr);
    tool_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	tool_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    tool_page.btn_rel_style.body.radius = 10;
    tool_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    tool_page.btn_language =  lv_btn_set(ui.src, tool_page.btn_language, 110, 110, TOOL_BTN_LIST_X1, TOOL_BTN_LIST_Y1, event_handler);
    tool_page.btn_style =  lv_btn_set(ui.src, tool_page.btn_style, 110, 110, TOOL_BTN_LIST_X2, TOOL_BTN_LIST_Y1, event_handler);
    tool_page.btn_sound =  lv_btn_set(ui.src, tool_page.btn_sound, 110, 110, TOOL_BTN_LIST_X3, TOOL_BTN_LIST_Y1, event_handler);
    tool_page.btn_wifi =  lv_btn_set(ui.src, tool_page.btn_wifi, 110, 110, TOOL_BTN_LIST_X4, TOOL_BTN_LIST_Y1, event_handler);
    tool_page.btn_console =  lv_btn_set(ui.src, tool_page.btn_console, 110, 110, TOOL_BTN_LIST_X1, TOOL_BTN_LIST_Y2, event_handler);
    tool_page.btn_back =  lv_btn_set(ui.src, tool_page.btn_back, 60, 60, TOOL_BTN_BACK_X, TOOL_BTN_BACK_Y, event_handler);
    tool_page.btn_about =  lv_btn_set(ui.src, tool_page.btn_about, 60, 60, TOOL_BTN_ABOUT_X, TOOL_BTN_ABOUT_Y, event_handler);

    lv_btn_set_style(tool_page.btn_language, LV_BTN_STYLE_PR, &tool_page.btn_pre_style);   // 按下
    lv_btn_set_style(tool_page.btn_language, LV_BTN_STYLE_REL, &tool_page.btn_rel_style);  // 松开

    lv_btn_set_style(tool_page.btn_style, LV_BTN_STYLE_PR, &tool_page.btn_pre_style);
    lv_btn_set_style(tool_page.btn_style, LV_BTN_STYLE_REL, &tool_page.btn_rel_style);

    lv_btn_set_style(tool_page.btn_sound, LV_BTN_STYLE_PR, &tool_page.btn_pre_style);
    lv_btn_set_style(tool_page.btn_sound, LV_BTN_STYLE_REL, &tool_page.btn_rel_style);

    lv_btn_set_style(tool_page.btn_wifi, LV_BTN_STYLE_PR, &tool_page.btn_pre_style);
    lv_btn_set_style(tool_page.btn_wifi, LV_BTN_STYLE_REL, &tool_page.btn_rel_style);

    lv_btn_set_style(tool_page.btn_console, LV_BTN_STYLE_PR, &tool_page.btn_pre_style);
    lv_btn_set_style(tool_page.btn_console, LV_BTN_STYLE_REL, &tool_page.btn_rel_style);

    lv_btn_set_style(tool_page.btn_back, LV_BTN_STYLE_PR, &tool_page.btn_pre_style);
    lv_btn_set_style(tool_page.btn_back, LV_BTN_STYLE_REL, &tool_page.btn_pre_style);

    lv_btn_set_style(tool_page.btn_about, LV_BTN_STYLE_PR, &tool_page.btn_pre_style);
    lv_btn_set_style(tool_page.btn_about, LV_BTN_STYLE_REL, &tool_page.btn_pre_style);

    tool_page.label_language_pic = lv_label_create(tool_page.btn_language, NULL);
    lv_label_set_text(tool_page.label_language_pic, FONT_PIC_LANGUAGE);
    lv_label_set_style(tool_page.label_language_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);

    tool_page.label_style_pic = lv_label_create(tool_page.btn_style, NULL);
    lv_label_set_text(tool_page.label_style_pic, FONT_STYLE);
    lv_label_set_style(tool_page.label_style_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    
    tool_page.label_sound_pic = lv_label_create(tool_page.btn_sound, NULL);
    lv_label_set_text(tool_page.label_sound_pic, FONT_PIC_SOUND);
    lv_label_set_style(tool_page.label_sound_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);

    tool_page.label_wifi_pic = lv_label_create(tool_page.btn_wifi, NULL);
    lv_label_set_text(tool_page.label_wifi_pic, FONT_WIRELESS);
    lv_label_set_style(tool_page.label_wifi_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);

    tool_page.label_console_pic = lv_label_create(tool_page.btn_console, NULL);
    lv_label_set_text(tool_page.label_console_pic, FONT_PIC_CONSOLE);
    lv_label_set_style(tool_page.label_console_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);

    tool_page.label_back_pic = lv_label_create(tool_page.btn_back, NULL);
    lv_label_set_text(tool_page.label_back_pic, FONT_PIC_BACK);
    lv_label_set_style(tool_page.label_back_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    tool_page.label_about_pic = lv_label_create(tool_page.btn_about, NULL);
    lv_label_set_text(tool_page.label_about_pic, FONT_PIC_ABOUT);
    lv_label_set_style(tool_page.label_about_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);


    tool_page.label_language = lv_label_create(tool_page.btn_language, NULL);
    lv_obj_align(tool_page.label_language, tool_page.label_language_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(tool_page.label_language, TOOL_LANGUAGE_EN);

    tool_page.label_style = lv_label_create(tool_page.btn_style, NULL);
    lv_obj_align(tool_page.label_style, tool_page.label_language_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(tool_page.label_style, TOOL_STYLE_EN);

    tool_page.label_sound = lv_label_create(tool_page.btn_sound, NULL);
    lv_obj_align(tool_page.label_sound, tool_page.label_language_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(tool_page.label_sound, TOOL_SOUND_EN);

    tool_page.label_wifi = lv_label_create(tool_page.btn_wifi, NULL);
    lv_obj_align(tool_page.label_wifi, tool_page.label_language_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(tool_page.label_wifi,TOOL_WIRELESS_EN);

    tool_page.label_console = lv_label_create(tool_page.btn_console, NULL);
    lv_obj_align(tool_page.label_console, tool_page.label_language_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(tool_page.label_console,TOOL_CONSOLE_EN);

    tool_page.label_back = lv_label_create(tool_page.btn_back, NULL);
    lv_obj_align(tool_page.label_back, tool_page.label_back_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(tool_page.label_back,TOOL_BACK_EN);

    tool_page.label_about = lv_label_create(tool_page.btn_about, NULL);
    lv_obj_align(tool_page.label_about, tool_page.label_about_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(tool_page.label_about,TOOL_ABOUT_EN);
}

/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_tool_font_pic_color(uint8_t id, bool status) {

    switch(id) {
        case ID_TOOL_LANGUAGE: 
            if(status) lv_label_set_style(tool_page.label_language_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
            else lv_label_set_style(tool_page.label_language_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        break;
        case ID_TOOL_STYLE: 
            if(status) lv_label_set_style(tool_page.label_style_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
            else lv_label_set_style(tool_page.label_style_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        break;
        case ID_TOOL_SOUND: 
            if(status) lv_label_set_style(tool_page.label_sound_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
            else lv_label_set_style(tool_page.label_sound_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        break;
        case ID_TOOL_WIRELESS: 
            if(status) lv_label_set_style(tool_page.label_wifi_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
            else lv_label_set_style(tool_page.label_wifi_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        break;
        case ID_TOOL_CONSOLE: 
            if(status) lv_label_set_style(tool_page.label_console_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
            else lv_label_set_style(tool_page.label_console_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        break;
    }

}





void clean_tool_page(void) {

    lv_obj_clean(ui.src);
}

