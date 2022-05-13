#include "setttingDefinitions.h"

IntSetting* Machine_type;

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


/*
    对ESP32来说，这段属于初始化NVS，在确保开启NVS正常后，
    开始创建对象，在对象都创建完毕之后，执行数据加载，在为
    空的数据里面，数据会自动写入默认值。
*/
void eeprom_init(void) {

    Setting::init();

    make_pargrame_list();

    load_settings();
}


void make_pargrame_list(void) {

    Machine_type = new IntSetting(GRBL, WG, "0", "MachineType", 1, 0, 10);
}


void change_mc_type(void) {

    Machine_type->setStringValue("1");
}

int32_t read_mc_type(void) {

    return Machine_type->get();
}