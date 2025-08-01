#include "RtosControl.hpp"

void setup() {
  // Start System
  static RtosControl rtosControl;

  rtosControl.startBackend();
  rtosControl.startUserInterface();
}

void loop() {
  vTaskDelay(portMAX_DELAY); // not needed RTOS is used
} 
