#include "touchscreen.h"
#include "ui_logic.hpp"
#include "EcoFlow.hpp"
#include "cu.hpp"
#include <WiFi.h>

#include "PrivateData.hpp"

void GUI_Task(void *paramter);
void Data_Task(void *paramter);

void Logger(String message)
{
  static bool serial_active = false;
  if (serial_active == false)
  {
      Serial.begin(115200);
      serial_active = true;
      Serial.println(String{"[" + String(millis()) + "]" + "Logger was activated"});
  }
  Serial.println(String{"[" + String(millis()) + "]" + message});
}

const PrivateData& Get_PrivateData(void)
{
  static const PrivateData privateData;
  return privateData;
}

EcoFlow& Get_EcoFlow(void)
{
  static EcoFlow ecoFlow(Get_PrivateData().key, Get_PrivateData().secret, Get_PrivateData().sn, Get_PrivateData().timezone);
  return ecoFlow;
}

SemaphoreHandle_t lvgl_mutex;

struct GlobalData
{
  uint32_t totalPvPower = 0;
  uint32_t module1PvPower = 0;
  uint32_t module2PvPower = 0;
  String localIP = "";
};

GlobalData globalData;

void setup() {

  //setup Hardware
  touchscreen_setup();

  init_SPIFFS();
  ui_setup();

  //setup RTOS
  lvgl_mutex = xSemaphoreCreateMutex();
  xTaskCreatePinnedToCore(GUI_Task, "GUI", 4096 * 2, NULL, 3, NULL, 1);
  xTaskCreatePinnedToCore(Data_Task, "DATA", 4096 * 10, NULL, 2, NULL, 1);

}

void loop() {
  vTaskDelay(portMAX_DELAY); // blockiert dauerhaft
} 

void GUI_Task(void *paramter) {
  static const uint32_t task_period = 75;
  while (true) {

    xSemaphoreTake(lvgl_mutex, portMAX_DELAY);
    uint32_t start_time = millis();
    // ---- Do some thing ----

    //update Data
    display_power(globalData.totalPvPower);
    lv_bar_set_value(objects.main_power_mod_1, globalData.module1PvPower, LV_ANIM_OFF);
    lv_bar_set_value(objects.main_power_mod_2, globalData.module2PvPower, LV_ANIM_OFF);


    //update UI
    lv_task_handler();
    lv_tick_inc(task_period);

    // -----------------------
    int end_time = millis();
    xSemaphoreGive(lvgl_mutex);
    uint32_t duration = end_time - start_time;
    if(duration > task_period)
    {
      Logger(String("The GUI Task has an overflow. the scheduled time " + String(task_period) + " was exceeded and required " + String(duration)));
    }
    else
    {
      vTaskDelay(pdMS_TO_TICKS(task_period - duration));
    }
  }
}

void Data_Task(void *paramter) {
  // try to conect to WIFI
  wifi_blocking_connect(Get_PrivateData().ssid, Get_PrivateData().password);
  configure_blocking_ntp();

  if(WiFi.status() == WL_CONNECTED) {
    globalData.localIP = WiFi.localIP().toString();
    Logger(globalData.localIP);
  }
   

  struct tm timeinfo;

  static const uint32_t task_period = 10000;

  while (true)
  {
    uint32_t start_time = millis();
    // ---- Do some thing ----

    if(getLocalTime(&timeinfo)) {
      Serial.println(&timeinfo, "Aktuelle Zeit: %A, %d.%m.%Y %H:%M:%S");
    }
    
    power_output ecoflowData = Get_EcoFlow().get_power((Get_EcoFlow().get_ecoflow_data()));
    globalData.totalPvPower = ecoflowData.outputWatts;
    globalData.module1PvPower = ecoflowData.mod1Watts;
    globalData.module2PvPower = ecoflowData.mod2Watts;

    // -----------------------
    int end_time = millis();
    uint32_t duration = end_time - start_time;
    if(duration > task_period)
    {
      Logger(String("The Data Task has an overflow. the scheduled time " + String(task_period) + " was exceeded and required " + String(duration)));
    }
    else
    {
      vTaskDelay(pdMS_TO_TICKS(task_period - duration));
    }
  }
}