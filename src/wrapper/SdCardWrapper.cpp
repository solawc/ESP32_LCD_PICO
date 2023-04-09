#include <vector>
#include "lvgl.h"
#include "SdCardWrapper.h"
#include "../hal/hal_sdcard.h"
#include "../lv_generated/custom/file_grid.h"
#include "../mid/report.h"

#define PAGE_MAX_FILE 8 // one page max files
static uint64_t fileListPointer = 0;

const char* getCurrentDir()
{
    std::string currentDir = mysdcard.getCurrentDir();
    return currentDir.c_str();
}

void file_list_init()
{
    mysdcard.listDir(SD, "/");
    fileListPointer = 0;
}

/**
 * para: flag, 0: initial; 1:next page, 2:last page
*/
void update_file_list(char * path, lv_obj_t* obj, uint8_t flag)
{
    std::vector<std::string> fileList;
    std::vector<uint8_t>     fileType;

    // clean the file list object
    lv_obj_clean(obj);
   
    // get file list
    debug_send(CLIENT_SERIAL, path);
    mysdcard.listDir(SD, path);
    fileList = mysdcard.getFileList();
    fileType = mysdcard.getFileType();

    // for(int i = 0; i<fileList.size(); i++){
    //     std::string str = fileList[i];

    //     std::string tmp = "File Name:" + str + "\n";
    //     debug_send(CLIENT_SERIAL, tmp.c_str());
    // }

    uint8_t files_cnt = 0;
    uint8_t cnt = 0;
    // debug_send(CLIENT_SERIAL, std::to_string(fileListPointer).c_str());

    switch (flag)
    {
        case 0: 
            files_cnt = fileList.size(); 
            cnt = (files_cnt >PAGE_MAX_FILE)?PAGE_MAX_FILE:files_cnt;
            for(int i = 0; i<cnt; i++){
                std::string str = fileList[fileListPointer+i];

                file_grid_insert_cell(obj, NULL);
                file_grid_set_cell_text(obj, str.c_str());
                std::string tmp = "File Name:" + str + "\n";
                debug_send(CLIENT_SERIAL, tmp.c_str());
            } 

            fileListPointer +=cnt;    
            break;
        case 1:// next page
            files_cnt = fileList.size();
            cnt = files_cnt - fileListPointer;
            debug_send(CLIENT_SERIAL, std::to_string(cnt).c_str());
            if(cnt <= 0)
            {
                // do  nothing;
            }
            else if (cnt < PAGE_MAX_FILE )
            {
                for(int i = 0; i<cnt; i++){
                    std::string str = fileList[fileListPointer+i];

                    file_grid_insert_cell(obj, NULL);
                    file_grid_set_cell_text(obj, str.c_str());
                    std::string tmp = "File Name:" + str + "\n";
                    debug_send(CLIENT_SERIAL, tmp.c_str());
                }  

                fileListPointer +=cnt;        
            }
            else
            {
                for(int i = 0; i<PAGE_MAX_FILE; i++){
                    std::string str = fileList[fileListPointer+i];

                    file_grid_insert_cell(obj, NULL);
                    file_grid_set_cell_text(obj, str.c_str());
                    std::string tmp = "File Name:" + str + "\n";
                    debug_send(CLIENT_SERIAL, tmp.c_str());
                }  

                fileListPointer +=PAGE_MAX_FILE; 
            }
            break;            
        case 2:// last page
            if(fileListPointer > PAGE_MAX_FILE)
            {
                for(int i = 0; i<PAGE_MAX_FILE; i++){
                    std::string str = fileList[fileListPointer-PAGE_MAX_FILE+i];

                    file_grid_insert_cell(obj, NULL);
                    file_grid_set_cell_text(obj, str.c_str());
                    std::string tmp = "File Name:" + str + "\n";
                    debug_send(CLIENT_SERIAL, tmp.c_str());
                }

                fileListPointer -=PAGE_MAX_FILE;
            }
            else
            {           
                for(int i = 0; i<PAGE_MAX_FILE; i++){
                    std::string str = fileList[i];

                    file_grid_insert_cell(obj, NULL);
                    file_grid_set_cell_text(obj, str.c_str());
                    std::string tmp = "File Name:" + str + "\n";
                    debug_send(CLIENT_SERIAL, tmp.c_str());
                }    
                fileListPointer = 0;        
            }
            break;                    
        // default:
        //     break;
    }

}

uint8_t get_sd_state(bool refresh)
{
    SDState state = mysdcard.get_sd_state(true);
    return static_cast<uint8_t>(state);
}
