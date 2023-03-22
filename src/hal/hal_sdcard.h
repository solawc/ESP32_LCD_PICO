#pragma once 

#include "main.h"
#include <FS.h>
#include <SD.h>
#include <SPI.h>
#include <vector>

#define GRBL_SPI_SCK 			            GPIO_NUM_14
#define GRBL_SPI_MISO 			            GPIO_NUM_4
#define GRBL_SPI_MOSI 			            GPIO_NUM_13
#define GRBL_SPI_SS 			            GPIO_NUM_5
#define SDCARD_DET_PIN 			            GPIO_NUM_36
#define GRBL_SPI_FREQ 			            4000000        /* ESP32 LCD PICO MAX Speed is 27MHz. */

#define USE_HSPI_FOR_SD 1
#ifdef USE_HSPI_FOR_SD
extern SPIClass SPI_H;
#define SD_SPI SPI_H
#else
#define SD_SPI SPI_L
#endif

//#define SDCARD_DET_PIN -1
const int SDCARD_DET_VAL = 0;  // for now, CD is close to ground

enum class SDState : uint8_t {
    Idle          = 0,
    NotPresent    = 1,
    Busy          = 2,
    BusyPrinting  = 2,
    BusyUploading = 3,
    BusyParsing   = 4,
};

extern bool                       SD_ready_next;  // Grbl has processed a line and is waiting for another
extern uint8_t                    SD_client;
extern uint32_t                   sd_current_line_number;

#define SD_ROOT_PATH              "/sd"
#define SD_MAX_OPEN_FILE          2



class SDCard {
    typedef struct file_info_t
    {
        std::vector<std::string>   list;
        /**
         * file:1
         * directory:2
         */
        std::vector<uint8_t>       type;
    }FILE_INFO_T;

private:
    File    myFile;
    bool    SD_ready_next = false;
    FILE_INFO_T                fileList;
    std::string                currentDir;    
public:
    void  cardInit(void);
    boolean  mount(void);
    void     unmount(void);
    SDState  get_sd_state(bool refresh);
    SDState  set_sd_state(SDState state);

    boolean  openFile(fs::FS& fs, const char* path);                                        /* 打开文件 */
    boolean  closeFile();                                                                   /* 关闭文件 */
    boolean  readFileLine(char* line, int maxlen);                                          /* 读取一行文件 */
    
    void     listDir(fs::FS& fs, const char* dirname, uint8_t levels, uint8_t client);      /* 列出SD卡文件列表 */
    void     listDir(fs::FS& fs, const char* dirname);
    
    float    sd_report_perc_complete();                                                     /* 报告打印进度 */     
     
    uint32_t sd_get_current_line_number();                                                  /* 获取当前文件行数 */  

    void     sd_get_current_filename(char* name);

    uint64_t get_sd_size(void);

    void     setSdNext(bool state);
    bool     getSdNext(void);

    std::vector<std::string>     getFileList();
    std::vector<uint8_t>         getFileType();
    std::string                  getCurrentDir();
    void                         cleanFileList();
    
    bool    isDirectory(fs::FS& fs, const char* dirname);    
};
extern SDCard mysdcard;