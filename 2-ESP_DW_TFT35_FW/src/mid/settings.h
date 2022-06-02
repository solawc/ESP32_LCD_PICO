#pragma once

#include "../main.h"
#include <map>
#include <nvs.h>


#undef bit
#define bit(n) (1 << static_cast<unsigned int>(n))

// Define settings restore bitflags.
enum SettingsRestore {
    Defaults     = bit(0),
    Parameters   = bit(1),
    StartupLines = bit(2),
    // BuildInfo = bit(3), // Obsolete
    Wifi = bit(4),
    All  = 0xff,
};

typedef enum : uint8_t {
    GRBL = 1,  // Classic GRBL settings like $100
    EXTENDED,  // Settings added by early versions of Grbl_Esp32
    WEBSET,    // Settings for ESP3D_WebUI, stored in NVS
    GRBLCMD,   // Non-persistent GRBL commands like $H
    WEBCMD,    // ESP3D_WebUI commands that are not directly settings
} type_t;

typedef enum : uint8_t {
    WG,  // Readable and writable as guest
    WU,  // Readable and writable as user and admin
    WA,  // Readable as user and admin, writable as admin
} permissions_t;

typedef uint8_t axis_t;

class Word {
protected:
    const char*   _description;
    const char*   _grblName;
    const char*   _fullName;
    type_t        _type;
    permissions_t _permissions;

public:
    Word(type_t type, permissions_t permissions, const char* description, const char* grblName, const char* fullName);
    type_t        getType() { return _type; }
    permissions_t getPermissions() { return _permissions; }
    const char*   getName() { return _fullName; }
    const char*   getGrblName() { return _grblName; }
    const char*   getDescription() { return _description; }
};

class Command : public Word {
protected:
    Command* link;  // linked list of setting objects
    bool (*_cmdChecker)();

public:
    static Command* List;
    Command*        next() { return link; }

    ~Command() {}
    Command(const char* description, type_t type, permissions_t permissions, const char* grblName, const char* fullName, bool (*cmdChecker)());

    // The default implementation of addWebui() does nothing.
    // Derived classes may override it to do something.
    // virtual void addWebui(WebUI::JSONencoder*) {};

    // virtual Error action(char* value, WebUI::AuthenticationLevel auth_level, WebUI::ESPResponseStream* out) = 0;
};

class Setting : public Word {
private:
protected:
    // group_t _group;
    // axis_t   _axis = NO_AXIS;
    Setting* link;  // linked list of setting objects

    bool (*_checker)(char*);
    const char* _keyName;

public:
    static nvs_handle _handle;
    static void       init();
    static Setting*   List;
    Setting*          next() { return link; }

    bool check(char* s);

//     static Error report_nvs_stats(const char* value, WebUI::AuthenticationLevel auth_level, WebUI::ESPResponseStream* out) {
//         nvs_stats_t stats;
//         if (esp_err_t err = nvs_get_stats(NULL, &stats)) {
//             return Error::NvsGetStatsFailed;
//         }
//         grbl_sendf(out->client(), "[MSG: NVS Used: %d Free: %d Total: %d]\r\n", stats.used_entries, stats.free_entries, stats.total_entries);

// #if 0  // The SDK we use does not have this yet
//         nvs_iterator_t it = nvs_entry_find(NULL, NULL, NVS_TYPE_ANY);
//         while (it != NULL) {
//             nvs_entry_info_t info;
//             nvs_entry_info(it, &info);
//             it = nvs_entry_next(it);
//             grbl_sendf(out->client(), "namespace %s key '%s', type '%d' \n", info.namespace_name, info.key, info.type);
//         }
// #endif
//         return Error::Ok;
//     }

    // static Error eraseNVS(const char* value, WebUI::AuthenticationLevel auth_level, WebUI::ESPResponseStream* out) {
    //     nvs_erase_all(_handle);
    //     return Error::Ok;
    // }

    ~Setting() {}
    // Setting(const char *description, group_t group, const char * grblName, const char* fullName, bool (*checker)(char *));
    Setting(const char* description, type_t type, permissions_t permissions, const char* grblName, const char* fullName, bool (*checker)(char*));
    // axis_t getAxis() { return _axis; }
    // void   setAxis(axis_t axis) { _axis = axis; }

