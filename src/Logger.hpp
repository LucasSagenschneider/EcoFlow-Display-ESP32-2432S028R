#pragma once

#include <Arduino.h>

class Logger
{
private:
    /* data */
public:
    Logger() = default;
    ~Logger() = default;
    static void log(String message)
    {
        static bool serial_active = false;
        if (serial_active == false)
        {
            Serial.begin(115200);
            serial_active = true;
            Serial.println(String{"[" + String(millis()) + "]" + "Logger was activated"});
        }
        Serial.println(String{"[" + String(millis()) + "]" + message});     
    };
};
