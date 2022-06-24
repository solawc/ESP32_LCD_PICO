


/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_keyboard.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_keyboard_t keyboard_page;

/***************************************************************************
 *                          static function
 * - static void set_keyboard_font_pic_color(uint8_t id, bool status) 
 * - static void draw_keyboard_bar(void)
 * 
***************************************************************************/
static void set_keyboard_font_pic_color(uint8_t id, bool status);
static void draw_keyboard_bar(void);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    // ID_TOOL_LANGUAGE,
    // ID_TOOL_STYLE,
    // ID_TOOL_SOUND,
    // ID_TOOL_WIRELESS,
    // ID_TOOL_CONSOLE,
    // ID_TOOL_BACK,
    // ID_TOOL_ABOUT,
};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {
//    if(obj == keyboard_page.btn_language) return ID_TOOL_LANGUAGE;
//    else if(obj == keyboard_page.btn_style) return ID_TOOL_STYLE;
//    else if(obj == keyboard_page.btn_sound) return ID_TOOL_SOUND;
//    else if(obj == keyboard_page.btn_wifi) return ID_TOOL_WIRELESS;
//    else if(obj == keyboard_page.btn_console) return ID_TOOL_CONSOLE;
//    else if(obj == keyboard_page.btn_back) return ID_TOOL_BACK;
//    else if(obj == keyboard_page.btn_about) return ID_TOOL_ABOUT;
}


static void event_handler_kb_event(lv_obj_t* obj, lv_event_t event) {

    lv_kb_def_event_cb(obj, event);

    // uint8_t id = get_event(obj);

    // if(event == LV_EVENT_PRESSED) {
        
    //     set_keyboard_font_pic_color(id, true);

    //     switch(id) {
    //         case ID_TOOL_LANGUAGE: 
                
    //         break;

    //         case ID_TOOL_STYLE:
                
    //         break;

    //         case ID_TOOL_SOUND: 

    //         break; 
    //         case ID_TOOL_WIRELESS:
                
    //         break;

    //         case ID_TOOL_CONSOLE: 

    //         break; 
    //     }
    // }

    // if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

    //     set_keyboard_font_pic_color(id, false);
        

    //     switch(id) {
    //         case ID_TOOL_LANGUAGE: 
    //             clean_keyboard_page();
    //             draw_language();
    //         break;

    //         case ID_TOOL_STYLE:
    //             clean_keyboard_page();
    //             draw_style();
    //         break;
    //         case ID_TOOL_ABOUT: 
    //             clean_keyboard_page();
    //             draw_about();
    //         break; 
    //         case ID_TOOL_SOUND: 

    //         break; 
    //         case ID_TOOL_WIRELESS:
    //             clean_keyboard_page();
    //             draw_wifi_list();
    //         break;

    //         case ID_TOOL_CONSOLE: 
    //             clean_keyboard_page();
    //             draw_init_set_Initialize();
    //         break; 
    //         case ID_TOOL_BACK: 
    //             clean_keyboard_page();
    //             draw_home();
    //         break; 
    //         }
    // }
}


#define TOOL_LANGUAGE_EN "Language"
#define TOOL_STYLE_EN  "Style"
#define TOOL_SOUND_EN  "Sound"
#define TOOL_WIRELESS_EN  "Wireless"
#define TOOL_CONSOLE_EN "Console"
#define TOOL_BACK_EN  "Back"
#define TOOL_ABOUT_EN "About"


