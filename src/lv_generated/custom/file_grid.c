#include "file_grid.h"
#include "gui_guider.h"

static void event_cb(lv_event_t* e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn_obj = lv_event_get_target(e);
    uint32_t child_cnt = lv_obj_get_child_cnt(btn_obj);
    lv_obj_t* label = lv_obj_get_child(btn_obj, child_cnt-1); 

    if(code == LV_EVENT_CLICKED){
        printf("%s\n", lv_label_get_text(label));
    }
}

static void test_event_cb(lv_event_t* e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn_obj = lv_event_get_target(e);
    lv_obj_t* cont = lv_event_get_user_data(e);

    uint32_t child_cnt = lv_obj_get_child_cnt(cont);

    if(code == LV_EVENT_PRESSED){
        lv_obj_set_style_bg_color(btn_obj, lv_palette_main(LV_PALETTE_RED), 0);
        
      //   lv_obj_clean(cont);

      // lv_obj_t * label;
      // lv_obj_t * obj;


      // uint32_t i;
      // for(i = 0; i < 4; i++) {
      //     uint8_t col = i % 2;
      //     uint8_t row = i / 2;

      //     //Write codes engraving_imgbtn_2
      //     obj = lv_imgbtn_create(cont);
      //     // lv_obj_set_pos(obj, 255, 82);
      //     // lv_obj_set_size(obj, 206, 33);
      //     lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
      //     lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &_file_alpha_206x33, NULL);
      //     lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
          
      //     /*Stretch the cell horizontally and vertically too
      //     *Set span to 1 to make the cell 1 column/row sized*/
      //     lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, col, 1,
      //                         LV_GRID_ALIGN_STRETCH, row, 1);

      //     label = lv_label_create(obj);
      //     lv_label_set_text_fmt(label, "c%d, r%d", col, row);
      //     lv_obj_center(label);

      //     // lv_obj_add_event_cb(obj, event_cb, LV_EVENT_CLICKED, NULL);   
      // }
    }
    else if(code == LV_EVENT_RELEASED){
        lv_obj_set_style_bg_color(btn_obj, lv_palette_main(LV_PALETTE_BROWN), 0);
    }

}

lv_obj_t* file_grid_init(lv_obj_t* parent){

	static lv_style_t style_cont_main_main_default;
	if (style_cont_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_cont_main_main_default);
	else
		lv_style_init(&style_cont_main_main_default);
	lv_style_set_bg_color(&style_cont_main_main_default, lv_color_make(0x1d, 0x23, 0x32));
	lv_style_set_bg_opa(&style_cont_main_main_default, 255);

    static lv_coord_t col_dsc[] = {206, 206, 206, LV_GRID_TEMPLATE_LAST};
    static lv_coord_t row_dsc[] = {30, 30, 30, 30, LV_GRID_TEMPLATE_LAST};

    /*Create a container with grid*/
    lv_obj_t * cont = lv_obj_create(parent);
    lv_obj_set_style_grid_column_dsc_array(cont, col_dsc, 0);
    lv_obj_set_style_grid_row_dsc_array(cont, row_dsc, 0);
	lv_obj_add_style(cont, &style_cont_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);

    lv_obj_center(cont);
    lv_obj_set_layout(cont, LV_LAYOUT_GRID);
    lv_obj_clear_flag(cont, LV_OBJ_FLAG_SCROLLABLE); // could not scrollable

    lv_obj_set_style_pad_column(cont, 34, 0);   // column space
    lv_obj_set_style_pad_row(cont, 15, 0);      // row space

    return cont;
}

lv_obj_t* file_grid_insert_cell(lv_obj_t* parent, lv_event_cb_t event_cb)
{
    lv_obj_t * obj;
    uint32_t i;

	//Write style state: LV_STATE_DEFAULT for style_engraving_imgbtn_2_main_main_default
	static lv_style_t style_engraving_imgbtn_2_main_main_default;
	if (style_engraving_imgbtn_2_main_main_default.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_2_main_main_default);
	else
		lv_style_init(&style_engraving_imgbtn_2_main_main_default);
	lv_style_set_text_color(&style_engraving_imgbtn_2_main_main_default, lv_color_make(0x21, 0x95, 0xf6));
	lv_style_set_text_align(&style_engraving_imgbtn_2_main_main_default, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_2_main_main_default, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_2_main_main_default, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_2_main_main_default, 255);

	//Write style state: LV_STATE_PRESSED for style_engraving_imgbtn_2_main_main_pressed
	static lv_style_t style_engraving_imgbtn_2_main_main_pressed;
	if (style_engraving_imgbtn_2_main_main_pressed.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_2_main_main_pressed);
	else
		lv_style_init(&style_engraving_imgbtn_2_main_main_pressed);
	lv_style_set_text_color(&style_engraving_imgbtn_2_main_main_pressed, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_2_main_main_pressed, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_2_main_main_pressed, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_2_main_main_pressed, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_2_main_main_pressed, 255);
	

	//Write style state: LV_STATE_CHECKED for style_engraving_imgbtn_2_main_main_checked
	static lv_style_t style_engraving_imgbtn_2_main_main_checked;
	if (style_engraving_imgbtn_2_main_main_checked.prop_cnt > 1)
		lv_style_reset(&style_engraving_imgbtn_2_main_main_checked);
	else
		lv_style_init(&style_engraving_imgbtn_2_main_main_checked);
	lv_style_set_text_color(&style_engraving_imgbtn_2_main_main_checked, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_text_align(&style_engraving_imgbtn_2_main_main_checked, LV_TEXT_ALIGN_CENTER);
	lv_style_set_img_recolor(&style_engraving_imgbtn_2_main_main_checked, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_img_recolor_opa(&style_engraving_imgbtn_2_main_main_checked, 0);
	lv_style_set_img_opa(&style_engraving_imgbtn_2_main_main_checked, 255);

    uint32_t child_cnt = lv_obj_get_child_cnt(parent);   
    // printf("child_cnt:%d\n", child_cnt); 
    uint8_t col = child_cnt % 2;
    uint8_t row = child_cnt / 2;
    // printf("col:%d, row:%d\n", col, row); 

    obj = lv_imgbtn_create(parent);

    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_add_style(obj, &style_engraving_imgbtn_2_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_add_style(obj, &style_engraving_imgbtn_2_main_main_pressed, LV_PART_MAIN|LV_STATE_PRESSED); 
    lv_obj_add_style(obj, &style_engraving_imgbtn_2_main_main_checked, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &_file_alpha_206x33, NULL);
    lv_obj_add_flag(obj, LV_OBJ_FLAG_CHECKABLE);
    
    /*Stretch the cell horizontally and vertically too
        *Set span to 1 to make the cell 1 column/row sized*/
    lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, col, 1,
                            LV_GRID_ALIGN_STRETCH, row, 1);

    lv_obj_add_event_cb(obj, event_cb, LV_EVENT_CLICKED, obj);   

    return obj;
}

void file_grid_set_cell_text(lv_obj_t* parent, const char * text)
{
    uint32_t child_cnt = lv_obj_get_child_cnt(parent); 
    lv_obj_t* obj = lv_obj_get_child(parent, child_cnt-1);
    lv_obj_t * label;

    label = lv_label_create(obj);
    lv_label_set_text(label, text);
    lv_obj_center(label);

}

void file_grid_test_case()
{
  lv_obj_t* obj = file_grid_init(lv_scr_act());
  for (size_t i = 0; i < 4; i++)
  {
    file_grid_insert_cell(obj, event_cb);
    file_grid_set_cell_text(obj, "test");
  }
      
}