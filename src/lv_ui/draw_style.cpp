#include "draw_style.h"

ui_style_t select_theme;

static void init_style(void);
static void reset_theme(void);
static void update_theme(uint8_t id);
static uint8_t get_theme_set();
static void update_btn_back_style();

enum {
    ID_THEME_WRITE = 0,
    ID_THEME_GREEN,
    ID_THENE_RED,
    ID_THEME_ORANGE,
    ID_THEME_PINK,
    ID_THEME_BACK,
};

static uint8_t get_event(lv_obj_t* obj) {

    if(obj == select_theme.btn_write) return ID_THEME_WRITE;
    else if(obj == select_theme.btn_green) return ID_THEME_GREEN;
    else if(obj == select_theme.btn_red) return ID_THENE_RED;
    else if(obj == select_theme.btn_orange) return ID_THEME_ORANGE;
    else if(obj == select_theme.btn_pink) return ID_THEME_PINK;
    else if(obj == select_theme.btn_back) return ID_THEME_BACK;
}

static void event_handler(lv_obj_t* obj, lv_event_t event) { 

    uint8_t id = get_event(obj);

    if(event == LV_EVENT_PRESSED) { 

        if(id != ID_THEME_BACK) {
            reset_theme();
            update_theme(id);
        }
    }

    if(event == LV_EVENT_RELEASED) {

            switch(id) {

            case ID_THEME_WRITE:
                ui_theme_reset();
                set_current_color(THEME_WRITE);
                ui_theme_set();
                update_btn_back_style();
            break;

            case ID_THEME_GREEN:
                ui_theme_reset();
                set_current_color(THEME_GREEN);
                ui_theme_set();
                update_btn_back_style();
            break;

            case ID_THENE_RED:
                ui_theme_reset();
                set_current_color(THEME_RED);
                ui_theme_set();
                update_btn_back_style();
            break;

            case ID_THEME_ORANGE:
                ui_theme_reset();
                set_current_color(THEME_ORANGE);
                ui_theme_set();
                update_btn_back_style();
            break;

            case ID_THEME_PINK:
                ui_theme_reset();
                set_current_color(THEME_PINK);
                ui_theme_set();
                update_btn_back_style();
            break;

            case ID_THEME_BACK:
                clean_theme_page();
                draw_home();
            break;
        }
    }
}


void draw_style(void) {

    init_style();

    select_theme.btn_write =  lv_btn_set(ui.src, select_theme.btn_write, 110, 110, 8, 84, event_handler);
    select_theme.btn_green =  lv_btn_set(ui.src, select_theme.btn_green, 110, 110, 126, 84, event_handler);
    select_theme.btn_red =  lv_btn_set(ui.src, select_theme.btn_red, 110, 110, 244, 84, event_handler);
    select_theme.btn_orange =  lv_btn_set(ui.src, select_theme.btn_orange, 110, 110, 362, 84, event_handler);
    select_theme.btn_pink =  lv_btn_set(ui.src, select_theme.btn_pink, 110, 110, 8, 204, event_handler);
    select_theme.btn_back =  lv_btn_set(ui.src, select_theme.btn_back, 60, 60, 8, 8, event_handler);

    reset_theme();
    
    // need get the theme id;
    update_theme(get_theme_set());

    select_theme.label_write = lv_label_create(select_theme.btn_write, NULL);
    select_theme.label_green = lv_label_create(select_theme.btn_green, NULL);
    select_theme.label_red = lv_label_create(select_theme.btn_red, NULL);
    select_theme.label_orange = lv_label_create(select_theme.btn_orange, NULL);
    select_theme.label_pink = lv_label_create(select_theme.btn_pink, NULL);

    lv_label_set_text(select_theme.label_write, "Write");
    lv_label_set_text(select_theme.label_green, "Green");
    lv_label_set_text(select_theme.label_red, "Red");
    lv_label_set_text(select_theme.label_orange, "Orange");
    lv_label_set_text(select_theme.label_pink, "Pink");
}

