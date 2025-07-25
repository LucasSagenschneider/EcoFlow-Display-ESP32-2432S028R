#ifndef UI_LOGIC_H
#define UI_LOGIC_H

#include "Arduino.h"
#include "ui/ui.h"


void ui_setup();
void init_SPIFFS(void);

void display_power(uint32_t power);



#endif /*UI_LOGIC_H*/