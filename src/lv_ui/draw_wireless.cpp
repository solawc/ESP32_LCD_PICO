/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_wireless.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_wifi_list_t wifi_list_page;

/***************************************************************************
 *                          static function
 * - static void set_wifi_list_font_pic_color(uint8_t id, bool status) 
 * - static void draw_wifi_list_bar(void)
 * 
***************************************************************************/
static void set_wifi_list_font_pic_color(uint8_t id, bool status);
static void draw_wifi_list_bar(void);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    ID_WIFI_LIST_NUM0,
    ID_WIFI_LIST_NUM1,
    ID_WIFI_LIST_NUM2,
    ID_WIFI_LIST_NUM3,
    ID_WIFI_LIST_NUM4,
    ID_WIFI_LIST_NUM5,
    ID_WIFI_LIST_NUM6,
    ID_WIFI_LIST_NUM7,
    ID_WIFI_LIST_UP,
    ID_WIFI_LIST_NEXT,
    ID_WIFI_LIST_BACK,
};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {
   if(obj == wifi_list_page.btn_file0) return ID_WIFI_LIST_NUM0;
   else if(obj == wifi_list_page.btn_file1) return ID_WIFI_LIST_NUM1;
   else if(obj == wifi_list_page.btn_file2) return ID_WIFI_LIST_NUM2;
   else if(obj == wifi_list_page.btn_file3) return ID_WIFI_LIST_NUM3;
   else if(obj == wifi_list_page.btn_up) return ID_WIFI_LIST_UP;
   else if(obj == wifi_list_page.btn_next) return ID_WIFI_LIST_NEXT;
   else if(obj == wifi_list_page.btn_back) return ID_WIFI_LIST_BACK;
}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        
        set_wifi_list_font_pic_color(id, true);

        switch(id) {
            case ID_WIFI_LIST_NUM0: 
                
            break;

            case ID_WIFI_LIST_NUM1:
                
            break;

            case ID_WIFI_LIST_NUM2: 

            break; 
            case ID_WIFI_LIST_NUM3:
                
            break;

        }
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        set_wifi_list_font_pic_color(id, false);
        

        switch(id) {
            case ID_WIFI_LIST_NUM0: 
                clean_wifi_list_page();
                draw_wireless_sign_in();
            break;

            case ID_WIFI_LIST_NUM1:

            break;

            case ID_WIFI_LIST_NUM2: 

            break; 
            case ID_WIFI_LIST_NUM3:
                
            break;


            case ID_WIFI_LIST_BACK: 
                clean_wifi_list_page();
                draw_tool();
            break; 
            }
    }
}

static void draw_wifi_list_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 76);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

#define WIFI_LIST_CN_EN "WIFI0"
#define WIFI_LIST_EN_EN  "WIFI0"
#define WIFI_LIST_RU_EN  "WIFI0"
#define WIFI_LIST_DE_EN  "WIFI0"
#define WIFI_LIST_BACK_EN  "Back"

#define WIFI_LIST_UP_EN    "Up"
#define WIFI_LIST_NEXT_EN  "Next"
#define WIFI_LIST_REFRESH_EN  "Refresh"