static void init_style(void) {

    lv_style_copy(&select_theme.style_write , &lv_style_scr);
    select_theme.style_write.body.border.color = LV_COLOR_WHITE;
    select_theme.style_write.body.border.width = 1;
    select_theme.style_write.body.grad_color = lv_color_hex(0x191919);
    select_theme.style_write.body.main_color = lv_color_hex(0x191919);
    select_theme.style_write.text.color = LV_COLOR_WHITE;

    lv_style_copy(&select_theme.style_write_pre , &lv_style_scr);
    select_theme.style_write_pre.body.border.color = LV_COLOR_WHITE;
    select_theme.style_write_pre.body.border.width = 1;
    select_theme.style_write_pre.body.grad_color = LV_COLOR_WHITE;
    select_theme.style_write_pre.body.main_color = LV_COLOR_WHITE;
    select_theme.style_write_pre.text.color = LV_COLOR_BLACK;


    lv_style_copy(&select_theme.style_green , &lv_style_scr);
    select_theme.style_green.body.border.color = lv_color_hex(0x4DE585);
    select_theme.style_green.body.border.width = 1;
    select_theme.style_green.body.grad_color = lv_color_hex(0x191919);
    select_theme.style_green.body.main_color = lv_color_hex(0x191919);
    select_theme.style_green.text.color = lv_color_hex(0x4DE585);

    lv_style_copy(&select_theme.style_green_pre , &lv_style_scr);
    select_theme.style_green_pre.body.border.color = lv_color_hex(0x4DE585);
    select_theme.style_green_pre.body.border.width = 1;
    select_theme.style_green_pre.body.grad_color = lv_color_hex(0x4DE585);
    select_theme.style_green_pre.body.main_color = lv_color_hex(0x4DE585);
    select_theme.style_green_pre.text.color = LV_COLOR_BLACK;

    lv_style_copy(&select_theme.style_red , &lv_style_scr);
    select_theme.style_red.body.border.color = lv_color_hex(0xD43636);
    select_theme.style_red.body.border.width = 1;
    select_theme.style_red.body.grad_color = lv_color_hex(0x191919);
    select_theme.style_red.body.main_color = lv_color_hex(0x191919);
    select_theme.style_red.text.color = lv_color_hex(0xD43636);

    lv_style_copy(&select_theme.style_red_pre , &lv_style_scr);
    select_theme.style_red_pre.body.border.color = lv_color_hex(0xD43636);
    select_theme.style_red_pre.body.border.width = 1;
    select_theme.style_red_pre.body.grad_color = lv_color_hex(0xD43636);
    select_theme.style_red_pre.body.main_color = lv_color_hex(0xD43636);
    select_theme.style_red_pre.text.color = LV_COLOR_BLACK;

    lv_style_copy(&select_theme.style_orange , &lv_style_scr);
    select_theme.style_orange.body.border.color = lv_color_hex(0xE5A240);
    select_theme.style_orange.body.border.width = 1;
    select_theme.style_orange.body.grad_color = lv_color_hex(0x191919);
    select_theme.style_orange.body.main_color = lv_color_hex(0x191919);
    select_theme.style_orange.text.color = lv_color_hex(0xE5A240);

    lv_style_copy(&select_theme.style_orange_pre , &lv_style_scr);
    select_theme.style_orange_pre.body.border.color = lv_color_hex(0xE5A240);;
    select_theme.style_orange_pre.body.border.width = 1;
    select_theme.style_orange_pre.body.grad_color = lv_color_hex(0xE5A240);
    select_theme.style_orange_pre.body.main_color = lv_color_hex(0xE5A240);
    select_theme.style_orange_pre.text.color = LV_COLOR_BLACK;

    lv_style_copy(&select_theme.style_pink , &lv_style_scr);
    select_theme.style_pink.body.border.color = lv_color_hex(F_THEME_PINK);
    select_theme.style_pink.body.border.width = 1;
    select_theme.style_pink.body.grad_color = lv_color_hex(0x191919);
    select_theme.style_pink.body.main_color = lv_color_hex(0x191919);
    select_theme.style_pink.text.color = lv_color_hex(F_THEME_PINK);

    lv_style_copy(&select_theme.style_pink_pre , &lv_style_scr);
    select_theme.style_pink_pre.body.border.color = lv_color_hex(F_THEME_PINK);;
    select_theme.style_pink_pre.body.border.width = 1;
    select_theme.style_pink_pre.body.grad_color = lv_color_hex(F_THEME_PINK);
    select_theme.style_pink_pre.body.main_color = lv_color_hex(F_THEME_PINK);
    select_theme.style_pink_pre.text.color = LV_COLOR_BLACK;
}


