#include "cu.hpp"
#include <WiFi.h>


// Zeitzone (Beispiel: Deutschland = UTC+1, Sommerzeit aktiv)
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 3600;       // UTC+1
const int   daylightOffset_sec = 3600;  // Sommerzeit

void wifi_blocking_connect(const char* ssid, const char* password)
{
    int connectionAttempts = 0;
    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("Connecting");
    while ((WiFi.status() != WL_CONNECTED) && (connectionAttempts < 20)) {
        delay(500);
        Serial.print(".");
        connectionAttempts++;
    }
}

void wifi_one_try_connect(const char* ssid, const char* password)
{
    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    Serial.print("Connecting");    
}

void configure_blocking_ntp(void) {
  if (WiFi.status() == WL_CONNECTED) {

    // NTP konfigurieren
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);

    struct tm timeinfo;
    int retry = 0;
    const int retry_count = 10;
    while (!getLocalTime(&timeinfo) && retry < retry_count) {
      Serial.println("Warte auf Zeitserver...");
      retry++;
      delay(1000);
    }
    if (retry == retry_count) {
      Serial.println("Fehler: Zeit konnte nicht abgerufen werden.");
    } else {
      Serial.println("Zeit erfolgreich abgerufen.");
    }

    // Zeit anzeigen
    Serial.println(&timeinfo, "Aktuelle Zeit: %A, %d.%m.%Y %H:%M:%S");
  }
}

