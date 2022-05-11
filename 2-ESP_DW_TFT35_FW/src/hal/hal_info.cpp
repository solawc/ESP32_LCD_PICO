#include "hal_info.h"
#include "WiFi.h"

void report_mcu_info(void) {
    
    // Init and get mc info;
    lcd_controller_init();
    
    serial_send(CLIENT_ALL, "/**************************************************/\n");
    serial_sendf(CLIENT_ALL, "         Board Support from Makerbase\n");
    serial_sendf(CLIENT_ALL, "/*-Board Name:%s\n", BOARD_NAME);
    serial_sendf(CLIENT_ALL, "/*-Machine Axis Num:4\n");
    serial_sendf(CLIENT_ALL, "/*-Chip ID:%s\n", String((uint16_t)(ESP.getEfuseMac() >> 32)));
    serial_sendf(CLIENT_ALL, "/*-CPU Freq:%s\n", String(ESP.getCpuFreqMHz()) + "Mhz");
    serial_sendf(CLIENT_ALL, "/*-CPU SDK Version:%s\n", ESP.getSdkVersion());
    serial_sendf(CLIENT_ALL, "/*-CPU Flah size:%dM\n", (ESP.getFlashChipSize()/1024)/1024);
    serial_sendf(CLIENT_ALL, "/*-CPU Serial baud:%s\n", String((Serial.baudRate() / 100) * 100));
    serial_sendf(CLIENT_ALL, "/*-WIFI Mode:%s\n", WiFi.getSleep() ? "Modem" : "None");
    serial_sendf(CLIENT_ALL, "/*-FW Work Mode:CNC\n");
    serial_sendf(CLIENT_ALL, "/*-FW Version:%s\n", FW_VERSION);
    serial_sendf(CLIENT_ALL, "/*-Update date:%s\n", UPDATA_DATA);
    serial_send(CLIENT_ALL, "/**************************************************/\n");
}


