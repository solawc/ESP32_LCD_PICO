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