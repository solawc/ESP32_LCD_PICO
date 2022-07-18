/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_file_list.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_file_list_t file_list_page;
ui_file_updata_t ui_file_list_page_updata;
/***************************************************************************
 *                          static function
 * - static void set_file_list_font_pic_color(uint8_t id, bool status) 
 * - static void draw_file_list_bar(void)
 * 
***************************************************************************/
static void set_file_list_font_pic_color(uint8_t id, bool status);
static void draw_file_list_bar(void);
void disp_file_name(int num , int page);
void del_sd_file_btn();
/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    ID_FLIE_LIST_FILE0,
    ID_FLIE_LIST_FILE1,
    ID_FLIE_LIST_FILE2,
    ID_FLIE_LIST_FILE3,
    ID_FLIE_LIST_FILE4,
    ID_FLIE_LIST_FILE5,
    ID_FLIE_LIST_FILE6,
    ID_FLIE_LIST_FILE7,
    ID_FLIE_LIST_UP,
    ID_FLIE_LIST_NEXT,
    ID_FILE_LIST_BACK,
};



/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {
   if(obj == file_list_page.btn_file0) return ID_FLIE_LIST_FILE0;
   else if(obj == file_list_page.btn_file1) return ID_FLIE_LIST_FILE1;
   else if(obj == file_list_page.btn_file2) return ID_FLIE_LIST_FILE2;
   else if(obj == file_list_page.btn_file3) return ID_FLIE_LIST_FILE3;
   else if(obj == file_list_page.btn_file4) return ID_FLIE_LIST_FILE4;
   else if(obj == file_list_page.btn_file5) return ID_FLIE_LIST_FILE5;
   else if(obj == file_list_page.btn_file6) return ID_FLIE_LIST_FILE6;
   else if(obj == file_list_page.btn_file7) return ID_FLIE_LIST_FILE7;
   else if(obj == file_list_page.btn_up) return ID_FLIE_LIST_UP;
   else if(obj == file_list_page.btn_next) return ID_FLIE_LIST_NEXT;
   else if(obj == file_list_page.btn_back) return ID_FILE_LIST_BACK;
}


static void event_handler(lv_obj_t* obj, lv_event_t event) {
    char buff[80];
    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) {
        
        set_file_list_font_pic_color(id, true);

        switch(id) {
            case ID_FLIE_LIST_FILE0: 
            
            break;

            case ID_FLIE_LIST_FILE1:
                
            break;

            case ID_FLIE_LIST_FILE2: 

            break; 
            case ID_FLIE_LIST_FILE3:
                
            break;
            case ID_FLIE_LIST_FILE4: 
            
            break;

            case ID_FLIE_LIST_FILE5:
                
            break;

            case ID_FLIE_LIST_FILE6: 

            break; 
            case ID_FLIE_LIST_FILE7:
                
            break;
        }
    }

    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        set_file_list_font_pic_color(id, false);
        

        switch(id) {
            case ID_FLIE_LIST_FILE0: 
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                memset(buff,0,sizeof(buff));
                sprintf(buff,"[ESP220]%s\n",sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 0)]);
                strcpy(grbl_cmd.grbl_basic_info.print_fname,sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 0)]);
                MKS_PICO_CMD_SEND(buff);
                // serial_sendf(CLIENT_SERIAL,"%s",buff);
                clean_file_list_page();
                draw_print();
            break;

            case ID_FLIE_LIST_FILE1:
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                memset(buff,0,sizeof(buff));
                sprintf(buff,"[ESP220]%s\n",sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 1)]);
                strcpy(grbl_cmd.grbl_basic_info.print_fname,sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 1)]);
                MKS_PICO_CMD_SEND(buff);
                // serial_sendf(CLIENT_SERIAL,"%s",buff);
                clean_file_list_page();
                draw_print();
            break;

            case ID_FLIE_LIST_FILE2: 
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                memset(buff,0,sizeof(buff));
                sprintf(buff,"[ESP220]%s\n",sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 2)]);
                strcpy(grbl_cmd.grbl_basic_info.print_fname,sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 2)]);
                MKS_PICO_CMD_SEND(buff);
                // serial_sendf(CLIENT_SERIAL,"%s",buff);
                clean_file_list_page();
                draw_print();
            break; 
            case ID_FLIE_LIST_FILE3:
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                memset(buff,0,sizeof(buff));
                sprintf(buff,"[ESP220]%s\n",sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 3)]);
                strcpy(grbl_cmd.grbl_basic_info.print_fname,sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 3)]);
                MKS_PICO_CMD_SEND(buff);
                clean_file_list_page();
                // serial_sendf(CLIENT_SERIAL,"%s",buff);
                draw_print();
            break;
