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
    lv_obj_set_pos(src_ready.imgbtn_engraving, 38, 112);                // set imgbtn pos.
    lv_obj_set_size(src_ready.imgbtn_engraving, 114, 114);              // set imgbtn size.
    lv_obj_set_scrollbar_mode(src_ready.imgbtn_engraving,               // close imgbtn scrollbar mode.
                                LV_SCROLLBAR_MODE_OFF);
    lv_imgbtn_set_src(src_ready.imgbtn_engraving, LV_IMGBTN_STATE_RELEASED, NULL, &pic_engraving, NULL);
    lv_imgbtn_set_src(src_ready.imgbtn_engraving, LV_IMGBTN_STATE_PRESSED, NULL, &pic_engraving, NULL);
	lv_imgbtn_set_src(src_ready.imgbtn_engraving, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &pic_engraving, NULL);
	lv_imgbtn_set_src(src_ready.imgbtn_engraving, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &pic_engraving, NULL);
    lv_obj_add_flag(src_ready.imgbtn_engraving, LV_OBJ_FLAG_CHECKABLE);
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


    // Label for engraving
    src_ready.label_engraving = lv_label_create(lv_ui.main_src);
    lv_obj_set_pos(src_ready.label_engraving, 38, 226);
	lv_obj_set_size(src_ready.label_engraving, 114, 32);
    lv_obj_set_scrollbar_mode(src_ready.label_engraving, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(src_ready.label_engraving, "Engraving");
    lv_label_set_long_mode(src_ready.label_engraving, LV_LABEL_LONG_WRAP);

    // Label for control
    src_ready.label_control = lv_label_create(lv_ui.main_src);
    lv_obj_set_pos(src_ready.label_control, 183, 226);
	lv_obj_set_size(src_ready.label_control, 114, 32);
    lv_obj_set_scrollbar_mode(src_ready.label_control, LV_SCROLLBAR_MODE_OFF);
    lv_label_set_text(src_ready.label_control, "Control");
    lv_label_set_long_mode(src_ready.label_control, LV_LABEL_LONG_WRAP);

    // Lable for tool
    src_ready.label_tool = lv_label_create(lv_ui.main_src);  
    lv_obj_set_pos(src_ready.label_tool, 328, 226);
	lv_obj_set_size(src_ready.label_tool, 114, 32);
	lv_obj_set_scrollbar_mode(src_ready.label_tool, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(src_ready.label_tool, "Tool");
	lv_label_set_long_mode(src_ready.label_tool, LV_LABEL_LONG_WRAP);


    if (src_ready.label_style.prop_cnt > 1)
		lv_style_reset(&src_ready.label_style);
	else
		lv_style_init(&src_ready.label_style);
	lv_style_set_radius(&src_ready.label_style, 0);
	lv_style_set_bg_color(&src_ready.label_style, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&src_ready.label_style, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&src_ready.label_style, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&src_ready.label_style, 0);
	lv_style_set_shadow_width(&src_ready.label_style, 0);
	lv_style_set_shadow_color(&src_ready.label_style, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&src_ready.label_style, 255);
	lv_style_set_shadow_spread(&src_ready.label_style, 0);
	lv_style_set_shadow_ofs_x(&src_ready.label_style, 0);
	lv_style_set_shadow_ofs_y(&src_ready.label_style, 0);
	lv_style_set_text_color(&src_ready.label_style, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&src_ready.label_style, &lv_font_montserrat_16);
	lv_style_set_text_letter_space(&src_ready.label_style, 2);
	lv_style_set_text_line_space(&src_ready.label_style, 0);
	lv_style_set_text_align(&src_ready.label_style, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&src_ready.label_style, 0);
	lv_style_set_pad_right(&src_ready.label_style, 0);
	lv_style_set_pad_top(&src_ready.label_style, 8);
	lv_style_set_pad_bottom(&src_ready.label_style, 0);

	lv_obj_add_style(src_ready.label_engraving, &src_ready.label_style, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(src_ready.label_control, &src_ready.label_style, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(src_ready.label_tool, &src_ready.label_style, LV_PART_MAIN|LV_STATE_DEFAULT);
}





