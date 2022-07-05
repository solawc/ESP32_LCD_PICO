#pragma once

#include "../main.h"
#include "error.h"

#define FILE_MAX_NUM       50
#define FILE_NAME_LEN      60
#define FILE_SPACE_LEN      10

typedef enum{
    FILE_TYPE,
    DIR_TYPE,
}file_type_t;

typedef enum{
    SD_SPACE_TYPE_FREE,
    SD_SPACE_TYPE_USED,
    SD_SPACE_TYPE_TOTAL,
};

typedef struct{
    file_type_t filetype[FILE_MAX_NUM];
    uint16_t file_num = 0;
    char filename[FILE_MAX_NUM][FILE_NAME_LEN];
    char filesize[FILE_MAX_NUM][FILE_NAME_LEN];
    bool sd_mount;
    bool gain_all_name = false;
    bool open_file_flag = false;
    double sd_free_space;
    double sd_used_space;
    double sd_total_space;
}sd_content_type;

extern sd_content_type sd_content;
void get_sd_filename(char *line);
void get_sd_size_data(char *data);