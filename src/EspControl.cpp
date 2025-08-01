#include "EspControl.hpp"
#include <WiFi.h>
#include "Logger.hpp"

EspControl::EspControl(const char* ssid, const char* password, const char* ntpServer, const long  gmtOffset_sec, const int daylightOffset_sec):
        m_ssid(ssid), m_password(password), m_ntpServer(ntpServer), m_gmtOffset_sec(gmtOffset_sec), m_daylightOffset_sec(daylightOffset_sec)
{
  // init
}

void EspControl::wifi_blocking_connect(void)
{
    int connectionAttempts = 0;
    // Connect to Wi-Fi
    WiFi.begin(m_ssid, m_password);
    Logger::log("Connecting");
    while ((WiFi.status() != WL_CONNECTED) && (connectionAttempts < 20)) {
        delay(500);
        Serial.print(".");
        connectionAttempts++;
    }
}

void EspControl::wifi_one_try_connect(void)
{
    // Connect to Wi-Fi
    WiFi.begin(m_ssid, m_password);
    Logger::log("Connecting");    
}

void EspControl::configure_blocking_ntp(void) {
    if (WiFi.status() == WL_CONNECTED) {
      
        // NTP konfigurieren
        configTime(m_gmtOffset_sec, m_daylightOffset_sec, m_ntpServer);
      
        struct tm timeinfo;
        int retry = 0;
        const int retry_count = 10;
        while (!getLocalTime(&timeinfo) && retry < retry_count) {
          Logger::log("Warte auf Zeitserver...");
          retry++;
          delay(1000);
        }
        if (retry == retry_count) {
          Logger::log("Fehler: Zeit konnte nicht abgerufen werden.");
        } else {
          Logger::log("Zeit erfolgreich abgerufen.");
        }
    }
}
