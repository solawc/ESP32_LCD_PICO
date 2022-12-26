#include "tft_lcd.h"
#include "../lv_ui/lv_port/lv_port_init.h"

// TFT_eSPI tft = TFT_eSPI(); /* TFT instance */
// tft_lcd_t tft_lcd;


// #ifdef USE_FT6336_TOUCH
//     FT6336U_TouchPointType tp;
// #endif

// #ifdef USE_XPT2046_TOUCH
//     // TODO.
// #endif

FT6336U ft6336u(I2C_SDA, I2C_SCL, RST_N_PIN, INT_N_PIN); 

// void tft_TS35_init() {

//     tft_lcd.lcd_h_size = TFT_WIDTH;
//     tft_lcd.lcd_w_size = TFT_HEIGHT;
//     tft_lcd.touch_type = DEFAULT_TOUCH_TYPE;

//     tft.begin();
//     tft.setRotation(1);
//     tft.fillScreen(tft.color565(0X00, 0X1A, 0XFF));

//     if(tft_lcd.touch_type == TOUCH_TYPE_CAP) {
//         ft6336u.begin(); 
//     }
//     else if(tft_lcd.touch_type == TOUCH_TYPE_RES) {

//     }
// } 

//  void tft_backlight_enable(void) {
//     LCD_BLK_ON;
//  }

//  void tft_backlight_disable(void) {
//     pinMode(LCD_EN, OUTPUT);
//     LCD_BLK_OFF;
//  }

// bool tp_read_task(uint16_t *x_pos, uint16_t *y_pos) {

//     uint16_t x_temp, y_temp;

//     if(tft_lcd.touch_type == TOUCH_TYPE_CAP) {

//         tp = ft6336u.scan(); 

//         if(tp.tp[0].status != release ) {

//             x_temp = tp.tp[0].x;
//             y_temp = tp.tp[0].y;

//             *x_pos = x_temp;
//             *y_pos = y_temp;

//             return true;
//         }else {
//             return false;
//         }
//     }else {
//         if(tft.getTouch(&y_temp, &x_temp) != false) {
            
//             x_temp = 320 - x_temp;

//             *x_pos = x_temp;
//             *y_pos = y_temp;

//             return true;
//         }
//         else{
//             return false;
//         } 
//     }
// }


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


HAL_TFT_LCD tft_lcd;




