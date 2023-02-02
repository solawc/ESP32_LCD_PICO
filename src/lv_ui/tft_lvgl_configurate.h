#ifndef __tft_lvgl_configurate_h
#define __tft_lvgl_configurate_h

#include "../main.h"



/* Theme Color */
#define MAIN_BG_COLOR           		0x1D2332// 0x13121A
#define SRC1_BG_COLOR          		 	0x1F2333

/* Extern define pic */
LV_IMG_DECLARE(mg_logo)
LV_IMG_DECLARE(pic_control)
LV_IMG_DECLARE(pic_engraving)
LV_IMG_DECLARE(pic_tool)

typedef struct {
	lv_obj_t* 	mg_logo;	
	lv_obj_t* 	main_src;
	lv_obj_t* 	src1;
	lv_obj_t* 	src2;

	lv_style_t  main_style;
	lv_style_t  src1_style;
	lv_style_t  src2_style;

	lv_timer_t* timer_logo;             // a timer to jump to draw_read()

}lv_ui_t;
extern lv_ui_t lv_ui;

typedef struct {

	lv_timer_t* timer_logo;
	lv_obj_t* 	mg_logo;	

	lv_obj_t *logo_page;
	bool logo_page_del;
	lv_obj_t *logo_page_logo_label;
	lv_obj_t *main_page;
	bool main_page_del;
	lv_obj_t *main_page_imgbtn_1;
	lv_obj_t *main_page_imgbtn_1_label;
	lv_obj_t *main_page_imgbtn_2;
	lv_obj_t *main_page_imgbtn_2_label;
	lv_obj_t *main_page_imgbtn_3;
	lv_obj_t *main_page_imgbtn_3_label;
	lv_obj_t *main_page_label_1;
	lv_obj_t *main_page_label_2;
	lv_obj_t *main_page_label_3;
	lv_obj_t *engraving_page;
	bool engraving_page_del;
	lv_obj_t *engraving_page_btn_frame;
	lv_obj_t *engraving_page_btn_frame_label;
	lv_obj_t *engraving_page_btn_home;
	lv_obj_t *engraving_page_btn_home_label;
	lv_obj_t *engraving_page_btn_position;
	lv_obj_t *engraving_page_btn_position_label;
	lv_obj_t *engraving_page_btn_start;
	lv_obj_t *engraving_page_btn_start_label;
	lv_obj_t *engraving_page_label_1;
	lv_obj_t *engraving_page_label_2;
	lv_obj_t *engraving_page_btn_5;
	lv_obj_t *engraving_page_btn_5_label;
	lv_obj_t *engraving_page_img_1;
	lv_obj_t *engraving_page_imgbtn_1;
	lv_obj_t *engraving_page_imgbtn_1_label;
	lv_obj_t *engraving_page_btn_6;
	lv_obj_t *engraving_page_btn_6_label;
	lv_obj_t *engraving_page_btn_7;
	lv_obj_t *engraving_page_btn_7_label;
	lv_obj_t *engraving_page_btn_8;
	lv_obj_t *engraving_page_btn_8_label;
	lv_obj_t *engraving_page_btn_9;
	lv_obj_t *engraving_page_btn_9_label;
	
}ui_t;
extern ui_t my_ui;

#include "draw_ready.h"
#include "draw_engraving.h"



void lvDrawLogo(void);

#endif
