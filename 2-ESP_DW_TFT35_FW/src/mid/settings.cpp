#include "settings.h"

char* trim(char* str) {
    char* end;
    // Trim leading space
    while (::isspace((unsigned char)*str)) {
        str++;
    }
    if (*str == 0) {  // All spaces?
        return str;
    }
    // Trim trailing space
    end = str + ::strlen(str) - 1;
    while (end > str && ::isspace((unsigned char)*end)) {
        end--;
    }
    // Write new null terminator character
    end[1] = '\0';
    return str;
}

uint8_t read_float(const char* line, uint8_t* char_counter, float* float_ptr) {
    const char*   ptr = line + *char_counter;
    unsigned char c;
    // Grab first character and increment pointer. No spaces assumed in line.
    c = *ptr++;
    // Capture initial positive/minus character
    bool isnegative = false;
    if (c == '-') {
        isnegative = true;
        c          = *ptr++;
    } else if (c == '+') {
        c = *ptr++;
    }

    // Extract number into fast integer. Track decimal in terms of exponent value.
    uint32_t intval    = 0;
    int8_t   exp       = 0;
    uint8_t  ndigit    = 0;
    bool     isdecimal = false;
    while (1) {
        c -= '0';
        if (c <= 9) {
            ndigit++;
            if (ndigit <= 8) {
                if (isdecimal) {
                    exp--;
                }
                intval = intval * 10 + c;
            } else {
                if (!(isdecimal)) {
                    exp++;  // Drop overflow digits
                }
            }
        } else if (c == (('.' - '0') & 0xff) && !(isdecimal)) {
            isdecimal = true;
        } else {
            break;
        }
        c = *ptr++;
    }
    // Return if no digits have been read.
    if (!ndigit) {
        return false;
    }

    // Convert integer into floating point.
    float fval;
    fval = (float)intval;
    // Apply decimal. Should perform no more than two floating point multiplications for the
    // expected range of E0 to E-4.
    if (fval != 0) {
        while (exp <= -2) {
            fval *= 0.01;
            exp += 2;
        }
        if (exp < 0) {
            fval *= 0.1;
        } else if (exp > 0) {
            do {
                fval *= 10.0;
            } while (--exp > 0);
        }
    }
    // Assign floating point value with correct sign.
    if (isnegative) {
        *float_ptr = -fval;
    } else {
        *float_ptr = fval;
    }
    *char_counter = ptr - line - 1;  // Set char_counter to next statement
    return true;
}

bool Setting::check(char* s) {

    if (!_checker) {
        return true;
    }
    return _checker(s) ? true : false;
}


nvs_handle Setting::_handle = 0;

void Setting::init() {
    if (!_handle) {
        if (esp_err_t err = nvs_open("Grbl_ESP32", NVS_READWRITE, &_handle)) {
            serial_sendf(CLIENT_SERIAL, "nvs_open failed with error %d\r\n", err);
        }else {
            debug_send(CLIENT_ALL, "debug:nvs_open succeed\n");
        }
    }
}

Setting* Setting::List = NULL;

Word::Word(type_t type, permissions_t permissions, const char* description, const char* grblName, const char* fullName) :
    _description(description), _grblName(grblName), _fullName(fullName), _type(type), _permissions(permissions) {}

Setting::Setting(
    const char* description, type_t type, permissions_t permissions, const char* grblName, const char* fullName, bool (*checker)(char*)) :
    Word(type, permissions, description, grblName, fullName),
    _checker(checker) {
    link = List;
    List = this;

    // NVS keys are limited to 15 characters, so if the setting name is longer
    // than that, we derive a 15-character name from a hash function
    size_t len = strlen(fullName);
    if (len <= 15) {
        _keyName = _fullName;
    } else {
        // This is Donald Knuth's hash function from Vol 3, chapter 6.4
        char*    hashName = (char*)malloc(16);
        uint32_t hash     = len;
        for (const char* s = fullName; *s; s++) {
            hash = ((hash << 5) ^ (hash >> 27)) ^ (*s);
        }
        sprintf(hashName, "%.7s%08x", fullName, hash);
        _keyName = hashName;
    }
}

