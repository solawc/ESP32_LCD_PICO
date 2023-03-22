#include "main.h"



void app_task_init(void) {

    // init client and init serial port
    client_init();

    // EEPROM(NVS) init
    eeprom_init();

    // SDCard init                  
    mysdcard.cardInit();   

    // mount SDCard Fatfs
    if(mysdcard.mount()) { 
        debug_send(CLIENT_SERIAL, "SD mount succeed\n"); 
    }
    else { 
        debug_send(CLIENT_SERIAL, "SD mount fail\n"); 
    }

    #ifdef ENABLE_DEBUG_WIFI
        HAL_WIFI::wifi_config.init();                      /* init wifi state */
    #endif   
}

void setup() {

    // if any bug reset?
    wdt_set_disable();

    // tunr off the lcd and wait the logo is OK
    tft_lcd.tftBglightInit();

    // all task init here
    app_task_init();

    // disp Board Info
    report_mcu_info();

#ifdef ENABLE_DEBUG_WIFI
    HAL_WIFI::wifi_config.begin();
#endif
    // init test
    // lv_draw_test();

    // turn on the lcd and finish Init
    ui.lvglTaskInit();  
}


void loop() {
     
    // grbl_protocol_main_loop();
}



