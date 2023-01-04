#include "main.h"

void app_task_init(void) {

    // init client and init serial port
    client_init();

    // EEPROM(NVS) init
    eeprom_init();

    // SDCard init                  
    // mysdcard.cardInit();             // need check it, will reset machine.
    #if (GRBL_SPI_SS != -1) || (GRBL_SPI_MISO != -1) || (GRBL_SPI_MOSI != -1) || (GRBL_SPI_SCK != -1)
        SD_SPI.begin(GRBL_SPI_SCK, GRBL_SPI_MISO, GRBL_SPI_MOSI, GRBL_SPI_SS);
    #endif

    // mount SDCard Fatfs
    if(mysdcard.mount()) { debug_send(CLIENT_SERIAL, "SD mount succeed\n"); }
    else { debug_send(CLIENT_SERIAL, "SD mount fail\n"); }
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

    // init test
    // lv_draw_test();

    // turn on the lcd and finish Init
    ui.lvglTaskInit();  
}


void loop() {
     
    // grbl_protocol_main_loop();
}



