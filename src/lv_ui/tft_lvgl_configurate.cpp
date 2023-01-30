#include "tft_lvgl_configurate.h"

lv_ui_t test_lv_ui;

void allStyleInit(void) {
	
	/* Settings bg color. */
	lv_style_init(&test_lv_ui.main_style);
	lv_style_set_bg_color(&test_lv_ui.main_style, lv_color_hex(MAIN_BG_COLOR));
	lv_style_set_bg_opa(&test_lv_ui.main_style, LV_OPA_COVER);
	lv_style_set_text_color(&test_lv_ui.main_style, lv_color_white());
	lv_obj_add_style(test_lv_ui.main_src, &test_lv_ui.main_style, 0);

	lv_style_init(&test_lv_ui.src1_style);
	lv_style_set_bg_color(&test_lv_ui.src1_style, lv_color_hex(SRC1_BG_COLOR));
	lv_style_set_bg_opa(&test_lv_ui.src1_style, LV_OPA_COVER);
	lv_style_set_border_width(&test_lv_ui.src1_style, 0);
	lv_style_set_radius(&test_lv_ui.src1_style, 17);
}

void drawLogoTaskCb(lv_timer_t*) {
	tft_lcd.tftBglightSetOn();
	delay(1000);
	lv_obj_del(test_lv_ui.mg_logo);
	// draw_ready();
	lv_timer_del(test_lv_ui.timer_logo);
}

void lv_example_btn_1(void);

void lvDrawLogo(void) {

	test_lv_ui.main_src = lv_obj_create(NULL);
	test_lv_ui.main_src = lv_scr_act();

	lv_obj_set_scrollbar_mode(test_lv_ui.main_src, LV_SCROLLBAR_MODE_OFF);
	lv_obj_clear_flag(test_lv_ui.main_src, LV_OBJ_FLAG_SCROLLABLE);
	lv_obj_set_size(test_lv_ui.main_src, 480, 320);
	lv_obj_remove_style_all(test_lv_ui.main_src);

	/* Creat logo */
	test_lv_ui.mg_logo = lv_img_create(test_lv_ui.main_src);
	// lv_img_set_src(test_lv_ui.mg_logo, "M:/mg_logo.bin");
	lv_img_set_src(test_lv_ui.mg_logo, &mg_logo);
	

	// lv_example_btn_1();		// debug demo

	/* Init all style */
	allStyleInit();

	/* Tick 2000ms */
	test_lv_ui.timer_logo = lv_timer_create(drawLogoTaskCb, 2000, NULL);
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

    lv_obj_t * btn1 = lv_btn_create(test_lv_ui.main_src );
    lv_obj_add_event_cb(btn1, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -40);

    label = lv_label_create(btn1);
    lv_label_set_text(label, "Button");
    lv_obj_center(label);

    lv_obj_t * btn2 = lv_btn_create(test_lv_ui.main_src );
    lv_obj_add_event_cb(btn2, event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn2, LV_ALIGN_CENTER, 0, 40);
    lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn2, LV_SIZE_CONTENT);

    label = lv_label_create(btn2);
    lv_label_set_text(label, "Toggle");
    lv_obj_center(label);
}