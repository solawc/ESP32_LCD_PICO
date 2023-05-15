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

#define SET_BUS_WRITE_MODE_REG  *_spi_user_reg = SPI_USR_MOSI
#define SET_BUS_READ_MODE_REG   *_spi_user_reg = SPI_USR_MOSI | SPI_USR_MISO | SPI_DOUTDIN

#define SPI_BUSY_CHECK_REG while (*_spi_cmd_reg&SPI_USR)

#define DMA_BUSY_CHECK  tft_dma_wait()

void tft_delay(uint32_t ms);
void tft_begin(void);
void tft_set_rotation(void);
void tft_set_windows(int32_t x0, int32_t y0, int32_t x1, int32_t y1);
void tft_trans_buff_dma(uint16_t *data, uint32_t len, bool swap);
void tft_trans_buff(const void* data_in, uint32_t len);
void tft_swap_trans_buff(const void* data_in, uint32_t len);

void tft_start_write(void);
void tft_end_write(void);
#endif

