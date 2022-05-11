#pragma once

#include "../main.h"
#include "../vantins.h"



// Init serial uart, and init all client , build and begin serial task;
void client_init();

// Write a string to uart fifo and send to client out;
void client_write(uint8_t client, const char* text);



