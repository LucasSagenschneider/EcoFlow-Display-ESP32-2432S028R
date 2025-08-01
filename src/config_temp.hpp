#pragma once

#include <Arduino.h>

struct ConfigData
{
    // Replace with your network credentials
    const char* ssid = "abcdefg";
    const char* password = "1234567890";

    // Type the timezone you want to get the time for
    String timezone = "Europe/Berlin";

    const char* ntpServer = "pool.ntp.org";
    const long  gmtOffset_sec = 3600;     // UTC+1
    const int daylightOffset_sec = 3600;  // Sommerzeit

    // EcoFlow
    String key     = "abcdefg";
    String secret  = "abcdefg";
    String sn      = "abcdefg"; 
};
