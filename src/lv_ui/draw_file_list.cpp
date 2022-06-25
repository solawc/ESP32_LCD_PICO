/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_file_list.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_file_list_t file_list_page;

/***************************************************************************
 *                          static function
 * - static void set_file_list_font_pic_color(uint8_t id, bool status) 
 * - static void draw_file_list_bar(void)
 * 
***************************************************************************/
static void set_file_list_font_pic_color(uint8_t id, bool status);
static void draw_file_list_bar(void);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    ID_FLIE_LIST_FILE0,
    ID_FLIE_LIST_FILE1,
    ID_FLIE_LIST_FILE2,
    ID_FLIE_LIST_FILE3,
    ID_FLIE_LIST_FILE4,
    ID_FLIE_LIST_FILE5,
    ID_FLIE_LIST_FILE6,
    ID_FLIE_LIST_FILE7,
    ID_FLIE_LIST_UP,
    ID_FLIE_LIST_NEXT,
    ID_FILE_LIST_BACK,
};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {
   if(obj == file_list_page.btn_file0) return ID_FLIE_LIST_FILE0;
   else if(obj == file_list_page.btn_file1) return ID_FLIE_LIST_FILE1;
   else if(obj == file_list_page.btn_file2) return ID_FLIE_LIST_FILE2;
   else if(obj == file_list_page.btn_file3) return ID_FLIE_LIST_FILE3;
   else if(obj == file_list_page.btn_up) return ID_FLIE_LIST_UP;
   else if(obj == file_list_page.btn_next) return ID_FLIE_LIST_NEXT;
   else if(obj == file_list_page.btn_back) return ID_FILE_LIST_BACK;
}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        
        set_file_list_font_pic_color(id, true);

        switch(id) {
            case ID_FLIE_LIST_FILE0: 
            
            break;

            case ID_FLIE_LIST_FILE1:
                
            break;

            case ID_FLIE_LIST_FILE2: 

            break; 
            case ID_FLIE_LIST_FILE3:
                
            break;

        }
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        set_file_list_font_pic_color(id, false);
        

        switch(id) {
            case ID_FLIE_LIST_FILE0: 
                clean_file_list_page();
                draw_print();
            break;

            case ID_FLIE_LIST_FILE1:

            break;

            case ID_FLIE_LIST_FILE2: 

            break; 
            case ID_FLIE_LIST_FILE3:
                
            break;


            case ID_FILE_LIST_BACK: 
                clean_file_list_page();
                draw_home();
            break; 
            }
    }
}

static void draw_file_list_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 76);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

#define FILE_LIST_CN_EN "简体中文"
#define FILE_LIST_EN_EN  "English"
#define FILE_LIST_RU_EN  "русский\nязык"
#define FILE_LIST_DE_EN  "Deutsch"
#define FILE_LIST_BACK_EN  "Back"

#define FILE_LIST_UP_EN    "Up"
#define FILE_LIST_NEXT_EN  "Next"

