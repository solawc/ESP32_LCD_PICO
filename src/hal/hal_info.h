#pragma once

#include "../main.h"



void report_mcu_info(void);
void serial_debug(const char* text);
void serial_debug_f(uint8_t client, const char* format, ...);