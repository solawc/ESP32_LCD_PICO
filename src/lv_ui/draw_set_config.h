#pragma once

/***************************************************************************
 *                            include   
***************************************************************************/
#include "../main.h"

/***************************************************************************
 *                            typedef struct    
***************************************************************************/

typedef struct{
    lv_obj_t *btn_type1;
    lv_obj_t *btn_type2;
    lv_obj_t *btn_type3;
    lv_obj_t *btn_ver1;
    lv_obj_t *btn_ver2;
    lv_obj_t *btn_ver3;
    lv_obj_t *btn_rate1;
    lv_obj_t *btn_rate2;
    lv_obj_t *btn_rate3;
    lv_obj_t *btn_axes1;
    lv_obj_t *btn_axes2;
    lv_obj_t *btn_axes3;
    lv_obj_t *btn_wireless_type1;
    lv_obj_t *btn_wireless_type2;
    lv_obj_t *btn_wireless_type3;
    lv_obj_t *btn_customize1;
    lv_obj_t *btn_customize2;
    lv_obj_t *btn_customize3;
    lv_obj_t *btn_previos;
    lv_obj_t *btn_next;

    lv_style_t btn_pre_style;
    lv_style_t btn_rel_style;
    lv_style_t label_style;

    lv_obj_t *label_type1;
    lv_obj_t *label_type2;
    lv_obj_t *label_type3;
    lv_obj_t *label_ver1;
    lv_obj_t *label_ver2;
    lv_obj_t *label_ver3;
    lv_obj_t *label_rate1;
    lv_obj_t *label_rate2;
    lv_obj_t *label_rate3;
    lv_obj_t *label_axes1;
    lv_obj_t *label_axes2;
    lv_obj_t *label_axes3;
    lv_obj_t *label_wireless_type1;
    lv_obj_t *label_wireless_type2;
    lv_obj_t *label_wireless_type3;
    lv_obj_t *label_customize1;
    lv_obj_t *label_customize2;
    lv_obj_t *label_customize3;
    lv_obj_t *label_previos;
    lv_obj_t *label_next;


    lv_obj_t *label_machine_type;
    lv_obj_t *label_fw_version;
    lv_obj_t *label_baud_rate;
    lv_obj_t *label_num_of_axes;
    lv_obj_t *label_wireless_type;

    lv_obj_t *btn_back;
    lv_obj_t *label_back;


}ui_set_config_t;

typedef enum{
    TYPE_CNC=1,
    TYPE_LASER,
    TYPE_WRITE,
}MACHINE_TYPE_t;

typedef enum{
    FW_VER_GRBL09=1,
    FW_VER_GRBL10,
    FW_VER_DLC32,
}FW_VER_t;

typedef enum{
    RATE_9600=1,
    RATE_115200,
    RATE_250000,
}BAUD_RATE_t;

typedef enum{
    NUM_AXES_2=1,
    NUM_AXES_3,
    NUM_AXES_4,
}NUM_AXES_t;

typedef enum{
    WIRELESS_TYPE_WIFI_AP=1,
    WIRELESS_TYPE_WIFI_STA,
    WIRELESS_TYPE_BLUETOOTH,
}WIRELESS_TYPE_t;

typedef enum{
    CUSTOMIZE_1=1,
    CUSTOMIZE_2,
    CUSTOMIZE_3,
}CUSTOMIZE_t;

typedef struct{
    MACHINE_TYPE_t machine_type = TYPE_CNC;
    FW_VER_t fw_ver = FW_VER_GRBL09;
    BAUD_RATE_t rate = RATE_9600;
    NUM_AXES_t axes = NUM_AXES_2;
    WIRELESS_TYPE_t wireless_type = WIRELESS_TYPE_WIFI_AP;
    CUSTOMIZE_t customize = CUSTOMIZE_1;
}set_config_data_t;


#define SET_CONFIG_BTN1_X1 192
#define SET_CONFIG_BTN1_X2 287
#define SET_CONFIG_BTN1_X3 382

#define SET_CONFIG_BTN2_X1 18
#define SET_CONFIG_BTN2_X2 190
#define SET_CONFIG_BTN2_X3 362

#define SET_CONFIG_BTN3_X1 8
#define SET_CONFIG_BTN3_X2 322


#define SET_CONFIG_BTN1_Y1 8
#define SET_CONFIG_BTN1_Y2 46
#define SET_CONFIG_BTN1_Y3 84
#define SET_CONFIG_BTN1_Y4 122
#define SET_CONFIG_BTN1_Y5 160
#define SET_CONFIG_BTN1_Y6 202

#define SET_CONFIG_BTN2_Y 210

#define SET_CONFIG_BTN3_Y 252

#define SET_CONFIG_BTN_W1  80
#define SET_CONFIG_BTN_H1  30

#define SET_CONFIG_BTN_W2  100
#define SET_CONFIG_BTN_H2  30

#define SET_CONFIG_BTN_W3 150
#define SET_CONFIG_BTN_H3 60


/***************************************************************************
 *                              extern
***************************************************************************/

void draw_set_config(void);
void clean_set_config_page(void);