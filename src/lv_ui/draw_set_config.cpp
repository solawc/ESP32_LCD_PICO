/***************************************************************************
 *                            include   
***************************************************************************/
#include "draw_set_config.h"

/***************************************************************************
 *                            global   
***************************************************************************/
ui_set_config_t set_config_page;
set_config_data_t set_config_data;
/***************************************************************************
 *                          static function
 * - static void set_set_config_font_pic_color(uint8_t id, bool status) 
 * - static void draw_set_config_bar(void)
 * 
***************************************************************************/
static void set_set_config_font_pic_color(uint8_t id, bool status);
static void draw_set_config_bar(void);
void disp_machine_type_style(MACHINE_TYPE_t date);
void disp_firmware_version_style(FW_VER_t date);
void disp_baud_rate_style(BAUD_RATE_t date);
void disp_number_of_axes_style(NUM_AXES_t date);
void disp_wireless_type_style(WIRELESS_TYPE_t date);
void disp_customize_style(CUSTOMIZE_t date);

/***************************************************************************
 *                              enum 
 * 
***************************************************************************/
enum{

    ID_CNC_TYPE,
    ID_LASER_TYPE,
    ID_WRITE_TYPE,
    ID_NUM_VER1,
    ID_NUM_VER2,
    ID_NUM_VER3,
    ID_9600_RATE,
    ID_115200_RATE,
    ID_250000_RATE,
    ID_2_AXES,
    ID_3_AXES,
    ID_4_AXES,
    ID_WIFI_WIRELESS,
    ID_WIFI_STA_WIRELESS,
    ID_BLUETOOTH_WIRELESS,
    ID_1_CUSTOMIZE,
    ID_2_CUSTOMIZE,
    ID_3_CUSTOMIZE,
    ID_PREVIOUS,
    ID_NEXT,

};

/***************************************************************************
 *                              Function 
 * 
***************************************************************************/
static uint8_t get_event(lv_obj_t* obj) {
   if(obj == set_config_page.btn_type1) return ID_CNC_TYPE;
   else if(obj == set_config_page.btn_type2) return ID_LASER_TYPE;
   else if(obj == set_config_page.btn_type3) return ID_WRITE_TYPE;
   else if(obj == set_config_page.btn_ver1) return ID_NUM_VER1;
   else if(obj == set_config_page.btn_ver2) return ID_NUM_VER2;
   else if(obj == set_config_page.btn_ver3) return ID_NUM_VER3;
   else if(obj == set_config_page.btn_rate1) return ID_9600_RATE;
   else if(obj == set_config_page.btn_rate2) return ID_115200_RATE;
   else if(obj == set_config_page.btn_rate3) return ID_250000_RATE;
   else if(obj == set_config_page.btn_axes1) return ID_2_AXES;
   else if(obj == set_config_page.btn_axes2) return ID_3_AXES;
   else if(obj == set_config_page.btn_axes3) return ID_4_AXES;
   else if(obj == set_config_page.btn_wireless_type1) return ID_WIFI_WIRELESS;
   else if(obj == set_config_page.btn_wireless_type2) return ID_WIFI_STA_WIRELESS;
   else if(obj == set_config_page.btn_wireless_type3) return ID_BLUETOOTH_WIRELESS;
   else if(obj == set_config_page.btn_customize1) return ID_1_CUSTOMIZE;
   else if(obj == set_config_page.btn_customize2) return ID_2_CUSTOMIZE;
   else if(obj == set_config_page.btn_customize3) return ID_3_CUSTOMIZE;
   else if(obj == set_config_page.btn_previos) return ID_PREVIOUS;
   else if(obj == set_config_page.btn_next) return ID_NEXT;
//    else if(obj == set_config_page.btn_back) return ID_SET_CONFIG_BACK;
}


