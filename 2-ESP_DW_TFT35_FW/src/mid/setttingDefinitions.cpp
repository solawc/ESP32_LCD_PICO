#include "setttingDefinitions.h"

IntSetting* Machine_type;


void eeprom_init(void) {

    Setting::init();

    Machine_type = new IntSetting(GRBL, WG, "0", "MachineType", 0, 0, 10);
}

