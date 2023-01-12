#include "esp32_tft_hal.h"

#define LCD_SPI_USE             VSPI
#define LCD_SPI_SPEED           40000000
#define TOUCH_SPI_SPEED         2000000
#define LCD_SPI_CODE            MSBFIRST
#define LCD_SPI_MODE            SPI_MODE0
SPIClass                        LCD_SPI(VSPI);
spi_host_device_t               spi_host_dma = VSPI_HOST;
spi_device_handle_t             dmaDevice;
#define LCD_SPI_DMA_CH          1

// LCD ctrl pins init.
#define LCD_CS_INIT()           pinMode(LCD_SPI_CS, OUTPUT) 
#define LCD_DC_INIT()           pinMode(LCD_DC, OUTPUT)
#define LCD_RST_INIT()          pinMode(LCD_RST, OUTPUT)
#define LCD_TOUCH_CS_INIT()     pinMode(LCD_TOUCH_CS, OUTPUT)


#define LCD_W                   320
#define LCD_H                   480

// CS pin ctrl.
#define LCD_CS_WRITE_L()        GPIO.out_w1tc = (1 << LCD_SPI_CS); GPIO.out_w1tc = (1 << LCD_SPI_CS)
#define LCD_CS_WRITE_H()        GPIO.out_w1ts = (1 << LCD_SPI_CS)

// Touch CS pin ctrl.
#define TOUCH_CS_WRITE_L()      GPIO.out_w1tc = (1 << LCD_TOUCH_CS); GPIO.out_w1tc = (1 << LCD_TOUCH_CS)
#define TOUCH_CS_WRITE_H()      GPIO.out_w1ts = (1 << LCD_TOUCH_CS)


// RST pins ctrl.
#define LCD_RST_WRITE_L()       digitalWrite(LCD_RST, LOW);     // GPIO.out_w1tc = (1 << LCD_RST)
#define LCD_RST_WRITE_H()       digitalWrite(LCD_RST, HIGH);    // GPIO.out_w1ts = (1 << LCD_RST)

// DC pin ctrl.
#define LCD_DC_WRITE_L()        GPIO.out_w1tc = (1 << (LCD_DC))
#define LCD_DC_WRITE_H()        GPIO.out_w1ts = (1 << (LCD_DC))

#define LCD_DELAY(ms)           tft_delay(ms)


/* define for esp23 */

// Volatile for register reads:
volatile uint32_t* _spi_cmd_reg       = (volatile uint32_t*)(SPI_CMD_REG(LCD_SPI_USE));
volatile uint32_t* _spi_user_reg      = (volatile uint32_t*)(SPI_USER_REG(LCD_SPI_USE));
// Register writes only:
volatile uint32_t* _spi_mosi_dlen_reg = (volatile uint32_t*)(SPI_MOSI_DLEN_REG(LCD_SPI_USE));
volatile uint32_t* _spi_w_reg         = (volatile uint32_t*)(SPI_W0_REG(LCD_SPI_USE));

#define TFT_WRITE_BITS_REG(D, B) *_spi_mosi_dlen_reg = B-1;    \
                               *_spi_w_reg = D;             \
                               *_spi_cmd_reg = SPI_USR;      \
                        while (*_spi_cmd_reg & SPI_USR);


#define tft_trans_8(c)          TFT_WRITE_BITS_REG(c, 8)
#define tft_trans_32C(C,D)      TFT_WRITE_BITS_REG((uint16_t)((D)<<8 | (D)>>8)<<16 | (uint16_t)((C)<<8 | (C)>>8), 32)


volatile uint8_t  mspiBusyCheck;
volatile bool trandLock;
volatile bool tftInTrans;
volatile bool tftLockTrans;

void init_ST7796();

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
  mspiBusyCheck = 0;
}

void tft_dma_wait(void) {

    if(!mspiBusyCheck) return;

    spi_transaction_t *rtrans;
    esp_err_t ret;

    for (int i = 0; i < mspiBusyCheck; ++i)
    {
        ret = spi_device_get_trans_result(dmaDevice, &rtrans, portMAX_DELAY);
        assert(ret == ESP_OK);
    }

    mspiBusyCheck = 0;
}