static void event_handler(lv_obj_t* obj, lv_event_t event) {

    uint8_t id = get_event(obj);
    uint16_t temp_data;
    if(event == LV_EVENT_PRESSED) {
    
        set_set_config_font_pic_color(id, true);

        switch(id) {
            case ID_CNC_TYPE: 
                temp_data = TYPE_CNC;
                disp_machine_type_style((MACHINE_TYPE_t)temp_data);
            break;

            case ID_LASER_TYPE:
                temp_data = TYPE_LASER;
                disp_machine_type_style((MACHINE_TYPE_t)temp_data);
            break;

            case ID_WRITE_TYPE: 
                temp_data = TYPE_WRITE;
                disp_machine_type_style((MACHINE_TYPE_t)temp_data);
            break; 
            case ID_NUM_VER1:
                temp_data = FW_VER_GRBL09;
                disp_firmware_version_style((FW_VER_t)temp_data);
            break;

            case ID_NUM_VER2:
                temp_data = FW_VER_GRBL10;
                disp_firmware_version_style((FW_VER_t)temp_data);
            break;
            case ID_NUM_VER3:
                temp_data = FW_VER_DLC32;
                disp_firmware_version_style((FW_VER_t)temp_data);
            break;
            case ID_9600_RATE:
                temp_data = RATE_9600;
                disp_baud_rate_style((BAUD_RATE_t)temp_data);
            break;
            case ID_115200_RATE:
                temp_data = RATE_115200;
                disp_baud_rate_style((BAUD_RATE_t)temp_data);
            break;
            case ID_250000_RATE:
                temp_data = RATE_250000;
                disp_baud_rate_style((BAUD_RATE_t)temp_data);
            break;
            case ID_2_AXES:
                temp_data = NUM_AXES_2;
                disp_number_of_axes_style((NUM_AXES_t)temp_data);
            break;
            case ID_3_AXES:
                temp_data = NUM_AXES_3;
                disp_number_of_axes_style((NUM_AXES_t)temp_data);
            break;
            case ID_4_AXES:
                temp_data = NUM_AXES_4;
                disp_number_of_axes_style((NUM_AXES_t)temp_data);
            break;
            case ID_WIFI_WIRELESS:
                temp_data = WIRELESS_TYPE_WIFI_AP;
                disp_wireless_type_style((WIRELESS_TYPE_t)temp_data);
            break;
            case ID_WIFI_STA_WIRELESS:
                temp_data = WIRELESS_TYPE_WIFI_STA;
                disp_wireless_type_style((WIRELESS_TYPE_t)temp_data);
            break;
            case ID_BLUETOOTH_WIRELESS:
                temp_data = WIRELESS_TYPE_BLUETOOTH;
                disp_wireless_type_style((WIRELESS_TYPE_t)temp_data);
            break;
            case ID_1_CUSTOMIZE:
                temp_data = CUSTOMIZE_1;
                disp_customize_style((CUSTOMIZE_t)temp_data);
            break;
            case ID_2_CUSTOMIZE:
                temp_data = CUSTOMIZE_2;
                disp_customize_style((CUSTOMIZE_t)temp_data);
            break;
            case ID_3_CUSTOMIZE:
                temp_data = CUSTOMIZE_3;
                disp_customize_style((CUSTOMIZE_t)temp_data);
            break;
            case ID_PREVIOUS:
            
            break;
            case ID_NEXT:

            break;
        }
    }
    // Machine_type_num->setStringValue();
    // set_config_data.machine_type = (MACHINE_TYPE_t)(Machine_type_num->get());
    // set_config_data.fw_ver = (FW_VER_t)(Firmware_ver_num->get());
    // set_config_data.rate = (BAUD_RATE_t)(Baud_rate->get());
    // set_config_data.axes = (NUM_AXES_t)(Num_of_axes->get());
    // set_config_data.wireless_type = (WIRELESS_TYPE_t)(Wireless_type->get());
    // set_config_data.customize = (CUSTOMIZE_t)(Customize_num->get());
    int val = 10;
    if((event == LV_EVENT_RELEASED) || (event == LV_EVENT_PRESS_LOST)) {

        set_set_config_font_pic_color(id, false);
        // serial_send(CLIENT_SERIAL,"HELLO\n");
        switch(id) {
            case ID_CNC_TYPE: 
                // int val = 10;
                val = 1;
                xQueueSend( setting_w_queue, &val, 0xffff);
            break;

            case ID_LASER_TYPE:
                // set_config_data.machine_type = TYPE_LASER;
                val = 2;
                xQueueSend( setting_w_queue, &val, 0xffff);
            break;

            case ID_WRITE_TYPE: 
                val = 3;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.machine_type = TYPE_WRITE;
                // Machine_type_num->setStringValue("3");
            break; 
            case ID_NUM_VER1:
                val = 4;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.fw_ver = FW_VER_GRBL09;
                // Firmware_ver_num->setStringValue("1");
            break;

            case ID_NUM_VER2:
                val = 5;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.fw_ver = FW_VER_GRBL10;
                // Firmware_ver_num->setStringValue("2");

            break;
            case ID_NUM_VER3:
                val = 6;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.fw_ver = FW_VER_DLC32;
                // Firmware_ver_num->setStringValue("3");
            break;
            case ID_9600_RATE:
                val = 7;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.rate = RATE_9600;
                // Baud_rate->setStringValue("1");
            break;
            case ID_115200_RATE:
                val = 8;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.rate = RATE_115200;
                // Baud_rate->setStringValue("2");
            break;
            case ID_250000_RATE:
                val = 9;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.rate = RATE_250000;
                // Baud_rate->setStringValue("3");
            break;
            case ID_2_AXES:
                val = 10;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.axes = NUM_AXES_2;
                // Num_of_axes->setStringValue("1");
            break;
            case ID_3_AXES:
                val = 11;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.axes = NUM_AXES_3;
                // Num_of_axes->setStringValue("2");
            break;
            case ID_4_AXES:
                val = 12;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.axes = NUM_AXES_4;
                // Num_of_axes->setStringValue("3");
            break;
            case ID_WIFI_WIRELESS:
                val = 13;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.wireless_type = WIRELESS_TYPE_WIFI_AP;
                // Wireless_type->setStringValue("1");
            break;
            case ID_WIFI_STA_WIRELESS:
                val = 14;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.wireless_type = WIRELESS_TYPE_WIFI_STA;
                // Wireless_type->setStringValue("2");
            break;
            case ID_BLUETOOTH_WIRELESS:
                val = 15;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.wireless_type = WIRELESS_TYPE_BLUETOOTH;
                // Wireless_type->setStringValue("3");
            break;
            case ID_1_CUSTOMIZE:
                val = 16;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.customize = CUSTOMIZE_1;
                // Customize_num->setStringValue("1");
            break;
            case ID_2_CUSTOMIZE:
                val = 17;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.customize = CUSTOMIZE_2;
                // Customize_num->setStringValue("2");
            break;
            case ID_3_CUSTOMIZE:
                val = 19;
                xQueueSend( setting_w_queue, &val, 0xffff);
                // set_config_data.customize = CUSTOMIZE_3;
                // Customize_num->setStringValue("3");
            break;
            case ID_PREVIOUS:
                clean_set_config_page();
                draw_init_set_Initialize();
            break;
            case ID_NEXT:
                // char buff[30];
                // memset(buff,0,sizeof(buff));
                // sprintf(buff,"%d",set_config_data.machine_type);
                // Machine_type_num->setStringValue(buff);
                // memset(buff,0,sizeof(buff));
                // sprintf(buff,"%d",set_config_data.fw_ver);
                // Firmware_ver_num->setStringValue(buff);
                // memset(buff,0,sizeof(buff));
                // sprintf(buff,"%d",set_config_data.rate);
                // Baud_rate->setStringValue(buff);
                // memset(buff,0,sizeof(buff));
                // sprintf(buff,"%d",set_config_data.axes);
                // Num_of_axes->setStringValue(buff);
                // memset(buff,0,sizeof(buff));
                // sprintf(buff,"%d",set_config_data.wireless_type);
                // Wireless_type->setStringValue(buff);
                // memset(buff,0,sizeof(buff));
                // sprintf(buff,"%d",set_config_data.customize);
                // Customize_num->setStringValue(buff);
                clean_set_config_page();
                draw_init_set_complete();
            break;
            }
    }
}

