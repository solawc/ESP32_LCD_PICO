#include "vantins.h"

s_lcd_t s_lcd;

void delay_ms(uint16_t ms) {
    delay(ms);
}

void lcd_controller_init(void) {
    s_lcd.mc_axix = 4;
    s_lcd.mc_type = TYPE_MC_32_GRBL_CNC; 
}


uint8_t get_mc_axis_num(void) {

    return s_lcd.mc_axix;
}

bool set_mc_axis_num(uint8_t num) {
    
    if(num > 128) return false;   // 我就不信有128个轴的机器！如果有我吃了它

    s_lcd.mc_axix = num;

    return true;
}





