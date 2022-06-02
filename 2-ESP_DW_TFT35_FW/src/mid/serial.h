#pragma once

#include "../main.h"
#include "../vantins.h"
#include <freertos/FreeRTOS.h>


// Init serial uart, and init all client , build and begin serial task;
void client_init();

// Write a string to uart fifo and send to client out;
void client_write(uint8_t client, const char* text);

// read a byte from buff
int client_read(uint8_t client);

// write a data to ringbuffer
void client_write_data(uint8_t client, uint8_t data);

// send cmd to client
void send_cmd(uint8_t client, const char *text);

