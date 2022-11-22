#pragma once

#include "../main.h"

/* Theme Color */
#define MAIN_BG_COLOR           		0x13121A
#define SRC1_BG_COLOR          		 	0x1F2333

typedef struct {
	lv_obj_t* 	mks_logo;
	lv_obj_t* 	main_src;
	lv_obj_t* 	src1;
	lv_obj_t* 	src2;

	lv_style_t  main_style;
	lv_style_t  src1_style;
	lv_style_t  src2_style;

	lv_timer_t* timer_logo;             // a timer to jump to draw_read()

}lv_ui_t;
extern lv_ui_t lv_ui;




void lvDrawLogo(void);