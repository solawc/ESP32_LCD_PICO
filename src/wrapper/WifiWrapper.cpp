#include "WifiWrapper.h"
#include "../lv_generated/custom/wifi_grid.h"
#include "../hal/hal_wifi.h"

void wifi_list_init()
{
    
}

void update_wifi_file_list(char * path, lv_obj_t* obj)
{
    for(int i = 0; i<8; i++){
        wifi_grid_insert_cell(obj, NULL);
        wifi_grid_set_cell_text(obj, "test");
    }
}

bool get_wifi_state()
{
    bool state = HAL_WIFI::wifi_config.getWifiInitStatus();
    return state;
}