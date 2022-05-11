#pragma once

#include "main.h"

#define CLIENT_SERIAL 0
#define CLIENT_BT 1
#define CLIENT_WEBUI 2
#define CLIENT_TELNET 3
#define CLIENT_INPUT 4
#define CLIENT_ALL 0xFF
#define CLIENT_COUNT 5  // total number of client types regardless if they are used





// send text to client and report out
void serial_send(uint8_t client, const char* text);

// format data, and run at serial_send
void serial_sendf(uint8_t client, const char* format, ...);

// run at DEBUG_MODE
void debug_send(uint8_t client, const char* text);