#include "cmd_esp_protocol.h"



Error execute_esp_cmd(char *line, uint8_t client) {

    if(line[0] == 0) return Error::Empty_line;  // 数据是空的

    if (line[0] == '[') {

        return doing_esp32_cmd(line);
    }

    return Error::No_esp_cmd;
}

Error doing_esp32_cmd(char *line) {

    char* value;

    if(*line++ == '[') {
        value = strrchr(line, ']');
        if (!value) {
            // Missing ] is an error in this form
            return Error::InvalidStatement;
        }

        // ']' was found; replace it with null and set value to the rest of the line.
        *value++ = '\0';

        // If the rest of the line is empty, replace value with NULL.
        if (*value == '\0') {
            value = NULL;
        }
    } else {
        // $xxx form
        value = strchr(line, '=');
        if (value) {
            // $xxx=yyy form.
            *value++ = '\0';
        }
    }

    return Error::Ok;
}