#pragma once

#include "Arduino.h" 

class EspControl 
{
    public:
        EspControl(const char* ssid, const char* password, const char* ntpServer, const long  gmtOffset_sec, const int daylightOffset_sec);
        ~EspControl() = default;
        void wifi_blocking_connect(void);
        void wifi_one_try_connect(void);
        void configure_blocking_ntp(void);
        void Logger(String message);

    private:
        const char* m_ssid;
        const char* m_password;

        // Zeitzone (Beispiel: Deutschland = UTC+1, Sommerzeit aktiv)
        const char* m_ntpServer;
        const long  m_gmtOffset_sec;
        const int   m_daylightOffset_sec;  
};
