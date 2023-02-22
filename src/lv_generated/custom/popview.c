#include "popview.h"
#include "custom.h"

lv_obj_t* popview_init(lv_obj_t* parent)
{
    static lv_style_t mbox_bg_style;
    lv_style_init(&mbox_bg_style);
    lv_style_set_bg_color(&mbox_bg_style,  lv_color_make(0x1d, 0x23, 0x32));
    lv_style_set_shadow_color(&mbox_bg_style, lv_color_make(0x1d, 0x23, 0x32));
    lv_style_set_shadow_width(&mbox_bg_style, 0);

    static lv_style_t mbox_btn_style;
    lv_style_init(&mbox_btn_style);
    lv_style_set_border_side(&mbox_btn_style, LV_BORDER_SIDE_TOP);
    

    // static const char * btns[] = {"Back", "Confirm", ""};
    // lv_obj_t* msgbox = lv_msgbox_create(parent, NULL, NULL, btns, false); // false: doesn't have "x" button
	// lv_obj_set_align(msgbox, LV_ALIGN_CENTER);
    // lv_obj_set_size(msgbox, 292, 186);
    // lv_obj_align(msgbox, LV_ALIGN_CENTER, 0, 0);

    // lv_obj_add_style(msgbox, &mbox_bg_style, LV_STATE_DEFAULT);
    // lv_obj_add_style(msgbox, &mbox_btn_style, LV_STATE_DEFAULT);

    static lv_opa_t mask_map[LV_VER_RES_MAX * LV_HOR_RES_MAX];
    static lv_opa_t mask_map_inner[292 * 186];

    /*Create a "8 bit alpha" canvas and clear it*/
    lv_obj_t * canvas = lv_canvas_create(parent);
    lv_canvas_set_buffer(canvas, mask_map, LV_HOR_RES_MAX, LV_VER_RES_MAX, LV_IMG_CF_ALPHA_8BIT);
    lv_obj_set_pos(canvas, 0, 0);
    lv_canvas_fill_bg(canvas, lv_color_black(), LV_OPA_50);

    lv_obj_t * canvas_inner = lv_canvas_create(canvas);
    lv_canvas_set_buffer(canvas_inner, mask_map, 292, 186, LV_IMG_CF_ALPHA_8BIT);
    lv_obj_set_pos(canvas_inner, 94, 67);
    // lv_obj_align(canvas_inner, LV_ALIGN_CENTER, 0, 0);
    lv_canvas_fill_bg(canvas_inner, lv_color_make(0x1d, 0x23, 0x32), LV_OPA_50);

    lv_obj_move_foreground(canvas_inner);
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICK_FOCUSABLE);


    static lv_style_t style_btn;
    lv_style_init(&style_btn);
    lv_style_set_radius(&style_btn, 15);
    // lv_style_set_bg_color(&style_btn, lv_color_make(0x00, 0x00, 0x00));


    lv_obj_t * btn1 = lv_btn_create(parent);
    lv_obj_set_size(btn1, 30, 30);
    lv_obj_set_pos(btn1, 307, 144);
    // lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -80);

    lv_obj_set_style_bg_img_src(btn1, LV_SYMBOL_PLUS, 0);
    lv_obj_add_style(btn1, &style_btn, LV_STATE_DEFAULT);

    lv_obj_t * btn2 = lv_btn_create(parent);
    lv_obj_set_size(btn2, 30, 30);
    lv_obj_set_pos(btn2, 149, 144);
    // lv_obj_align(btn1, LV_ALIGN_CENTER, 0, -80);

    lv_obj_set_style_bg_img_src(btn2, LV_SYMBOL_MINUS, 0);
    lv_obj_add_style(btn2, &style_btn, LV_STATE_DEFAULT);

    return canvas;
}

