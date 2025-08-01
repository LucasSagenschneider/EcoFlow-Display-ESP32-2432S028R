#include "Backend.hpp"
#include "UserInterfaceData.hpp"
#include "WiFi.h"

Backend::Backend(const ConfigData &configData):
    m_ecoFlow(configData.key, configData.secret, configData.sn, configData.timezone),
    m_espControl(configData.ssid, configData.password, configData.ntpServer, configData.gmtOffset_sec, configData.daylightOffset_sec)
{
    m_espControl.wifi_blocking_connect();
    m_espControl.configure_blocking_ntp();
}

void Backend::backendTick(QueueHandle_t &guiQueue)
{
    if(WiFi.status() == WL_CONNECTED) {
        
        power_output ecoflowData = m_ecoFlow.get_power();

        GuiData sendData;
        sendData.totalPvPower = ecoflowData.outputWatts;
        sendData.module1PvPower = ecoflowData.mod1Watts;
        sendData.module2PvPower = ecoflowData.mod2Watts;

        xQueueSend(guiQueue, &sendData, portMAX_DELAY);
    
    }
}