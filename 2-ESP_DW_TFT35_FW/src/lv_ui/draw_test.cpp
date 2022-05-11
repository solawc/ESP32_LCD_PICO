#include "draw_test.h"

static lv_obj_t *src;
static lv_obj_t *btn1;
static lv_obj_t *btn2;

static void event_handler(lv_obj_t * obj, lv_event_t event) {

    if(event != LV_EVENT_RELEASED) return ;



}

void lv_draw_test(void) {

    src = lv_obj_create(NULL, NULL);
    src = lv_scr_act();

    btn1 = lv_btn_create(src, NULL);
    lv_obj_set_size(btn1, 100, 100);
    lv_obj_set_pos(btn1, 10, 10);
    lv_obj_set_event_cb(btn1, event_handler);

    btn2 = lv_btn_create(src, NULL);
    lv_obj_set_size(btn2, 100, 100);
    lv_obj_set_pos(btn2, 120, 10);
    lv_obj_set_event_cb(btn2, event_handler);

}