#ifndef __POPVIEW_H
#define __POPVIEW_H

#include "lvgl.h"

lv_obj_t* objmask_init();
void objmask_clean();
void objmask_deinit();


lv_obj_t* power_popview_init(lv_obj_t* parent);
void power_popview_test_case();
void wifi_linking_popview_test_case();
void wifi_password_error_popview_test_case();
void file_download_popview_test_case();

#endif
