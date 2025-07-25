#ifndef CU_H
#define CU_H

#include "Arduino.h" 

        void wifi_blocking_connect(const char* ssid, const char* password);
        void wifi_one_try_connect(const char* ssid, const char* password);
        void update_rtc(void);
        void configure_blocking_ntp(void);
        


#endif /*CU_H*/