#include "sd_info.h"

sd_content_type sd_content;


void get_sd_filename(char *line)
{
    char c;
    char buf[20];
    char *p = buf;
    while (*line != '\0')
    {
        if(*line == '[')
        {
            line++;
        }
        if(*line == ':')
        {
            *p = '\0';
            p = sd_content.filename[sd_content.file_num];
            line++;
        }
        if(*line == ']')
        {
            if(strcmp(buf,"File") == 0)
            {
                sd_content.filetype[sd_content.file_num] = FILE_TYPE;
            }
            if(strcmp(buf,"Dir") == 0)
            {
                sd_content.filetype[sd_content.file_num] = DIR_TYPE;
            }
            sd_content.file_num++;
            break;
        }
        *p = *line;
        p++;
        line++;
        /* code */
    }
    // serial_sendf(CLIENT_SERIAL, "file %d %s\n", sd_content.filetype[0],sd_content.filename[0]);

}