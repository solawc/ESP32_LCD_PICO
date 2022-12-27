#include "serial.h"

portMUX_TYPE myMutex = portMUX_INITIALIZER_UNLOCKED;

static TaskHandle_t clientCheckTaskHandle = 0;

WebUI::InputBuffer client_buffer[CLIENT_COUNT];  // create a buffer for each client

static uint8_t getClientChar(uint8_t* data) {
    int res;

    /* UART0 */
    if (client_buffer[CLIENT_SERIAL].availableforwrite() && (res = Uart0.read()) != -1) {
        *data = res;
        return CLIENT_SERIAL;
    }
    
    /*UART2*/
    if (client_buffer[CLIENT_SERIAL_LCD].availableforwrite() && (res = Uart2.read()) != -1) {
        *data = res;
        return CLIENT_SERIAL_LCD;
    }

    return CLIENT_ALL;
}

void clientCheckTask(void* pvParameters) {

    uint8_t            data = 0;
    uint8_t            client;  // who sent the data
    
    while (true) {  // run continuously

        while ((client = getClientChar(&data)) != CLIENT_ALL) {
            taskENTER_CRITICAL(&myMutex);
            client_write_data(client, data);
            taskEXIT_CRITICAL(&myMutex);
        }  // if something available

        vTaskDelay(1 / portTICK_RATE_MS);  // Yield to other tasks
    }
}

void client_reset_read_buffer(uint8_t client) {
    for (uint8_t client_num = 0; client_num < CLIENT_COUNT; client_num++) {
        if (client == client_num || client == CLIENT_ALL) {
            client_buffer[client_num].begin();
        }
    }
}


void client_init() {


    Uart0.setPins(1, 3);  // Tx 1, Rx 3 - standard hardware pins
    Uart0.begin(BAUD_RATE, Uart::Data::Bits8, Uart::Stop::Bits1, Uart::Parity::None);

    Uart2.setPins(17, 16);  // Tx 17, Rx 16 - standard hardware pins
    Uart2.begin(BAUD_RATE, Uart::Data::Bits8, Uart::Stop::Bits1, Uart::Parity::None);

    client_reset_read_buffer(CLIENT_ALL);
    Uart0.write("\r\n");  // create some white space after ESP32 boot info
    Uart2.write("\r\n");

    clientCheckTaskHandle = 0;
    // create a task to check for incoming data
    // For a 4096-word stack, uxTaskGetStackHighWaterMark reports 244 words available
    // after WebUI attaches.
    xTaskCreatePinnedToCore(clientCheckTask,    // task
                            "clientCheckTask",  // name for task
                            8192,               // size of task stack
                            NULL,               // parameters
                            3,                  // priority
                            &clientCheckTaskHandle,
                            SUPPORT_TASK_CORE  // must run the task on same core
                                               // core
    );
}

int client_read(uint8_t client) {
    taskENTER_CRITICAL(&myMutex);
    int data = client_buffer[client].read();
    taskENTER_CRITICAL(&myMutex);
    return data;
}

void client_write_data(uint8_t client, uint8_t data) {
    taskENTER_CRITICAL(&myMutex);
    client_buffer[client].write(data);
    taskEXIT_CRITICAL(&myMutex);
}

void client_write(uint8_t client, const char* text) {
    if (client == CLIENT_INPUT) {
        return;
    }
#ifdef ENABLE_BLUETOOTH
    if (WebUI::SerialBT.hasClient() && (client == CLIENT_BT || client == CLIENT_ALL)) {
        WebUI::SerialBT.print(text);
        //delay(10); // possible fix for dropped characters
    }
#endif
#if defined(ENABLE_WIFI) && defined(ENABLE_HTTP) && defined(ENABLE_SERIAL2SOCKET_OUT)
    if (client == CLIENT_WEBUI || client == CLIENT_ALL) {
        WebUI::Serial2Socket.write((const uint8_t*)text, strlen(text));
    }
#endif
#if defined(ENABLE_WIFI) && defined(ENABLE_TELNET)
    if (client == CLIENT_TELNET || client == CLIENT_ALL) {
        WebUI::telnet_server.write((const uint8_t*)text, strlen(text));
    }
#endif
    if (client == CLIENT_SERIAL || client == CLIENT_ALL) {
        Uart0.write(text);
    }

    if (client == CLIENT_SERIAL_LCD || client == CLIENT_ALL) {
        Uart2.write(text);
    }
}

void send_cmd(uint8_t client, const char *text) {

    client_write(client, text);
}