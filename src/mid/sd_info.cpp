#include "sd_info.h"

sd_content_type sd_content;
// char public1_buff[60];

// #define SD_OK  "OK"
/*
    解析获取到sd内文件的名字和sd卡的容量
*/
void get_sd_filename(char *line)
{

    bool get_flag = true;
    bool sd_size_flag = false;
    bool sd_file_size_flag = false;
<<<<<<< HEAD
    memset(public1_buff,0,sizeof(public1_buff));
    char *p = public1_buff;
=======

    char *p = NULL;
>>>>>>> cb5f09ac69d4aa9827ecc96315e0f03b397e0f00
    while (*line != '\0')
    {
        if(*line == '[')
        {
            // memset(public1_buff,0,sizeof(public1_buff));
            memset(public1_buff,0,sizeof(public1_buff));
            p = public1_buff;
            get_flag = false;
            line++;
        }
        else if(*line == ':')
        {
            if(!sd_size_flag)
            {
                get_flag = false;
                if(strcmp(public1_buff,"SD Free") == 0)
                {
                    sd_size_flag = true;
                    get_flag = true;
                    sd_file_size_flag = false;
                }
            }
            if(!sd_size_flag)
            {
                if(sd_file_size_flag)
                {
                    p = sd_content.filesize[sd_content.file_num];
                    sd_file_size_flag = false;
                }
                else
                {
<<<<<<< HEAD
                    line++;
=======
>>>>>>> cb5f09ac69d4aa9827ecc96315e0f03b397e0f00
                    p = sd_content.filename[sd_content.file_num];
                }
            }
        }
        else if(*line == '|')
        {
            if(!sd_size_flag)
            {
                p =  NULL;
                get_flag = false;
                sd_file_size_flag = true;
            }            
        }
        
        if(*line == ']')
        {
            if(sd_size_flag)
            {
                *p = '\0';
                // serial_sendf(CLIENT_SERIAL,"f2f %s f2f\n",public1_buff);
                get_sd_size_data(public1_buff);
            }
            else
            {
                if(strcmp(public1_buff,"FILE") == 0)
                {
                    sd_content.filetype[sd_content.file_num] = FILE_TYPE;
                }
                if(strcmp(public1_buff,"Dir") == 0)
                {
                    sd_content.filetype[sd_content.file_num] = DIR_TYPE;
                }
                sd_content.file_num++;
            }
            break;
        }
        else
        {
            if(!sd_size_flag)
            {
                if(sd_file_size_flag)
                {
                    get_flag = false;
                }
                else
                {
                    get_flag = true;
                }
            }
        }

        if(get_flag)
        {
            *p = *line;
            p++;
        }
        line++;
        /* code */
    }
}
/*
把MB GB 转化成 KB
<<<<<<< HEAD

*/
double sd_space_unit_change(uint16_t type, double data)
{
    switch (type)
    {
    case 0:
        return data;
        break;
    case 1:
        return data * 1024;
        break;
    case 2:
        return data * 1024 * 1024;
        break;
    default:
        break;
    }
}
/*
获取不同sd卡容量类型的大小 
并且最终转化成kb单位的大小
*/
uint16_t get_sd_space_num(uint16_t type,char *data)
{
    // char buff[60];
    FD_ZERO(public3_buff);
    uint16_t unit = 0;  // 0代表K 1代表M 2代表G
    char *p = public3_buff;
    while(*data != '\0')
    {
        if((*data >= 48 && *data <= 58)||(*data == '.'))
        {
            *p++ = *data;
        }
        else
        {
            *p = '\0';
        }
        switch (*data)
        {
        case 'G':
            unit = 2;
            break;
        case 'M':
            unit = 1;
            break;
        case 'K':
            unit = 0;
            break;
        default:
            break;
        }
        data++;
    }
    switch (type)
    {
    case SD_SPACE_TYPE_FREE:
        sd_content.sd_free_space = strtof(public3_buff,NULL);
        sd_content.sd_free_space = sd_space_unit_change(unit,sd_content.sd_free_space);
        // serial_sendf(CLIENT_SERIAL,"data1 %0.2f\n",sd_content.sd_free_space);
        break;
    case SD_SPACE_TYPE_USED:
        sd_content.sd_used_space = strtof(public3_buff,NULL);
        sd_content.sd_used_space = sd_space_unit_change(unit,sd_content.sd_used_space);
        // serial_sendf(CLIENT_SERIAL,"data1 %0.2f\n",sd_content.sd_used_space);
        break;
    case SD_SPACE_TYPE_TOTAL:
        sd_content.sd_total_space = strtof(public3_buff,NULL);
        sd_content.sd_total_space = sd_space_unit_change(unit,sd_content.sd_total_space);
        // serial_sendf(CLIENT_SERIAL,"data1 %0.2f\n",sd_content.sd_total_space);
        break;
    default:
        break;
    }
}
/*获取到sd卡容量类型
sd空闲空间大小
sd已经使用的大小
sd卡总容量
*/
uint16_t get_sd_space_type(char *data)
{
    static uint8_t sd_space_type = 0;
    if (strcmp(data,"SDFree") == 0)
    {
        return SD_SPACE_TYPE_FREE;
    }
    else if(strcmp(data,"Used") == 0)
    {
        return SD_SPACE_TYPE_USED;
    }
    else if(strcmp(data,"Total") == 0)
    {
        return SD_SPACE_TYPE_TOTAL;
    }

=======

*/
double sd_space_unit_change(uint16_t type, double data)
{
    switch (type)
    {
    case 0:
        return data;
        break;
    case 1:
        return data * 1024;
        break;
    case 2:
        return data * 1024 * 1024;
        break;
    default:
        break;
    }
}
/*
获取不同sd卡容量类型的大小 
并且最终转化成kb单位的大小
*/
uint16_t get_sd_space_num(uint16_t type,char *data)
{
    // char buff[60];
    FD_ZERO(public3_buff);
    uint16_t unit = 0;  // 0代表K 1代表M 2代表G
    char *p = public3_buff;
    while(*data != '\0')
    {
        if((*data >= 48 && *data <= 58)||(*data == '.'))
        {
            *p++ = *data;
        }
        else
        {
            *p = '\0';
        }
        switch (*data)
        {
        case 'G':
            unit = 2;
            break;
        case 'M':
            unit = 1;
            break;
        case 'K':
            unit = 0;
            break;
        default:
            break;
        }
        data++;
    }
    switch (type)
    {
    case SD_SPACE_TYPE_FREE:
        sd_content.sd_free_space = strtof(public3_buff,NULL);
        sd_content.sd_free_space = sd_space_unit_change(unit,sd_content.sd_free_space);
        // serial_sendf(CLIENT_SERIAL,"data1 %0.2f\n",sd_content.sd_free_space);
        break;
    case SD_SPACE_TYPE_USED:
        sd_content.sd_used_space = strtof(public3_buff,NULL);
        sd_content.sd_used_space = sd_space_unit_change(unit,sd_content.sd_used_space);
        // serial_sendf(CLIENT_SERIAL,"data1 %0.2f\n",sd_content.sd_used_space);
        break;
    case SD_SPACE_TYPE_TOTAL:
        sd_content.sd_total_space = strtof(public3_buff,NULL);
        sd_content.sd_total_space = sd_space_unit_change(unit,sd_content.sd_total_space);
        // serial_sendf(CLIENT_SERIAL,"data1 %0.2f\n",sd_content.sd_total_space);
        break;
    default:
        break;
    }
}
/*获取到sd卡容量类型
sd空闲空间大小
sd已经使用的大小
sd卡总容量
*/
uint16_t get_sd_space_type(char *data)
{
    static uint8_t sd_space_type = 0;
    if (strcmp(data,"SDFree") == 0)
    {
        return SD_SPACE_TYPE_FREE;
    }
    else if(strcmp(data,"Used") == 0)
    {
        return SD_SPACE_TYPE_USED;
    }
    else if(strcmp(data,"Total") == 0)
    {
        return SD_SPACE_TYPE_TOTAL;
    }

>>>>>>> cb5f09ac69d4aa9827ecc96315e0f03b397e0f00
}
/*
对获取到的sd卡容量的字符串进行解析
*/
void get_sd_size_data(char *data)
{
    FD_ZERO(public2_buff);
    char *p = public2_buff;
    uint16_t counter = 0;
    uint16_t type;
    while (*data != '\0')
    {
        if(*data == ':')
        {
            *p = '\0';
            type = get_sd_space_type(public2_buff);
            FD_ZERO(public2_buff);
            p = public2_buff;
            data++;
        }
        if(*data == 'B')
        {
            *p++ = *data;
            *p = '\0';
            get_sd_space_num(type,public2_buff);
            // serial_sendf(CLIENT_SERIAL,"data %s\n",public2_buff);
            FD_ZERO(public2_buff);
            p = public2_buff;
            data++;
        }
        if(*data != ' ')
        {
            *p++ = *data;
        }
        data++;
    }
    // serial_sendf(CLIENT_SERIAL,"ss %s\n",public2_buff);
}