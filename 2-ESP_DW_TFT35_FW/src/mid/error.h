#pragma once

#include <map>
#include "main.h"

// 用于检测返回值相关类型
enum class Error :uint8_t { 

    // common grbl and Marlin
    Ok                          = 0,
    Overflow                    = 11,
    Eol                         = 111,
};




void grbl_protocol_main_loop();
