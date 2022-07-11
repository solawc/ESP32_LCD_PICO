#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    lv_obj_t *btn_file0;
    lv_obj_t *btn_file1;
    lv_obj_t *btn_file2;
    lv_obj_t *btn_file3;
    lv_obj_t *btn_file4;
    lv_obj_t *btn_file5;
    lv_obj_t *btn_file6;
    lv_obj_t *btn_file7;

    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;

    lv_obj_t *label_pic_file0;
    lv_obj_t *label_pic_file1;
    lv_obj_t *label_pic_file2;
    lv_obj_t *label_pic_file3;
    lv_obj_t *label_pic_file4;
    lv_obj_t *label_pic_file5;
    lv_obj_t *label_pic_file6;
    lv_obj_t *label_pic_file7;

    lv_obj_t *label_file0;
    lv_obj_t *label_file1;
    lv_obj_t *label_file2;
    lv_obj_t *label_file3;
    lv_obj_t *label_file4;
    lv_obj_t *label_file5;
    lv_obj_t *label_file6;
    lv_obj_t *label_file7;

    lv_obj_t *btn_back;
    lv_obj_t *label_back_pic;
    lv_obj_t *label_back;

    lv_obj_t *btn_up;
    lv_obj_t *label_up_pic;
    lv_obj_t *label_up;

    lv_obj_t *btn_next;
    lv_obj_t *label_next_pic;
    lv_obj_t *label_next;
    
}ui_file_list_t;

#define PAGE_MAX_FILE_NUM 8
#define MAX_PAGE_NUM 4

typedef struct{
    bool updata_flag = false;
    uint16_t cur_page = 0;
    uint16_t cur_page_file_num = 0;
}ui_file_updata_t;
extern ui_file_updata_t ui_file_list_page_updata;

#define FILE_LIST_BTN_LIST_X1 8
#define FILE_LIST_BTN_LIST_X2 126
#define FILE_LIST_BTN_LIST_X3 244
#define FILE_LIST_BTN_LIST_X4 362

#define FILE_LIST_BTN_LIST_Y1 84
#define FILE_LIST_BTN_LIST_Y2 202

#define FILE_LIST_BTN_BACK_X 8
#define FILE_LIST_BTN_BACK_Y 8

#define FILE_LIST_BTN_UP_X 354
#define FILE_LIST_BTN_UP_Y 8

#define FILE_LIST_BTN_NEXT_X 422
#define FILE_LIST_BTN_NEXT_Y 8

/***************************************************************************
 *                              extern
***************************************************************************/

void draw_file_list(void);
void clean_file_list_page(void);
void disp_file_name(int num , int page);
void disp_open_file();