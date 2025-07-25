#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_settings_set_keyboard_input(lv_event_t * e);
extern void action_back_to_main_page(lv_event_t * e);
extern void action_save_settings(lv_event_t * e);
extern void action_go_to_settings_page(lv_event_t * e);
extern void action_go_to_wifi_info(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/