// defines the Private Data
#ifndef PrivateData_h
#define PrivateData_h

#include <Arduino.h>

struct PrivateData
{
    // Replace with your network credentials
    const char* ssid = "SSID";
    const char* password = "PW";

    // Type the timezone you want to get the time for
    String timezone = "Europe/Berlin";

    // EcoFlow
    String key     = "ABC";
    String secret  = "ABC";
    String sn      = "ABC"; 
};
#endif