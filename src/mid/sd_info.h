#pragma once

#include "../main.h"
#include "error.h"


#define FILE_MAX_NUM       50
#define FILE_NAME_LEN      16

typedef enum{
    FILE_TYPE,
    DIR_TYPE,
}file_type_t;

typedef struct{
    bool sd_mount;
    char filename[FILE_MAX_NUM][FILE_NAME_LEN];
    file_type_t filetype[FILE_MAX_NUM];
    uint16_t file_num;
}sd_content_type;

extern sd_content_type sd_content;
void get_sd_filename(char *line);