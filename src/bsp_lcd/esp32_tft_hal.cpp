#include "esp32_tft_hal.h"

#define LCD_SPI_USE         VSPI
SPIClass LCD_SPI(LCD_SPI_USE);

// LCD ctrl pins init.
#define LCD_CS_INIT()       pinMode(LCD_SPI_CS, OUTPUT) 
#define LCD_DC_INIT()       pinMode(LCD_DC, OUTPUT)
#define LCD_RST_INIT()      pinMode(LCD_RST, OUTPUT)

// CS pin ctrl.
#define LCD_CS_WRITE_L()    GPIO.out_w1tc = (1 << LCD_SPI_CS); GPIO.out_w1tc = (1 << LCD_SPI_CS)
#define LCD_CS_WRITE_H()    GPIO.out_w1ts = (1 << LCD_SPI_CS)

// RST pins ctrl.
#define LCD_RST_WRITE_L()   digitalWrite(LCD_RST, LOW);     // GPIO.out_w1tc = (1 << LCD_RST)
#define LCD_RST_WRITE_H()   digitalWrite(LCD_RST, HIGH);    // GPIO.out_w1ts = (1 << LCD_RST)

// DC pin ctrl.
#define LCD_DC_WRITE_L()    digitalWrite(LCD_DC, LOW);      // GPIO.out_w1tc = (1 << LCD_DC)
#define LCD_DC_WRITE_H()    digitalWrite(LCD_DC, HIGH);     // GPIO.out_w1ts = (1 << LCD_DC)



#define LCD_DELAY(ms)       tft_delay(ms)


/* define for esp23 */

// Volatile for register reads:
volatile uint32_t* _spi_cmd_reg       = (volatile uint32_t*)(SPI_CMD_REG(LCD_SPI_USE));
volatile uint32_t* _spi_user_reg      = (volatile uint32_t*)(SPI_USER_REG(LCD_SPI_USE));
// Register writes only:
volatile uint32_t* _spi_mosi_dlen_reg = (volatile uint32_t*)(SPI_MOSI_DLEN_REG(LCD_SPI_USE));
volatile uint32_t* _spi_w_reg         = (volatile uint32_t*)(SPI_W0_REG(LCD_SPI_USE));


#define TFT_WRITE_BITS(D, B) *_spi_mosi_dlen_reg = B-1;    \
                               *_spi_w_reg = D;             \
                               *_spi_cmd_reg = SPI_USR;      \
                        while (*_spi_cmd_reg & SPI_USR);


#define tft_trans_8(c)  TFT_WRITE_BITS(c, 8)

void tft_delay(uint32_t ms) { delay(ms); }


void tft_write_cmd(uint8_t cmd) {

    // TODO: set begin tft write.

    LCD_DC_WRITE_L();
    tft_trans_8(cmd);
    LCD_DC_WRITE_H();

    // TODO: set end tft write.
}

void tft_write_data(uint8_t data) {


}


void tft_begin(void) {

    // First: Init HAL SPI.
    LCD_SPI.begin(LCD_SPI_SCK, LCD_SPI_MISO, LCD_SPI_MOSI, -1);

    // Init SPI CS pin
#ifdef LCD_SPI_CS
    LCD_CS_INIT();              /* init cs pin */
    LCD_CS_WRITE_H();           /* set cs pin pull up. */
#endif

#ifdef LCD_DC 
    LCD_DC_INIT(); 
    LCD_DC_WRITE_H();
#endif

#ifdef LCD_RST
    LCD_RST_INIT();             /* init rst pin. */
    LCD_RST_WRITE_H();          /* set rst pin pull up and begin reset lcd config. */
    LCD_DELAY(5);
    LCD_RST_WRITE_L();
    LCD_DELAY(5);
    LCD_RST_WRITE_H();
#else   
    /* if not define LCD_RST pin, we must use software to reset TFT LCD config. */

#endif

}




