#ifndef __WifiWrapper_h
#define __WifiWrapper_h

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void wifi_list_init();
extern void update_wifi_file_list(char * path, lv_obj_t* obj);
extern bool get_wifi_state();

#ifdef __cplusplus
};
#endif



#endif