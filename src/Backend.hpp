#pragma once

#include "Arduino.h"
#include "config.hpp"
#include "EcoFlow.hpp"
#include "EspControl.hpp"

class Backend
{
public:
    Backend(const ConfigData &configData);
    ~Backend() = default;

    void backendTick(QueueHandle_t &guiQueue);
private:
    EcoFlow m_ecoFlow;
    EspControl m_espControl;
};




