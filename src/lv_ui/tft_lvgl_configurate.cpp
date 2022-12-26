#include "tft_lvgl_configurate.h"



lv_ui_t lv_ui;

void allStyleInit(void) {

	lv_style_init(&lv_ui.main_style);
	lv_style_set_bg_color(&lv_ui.main_style, lv_color_hex(MAIN_BG_COLOR));
	lv_style_set_bg_opa(&lv_ui.main_style, LV_OPA_COVER);
	lv_style_set_text_color(&lv_ui.main_style, lv_color_white());
	lv_obj_add_style(lv_ui.main_src, &lv_ui.main_style, 0);

	lv_style_init(&lv_ui.src1_style);
	lv_style_set_bg_color(&lv_ui.src1_style, lv_color_hex(SRC1_BG_COLOR));
	lv_style_set_bg_opa(&lv_ui.src1_style, LV_OPA_COVER);
	lv_style_set_border_width(&lv_ui.src1_style, 0);
	lv_style_set_radius(&lv_ui.src1_style, 17);
}

void drawLogoTaskCb(lv_timer_t*) {
	tft_lcd.tftBglightSetOn();
	// delay(1000);
	// lv_obj_del(lv_ui.mks_logo);
	// draw_ready();
	lv_timer_del(lv_ui.timer_logo);
}

void lv_example_btn_1(void);

void lvDrawLogo(void) {

	lv_ui.main_src = lv_obj_create(NULL);
	lv_ui.main_src = lv_scr_act();
	lv_obj_clear_flag(lv_ui.main_src, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(lv_ui.main_src, 480, 320);
	lv_obj_remove_style_all(lv_ui.main_src);

	/* Creat logo */
	// lv_ui.mks_logo = lv_img_create(lv_ui.main_src);
	// lv_img_set_src(lv_ui.mks_logo, "M:/mks_logo.bin");

	lv_example_btn_1();

	/* Init all style */
	allStyleInit();

	/* Tick 2000ms */
	lv_ui.timer_logo = lv_timer_create(drawLogoTaskCb, 2000, NULL);
}


static void event_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);

    if(code == LV_EVENT_CLICKED) {
        LV_LOG_USER("Clicked");
    }
    else if(code == LV_EVENT_VALUE_CHANGED) {
        LV_LOG_USER("Toggled");
    }
}

void lv_example_btn_1(void)
{
    lv_obj_t * label;

    lv_obj_t * btn1 = lv_btn_create(lv_ui.main_src );
    lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    lv_obj_t * btn2 = lv_btn_create(lv_ui.main_src );
    lv_obj_add_event_cb(btn2, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Toggle");
    lv_obj_center(label);
}