inline void tft_begin_trans(void) {

    if(trandLock) {
        trandLock = false;
        LCD_SPI.beginTransaction(SPISettings(LCD_SPI_SPEED, LCD_SPI_CODE, LCD_SPI_MODE));
        LCD_CS_WRITE_L();
        SET_BUS_WRITE_MODE_REG;
    }
}

inline void tft_end_trans(void) {

    if(!tftInTrans) { 
        if(!trandLock) {
            trandLock = true;
            SPI_BUSY_CHECK_REG;
            LCD_CS_WRITE_H();
            LCD_SPI.endTransaction();
        }
        SET_BUS_READ_MODE_REG;
    }
}

void tft_start_write(void) {
    tft_begin_trans();
    tftInTrans = true;
    tftLockTrans = true;
}

void tft_end_write(void) {
    tftInTrans = false;
    tftLockTrans = false;
    DMA_BUSY_CHECK;
    tft_end_trans();
}


void tft_write_cmd(uint8_t cmd) {

    tft_begin_trans();      // TODO: set begin tft write.
    LCD_DC_WRITE_L();
    tft_trans_8(cmd);
    LCD_DC_WRITE_H();
    tft_end_trans();        // TODO: set end tft write.
}

void tft_write_data(uint8_t data) {
    tft_begin_trans();
    LCD_DC_WRITE_H();        // Play safe, but should already be in data mode
    tft_trans_8(data);
    LCD_CS_WRITE_L();        // Allow more hold time for low VDI rail
    tft_end_trans();
}

extern void IRAM_ATTR disp_flush_callback(spi_transaction_t *spi_tx);

void tft_begin(void) {

    // First: Init HAL SPI.
    LCD_SPI.begin(LCD_SPI_SCK, LCD_SPI_MISO, LCD_SPI_MOSI, -1);

    trandLock = true;
    tftInTrans = false;
    tftLockTrans = false;

    // Init SPI CS pin
#ifdef LCD_SPI_CS
    LCD_CS_INIT();              /* init cs pin */
    LCD_CS_WRITE_H();           /* set cs pin pull up. */
#endif

#ifdef LCD_TOUCH_CS
    LCD_TOUCH_CS_INIT();
    TOUCH_CS_WRITE_H();
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

    // tft_begin_trans();

    // TODO: Write config data to TFT LCD.
    init_ST7796();

    // tft_end_trans();

    tft_set_rotation();

    esp32_spi_dma_init(false, disp_flush_callback);
}

void tft_set_rotation(void) {

    tft_begin_trans();

    // TODO: Write LCD dir data.
    tft_write_cmd(0x36);
    tft_write_data(TFT_MAD_MV | TFT_MAD_COLOR_ORDER);

    tft_end_trans();
}

void tft_set_windows(int32_t x0, int32_t y0, int32_t x1, int32_t y1) {

    tft_begin_trans();

    SPI_BUSY_CHECK_REG;
    LCD_DC_WRITE_L();   tft_trans_8(0x2A);    
    LCD_DC_WRITE_H();   tft_trans_32C(x0, x1-1);
    LCD_DC_WRITE_L();   tft_trans_8(0x2B); 
    LCD_DC_WRITE_H();   tft_trans_32C(y0, y1-1);
    LCD_DC_WRITE_L();   tft_trans_8(0x2C);
    LCD_DC_WRITE_H();

    tft_end_trans();
} 


void tft_push_dma(uint16_t *data, uint32_t len, bool swap) {

    if(len == 0) return;

    tft_dma_wait();

    if(swap) {
        for (uint32_t i = 0; i < len; i++) (data[i] = data[i] << 8 | data[i] >> 8);
    }

    esp_err_t ret;
    static spi_transaction_t mtrans;

    memset(&mtrans, 0, sizeof(spi_transaction_t));

    mtrans.user = (void *)1;
    mtrans.tx_buffer = data;         //finally send the line data
    mtrans.length = len * 16;        //Data length, in bits
    mtrans.flags = 0;                //SPI_TRANS_USE_TXDATA flag

    ret = spi_device_queue_trans(dmaDevice, &mtrans, portMAX_DELAY);
    assert(ret == ESP_OK);

    mspiBusyCheck++;
}


