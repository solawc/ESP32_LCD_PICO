#include "draw_logo.h"


ui_logo_t logo;

void draw_logo_init(void) {

    ui.src = lv_obj_create(NULL, NULL);
    ui.src = lv_scr_act();

    ui_init_style();

    lv_obj_set_style(ui.src, &ui.src_style);
}



