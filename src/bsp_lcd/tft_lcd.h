#ifndef __tft_lcd_35_h
#define __tft_lcd_35_h

#include "main.h"
#include "TFT_eSPI.h"
#include "FT6336U.h"

extern TFT_eSPI tft;

#define LCD_EN		        GPIO_NUM_5    

#define I2C_SDA             0
#define I2C_SCL             4
#define RST_N_PIN           -1
#define INT_N_PIN           21

#define LCD_BLK_ON          digitalWrite(LCD_EN, LOW)
#define LCD_BLK_OFF         digitalWrite(LCD_EN, HIGH)

#ifdef USE_FT6336_TOUCH
#define DEFAULT_TOUCH_TYPE  TOUCH_TYPE_CAP
#else
#define DEFAULT_TOUCH_TYPE  TOUCH_TYPE_RES
#endif

typedef enum {
    TOUCH_TYPE_CAP,         // 电容屏类型
    TOUCH_TYPE_RES,         // 电阻屏类型
}touch_type_t;

typedef struct {

    touch_type_t touch_type;
    uint16_t lcd_w_size;
    uint16_t lcd_h_size;

}tft_lcd_t;



class HAL_TFT_LCD {

private:
    FT6336U_TouchPointType      capTp;           /* Cap touch */
    touch_type_t                touchType;
public:
    TFT_eSPI tft = TFT_eSPI();
    void tft_init(void);

    uint8_t tftTouchRead(uint16_t *xPos, uint16_t *yPos);

    void tftBglightInit(void);
    void tftBglightSetOn(void);
    void tftBglightSetOff(void);
    void tftBglightBeginOn(void);           /* 待实现背光渐变启动的功能 */ 
};

extern HAL_TFT_LCD tft_lcd;




#endif