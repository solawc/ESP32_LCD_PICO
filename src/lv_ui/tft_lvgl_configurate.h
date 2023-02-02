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


#include "draw_ready.h"
#include "draw_engraving.h"



void lvDrawLogo(void);

#endif
