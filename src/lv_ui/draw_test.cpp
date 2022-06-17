#include "draw_test.h"

static lv_obj_t *src;
static lv_obj_t *btn1;
static lv_obj_t *btn2;
static lv_obj_t *label;
static lv_obj_t *labe2;
static lv_style_t test_style;

static void event_handler1(lv_obj_t * obj, lv_event_t event) {

    if(event != LV_EVENT_RELEASED) return ;

    serial_sendf(CLIENT_SERIAL, "get mc type:%d\n", read_mc_type());
}

static void event_handler2(lv_obj_t * obj, lv_event_t event) {

    if(event != LV_EVENT_RELEASED) return ;

    change_mc_type();
}

void lv_draw_test(void) { 
    lv_style_copy(&test_style, &lv_style_scr);
    test_style.body.grad_color = LV_COLOR_MAKE(0xff, 0x12, 0xff);
	test_style.body.main_color = LV_COLOR_MAKE(0xff, 0x12, 0xff);
    test_style.text.color = LV_COLOR_YELLOW;
    test_style.text.font = &dlc_font_40x40;

    src = lv_obj_create(NULL, NULL);
    src = lv_scr_act();

    lv_obj_set_style(src, &test_style);

    label = lv_label_create(src, NULL);
    labe2 = lv_label_create(src, NULL);
    

    lv_label_set_body_draw(label, true);
    lv_label_set_text(label, FONT_ICON_BACK);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER,0,0);

    lv_label_set_body_draw(labe2, true);
    lv_label_set_text(labe2, FONT_ICON_BACK1);
    lv_obj_align(labe2, NULL, LV_ALIGN_CENTER,0,40);
}