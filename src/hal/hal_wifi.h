#ifndef hal_wifi_h
#define hal_wifi_h

#include "../main.h"

#include <WiFi.h>

namespace HAL_WIFI {
    // TODO: Clean these constants up. Some of them don't belong here.

    //Notifications
    static const int ESP_PUSHOVER_NOTIFICATION = 1;
    static const int ESP_EMAIL_NOTIFICATION    = 2;
    static const int ESP_LINE_NOTIFICATION     = 3;

    static const int DHCP_MODE   = 0;
    static const int STATIC_MODE = 1;

    //Switch
    static const int ESP_SAVE_ONLY = 0;
    static const int ESP_APPLY_NOW = 1;

    //defaults values
    static const char* DEFAULT_HOSTNAME = "makegoesp";
#ifdef CONNECT_TO_SSID
    static const char* DEFAULT_STA_SSID = CONNECT_TO_SSID;
    static const char* DEFAULT_STA_PWD  = SSID_PASSWORD;
#else   //!CONNECT_TO_SSID
    static const char* DEFAULT_STA_SSID = "LG_ESP";
    static const char* DEFAULT_STA_PWD  = "12345678";
#endif  //CONNECT_TO_SSID
    static const char* DEFAULT_STA_IP            = "0.0.0.0";
    static const char* DEFAULT_STA_GW            = "0.0.0.0";
    static const char* DEFAULT_STA_MK            = "0.0.0.0";
    static const char* DEFAULT_AP_SSID           = "LG_ESP";
    static const char* DEFAULT_AP_PWD            = "12345678";
    static const char* DEFAULT_AP_IP             = "192.168.4.1";
    static const char* DEFAULT_AP_MK             = "255.255.255.0";
    static const int   DEFAULT_AP_CHANNEL        = 1;
    static const int   DEFAULT_WEBSERVER_PORT    = 80;
    static const int   DEFAULT_HTTP_STATE        = 1;
    static const int   DEFAULT_TELNETSERVER_PORT = 8080;
    static const int   DEFAULT_TELNET_STATE      = 1;
    static const int   DEFAULT_STA_IP_MODE       = DHCP_MODE;
    static const char* HIDDEN_PASSWORD           = "********";
    static const char* DEFAULT_TOKEN             = "";
    static const int   DEFAULT_NOTIFICATION_TYPE = 0;

    //boundaries
    static const int MAX_SSID_LENGTH     = 32;
    static const int MIN_SSID_LENGTH     = 1;
    static const int MAX_PASSWORD_LENGTH = 64;
    //min size of password is 0 or upper than 8 char
    //so let set min is 8
    static const int MIN_PASSWORD_LENGTH             = 8;
    static const int MAX_HOSTNAME_LENGTH             = 32;
    static const int MIN_HOSTNAME_LENGTH             = 1;
    static const int MAX_HTTP_PORT                   = 65001;
    static const int MIN_HTTP_PORT                   = 1;
    static const int MAX_TELNET_PORT                 = 65001;
    static const int MIN_TELNET_PORT                 = 1;
    static const int MIN_CHANNEL                     = 1;
    static const int MAX_CHANNEL                     = 14;
    static const int MIN_NOTIFICATION_TOKEN_LENGTH   = 0;
    static const int MAX_NOTIFICATION_TOKEN_LENGTH   = 63;
    static const int MAX_NOTIFICATION_SETTING_LENGTH = 127;

    class WiFiConfig {
    public:
        WiFiConfig();
        
        static void        init();
        static const char* info();
        static bool        isValidIP(const char* string);
        static bool        isPasswordValid(const char* password);
        static bool        isSSIDValid(const char* ssid);
        static bool        isHostnameValid(const char* hostname);
        static uint32_t    IP_int_from_string(String& s);
        static String      IP_string_from_int(uint32_t ip_int);
        static String      Hostname() { return _hostname; }
        static char*       mac2str(uint8_t mac[8]);
        static bool        StartAP();
        static bool        StartSTA();
        static void        StopWiFi();
        static int32_t     getSignal(int32_t RSSI);
        static void        begin();
        static void        end();
        static void        handle();
        static void        reset_settings();
        static bool        Is_WiFi_on();
        static void        setWifiMode(int8_t mode);
        static int8_t      getWifiMode();
        static bool        getWifiInitStatus();
        ~WiFiConfig();

    private:
        static bool   ConnectSTA2AP();
        static void   WiFiEvent(WiFiEvent_t event);
        static String _hostname;
        static bool   _events_registered;
        static int8_t  _wifi_radio_mode;
        static bool _wifi_init_status; // true: success; false: falied
    };

    extern WiFiConfig wifi_config;
}



#endif