void draw_keyboard(void) {
    


    lv_style_copy(&keyboard_page.ta_bg_style , &ui.src_1_style);
    // keyboard_page.ta_bg_style.body.grad_color = lv_color_hex(get_current_color());;
	// keyboard_page.ta_bg_style.body.main_color = lv_color_hex(get_current_color());;
    keyboard_page.ta_bg_style.body.radius = 8;
    keyboard_page.ta_bg_style.text.color = LV_COLOR_WHITE;
    keyboard_page.ta_bg_style.body.border.color = lv_color_hex(get_current_color());;
    keyboard_page.ta_bg_style.body.border.width = 1;
    keyboard_page.ta_bg_style.body.main_color = lv_color_hex(0X1A1A1A);
    keyboard_page.ta_bg_style.body.grad_color = lv_color_hex(0X1A1A1A);

    lv_style_copy(&keyboard_page.kb_rel_style , &lv_style_scr);
    keyboard_page.kb_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	keyboard_page.kb_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    keyboard_page.kb_rel_style.text.color = lv_color_hex(get_current_color());

    lv_style_copy(&keyboard_page.kb_pr_style , &lv_style_scr);
    keyboard_page.kb_pr_style.body.grad_color = lv_color_hex(get_current_color());
	keyboard_page.kb_pr_style.body.main_color = lv_color_hex(get_current_color());
    keyboard_page.kb_pr_style.body.border.color = lv_color_hex(get_current_color());
    keyboard_page.kb_pr_style.body.border.width = 1;
    keyboard_page.kb_pr_style.text.color = lv_color_hex(get_current_color());

    lv_style_copy(&keyboard_page.kb_bg_style, &lv_style_pretty);
    keyboard_page.kb_bg_style.body.main_color = lv_color_hex(0X1A1A1A);
    keyboard_page.kb_bg_style.body.grad_color = lv_color_hex(0X1A1A1A);
    keyboard_page.kb_bg_style.body.border.width = 0;
    keyboard_page.kb_bg_style.body.radius = 0;
    keyboard_page.kb_bg_style.body.padding.inner = 2;
    keyboard_page.kb_bg_style.body.padding.left   = 1;
    keyboard_page.kb_bg_style.body.padding.right  = 1;
    keyboard_page.kb_bg_style.body.padding.top    = 1;
    keyboard_page.kb_bg_style.body.padding.bottom = 1;
    // lv_style_transp.glass             = 1;
    lv_style_transp.body.border.width = 0;
    
    keyboard_page.kb = lv_kb_create(ui.src, NULL);
    lv_kb_set_cursor_manage(keyboard_page.kb, true);
    lv_kb_set_style(keyboard_page.kb, LV_KB_STYLE_BG, &keyboard_page.kb_bg_style);
    lv_kb_set_style(keyboard_page.kb, LV_KB_STYLE_BTN_REL, &keyboard_page.kb_rel_style);
    lv_kb_set_style(keyboard_page.kb, LV_KB_STYLE_BTN_PR, &keyboard_page.kb_pr_style);
    lv_obj_set_event_cb(keyboard_page.kb, event_handler_kb_event);

    lv_obj_set_size(keyboard_page.kb,KEYBOARD_KB_W,KEYBOARD_KB_H);
    lv_obj_set_pos(keyboard_page.kb,KEYBOARD_KB_X,KEYBOARD_KB_Y);

    keyboard_page.ta = lv_ta_create(ui.src, NULL); 
    lv_obj_set_pos(keyboard_page.ta, KEYBOARD_TA_X, KEYBOARD_TA_Y);
    lv_obj_set_size(keyboard_page.ta, KEYBOARD_TA_W, KEYBOARD_TA_H);
    lv_ta_set_text(keyboard_page.ta, "");
    lv_kb_set_ta(keyboard_page.kb, keyboard_page.ta);
    lv_ta_set_style(keyboard_page.ta,LV_TA_STYLE_BG,&keyboard_page.ta_bg_style);
    // lv_ta_set_cursor_pos(keyboard_page.ta,10);
    // lv_ta_set_cursor_type(keyboard_page.ta,LV_CURSOR_OUTLINE);
    // lv_ta_cursor_down(keyboard_page.ta);
    // lv_style_copy(&keyboard_page.btn_rel_style , &lv_style_scr);
    // keyboard_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	// keyboard_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    // keyboard_page.btn_rel_style.body.radius = 10;
    // keyboard_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  


}
/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_keyboard_font_pic_color(uint8_t id, bool status) {

    switch(id) {
        // case ID_TOOL_LANGUAGE: 
        //     if(status) lv_label_set_style(keyboard_page.label_language_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
        //     else lv_label_set_style(keyboard_page.label_language_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        // break;
        // case ID_TOOL_STYLE: 
        //     if(status) lv_label_set_style(keyboard_page.label_style_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
        //     else lv_label_set_style(keyboard_page.label_style_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        // break;
        // case ID_TOOL_SOUND: 
        //     if(status) lv_label_set_style(keyboard_page.label_sound_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
        //     else lv_label_set_style(keyboard_page.label_sound_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        // break;
        // case ID_TOOL_WIRELESS: 
        //     if(status) lv_label_set_style(keyboard_page.label_wifi_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
        //     else lv_label_set_style(keyboard_page.label_wifi_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        // break;
        // case ID_TOOL_CONSOLE: 
        //     if(status) lv_label_set_style(keyboard_page.label_console_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
        //     else lv_label_set_style(keyboard_page.label_console_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        // break;
    }

}





void clean_keyboard_page(void) {

    lv_obj_clean(ui.src);
}

