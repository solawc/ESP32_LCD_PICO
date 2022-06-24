#pragma once

#include "../main.h"

LV_FONT_DECLARE(dlc32_gb2312);
LV_FONT_DECLARE(dlc_font_40x40);
LV_FONT_DECLARE(dlc_font_70x70);
LV_FONT_DECLARE(dlc_font_60x60);





/**********************************************************
 *                        Theme
 *  - White
 *  - Green
 *  - Red
 *  - Orange
 *  - Pink
**********************************************************/
#define F_THEME_WRITE               (0xffffff)
#define F_THEME_GREEN               (0x4DE585) 
#define F_THEME_RED                 (0xD43636)
#define F_THEME_ORANGE              (0xE5A240)
#define F_THEME_PINK                (0xFFAEC9)
#define F_THEME_BTN_REL_COLOR       (0x333333)// (0X191919)
#define F_THEME_FONR_REL_COLOR      (0X191919)

typedef enum {

    THEME_WRITE,
    THEME_GREEN,
    THEME_RED,
    THEME_ORANGE,
    THEME_PINK,

}theme_type_t;


typedef struct {

    theme_type_t theme_type;

    uint32_t font_pre_color;
    uint32_t font_rel_color;

    uint32_t btn_pre_color;
    uint32_t btn_rel_color;

    
    // ....
}ui_theme_t;

typedef struct {

    lv_obj_t    *src;                           // 作为主页
    lv_obj_t    *src_1;               
    lv_obj_t    *src_2;               

    

    uint8_t     page_list;     

    ui_theme_t ui_theme;                        // 用于保存主题的相关信息

    lv_style_t di_font_40_40;                   // 自定义字库类型         
    lv_style_t di_font_40_40_pre;               // 自定义字库类型
    lv_style_t di_font_60_60;                   // 自定义字库类型         
    lv_style_t di_font_60_60_pre;               // 自定义字库类型
    lv_style_t di_font_70_70;                   // 自定义字库类型         
    lv_style_t di_font_70_70_pre;               // 自定义字库类型  


    /* 公共使用的样式 */
    lv_style_t  src_style;                      // 主页样式
    lv_style_t  src_1_style;                    // 状态栏样式1
    lv_style_t  src_2_style;                    // 状态栏样式2

    lv_style_t com_back;                        
    lv_style_t com_back_pre;                    



}_ui_t;
extern _ui_t ui;






void ui_init_style(void);
void ui_theme_set(void);
void ui_theme_reset(void);
void set_current_color(theme_type_t color);
theme_type_t get_default_theme(void);
uint32_t get_current_color(void);

lv_obj_t* lv_btn_set(lv_obj_t* scr, lv_obj_t* btn, lv_coord_t btn_w, lv_coord_t btn_h, lv_coord_t x, lv_coord_t y, lv_event_cb_t event_cb);
lv_obj_t* lv_obj_set(lv_obj_t* scr, lv_obj_t* obj, lv_coord_t btn_w, lv_coord_t btn_h, lv_coord_t x, lv_coord_t y);
lv_obj_t* lv_label_set(lv_obj_t* scr, lv_obj_t* label, lv_coord_t x, lv_coord_t y, const char *text);
lv_obj_t* lv_label_set_btn(lv_obj_t* scr, lv_obj_t* label, lv_obj_t* base, lv_coord_t x, lv_coord_t y, const char *text);