static void reset_theme(void) {

    lv_btn_set_style(select_theme.btn_write, LV_BTN_STYLE_REL, &select_theme.style_write);
    lv_btn_set_style(select_theme.btn_write, LV_BTN_STYLE_PR, &select_theme.style_write);

    lv_btn_set_style(select_theme.btn_green, LV_BTN_STYLE_REL, &select_theme.style_green);
    lv_btn_set_style(select_theme.btn_green, LV_BTN_STYLE_PR, &select_theme.style_green);

    lv_btn_set_style(select_theme.btn_red, LV_BTN_STYLE_REL, &select_theme.style_red);
    lv_btn_set_style(select_theme.btn_red, LV_BTN_STYLE_PR, &select_theme.style_red);

    lv_btn_set_style(select_theme.btn_orange, LV_BTN_STYLE_REL, &select_theme.style_orange);
    lv_btn_set_style(select_theme.btn_orange, LV_BTN_STYLE_PR, &select_theme.style_orange);

    lv_btn_set_style(select_theme.btn_pink, LV_BTN_STYLE_REL, &select_theme.style_pink);
    lv_btn_set_style(select_theme.btn_pink, LV_BTN_STYLE_PR, &select_theme.style_pink);

    lv_btn_set_style(select_theme.btn_back, LV_BTN_STYLE_REL, &ui.com_back);
    lv_btn_set_style(select_theme.btn_back, LV_BTN_STYLE_PR, &ui.com_back_pre);
}

static void update_theme(uint8_t id) {

    switch(id) {
        case ID_THEME_WRITE: 
            lv_btn_set_style(select_theme.btn_write, LV_BTN_STYLE_REL, &select_theme.style_write_pre);
            lv_btn_set_style(select_theme.btn_write, LV_BTN_STYLE_PR, &select_theme.style_write_pre);
        break;

        case ID_THEME_GREEN: 
            lv_btn_set_style(select_theme.btn_green, LV_BTN_STYLE_REL, &select_theme.style_green_pre);
            lv_btn_set_style(select_theme.btn_green, LV_BTN_STYLE_PR, &select_theme.style_green_pre);
        break;

        case ID_THENE_RED: 
            lv_btn_set_style(select_theme.btn_red, LV_BTN_STYLE_REL, &select_theme.style_red_pre);
            lv_btn_set_style(select_theme.btn_red, LV_BTN_STYLE_PR, &select_theme.style_red_pre);
        break;

        case ID_THEME_ORANGE:
            lv_btn_set_style(select_theme.btn_orange, LV_BTN_STYLE_REL, &select_theme.style_orange_pre);
            lv_btn_set_style(select_theme.btn_orange, LV_BTN_STYLE_PR, &select_theme.style_orange_pre);
        break;

        case ID_THEME_PINK: 
            lv_btn_set_style(select_theme.btn_pink, LV_BTN_STYLE_REL, &select_theme.style_pink_pre);
            lv_btn_set_style(select_theme.btn_pink, LV_BTN_STYLE_PR, &select_theme.style_pink_pre);
        break;
    }

    
}

static void update_btn_back_style() {
    lv_btn_set_style(select_theme.btn_back, LV_BTN_STYLE_REL, &ui.com_back);
    lv_btn_set_style(select_theme.btn_back, LV_BTN_STYLE_PR, &ui.com_back_pre);
}

static uint8_t get_theme_set() {

    switch(get_current_color()) {

        case F_THEME_WRITE:
            return ID_THEME_WRITE;
        break;

        case F_THEME_GREEN:
            return ID_THEME_GREEN;
        break;

        case F_THEME_RED:
            return ID_THENE_RED;
        break;

        case F_THEME_ORANGE:
            return ID_THEME_ORANGE;
        break;

        case F_THEME_PINK:
            return ID_THEME_PINK;
        break;
    }
}

void clean_theme_page(void) {
    lv_obj_clean(ui.src);
}