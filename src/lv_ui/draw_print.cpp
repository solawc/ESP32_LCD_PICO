/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_print.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_print_t print_page;

/***************************************************************************
 *                          static function
 * - static void set_print_font_pic_color(uint8_t id, bool status) 
 * - static void draw_print_bar(void)
 * 
***************************************************************************/
static void set_print_font_pic_color(uint8_t id, bool status);
static void draw_print_bar(void);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    ID_PRINT_START,
    ID_PRINT_STOP,
    ID_PRINT_ADJUSTMENT,
};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {
   if(obj == print_page.btn_start) return ID_PRINT_START;
   else if(obj == print_page.btn_stop) return ID_PRINT_STOP;
   else if(obj == print_page.btn_adjustment) return ID_PRINT_ADJUSTMENT;
}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        
        set_print_font_pic_color(id, true);

        switch(id) {
            case ID_PRINT_START: 
                
            break;

            case ID_PRINT_STOP:
                
            break;

            case ID_PRINT_ADJUSTMENT: 

            break; 


        }
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        set_print_font_pic_color(id, false);
        

        switch(id) {
            case ID_PRINT_START: 
                
            break;

            case ID_PRINT_STOP:

            break;

            case ID_PRINT_ADJUSTMENT: 
                // clean_print_page();
                draw_adjustment();
            break; 
            }
    }
}

static void draw_print_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 40);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

#define PRINT_START_EN "Start"
#define PRINT_STOP_EN  "Stop"
#define PRINT_ADJUSTMENT_EN  "Adjustment"
#define PRINT_WORK_EN     "Working\ncoordinates"
#define PRINT_MECHANI_EN  "Mechanical\ncoordinates"
#define PRINT_SPINDLE_EN  "Spindle speed"

#define FILE_NAME_EN "The Attack of the Advertiser.nc"


