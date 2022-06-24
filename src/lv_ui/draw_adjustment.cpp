
/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_adjustment.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_adjustment_t adjustment_page;
int feed_rate = 10;
int spindle_speed = 10;
int rapid_speed = 10;

/***************************************************************************
 *                          static function
 * - static void set_print_font_pic_color(uint8_t id, bool status) 
 * - static void draw_adjustment_bar(void)
 * 
***************************************************************************/
enum{
    ID_ADJUSTMENT_FEED,
    ID_ADJUSTMENT_SPINDLE,
    ID_ADJUSTMENT_RAPID,
    ID_ADJUSTMENT_ADD,
    ID_ADJUSTMENT_REDUCE,
    ID_ADJUSTMENT_STEP,
    ID_ADJUSTMENT_BACK,
    ID_ADJUSTMENT_CONFIRM,
};

enum{
    ADJUSTMENT_STEP_1 = 1,
    ADJUSTMENT_STEP_5 = 5,
    ADJUSTMENT_STEP_10 = 10,
};
int step = ADJUSTMENT_STEP_1;

typedef enum{
    CHOICE_FEED,
    CHOICE_SPINDLE,
    CHOICE_RAPID,
}CHOICE_BTN_TYPE_t;

CHOICE_BTN_TYPE_t current_choice_btn = CHOICE_FEED;
static void disp_current_choice_btn(CHOICE_BTN_TYPE_t data);
static void disp_current_choice_btn_label(CHOICE_BTN_TYPE_t data);
static void set_adjustment_font_pic_color(uint8_t id, bool status);
static void change_adjustment_step();
static void add_adjustment_num();
static void dec_adjustment_num();
static uint8_t get_event(lv_obj_t* obj) {

   if(obj == adjustment_page.btn_feed) return ID_ADJUSTMENT_FEED;
   else if(obj == adjustment_page.btn_spindle) return ID_ADJUSTMENT_SPINDLE;
   else if(obj == adjustment_page.btn_rapid) return ID_ADJUSTMENT_RAPID;
   else if(obj == adjustment_page.btn_add) return ID_ADJUSTMENT_ADD;
   else if(obj == adjustment_page.btn_reduce) return ID_ADJUSTMENT_REDUCE;
   else if(obj == adjustment_page.btn_step) return ID_ADJUSTMENT_STEP;
   else if(obj == adjustment_page.btn_back) return ID_ADJUSTMENT_BACK;
   else if(obj == adjustment_page.btn_confirm) return ID_ADJUSTMENT_CONFIRM;


}

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
#define ADJUSTMENT_ADD_EN  "Add"
#define ADJUSTMENT_REDUCE_EN  "Reduce"
#define ADJUSTMENT_BACK_EN  "Back"
#define ADJUSTMENT_CONFIRM_EN  "Confirm"

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {

        set_adjustment_font_pic_color(id, true);

        switch(id) {
            case ID_ADJUSTMENT_FEED: 
            current_choice_btn = CHOICE_FEED;
            disp_current_choice_btn(current_choice_btn);
            disp_current_choice_btn_label(current_choice_btn);

            break;
            case ID_ADJUSTMENT_SPINDLE:
            current_choice_btn = CHOICE_SPINDLE;
            disp_current_choice_btn(current_choice_btn);
            disp_current_choice_btn_label(current_choice_btn);
            break;

            case ID_ADJUSTMENT_RAPID: 
            current_choice_btn = CHOICE_RAPID;
            disp_current_choice_btn(current_choice_btn);
            disp_current_choice_btn_label(current_choice_btn);
            break; 
            case ID_ADJUSTMENT_ADD:
                
            break;
            case ID_ADJUSTMENT_REDUCE:
                
            break;
            case ID_ADJUSTMENT_STEP:
                
            break;
            case ID_ADJUSTMENT_BACK:
                
            break;
            case ID_ADJUSTMENT_CONFIRM:
                
            break;
        }
    }
        if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        set_adjustment_font_pic_color(id, false);
        

        switch(id) {

            case ID_ADJUSTMENT_FEED: 
                
            break;

            case ID_ADJUSTMENT_SPINDLE:
                
            break;

            case ID_ADJUSTMENT_RAPID: 

            break; 
            case ID_ADJUSTMENT_ADD:
                add_adjustment_num();
            break;
            case ID_ADJUSTMENT_REDUCE:
                dec_adjustment_num();

            break;
            case ID_ADJUSTMENT_STEP:
                change_adjustment_step();
            break;
            case ID_ADJUSTMENT_BACK:
                clean_adjustment_page();
            break;
            case ID_ADJUSTMENT_CONFIRM:
                
            break;
            
            }
    }
}
void draw_adjustment(void) {

    ui.src_2 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_2, 360, 220);
    lv_obj_set_pos(ui.src_2, 60, 50);
    lv_obj_set_style(ui.src_2, &ui.src_style);

    lv_style_copy(&adjustment_page.btn_pre_style , &lv_style_scr);
    adjustment_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	adjustment_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    adjustment_page.btn_pre_style.body.radius = 10;
    adjustment_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&adjustment_page.btn_rel_style , &lv_style_scr);
    adjustment_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	adjustment_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    adjustment_page.btn_rel_style.body.radius = 10;
    adjustment_page.btn_rel_style.body.border.part = LV_BORDER_FULL;
    adjustment_page.btn_rel_style.body.border.color = lv_color_hex(get_current_color());;
    adjustment_page.btn_rel_style.body.border.opa = 255;
    adjustment_page.btn_rel_style.body.border.width = 1;
    adjustment_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  


    adjustment_page.btn_feed =  lv_btn_set(ui.src_2, adjustment_page.btn_feed, ADJUSTMENT_BTN1_W, ADJUSTMENT_BTN1_H, ADJUSTMENT_BTN1_X, ADJUSTMENT_BTN1_Y1, event_handler);
    adjustment_page.btn_spindle =  lv_btn_set(ui.src_2, adjustment_page.btn_spindle, ADJUSTMENT_BTN1_W, ADJUSTMENT_BTN1_H, ADJUSTMENT_BTN1_X, ADJUSTMENT_BTN1_Y2, event_handler);
    adjustment_page.btn_rapid =  lv_btn_set(ui.src_2, adjustment_page.btn_rapid, ADJUSTMENT_BTN1_W, ADJUSTMENT_BTN1_H, ADJUSTMENT_BTN1_X, ADJUSTMENT_BTN1_Y3, event_handler);

    adjustment_page.btn_add =  lv_btn_set(ui.src_2, adjustment_page.btn_add, ADJUSTMENT_BTN3_W, ADJUSTMENT_BTN3_H, ADJUSTMENT_BTN3_X, ADJUSTMENT_BTN3_Y1, event_handler);
    adjustment_page.btn_reduce =  lv_btn_set(ui.src_2, adjustment_page.btn_reduce, ADJUSTMENT_BTN3_W, ADJUSTMENT_BTN3_H, ADJUSTMENT_BTN3_X, ADJUSTMENT_BTN3_Y2, event_handler);
    adjustment_page.btn_step =  lv_btn_set(ui.src_2, adjustment_page.btn_step, ADJUSTMENT_BTN3_W, ADJUSTMENT_BTN3_H, ADJUSTMENT_BTN3_X, ADJUSTMENT_BTN3_Y3, event_handler);

    adjustment_page.btn_back =  lv_btn_set(ui.src_2, adjustment_page.btn_back, adjustment_BTN2_W, adjustment_BTN2_H, adjustment_BTN2_X2, adjustment_BTN2_Y, event_handler);
    adjustment_page.btn_confirm =  lv_btn_set(ui.src_2, adjustment_page.btn_confirm, adjustment_BTN2_W, adjustment_BTN2_H, ADJUSTMENT_BTN2_X1, adjustment_BTN2_Y, event_handler);



    disp_current_choice_btn(current_choice_btn);



    lv_btn_set_style(adjustment_page.btn_add, LV_BTN_STYLE_PR, &adjustment_page.btn_pre_style);   // 按下
    lv_btn_set_style(adjustment_page.btn_add, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  // 

    lv_btn_set_style(adjustment_page.btn_reduce, LV_BTN_STYLE_PR, &adjustment_page.btn_pre_style);   // 按下
    lv_btn_set_style(adjustment_page.btn_reduce, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  // 

    lv_btn_set_style(adjustment_page.btn_step, LV_BTN_STYLE_PR, &adjustment_page.btn_pre_style);   // 按下
    lv_btn_set_style(adjustment_page.btn_step, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  // 

    lv_btn_set_style(adjustment_page.btn_back, LV_BTN_STYLE_PR, &adjustment_page.btn_pre_style);   // 按下
    lv_btn_set_style(adjustment_page.btn_back, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  // 

    lv_btn_set_style(adjustment_page.btn_confirm, LV_BTN_STYLE_PR, &adjustment_page.btn_pre_style);   // 按下
    lv_btn_set_style(adjustment_page.btn_confirm, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  // 



    char buff[20];
    FD_ZERO(buff);
    sprintf(buff,"Feed rate:%d%",feed_rate);
    adjustment_page.label_feed = lv_label_create(ui.src_2, NULL);
    lv_obj_align(adjustment_page.label_feed, adjustment_page.btn_feed, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_text(adjustment_page.label_feed, buff);
    FD_ZERO(buff);
    sprintf(buff,"Spindle speed:%d%",spindle_speed);
    adjustment_page.label_spindle = lv_label_create(ui.src_2, NULL);
    lv_obj_align(adjustment_page.label_spindle, adjustment_page.btn_spindle, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_text(adjustment_page.label_spindle, buff);
    FD_ZERO(buff);
    sprintf(buff,"Rapid speed:%d%",rapid_speed);
    adjustment_page.label_rapid = lv_label_create(ui.src_2, NULL);
    lv_obj_align(adjustment_page.label_rapid, adjustment_page.btn_rapid, LV_ALIGN_IN_LEFT_MID, 10, 0);
    lv_label_set_text(adjustment_page.label_rapid, buff);

    disp_current_choice_btn_label(current_choice_btn);

    adjustment_page.label_add_pic = lv_label_create(adjustment_page.btn_add, NULL);
    lv_label_set_text(adjustment_page.label_add_pic, FONT_PIC_ADD);
    lv_label_set_style(adjustment_page.label_add_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);

    adjustment_page.label_reduce_pic = lv_label_create(adjustment_page.btn_reduce, NULL);
    lv_label_set_text(adjustment_page.label_reduce_pic, FONT_PIC_REDUCE);
    lv_label_set_style(adjustment_page.label_reduce_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);

    adjustment_page.label_back_pic = lv_label_create(adjustment_page.btn_back, NULL);
    lv_label_set_text(adjustment_page.label_back_pic, FONT_PIC_BACK);
    lv_label_set_style(adjustment_page.label_back_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);

    adjustment_page.label_confirm_pic = lv_label_create(adjustment_page.btn_confirm, NULL);
    lv_label_set_text(adjustment_page.label_confirm_pic, FONT_PIC_CONFIRM);
    lv_label_set_style(adjustment_page.label_confirm_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
    // adjustment_page.label_start = lv_label_create(ui.src_2, NULL);
    // lv_obj_align(adjustment_page.label_start, adjustment_page.btn_start, LV_ALIGN_CENTER, 10, 0);
    // lv_label_set_text(adjustment_page.label_start, PRINT_START_EN);
    
    adjustment_page.label_add = lv_label_create(adjustment_page.btn_add, NULL);
    lv_obj_align(adjustment_page.label_add, adjustment_page.label_add_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(adjustment_page.label_add, ADJUSTMENT_ADD_EN);

    adjustment_page.label_reduce = lv_label_create(adjustment_page.btn_reduce, NULL);
    lv_obj_align(adjustment_page.label_reduce, adjustment_page.label_reduce_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(adjustment_page.label_reduce, ADJUSTMENT_REDUCE_EN);


    adjustment_page.label_back_pic = lv_label_create(adjustment_page.btn_back, NULL);
    lv_obj_align(adjustment_page.label_back_pic, adjustment_page.label_reduce_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(adjustment_page.label_back_pic, ADJUSTMENT_BACK_EN);

    adjustment_page.label_confirm_pic = lv_label_create(adjustment_page.btn_confirm, NULL);
    lv_obj_align(adjustment_page.label_confirm_pic, adjustment_page.label_confirm_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(adjustment_page.label_confirm_pic, ADJUSTMENT_CONFIRM_EN);


    FD_ZERO(buff);
    sprintf(buff,"%d%",step);
    adjustment_page.label_step = lv_label_create(ui.src_2, NULL);
    lv_obj_align(adjustment_page.label_step, adjustment_page.btn_step, LV_ALIGN_CENTER, 0, 0);
    lv_label_set_text(adjustment_page.label_step, buff);

}

/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
void disp_current_choice_btn(CHOICE_BTN_TYPE_t data)
{
    switch (data)
    {
    case CHOICE_FEED:
        lv_btn_set_style(adjustment_page.btn_feed, LV_BTN_STYLE_PR, &adjustment_page.btn_pre_style);   // 按下
        lv_btn_set_style(adjustment_page.btn_feed, LV_BTN_STYLE_REL, &adjustment_page.btn_pre_style);  // 
        lv_btn_set_style(adjustment_page.btn_spindle, LV_BTN_STYLE_PR, &adjustment_page.btn_rel_style);   // 按下
        lv_btn_set_style(adjustment_page.btn_spindle, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  // 
        lv_btn_set_style(adjustment_page.btn_rapid, LV_BTN_STYLE_PR, &adjustment_page.btn_rel_style);   // 按下
        lv_btn_set_style(adjustment_page.btn_rapid, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  //
        break;
    
    case CHOICE_SPINDLE:
        lv_btn_set_style(adjustment_page.btn_feed, LV_BTN_STYLE_PR, &adjustment_page.btn_rel_style);   // 按下
        lv_btn_set_style(adjustment_page.btn_feed, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  // 
        lv_btn_set_style(adjustment_page.btn_spindle, LV_BTN_STYLE_PR, &adjustment_page.btn_pre_style);   // 按下
        lv_btn_set_style(adjustment_page.btn_spindle, LV_BTN_STYLE_REL, &adjustment_page.btn_pre_style);  // 
        lv_btn_set_style(adjustment_page.btn_rapid, LV_BTN_STYLE_PR, &adjustment_page.btn_rel_style);   // 按下
        lv_btn_set_style(adjustment_page.btn_rapid, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  //
        break;

    case CHOICE_RAPID:
        lv_btn_set_style(adjustment_page.btn_feed, LV_BTN_STYLE_PR, &adjustment_page.btn_rel_style);   // 按下
        lv_btn_set_style(adjustment_page.btn_feed, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  // 
        lv_btn_set_style(adjustment_page.btn_spindle, LV_BTN_STYLE_PR, &adjustment_page.btn_rel_style);   // 按下
        lv_btn_set_style(adjustment_page.btn_spindle, LV_BTN_STYLE_REL, &adjustment_page.btn_rel_style);  // 
        lv_btn_set_style(adjustment_page.btn_rapid, LV_BTN_STYLE_PR, &adjustment_page.btn_pre_style);   // 按下
        lv_btn_set_style(adjustment_page.btn_rapid, LV_BTN_STYLE_REL, &adjustment_page.btn_pre_style);  //
        break;
    }
}

void disp_current_choice_btn_label(CHOICE_BTN_TYPE_t data)
{
    switch (data)
    {
    case CHOICE_FEED:
        lv_label_set_style(adjustment_page.label_feed,LV_LABEL_STYLE_MAIN,&adjustment_page.btn_pre_style);
        lv_label_set_style(adjustment_page.label_spindle,LV_LABEL_STYLE_MAIN,&adjustment_page.btn_rel_style);
        lv_label_set_style(adjustment_page.label_rapid,LV_LABEL_STYLE_MAIN,&adjustment_page.btn_rel_style);
        break;
    
    case CHOICE_SPINDLE:
        lv_label_set_style(adjustment_page.label_feed,LV_LABEL_STYLE_MAIN,&adjustment_page.btn_rel_style);
        lv_label_set_style(adjustment_page.label_spindle,LV_LABEL_STYLE_MAIN,&adjustment_page.btn_pre_style);
        lv_label_set_style(adjustment_page.label_rapid,LV_LABEL_STYLE_MAIN,&adjustment_page.btn_rel_style);
        break;

    case CHOICE_RAPID:
        lv_label_set_style(adjustment_page.label_feed,LV_LABEL_STYLE_MAIN,&adjustment_page.btn_rel_style);
        lv_label_set_style(adjustment_page.label_spindle,LV_LABEL_STYLE_MAIN,&adjustment_page.btn_rel_style);
        lv_label_set_style(adjustment_page.label_rapid,LV_LABEL_STYLE_MAIN,&adjustment_page.btn_pre_style);
        break;
    }
}


static void set_adjustment_font_pic_color(uint8_t id, bool status) {

    switch(id) {
        case ID_ADJUSTMENT_ADD: 
            if(status) lv_label_set_style(adjustment_page.label_add_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(adjustment_page.label_add_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_ADJUSTMENT_REDUCE: 
            if(status) lv_label_set_style(adjustment_page.label_reduce_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(adjustment_page.label_reduce_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_ADJUSTMENT_BACK: 
            if(status) lv_label_set_style(adjustment_page.label_back_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(adjustment_page.label_back_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_ADJUSTMENT_CONFIRM: 
            if(status) lv_label_set_style(adjustment_page.label_confirm_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(adjustment_page.label_confirm_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
    }

}
static void change_adjustment_step() {
    char buff[20];
    switch (step)
    {
    case ADJUSTMENT_STEP_1:
        FD_ZERO(buff);
        step = ADJUSTMENT_STEP_5;
        sprintf(buff,"%d%",step);
        lv_obj_align(adjustment_page.label_step, adjustment_page.btn_step, LV_ALIGN_CENTER, 0, 0);
        lv_label_set_text(adjustment_page.label_step, buff);
        break;
    case ADJUSTMENT_STEP_5:
        FD_ZERO(buff);
        step = ADJUSTMENT_STEP_10;
        sprintf(buff,"%d%",step);
        lv_obj_align(adjustment_page.label_step, adjustment_page.btn_step, LV_ALIGN_CENTER, 0, 0);
        lv_label_set_text(adjustment_page.label_step, buff);
        break;
    case ADJUSTMENT_STEP_10:
        FD_ZERO(buff);
        step = ADJUSTMENT_STEP_1;
        sprintf(buff,"%d%",step);
        lv_obj_align(adjustment_page.label_step, adjustment_page.btn_step, LV_ALIGN_CENTER, 0, 0);
        lv_label_set_text(adjustment_page.label_step, buff);
        break;
    }
}
static void add_adjustment_num() 
{
    char buff[20];
    switch (current_choice_btn)
    {
    case CHOICE_FEED:
            feed_rate += step;
            FD_ZERO(buff);
            sprintf(buff,"Feed rate:%d%",feed_rate);
            lv_obj_align(adjustment_page.label_feed, adjustment_page.btn_feed, LV_ALIGN_IN_LEFT_MID, 10, 0);
            lv_label_set_text(adjustment_page.label_feed, buff);
        break;
    
    case CHOICE_SPINDLE:
            spindle_speed += step;
            FD_ZERO(buff);
            sprintf(buff,"Spindle speed:%d%",spindle_speed);
            lv_obj_align(adjustment_page.label_spindle, adjustment_page.btn_spindle, LV_ALIGN_IN_LEFT_MID, 10, 0);
            lv_label_set_text(adjustment_page.label_spindle, buff);
        break;

    case CHOICE_RAPID:
            rapid_speed += step;
            FD_ZERO(buff);
            sprintf(buff,"Rapid speed:%d%",rapid_speed);
            lv_obj_align(adjustment_page.label_rapid, adjustment_page.btn_rapid, LV_ALIGN_IN_LEFT_MID, 10, 0);
            lv_label_set_text(adjustment_page.label_rapid, buff);
        break;
    }
}
static void dec_adjustment_num() 
{
    char buff[20];
    switch (current_choice_btn)
    {
    case CHOICE_FEED:
            feed_rate -= step;
            if(feed_rate <= 0)
                feed_rate = 0;
            FD_ZERO(buff);
            sprintf(buff,"Feed rate:%d%",feed_rate);
            lv_obj_align(adjustment_page.label_feed, adjustment_page.btn_feed, LV_ALIGN_IN_LEFT_MID, 10, 0);
            lv_label_set_text(adjustment_page.label_feed, buff);
        break;
    
    case CHOICE_SPINDLE:
            spindle_speed -= step;
            if(spindle_speed <= 0)
                spindle_speed = 0;
            FD_ZERO(buff);
            sprintf(buff,"Spindle speed:%d%",spindle_speed);
            lv_obj_align(adjustment_page.label_spindle, adjustment_page.btn_spindle, LV_ALIGN_IN_LEFT_MID, 10, 0);
            lv_label_set_text(adjustment_page.label_spindle, buff);
        break;

    case CHOICE_RAPID:
            rapid_speed -= step;
            if(rapid_speed <= 0)
                rapid_speed = 0;
            FD_ZERO(buff);
            sprintf(buff,"Rapid speed:%d%",rapid_speed);
            lv_obj_align(adjustment_page.label_rapid, adjustment_page.btn_rapid, LV_ALIGN_IN_LEFT_MID, 10, 0);
            lv_label_set_text(adjustment_page.label_rapid, buff);
        break;
    }
}
void clean_adjustment_page(void) {

    lv_obj_del(ui.src_2);
}

