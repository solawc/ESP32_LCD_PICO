#include "draw_engraving.h"


src_engraving_t  src_engraving;


static void event_handler(lv_event_t * e) { 

	lv_event_code_t code = lv_event_get_code(e);

	if(e->target == src_engraving.btn_back) {
		if(code == LV_EVENT_RELEASED) {

			lv_obj_t * act_scr = lv_scr_act();
		    lv_disp_t * d = lv_obj_get_disp(act_scr);

			if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
            {
                lv_obj_clean(lv_ui.main_src);
                draw_ready();
                // lv_scr_load_anim(lv_ui.main_src, LV_SCR_LOAD_ANIM_OVER_LEFT, 50, 50, false);
            }
		}
	}
}



void draw_engraving(void) {

    if (src_engraving.btn_style_1.prop_cnt > 1)
		lv_style_reset(&src_engraving.btn_style_1);
	else
		lv_style_init(&src_engraving.btn_style_1);
	lv_style_set_radius(&src_engraving.btn_style_1, 20);
	lv_style_set_bg_color(&src_engraving.btn_style_1, lv_color_make(0x20, 0x27, 0x3A));
	lv_style_set_bg_grad_color(&src_engraving.btn_style_1, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&src_engraving.btn_style_1, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&src_engraving.btn_style_1, 255);
	lv_style_set_shadow_width(&src_engraving.btn_style_1, 0);
	lv_style_set_shadow_color(&src_engraving.btn_style_1, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&src_engraving.btn_style_1, 0);
	lv_style_set_shadow_spread(&src_engraving.btn_style_1, 0);
	lv_style_set_shadow_ofs_x(&src_engraving.btn_style_1, 0);
	lv_style_set_shadow_ofs_y(&src_engraving.btn_style_1, 0);
	lv_style_set_border_color(&src_engraving.btn_style_1, lv_color_make(0xFF, 0x57, 0x00));
	lv_style_set_border_width(&src_engraving.btn_style_1, 1);
	lv_style_set_border_opa(&src_engraving.btn_style_1, 255);
	lv_style_set_text_color(&src_engraving.btn_style_1, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&src_engraving.btn_style_1, &lv_font_montserrat_16); 
	lv_style_set_text_align(&src_engraving.btn_style_1, LV_TEXT_ALIGN_CENTER);
	
    src_engraving.btn_frame = lv_btn_create(lv_ui.main_src);
	lv_obj_set_pos(src_engraving.btn_frame, 252, 80);
	lv_obj_set_size(src_engraving.btn_frame, 212, 37);
	lv_obj_set_scrollbar_mode(src_engraving.btn_frame, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_style(src_engraving.btn_frame, &src_engraving.btn_style_1, LV_PART_MAIN|LV_STATE_DEFAULT);
	src_engraving.label_frame = lv_label_create(src_engraving.btn_frame);
	lv_label_set_text(src_engraving.label_frame, "Frame");
	lv_obj_set_style_pad_all(src_engraving.btn_frame, 0, LV_STATE_DEFAULT);
	lv_obj_align(src_engraving.label_frame, LV_ALIGN_CENTER, 0, 0);

	src_engraving.btn_home = lv_btn_create(lv_ui.main_src);
	lv_obj_set_pos(src_engraving.btn_home, 252, 134);
	lv_obj_set_size(src_engraving.btn_home, 212, 37);
	lv_obj_set_scrollbar_mode(src_engraving.btn_home, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_style(src_engraving.btn_home, &src_engraving.btn_style_1, LV_PART_MAIN|LV_STATE_DEFAULT);
	src_engraving.label_home = lv_label_create(src_engraving.btn_home);
	lv_label_set_text(src_engraving.label_home, "Home");
	lv_obj_set_style_pad_all(src_engraving.btn_home, 0, LV_STATE_DEFAULT);
	lv_obj_align(src_engraving.label_home, LV_ALIGN_CENTER, 0, 0);

	src_engraving.btn_position = lv_btn_create(lv_ui.main_src);
	lv_obj_set_pos(src_engraving.btn_position, 252, 188);
	lv_obj_set_size(src_engraving.btn_position, 212, 37);
	lv_obj_set_scrollbar_mode(src_engraving.btn_position, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_style(src_engraving.btn_position, &src_engraving.btn_style_1, LV_PART_MAIN|LV_STATE_DEFAULT);
	src_engraving.label_position = lv_label_create(src_engraving.btn_position);
	lv_label_set_text(src_engraving.label_position, "Position");
	lv_obj_set_style_pad_all(src_engraving.btn_position, 0, LV_STATE_DEFAULT);
	lv_obj_align(src_engraving.label_position, LV_ALIGN_CENTER, 0, 0);

	src_engraving.btn_start = lv_btn_create(lv_ui.main_src);
	lv_obj_set_pos(src_engraving.btn_start, 270, 240);
	lv_obj_set_size(src_engraving.btn_start, 175, 50);
	lv_obj_set_scrollbar_mode(src_engraving.btn_start, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_style(src_engraving.btn_start, &src_engraving.btn_style_1, LV_PART_MAIN|LV_STATE_DEFAULT);
	src_engraving.label_start = lv_label_create(src_engraving.btn_start);
	lv_label_set_text(src_engraving.label_start, "Start");
	lv_obj_set_style_pad_all(src_engraving.btn_start, 0, LV_STATE_DEFAULT);
	lv_obj_align(src_engraving.label_start, LV_ALIGN_CENTER, 0, 0);

	src_engraving.btn_back = lv_btn_create(lv_ui.main_src);
	lv_obj_set_pos(src_engraving.btn_back, 364, 13);
	lv_obj_set_size(src_engraving.btn_back, 100, 50);
	lv_obj_set_scrollbar_mode(src_engraving.btn_back, LV_SCROLLBAR_MODE_OFF);
	lv_obj_add_style(src_engraving.btn_back, &src_engraving.btn_style_1, LV_PART_MAIN|LV_STATE_DEFAULT);
	src_engraving.label_back = lv_label_create(src_engraving.btn_back);
	lv_label_set_text(src_engraving.label_back, "Back");
	lv_obj_set_style_pad_all(src_engraving.btn_back, 0, LV_STATE_DEFAULT);
	lv_obj_align(src_engraving.label_back, LV_ALIGN_CENTER, 0, 0);
	lv_obj_add_event_cb(src_engraving.btn_back , event_handler, LV_EVENT_ALL, NULL);
}
