#include "ui_logic.hpp"
#include "ui/actions.h"
#include "ui/images.h"
#include "SPIFFS.h"

void ui_setup() {
  ui_init();

  // workaround - eez studio can not adress lvgl symbols
  lv_label_set_text(objects.button_lable_settings, LV_SYMBOL_SETTINGS);
  lv_label_set_text(objects.button_lable_wifi_info, LV_SYMBOL_WIFI);
}

void action_back_to_main_page(lv_event_t *e) {
  lv_scr_load(objects.main);
}

void action_go_to_settings_page(lv_event_t *e) {
  lv_scr_load(objects.settings);
}

void action_settings_set_keyboard_input(lv_event_t *e) {
  lv_obj_t *obj = (lv_obj_t *)lv_event_get_target(e);
  lv_keyboard_set_textarea(objects.settings_keyboard, obj);
}

void action_save_settings(lv_event_t *e) {
    // TODO: Implement action save_settings here
}

void display_power(uint32_t power) {
  lv_arc_set_value(objects.main_power_arc, power);
  lv_label_set_text_fmt(objects.main_power_lable, "%d Wh", power);
  
  if(power == 0) {
    lv_image_set_src(objects.main_img, &img_mond);
    lv_label_set_text(objects.main_name_lable, "Nacht");
  }
  else if((power > 0) && (power <= 100)) {
    lv_image_set_src(objects.main_img, &img_handy);
    lv_label_set_text(objects.main_name_lable, "Handy laden");
  }
  else if((power > 100) && (power <= 200)) {
    lv_image_set_src(objects.main_img, &img_radio);
    lv_label_set_text(objects.main_name_lable, "Radio hören");
  }
  else if((power > 200) && (power <= 300)) {
    lv_image_set_src(objects.main_img, &img_joystick);
    lv_label_set_text(objects.main_name_lable, "XBOX spielen");
  }
  else if((power > 300) && (power <= 400)) {
    lv_image_set_src(objects.main_img, &img_fernseh);
    lv_label_set_text(objects.main_name_lable, "Fernsehen");
  }
  else if((power > 400) && (power <= 500)) {
    lv_image_set_src(objects.main_img, &img_staubsauger);
    lv_label_set_text(objects.main_name_lable, "Staubsaugen");
  }
  else if((power > 500) && (power <= 600)) {
    lv_image_set_src(objects.main_img, &img_mikrowelle);
    lv_label_set_text(objects.main_name_lable, "Essen aufwärmen");
  }
  else if((power > 600) && (power <= 700)) {
    lv_image_set_src(objects.main_img, &img_kuhlschrank);
    lv_label_set_text(objects.main_name_lable, "Kühlen");
  }
  else if((power > 700) && (power <= 800)) {
    lv_image_set_src(objects.main_img, &img_kaffeemaschine);
    lv_label_set_text(objects.main_name_lable, "Kaffee kochen");
  }
  
}

void action_go_to_wifi_info(lv_event_t * e) {


}

// filesystem
void init_SPIFFS(void){
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS konnte nicht gestartet werden.");
    return;
  }
}
