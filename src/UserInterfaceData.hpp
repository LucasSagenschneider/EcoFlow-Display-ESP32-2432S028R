#pragma once

#include "Arduino.h"

struct GuiData
{
  uint32_t totalPvPower = 0;
  uint32_t module1PvPower = 0;
  uint32_t module2PvPower = 0;
  String ssid = "";
  String signal = "";
  String ipAdress = "not connected";
};