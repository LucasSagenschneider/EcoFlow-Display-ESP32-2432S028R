#include "EcoFlow.hpp"
#include <WiFi.h>
#include <HTTPClient.h>
#include "mbedtls/md.h"
#include "Logger.hpp"

EcoFlow::EcoFlow(String key, String secret, String sn, String timezone):
    m_key(key), 
    m_secret(secret), 
    m_sn(sn), 
    m_timezone(timezone),
    m_nonce(String(random(100000,999999))), 
    m_path("/iot-open/sign/device/quota/all"),
    m_url("https://api.ecoflow.com")
{
};

String EcoFlow::byteArrayToString(byte* byteArray, int length) {
  String str = "";
  for (int i = 0; i < length; i++) {
    if (byteArray[i] < 0x10) {
      str += "0"; // Führende Null hinzufügen, wenn nötig
    }
    str += String(byteArray[i], HEX);
  }
  return str;
}

String EcoFlow::hmac_sha256(const char *payload, const char *key) {	
  byte hmacResult[32];
  mbedtls_md_context_t ctx;
  mbedtls_md_type_t md_type = MBEDTLS_MD_SHA256;	
  const size_t payloadLength = strlen(payload);
  const size_t keyLength = strlen(key);
  mbedtls_md_init(&ctx);
  mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(md_type), 1); 
  mbedtls_md_hmac_starts(&ctx, (const unsigned char *) key, keyLength); 	
  mbedtls_md_hmac_update(&ctx, (const unsigned char *) payload, payloadLength);
  mbedtls_md_hmac_finish(&ctx, hmacResult);
  mbedtls_md_free(&ctx);
  return byteArrayToString(hmacResult, 32);
}

String EcoFlow::get_ecoflow_data(String path) {
  String payload;
  if (WiFi.status() == WL_CONNECTED) 
  {
    HTTPClient http;
    // Construct the API endpoint
    http.begin(String(m_url + path + "?sn=" + m_sn));

    struct tm timeinfo;
    time_t localEpoch = 0;
    if (getLocalTime(&timeinfo)) {
      localEpoch = mktime(&timeinfo);
    }
    String timestamp_in_ms = String(String(localEpoch) + "000");

    String sign_str{"sn=" + m_sn + "&" + "accessKey=" + m_key + "&" + "nonce=" + m_nonce + "&" + "timestamp=" + timestamp_in_ms};

    String hash_str = hmac_sha256(sign_str.c_str(), m_secret.c_str());

    http.addHeader("accessKey",m_key);
    http.addHeader("nonce",m_nonce);
    http.addHeader("timestamp",timestamp_in_ms);
    http.addHeader("sign",hash_str);


    int httpCode = http.GET(); // Make the GET request
    if (httpCode > 0) 
    {
      // Check for the response
      if (httpCode == HTTP_CODE_OK) 
      {
        payload = http.getString();
      }
      else
      {
        Logger::log("GET request failed, error: " + String(httpCode));
      }
      
    } 
    else 
    {
      Logger::log("GET request failed, error: " + String(httpCode));
    }
    http.end(); // Close connection
  } 
  else 
  {
    Logger::log("Not connected to Wi-Fi");
  }

  return payload;
}

power_output EcoFlow::get_power() {
  String inData = get_ecoflow_data(m_path);

  // JSON-Parsing vorbereiten
  DynamicJsonDocument doc(16384);

  power_output ret_vel;

  // Deserialisieren
  DeserializationError error = deserializeJson(doc, inData);
  if (error) {
    Serial.print(F("JSON Fehler: "));
    Serial.println(error.f_str());
    return ret_vel;
  }

  // Wert extrahieren
  JsonObject data = doc["data"];  
  ret_vel.outputWatts = static_cast<uint32_t>(data["20_1.invOutputWatts"])/10;
  ret_vel.mod1Watts = static_cast<uint32_t>(data["20_1.pv1InputWatts"])/10;
  ret_vel.mod2Watts = static_cast<uint32_t>(data["20_1.pv2InputWatts"])/10;
  Serial.print("Leistung: ");
  Serial.println(ret_vel.outputWatts);
  Serial.print("Modul 1: ");
  Serial.println(ret_vel.mod1Watts);
  Serial.print("Modul 2: ");
  Serial.println(ret_vel.mod2Watts);
  return ret_vel;
}
