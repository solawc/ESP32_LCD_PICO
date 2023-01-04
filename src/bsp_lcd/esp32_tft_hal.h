#ifndef __esp32_tft_hal_h
#define __esp32_tft_hal_h

#include "main.h"

#define LCD_SPI_SCK         18
#define LCD_SPI_MISO        19
#define LCD_SPI_MOSI        23
#define LCD_SPI_CS          26
#define LCD_DC              25
#define LCD_RST             22
#define LCD_TOUCH_CS        27



void tft_delay(uint32_t ms);

void tft_set_rotation(void);
void tft_set_windows(int32_t x0, int32_t y0, int32_t x1, int32_t y1);
void tft_trans_buff(uint16_t *data, uint32_t len);


#endif

