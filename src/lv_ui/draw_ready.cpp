#include "draw_ready.h"

src_ready_t src_ready;

static void event_handler(lv_event_t * e) {

    lv_event_code_t code = lv_event_get_code(e);

    if(e->target == src_ready.imgbtn_engraving ) {
        if(code == LV_EVENT_CLICKED) {
            debug_send(CLIENT_SERIAL, "engraving Clicked\n");
        }
    }else if(e->target == src_ready.imgbtn_control) {
        if(code == LV_EVENT_CLICKED) {
            debug_send(CLIENT_SERIAL, "control Clicked\n");
        }
    }
}

void draw_ready(void) {

    src_ready.imgbtn_engraving = lv_imgbtn_create(lv_ui.main_src);
    lv_obj_set_size(src_ready.imgbtn_engraving, 114, 114);
    lv_imgbtn_set_src(src_ready.imgbtn_engraving, LV_IMGBTN_STATE_RELEASED, 
                        &pic_engraving, NULL, NULL);
    lv_obj_set_pos(src_ready.imgbtn_engraving, 38, 112);
    lv_obj_add_event_cb(src_ready.imgbtn_engraving, event_handler, LV_EVENT_ALL, NULL);

    src_ready.imgbtn_control = lv_imgbtn_create(lv_ui.main_src);
    lv_obj_set_size(src_ready.imgbtn_control, 114, 114);
    lv_imgbtn_set_src(src_ready.imgbtn_control, LV_IMGBTN_STATE_RELEASED, 
                        &pic_control, NULL, NULL);
    lv_obj_set_pos(src_ready.imgbtn_control, 188, 112);
    lv_obj_add_event_cb(src_ready.imgbtn_control, event_handler, LV_EVENT_ALL, NULL);

    src_ready.imgbtn_tool = lv_imgbtn_create(lv_ui.main_src);
    lv_obj_set_size(src_ready.imgbtn_tool, 114, 114);
    lv_imgbtn_set_src(src_ready.imgbtn_tool, LV_IMGBTN_STATE_RELEASED, 
                        &pic_tool, NULL, NULL);
    lv_obj_set_pos(src_ready.imgbtn_tool, 328, 112);
    lv_obj_add_event_cb(src_ready.imgbtn_tool, event_handler, LV_EVENT_ALL, NULL);

    // src_ready.label_engraving = lv_label_create(lv_ui.main_src);
    // src_ready.label_control = lv_label_create(lv_ui.main_src);
    // src_ready.label_tool = lv_label_create(lv_ui.main_src);
    src_ready.label_engraving = lv_label_create(lv_ui.main_src);
    src_ready.label_control = lv_label_create(src_ready.imgbtn_control);
    src_ready.label_tool = lv_label_create(src_ready.imgbtn_tool);

    // lv_obj_set_align(src_ready.label_engraving, LV_ALIGN_OUT_BOTTOM_MID);
    // lv_obj_align(src_ready.label_engraving, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
    lv_obj_align_to(src_ready.label_engraving, src_ready.imgbtn_engraving, LV_ALIGN_OUT_BOTTOM_RIGHT, 0, 0);

    lv_label_set_text(src_ready.label_engraving, "Engraving");

}





