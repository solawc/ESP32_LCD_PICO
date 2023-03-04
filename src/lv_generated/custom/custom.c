// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include "custom.h"
#include "file_grid.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
int cur_scr;

/**********************
 *  STATIC VARIABLES
 **********************/
void load_disbtn_home_cb(lv_event_t * event){
    lv_event_code_t code = lv_event_get_code(event);
    lv_obj_t * obj = lv_event_get_target(event);
    if (code == LV_EVENT_PRESSED) {
        guider_load_screen(SCR_HOME);
    }
}

void load_disbtn_tool_switch_cb(lv_event_t * event){
    lv_event_code_t code = lv_event_get_code(event);
    lv_obj_t * obj = lv_event_get_target(event);

    if (code == LV_EVENT_PRESSED) {
        if (obj == guider_ui.tool_imgbtn_1)
        {
            guider_load_screen(SCR_TOOL_INFO);
        }
        else if(obj == guider_ui.tool_imgbtn_2)
        {
            guider_load_screen(SCR_TOOL_WIFI);
        }       
    }
}

void scr_tool_event_init(void){
    lv_obj_add_event_cb(guider_ui.tool_imgbtn_3, load_disbtn_home_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(guider_ui.tool_imgbtn_1, load_disbtn_tool_switch_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(guider_ui.tool_imgbtn_2, load_disbtn_tool_switch_cb, LV_EVENT_ALL, NULL);
}

void load_disbtn_engraving_switch_cb(lv_event_t * event){
    lv_event_code_t code = lv_event_get_code(event);
    lv_obj_t * obj = lv_event_get_target(event);

    if (code == LV_EVENT_PRESSED) {
        if (obj == guider_ui.engraving_imgbtn_2)
        {
            guider_load_screen(SCR_ENGRAING_FILE);
        }
        else if(obj == guider_ui.engraving_imgbtn_3)
        {
            guider_load_screen(SCR_HOME);
        }       
    }
}

void load_incarving_cb(lv_event_t * event)
{
    lv_event_code_t code = lv_event_get_code(event);
    lv_obj_t * obj = lv_event_get_target(event);
    if (code == LV_EVENT_PRESSED) {
        guider_load_screen(SCR_INCARVING);
    }
}

void scr_engraving_event_init(void){
    lv_obj_add_event_cb(guider_ui.engraving_imgbtn_2, load_disbtn_engraving_switch_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(guider_ui.engraving_imgbtn_3, load_disbtn_engraving_switch_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(guider_ui.engraving_imgbtn_6, load_disbtn_home_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(guider_ui.engraving_imgbtn_5, load_incarving_cb, LV_EVENT_ALL, NULL);
}

void load_disbtn_file_management_switch_cb(lv_event_t * event){
    lv_event_code_t code = lv_event_get_code(event);
    lv_obj_t * obj = lv_event_get_target(event);

    if (code == LV_EVENT_PRESSED) {
        if (obj == guider_ui.file_management_imgbtn_1)
        {
            guider_load_screen(SCR_ENGRAING_POSITION);
        }   
    }
}

void load_disbtn_file_management_last_page_event_cb(lv_event_t* e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn_obj = lv_event_get_target(e);
    lv_ui* handle = (lv_ui*)lv_event_get_user_data(e);

    if(code == LV_EVENT_CLICKED){
        lv_obj_clean(handle->file_management_table);
        uint32_t num = lv_rand(1, 8);
        for (size_t i = 0; i < num; i++)
        {
            file_grid_insert_cell(handle->file_management_table, NULL);
            file_grid_set_cell_text(handle->file_management_table, "test");
        }   
    }
}

void load_disbtn_file_management_next_page_event_cb(lv_event_t* e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn_obj = lv_event_get_target(e);
    lv_ui* handle = (lv_ui*)lv_event_get_user_data(e);

    if(code == LV_EVENT_CLICKED){
        lv_obj_clean(handle->file_management_table);
        uint32_t num = lv_rand(1, 8);
        for (size_t i = 0; i < num; i++)
        {
            file_grid_insert_cell(handle->file_management_table, NULL);
            file_grid_set_cell_text(handle->file_management_table, "test");
        }        
    }
}

void scr_file_management_event_init(void){
    lv_obj_add_event_cb(guider_ui.file_management_imgbtn_1, load_disbtn_file_management_switch_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(guider_ui.file_management_btn_next_page, load_disbtn_file_management_next_page_event_cb, LV_EVENT_ALL, &guider_ui); 
    lv_obj_add_event_cb(guider_ui.file_management_btn_last_page, load_disbtn_file_management_last_page_event_cb, LV_EVENT_ALL, &guider_ui); 
}

void scr_control_event_init(void){
    if(guider_ui.control_imgbtn_6){
        lv_obj_add_event_cb(guider_ui.control_imgbtn_6, load_disbtn_home_cb, LV_EVENT_ALL, NULL);
    }
}

void load_disbtn_tool_cb(lv_event_t * event){
    lv_event_code_t code = lv_event_get_code(event);
    lv_obj_t * obj = lv_event_get_target(event);
    if (code == LV_EVENT_PRESSED) {
        guider_load_screen(SCR_TOOL);
    }
}

void scr_tool_info_event_init(void){
    lv_obj_add_event_cb(guider_ui.tool_info_imgbtn_3, load_disbtn_tool_cb, LV_EVENT_ALL, NULL);
}

static void ta_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_current_target(e);
    lv_ui * ui = (lv_ui*)lv_event_get_user_data(e);
    
    if(code == LV_EVENT_READY) {
        // connect the wifi
        if(ui->tool_wifi_msgbox )
        {
            // static lv_opa_t mask_map[LV_VER_RES_MAX * LV_HOR_RES_MAX];
            // /*Create a "8 bit alpha" canvas and clear it*/
            // lv_obj_t * canvas = lv_canvas_create(ui->tool_wifi);
            // lv_canvas_set_buffer(canvas, mask_map, LV_HOR_RES_MAX, LV_VER_RES_MAX, LV_IMG_CF_ALPHA_8BIT);
            // lv_obj_set_pos(canvas, 0, 0);
            // lv_canvas_fill_bg(canvas, lv_color_black(), LV_OPA_50);

            // lv_obj_move_foreground(ui->tool_wifi_msgbox);

            // lv_obj_add_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
            // lv_obj_clear_flag(ui->tool_wifi_msgbox, LV_OBJ_FLAG_HIDDEN);
            printf("ok is press3\n");
            // lv_obj_clear_flag(lv_layer_top(), LV_OBJ_FLAG_CLICKABLE);
        }
   
    }
}

void msgbox_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * msgbox = lv_event_get_current_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        // connect the wifi
        lv_msgbox_close(msgbox);
        printf("close msgbox\n");
    }
}

void scr_tool_wifi_event_init(void){
    lv_obj_add_event_cb(guider_ui.tool_wifi_imgbtn_3, load_disbtn_tool_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(guider_ui.tool_wifi_textare, ta_event_cb, LV_EVENT_ALL, &guider_ui);
    // lv_obj_add_event_cb(guider_ui.tool_wifi_msgbox, msgbox_event_cb, LV_EVENT_ALL, NULL);
}

void scr_incarving_event_init(void){
    lv_obj_add_event_cb(guider_ui.incarving_imgbtn_6, load_disbtn_home_cb, LV_EVENT_ALL, NULL);
}

lv_obj_t **get_scr_by_id(int scr_id)
{
    if(scr_id ==SCR_LOGO)
        return &guider_ui.logo;
    else if(scr_id == SCR_HOME)
        return &guider_ui.home;
    else if(scr_id == SCR_TOOL)
        return &guider_ui.tool;
    else if(scr_id == SCR_ENGRAING_POSITION)
        return &guider_ui.engraving;
    else if(scr_id == SCR_CONTROL)
        return &guider_ui.control;
    else if(scr_id == SCR_TOOL_INFO)
        return &guider_ui.tool_info;
    else if(scr_id == SCR_TOOL_WIFI)
        return &guider_ui.tool_wifi;        
    else if(scr_id == SCR_ENGRAING_FILE)
        return &guider_ui.file_management;  
    else if(scr_id == SCR_INCARVING)
        return &guider_ui.incarving;           
    return NULL;
}

void guider_load_screen(int scr_id)
{
    lv_obj_t **scr = NULL;
    lv_obj_t **old_scr = NULL;

    switch(scr_id)
    {
        // case SCR_LOGO:
        //     if(!guider_ui.logo) {
        //         scr = &guider_ui.logo;
        //         setup_scr_logo(&guider_ui);
        //     }
        //     break;          
        case SCR_HOME:
            if(!guider_ui.home) {
                scr = &guider_ui.home;
                setup_scr_home(&guider_ui);
            }
            break;
        case SCR_TOOL:
            if(!guider_ui.tool) {
                scr = &guider_ui.tool;
                setup_scr_tool(&guider_ui);
                scr_tool_event_init();
            }
            break;
        case SCR_ENGRAING_POSITION:
            if(!guider_ui.engraving) {
                scr = &guider_ui.engraving;
                setup_scr_engraving(&guider_ui);
                scr_engraving_event_init();
            }
            break;               
        case SCR_ENGRAING_FILE:
            if(!guider_ui.file_management) {
                scr = &guider_ui.file_management;
                setup_scr_file_management(&guider_ui);
                scr_file_management_event_init();
            }
            break;                
        case SCR_CONTROL:
            if(!guider_ui.control) {
                scr = &guider_ui.control;
                setup_scr_control(&guider_ui);
                scr_control_event_init();
            }
            break; 
        case SCR_TOOL_INFO:
            if(!guider_ui.tool_info) {
                scr = &guider_ui.tool_info;
                setup_scr_tool_info(&guider_ui);
                scr_tool_info_event_init();
            }
            break; 
        case SCR_TOOL_WIFI:
            if(!guider_ui.tool_wifi) {
                scr = &guider_ui.tool_wifi;
                setup_scr_tool_wifi(&guider_ui);
                scr_tool_wifi_event_init();
            }
            break; 
        case SCR_INCARVING:
            if(!guider_ui.incarving) {
                scr = &guider_ui.incarving;
                setup_scr_incarving(&guider_ui);
                scr_incarving_event_init();
            }
            break;                                                                                              
    }

    lv_scr_load(*scr);
    old_scr = get_scr_by_id(cur_scr);
    lv_obj_clean(*old_scr);
    lv_obj_del(*old_scr);
    
    *old_scr = NULL;
    cur_scr = scr_id;
}

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
    cur_scr = SCR_HOME;   
    // ui->logo = NULL; 
    // ui->engraving = NULL; 
    // ui->file_management = NULL; 
    // ui->incarving = NULL; 
    // ui->control = NULL; 
    // ui->tool = NULL;     
    // ui->tool_info = NULL;         
    // ui->tool_wifi = NULL;       
}

