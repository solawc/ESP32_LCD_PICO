#include "esp32_tft_hal.h"

#define LCD_SPI_USE             VSPI
#define LCD_SPI_SPEED           27000000
#define TOUCH_SPI_SPEED         2000000
#define LCD_SPI_CODE            MSBFIRST
#define LCD_SPI_MODE            SPI_MODE0
SPIClass                        LCD_SPI(LCD_SPI_USE);
spi_host_device_t               spi_host_dma = VSPI_HOST;
spi_device_handle_t             dmaDevice;
#define LCD_SPI_DMA_CH          1

// LCD ctrl pins init.
#define LCD_CS_INIT()       pinMode(LCD_SPI_CS, OUTPUT) 
#define LCD_DC_INIT()       pinMode(LCD_DC, OUTPUT)
#define LCD_RST_INIT()      pinMode(LCD_RST, OUTPUT)

#define LCD_W               320
#define LCD_H               480

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

#define SET_BUS_WRITE_MODE_REG  *_spi_user_reg = SPI_USR_MOSI
#define SET_BUS_READ_MODE_REG   *_spi_user_reg = SPI_USR_MOSI | SPI_USR_MISO | SPI_DOUTDIN

#define SPI_BUSY_CHECK_REG while (*_spi_cmd_reg & SPI_USR)



#define TFT_WRITE_BITS(D, B) *_spi_mosi_dlen_reg = B-1;    \
                               *_spi_w_reg = D;             \
                               *_spi_cmd_reg = SPI_USR;      \
                        while (*_spi_cmd_reg & SPI_USR);


#define tft_trans_8(c)          TFT_WRITE_BITS(c, 8)
#define tft_trans_32C(C,D)      TFT_WRITE_BITS((uint16_t)((D)<<8 | (D)>>8)<<16 | (uint16_t)((C)<<8 | (C)>>8), 32)


void tft_delay(uint32_t ms) { delay(ms); }

void esp32_spi_dma_init(bool ctrl_cs, transaction_cb_t trComplat) {

    esp_err_t ret;
    spi_bus_config_t buscfg = {
    .mosi_io_num = LCD_SPI_MOSI,
    .miso_io_num = LCD_SPI_MISO,
    .sclk_io_num = LCD_SPI_SCK,
    .quadwp_io_num = -1,
    .quadhd_io_num = -1,
    .max_transfer_sz = LCD_W * LCD_H * 2 + 8, // TFT screen size
    .flags = 0,
    .intr_flags = 0
  };

  int8_t pin = -1;
  if (ctrl_cs) pin = LCD_SPI_CS;

  spi_device_interface_config_t devcfg = {
    .command_bits = 0,
    .address_bits = 0,
    .dummy_bits = 0,
    .mode = LCD_SPI_MODE,
    .duty_cycle_pos = 0,
    .cs_ena_pretrans = 0,
    .cs_ena_posttrans = 0,
    .clock_speed_hz = LCD_SPI_SPEED,
    .input_delay_ns = 0,
    .spics_io_num = pin,
    .flags = SPI_DEVICE_NO_DUMMY, //0,
    .queue_size = 1,
    .pre_cb = 0, //dc_callback, //Callback to handle D/C line
    .post_cb = trComplat 
  };

  ret = spi_bus_initialize(spi_host_dma, &buscfg, LCD_SPI_DMA_CH);
  ESP_ERROR_CHECK(ret);
  ret = spi_bus_add_device(spi_host_dma, &devcfg, &dmaDevice);
  ESP_ERROR_CHECK(ret);
}

void tft_dma_wait() {

    spi_transaction_t *rtrans;
    esp_err_t ret;

    // for (int i = 0; i < spiBusyCheck; ++i)
    // {
    //     ret = spi_device_get_trans_result(dmaDevice, &rtrans, portMAX_DELAY);
    //     assert(ret == ESP_OK);
    // }

}

void tft_begin_trans(void) {

    LCD_SPI.beginTransaction(SPISettings(LCD_SPI_SPEED, LCD_SPI_CODE, LCD_SPI_MODE));
    LCD_CS_WRITE_L();
    SET_BUS_WRITE_MODE_REG;
}

void tft_end_trans(void) {

    SPI_BUSY_CHECK_REG;
    LCD_CS_WRITE_H();
    LCD_SPI.endTransaction();
    SET_BUS_READ_MODE_REG;
}

void tft_write_cmd(uint8_t cmd) {

    tft_begin_trans();      // TODO: set begin tft write.

    LCD_DC_WRITE_L();
    tft_trans_8(cmd);
    LCD_DC_WRITE_H();

    tft_end_trans();        // TODO: set end tft write.
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
    // TODO..
    tft_write_cmd(0x01);   // 0x01 is for ST7795S
#endif

    LCD_DELAY(150);

    tft_begin_trans();

    // TODO: Write config data to TFT LCD.

    tft_end_trans();

    tft_set_rotation();
}

void tft_set_rotation(void) {

    tft_begin_trans();

    // TODO: Write LCD dir data.

    LCD_DELAY(10);
    
    tft_end_trans();
}

void tft_set_windows(int32_t x0, int32_t y0, int32_t x1, int32_t y1) {

    tft_begin_trans();

    SPI_BUSY_CHECK_REG;
    LCD_DC_WRITE_L();   tft_trans_8(0x2A);    
    LCD_DC_WRITE_H();   tft_trans_32C(x0, x1);
    LCD_DC_WRITE_L();   tft_trans_8(0x2B); 
    LCD_DC_WRITE_H();   tft_trans_32C(y0, y1);
    LCD_DC_WRITE_L();   tft_trans_8(0x2C);
    LCD_DC_WRITE_H();

    tft_end_trans();
} 

void tft_trans_buff(uint16_t *data, uint32_t len) {

    tft_begin_trans();

    // TODO: Wait dma standby.

    esp_err_t ret;
    static spi_transaction_t trans;
    memset(&trans, 0, sizeof(spi_transaction_t));

    trans.user = (void *)1;
    trans.tx_buffer = data;         //finally send the line data
    trans.length = len * 16;        //Data length, in bits
    trans.flags = 0;                //SPI_TRANS_USE_TXDATA flag

    ret = spi_device_queue_trans(dmaDevice, &trans, portMAX_DELAY);
    assert(ret == ESP_OK);

    tft_end_trans();
}




