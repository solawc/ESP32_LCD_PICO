#include "cmd_grbl_protocol.h"

#define LINE_BUFFER_SIZE 256
static char    line[LINE_BUFFER_SIZE];     // Line to be executed. Zero-terminated.

typedef struct {
    char buffer[LINE_BUFFER_SIZE];
    int  len;
    int  line_number;
} client_line_t;
client_line_t client_lines[CLIENT_COUNT];

static void empty_line(uint8_t client) {
    client_line_t* cl = &client_lines[client];
    cl->len           = 0;
    cl->buffer[0]     = '\0';
}

static void empty_lines() {
    for (uint8_t client = 0; client < CLIENT_COUNT; client++) {
        empty_line(client);
    }
}

Error add_char_to_line(char c, uint8_t client) {
    client_line_t* cl = &client_lines[client];
    // Simple editing for interactive input
    if (c == '\b') {
        // Backspace erases
        if (cl->len) {
            --cl->len;
            cl->buffer[cl->len] = '\0';
        }
        return Error::Ok;
    }
    if (cl->len == (LINE_BUFFER_SIZE - 1)) {
        return Error::Overflow;
    }
    if (c == '\r' || c == '\n') {
        cl->len = 0;
        cl->line_number++;
        return Error::Eol;
    }
    cl->buffer[cl->len++] = c;
    cl->buffer[cl->len]   = '\0';
    return Error::Ok;
}

void grbl_protocol_main_loop(void) {

    int c;

    for(;;) {

        uint8_t client = CLIENT_SERIAL;
        char*   line;

        for (client = 0; client < CLIENT_COUNT; client++) {
            while ((c = client_read(client)) != -1) {
                Error res = add_char_to_line(c, client);
                switch (res) {
                    case Error::Ok:
                        break;
                    case Error::Eol:

                        line = client_lines[client].buffer;
                        
                        debug_line_received(line, CLIENT_SERIAL);

                        empty_line(client);
                        break;
                    case Error::Overflow:
                        empty_line(client);
                        break;
                    default:
                        break;
                }
            }  // while serial read
        }      // for clients
    }
}