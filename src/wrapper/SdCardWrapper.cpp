#include <vector>
#include "lvgl.h"
#include "SdCardWrapper.h"
#include "../hal/hal_sdcard.h"
#include "../lv_generated/custom/file_grid.h"


const char* getCurrentDir()
{
    std::string currentDir = mysdcard.getCurrentDir();
    return currentDir.c_str();
}

void file_list_init()
{
    mysdcard.listDir(SD, "/");
}

void update_file_list(char * path, lv_obj_t* obj)
{
    std::vector<std::string> fileList;
    std::vector<uint8_t>     fileType;
    uint16_t index = 0;

    // clean the file list object
    lv_obj_clean(obj);
   
    // get file list
    mysdcard.listDir(SD, path);
    fileList = mysdcard.getFileList();
    fileType = mysdcard.getFileType();

    for(int i = 0; i<fileList.size(); i++){
        std::string str = fileList[i];

        file_grid_insert_cell(obj, NULL);
        file_grid_set_cell_text(obj, str.c_str());

        index++;
    }

}