IntSetting::IntSetting(const char*   description,
                       type_t        type,
                       permissions_t permissions,
                       const char*   grblName,
                       const char*   name,
                       int32_t       defVal,
                       int32_t       minVal,
                       int32_t       maxVal,
                       bool (*checker)(char*) = NULL,
                       bool currentIsNvm) :
    Setting(description, type, permissions, grblName, name, checker),
    _defaultValue(defVal), _currentValue(defVal), _minValue(minVal), _maxValue(maxVal), _currentIsNvm(currentIsNvm) {
    _storedValue = std::numeric_limits<int32_t>::min();
}

void IntSetting::load() {
    esp_err_t err = nvs_get_i32(_handle, _keyName, &_storedValue);
    if (err) {
        _storedValue  = std::numeric_limits<int32_t>::min();
        _currentValue = _defaultValue;
    } else {
        _currentValue = _storedValue;
    }
}

void IntSetting::setDefault() {
    if (_currentIsNvm) {
        nvs_erase_key(_handle, _keyName);
    } else {
        _currentValue = _defaultValue;
        if (_storedValue != _currentValue) {
            nvs_erase_key(_handle, _keyName);
        }
    }
}


bool IntSetting::setStringValue(char* s) {
    // s         = trim(s);
    bool err  = check(s);

    if(err != true) return false; 

    char*   endptr;
    int32_t convertedValue = strtol(s, &endptr, 10);
    if (endptr == s || *endptr != '\0') {
        return false;
    }
    if (convertedValue < _minValue || convertedValue > _maxValue) {
        return false;
    }

    // If we don't see the NVM state, we have to make this the live value:
    if (!_currentIsNvm) {
        _currentValue = convertedValue;
    }

    if (_storedValue != convertedValue) {
        if (convertedValue == _defaultValue) {
            nvs_erase_key(_handle, _keyName);
        } else {
            if (nvs_set_i32(_handle, _keyName, convertedValue)) {
                return false;
            }
            _storedValue = convertedValue;
        }
    }
    check(NULL);
    return true;
}

bool IntSetting::setStringValue_nocheck(char* s) {
    s         = trim(s);
    // Error err = check(s);
    // if (err != Error::Ok) {
    //     return err;
    // }
    char*   endptr;
    int32_t convertedValue = strtol(s, &endptr, 10);
    // grbl_sendf(CLIENT_SERIAL, "GETI NUM = %d\n", convertedValue);
    if (endptr == s || *endptr != '\0') {
        // return Error::BadNumberFormat;
        return false;
    }
    if (convertedValue < _minValue || convertedValue > _maxValue) {
        // return Error::NumberRange;
        return false;
    }

    // If we don't see the NVM state, we have to make this the live value:
    if (!_currentIsNvm) {
        _currentValue = convertedValue;
    }

    if (_storedValue != convertedValue) {
        if (convertedValue == _defaultValue) {
            nvs_erase_key(_handle, _keyName);
        } else {
            if (nvs_set_i32(_handle, _keyName, convertedValue)) {
                // return Error::NvsSetFailed;
                return false;
            }
            _storedValue = convertedValue;
        }
    }
    check(NULL);
    // return Error::Ok;
    return true;
}

const char* IntSetting::getDefaultString() {
    static char strval[32];
    sprintf(strval, "%d", _defaultValue);
    return strval;
}

const char* IntSetting::getStringValue() {
    static char strval[32];

    int currentSettingValue;
    if (_currentIsNvm) {
        if (std::numeric_limits<int32_t>::min() == _storedValue) {
            currentSettingValue = _defaultValue;
        } else {
            currentSettingValue = _storedValue;
        }
    } else {
        currentSettingValue = get();
    }

    sprintf(strval, "%d", currentSettingValue);
    return strval;
}

// void IntSetting::addWebui(WebUI::JSONencoder* j) {
//     if (getDescription()) {
//         j->begin_webui(getName(), getDescription(), "I", getStringValue(), _minValue, _maxValue);
//         j->end_object();
//     }
// }

FloatSetting::FloatSetting(const char*   description,
                           type_t        type,
                           permissions_t permissions,
                           const char*   grblName,
                           const char*   name,
                           float         defVal,
                           float         minVal,
                           float         maxVal,
                           bool (*checker)(char*) = NULL) :
    Setting(description, type, permissions, grblName, name, checker),
    _defaultValue(defVal), _currentValue(defVal), _minValue(minVal), _maxValue(maxVal) {}

