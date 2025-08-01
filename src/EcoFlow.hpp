#pragma once

#include "Arduino.h" 
#include <ESP32Time.h>
#include <ArduinoJson.h>

struct power_output
{
  uint32_t outputWatts;
  uint32_t mod1Watts;
  uint32_t mod2Watts;
};

class EcoFlow 
{
    public:
        EcoFlow(String key, String secret, String sn, String timezone);
        ~EcoFlow() = default;
        power_output get_power();


    private:
        String byteArrayToString(byte* byteArray, int length);
        String hmac_sha256(const char *payload, const char *key);
        String get_ecoflow_data(String path);

        bool m_rtcIsUpToDate = false;
        String m_url;
        String m_path;
        String m_nonce;
        String m_key;
        String m_secret;
        String m_sn;
        String m_timezone;
        ESP32Time m_rtc;
};
