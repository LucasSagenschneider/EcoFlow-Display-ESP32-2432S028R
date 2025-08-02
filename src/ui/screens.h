#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *settings;
    lv_obj_t *main_go_to_settings;
    lv_obj_t *button_lable_settings;
    lv_obj_t *main_wifi_info;
    lv_obj_t *button_lable_wifi_info;
    lv_obj_t *main_img;
    lv_obj_t *main_power_arc;
    lv_obj_t *main_power_lable;
    lv_obj_t *main_power_mod_1;
    lv_obj_t *main_power_mod_2;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *main_name_lable;
    lv_obj_t *wifi_info;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *main_wifi_info_ip_adress;
    lv_obj_t *main_wifi_info_wifi_siganl;
    lv_obj_t *main_wifi_info_wifi_name;
    lv_obj_t *obj6;
    lv_obj_t *settings_table;
    lv_obj_t *wifi_ssid;
    lv_obj_t *wifi_password;
    lv_obj_t *ecoflow_token;
    lv_obj_t *sttings_back;
    lv_obj_t *settings_save;
    lv_obj_t *settings_keyboard;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_SETTINGS = 2,
};

void create_screen_main();
void tick_screen_main();

void create_screen_settings();
void tick_screen_settings();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/