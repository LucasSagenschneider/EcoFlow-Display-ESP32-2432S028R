#pragma once

#include "Arduino.h"

class RtosControl
{
public:
  RtosControl();
  ~RtosControl() = default;

  void startUserInterface(void);
  void startBackend(void);

  static void userInterfaceTask(void* parameter);
  static void backendTask(void *parameter);

private:
  static QueueHandle_t m_guiQueue;
};