void FloatSetting::load() {
    union {
        int32_t ival;
        float   fval;
    } v;
    if (nvs_get_i32(_handle, _keyName, &v.ival)) {
        _currentValue = _defaultValue;
    } else {
        _currentValue = v.fval;
    }
}

void FloatSetting::setDefault() {
    _currentValue = _defaultValue;
    if (_storedValue != _currentValue) {
        nvs_erase_key(_handle, _keyName);
    }
}

bool FloatSetting::setStringValue(char* s) {
    s         = trim(s);
    bool err = check(s);
    if (err != true) {
        // return err;
        return false;
    }

    float   convertedValue;
    uint8_t len    = strlen(s);
    uint8_t retlen = 0;
    if (!read_float(s, &retlen, &convertedValue) || retlen != len) {
        // return Error::BadNumberFormat;
        return false;
    }
    if (convertedValue < _minValue || convertedValue > _maxValue) {
        // return Error::NumberRange;
        return false;
    }
    _currentValue = convertedValue;
    if (_storedValue != _currentValue) {
        if (_currentValue == _defaultValue) {
            nvs_erase_key(_handle, _keyName);
        } else {
            union {
                int32_t ival;
                float   fval;
            } v;
            v.fval = _currentValue;
            if (nvs_set_i32(_handle, _keyName, v.ival)) {
                // return Error::NvsSetFailed;
                return false;
            }
            _storedValue = _currentValue;
        }
    }
    check(NULL);
    // return Error::Ok;
    return true;
}

const char* FloatSetting::getDefaultString() {
    static char strval[32];
    (void)sprintf(strval, "%.3f", _defaultValue);
    return strval;
}

const char* FloatSetting::getStringValue() {
    static char strval[32];
    (void)sprintf(strval, "%.3f", get());
#if 0
    // With the goal of representing both large and small floating point
    // numbers compactly while showing clearly that the are floating point,
    // remove trailing zeros leaving at least one post-decimal digit.
    // The loop is guaranteed to terminate because the string contains
    // a decimal point which is not a '0'.
    for (char *p = strval + strlen(strval) - 1; *p == '0'; --p) {
        if (*(p-1) != '.' && *(p-1) != ',') {
            *p = '\0';
        }
    }
#endif
    return strval;
}

StringSetting::StringSetting(const char*   description,
                             type_t        type,
                             permissions_t permissions,
                             const char*   grblName,
                             const char*   name,
                             const char*   defVal,
                             int           min,
                             int           max,
                             bool (*checker)(char*)) :
    Setting(description, type, permissions, grblName, name, checker) {
    _defaultValue = defVal;
    _currentValue = defVal;
    _minLength    = min;
    _maxLength    = max;
};


void StringSetting::load() {
    size_t    len = 0;
    esp_err_t err = nvs_get_str(_handle, _keyName, NULL, &len);
    if (err) {
        _storedValue  = _defaultValue;
        _currentValue = _defaultValue;
        return;
    }
    char buf[len];
    err = nvs_get_str(_handle, _keyName, buf, &len);
    if (err) {
        _storedValue  = _defaultValue;
        _currentValue = _defaultValue;
        return;
    }
    _storedValue  = String(buf);
    _currentValue = _storedValue;
}

void StringSetting::setDefault() {
    _currentValue = _defaultValue;
    if (_storedValue != _currentValue) {
        nvs_erase_key(_handle, _keyName);
    }
}

bool StringSetting::setStringValue(char* s) {  
    if (_minLength && _maxLength && (strlen(s) < _minLength || strlen(s) > _maxLength)) {
        // grbl_send(CLIENT_ALL, "return BadNumberFormat\n");
        // return Error::BadNumberFormat;
        return false;
    }
    bool err = check(s);
    if (err != true) {
        // grbl_send(CLIENT_ALL, "return err\n");
        // return err;
        return false;
    }
    _currentValue = s;
    if (_storedValue != _currentValue) {
        if (_currentValue == _defaultValue) {
            nvs_erase_key(_handle, _keyName);
            _storedValue = _defaultValue;
        } else {
            if (nvs_set_str(_handle, _keyName, _currentValue.c_str())) {
                // return Error::NvsSetFailed;
                return false;
            }
            _storedValue = _currentValue;
        }
    }
    check(NULL);
    // return Error::Ok;
    return true;
}