<<<<<<< HEAD
            case ID_FLIE_LIST_FILE4: 
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                memset(buff,0,sizeof(buff));
                sprintf(buff,"[ESP220]%s\n",sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 4)]);
                strcpy(grbl_cmd.grbl_basic_info.print_fname,sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 4)]);
                clean_file_list_page();
                MKS_PICO_CMD_SEND(buff);
                // serial_sendf(CLIENT_SERIAL,"%s",buff);
                draw_print();
            break;

            case ID_FLIE_LIST_FILE5:
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                memset(buff,0,sizeof(buff));
                sprintf(buff,"[ESP220]%s\n",sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 5)]);
                strcpy(grbl_cmd.grbl_basic_info.print_fname,sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 5)]);
                clean_file_list_page();
                MKS_PICO_CMD_SEND(buff);
                // serial_sendf(CLIENT_SERIAL,"%s",buff);
                draw_print();
            break;

            case ID_FLIE_LIST_FILE6: 
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                memset(buff,0,sizeof(buff));
                sprintf(buff,"[ESP220]%s\n",sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 6)]);
                strcpy(grbl_cmd.grbl_basic_info.print_fname,sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 6)]);
                MKS_PICO_CMD_SEND(buff);
                // serial_sendf(CLIENT_SERIAL,"%s",buff);
                clean_file_list_page();
                draw_print();
            break; 
            case ID_FLIE_LIST_FILE7:
                mks_ui_page.mks_ui_page = MKS_UI_PAGE_LOADING;
                memset(buff,0,sizeof(buff));
                sprintf(buff,"[ESP220]%s\n",sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 7)]);
                strcpy(grbl_cmd.grbl_basic_info.print_fname,sd_content.filename[((ui_file_list_page_updata.cur_page - 1)*8 + 7)]);
                MKS_PICO_CMD_SEND(buff);
                // serial_sendf(CLIENT_SERIAL,"%s",buff);
                clean_file_list_page();
                draw_print();
            break;
=======
>>>>>>> cb5f09ac69d4aa9827ecc96315e0f03b397e0f00
            case ID_FLIE_LIST_UP:
                ui_file_list_page_updata.cur_page--;
                if(ui_file_list_page_updata.cur_page >= 1)
                {
                    del_sd_file_btn();
                    disp_file_name(sd_content.file_num,ui_file_list_page_updata.cur_page);
                }
                else
                {
                    ui_file_list_page_updata.cur_page = 1;
                }

            break;
            case ID_FLIE_LIST_NEXT:
<<<<<<< HEAD
                // if(sd_content.file_num > 0)
                // {
                    if(ui_file_list_page_updata.cur_page_file_num < 8)
=======
                if(ui_file_list_page_updata.cur_page_file_num < 8)
                {
                    ui_file_list_page_updata.cur_page = ui_file_list_page_updata.cur_page;
                }
                else
                {
<<<<<<< HEAD
                    if((sd_content.file_num - ui_file_list_page_updata.cur_page * 8) > 0)
>>>>>>> 3fc87eb2a8cffb20c2c65f158e4709c880709526
                    {
                        ui_file_list_page_updata.cur_page = ui_file_list_page_updata.cur_page;
                    }
<<<<<<< HEAD
                    else
                    {
                        if((sd_content.file_num - ui_file_list_page_updata.cur_page * 8) > 0)
                        {
                            del_sd_file_btn();
                            ui_file_list_page_updata.cur_page++;
                            disp_file_name(sd_content.file_num,ui_file_list_page_updata.cur_page);
                        }
                    }
                // }

=======
=======
                    del_sd_file_btn();
                    ui_file_list_page_updata.cur_page++;
                    disp_file_name(sd_content.file_num,ui_file_list_page_updata.cur_page);
>>>>>>> cb5f09ac69d4aa9827ecc96315e0f03b397e0f00
                }
