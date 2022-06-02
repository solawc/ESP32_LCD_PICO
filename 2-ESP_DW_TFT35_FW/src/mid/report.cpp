#include "report.h"


void serial_send(uint8_t client, const char* text) {
    client_write(client, text);
}

void serial_sendf(uint8_t client, const char* format, ...) {
    if (client == CLIENT_INPUT) {
        return;
    }
    char    loc_buf[64];
    char*   temp = loc_buf;
    va_list arg;
    va_list copy;
    va_start(arg, format);
    va_copy(copy, arg);
    size_t len = vsnprintf(NULL, 0, format, arg);
    va_end(copy);
    if (len >= sizeof(loc_buf)) {
        temp = new char[len + 1];
        if (temp == NULL) {
            return;
        }
    }
    len = vsnprintf(temp, len + 1, format, arg);
    serial_send(client, temp);
    va_end(arg);
    if (temp != loc_buf) {
        delete[] temp;
    }
}

void debug_send(uint8_t client, const char* text) {
#ifdef DEBUG_MODE
      client_write(client, text);
#endif
}

void debug_line_received(char* line, uint8_t client) {
    serial_sendf(client, "%s\n", line);
}




bool mc_handshake() {
      // TODO.
}