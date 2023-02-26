#include "popview.h"
#include "custom.h"

static lv_obj_t* objmask = NULL;

lv_obj_t* objmask_init()
{
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, lv_color_hex(0x1d2332));
    lv_style_set_bg_opa(&style, LV_OPA_80);
    // lv_style_set_radius(&style, 5);

    objmask = lv_img_create(lv_layer_top());
    lv_obj_set_size(objmask, LV_HOR_RES_MAX, LV_VER_RES_MAX);
    lv_obj_add_style(objmask, &style, 0);
	
	return objmask;
}

void objmask_clean()
{
  lv_obj_clean(objmask);
}

void objmask_deinit()
{
  lv_obj_del(objmask);
  objmask = NULL;
}

lv_obj_t* power_popview_init(lv_obj_t* parent)
{
    lv_obj_t* background = lv_img_create(parent);
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

void power_popview_test_case()
{
	objmask_init();
  	lv_obj_t* obj = power_popview_init(objmask);
      
}

lv_obj_t* wifi_linking_popview_init(lv_obj_t* parent)
{
    lv_obj_t* background = lv_img_create(parent);
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

	//Write codes tool_wifi_label_2
	lv_obj_t* tool_wifi_label_2 = lv_label_create(background);
	lv_obj_align(tool_wifi_label_2, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_size(tool_wifi_label_2, 212, 31);
	lv_obj_set_scrollbar_mode(tool_wifi_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(tool_wifi_label_2, "Link, please wait");
	lv_label_set_long_mode(tool_wifi_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_wifi_label_2_main_main_default
	static lv_style_t style_tool_wifi_label_2_main_main_default;
	if (style_tool_wifi_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_wifi_label_2_main_main_default);
	else
		lv_style_init(&style_tool_wifi_label_2_main_main_default);
	lv_style_set_radius(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_wifi_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_wifi_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_wifi_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_tool_wifi_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_tool_wifi_label_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_tool_wifi_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_wifi_label_2_main_main_default, &lv_font_Acme_Regular_16);
	lv_style_set_text_letter_space(&style_tool_wifi_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_tool_wifi_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_wifi_label_2_main_main_default, 0);
	lv_obj_add_style(tool_wifi_label_2, &style_tool_wifi_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
}

void wifi_linking_popview_test_case()
{
	objmask_init();
  	lv_obj_t* obj = wifi_linking_popview_init(objmask);
}

lv_obj_t* wifi_password_error_popview_init(lv_obj_t* parent)
{
    lv_obj_t* background = lv_img_create(parent);
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

	//Write codes tool_wifi_label_2
	lv_obj_t* tool_wifi_label_2 = lv_label_create(background);
	lv_obj_align(tool_wifi_label_2, LV_ALIGN_BOTTOM_MID, 0, 0);
	lv_obj_set_size(tool_wifi_label_2, 227, 31);
	lv_obj_set_scrollbar_mode(tool_wifi_label_2, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(tool_wifi_label_2, "Passwork error, link failed");
	lv_label_set_long_mode(tool_wifi_label_2, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_tool_wifi_label_2_main_main_default
	static lv_style_t style_tool_wifi_label_2_main_main_default;
	if (style_tool_wifi_label_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_wifi_label_2_main_main_default);
	else
		lv_style_init(&style_tool_wifi_label_2_main_main_default);
	lv_style_set_radius(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_bg_color(&style_tool_wifi_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_tool_wifi_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_tool_wifi_label_2_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_width(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_color(&style_tool_wifi_label_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_tool_wifi_label_2_main_main_default, 255);
	lv_style_set_shadow_spread(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_text_color(&style_tool_wifi_label_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_tool_wifi_label_2_main_main_default, &lv_font_Acme_Regular_16);
	lv_style_set_text_letter_space(&style_tool_wifi_label_2_main_main_default, 2);
	lv_style_set_text_line_space(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_text_align(&style_tool_wifi_label_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_right(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_top(&style_tool_wifi_label_2_main_main_default, 0);
	lv_style_set_pad_bottom(&style_tool_wifi_label_2_main_main_default, 0);
	lv_obj_add_style(tool_wifi_label_2, &style_tool_wifi_label_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes tool_wifi_img_1
	lv_obj_t* tool_wifi_img_1 = lv_img_create(background);
	lv_obj_align(tool_wifi_img_1, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_size(tool_wifi_img_1, 76, 58);
	lv_obj_set_scrollbar_mode(tool_wifi_img_1, LV_SCROLLBAR_MODE_OFF);

	//Write style state: LV_STATE_DEFAULT for style_tool_wifi_img_1_main_main_default
	static lv_style_t style_tool_wifi_img_1_main_main_default;
	if (style_tool_wifi_img_1_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_tool_wifi_img_1_main_main_default);
	else
		lv_style_init(&style_tool_wifi_img_1_main_main_default);
	lv_style_set_img_recolor(&style_tool_wifi_img_1_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_tool_wifi_img_1_main_main_default, 0);
	lv_style_set_img_opa(&style_tool_wifi_img_1_main_main_default, 255);
	lv_obj_add_style(tool_wifi_img_1, &style_tool_wifi_img_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_add_flag(tool_wifi_img_1, LV_OBJ_FLAG_CLICKABLE);
	lv_img_set_src(tool_wifi_img_1,&_wifi_disconnect_76x58);
	lv_img_set_pivot(tool_wifi_img_1, 50,50);
	lv_img_set_angle(tool_wifi_img_1, 0);
}

void wifi_password_error_popview_test_case()
{
	objmask_init();
  	lv_obj_t* obj = wifi_password_error_popview_init(objmask);
}

static void obj_bar_anim_exec_callback(void * bar, int32_t value)
{
    if (bar != NULL)
    {
        lv_bar_set_value((lv_obj_t *)bar, value, LV_ANIM_ON); // 设置进度条对象的值
    }
}

lv_obj_t* file_download_popview_init(lv_obj_t* parent)
{
    lv_obj_t* background = lv_img_create(parent);
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

	//Write codes file_download_label
	lv_obj_t* file_download_label = lv_label_create(background);
	lv_obj_align(file_download_label, LV_ALIGN_CENTER, 0, -24);
	lv_obj_set_size(file_download_label, 212, 31);
	lv_obj_set_scrollbar_mode(file_download_label, LV_SCROLLBAR_MODE_OFF);
	lv_label_set_text(file_download_label, "Receiving file");
	lv_label_set_long_mode(file_download_label, LV_LABEL_LONG_WRAP);

	//Write style state: LV_STATE_DEFAULT for style_file_download_label_main_main_default
	static lv_style_t style_file_download_label_main_main_default;
	if (style_file_download_label_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_file_download_label_main_main_default);
	else
		lv_style_init(&style_file_download_label_main_main_default);
	lv_style_set_radius(&style_file_download_label_main_main_default, 0);
	lv_style_set_bg_color(&style_file_download_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_color(&style_file_download_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_bg_grad_dir(&style_file_download_label_main_main_default, LV_GRAD_DIR_NONE);
	lv_style_set_bg_opa(&style_file_download_label_main_main_default, 0);
	lv_style_set_shadow_width(&style_file_download_label_main_main_default, 0);
	lv_style_set_shadow_color(&style_file_download_label_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_shadow_opa(&style_file_download_label_main_main_default, 255);
	lv_style_set_shadow_spread(&style_file_download_label_main_main_default, 0);
	lv_style_set_shadow_ofs_x(&style_file_download_label_main_main_default, 0);
	lv_style_set_shadow_ofs_y(&style_file_download_label_main_main_default, 0);
	lv_style_set_text_color(&style_file_download_label_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_text_font(&style_file_download_label_main_main_default, &lv_font_Acme_Regular_16);
	lv_style_set_text_letter_space(&style_file_download_label_main_main_default, 2);
	lv_style_set_text_line_space(&style_file_download_label_main_main_default, 0);
	lv_style_set_text_align(&style_file_download_label_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_pad_left(&style_file_download_label_main_main_default, 0);
	lv_style_set_pad_right(&style_file_download_label_main_main_default, 0);
	lv_style_set_pad_top(&style_file_download_label_main_main_default, 0);
	lv_style_set_pad_bottom(&style_file_download_label_main_main_default, 0);
	lv_obj_add_style(file_download_label, &style_file_download_label_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
 
    static lv_style_t style_indic;
    lv_style_init(&style_indic);
    lv_style_reset(&style_indic);

    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER); // 设置背景不透明度
    lv_style_set_bg_color(&style_indic, lv_color_hex(0x35B935));
    lv_style_set_radius(&style_indic, 3);
 
    lv_obj_t * obj_bar = lv_bar_create(background);
    if (obj_bar != NULL)
    {
        lv_obj_remove_style_all(obj_bar);  // 清除所有样式
        // lv_obj_add_style(obj_bar, &style_bg, 0);
        lv_obj_add_style(obj_bar, &style_indic, LV_PART_INDICATOR);
        lv_obj_set_size(obj_bar, 100, 30);
        lv_obj_align(obj_bar, LV_ALIGN_CENTER, 0, 30);
 
        lv_anim_t anim;
        lv_anim_init(&anim); // 初始化动画
        lv_anim_set_exec_cb(&anim, obj_bar_anim_exec_callback); // 添加回调函数
        lv_anim_set_time(&anim, 5000); // 设置动画时长
        lv_anim_set_var(&anim, obj_bar); // 动画绑定对象
        lv_anim_set_values(&anim, 0, 100); // 设置开始值和结束值
        lv_anim_set_repeat_count(&anim, LV_ANIM_REPEAT_INFINITE); // 重复次数，默认值为1 LV_ANIM_REPEAT_INFINIT用于无限重复
        lv_anim_start(&anim); // 应用动画效果
    }
}

void file_download_popview_test_case()
{
	objmask_init();
  	lv_obj_t* obj = file_download_popview_init(objmask);
}