void draw_wifi_list(void) {
    
    draw_wifi_list_bar();

    lv_style_copy(&wifi_list_page.btn_pre_style , &lv_style_scr);
    wifi_list_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	wifi_list_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    wifi_list_page.btn_pre_style.body.radius = 10;
    wifi_list_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&wifi_list_page.btn_rel_style , &lv_style_scr);
    wifi_list_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	wifi_list_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    wifi_list_page.btn_rel_style.body.radius = 10;
    wifi_list_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    wifi_list_page.btn_file0 =  lv_btn_set(ui.src, wifi_list_page.btn_file0, WIFI_LIST_BTN_LIST_W, WIFI_LIST_BTN_LIST_H, WIFI_LIST_BTN_LIST_X1, WIFI_LIST_BTN_LIST_Y1, event_handler);
    wifi_list_page.btn_file1 =  lv_btn_set(ui.src, wifi_list_page.btn_file1, WIFI_LIST_BTN_LIST_W, WIFI_LIST_BTN_LIST_H, WIFI_LIST_BTN_LIST_X2, WIFI_LIST_BTN_LIST_Y1, event_handler);
    wifi_list_page.btn_file2 =  lv_btn_set(ui.src, wifi_list_page.btn_file2, WIFI_LIST_BTN_LIST_W, WIFI_LIST_BTN_LIST_H, WIFI_LIST_BTN_LIST_X1, WIFI_LIST_BTN_LIST_Y2, event_handler);
    wifi_list_page.btn_file3 =  lv_btn_set(ui.src, wifi_list_page.btn_file3, WIFI_LIST_BTN_LIST_W, WIFI_LIST_BTN_LIST_H, WIFI_LIST_BTN_LIST_X2, WIFI_LIST_BTN_LIST_Y2, event_handler);
    wifi_list_page.btn_back =  lv_btn_set(ui.src, wifi_list_page.btn_back, 60, 60, WIFI_LIST_BTN_BACK_X, WIFI_LIST_BTN_BACK_Y, event_handler);
    wifi_list_page.btn_up =  lv_btn_set(ui.src, wifi_list_page.btn_back, 60, 60, WIFI_LIST_BTN_UP_X, WIFI_LIST_BTN_UP_Y, event_handler);
    wifi_list_page.btn_next =  lv_btn_set(ui.src, wifi_list_page.btn_back, 60, 60, WIFI_LIST_BTN_NEXT_X, WIFI_LIST_BTN_NEXT_Y, event_handler);
    wifi_list_page.btn_refresh =  lv_btn_set(ui.src, wifi_list_page.btn_refresh, 60, 60, WIFI_LIST_BTN_REFRESH_X, WIFI_LIST_BTN_REFRESH_Y, event_handler);

    lv_btn_set_style(wifi_list_page.btn_file0, LV_BTN_STYLE_PR, &wifi_list_page.btn_pre_style);   // 松开
    lv_btn_set_style(wifi_list_page.btn_file0, LV_BTN_STYLE_REL, &wifi_list_page.btn_rel_style);  // 按下

    lv_btn_set_style(wifi_list_page.btn_file1, LV_BTN_STYLE_PR, &wifi_list_page.btn_pre_style);
    lv_btn_set_style(wifi_list_page.btn_file1, LV_BTN_STYLE_REL, &wifi_list_page.btn_rel_style);

    lv_btn_set_style(wifi_list_page.btn_file2, LV_BTN_STYLE_PR, &wifi_list_page.btn_pre_style);
    lv_btn_set_style(wifi_list_page.btn_file2, LV_BTN_STYLE_REL, &wifi_list_page.btn_rel_style);

    lv_btn_set_style(wifi_list_page.btn_file3, LV_BTN_STYLE_PR, &wifi_list_page.btn_pre_style);
    lv_btn_set_style(wifi_list_page.btn_file3, LV_BTN_STYLE_REL, &wifi_list_page.btn_rel_style);


    lv_btn_set_style(wifi_list_page.btn_back, LV_BTN_STYLE_PR, &wifi_list_page.btn_pre_style);
    lv_btn_set_style(wifi_list_page.btn_back, LV_BTN_STYLE_REL, &wifi_list_page.btn_pre_style);

    lv_btn_set_style(wifi_list_page.btn_up, LV_BTN_STYLE_PR, &wifi_list_page.btn_pre_style);
    lv_btn_set_style(wifi_list_page.btn_up, LV_BTN_STYLE_REL, &wifi_list_page.btn_pre_style);

    lv_btn_set_style(wifi_list_page.btn_next, LV_BTN_STYLE_PR, &wifi_list_page.btn_pre_style);
    lv_btn_set_style(wifi_list_page.btn_next, LV_BTN_STYLE_REL, &wifi_list_page.btn_pre_style);

    lv_btn_set_style(wifi_list_page.btn_refresh, LV_BTN_STYLE_PR, &wifi_list_page.btn_pre_style);
    lv_btn_set_style(wifi_list_page.btn_refresh, LV_BTN_STYLE_REL, &wifi_list_page.btn_pre_style);

    wifi_list_page.label_back_pic = lv_label_create(wifi_list_page.btn_back, NULL);
    lv_label_set_text(wifi_list_page.label_back_pic, FONT_PIC_BACK);
    lv_label_set_style(wifi_list_page.label_back_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    wifi_list_page.label_up_pic = lv_label_create(wifi_list_page.btn_up, NULL);
    lv_label_set_text(wifi_list_page.label_up_pic, FONT_PIC_UP);
    lv_label_set_style(wifi_list_page.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    wifi_list_page.label_next_pic = lv_label_create(wifi_list_page.btn_next, NULL);
    lv_label_set_text(wifi_list_page.label_next_pic, FONT_PIC_NEXT);
    lv_label_set_style(wifi_list_page.label_next_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    wifi_list_page.label_refresh_pic= lv_label_create(wifi_list_page.btn_refresh, NULL);
    lv_label_set_text(wifi_list_page.label_refresh_pic, FONT_PIC_REFRESH);
    lv_label_set_style(wifi_list_page.label_refresh_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    wifi_list_page.label_file0 = lv_label_create(wifi_list_page.btn_file0, NULL);
    // lv_obj_align(wifi_list_page.label_file0, wifi_list_page.label_file0_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(wifi_list_page.label_file0, WIFI_LIST_CN_EN);

    wifi_list_page.label_file1 = lv_label_create(wifi_list_page.btn_file1, NULL);
    // lv_obj_align(wifi_list_page.label_file1, wifi_list_page.label_file0_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(wifi_list_page.label_file1, WIFI_LIST_EN_EN);

    wifi_list_page.label_file2 = lv_label_create(wifi_list_page.btn_file2, NULL);
    // lv_obj_align(wifi_list_page.label_file2, wifi_list_page.label_file0_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(wifi_list_page.label_file2, WIFI_LIST_RU_EN);

    wifi_list_page.label_file3 = lv_label_create(wifi_list_page.btn_file3, NULL);
    // lv_obj_align(wifi_list_page.label_file3, wifi_list_page.label_file0_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(wifi_list_page.label_file3,WIFI_LIST_DE_EN);

    wifi_list_page.label_back = lv_label_create(wifi_list_page.btn_back, NULL);
    lv_obj_align(wifi_list_page.label_back, wifi_list_page.label_back_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(wifi_list_page.label_back,WIFI_LIST_BACK_EN);

    wifi_list_page.label_up = lv_label_create(wifi_list_page.btn_up, NULL);
    lv_obj_align(wifi_list_page.label_up, wifi_list_page.label_up_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(wifi_list_page.label_up,WIFI_LIST_UP_EN);

    wifi_list_page.label_next = lv_label_create(wifi_list_page.btn_next, NULL);
    lv_obj_align(wifi_list_page.label_next, wifi_list_page.label_next_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(wifi_list_page.label_next,WIFI_LIST_NEXT_EN);

    wifi_list_page.label_refresh = lv_label_create(wifi_list_page.btn_refresh, NULL);
    lv_obj_align(wifi_list_page.label_refresh, wifi_list_page.label_refresh_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(wifi_list_page.label_refresh,WIFI_LIST_REFRESH_EN);

}

/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_wifi_list_font_pic_color(uint8_t id, bool status) {

    // switch(id) {
    //     case ID_WIFI_LIST_NUM0: 
    //         if(status) lv_label_set_style(wifi_list_page.label_file0_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
    //         else lv_label_set_style(wifi_list_page.label_file0_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    //     break;
    //     case ID_WIFI_LIST_NUM1: 
    //         if(status) lv_label_set_style(wifi_list_page.label_file1_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
    //         else lv_label_set_style(wifi_list_page.label_file1_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    //     break;
    //     case ID_WIFI_LIST_NUM2: 
    //         if(status) lv_label_set_style(wifi_list_page.label_file2_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
    //         else lv_label_set_style(wifi_list_page.label_file2_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    //     break;
    //     case ID_WIFI_LIST_NUM3: 
    //         if(status) lv_label_set_style(wifi_list_page.label_file3_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
    //         else lv_label_set_style(wifi_list_page.label_file3_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    //     break;
    // }

}





void clean_wifi_list_page(void) {

    lv_obj_clean(ui.src);
}

