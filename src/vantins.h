#ifndef __vantins_h__
#define __vantins_h__

#include "main.h"

#define EEPROM_VERSION      "20221226"
#define BOARD_NAME          "ESP32_LCD_PICO"
#define FW_VERSION          "PICO_V20221226_001"
#define UPDATA_DATA         "2022-12-26"

/* for ESP32, main core is core 1 */
#define SUPPORT_TASK_CORE 1  // Reference: CONFIG_ARDUINO_RUNNING_CORE = 1

/* 
    select touch type
*/
#define SUPPORT_TOUCH_SELECT
#ifdef SUPPORT_TOUCH_SELECT
// #define USE_FT6336_TOUCH
// #define USE_XPT2046_TOUCH
#endif // SUPPORT_TOUCH_SELECT

/*
    if you don't want to disp, you can undef this
*/
// #define USE_CUSTOM_LOGO

/*
    TODO
*/
// #define USE_SD_CARD


/*
            Serial LCD Config
 -BAUD_RATE: defaule is 115200
 -SET_LCD_DIR: (0...3)
 -USE_NVS: default is enable
*/
#define USR_TFT_LCD_CONFIG
#ifdef USR_TFT_LCD_CONFIG
    #define BAUD_RATE                               115200          // default is 115200
    #define SET_LCD_DIR                             1               // default is 1
    // #define USE_NVS                                              // TODO. nvs is eeprom at ESP32
    // #define USE_LCD_DMA                                          // default is false
#endif // USR_TFT_LCD_CONFIG


/*
        Support Machine
*/
#define SUPPORT_MACHINE
#ifdef SUPPORT_MACHINE
    // #define USE_FDM_NANO_V3
    // #define USE_DLC32_LASER
    #define USE_DLC32_CNC
#else 
#error:"please select machine."
#endif //SUPPORT_MACHINE


typedef enum {
    TYPE_MC_FMD_MARLIN_2_0,
    TYPE_MC_32_GRBL_CNC,
    TYPE_MC_32_GRBL_LASER,
    TYPE_MC_8_GRBL_1_1_CNC,
    TYPE_MC_8_GRBL_1_1_LASER,
    TYPE_MC_8_GRBL_0_9_CNC,
    TYPE_MC_8_GRBL_0_9_LASER,
}mc_type_t;  

/*
    这个结构体用来管理下位机参数设置
    - mc_axix:用于设置轴的数量
    - mc_type：用于设置机器类型，主要是为了切换不一样的握手协议
*/
typedef struct {

    uint8_t mc_axix;        // default is 4 axis.
    mc_type_t mc_type;

}s_lcd_t;


/* Some common function */
void delay_ms(uint16_t ms);

// Init or get info form EEPROM or NVS
void lcd_controller_init(void);

#endif