void tft_trans_buff_dma(uint16_t *data, uint32_t len, bool swap) {

    tft_begin_trans();

    tft_push_dma(data, len, swap);

    tft_end_trans();
}


void init_ST7796() {

    LCD_DELAY(120);

	tft_write_cmd(0x01); //Software reset
	LCD_DELAY(120);

	tft_write_cmd(0x11); //Sleep exit                                            
	LCD_DELAY(120);

	tft_write_cmd(0xF0); //Command Set control                                 
	tft_write_data(0xC3);    //Enable extension command 2 partI
	
	tft_write_cmd(0xF0); //Command Set control                                 
	tft_write_data(0x96);    //Enable extension command 2 partII
	
	tft_write_cmd(0x36); //Memory Data Access Control MX, MY, RGB mode                                    
	tft_write_data(0x48);    //X-Mirror, Top-Left to right-Buttom, RGB  
	
	tft_write_cmd(0x3A); //Interface Pixel Format                                    
	tft_write_data(0x55);    //Control interface color format set to 16
	
	
	tft_write_cmd(0xB4); //Column inversion 
	tft_write_data(0x01);    //1-dot inversion

	tft_write_cmd(0xB6); //Display Function Control
	tft_write_data(0x80);    //Bypass
	tft_write_data(0x02);    //Source Output Scan from S1 to S960, Gate Output scan from G1 to G480, scan cycle=2
	tft_write_data(0x3B);    //LCD Drive Line=8*(59+1)

	tft_write_cmd(0xE8); //Display Output Ctrl Adjust
	tft_write_data(0x40);
	tft_write_data(0x8A);	
	tft_write_data(0x00);
	tft_write_data(0x00);
	tft_write_data(0x29);    //Source eqaulizing period time= 22.5 us
	tft_write_data(0x19);    //Timing for "Gate start"=25 (Tclk)
	tft_write_data(0xA5);    //Timing for "Gate End"=37 (Tclk), Gate driver EQ function ON
	tft_write_data(0x33);
	
	tft_write_cmd(0xC1); //Power control2                          
	tft_write_data(0x06);    //VAP(GVDD)=3.85+( vcom+vcom offset), VAN(GVCL)=-3.85+( vcom+vcom offset)
	 
	tft_write_cmd(0xC2); //Power control 3                                      
	tft_write_data(0xA7);    //Source driving current level=low, Gamma driving current level=High
	 
	tft_write_cmd(0xC5); //VCOM Control
	tft_write_data(0x18);    //VCOM=0.9

	LCD_DELAY(120);
	
	//ST7796 Gamma Sequence
	tft_write_cmd(0xE0); //Gamma"+"                                             
	tft_write_data(0xF0);
	tft_write_data(0x09); 
	tft_write_data(0x0b);
	tft_write_data(0x06); 
	tft_write_data(0x04);
	tft_write_data(0x15); 
	tft_write_data(0x2F);
	tft_write_data(0x54); 
	tft_write_data(0x42);
	tft_write_data(0x3C); 
	tft_write_data(0x17);
	tft_write_data(0x14);
	tft_write_data(0x18); 
	tft_write_data(0x1B); 
	 
	tft_write_cmd(0xE1); //Gamma"-"                                             
	tft_write_data(0xE0);
	tft_write_data(0x09); 
	tft_write_data(0x0B);
	tft_write_data(0x06); 
	tft_write_data(0x04);
	tft_write_data(0x03); 
	tft_write_data(0x2B);
	tft_write_data(0x43); 
	tft_write_data(0x42);
	tft_write_data(0x3B); 
	tft_write_data(0x16);
	tft_write_data(0x14);
	tft_write_data(0x17); 
	tft_write_data(0x1B);

    LCD_DELAY(120);
	
	tft_write_cmd(0xF0); //Command Set control                                 
	tft_write_data(0x3C);    //Disable extension command 2 partI

	tft_write_cmd(0xF0); //Command Set control                                 
	tft_write_data(0x69);    //Disable extension command 2 partII

    tft_end_trans();
    LCD_DELAY(120);
    tft_begin_trans();

    tft_write_cmd(0x29); //Display on   
}



