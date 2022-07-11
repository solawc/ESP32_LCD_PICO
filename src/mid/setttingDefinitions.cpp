#include "setttingDefinitions.h"

IntSetting* Machine_type;

IntSetting* Machine_theme;


IntSetting* Machine_type_num;
IntSetting* Firmware_ver_num;
IntSetting* Baud_rate;
IntSetting* Num_of_axes;
IntSetting* Wireless_type;
IntSetting* Customize_num;

xQueueHandle setting_w_queue;  // used by limit switch debouncing


/*  数据将会从NVS中加载出来，保存带List中 
    List里面每当new一个新的对象时，List会自动添加
    这个对象的值，并且装载到Flash中使用，因此这个
    函数需要在初始化NVS、创建好对象之后再使用，否则
    对象里面包含的只有内存的值，并不是NVS里面的值，会
    导致数据无法保存
*/
void load_settings() {
    for (Setting* s = Setting::List; s; s = s->next()) {
        s->load();
    }
}
char buff[10];
void Setting_w_Task(void* pvParameters) {
    while (true) {
        int evt;
        xQueueReceive(setting_w_queue, &evt, portMAX_DELAY);  // block until receive queue
        vTaskDelay(32 / portTICK_PERIOD_MS);    // delay a while
        serial_sendf(CLIENT_SERIAL,"task %d\n",evt);
        switch (evt)
        {
        case 1:
            Machine_type_num->setStringValue("1");
            break;
        case 2:
            Machine_type_num->setStringValue("2");
            break;
        case 3:
            Machine_type_num->setStringValue("3");
            break;
        case 4:
            Firmware_ver_num->setStringValue("1");
            break;
        case 5:
            Firmware_ver_num->setStringValue("2");
            break;
        case 6:
            Firmware_ver_num->setStringValue("3");
            break;
        case 7:
            Baud_rate->setStringValue("1");
            break;
        case 8:
            Baud_rate->setStringValue("2");
            break;
        case 9:
            Baud_rate->setStringValue("3");
            break;
        case 10:
            Num_of_axes->setStringValue("1");
            break;
        case 11:
            Num_of_axes->setStringValue("2");
            break;
        case 12:
            Num_of_axes->setStringValue("3");
            break;
        case 13:
            Wireless_type->setStringValue("1");
            break;
        case 14:
            Wireless_type->setStringValue("2");
            break;
        case 15:
            Wireless_type->setStringValue("3");
            break;
        case 16:
            Customize_num->setStringValue("1");
            break;
        case 17:
            Customize_num->setStringValue("2");
            break;
        case 18:
            Customize_num->setStringValue("3");
            break;
        default:
            break;
        }
    }
}
/*
    对ESP32来说，这段属于初始化NVS，在确保开启NVS正常后，
    开始创建对象，在对象都创建完毕之后，执行数据加载，在为
    空的数据里面，数据会自动写入默认值。
*/
void eeprom_init(void) {

    Setting::init();

    make_pargrame_list();

    load_settings();

    if (setting_w_queue == NULL) {
        setting_w_queue = xQueueCreate(10, sizeof(int));
        xTaskCreate(Setting_w_Task,
                    "Setting_w_Task",
                    2048,
                    NULL,
                    1,  // priority
                    NULL);
    }
}


void make_pargrame_list(void) {

    Machine_type = new IntSetting(GRBL, WG, "0", "MachineType", 1, 0, 10);

    Machine_theme = new IntSetting(GRBL, WG, "1", "MachineTheme", 1, 0, 4);

    Machine_type_num   = new IntSetting(GRBL, WG, "2", "Machine type", 1, 0, 100);
    Firmware_ver_num   = new IntSetting(GRBL, WG, "3", "Firmware version", 1, 0, 10);
    Baud_rate   = new IntSetting(GRBL, WG, "4", "Baud rate", 1, 0, 10);
    Num_of_axes   = new IntSetting(GRBL, WG, "5", "Number of axes", 1, 0, 10);
    Wireless_type   = new IntSetting(GRBL, WG, "6", "Wireless type", 1, 0, 10);
    Customize_num   = new IntSetting(GRBL, WG, "7", "Customize", 1, 0, 10);
    
}


void change_mc_type(void) {

    Machine_type->setStringValue("1");
}

int32_t read_mc_type(void) {

    return Machine_type->get();
}