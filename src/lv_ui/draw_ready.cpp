#include "draw_ready.h"

src_ready_t src_ready;

static void event_handler(lv_event_t * e) {

    lv_event_code_t code = lv_event_get_code(e);

    if(e->target == src_ready.imgbtn_engraving ) {
        if(code == LV_EVENT_RELEASED) {
            debug_send(CLIENT_SERIAL, "engraving Clicked\n");

            lv_obj_t * act_scr = lv_scr_act();
		    lv_disp_t * d = lv_obj_get_disp(act_scr);

            if (d->prev_scr == NULL && (d->scr_to_load == NULL || d->scr_to_load == act_scr))
            {
                lv_obj_clean(my_ui.main_page);
                // draw_engraving();
                // lv_scr_load_anim(lv_ui.main_src, LV_SCR_LOAD_ANIM_OVER_LEFT, 100, 100, true);
                setup_scr_engraving_page(&my_ui);
            }
        }
    }else if(e->target == src_ready.imgbtn_control) {
        if(code == LV_EVENT_RELEASED) {
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
    lv_imgbtn_set_src(src_ready.imgbtn_engraving, LV_IMGBTN_STATE_PRESSED,  NULL, &pic_engraving, NULL);
	lv_imgbtn_set_src(src_ready.imgbtn_engraving, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &pic_engraving, NULL);
	lv_imgbtn_set_src(src_ready.imgbtn_engraving, LV_IMGBTN_STATE_CHECKED_PRESSED,  NULL, &pic_engraving, NULL);
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

    // add style to label.
	lv_obj_add_style(src_ready.label_engraving, &src_ready.label_style, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(src_ready.label_control,   &src_ready.label_style, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(src_ready.label_tool,      &src_ready.label_style, LV_PART_MAIN|LV_STATE_DEFAULT);
}


void setup_scr_main_page(ui_t *ui) { 
    //Write codes main_page
	ui->main_page = lv_obj_create(NULL);
    ui->main_page = lv_scr_act();

	lv_obj_set_scrollbar_mode(ui->main_page, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_main_page_main_main_default
	static lv_style_t style_main_page_main_main_default;
	if (style_main_page_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_page_main_main_default);
	else
		lv_style_init(&style_main_page_main_main_default);
	lv_style_set_bg_color(&style_main_page_main_main_default, lv_color_make(0x1D, 0x23, 0x32));
	lv_style_set_bg_opa(&style_main_page_main_main_default, 255);
	lv_obj_add_style(ui->main_page, &style_main_page_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_imgbtn_1
	ui->main_page_imgbtn_1 = lv_imgbtn_create(ui->main_page);
	lv_obj_set_pos(ui->main_page_imgbtn_1, 38, 112);
	lv_obj_set_size(ui->main_page_imgbtn_1, 114, 114);
	lv_obj_set_scrollbar_mode(ui->main_page_imgbtn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_main_page_imgbtn_1_main_main_default
	static lv_style_t style_main_page_imgbtn_1_main_main_default;
	if (style_main_page_imgbtn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_page_imgbtn_1_main_main_default);
	else
		lv_style_init(&style_main_page_imgbtn_1_main_main_default);
	lv_style_set_shadow_width(&style_main_page_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_main_page_imgbtn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_spread(&style_main_page_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_imgbtn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_imgbtn_1_main_main_default, 0);
	lv_style_set_text_color(&style_main_page_imgbtn_1_main_main_default, lv_color_make(0xee, 0xe1, 0xe1));
	lv_style_set_text_align(&style_main_page_imgbtn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_main_page_imgbtn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_main_page_imgbtn_1_main_main_default, 0);
	lv_style_set_img_opa(&style_main_page_imgbtn_1_main_main_default, 255);
	lv_obj_add_style(ui->main_page_imgbtn_1, &style_main_page_imgbtn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_main_page_imgbtn_1_main_main_pressed
	static lv_style_t style_main_page_imgbtn_1_main_main_pressed;
	if (style_main_page_imgbtn_1_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_main_page_imgbtn_1_main_main_pressed);
	else
		lv_style_init(&style_main_page_imgbtn_1_main_main_pressed);
	lv_style_set_shadow_width(&style_main_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_main_page_imgbtn_1_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_imgbtn_1_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_main_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_text_color(&style_main_page_imgbtn_1_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_main_page_imgbtn_1_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_main_page_imgbtn_1_main_main_pressed, 0);
	lv_style_set_img_opa(&style_main_page_imgbtn_1_main_main_pressed, 255);
	lv_obj_add_style(ui->main_page_imgbtn_1, &style_main_page_imgbtn_1_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_main_page_imgbtn_1_main_main_checked
	static lv_style_t style_main_page_imgbtn_1_main_main_checked;
	if (style_main_page_imgbtn_1_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_main_page_imgbtn_1_main_main_checked);
	else
		lv_style_init(&style_main_page_imgbtn_1_main_main_checked);
	lv_style_set_shadow_width(&style_main_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_color(&style_main_page_imgbtn_1_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_imgbtn_1_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_main_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_text_color(&style_main_page_imgbtn_1_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_main_page_imgbtn_1_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_main_page_imgbtn_1_main_main_checked, 0);
	lv_style_set_img_opa(&style_main_page_imgbtn_1_main_main_checked, 255);
	lv_obj_add_style(ui->main_page_imgbtn_1, &style_main_page_imgbtn_1_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->main_page_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &pic_engraving, NULL);
	lv_imgbtn_set_src(ui->main_page_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &pic_engraving, NULL);
	lv_imgbtn_set_src(ui->main_page_imgbtn_1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &pic_engraving, NULL);
	lv_imgbtn_set_src(ui->main_page_imgbtn_1, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &pic_engraving, NULL);
	lv_obj_add_flag(ui->main_page_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);

	//Write codes main_page_imgbtn_2
	ui->main_page_imgbtn_2 = lv_imgbtn_create(ui->main_page);
	lv_obj_set_pos(ui->main_page_imgbtn_2, 183, 112);
	lv_obj_set_size(ui->main_page_imgbtn_2, 114, 114);
	lv_obj_set_scrollbar_mode(ui->main_page_imgbtn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_main_page_imgbtn_2_main_main_default
	static lv_style_t style_main_page_imgbtn_2_main_main_default;
	if (style_main_page_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_page_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_main_page_imgbtn_2_main_main_default);
	lv_style_set_shadow_width(&style_main_page_imgbtn_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_main_page_imgbtn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_imgbtn_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_main_page_imgbtn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_imgbtn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_imgbtn_2_main_main_default, 0);
	lv_style_set_text_color(&style_main_page_imgbtn_2_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_main_page_imgbtn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_main_page_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_main_page_imgbtn_2_main_main_default, 0);
	lv_style_set_img_opa(&style_main_page_imgbtn_2_main_main_default, 255);
	lv_obj_add_style(ui->main_page_imgbtn_2, &style_main_page_imgbtn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_main_page_imgbtn_2_main_main_pressed
	static lv_style_t style_main_page_imgbtn_2_main_main_pressed;
	if (style_main_page_imgbtn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_main_page_imgbtn_2_main_main_pressed);
	else
		lv_style_init(&style_main_page_imgbtn_2_main_main_pressed);
	lv_style_set_shadow_width(&style_main_page_imgbtn_2_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_main_page_imgbtn_2_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_imgbtn_2_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_main_page_imgbtn_2_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_imgbtn_2_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_imgbtn_2_main_main_pressed, 0);
	lv_style_set_text_color(&style_main_page_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_main_page_imgbtn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_main_page_imgbtn_2_main_main_pressed, 0);
	lv_style_set_img_opa(&style_main_page_imgbtn_2_main_main_pressed, 255);
	lv_obj_add_style(ui->main_page_imgbtn_2, &style_main_page_imgbtn_2_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_main_page_imgbtn_2_main_main_checked
	static lv_style_t style_main_page_imgbtn_2_main_main_checked;
	if (style_main_page_imgbtn_2_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_main_page_imgbtn_2_main_main_checked);
	else
		lv_style_init(&style_main_page_imgbtn_2_main_main_checked);
	lv_style_set_shadow_width(&style_main_page_imgbtn_2_main_main_checked, 0);
	lv_style_set_shadow_color(&style_main_page_imgbtn_2_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_imgbtn_2_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_main_page_imgbtn_2_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_imgbtn_2_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_imgbtn_2_main_main_checked, 0);
	lv_style_set_text_color(&style_main_page_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_main_page_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_main_page_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_main_page_imgbtn_2_main_main_checked, 255);
	lv_obj_add_style(ui->main_page_imgbtn_2, &style_main_page_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->main_page_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &pic_control, NULL);
	lv_imgbtn_set_src(ui->main_page_imgbtn_2, LV_IMGBTN_STATE_PRESSED, NULL, &pic_control, NULL);
	lv_imgbtn_set_src(ui->main_page_imgbtn_2, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &pic_control, NULL);
	lv_imgbtn_set_src(ui->main_page_imgbtn_2, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &pic_control, NULL);
	lv_obj_add_flag(ui->main_page_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);

	//Write codes main_page_imgbtn_3
	ui->main_page_imgbtn_3 = lv_imgbtn_create(ui->main_page);
	lv_obj_set_pos(ui->main_page_imgbtn_3, 328, 112);
	lv_obj_set_size(ui->main_page_imgbtn_3, 114, 114);
	lv_obj_set_scrollbar_mode(ui->main_page_imgbtn_3, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_main_page_imgbtn_3_main_main_default
	static lv_style_t style_main_page_imgbtn_3_main_main_default;
	if (style_main_page_imgbtn_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_page_imgbtn_3_main_main_default);
	else
		lv_style_init(&style_main_page_imgbtn_3_main_main_default);
	lv_style_set_shadow_width(&style_main_page_imgbtn_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_main_page_imgbtn_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_imgbtn_3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_main_page_imgbtn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_imgbtn_3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_imgbtn_3_main_main_default, 0);
	lv_style_set_text_color(&style_main_page_imgbtn_3_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_main_page_imgbtn_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_main_page_imgbtn_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_main_page_imgbtn_3_main_main_default, 0);
	lv_style_set_img_opa(&style_main_page_imgbtn_3_main_main_default, 255);
	lv_obj_add_style(ui->main_page_imgbtn_3, &style_main_page_imgbtn_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_main_page_imgbtn_3_main_main_pressed
	static lv_style_t style_main_page_imgbtn_3_main_main_pressed;
	if (style_main_page_imgbtn_3_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_main_page_imgbtn_3_main_main_pressed);
	else
		lv_style_init(&style_main_page_imgbtn_3_main_main_pressed);
	lv_style_set_shadow_width(&style_main_page_imgbtn_3_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_main_page_imgbtn_3_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_imgbtn_3_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_main_page_imgbtn_3_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_imgbtn_3_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_imgbtn_3_main_main_pressed, 0);
	lv_style_set_text_color(&style_main_page_imgbtn_3_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_main_page_imgbtn_3_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_main_page_imgbtn_3_main_main_pressed, 0);
	lv_style_set_img_opa(&style_main_page_imgbtn_3_main_main_pressed, 255);
	lv_obj_add_style(ui->main_page_imgbtn_3, &style_main_page_imgbtn_3_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_main_page_imgbtn_3_main_main_checked
	static lv_style_t style_main_page_imgbtn_3_main_main_checked;
	if (style_main_page_imgbtn_3_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_main_page_imgbtn_3_main_main_checked);
	else
		lv_style_init(&style_main_page_imgbtn_3_main_main_checked);
	lv_style_set_shadow_width(&style_main_page_imgbtn_3_main_main_checked, 0);
	lv_style_set_shadow_color(&style_main_page_imgbtn_3_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_imgbtn_3_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_main_page_imgbtn_3_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_imgbtn_3_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_imgbtn_3_main_main_checked, 0);
	lv_style_set_text_color(&style_main_page_imgbtn_3_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_main_page_imgbtn_3_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_main_page_imgbtn_3_main_main_checked, 0);
	lv_style_set_img_opa(&style_main_page_imgbtn_3_main_main_checked, 255);
	lv_obj_add_style(ui->main_page_imgbtn_3, &style_main_page_imgbtn_3_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(ui->main_page_imgbtn_3, LV_IMGBTN_STATE_RELEASED, NULL, &pic_tool, NULL);
	lv_imgbtn_set_src(ui->main_page_imgbtn_3, LV_IMGBTN_STATE_PRESSED, NULL, &pic_tool, NULL);
	lv_imgbtn_set_src(ui->main_page_imgbtn_3, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &pic_tool, NULL);
	lv_imgbtn_set_src(ui->main_page_imgbtn_3, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &pic_tool, NULL);
	lv_obj_add_flag(ui->main_page_imgbtn_3, LV_OBJ_FLAG_CHECKABLE);

	//Write codes main_page_label_1
	ui->main_page_label_1 = lv_label_create(ui->main_page);
	lv_obj_set_pos(ui->main_page_label_1, 38, 226);
	lv_obj_set_size(ui->main_page_label_1, 114, 32);
	lv_obj_set_scrollbar_mode(ui->main_page_label_1, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->main_page_label_1, "Engraving");
	lv_label_set_long_mode(ui->main_page_label_1, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_main_page_label_1_main_main_default
	static lv_style_t style_main_page_label_1_main_main_default;
	if (style_main_page_label_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_page_label_1_main_main_default);
	else
		lv_style_init(&style_main_page_label_1_main_main_default);
	lv_style_set_radius(&style_main_page_label_1_main_main_default, 0);
	lv_style_set_bg_color(&style_main_page_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_main_page_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_main_page_label_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_main_page_label_1_main_main_default, 0);
	lv_style_set_shadow_width(&style_main_page_label_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_main_page_label_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_label_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_main_page_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_label_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_label_1_main_main_default, 0);
	lv_style_set_text_color(&style_main_page_label_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_main_page_label_1_main_main_default, &lv_font_montserrat_16);
	lv_style_set_text_letter_space(&style_main_page_label_1_main_main_default, 2);
	lv_style_set_text_line_space(&style_main_page_label_1_main_main_default, 0);
	lv_style_set_text_align(&style_main_page_label_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_main_page_label_1_main_main_default, 0);
	lv_style_set_pad_right(&style_main_page_label_1_main_main_default, 0);
	lv_style_set_pad_top(&style_main_page_label_1_main_main_default, 8);
	lv_style_set_pad_bottom(&style_main_page_label_1_main_main_default, 0);
	lv_obj_add_style(ui->main_page_label_1, &style_main_page_label_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_label_2
	ui->main_page_label_2 = lv_label_create(ui->main_page);
	lv_obj_set_pos(ui->main_page_label_2, 183, 226);
	lv_obj_set_size(ui->main_page_label_2, 114, 32);
	lv_obj_set_scrollbar_mode(ui->main_page_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->main_page_label_2, "Control");
	lv_label_set_long_mode(ui->main_page_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_main_page_label_2_main_main_default
	static lv_style_t style_main_page_label_2_main_main_default;
	if (style_main_page_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_page_label_2_main_main_default);
	else
		lv_style_init(&style_main_page_label_2_main_main_default);
	lv_style_set_radius(&style_main_page_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_main_page_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_main_page_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_main_page_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_main_page_label_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_main_page_label_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_main_page_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_label_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_main_page_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_main_page_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_main_page_label_2_main_main_default, &lv_font_montserrat_16);
	lv_style_set_text_letter_space(&style_main_page_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_main_page_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_main_page_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_main_page_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_main_page_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_main_page_label_2_main_main_default, 8);
	lv_style_set_pad_bottom(&style_main_page_label_2_main_main_default, 0);
	lv_obj_add_style(ui->main_page_label_2, &style_main_page_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes main_page_label_3
	ui->main_page_label_3 = lv_label_create(ui->main_page);
	lv_obj_set_pos(ui->main_page_label_3, 328, 226);
	lv_obj_set_size(ui->main_page_label_3, 114, 32);
	lv_obj_set_scrollbar_mode(ui->main_page_label_3, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(ui->main_page_label_3, "Tool");
	lv_label_set_long_mode(ui->main_page_label_3, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_main_page_label_3_main_main_default
	static lv_style_t style_main_page_label_3_main_main_default;
	if (style_main_page_label_3_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_main_page_label_3_main_main_default);
	else
		lv_style_init(&style_main_page_label_3_main_main_default);
	lv_style_set_radius(&style_main_page_label_3_main_main_default, 0);
	lv_style_set_bg_color(&style_main_page_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_main_page_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_main_page_label_3_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_main_page_label_3_main_main_default, 0);
	lv_style_set_shadow_width(&style_main_page_label_3_main_main_default, 0);
	lv_style_set_shadow_color(&style_main_page_label_3_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_main_page_label_3_main_main_default, 255);
	lv_style_set_shadow_spread(&style_main_page_label_3_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_main_page_label_3_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_main_page_label_3_main_main_default, 0);
	lv_style_set_text_color(&style_main_page_label_3_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_main_page_label_3_main_main_default, &lv_font_montserrat_16);
	lv_style_set_text_letter_space(&style_main_page_label_3_main_main_default, 2);
	lv_style_set_text_line_space(&style_main_page_label_3_main_main_default, 0);
	lv_style_set_text_align(&style_main_page_label_3_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_main_page_label_3_main_main_default, 0);
	lv_style_set_pad_right(&style_main_page_label_3_main_main_default, 0);
	lv_style_set_pad_top(&style_main_page_label_3_main_main_default, 8);
	lv_style_set_pad_bottom(&style_main_page_label_3_main_main_default, 0);
	lv_obj_add_style(ui->main_page_label_3, &style_main_page_label_3_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    // lv_obj_add_event_cb(ui->main_page_imgbtn_1, main_page_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->main_page_imgbtn_1, event_handler, LV_EVENT_ALL, ui);
} 


