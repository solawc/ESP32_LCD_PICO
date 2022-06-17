#include "hal_wdt.h"



void wdt_set_disable(void) {
    disableCore0WDT();
    disableCore1WDT();
    disableLoopWDT();
}