static void draw_set_config_bar(void) {

    ui.src_1 = lv_obj_create(ui.src, NULL);
    lv_obj_set_size(ui.src_1, 480, 76);
    lv_obj_set_pos(ui.src_1, 0, 0);
    lv_obj_set_style(ui.src_1, &ui.src_1_style);
    
}

#define SET_CNC_EN "CNC"
#define SET_LASER_EN  "Laser"
#define SET_WRITE_EN  "Write"
#define SET_GRBL09_EN  "GRBL 0.9"
#define SET_GRBL10_EN  "GRBL 1.0"
#define SET_DLC32_EN  "DLC32"
#define SET_RATE_9600_EN  "9600"
#define SET_RATE_115200_EN  "115200"
#define SET_RATE_250000_EN  "250000"
#define SET_2_AXES_EN  "2 axes"
#define SET_3_AXES_EN  "3 axes"
#define SET_4_AXES_EN  "4 axes"
#define SET_WIFI_AP_EN  "WIFI-AP"
#define SET_WIFI_STA_EN  "WIFI-STA"
#define SET_BLUETOOTH_EN  "Bluetooth"
#define SET_CUSTOMIZE1_EN  "Customize 1"
#define SET_CUSTOMIZE2_EN  "Customize 2"
#define SET_CUSTOMIZE3_EN  "Customize 3"
#define SET_PREVIOUS_EN  "Previous"
#define SET_NEXT_EN  "Next"

