/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_language.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_language_t language_page;

/***************************************************************************
 *                          static function
 * - static void set_language_font_pic_color(uint8_t id, bool status) 
 * - static void draw_language_bar(void)
 * 
***************************************************************************/
static void set_language_font_pic_color(uint8_t id, bool status);
static void draw_language_bar(void);

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
   if(obj == language_page.btn_cn) return ID_LANGUAGE_CN;
   else if(obj == language_page.btn_en) return ID_LANGUAGE_EN;
   else if(obj == language_page.btn_ru) return ID_LANGUAGE_RU;
   else if(obj == language_page.btn_de) return ID_LANGUAGE_DE;
   else if(obj == language_page.btn_back) return ID_LANGUAGE_BACK;
}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        
        set_language_font_pic_color(id, true);

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

        set_language_font_pic_color(id, false);
        

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
                clean_language_page();
                draw_tool();
            break; 
            }
    }
}

static void draw_language_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 76);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

#define LANGUAGE_CN_EN "简体中文"
#define LANGUAGE_EN_EN  "English"
#define LANGUAGE_RU_EN  "русский\nязык"
#define LANGUAGE_DE_EN  "Deutsch"
#define LANGUAGE_BACK_EN  "Back"



void draw_language(void) {
    
    draw_language_bar();

    lv_style_copy(&language_page.btn_pre_style , &lv_style_scr);
    language_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	language_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    language_page.btn_pre_style.body.radius = 10;
    language_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&language_page.btn_rel_style , &lv_style_scr);
    language_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	language_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    language_page.btn_rel_style.body.radius = 10;
    language_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    language_page.btn_cn =  lv_btn_set(ui.src, language_page.btn_cn, 110, 110, LANGUAGE_BTN_LIST_X1, LANGUAGE_BTN_LIST_Y1, event_handler);
    language_page.btn_en =  lv_btn_set(ui.src, language_page.btn_en, 110, 110, LANGUAGE_BTN_LIST_X2, LANGUAGE_BTN_LIST_Y1, event_handler);
    language_page.btn_ru =  lv_btn_set(ui.src, language_page.btn_ru, 110, 110, LANGUAGE_BTN_LIST_X3, LANGUAGE_BTN_LIST_Y1, event_handler);
    language_page.btn_de =  lv_btn_set(ui.src, language_page.btn_de, 110, 110, LANGUAGE_BTN_LIST_X4, LANGUAGE_BTN_LIST_Y1, event_handler);
    language_page.btn_back =  lv_btn_set(ui.src, language_page.btn_back, 60, 60, LANGUAGE_BTN_BACK_X, LANGUAGE_BTN_BACK_Y, event_handler);

    lv_btn_set_style(language_page.btn_cn, LV_BTN_STYLE_PR, &language_page.btn_pre_style);   // 松开
    lv_btn_set_style(language_page.btn_cn, LV_BTN_STYLE_REL, &language_page.btn_rel_style);  // 按下

    lv_btn_set_style(language_page.btn_en, LV_BTN_STYLE_PR, &language_page.btn_pre_style);
    lv_btn_set_style(language_page.btn_en, LV_BTN_STYLE_REL, &language_page.btn_rel_style);

    lv_btn_set_style(language_page.btn_ru, LV_BTN_STYLE_PR, &language_page.btn_pre_style);
    lv_btn_set_style(language_page.btn_ru, LV_BTN_STYLE_REL, &language_page.btn_rel_style);

    lv_btn_set_style(language_page.btn_de, LV_BTN_STYLE_PR, &language_page.btn_pre_style);
    lv_btn_set_style(language_page.btn_de, LV_BTN_STYLE_REL, &language_page.btn_rel_style);


    lv_btn_set_style(language_page.btn_back, LV_BTN_STYLE_PR, &language_page.btn_pre_style);
    lv_btn_set_style(language_page.btn_back, LV_BTN_STYLE_REL, &language_page.btn_pre_style);


    language_page.label_cn_pic = lv_label_create(language_page.btn_cn, NULL);
    lv_label_set_text(language_page.label_cn_pic, FONT_PIC_LANGUAGE);
    lv_label_set_style(language_page.label_cn_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);

    language_page.label_en_pic = lv_label_create(language_page.btn_en, NULL);
    lv_label_set_text(language_page.label_en_pic, FONT_STYLE);
    lv_label_set_style(language_page.label_en_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    
    language_page.label_ru_pic = lv_label_create(language_page.btn_ru, NULL);
    lv_label_set_text(language_page.label_ru_pic, FONT_PIC_SOUND);
    lv_label_set_style(language_page.label_ru_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);

    language_page.label_de_pic = lv_label_create(language_page.btn_de, NULL);
    lv_label_set_text(language_page.label_de_pic, FONT_WIRELESS);
    lv_label_set_style(language_page.label_de_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);

    language_page.label_back_pic = lv_label_create(language_page.btn_back, NULL);
    lv_label_set_text(language_page.label_back_pic, FONT_PIC_BACK);
    lv_label_set_style(language_page.label_back_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);




    language_page.label_cn = lv_label_create(language_page.btn_cn, NULL);
    lv_obj_align(language_page.label_cn, language_page.label_cn_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(language_page.label_cn, LANGUAGE_CN_EN);

    language_page.label_en = lv_label_create(language_page.btn_en, NULL);
    lv_obj_align(language_page.label_en, language_page.label_cn_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(language_page.label_en, LANGUAGE_EN_EN);

    language_page.label_ru = lv_label_create(language_page.btn_ru, NULL);
    lv_obj_align(language_page.label_ru, language_page.label_cn_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(language_page.label_ru, LANGUAGE_RU_EN);

    language_page.label_de = lv_label_create(language_page.btn_de, NULL);
    lv_obj_align(language_page.label_de, language_page.label_cn_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(language_page.label_de,LANGUAGE_DE_EN);

    language_page.label_back = lv_label_create(language_page.btn_back, NULL);
    lv_obj_align(language_page.label_back, language_page.label_back_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(language_page.label_back,LANGUAGE_BACK_EN);


}

/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_language_font_pic_color(uint8_t id, bool status) {

    switch(id) {
        case ID_LANGUAGE_CN: 
            if(status) lv_label_set_style(language_page.label_cn_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
            else lv_label_set_style(language_page.label_cn_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        break;
        case ID_LANGUAGE_EN: 
            if(status) lv_label_set_style(language_page.label_en_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
            else lv_label_set_style(language_page.label_en_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        break;
        case ID_LANGUAGE_RU: 
            if(status) lv_label_set_style(language_page.label_ru_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
            else lv_label_set_style(language_page.label_ru_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        break;
        case ID_LANGUAGE_DE: 
            if(status) lv_label_set_style(language_page.label_de_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
            else lv_label_set_style(language_page.label_de_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
        break;
    }

}





void clean_language_page(void) {

    lv_obj_clean(ui.src);
}

