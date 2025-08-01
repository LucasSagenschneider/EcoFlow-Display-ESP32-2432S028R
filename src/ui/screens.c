#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 240, 320);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // main_go_to_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.main_go_to_settings = obj;
            lv_obj_set_pos(obj, 200, 5);
            lv_obj_set_size(obj, 35, 35);
            lv_obj_add_event_cb(obj, action_go_to_settings_page, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3a521), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_lable_settings
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.button_lable_settings = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // main_wifi_info
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.main_wifi_info = obj;
            lv_obj_set_pos(obj, 5, 5);
            lv_obj_set_size(obj, 35, 35);
            lv_obj_add_event_cb(obj, action_go_to_wifi_info, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3a521), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_lable_wifi_info
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.button_lable_wifi_info = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "");
                }
            }
        }
        {
            // main_img
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.main_img = obj;
            lv_obj_set_pos(obj, 60, 75);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_mond);
        }
        {
            // main_power_arc
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.main_power_arc = obj;
            lv_obj_set_pos(obj, 20, 35);
            lv_obj_set_size(obj, 200, 200);
            lv_arc_set_range(obj, 0, 800);
            lv_arc_set_value(obj, 50);
            lv_obj_add_state(obj, LV_STATE_DISABLED);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3a521), LV_PART_KNOB | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xfff3a521), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // main_power_lable
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.main_power_lable = obj;
            lv_obj_set_pos(obj, 91, 197);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "000 WH");
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 5, 245);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_solar);
            lv_image_set_rotation(obj, 2);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 171, 245);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_solar);
            lv_image_set_rotation(obj, 2);
        }
        {
            // main_power_mod_1
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.main_power_mod_1 = obj;
            lv_obj_set_pos(obj, 5, 300);
            lv_obj_set_size(obj, 64, 15);
            lv_bar_set_range(obj, 0, 400);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3a521), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // main_power_mod_2
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.main_power_mod_2 = obj;
            lv_obj_set_pos(obj, 171, 300);
            lv_obj_set_size(obj, 64, 15);
            lv_bar_set_range(obj, 0, 400);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3a521), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(obj, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_animimg_create(parent_obj);
            lv_obj_set_pos(obj, 69, 201);
            lv_obj_set_size(obj, 102, 100);
            static const lv_image_dsc_t *images[61] = {
                &img_frame_00_delay_0_08s,
                &img_frame_01_delay_0_04s,
                &img_frame_02_delay_0_04s,
                &img_frame_03_delay_0_04s,
                &img_frame_04_delay_0_04s,
                &img_frame_05_delay_0_04s,
                &img_frame_06_delay_0_04s,
                &img_frame_07_delay_0_04s,
                &img_frame_08_delay_0_04s,
                &img_frame_09_delay_0_04s,
                &img_frame_10_delay_0_04s,
                &img_frame_11_delay_0_04s,
                &img_frame_12_delay_0_04s,
                &img_frame_13_delay_0_04s,
                &img_frame_14_delay_0_04s,
                &img_frame_15_delay_0_04s,
                &img_frame_16_delay_0_04s,
                &img_frame_17_delay_0_04s,
                &img_frame_18_delay_0_04s,
                &img_frame_19_delay_0_04s,
                &img_frame_20_delay_0_04s,
                &img_frame_21_delay_0_04s,
                &img_frame_22_delay_0_04s,
                &img_frame_23_delay_0_04s,
                &img_frame_24_delay_0_04s,
                &img_frame_25_delay_0_04s,
                &img_frame_26_delay_0_04s,
                &img_frame_27_delay_0_04s,
                &img_frame_28_delay_0_04s,
                &img_frame_29_delay_0_04s,
                &img_frame_30_delay_0_04s,
                &img_frame_31_delay_0_04s,
                &img_frame_32_delay_0_04s,
                &img_frame_33_delay_0_04s,
                &img_frame_34_delay_0_04s,
                &img_frame_35_delay_0_04s,
                &img_frame_36_delay_0_04s,
                &img_frame_37_delay_0_04s,
                &img_frame_38_delay_0_44s,
                &img_frame_39_delay_0_04s,
                &img_frame_40_delay_0_04s,
                &img_frame_41_delay_0_04s,
                &img_frame_42_delay_0_04s,
                &img_frame_43_delay_0_04s,
                &img_frame_44_delay_0_04s,
                &img_frame_45_delay_0_04s,
                &img_frame_46_delay_0_04s,
                &img_frame_47_delay_0_04s,
                &img_frame_48_delay_0_04s,
                &img_frame_49_delay_0_04s,
                &img_frame_50_delay_0_04s,
                &img_frame_51_delay_0_04s,
                &img_frame_52_delay_0_04s,
                &img_frame_53_delay_0_04s,
                &img_frame_54_delay_0_04s,
                &img_frame_55_delay_0_04s,
                &img_frame_56_delay_0_04s,
                &img_frame_57_delay_0_04s,
                &img_frame_58_delay_0_04s,
                &img_frame_59_delay_0_08s,
                &img_frame_60_delay_0_12s,
            };
            lv_animimg_set_src(obj, (const void **)images, 61);
            lv_animimg_set_duration(obj, 3000);
            lv_animimg_set_repeat_count(obj, LV_ANIM_REPEAT_INFINITE);
            lv_animimg_start(obj);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 175, 239);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Modul 2");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 13, 237);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Modul 1");
        }
        {
            // main_name_lable
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.main_name_lable = obj;
            lv_obj_set_pos(obj, 120, 14);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}