lv_obj_t* power_popview_init(lv_obj_t* parent)
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, lv_color_hex(0x1d2332));
    lv_style_set_bg_opa(&style, LV_OPA_80);
    // lv_style_set_radius(&style, 5);

    lv_obj_t* objmask = lv_img_create(parent);
    lv_obj_set_size(objmask, LV_HOR_RES_MAX, LV_VER_RES_MAX);
    lv_obj_add_style(objmask, &style, 0);

    lv_obj_t* background = lv_img_create(lv_layer_top());
    lv_obj_set_size(background, 292, 186);
    lv_obj_set_pos(background, 94, 67);

    static lv_style_t background_style;
    lv_style_init(&background_style);
    lv_style_set_bg_color(&background_style, lv_color_hex(0x254b73));
    lv_style_set_bg_opa(&background_style, LV_OPA_COVER);
    lv_style_set_radius(&background_style, 5); 
    lv_obj_add_style(background, &background_style, 0);

    lv_obj_move_foreground(background);
    lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);

	//Write codes wifi_popview_btn_1
	lv_obj_t* wifi_popview_btn_1 = lv_btn_create(background);
	// lv_obj_set_pos(wifi_popview_btn_1, 135, 198);
    lv_obj_align(wifi_popview_btn_1, LV_ALIGN_BOTTOM_MID, -70, 0);
	lv_obj_set_size(wifi_popview_btn_1, 87, 26);
	lv_obj_set_scrollbar_mode(wifi_popview_btn_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_popview_btn_1_main_main_default
	static lv_style_t style_wifi_popview_btn_1_main_main_default;
	if (style_wifi_popview_btn_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_popview_btn_1_main_main_default);
	else
		lv_style_init(&style_wifi_popview_btn_1_main_main_default);
	lv_style_set_radius(&style_wifi_popview_btn_1_main_main_default, 5);
	lv_style_set_bg_color(&style_wifi_popview_btn_1_main_main_default, lv_color_make(0x56, 0x69, 0x7B));
	lv_style_set_bg_grad_color(&style_wifi_popview_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_popview_btn_1_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_popview_btn_1_main_main_default, 255);
	lv_style_set_shadow_width(&style_wifi_popview_btn_1_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_popview_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_popview_btn_1_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_popview_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_popview_btn_1_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_popview_btn_1_main_main_default, 0);
	lv_style_set_border_color(&style_wifi_popview_btn_1_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_wifi_popview_btn_1_main_main_default, 0);
	lv_style_set_border_opa(&style_wifi_popview_btn_1_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_popview_btn_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_wifi_popview_btn_1_main_main_default, &lv_font_Abel_regular_16);
	lv_style_set_text_align(&style_wifi_popview_btn_1_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(wifi_popview_btn_1, &style_wifi_popview_btn_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t* wifi_popview_btn_1_label = lv_label_create(wifi_popview_btn_1);
	lv_label_set_text(wifi_popview_btn_1_label, "Back");
	lv_obj_set_style_pad_all(wifi_popview_btn_1, 0, LV_STATE_DEFAULT);
	lv_obj_align(wifi_popview_btn_1_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes wifi_popview_btn_2
	lv_obj_t* wifi_popview_btn_2 = lv_btn_create(background);
	// lv_obj_set_pos(wifi_popview_btn_2, 259, 198);
    lv_obj_align(wifi_popview_btn_2, LV_ALIGN_BOTTOM_MID, 70, 0);
	lv_obj_set_size(wifi_popview_btn_2, 87, 26);
	lv_obj_set_scrollbar_mode(wifi_popview_btn_2, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_popview_btn_2_main_main_default
	static lv_style_t style_wifi_popview_btn_2_main_main_default;
	if (style_wifi_popview_btn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_popview_btn_2_main_main_default);
	else
		lv_style_init(&style_wifi_popview_btn_2_main_main_default);
	lv_style_set_radius(&style_wifi_popview_btn_2_main_main_default, 5);
	lv_style_set_bg_color(&style_wifi_popview_btn_2_main_main_default, lv_color_make(0xE8, 0x5D, 0x00));
	lv_style_set_bg_grad_color(&style_wifi_popview_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_popview_btn_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_popview_btn_2_main_main_default, 191);
	lv_style_set_shadow_width(&style_wifi_popview_btn_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_popview_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_popview_btn_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_popview_btn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_popview_btn_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_popview_btn_2_main_main_default, 0);
	lv_style_set_border_color(&style_wifi_popview_btn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_border_width(&style_wifi_popview_btn_2_main_main_default, 0);
	lv_style_set_border_opa(&style_wifi_popview_btn_2_main_main_default, 255);
	lv_style_set_text_color(&style_wifi_popview_btn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_wifi_popview_btn_2_main_main_default, &lv_font_simsun_16);
	lv_style_set_text_align(&style_wifi_popview_btn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_obj_add_style(wifi_popview_btn_2, &style_wifi_popview_btn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_t* wifi_popview_btn_2_label = lv_label_create(wifi_popview_btn_2);
	lv_label_set_text(wifi_popview_btn_2_label, "Confirm");
	lv_obj_set_style_pad_all(wifi_popview_btn_2, 0, LV_STATE_DEFAULT);
	lv_obj_align(wifi_popview_btn_2_label, LV_ALIGN_CENTER, 0, 0);

	//Write codes wifi_popview_label_2
	lv_obj_t* wifi_popview_label_2 = lv_label_create(background);
	// lv_obj_set_pos(wifi_popview_label_2, 170, 105);
    lv_obj_align(wifi_popview_label_2, LV_ALIGN_TOP_MID, 0, 0);
	lv_obj_set_size(wifi_popview_label_2, 100, 32);
	lv_obj_set_scrollbar_mode(wifi_popview_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(wifi_popview_label_2, "POWER:");
	lv_label_set_long_mode(wifi_popview_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_wifi_popview_label_2_main_main_default
	static lv_style_t style_wifi_popview_label_2_main_main_default;
	if (style_wifi_popview_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_popview_label_2_main_main_default);
	else
		lv_style_init(&style_wifi_popview_label_2_main_main_default);
	lv_style_set_radius(&style_wifi_popview_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_wifi_popview_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_wifi_popview_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_wifi_popview_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_wifi_popview_label_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_wifi_popview_label_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_popview_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_popview_label_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_popview_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_popview_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_popview_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_wifi_popview_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_wifi_popview_label_2_main_main_default, &lv_font_Alatsi_Regular_22);
	lv_style_set_text_letter_space(&style_wifi_popview_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_wifi_popview_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_wifi_popview_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_wifi_popview_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_wifi_popview_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_wifi_popview_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_wifi_popview_label_2_main_main_default, 0);
	lv_obj_add_style(wifi_popview_label_2, &style_wifi_popview_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes wifi_popview_imgbtn_4
	lv_obj_t* wifi_popview_imgbtn_4 = lv_imgbtn_create(background);
	// lv_obj_set_pos(wifi_popview_imgbtn_4, 149, 144);
    lv_obj_align(wifi_popview_imgbtn_4, LV_ALIGN_LEFT_MID, 70, 0);
	lv_obj_set_size(wifi_popview_imgbtn_4, 25, 25);
	lv_obj_set_scrollbar_mode(wifi_popview_imgbtn_4, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_popview_imgbtn_4_main_main_default
	static lv_style_t style_wifi_popview_imgbtn_4_main_main_default;
	if (style_wifi_popview_imgbtn_4_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_popview_imgbtn_4_main_main_default);
	else
		lv_style_init(&style_wifi_popview_imgbtn_4_main_main_default);
	lv_style_set_shadow_width(&style_wifi_popview_imgbtn_4_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_popview_imgbtn_4_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_popview_imgbtn_4_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_popview_imgbtn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_popview_imgbtn_4_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_popview_imgbtn_4_main_main_default, 0);
	lv_style_set_text_color(&style_wifi_popview_imgbtn_4_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_wifi_popview_imgbtn_4_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_wifi_popview_imgbtn_4_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_wifi_popview_imgbtn_4_main_main_default, 0);
	lv_style_set_img_opa(&style_wifi_popview_imgbtn_4_main_main_default, 255);
	lv_obj_add_style(wifi_popview_imgbtn_4, &style_wifi_popview_imgbtn_4_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_wifi_popview_imgbtn_4_main_main_pressed
	static lv_style_t style_wifi_popview_imgbtn_4_main_main_pressed;
	if (style_wifi_popview_imgbtn_4_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_wifi_popview_imgbtn_4_main_main_pressed);
	else
		lv_style_init(&style_wifi_popview_imgbtn_4_main_main_pressed);
	lv_style_set_shadow_width(&style_wifi_popview_imgbtn_4_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_wifi_popview_imgbtn_4_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_popview_imgbtn_4_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_wifi_popview_imgbtn_4_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_popview_imgbtn_4_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_popview_imgbtn_4_main_main_pressed, 0);
	lv_style_set_text_color(&style_wifi_popview_imgbtn_4_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_wifi_popview_imgbtn_4_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_wifi_popview_imgbtn_4_main_main_pressed, 0);
	lv_style_set_img_opa(&style_wifi_popview_imgbtn_4_main_main_pressed, 255);
	lv_obj_add_style(wifi_popview_imgbtn_4, &style_wifi_popview_imgbtn_4_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_wifi_popview_imgbtn_4_main_main_checked
	static lv_style_t style_wifi_popview_imgbtn_4_main_main_checked;
	if (style_wifi_popview_imgbtn_4_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_wifi_popview_imgbtn_4_main_main_checked);
	else
		lv_style_init(&style_wifi_popview_imgbtn_4_main_main_checked);
	lv_style_set_shadow_width(&style_wifi_popview_imgbtn_4_main_main_checked, 0);
	lv_style_set_shadow_color(&style_wifi_popview_imgbtn_4_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_popview_imgbtn_4_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_wifi_popview_imgbtn_4_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_popview_imgbtn_4_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_popview_imgbtn_4_main_main_checked, 0);
	lv_style_set_text_color(&style_wifi_popview_imgbtn_4_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_wifi_popview_imgbtn_4_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_wifi_popview_imgbtn_4_main_main_checked, 0);
	lv_style_set_img_opa(&style_wifi_popview_imgbtn_4_main_main_checked, 255);
	lv_obj_add_style(wifi_popview_imgbtn_4, &style_wifi_popview_imgbtn_4_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(wifi_popview_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_sub_alpha_25x25, NULL);
	lv_obj_add_flag(wifi_popview_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);

	//Write codes wifi_popview_imgbtn_5
	lv_obj_t* wifi_popview_imgbtn_5 = lv_imgbtn_create(background);
	// lv_obj_set_pos(wifi_popview_imgbtn_5, 307, 144);
    lv_obj_align(wifi_popview_imgbtn_5, LV_ALIGN_RIGHT_MID, -70, 0);
	lv_obj_set_size(wifi_popview_imgbtn_5, 25, 25);
	lv_obj_set_scrollbar_mode(wifi_popview_imgbtn_5, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_wifi_popview_imgbtn_5_main_main_default
	static lv_style_t style_wifi_popview_imgbtn_5_main_main_default;
	if (style_wifi_popview_imgbtn_5_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_wifi_popview_imgbtn_5_main_main_default);
	else
		lv_style_init(&style_wifi_popview_imgbtn_5_main_main_default);
	lv_style_set_shadow_width(&style_wifi_popview_imgbtn_5_main_main_default, 0);
	lv_style_set_shadow_color(&style_wifi_popview_imgbtn_5_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_popview_imgbtn_5_main_main_default, 255);
	lv_style_set_shadow_spread(&style_wifi_popview_imgbtn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_popview_imgbtn_5_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_popview_imgbtn_5_main_main_default, 0);
	lv_style_set_text_color(&style_wifi_popview_imgbtn_5_main_main_default, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_align(&style_wifi_popview_imgbtn_5_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_wifi_popview_imgbtn_5_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_wifi_popview_imgbtn_5_main_main_default, 0);
	lv_style_set_img_opa(&style_wifi_popview_imgbtn_5_main_main_default, 255);
	lv_obj_add_style(wifi_popview_imgbtn_5, &style_wifi_popview_imgbtn_5_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style state: LV_STATE_PRESSED for style_wifi_popview_imgbtn_5_main_main_pressed
	static lv_style_t style_wifi_popview_imgbtn_5_main_main_pressed;
	if (style_wifi_popview_imgbtn_5_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_wifi_popview_imgbtn_5_main_main_pressed);
	else
		lv_style_init(&style_wifi_popview_imgbtn_5_main_main_pressed);
	lv_style_set_shadow_width(&style_wifi_popview_imgbtn_5_main_main_pressed, 0);
	lv_style_set_shadow_color(&style_wifi_popview_imgbtn_5_main_main_pressed, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_popview_imgbtn_5_main_main_pressed, 255);
	lv_style_set_shadow_spread(&style_wifi_popview_imgbtn_5_main_main_pressed, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_popview_imgbtn_5_main_main_pressed, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_popview_imgbtn_5_main_main_pressed, 0);
	lv_style_set_text_color(&style_wifi_popview_imgbtn_5_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_wifi_popview_imgbtn_5_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_wifi_popview_imgbtn_5_main_main_pressed, 0);
	lv_style_set_img_opa(&style_wifi_popview_imgbtn_5_main_main_pressed, 255);
	lv_obj_add_style(wifi_popview_imgbtn_5, &style_wifi_popview_imgbtn_5_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED);

	//Write style state: LV_STATE_CHECKED for style_wifi_popview_imgbtn_5_main_main_checked
	static lv_style_t style_wifi_popview_imgbtn_5_main_main_checked;
	if (style_wifi_popview_imgbtn_5_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_wifi_popview_imgbtn_5_main_main_checked);
	else
		lv_style_init(&style_wifi_popview_imgbtn_5_main_main_checked);
	lv_style_set_shadow_width(&style_wifi_popview_imgbtn_5_main_main_checked, 0);
	lv_style_set_shadow_color(&style_wifi_popview_imgbtn_5_main_main_checked, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_wifi_popview_imgbtn_5_main_main_checked, 255);
	lv_style_set_shadow_spread(&style_wifi_popview_imgbtn_5_main_main_checked, 0);
	lv_style_set_shadow_ofs_x(&style_wifi_popview_imgbtn_5_main_main_checked, 0);
	lv_style_set_shadow_ofs_y(&style_wifi_popview_imgbtn_5_main_main_checked, 0);
	lv_style_set_text_color(&style_wifi_popview_imgbtn_5_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_img_recolor(&style_wifi_popview_imgbtn_5_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_wifi_popview_imgbtn_5_main_main_checked, 0);
	lv_style_set_img_opa(&style_wifi_popview_imgbtn_5_main_main_checked, 255);
	lv_obj_add_style(wifi_popview_imgbtn_5, &style_wifi_popview_imgbtn_5_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
	lv_imgbtn_set_src(wifi_popview_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_plus_alpha_25x25, NULL);
	lv_obj_add_flag(wifi_popview_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);

    return objmask;
}

void power_popview_deinit(lv_obj_t* parent){
  lv_obj_clean(parent);
  lv_obj_del(parent);
}

void power_popview_test_case()
{
  lv_obj_t* obj = power_popview_init(lv_scr_act());
      
}
