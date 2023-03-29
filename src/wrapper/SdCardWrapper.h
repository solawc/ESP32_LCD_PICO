#ifndef __SdCardWrapper_h
#define __SdCardWrapper_h

#ifdef __cplusplus
extern "C" {
#endif


extern const char* getCurrentDir();
extern void file_list_init();
extern void update_file_list(char * path, lv_obj_t* obj);
extern uint8_t get_sd_state(bool refresh);

#ifdef __cplusplus
};
#endif


#endif