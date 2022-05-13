#pragma once

#include "../main.h"
#include "settings.h"
// extern IntSetting* Machine_type;



// for ESP32, Init nvs to save or load pargram
void eeprom_init(void);
void change_mc_type(void);
int32_t read_mc_type(void);
void load_settings();
void make_pargrame_list(void);