#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_coffee_machine;
extern const lv_img_dsc_t img_kuhlschrank;
extern const lv_img_dsc_t img_night;
extern const lv_img_dsc_t img_oven;
extern const lv_img_dsc_t img_phone;
extern const lv_img_dsc_t img_radio;
extern const lv_img_dsc_t img_solar_panel;
extern const lv_img_dsc_t img_television;
extern const lv_img_dsc_t img_vacuum;
extern const lv_img_dsc_t img_xbox;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[10];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/