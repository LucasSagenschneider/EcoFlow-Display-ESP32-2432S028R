// EcoFlow functions to request data from the cloud

#ifndef EcoFlow_h
#define EcoFlow_h

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
        EcoFlow(String key, String secret, String sn, String timezone):
                m_key(key), m_secret(secret), m_sn(sn), m_timezone(timezone)
                {
                  m_rtc = ESP32Time(7200); // offset in seconds GMT+1
                };
        String get_ecoflow_data(void);
        ESP32Time get_ESP32Time();
        power_output get_power(String inData);


    private:
        String byteArrayToString(byte* byteArray, int length);
        String hmac_sha256(const char *payload, const char *key);

        bool m_rtcIsUpToDate = false;
        String m_url     = "https://api.ecoflow.com";
        String m_path    = "/iot-open/sign/device/quota/all";
        String m_nonce   = String(random(100000,999999));
        String m_key;
        String m_secret;
        String m_sn;
        String m_timezone;
        ESP32Time m_rtc;
};

#endif