#define SET_MACHINE_TYPE_EN  "Machine type :"
#define SET_FW_VERSION_EN  "Firmware version :"
#define SET_BAUD_RATE_EN  "Baud rate :"
#define SET_NUM_AXES_EN  "Number of axes :"
#define SET_WIRELESS_TYPE_EN  "Wireless type :"


void draw_set_config(void) {
    
    // draw_set_config_bar();
    lv_style_copy(&set_config_page.label_style , &lv_style_scr);
    set_config_page.label_style.text.color = LV_COLOR_WHITE;

    lv_style_copy(&set_config_page.btn_pre_style , &lv_style_scr);
    set_config_page.btn_pre_style.body.grad_color = lv_color_hex(get_current_color());;
	set_config_page.btn_pre_style.body.main_color = lv_color_hex(get_current_color());;
    set_config_page.btn_pre_style.body.radius = 5;
    set_config_page.btn_pre_style.text.color = lv_color_hex(0x191919);
    
    lv_style_copy(&set_config_page.btn_rel_style , &lv_style_scr);
    set_config_page.btn_rel_style.body.grad_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
	set_config_page.btn_rel_style.body.main_color = lv_color_hex(F_THEME_BTN_REL_COLOR);
    set_config_page.btn_rel_style.body.radius = 5;
    set_config_page.btn_rel_style.text.color = lv_color_hex(get_current_color());  //ui.ui_theme.font_rel_color  

    set_config_page.btn_type1 =  lv_btn_set(ui.src, set_config_page.btn_type1, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X1, SET_CONFIG_BTN1_Y1, event_handler);
    set_config_page.btn_type2 =  lv_btn_set(ui.src, set_config_page.btn_type2, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X2, SET_CONFIG_BTN1_Y1, event_handler);
    set_config_page.btn_type3 =  lv_btn_set(ui.src, set_config_page.btn_type3, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X3, SET_CONFIG_BTN1_Y1, event_handler);

    set_config_page.btn_ver1 =  lv_btn_set(ui.src, set_config_page.btn_ver1, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X1, SET_CONFIG_BTN1_Y2, event_handler);
    set_config_page.btn_ver2 =  lv_btn_set(ui.src, set_config_page.btn_ver2, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X2, SET_CONFIG_BTN1_Y2, event_handler);
    set_config_page.btn_ver3 =  lv_btn_set(ui.src, set_config_page.btn_ver3, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X3, SET_CONFIG_BTN1_Y2, event_handler);

    set_config_page.btn_rate1 =  lv_btn_set(ui.src, set_config_page.btn_rate1, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X1, SET_CONFIG_BTN1_Y3, event_handler);
    set_config_page.btn_rate2 =  lv_btn_set(ui.src, set_config_page.btn_rate2, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X2, SET_CONFIG_BTN1_Y3, event_handler);
    set_config_page.btn_rate3 =  lv_btn_set(ui.src, set_config_page.btn_rate3, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X3, SET_CONFIG_BTN1_Y3, event_handler);

    set_config_page.btn_axes1 =  lv_btn_set(ui.src, set_config_page.btn_axes1, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X1, SET_CONFIG_BTN1_Y4, event_handler);
    set_config_page.btn_axes2 =  lv_btn_set(ui.src, set_config_page.btn_axes2, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X2, SET_CONFIG_BTN1_Y4, event_handler);
    set_config_page.btn_axes3 =  lv_btn_set(ui.src, set_config_page.btn_axes3, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X3, SET_CONFIG_BTN1_Y4, event_handler);

    set_config_page.btn_wireless_type1 =  lv_btn_set(ui.src, set_config_page.btn_wireless_type1, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X1, SET_CONFIG_BTN1_Y5, event_handler);
    set_config_page.btn_wireless_type2 =  lv_btn_set(ui.src, set_config_page.btn_wireless_type2, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X2, SET_CONFIG_BTN1_Y5, event_handler);
    set_config_page.btn_wireless_type3 =  lv_btn_set(ui.src, set_config_page.btn_wireless_type3, SET_CONFIG_BTN_W1, SET_CONFIG_BTN_H1, SET_CONFIG_BTN1_X3, SET_CONFIG_BTN1_Y5, event_handler);

    set_config_page.btn_customize1 =  lv_btn_set(ui.src, set_config_page.btn_customize1, SET_CONFIG_BTN_W2, SET_CONFIG_BTN_H2, SET_CONFIG_BTN2_X1, SET_CONFIG_BTN2_Y, event_handler);
    set_config_page.btn_customize2 =  lv_btn_set(ui.src, set_config_page.btn_customize2, SET_CONFIG_BTN_W2, SET_CONFIG_BTN_H2, SET_CONFIG_BTN2_X2, SET_CONFIG_BTN2_Y, event_handler);
    set_config_page.btn_customize3 =  lv_btn_set(ui.src, set_config_page.btn_customize3, SET_CONFIG_BTN_W2, SET_CONFIG_BTN_H2, SET_CONFIG_BTN2_X3, SET_CONFIG_BTN2_Y, event_handler);

    set_config_page.btn_previos =  lv_btn_set(ui.src, set_config_page.btn_previos, SET_CONFIG_BTN_W3, SET_CONFIG_BTN_H3, SET_CONFIG_BTN3_X1, SET_CONFIG_BTN3_Y, event_handler);
    set_config_page.btn_next =  lv_btn_set(ui.src, set_config_page.btn_next, SET_CONFIG_BTN_W3, SET_CONFIG_BTN_H3, SET_CONFIG_BTN3_X2, SET_CONFIG_BTN3_Y, event_handler);




    lv_btn_set_style(set_config_page.btn_previos, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);   
    lv_btn_set_style(set_config_page.btn_previos, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);  

    lv_btn_set_style(set_config_page.btn_next, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
    lv_btn_set_style(set_config_page.btn_next, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

    set_config_page.label_type1 = lv_label_create(set_config_page.btn_type1, NULL);
    lv_label_set_text(set_config_page.label_type1, SET_CNC_EN);

    set_config_page.label_type2 = lv_label_create(set_config_page.btn_type2, NULL);
    lv_label_set_text(set_config_page.label_type2, SET_LASER_EN);

    set_config_page.label_type3 = lv_label_create(set_config_page.btn_type3, NULL);
    lv_label_set_text(set_config_page.label_type3, SET_WRITE_EN);

    set_config_page.label_ver1 = lv_label_create(set_config_page.btn_ver1, NULL);
    lv_label_set_text(set_config_page.label_ver1,SET_GRBL09_EN);

    set_config_page.label_ver2 = lv_label_create(set_config_page.btn_ver2, NULL);
    lv_label_set_text(set_config_page.label_ver2,SET_GRBL10_EN);

    set_config_page.label_ver3 = lv_label_create(set_config_page.btn_ver3, NULL);
    lv_label_set_text(set_config_page.label_ver3,SET_DLC32_EN);

    set_config_page.label_rate1 = lv_label_create(set_config_page.btn_rate1, NULL);
    lv_label_set_text(set_config_page.label_rate1,SET_RATE_9600_EN);

    set_config_page.label_rate2 = lv_label_create(set_config_page.btn_rate2, NULL);
    lv_label_set_text(set_config_page.label_rate2,SET_RATE_115200_EN);

    set_config_page.label_rate3 = lv_label_create(set_config_page.btn_rate3, NULL);
    lv_label_set_text(set_config_page.label_rate3,SET_RATE_250000_EN);

    set_config_page.label_axes1 = lv_label_create(set_config_page.btn_axes1, NULL);
    lv_label_set_text(set_config_page.label_axes1,SET_2_AXES_EN);

    set_config_page.label_axes2 = lv_label_create(set_config_page.btn_axes2, NULL);
    lv_label_set_text(set_config_page.label_axes2,SET_3_AXES_EN);

    set_config_page.label_axes3 = lv_label_create(set_config_page.btn_axes3, NULL);
    lv_label_set_text(set_config_page.label_axes3,SET_4_AXES_EN);

    set_config_page.label_wireless_type1 = lv_label_create(set_config_page.btn_wireless_type1, NULL);
    lv_label_set_text(set_config_page.label_wireless_type1,SET_WIFI_AP_EN);

    set_config_page.label_wireless_type2 = lv_label_create(set_config_page.btn_wireless_type2, NULL);
    lv_label_set_text(set_config_page.label_wireless_type2,SET_WIFI_STA_EN);

    set_config_page.label_wireless_type3 = lv_label_create(set_config_page.btn_wireless_type3, NULL);
    lv_label_set_text(set_config_page.label_wireless_type3,SET_BLUETOOTH_EN);

    set_config_page.label_customize1 = lv_label_create(set_config_page.btn_customize1, NULL);
    lv_label_set_text(set_config_page.label_customize1,SET_CUSTOMIZE1_EN);

    set_config_page.label_customize2 = lv_label_create(set_config_page.btn_customize2, NULL);
    lv_label_set_text(set_config_page.label_customize2,SET_CUSTOMIZE2_EN);

    set_config_page.label_customize3 = lv_label_create(set_config_page.btn_customize3, NULL);
    lv_label_set_text(set_config_page.label_customize3,SET_CUSTOMIZE3_EN);

    set_config_page.label_previos = lv_label_create(set_config_page.btn_previos, NULL);
    lv_label_set_text(set_config_page.label_previos,SET_PREVIOUS_EN);

    set_config_page.label_next = lv_label_create(set_config_page.btn_next, NULL);
    lv_label_set_text(set_config_page.label_next,SET_NEXT_EN);

    set_config_page.label_machine_type = lv_label_create(ui.src, NULL);
    lv_obj_align(set_config_page.label_machine_type, set_config_page.btn_type1, LV_ALIGN_OUT_LEFT_MID, -115, 0);
    lv_label_set_text(set_config_page.label_machine_type,SET_MACHINE_TYPE_EN);
    lv_label_set_align(set_config_page.label_machine_type,LV_LABEL_ALIGN_RIGHT);

    set_config_page.label_fw_version = lv_label_create(ui.src, NULL);
    lv_obj_align(set_config_page.label_fw_version, set_config_page.label_machine_type, LV_ALIGN_OUT_BOTTOM_RIGHT, -105, 12);
    lv_label_set_text(set_config_page.label_fw_version,SET_FW_VERSION_EN);
    lv_label_set_align(set_config_page.label_fw_version,LV_LABEL_ALIGN_RIGHT);

    set_config_page.label_baud_rate = lv_label_create(ui.src, NULL);
    lv_obj_set_size(set_config_page.label_baud_rate,130,19);
    lv_obj_align(set_config_page.label_baud_rate, set_config_page.label_fw_version, LV_ALIGN_OUT_BOTTOM_MID, 3, 15);
    lv_label_set_text(set_config_page.label_baud_rate,SET_BAUD_RATE_EN);
    lv_label_set_align(set_config_page.label_baud_rate,LV_LABEL_ALIGN_RIGHT);

    set_config_page.label_num_of_axes = lv_label_create(ui.src, NULL);
    lv_obj_set_size(set_config_page.label_num_of_axes,130,19);
    lv_obj_align(set_config_page.label_num_of_axes, set_config_page.label_baud_rate, LV_ALIGN_OUT_BOTTOM_MID, -65, 15);
    lv_label_set_text(set_config_page.label_num_of_axes,SET_NUM_AXES_EN);
    lv_label_set_align(set_config_page.label_num_of_axes,LV_LABEL_ALIGN_RIGHT);

    set_config_page.label_wireless_type = lv_label_create(ui.src, NULL);
    lv_obj_set_size(set_config_page.label_wireless_type,130,19);
    lv_obj_align(set_config_page.label_wireless_type, set_config_page.label_num_of_axes, LV_ALIGN_OUT_BOTTOM_MID, -30, 15);
    lv_label_set_text(set_config_page.label_wireless_type,SET_WIRELESS_TYPE_EN);
    lv_label_set_align(set_config_page.label_wireless_type,LV_LABEL_ALIGN_RIGHT);

    // set_config_page.label_back = lv_label_create(set_config_page.btn_back, NULL);
    // lv_obj_align(set_config_page.label_back, set_config_page.label_back_pic, LV_ALIGN_OUT_BOTTOM_MID, 0, 30);
    // lv_label_set_text(set_config_page.label_back,LANGUAGE_BACK_EN);
    

    // disp_machine_type_style((MACHINE_TYPE_t)(Machine_type_num->get()));
    // disp_firmware_version_style((FW_VER_t)(Firmware_ver_num->get()));
    // disp_baud_rate_style((BAUD_RATE_t)(Baud_rate->get()));
    // disp_number_of_axes_style((NUM_AXES_t)(Num_of_axes->get()));
    // disp_wireless_type_style((WIRELESS_TYPE_t)(Wireless_type->get()));
    // disp_customize_style((CUSTOMIZE_t)(Customize_num->get()));

    set_config_data.machine_type = (MACHINE_TYPE_t)(Machine_type_num->get());
    set_config_data.fw_ver = (FW_VER_t)(Firmware_ver_num->get());
    set_config_data.rate = (BAUD_RATE_t)(Baud_rate->get());
    set_config_data.axes = (NUM_AXES_t)(Num_of_axes->get());
    set_config_data.wireless_type = (WIRELESS_TYPE_t)(Wireless_type->get());
    set_config_data.customize = (CUSTOMIZE_t)(Customize_num->get());


    disp_machine_type_style(set_config_data.machine_type);
    disp_firmware_version_style(set_config_data.fw_ver);
    disp_baud_rate_style(set_config_data.rate);
    disp_number_of_axes_style(set_config_data.axes);
    disp_wireless_type_style(set_config_data.wireless_type);
    disp_customize_style(set_config_data.customize);

}

/* 
 *  update font pic color
 *  status: true:press, false:relase

*/
static void set_set_config_font_pic_color(uint8_t id, bool status) {

    // switch(id) {
    //     case ID_CNC_TYPE: 
    //         if(status) lv_label_set_style(set_config_page.label_type1_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(set_config_page.label_type1_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_LASER_TYPE: 
    //         if(status) lv_label_set_style(set_config_page.label_type2_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(set_config_page.label_type2_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_WRITE_TYPE: 
    //         if(status) lv_label_set_style(set_config_page.label_type3_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(set_config_page.label_type3_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    //     case ID_NUM_VER1: 
    //         if(status) lv_label_set_style(set_config_page.label_ver1_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60_pre);
    //         else lv_label_set_style(set_config_page.label_ver1_pic, LV_LABEL_STYLE_MAIN, &ui.di_font_60_60);
    //     break;
    // }

}



void disp_machine_type_style(MACHINE_TYPE_t date)
{
    switch (date)
    {
    case TYPE_CNC:
        lv_btn_set_style(set_config_page.btn_type1, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_type1, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_type2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_type2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_type3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_type3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case TYPE_LASER:
        lv_btn_set_style(set_config_page.btn_type1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_type1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_type2, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_type2, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_type3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_type3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case TYPE_WRITE:
        lv_btn_set_style(set_config_page.btn_type1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_type1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_type2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_type2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_type3, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_type3, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);
        break;
    }
}
void disp_firmware_version_style(FW_VER_t date)
{
    switch (date)
    {
    case FW_VER_GRBL09:
        lv_btn_set_style(set_config_page.btn_ver1, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_ver1, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_ver2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_ver2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_ver3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_ver3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case FW_VER_GRBL10:
        lv_btn_set_style(set_config_page.btn_ver1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_ver1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_ver2, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_ver2, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_ver3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_ver3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case FW_VER_DLC32:
        lv_btn_set_style(set_config_page.btn_ver1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_ver1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_ver2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_ver2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_ver3, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_ver3, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);
        break;
    }
}
void disp_baud_rate_style(BAUD_RATE_t date)
{
    switch (date)
    {
    case RATE_9600:
        lv_btn_set_style(set_config_page.btn_rate1, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_rate1, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_rate2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_rate2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_rate3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_rate3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case RATE_115200:
        lv_btn_set_style(set_config_page.btn_rate1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_rate1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_rate2, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_rate2, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_rate3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_rate3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case RATE_250000:
        lv_btn_set_style(set_config_page.btn_rate1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_rate1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_rate2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_rate2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_rate3, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_rate3, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);
        break;
    }
}
void disp_number_of_axes_style(NUM_AXES_t date)
{
    switch (date)
    {
    case NUM_AXES_2:
        lv_btn_set_style(set_config_page.btn_axes1, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_axes1, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_axes2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_axes2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_axes3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_axes3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case NUM_AXES_3:
        lv_btn_set_style(set_config_page.btn_axes1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_axes1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_axes2, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_axes2, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_axes3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_axes3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case NUM_AXES_4:
        lv_btn_set_style(set_config_page.btn_axes1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_axes1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_axes2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_axes2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_axes3, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_axes3, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);
        break;
    }
}
void disp_wireless_type_style(WIRELESS_TYPE_t date)
{
    switch (date)
    {
    case WIRELESS_TYPE_WIFI_AP:
        lv_btn_set_style(set_config_page.btn_wireless_type1, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_wireless_type1, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_wireless_type2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_wireless_type2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_wireless_type3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_wireless_type3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case WIRELESS_TYPE_WIFI_STA:
        lv_btn_set_style(set_config_page.btn_wireless_type1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_wireless_type1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_wireless_type2, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_wireless_type2, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_wireless_type3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_wireless_type3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case WIRELESS_TYPE_BLUETOOTH:
        lv_btn_set_style(set_config_page.btn_wireless_type1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_wireless_type1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_wireless_type2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_wireless_type2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_wireless_type3, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_wireless_type3, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);
        break;
    }
}
void disp_customize_style(CUSTOMIZE_t date)
{
    switch (date)
    {
    case CUSTOMIZE_1:
        lv_btn_set_style(set_config_page.btn_customize1, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_customize1, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_customize2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_customize2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_customize3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_customize3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case CUSTOMIZE_2:
        lv_btn_set_style(set_config_page.btn_customize1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_customize1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_customize2, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_customize2, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);

        lv_btn_set_style(set_config_page.btn_customize3, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_customize3, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);
        break;
    case CUSTOMIZE_3:
        lv_btn_set_style(set_config_page.btn_customize1, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_customize1, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_customize2, LV_BTN_STYLE_PR, &set_config_page.btn_rel_style);
        lv_btn_set_style(set_config_page.btn_customize2, LV_BTN_STYLE_REL, &set_config_page.btn_rel_style);

        lv_btn_set_style(set_config_page.btn_customize3, LV_BTN_STYLE_PR, &set_config_page.btn_pre_style);
        lv_btn_set_style(set_config_page.btn_customize3, LV_BTN_STYLE_REL, &set_config_page.btn_pre_style);
        break;
    }
}
void clean_set_config_page(void) {

    lv_obj_clean(ui.src);
}

