#pragma once

#include "Arduino.h"
#include "ui/ui.h"
#include "UserInterfaceData.hpp"

class UserInterface
{
public:
  UserInterface(uint32_t task_period);
  ~UserInterface() = default;
  void userInterfaseTick(QueueHandle_t &guiQueue);
private:
  GuiData m_receivedData;
  uint32_t m_task_period;
  void updateElements(void);
};