>>>>>>> 3fc87eb2a8cffb20c2c65f158e4709c880709526

            break;
            case ID_FILE_LIST_BACK: 
                ui_file_list_page_updata.cur_page_file_num = 0;
                sd_content.gain_all_name = false;
                clean_file_list_page();
                draw_home();
            break; 
            }
    }
}

static void draw_file_list_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 76);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

#define FILE_LIST_CN_EN "English"
#define FILE_LIST_EN_EN  "English"
#define FILE_LIST_RU_EN  "English"
#define FILE_LIST_DE_EN  "Deutsch"
#define FILE_LIST_BACK_EN  "Back"

#define FILE_LIST_UP_EN    "Up"
#define FILE_LIST_NEXT_EN  "Next"



void draw_file_list(void) {
    
    draw_file_list_bar();
    lv_style_copy(&file_list_page.btn_pre_style , &lv_style_scr);
    file_list_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	file_list_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    file_list_page.btn_pre_style.body.radius = 10;
    file_list_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&file_list_page.btn_rel_style , &lv_style_scr);
    file_list_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	file_list_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    file_list_page.btn_rel_style.body.radius = 10;
    file_list_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    file_list_page.btn_back =  lv_btn_set(ui.src, file_list_page.btn_back, 60, 60, FILE_LIST_BTN_BACK_X, FILE_LIST_BTN_BACK_Y, event_handler);
    file_list_page.btn_up =  lv_btn_set(ui.src, file_list_page.btn_back, 60, 60, FILE_LIST_BTN_UP_X, FILE_LIST_BTN_UP_Y, event_handler);
    file_list_page.btn_next =  lv_btn_set(ui.src, file_list_page.btn_back, 60, 60, FILE_LIST_BTN_NEXT_X, FILE_LIST_BTN_NEXT_Y, event_handler);

    lv_btn_set_style(file_list_page.btn_back, LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);
    lv_btn_set_style(file_list_page.btn_back, LV_BTN_STYLE_REL, &file_list_page.btn_pre_style);

    lv_btn_set_style(file_list_page.btn_up, LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);
    lv_btn_set_style(file_list_page.btn_up, LV_BTN_STYLE_REL, &file_list_page.btn_pre_style);

    lv_btn_set_style(file_list_page.btn_next, LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);
    lv_btn_set_style(file_list_page.btn_next, LV_BTN_STYLE_REL, &file_list_page.btn_pre_style);



    file_list_page.label_back_pic = lv_label_create(file_list_page.btn_back, NULL);
    lv_label_set_text(file_list_page.label_back_pic, FONT_PIC_BACK);
    lv_label_set_style(file_list_page.label_back_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    file_list_page.label_up_pic = lv_label_create(file_list_page.btn_up, NULL);
    lv_label_set_text(file_list_page.label_up_pic, FONT_PIC_UP);
    lv_label_set_style(file_list_page.label_up_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);

    file_list_page.label_next_pic = lv_label_create(file_list_page.btn_next, NULL);
    lv_label_set_text(file_list_page.label_next_pic, FONT_PIC_NEXT);
    lv_label_set_style(file_list_page.label_next_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);




    file_list_page.label_back = lv_label_create(file_list_page.btn_back, NULL);
    lv_obj_align(file_list_page.label_back, file_list_page.label_back_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(file_list_page.label_back,FILE_LIST_BACK_EN);

    file_list_page.label_up = lv_label_create(file_list_page.btn_up, NULL);
    lv_obj_align(file_list_page.label_up, file_list_page.label_up_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(file_list_page.label_up,FILE_LIST_UP_EN);

    file_list_page.label_next = lv_label_create(file_list_page.btn_next, NULL);
    lv_obj_align(file_list_page.label_next, file_list_page.label_next_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    lv_label_set_text(file_list_page.label_next,FILE_LIST_NEXT_EN);

    // disp_file_name(8 , 0);

    mks_ui_page.mks_ui_page = MKS_UI_PAGE_SD_LIST;
    ui_file_list_page_updata.updata_flag = true;
<<<<<<< HEAD
    // sd_content.open_file_flag = false;
=======
>>>>>>> cb5f09ac69d4aa9827ecc96315e0f03b397e0f00
    ui_file_list_page_updata.cur_page = 1;

}
#define FILE_LIST_BTN_FILE_ARRAY0    FILE_LIST_BTN_LIST_X1, FILE_LIST_BTN_LIST_Y1
#define FILE_LIST_BTN_FILE_ARRAY1    FILE_LIST_BTN_LIST_X2, FILE_LIST_BTN_LIST_Y1
#define FILE_LIST_BTN_FILE_ARRAY2    FILE_LIST_BTN_LIST_X3, FILE_LIST_BTN_LIST_Y1
#define FILE_LIST_BTN_FILE_ARRAY3    FILE_LIST_BTN_LIST_X4, FILE_LIST_BTN_LIST_Y1
#define FILE_LIST_BTN_FILE_ARRAY4    FILE_LIST_BTN_LIST_X1, FILE_LIST_BTN_LIST_Y2
#define FILE_LIST_BTN_FILE_ARRAY5    FILE_LIST_BTN_LIST_X2, FILE_LIST_BTN_LIST_Y2
#define FILE_LIST_BTN_FILE_ARRAY6    FILE_LIST_BTN_LIST_X3, FILE_LIST_BTN_LIST_Y2
#define FILE_LIST_BTN_FILE_ARRAY7    FILE_LIST_BTN_LIST_X4, FILE_LIST_BTN_LIST_Y2


 #define  FILE_LSIT_BTN_FILE(X)  file_list_page.btn_file##X
 #define  FILE_LSIT_PIC_FILE(X)  file_list_page.label_pic_file##X
 #define  FILE_LSIT_LABEL_FILE(X)  file_list_page.label_file##X
 #define  FILE_LIST_BTN_FILE_ARRAY(X) FILE_LIST_BTN_FILE_ARRAY##X

<<<<<<< HEAD
void disp_open_file()
{
    if(sd_content.open_file_flag)
    {
        sd_content.open_file_flag = false;
        clean_file_list_page();
        draw_print();
    }
}

=======
>>>>>>> cb5f09ac69d4aa9827ecc96315e0f03b397e0f00
void disp_file_name(int num , int page)
{
    uint16_t index = 0;
    uint16_t cur_page_num;
    if(num <= 8)
    {
        index = 0;
        cur_page_num = num;
    }
    else
    {
        if(page == 1)
        {
            index = 0;
            cur_page_num = 8;
        }
        else
        {
            cur_page_num = num - (page - 1)*8;
            if(cur_page_num >= 8)
            {
                cur_page_num = 8;
            }
            index = ((page - 1)*8);
        }
    }
    // if(num <= 8 && page == 1)
    // {
    //     index = 0;
    //     cur_page_num = num;
    // }
    // else if((num - (page - 1)*8) >= 0)
    // {
    //     index = ((page - 1)*8) -1;
    // }
    ui_file_list_page_updata.cur_page_file_num = cur_page_num;
    ui_file_list_page_updata.cur_page = page;
    switch (cur_page_num)
    {
    case 1:
        FILE_LSIT_BTN_FILE(0) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(0), 110, 110, FILE_LIST_BTN_FILE_ARRAY(0), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(0), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(0), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(0), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(0), FILE_LSIT_PIC_FILE(0), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(0), sd_content.filename[0 + index]);
        break;
    case 2:
        FILE_LSIT_BTN_FILE(0) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(0), 110, 110, FILE_LIST_BTN_FILE_ARRAY(0), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(0), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(0), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(0), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(0), FILE_LSIT_PIC_FILE(0), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(0), sd_content.filename[0 + index]);
        FILE_LSIT_BTN_FILE(1) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(1), 110, 110, FILE_LIST_BTN_FILE_ARRAY(1), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(1), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(1), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(1), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(1), FILE_LSIT_PIC_FILE(1), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(1), sd_content.filename[1 + index]);
        break;
    case 3:
        FILE_LSIT_BTN_FILE(0) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(0), 110, 110, FILE_LIST_BTN_FILE_ARRAY(0), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(0), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(0), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(0), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(0), FILE_LSIT_PIC_FILE(0), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(0), sd_content.filename[0 + index]);
        FILE_LSIT_BTN_FILE(1) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(1), 110, 110, FILE_LIST_BTN_FILE_ARRAY(1), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(1), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(1), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(1), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(1), FILE_LSIT_PIC_FILE(1), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(1), sd_content.filename[1 + index]);
        FILE_LSIT_BTN_FILE(2) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(2), 110, 110, FILE_LIST_BTN_FILE_ARRAY(2), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(2), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(2), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(2), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(2), FILE_LSIT_PIC_FILE(2), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(2), sd_content.filename[2 + index]);
        break;
    case 4:
        FILE_LSIT_BTN_FILE(0) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(0), 110, 110, FILE_LIST_BTN_FILE_ARRAY(0), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(0), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(0), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(0), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(0), FILE_LSIT_PIC_FILE(0), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(0), sd_content.filename[0 + index]);
        FILE_LSIT_BTN_FILE(1) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(1), 110, 110, FILE_LIST_BTN_FILE_ARRAY(1), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(1), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(1), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(1), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(1), FILE_LSIT_PIC_FILE(1), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(1), sd_content.filename[1 + index]);
        FILE_LSIT_BTN_FILE(2) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(2), 110, 110, FILE_LIST_BTN_FILE_ARRAY(2), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(2), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(2), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(2), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(2), FILE_LSIT_PIC_FILE(2), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(2), sd_content.filename[2 + index]);
        FILE_LSIT_BTN_FILE(3) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(3), 110, 110, FILE_LIST_BTN_FILE_ARRAY(3), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(3), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(3), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(3) = lv_label_create(FILE_LSIT_BTN_FILE(3), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(3), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(3), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(3) = lv_label_create(FILE_LSIT_BTN_FILE(3), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(3), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(3), FILE_LSIT_PIC_FILE(3), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(3), sd_content.filename[3 + index]);
        break;
    case 5:
        FILE_LSIT_BTN_FILE(0) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(0), 110, 110, FILE_LIST_BTN_FILE_ARRAY(0), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(0), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(0), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(0), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(0), FILE_LSIT_PIC_FILE(0), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(0), sd_content.filename[0 + index]);
        FILE_LSIT_BTN_FILE(1) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(1), 110, 110, FILE_LIST_BTN_FILE_ARRAY(1), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(1), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(1), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(1), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(1), FILE_LSIT_PIC_FILE(1), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(1), sd_content.filename[1 + index]);
        FILE_LSIT_BTN_FILE(2) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(2), 110, 110, FILE_LIST_BTN_FILE_ARRAY(2), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(2), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(2), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(2), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(2), FILE_LSIT_PIC_FILE(2), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(2), sd_content.filename[2 + index]);
        FILE_LSIT_BTN_FILE(3) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(3), 110, 110, FILE_LIST_BTN_FILE_ARRAY(3), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(3), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(3), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(3) = lv_label_create(FILE_LSIT_BTN_FILE(3), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(3), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(3), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(3) = lv_label_create(FILE_LSIT_BTN_FILE(3), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(3), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(3), FILE_LSIT_PIC_FILE(3), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(3), sd_content.filename[3 + index]);
        FILE_LSIT_BTN_FILE(4) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(4), 110, 110, FILE_LIST_BTN_FILE_ARRAY(4), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(4), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(4), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(4) = lv_label_create(FILE_LSIT_BTN_FILE(4), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(4), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(4), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(4) = lv_label_create(FILE_LSIT_BTN_FILE(4), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(4), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(4), FILE_LSIT_PIC_FILE(4), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(4), sd_content.filename[4 + index]);
        break;
    case 6:
        FILE_LSIT_BTN_FILE(0) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(0), 110, 110, FILE_LIST_BTN_FILE_ARRAY(0), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(0), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(0), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(0), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(0), FILE_LSIT_PIC_FILE(0), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(0), sd_content.filename[0 + index]);
        FILE_LSIT_BTN_FILE(1) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(1), 110, 110, FILE_LIST_BTN_FILE_ARRAY(1), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(1), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(1), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(1), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(1), FILE_LSIT_PIC_FILE(1), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(1), sd_content.filename[1 + index]);
        FILE_LSIT_BTN_FILE(2) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(2), 110, 110, FILE_LIST_BTN_FILE_ARRAY(2), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(2), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(2), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(2), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(2), FILE_LSIT_PIC_FILE(2), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(2), sd_content.filename[2 + index]);
        FILE_LSIT_BTN_FILE(3) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(3), 110, 110, FILE_LIST_BTN_FILE_ARRAY(3), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(3), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(3), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(3) = lv_label_create(FILE_LSIT_BTN_FILE(3), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(3), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(3), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(3) = lv_label_create(FILE_LSIT_BTN_FILE(3), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(3), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(3), FILE_LSIT_PIC_FILE(3), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(3), sd_content.filename[3 + index]);
        FILE_LSIT_BTN_FILE(4) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(4), 110, 110, FILE_LIST_BTN_FILE_ARRAY(4), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(4), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(4), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(4) = lv_label_create(FILE_LSIT_BTN_FILE(4), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(4), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(4), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(4) = lv_label_create(FILE_LSIT_BTN_FILE(4), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(4), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(4), FILE_LSIT_PIC_FILE(4), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(4), sd_content.filename[4 + index]);
        FILE_LSIT_BTN_FILE(5) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(5), 110, 110, FILE_LIST_BTN_FILE_ARRAY(5), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(5), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(5), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(5) = lv_label_create(FILE_LSIT_BTN_FILE(5), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(5), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(5), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(5) = lv_label_create(FILE_LSIT_BTN_FILE(5), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(5), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(5), FILE_LSIT_PIC_FILE(5), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(5), sd_content.filename[5 + index]);
        break;
    case 7:
        FILE_LSIT_BTN_FILE(0) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(0), 110, 110, FILE_LIST_BTN_FILE_ARRAY(0), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(0), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(0), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(0), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(0), FILE_LSIT_PIC_FILE(0), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(0), sd_content.filename[0 + index]);
        FILE_LSIT_BTN_FILE(1) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(1), 110, 110, FILE_LIST_BTN_FILE_ARRAY(1), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(1), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(1), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(1), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(1), FILE_LSIT_PIC_FILE(1), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(1), sd_content.filename[1 + index]);
        FILE_LSIT_BTN_FILE(2) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(2), 110, 110, FILE_LIST_BTN_FILE_ARRAY(2), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(2), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(2), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(2), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(2), FILE_LSIT_PIC_FILE(2), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(2), sd_content.filename[2 + index]);
        FILE_LSIT_BTN_FILE(3) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(3), 110, 110, FILE_LIST_BTN_FILE_ARRAY(3), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(3), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(3), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(3) = lv_label_create(FILE_LSIT_BTN_FILE(3), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(3), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(3), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(3) = lv_label_create(FILE_LSIT_BTN_FILE(3), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(3), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(3), FILE_LSIT_PIC_FILE(3), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(3), sd_content.filename[3 + index]);
        FILE_LSIT_BTN_FILE(4) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(4), 110, 110, FILE_LIST_BTN_FILE_ARRAY(4), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(4), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(4), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(4) = lv_label_create(FILE_LSIT_BTN_FILE(4), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(4), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(4), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(4) = lv_label_create(FILE_LSIT_BTN_FILE(4), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(4), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(4), FILE_LSIT_PIC_FILE(4), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(4), sd_content.filename[4 + index]);
        FILE_LSIT_BTN_FILE(5) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(5), 110, 110, FILE_LIST_BTN_FILE_ARRAY(5), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(5), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(5), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(5) = lv_label_create(FILE_LSIT_BTN_FILE(5), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(5), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(5), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(5) = lv_label_create(FILE_LSIT_BTN_FILE(5), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(5), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(5), FILE_LSIT_PIC_FILE(5), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(5), sd_content.filename[5 + index]);
        FILE_LSIT_BTN_FILE(6) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(6), 110, 110, FILE_LIST_BTN_FILE_ARRAY(6), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(6), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(6), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(6) = lv_label_create(FILE_LSIT_BTN_FILE(6), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(6), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(6), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(6) = lv_label_create(FILE_LSIT_BTN_FILE(6), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(6), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(6), FILE_LSIT_PIC_FILE(6), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(6), sd_content.filename[6 + index]);
        break;
    case 8:
        FILE_LSIT_BTN_FILE(0) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(0), 110, 110, FILE_LIST_BTN_FILE_ARRAY(0), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(0), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(0), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(0), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(0) = lv_label_create(FILE_LSIT_BTN_FILE(0), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(0), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(0), FILE_LSIT_PIC_FILE(0), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(0), sd_content.filename[0 + index]);
        FILE_LSIT_BTN_FILE(1) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(1), 110, 110, FILE_LIST_BTN_FILE_ARRAY(1), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(1), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(1), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(1), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(1) = lv_label_create(FILE_LSIT_BTN_FILE(1), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(1), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(1), FILE_LSIT_PIC_FILE(1), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(1), sd_content.filename[1 + index]);
        FILE_LSIT_BTN_FILE(2) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(2), 110, 110, FILE_LIST_BTN_FILE_ARRAY(2), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(2), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(2), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(2), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(2) = lv_label_create(FILE_LSIT_BTN_FILE(2), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(2), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(2), FILE_LSIT_PIC_FILE(2), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(2), sd_content.filename[2 + index]);
        FILE_LSIT_BTN_FILE(3) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(3), 110, 110, FILE_LIST_BTN_FILE_ARRAY(3), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(3), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(3), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(3) = lv_label_create(FILE_LSIT_BTN_FILE(3), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(3), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(3), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(3) = lv_label_create(FILE_LSIT_BTN_FILE(3), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(3), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(3), FILE_LSIT_PIC_FILE(3), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(3), sd_content.filename[3 + index]);
        FILE_LSIT_BTN_FILE(4) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(4), 110, 110, FILE_LIST_BTN_FILE_ARRAY(4), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(4), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(4), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(4) = lv_label_create(FILE_LSIT_BTN_FILE(4), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(4), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(4), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(4) = lv_label_create(FILE_LSIT_BTN_FILE(4), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(4), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(4), FILE_LSIT_PIC_FILE(4), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(4), sd_content.filename[4 + index]);
        FILE_LSIT_BTN_FILE(5) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(5), 110, 110, FILE_LIST_BTN_FILE_ARRAY(5), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(5), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(5), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(5) = lv_label_create(FILE_LSIT_BTN_FILE(5), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(5), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(5), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(5) = lv_label_create(FILE_LSIT_BTN_FILE(5), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(5), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(5), FILE_LSIT_PIC_FILE(5), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(5), sd_content.filename[5 + index]);
        FILE_LSIT_BTN_FILE(6) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(6), 110, 110, FILE_LIST_BTN_FILE_ARRAY(6), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(6), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(6), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(6) = lv_label_create(FILE_LSIT_BTN_FILE(6), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(6), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(6), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(6) = lv_label_create(FILE_LSIT_BTN_FILE(6), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(6), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(6), FILE_LSIT_PIC_FILE(6), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(6), sd_content.filename[6 + index]);
        FILE_LSIT_BTN_FILE(7) =  lv_btn_set(ui.src, FILE_LSIT_BTN_FILE(7), 110, 110, FILE_LIST_BTN_FILE_ARRAY(7), event_handler);
        lv_btn_set_style(FILE_LSIT_BTN_FILE(7), LV_BTN_STYLE_PR, &file_list_page.btn_pre_style);   // 松开
        lv_btn_set_style(FILE_LSIT_BTN_FILE(7), LV_BTN_STYLE_REL, &file_list_page.btn_rel_style);  // 按下
        FILE_LSIT_PIC_FILE(7) = lv_label_create(FILE_LSIT_BTN_FILE(7), NULL);
        lv_label_set_text(FILE_LSIT_PIC_FILE(7), FONT_PIC_FILE);
        lv_label_set_style(FILE_LSIT_PIC_FILE(7), LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        FILE_LSIT_LABEL_FILE(7) = lv_label_create(FILE_LSIT_BTN_FILE(7), NULL);
        lv_label_set_long_mode(FILE_LSIT_LABEL_FILE(7), LV_LABEL_LONG_SROLL);
        lv_obj_align(FILE_LSIT_LABEL_FILE(7), FILE_LSIT_PIC_FILE(7), LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
        lv_label_set_text(FILE_LSIT_LABEL_FILE(7), sd_content.filename[7 + index]);
        break;
    default:
        break;
    }

}

void del_sd_file_btn()
{
    switch (ui_file_list_page_updata.cur_page_file_num)
    {
    case 1:
        lv_obj_del(FILE_LSIT_BTN_FILE(0));
        break;
    case 2:
        lv_obj_del(FILE_LSIT_BTN_FILE(0));
        lv_obj_del(FILE_LSIT_BTN_FILE(1));
        break;
    case 3:
        lv_obj_del(FILE_LSIT_BTN_FILE(0));
        lv_obj_del(FILE_LSIT_BTN_FILE(1));
        lv_obj_del(FILE_LSIT_BTN_FILE(2));
        break;
    case 4:
        lv_obj_del(FILE_LSIT_BTN_FILE(0));
        lv_obj_del(FILE_LSIT_BTN_FILE(1));
        lv_obj_del(FILE_LSIT_BTN_FILE(2));
        lv_obj_del(FILE_LSIT_BTN_FILE(3));
        break;
    case 5:
        lv_obj_del(FILE_LSIT_BTN_FILE(0));
        lv_obj_del(FILE_LSIT_BTN_FILE(1));
        lv_obj_del(FILE_LSIT_BTN_FILE(2));
        lv_obj_del(FILE_LSIT_BTN_FILE(3));
        lv_obj_del(FILE_LSIT_BTN_FILE(4));
        break;
    case 6:
        lv_obj_del(FILE_LSIT_BTN_FILE(0));
        lv_obj_del(FILE_LSIT_BTN_FILE(1));
        lv_obj_del(FILE_LSIT_BTN_FILE(2));
        lv_obj_del(FILE_LSIT_BTN_FILE(3));
        lv_obj_del(FILE_LSIT_BTN_FILE(4));
        lv_obj_del(FILE_LSIT_BTN_FILE(5));
        break;
    case 7:
        lv_obj_del(FILE_LSIT_BTN_FILE(0));
        lv_obj_del(FILE_LSIT_BTN_FILE(1));
        lv_obj_del(FILE_LSIT_BTN_FILE(2));
        lv_obj_del(FILE_LSIT_BTN_FILE(3));
        lv_obj_del(FILE_LSIT_BTN_FILE(4));
        lv_obj_del(FILE_LSIT_BTN_FILE(5));
        lv_obj_del(FILE_LSIT_BTN_FILE(6));
        break;
    case 8:
        lv_obj_del(FILE_LSIT_BTN_FILE(0));
        lv_obj_del(FILE_LSIT_BTN_FILE(1));
        lv_obj_del(FILE_LSIT_BTN_FILE(2));
        lv_obj_del(FILE_LSIT_BTN_FILE(3));
        lv_obj_del(FILE_LSIT_BTN_FILE(4));
        lv_obj_del(FILE_LSIT_BTN_FILE(5));
        lv_obj_del(FILE_LSIT_BTN_FILE(6));
        lv_obj_del(FILE_LSIT_BTN_FILE(7));
        break;
    default:
        break;
    }
}
/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_file_list_font_pic_color(uint8_t id, bool status) {

    switch(id) {
        case ID_FLIE_LIST_FILE0: 
            if(status) lv_label_set_style(file_list_page.label_pic_file0, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_pic_file0, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_FLIE_LIST_FILE1: 
            if(status) lv_label_set_style(file_list_page.label_pic_file1, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_pic_file1, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_FLIE_LIST_FILE2: 
            if(status) lv_label_set_style(file_list_page.label_pic_file2, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_pic_file2, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_FLIE_LIST_FILE3: 
            if(status) lv_label_set_style(file_list_page.label_pic_file3, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_pic_file3, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_FLIE_LIST_FILE4: 
            if(status) lv_label_set_style(file_list_page.label_pic_file3, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_pic_file3, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_FLIE_LIST_FILE5: 
            if(status) lv_label_set_style(file_list_page.label_pic_file3, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_pic_file3, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_FLIE_LIST_FILE6: 
            if(status) lv_label_set_style(file_list_page.label_pic_file3, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_pic_file3, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;
        case ID_FLIE_LIST_FILE7: 
            if(status) lv_label_set_style(file_list_page.label_pic_file3, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40_pre);
            else lv_label_set_style(file_list_page.label_pic_file3, LV_LABEL_STYLE_MAIN, &ui.di_font_40_40);
        break;

    }

}





void clean_file_list_page(void) {

    lv_obj_clean(ui.src);
}