void draw_file_list(void) {
    
    draw_file_list_bar();

    lv_style_copy(&file_list_page.btn_pre_style , &lv_style_scr);
    file_list_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	file_list_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    file_list_page.btn_pre_style.body.radius = 10;
    file_list_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&file_list_page.btn_rel_style , &lv_style_scr);
    file_list_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	file_list_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    file_list_page.btn_rel_style.body.radius = 10;
    file_list_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    file_list_page.btn_file0 =  lv_btn_set(ui.src, file_list_page.btn_file0, 110, 110, FILE_LIST_BTN_LIST_X1, FILE_LIST_BTN_LIST_Y1, event_handler);
    file_list_page.btn_file1 =  lv_btn_set(ui.src, file_list_page.btn_file1, 110, 110, FILE_LIST_BTN_LIST_X2, FILE_LIST_BTN_LIST_Y1, event_handler);
    file_list_page.btn_file2 =  lv_btn_set(ui.src, file_list_page.btn_file2, 110, 110, FILE_LIST_BTN_LIST_X3, FILE_LIST_BTN_LIST_Y1, event_handler);
    file_list_page.btn_file3 =  lv_btn_set(ui.src, file_list_page.btn_file3, 110, 110, FILE_LIST_BTN_LIST_X4, FILE_LIST_BTN_LIST_Y1, event_handler);
    file_list_page.btn_back =  lv_btn_set(ui.src, file_list_page.btn_back, 60, 60, FILE_LIST_BTN_BACK_X, FILE_LIST_BTN_BACK_Y, event_handler);
    file_list_page.btn_up =  lv_btn_set(ui.src, file_list_page.btn_back, 60, 60, FILE_LIST_BTN_UP_X, FILE_LIST_BTN_UP_Y, event_handler);
    file_list_page.btn_next =  lv_btn_set(ui.src, file_list_page.btn_back, 60, 60, FILE_LIST_BTN_NEXT_X, FILE_LIST_BTN_NEXT_Y, event_handler);

    lv_btn_set_style(file_list_page.btn_file0, LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
    lv_btn_set_style(file_list_page.btn_file0, LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下

    lv_btn_set_style(file_list_page.btn_file1, LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);
    lv_btn_set_style(file_list_page.btn_file1, LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);

    lv_btn_set_style(file_list_page.btn_file2, LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);
    lv_btn_set_style(file_list_page.btn_file2, LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);

    lv_btn_set_style(file_list_page.btn_file3, LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);
    lv_btn_set_style(file_list_page.btn_file3, LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);


    lv_btn_set_style(file_list_page.btn_back, LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);
    lv_btn_set_style(file_list_page.btn_back, LV_BTN_STYLE_REL, &file_list_page.btn_pre_style);

    lv_btn_set_style(file_list_page.btn_up, LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);
    lv_btn_set_style(file_list_page.btn_up, LV_BTN_STYLE_REL, &file_list_page.btn_pre_style);

    lv_btn_set_style(file_list_page.btn_next, LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);
    lv_btn_set_style(file_list_page.btn_next, LV_BTN_STYLE_REL, &file_list_page.btn_pre_style);

    file_list_page.label_file0_pic = lv_label_create(file_list_page.btn_file0, NULL);
    lv_label_set_text(file_list_page.label_file0_pic, FONT_PIC_FILE);
    lv_label_set_style(file_list_page.label_file0_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    file_list_page.label_file1_pic = lv_label_create(file_list_page.btn_file1, NULL);
    lv_label_set_text(file_list_page.label_file1_pic, FONT_PIC_FILE);
    lv_label_set_style(file_list_page.label_file1_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    
    file_list_page.label_file2_pic = lv_label_create(file_list_page.btn_file2, NULL);
    lv_label_set_text(file_list_page.label_file2_pic, FONT_PIC_FILE);
    lv_label_set_style(file_list_page.label_file2_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);

    file_list_page.label_file3_pic = lv_label_create(file_list_page.btn_file3, NULL);
    lv_label_set_text(file_list_page.label_file3_pic, FONT_PIC_FILE);
    lv_label_set_style(file_list_page.label_file3_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);

    file_list_page.label_back_pic = lv_label_create(file_list_page.btn_back, NULL);
    lv_label_set_text(file_list_page.label_back_pic, FONT_PIC_BACK);
    lv_label_set_style(file_list_page.label_back_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    file_list_page.label_up_pic = lv_label_create(file_list_page.btn_up, NULL);
    lv_label_set_text(file_list_page.label_up_pic, FONT_PIC_UP);
    lv_label_set_style(file_list_page.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    file_list_page.label_next_pic = lv_label_create(file_list_page.btn_next, NULL);
    lv_label_set_text(file_list_page.label_next_pic, FONT_PIC_NEXT);
    lv_label_set_style(file_list_page.label_next_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);


    file_list_page.label_file0 = lv_label_create(file_list_page.btn_file0, NULL);
    lv_obj_align(file_list_page.label_file0, file_list_page.label_file0_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(file_list_page.label_file0, FILE_LIST_CN_EN);

    file_list_page.label_file1 = lv_label_create(file_list_page.btn_file1, NULL);
    lv_obj_align(file_list_page.label_file1, file_list_page.label_file0_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(file_list_page.label_file1, FILE_LIST_EN_EN);

    file_list_page.label_file2 = lv_label_create(file_list_page.btn_file2, NULL);
    lv_obj_align(file_list_page.label_file2, file_list_page.label_file0_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(file_list_page.label_file2, FILE_LIST_RU_EN);

    file_list_page.label_file3 = lv_label_create(file_list_page.btn_file3, NULL);
    lv_obj_align(file_list_page.label_file3, file_list_page.label_file0_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(file_list_page.label_file3,FILE_LIST_DE_EN);

    file_list_page.label_back = lv_label_create(file_list_page.btn_back, NULL);
    lv_obj_align(file_list_page.label_back, file_list_page.label_back_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(file_list_page.label_back,FILE_LIST_BACK_EN);

    file_list_page.label_up = lv_label_create(file_list_page.btn_up, NULL);
    lv_obj_align(file_list_page.label_up, file_list_page.label_up_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(file_list_page.label_up,FILE_LIST_UP_EN);

    file_list_page.label_next = lv_label_create(file_list_page.btn_next, NULL);
    lv_obj_align(file_list_page.label_next, file_list_page.label_next_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(file_list_page.label_next,FILE_LIST_NEXT_EN);
}

/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_file_list_font_pic_color(uint8_t id, bool status) {

    switch(id) {
        case ID_FLIE_LIST_FILE0: 
            if(status) lv_label_set_style(file_list_page.label_file0_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_file0_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_FLIE_LIST_FILE1: 
            if(status) lv_label_set_style(file_list_page.label_file1_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_file1_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_FLIE_LIST_FILE2: 
            if(status) lv_label_set_style(file_list_page.label_file2_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_file2_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_FLIE_LIST_FILE3: 
            if(status) lv_label_set_style(file_list_page.label_file3_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_file3_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
    }

}





void clean_file_list_page(void) {

    lv_obj_clean(ui.src);
}