    // load() reads the backing store to get the current
    // value of the setting.  This could be slow so it
    // should be done infrequently, typically once at startup.
    virtual void load() {};
    virtual void setDefault() {};

    // The default implementation of addWebui() does nothing.
    // Derived classes may override it to do something.
    // virtual void addWebui(WebUI::JSONencoder*) {};

    virtual bool       setStringValue(char* value) = 0;
    bool               setStringValue(String s) { return setStringValue(s.c_str()); }
    virtual const char* getStringValue() = 0;
    virtual const char* getCompatibleValue() { return getStringValue(); }
    virtual const char* getDefaultString() = 0;
};

class IntSetting : public Setting {
private:
    int32_t _defaultValue;
    int32_t _currentValue;
    int32_t _storedValue;
    int32_t _minValue;
    int32_t _maxValue;
    bool    _currentIsNvm;

public:
    IntSetting(const char*   description,
               type_t        type,
               permissions_t permissions,
               const char*   grblName,
               const char*   name,
               int32_t       defVal,
               int32_t       minVal,
               int32_t       maxVal,
               bool (*checker)(char*),
               bool currentIsNvm = false);

    IntSetting(type_t        type,
               permissions_t permissions,
               const char*   grblName,
               const char*   name,
               int32_t       defVal,
               int32_t       minVal,
               int32_t       maxVal,
               bool (*checker)(char*) = NULL,
               bool currentIsNvm      = false) :
        IntSetting(NULL, type, permissions, grblName, name, defVal, minVal, maxVal, checker, currentIsNvm) {}

    void        load();
    void        setDefault();
    // void        addWebui(WebUI::JSONencoder*);
    bool       setStringValue(char* value);
    bool       setStringValue_nocheck(char* s);
    const char* getStringValue();
    const char* getDefaultString();

    int32_t get() { return _currentValue; }
};
extern IntSetting* Machine_type;
extern IntSetting* Machine_theme;



class FloatSetting : public Setting {
private:
    float _defaultValue;
    float _currentValue;
    float _storedValue;
    float _minValue;
    float _maxValue;

public:
    FloatSetting(const char*   description,
                 type_t        type,
                 permissions_t permissions,
                 const char*   grblName,
                 const char*   name,
                 float         defVal,
                 float         minVal,
                 float         maxVal,
                 bool (*checker)(char*));

    FloatSetting(type_t        type,
                 permissions_t permissions,
                 const char*   grblName,
                 const char*   name,
                 float         defVal,
                 float         minVal,
                 float         maxVal,
                 bool (*checker)(char*) = NULL) :
        FloatSetting(NULL, type, permissions, grblName, name, defVal, minVal, maxVal, checker) {}

    void load();
    void setDefault();
    // There are no Float settings in WebUI
    // void        addWebui(WebUI::JSONencoder*) {}
    bool       setStringValue(char* value);
    const char* getStringValue();
    const char* getDefaultString();

    float get() { return _currentValue; }
};



class StringSetting : public Setting {
private:
    String _defaultValue;
    String _currentValue;
    String _storedValue;
    int    _minLength;
    int    _maxLength;
    void   _setStoredValue(const char* s);

public:
    StringSetting(const char*   description,
                  type_t        type,
                  permissions_t permissions,
                  const char*   grblName,
                  const char*   name,
                  const char*   defVal,
                  int           min,
                  int           max,
                  bool (*checker)(char*));

    StringSetting(
        type_t type, permissions_t permissions, const char* grblName, const char* name, const char* defVal, bool (*checker)(char*) = NULL) :
        StringSetting(NULL, type, permissions, grblName, name, defVal, 0, 0, checker) {};

    void        load();
    void        setDefault();
    // void        addWebui(WebUI::JSONencoder*);
    bool       setStringValue(char* value);
    // Error       mks_setStringValue(char* s);
    const char* getStringValue();
    const char* getDefaultString();

    const char* get() { return _currentValue.c_str(); }
};


