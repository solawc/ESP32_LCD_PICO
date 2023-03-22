#ifndef __FILE_GRID_H
#define __FILE_GRID_H


#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

lv_obj_t* file_grid_init(lv_obj_t* parent);
lv_obj_t* file_grid_insert_cell(lv_obj_t* parent, lv_event_cb_t event_cb);
void file_grid_set_cell_text(lv_obj_t* parent, const char * text);

void file_grid_test_case();

#ifdef __cplusplus
};
#endif

#endif