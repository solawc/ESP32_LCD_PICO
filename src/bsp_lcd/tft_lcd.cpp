#include "tft_lcd.h"
#include "../lv_ui/lv_port/lv_port_init.h"

HAL_TFT_LCD tft_lcd;

#ifndef I2C_SDA
    #define I2C_SDA         -1
#endif 

#ifndef I2C_SCL
    #define I2C_SCL         -1
#endif 

#ifndef RST_N_PIN
    #define RST_N_PIN         -1
#endif 

#ifndef INT_N_PIN
    #define INT_N_PIN         -1
#endif 

FT6336U ft6336u(I2C_SDA, I2C_SCL, RST_N_PIN, INT_N_PIN); 

/*-------------------------------------------------------------*/

void IRAM_ATTR disp_flush_callback(spi_transaction_t *spi_tx) {
    ui.lvPortDispCallback();
}

void HAL_TFT_LCD::tft_init(void) {
    tft.begin();
    tft.setRotation(1);
    tft.initDMA(false, disp_flush_callback);
}

void HAL_TFT_LCD::tftBglightInit(void) {
#ifdef LCD_EN
    pinMode(LCD_EN, OUTPUT);
#endif
    tft.fillScreen(TFT_RED);
}

void HAL_TFT_LCD::tftBglightSetOn(void) {
#ifdef LCD_EN
    digitalWrite(LCD_EN, LOW);
#endif
}

void HAL_TFT_LCD::tftBglightSetOff(void) {
#ifdef LCD_EN
    digitalWrite(LCD_EN, HIGH);
#endif
}

void HAL_TFT_LCD::tftBglightBeginOn(void) {
    // TODO...(让屏幕渐变启动)
}

uint8_t HAL_TFT_LCD::tftTouchRead(uint16_t *xPos, uint16_t *yPos) {

    uint16_t x_temp, y_temp;
        
    if(tft_lcd.touchType == TOUCH_TYPE_CAP) {

        tft_lcd.capTp = ft6336u.scan(); 

        if(tft_lcd.capTp.tp[0].status != release ) {

            x_temp = tft_lcd.capTp.tp[0].x;
            y_temp = tft_lcd.capTp.tp[0].y;

            *xPos = x_temp;
            *yPos = y_temp;

            return true;
        }else {
            return false;
        }
    }else {
        if(tft.getTouch(&y_temp, &x_temp) != false) {
            x_temp = 320 - x_temp;
            *xPos = x_temp;
            *yPos = y_temp;
            return true;
        }
        else{
            return false;
        } 
    }
}