void create_screen_settings() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 240, 320);
    lv_obj_set_scrollbar_mode(obj, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Settings_Table
            lv_obj_t *obj = lv_table_create(parent_obj);
            objects.settings_table = obj;
            lv_obj_set_pos(obj, 0, 35);
            lv_obj_set_size(obj, 240, 165);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "WIFI:");
                }
                {
                    // wifi_ssid
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.wifi_ssid = obj;
                    lv_obj_set_pos(obj, -2, 16);
                    lv_obj_set_size(obj, 240, 35);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "SSID");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, action_settings_set_keyboard_input, LV_EVENT_CLICKED, (void *)0);
                }
                {
                    // wifi_password
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.wifi_password = obj;
                    lv_obj_set_pos(obj, -2, 51);
                    lv_obj_set_size(obj, 240, 35);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "Password");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, true);
                    lv_obj_add_event_cb(obj, action_settings_set_keyboard_input, LV_EVENT_CLICKED, (void *)0);
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 87);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Ecoflow:");
                }
                {
                    // ecoflow_token
                    lv_obj_t *obj = lv_textarea_create(parent_obj);
                    objects.ecoflow_token = obj;
                    lv_obj_set_pos(obj, -2, 103);
                    lv_obj_set_size(obj, 240, 36);
                    lv_textarea_set_max_length(obj, 128);
                    lv_textarea_set_placeholder_text(obj, "Token");
                    lv_textarea_set_one_line(obj, true);
                    lv_textarea_set_password_mode(obj, false);
                    lv_obj_add_event_cb(obj, action_settings_set_keyboard_input, LV_EVENT_CLICKED, (void *)0);
                }
            }
        }
        {
            // sttings_back
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.sttings_back = obj;
            lv_obj_set_pos(obj, 9, 5);
            lv_obj_set_size(obj, 59, 25);
            lv_obj_add_event_cb(obj, action_back_to_main_page, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3a521), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_event_cb(obj, action_back_to_main_page, LV_EVENT_CLICKED, (void *)0);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Back");
                }
            }
        }
        {
            // settings_save
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.settings_save = obj;
            lv_obj_set_pos(obj, 168, 5);
            lv_obj_set_size(obj, 64, 25);
            lv_obj_add_event_cb(obj, action_save_settings, LV_EVENT_CLICKED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xfff3a521), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_add_event_cb(obj, action_save_settings, LV_EVENT_CLICKED, (void *)0);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Save");
                }
            }
        }
        {
            // settings_keyboard
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.settings_keyboard = obj;
            lv_obj_set_pos(obj, 0, 200);
            lv_obj_set_size(obj, 240, 120);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_settings();
}

void tick_screen_settings() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_settings,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_settings();
}
