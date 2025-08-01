#include "RtosControl.hpp"
#include "Backend.hpp"
#include "UserInterface.hpp"
#include "config.hpp"
#include "Logger.hpp"

QueueHandle_t RtosControl::m_guiQueue = nullptr;

RtosControl::RtosControl()
{
  //setup data queue
  Logger::log("System Start");
  m_guiQueue = xQueueCreate(10, sizeof(GuiData));  // max. 10 Einträge
}

void RtosControl::startUserInterface(void)
{
  xTaskCreatePinnedToCore(userInterfaceTask, "USER_INTERFACE", 4096 * 2, NULL, 3, NULL, 1);
}

void RtosControl::startBackend(void)
{
  xTaskCreatePinnedToCore(backendTask, "BACKEND", 4096 * 10, NULL, 2, NULL, 1);
}

void RtosControl::userInterfaceTask(void* parameter) {

  static const uint32_t task_period = 75;

  // Initialize the UserInterface object
  UserInterface userInterface(task_period);

  while (true) {

    uint32_t start_time = millis();
    // ---- Do some thing ----
    userInterface.userInterfaseTick(m_guiQueue);
    // -----------------------
    int end_time = millis();
    uint32_t duration = end_time - start_time;
    if(duration > task_period)
    {
      Logger::log(String("The GUI Task has an overflow. the scheduled time " + String(task_period) + " was exceeded and required " + String(duration)));
    }
    else
    {
      vTaskDelay(pdMS_TO_TICKS(task_period - duration));
    }
  }
}

void RtosControl::backendTask(void *parameter) {
  // Initialize the Backend object with the configuration data
  const ConfigData configData;
  Backend backend(configData);

  static const uint32_t task_period = 10000;

  while (true)
  {
    uint32_t start_time = millis();
    // ---- Do some thing ----
    backend.backendTick(m_guiQueue);
    // -----------------------
    int end_time = millis();
    uint32_t duration = end_time - start_time;
    if(duration > task_period)
    {
      Logger::log(String("The Data Task has an overflow. the scheduled time " + String(task_period) + " was exceeded and required " + String(duration)));
    }
    else
    {
      vTaskDelay(pdMS_TO_TICKS(task_period - duration));
    }
  }
}