void draw_print(void) {
    
    draw_print_bar();

    lv_style_copy(&print_page.btn_pre_style , &lv_style_scr);
    print_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	print_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    print_page.btn_pre_style.body.radius = 10;
    print_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&print_page.btn_rel_style , &lv_style_scr);
    print_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	print_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    print_page.btn_rel_style.body.radius = 10;
    print_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    lv_style_copy(&print_page.bar_indic_style , &print_page.btn_pre_style);
    print_page.bar_indic_style.body.border.width = 0;
    print_page.bar_indic_style.body.padding.left = 0;
    print_page.bar_indic_style.body.padding.top = 0;
    print_page.bar_indic_style.body.padding.right = 0;
    print_page.bar_indic_style.body.padding.bottom = 0;

    lv_style_copy(&print_page.bar_bg_style , &print_page.btn_rel_style);
    print_page.bar_bg_style.body.border.color = lv_color_hex(get_current_color());;
    print_page.bar_bg_style.body.border.width = 1;
    print_page.bar_bg_style.body.border.color = lv_color_hex(get_current_color());;
    print_page.bar_bg_style.body.border.part = LV_BORDER_FULL;
    print_page.bar_bg_style.body.border.opa = 255;

    lv_style_copy(&print_page.label_bar_style , &print_page.btn_rel_style);
    print_page.label_bar_style.body.opa = 0;
    print_page.label_bar_style.text.color = LV_COLOR_WHITE;


    print_page.label_file_name_pic = lv_label_create(ui.src_1 , NULL);
    lv_obj_set_pos(print_page.label_file_name_pic,0,5);
    lv_label_set_text(print_page.label_file_name_pic, FONT_PIC_FILE);
    lv_label_set_style(print_page.label_file_name_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    print_page.label_file_name = lv_label_create(ui.src_1, NULL);
    lv_obj_align(print_page.label_file_name, print_page.label_file_name_pic, LV_ALIGN_OUT_RIGHT_MID, 10, 0);
    lv_label_set_text(print_page.label_file_name, FILE_NAME_EN);


    print_page.obj_work_region = lv_obj_set(ui.src, print_page.obj_work_region,PRINT_REGION_W, PRINT_REGION_H, PRINT_REGION_X1, PRINT_REGION_Y);
    print_page.obj_mechang_region = lv_obj_set(ui.src, print_page.obj_mechang_region,PRINT_REGION_W, PRINT_REGION_H, PRINT_REGION_X2, PRINT_REGION_Y);
    print_page.obj_speed_region = lv_obj_set(ui.src, print_page.obj_speed_region,PRINT_REGION_W, PRINT_REGION_H, PRINT_REGION_X3, PRINT_REGION_Y);

    lv_obj_set_style(print_page.obj_work_region, &print_page.btn_rel_style);
    lv_obj_set_style(print_page.obj_mechang_region, &print_page.btn_rel_style);
    lv_obj_set_style(print_page.obj_speed_region, &print_page.btn_rel_style);


    print_page.bar = lv_bar_create(ui.src, nullptr);
    lv_obj_set_pos(print_page.bar, PRINT_BAR_X, PRINT_BAR_Y);
    lv_obj_set_size(print_page.bar, PRINT_BAR_W, PRINT_BAR_H);
    lv_bar_set_style(print_page.bar, LV_BAR_STYLE_INDIC, &print_page.bar_indic_style);
    lv_bar_set_style(print_page.bar, LV_BAR_STYLE_BG, &print_page.bar_bg_style);
    lv_bar_set_anim_time(print_page.bar, 1000);
    lv_bar_set_value(print_page.bar, 10, LV_ANIM_ON);

    int per_num = 10;
    char buff[20];
    FD_ZERO(buff);
    sprintf(buff,"%d\%",per_num);
    print_page.label_bar_percen = lv_label_create(ui.src, NULL);
    lv_obj_align(print_page.label_bar_percen, print_page.bar, LV_ALIGN_IN_RIGHT_MID, 0, 0);
    lv_label_set_text(print_page.label_bar_percen, buff);
    lv_obj_set_style(print_page.label_bar_percen,&print_page.label_bar_style);

    int time_num = 10;
    FD_ZERO(buff);
    sprintf(buff,"%d\%",time_num);
    print_page.label_bar_time = lv_label_create(ui.src, NULL);
    lv_obj_align(print_page.label_bar_time, print_page.bar, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_text(print_page.label_bar_time, buff);
    lv_obj_set_style(print_page.label_bar_time,&print_page.label_bar_style);


    print_page.btn_start =  lv_btn_set(ui.src, print_page.btn_start, PRINT_BTN_W, PRINT_BTN_H, PRINT_BTN_X1, PRINT_BTN_Y, event_handler);
    print_page.btn_stop =  lv_btn_set(ui.src, print_page.btn_stop, PRINT_BTN_W, PRINT_BTN_H, PRINT_BTN_X2, PRINT_BTN_Y, event_handler);
    print_page.btn_adjustment =  lv_btn_set(ui.src, print_page.btn_adjustment, PRINT_BTN_W, PRINT_BTN_H, PRINT_BTN_X3, PRINT_BTN_Y, event_handler);
    

    lv_btn_set_style(print_page.btn_start, LV_BTN_STYLE_PR, &print_page.btn_pre_style);   // 按下
    lv_btn_set_style(print_page.btn_start, LV_BTN_STYLE_REL, &print_page.btn_rel_style);  // 

    lv_btn_set_style(print_page.btn_stop, LV_BTN_STYLE_PR, &print_page.btn_pre_style);
    lv_btn_set_style(print_page.btn_stop, LV_BTN_STYLE_REL, &print_page.btn_rel_style);

    lv_btn_set_style(print_page.btn_adjustment, LV_BTN_STYLE_PR, &print_page.btn_pre_style);
    lv_btn_set_style(print_page.btn_adjustment, LV_BTN_STYLE_REL, &print_page.btn_rel_style);


    print_page.label_work_region_pic = lv_label_create(ui.src, NULL);
    lv_label_set_text(print_page.label_work_region_pic, FONT_PIC_WORKING_COORDINATES);
    lv_label_set_style(print_page.label_work_region_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_obj_set_pos(print_page.label_work_region_pic,PRINT_REGION_X1,PRINT_REGION_Y + 10);

    print_page.label_mechang_region_pic = lv_label_create(ui.src, NULL);
    lv_label_set_text(print_page.label_mechang_region_pic, FONT_PIC_MECHANICAL_COORDINATES);
    lv_label_set_style(print_page.label_mechang_region_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_obj_set_pos(print_page.label_mechang_region_pic,PRINT_REGION_X2,PRINT_REGION_Y + 10);

    print_page.label_speed_region_pic = lv_label_create(ui.src, NULL);
    lv_label_set_text(print_page.label_speed_region_pic, FONT_PIC_SPINDLE);
    lv_label_set_style(print_page.label_speed_region_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_obj_set_pos(print_page.label_speed_region_pic,PRINT_REGION_X3,PRINT_REGION_Y + 10);


    print_page.label_start_pic = lv_label_create(ui.src, NULL);
    lv_label_set_text(print_page.label_start_pic, FONT_PIC_START);
    lv_label_set_style(print_page.label_start_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_obj_align(print_page.label_start_pic, print_page.btn_start, LV_ALIGN_IN_LEFT_MID, 30, 0);

    print_page.label_stop_pic = lv_label_create(ui.src, NULL);
    lv_label_set_text(print_page.label_stop_pic, FONT_PIC_STOP);
    lv_label_set_style(print_page.label_stop_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_obj_align(print_page.label_stop_pic, print_page.btn_stop, LV_ALIGN_IN_LEFT_MID, 30, 0);

    print_page.label_adjustment_pic = lv_label_create(ui.src, NULL);
    lv_label_set_text(print_page.label_adjustment_pic, FONT_PIC_ADJUSTMENT);
    lv_label_set_style(print_page.label_adjustment_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    lv_obj_align(print_page.label_adjustment_pic, print_page.btn_adjustment, LV_ALIGN_IN_LEFT_MID, 10, 0);



    print_page.label_start = lv_label_create(ui.src, NULL);
    lv_obj_align(print_page.label_start, print_page.btn_start, LV_ALIGN_CENTER, 10, 0);
    lv_label_set_text(print_page.label_start, PRINT_START_EN);

    print_page.label_stop = lv_label_create(ui.src, NULL);
    lv_obj_align(print_page.label_stop, print_page.btn_stop, LV_ALIGN_CENTER, 10, 0);
    lv_label_set_text(print_page.label_stop, PRINT_STOP_EN);

    print_page.label_adjustment = lv_label_create(ui.src, NULL);
    lv_obj_align(print_page.label_adjustment, print_page.btn_adjustment, LV_ALIGN_CENTER, -5, 0);
    lv_label_set_text(print_page.label_adjustment, PRINT_ADJUSTMENT_EN);

    print_page.label_work_region = lv_label_create(ui.src, NULL);
    lv_obj_align(print_page.label_work_region, print_page.label_work_region_pic, LV_ALIGN_OUT_RIGHT_MID, 0, -10);
    lv_label_set_text(print_page.label_work_region, PRINT_WORK_EN);

    print_page.label_mechang_region = lv_label_create(ui.src, NULL);
    lv_obj_align(print_page.label_mechang_region, print_page.label_mechang_region_pic, LV_ALIGN_OUT_RIGHT_MID, 0, -10);
    lv_label_set_text(print_page.label_mechang_region, PRINT_MECHANI_EN);

    print_page.label_speed_region = lv_label_create(ui.src, NULL);
    lv_obj_align(print_page.label_speed_region, print_page.label_speed_region_pic, LV_ALIGN_OUT_RIGHT_MID, 0, 0);
    lv_label_set_text(print_page.label_speed_region, PRINT_SPINDLE_EN);

}

/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_print_font_pic_color(uint8_t id, bool status) {

    // switch(id) {
    //     case ID_PRINT_START: 
    //         if(status) lv_label_set_style(print_page.label_start_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(print_page.label_start_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_PRINT_STOP: 
    //         if(status) lv_label_set_style(print_page.label_stop_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(print_page.label_stop_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_PRINT_ADJUSTMENT: 
    //         if(status) lv_label_set_style(print_page.label_adjustment_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(print_page.label_adjustment_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_LANGUAGE_DE: 
    //         if(status) lv_label_set_style(print_page.label_de_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(print_page.label_de_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    // }

}





void clean_print_page(void) {

    lv_obj_clean(ui.src);
}

