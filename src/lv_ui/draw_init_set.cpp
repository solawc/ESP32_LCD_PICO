/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_init_set.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_init_set_t init_set_page;

/***************************************************************************
 *                          static function
 * - static void set_init_set_font_pic_color(uint8_t id, bool status) 
 * - static void draw_init_set_bar(void)
 * 
***************************************************************************/
static void set_init_set_font_pic_color(uint8_t id, bool status);
static void draw_init_set_bar(void);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    ID_INIT_SET_CANCEL,
    ID_INIT_SET_FINISH,
    ID_INIT_SET_NEXT,
};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {
   if(obj == init_set_page.btn_cancel) return ID_INIT_SET_CANCEL;
   else if(obj == init_set_page.btn_finish) return ID_INIT_SET_FINISH;
   else if(obj == init_set_page.btn_next) return ID_INIT_SET_NEXT;

}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        
        set_init_set_font_pic_color(id, true);

        switch(id) {
            case ID_INIT_SET_CANCEL: 
                
            break;

            case ID_INIT_SET_FINISH:
                
            break;

            case ID_INIT_SET_NEXT: 

            break; 


        }
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        set_init_set_font_pic_color(id, false);
        

        switch(id) {
            case ID_INIT_SET_CANCEL: 
                clean_init_set_page();
                draw_tool();
            break;

            case ID_INIT_SET_FINISH:
                clean_init_set_page();
                draw_tool();
            break;

            case ID_INIT_SET_NEXT: 
                clean_init_set_page();
                draw_set_config();
            break; 
            }
    }
}

static void draw_init_set_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 76);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

#define INIT_SET_CANCEL_EN "Cancel"
#define INIT_SET_FINISH_EN  "Finish"
#define INIT_SET_NEXT_EN  "Next"

#define INIT_SET_COM_EN  "Setup is complete"
#define INIT_SET_INIT_EN  "Initialize settings"

void draw_init_set_complete(void) {
    
    // draw_init_set_bar();

    lv_style_copy(&init_set_page.btn_pre_style , &lv_style_scr);
    init_set_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	init_set_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    init_set_page.btn_pre_style.body.radius = 10;
    init_set_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&init_set_page.btn_rel_style , &lv_style_scr);
    init_set_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	init_set_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    init_set_page.btn_rel_style.body.radius = 10;
    init_set_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    init_set_page.btn_cancel =  lv_btn_set(ui.src, init_set_page.btn_cancel, INIT_SET_BTN_W, INIT_SET_BTN_H, INIT_SET_BTN_X1, INIT_SET_BTN_Y, event_handler);
    init_set_page.btn_finish =  lv_btn_set(ui.src, init_set_page.btn_finish, INIT_SET_BTN_W, INIT_SET_BTN_H, INIT_SET_BTN_X2, INIT_SET_BTN_Y, event_handler);


    lv_btn_set_style(init_set_page.btn_cancel, LV_BTN_STYLE_PR, &init_set_page.btn_pre_style);   // 松开
    lv_btn_set_style(init_set_page.btn_cancel, LV_BTN_STYLE_REL, &init_set_page.btn_rel_style);  // 按下

    lv_btn_set_style(init_set_page.btn_finish, LV_BTN_STYLE_PR, &init_set_page.btn_pre_style);
    lv_btn_set_style(init_set_page.btn_finish, LV_BTN_STYLE_REL, &init_set_page.btn_rel_style);


    init_set_page.label_text = lv_label_create(ui.src, NULL);
    lv_obj_align(init_set_page.label_text,ui.src,LV_ALIGN_CENTER,0,0);
    lv_label_set_text(init_set_page.label_text, INIT_SET_COM_EN);

    init_set_page.label_cancel = lv_label_create(init_set_page.btn_cancel, NULL);
    lv_label_set_text(init_set_page.label_cancel, INIT_SET_CANCEL_EN);

    init_set_page.label_finish = lv_label_create(init_set_page.btn_finish, NULL);
    lv_label_set_text(init_set_page.label_finish, INIT_SET_FINISH_EN);

}
void draw_init_set_Initialize(void) {
    
    // draw_init_set_bar();

    lv_style_copy(&init_set_page.btn_pre_style , &lv_style_scr);
    init_set_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	init_set_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    init_set_page.btn_pre_style.body.radius = 10;
    init_set_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&init_set_page.btn_rel_style , &lv_style_scr);
    init_set_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	init_set_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    init_set_page.btn_rel_style.body.radius = 10;
    init_set_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    init_set_page.btn_cancel =  lv_btn_set(ui.src, init_set_page.btn_cancel, INIT_SET_BTN_W, INIT_SET_BTN_H, INIT_SET_BTN_X1, INIT_SET_BTN_Y, event_handler);
    init_set_page.btn_next =  lv_btn_set(ui.src, init_set_page.btn_next, INIT_SET_BTN_W, INIT_SET_BTN_H, INIT_SET_BTN_X2, INIT_SET_BTN_Y, event_handler);


    lv_btn_set_style(init_set_page.btn_cancel, LV_BTN_STYLE_PR, &init_set_page.btn_pre_style);   // 松开
    lv_btn_set_style(init_set_page.btn_cancel, LV_BTN_STYLE_REL, &init_set_page.btn_rel_style);  // 按下

    lv_btn_set_style(init_set_page.btn_next, LV_BTN_STYLE_PR, &init_set_page.btn_pre_style);
    lv_btn_set_style(init_set_page.btn_next, LV_BTN_STYLE_REL, &init_set_page.btn_rel_style);

    init_set_page.label_text = lv_label_create(ui.src, NULL);
    lv_obj_align(init_set_page.label_text,ui.src,LV_ALIGN_CENTER,0,0);
    lv_label_set_text(init_set_page.label_text, INIT_SET_INIT_EN);


    init_set_page.label_cancel = lv_label_create(init_set_page.btn_cancel, NULL);
    lv_label_set_text(init_set_page.label_cancel, INIT_SET_CANCEL_EN);

    init_set_page.label_next = lv_label_create(init_set_page.btn_next, NULL);
    lv_label_set_text(init_set_page.label_next, INIT_SET_NEXT_EN);

}
/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_init_set_font_pic_color(uint8_t id, bool status) {

    // switch(id) {
    //     case ID_INIT_SET_CANCEL: 
    //         if(status) lv_label_set_style(init_set_page.label_cancel_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(init_set_page.label_cancel_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_INIT_SET_FINISH: 
    //         if(status) lv_label_set_style(init_set_page.label_finish_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(init_set_page.label_finish_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_INIT_SET_NEXT: 
    //         if(status) lv_label_set_style(init_set_page.label_ru_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(init_set_page.label_ru_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_LANGUAGE_DE: 
    //         if(status) lv_label_set_style(init_set_page.label_de_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(init_set_page.label_de_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    // }

}





void clean_init_set_page(void) {

    lv_obj_clean(ui.src);
}

