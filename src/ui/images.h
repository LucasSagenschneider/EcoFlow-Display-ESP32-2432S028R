#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_fernseh;
extern const lv_img_dsc_t img_handy;
extern const lv_img_dsc_t img_joystick;
extern const lv_img_dsc_t img_kaffeemaschine;
extern const lv_img_dsc_t img_kuhlschrank;
extern const lv_img_dsc_t img_mikrowelle;
extern const lv_img_dsc_t img_mond;
extern const lv_img_dsc_t img_radio;
extern const lv_img_dsc_t img_staubsauger;
extern const lv_img_dsc_t img_solar;
extern const lv_img_dsc_t img_frame_00_delay_0_08s;
extern const lv_img_dsc_t img_frame_01_delay_0_04s;
extern const lv_img_dsc_t img_frame_02_delay_0_04s;
extern const lv_img_dsc_t img_frame_03_delay_0_04s;
extern const lv_img_dsc_t img_frame_04_delay_0_04s;
extern const lv_img_dsc_t img_frame_05_delay_0_04s;
extern const lv_img_dsc_t img_frame_06_delay_0_04s;
extern const lv_img_dsc_t img_frame_07_delay_0_04s;
extern const lv_img_dsc_t img_frame_08_delay_0_04s;
extern const lv_img_dsc_t img_frame_09_delay_0_04s;
extern const lv_img_dsc_t img_frame_10_delay_0_04s;
extern const lv_img_dsc_t img_frame_11_delay_0_04s;
extern const lv_img_dsc_t img_frame_12_delay_0_04s;
extern const lv_img_dsc_t img_frame_13_delay_0_04s;
extern const lv_img_dsc_t img_frame_14_delay_0_04s;
extern const lv_img_dsc_t img_frame_15_delay_0_04s;
extern const lv_img_dsc_t img_frame_16_delay_0_04s;
extern const lv_img_dsc_t img_frame_17_delay_0_04s;
extern const lv_img_dsc_t img_frame_18_delay_0_04s;
extern const lv_img_dsc_t img_frame_19_delay_0_04s;
extern const lv_img_dsc_t img_frame_20_delay_0_04s;
extern const lv_img_dsc_t img_frame_21_delay_0_04s;
extern const lv_img_dsc_t img_frame_22_delay_0_04s;
extern const lv_img_dsc_t img_frame_23_delay_0_04s;
extern const lv_img_dsc_t img_frame_24_delay_0_04s;
extern const lv_img_dsc_t img_frame_25_delay_0_04s;
extern const lv_img_dsc_t img_frame_26_delay_0_04s;
extern const lv_img_dsc_t img_frame_27_delay_0_04s;
extern const lv_img_dsc_t img_frame_28_delay_0_04s;
extern const lv_img_dsc_t img_frame_29_delay_0_04s;
extern const lv_img_dsc_t img_frame_30_delay_0_04s;
extern const lv_img_dsc_t img_frame_31_delay_0_04s;
extern const lv_img_dsc_t img_frame_32_delay_0_04s;
extern const lv_img_dsc_t img_frame_33_delay_0_04s;
extern const lv_img_dsc_t img_frame_34_delay_0_04s;
extern const lv_img_dsc_t img_frame_35_delay_0_04s;
extern const lv_img_dsc_t img_frame_36_delay_0_04s;
extern const lv_img_dsc_t img_frame_37_delay_0_04s;
extern const lv_img_dsc_t img_frame_38_delay_0_44s;
extern const lv_img_dsc_t img_frame_39_delay_0_04s;
extern const lv_img_dsc_t img_frame_40_delay_0_04s;
extern const lv_img_dsc_t img_frame_41_delay_0_04s;
extern const lv_img_dsc_t img_frame_42_delay_0_04s;
extern const lv_img_dsc_t img_frame_43_delay_0_04s;
extern const lv_img_dsc_t img_frame_44_delay_0_04s;
extern const lv_img_dsc_t img_frame_45_delay_0_04s;
extern const lv_img_dsc_t img_frame_46_delay_0_04s;
extern const lv_img_dsc_t img_frame_47_delay_0_04s;
extern const lv_img_dsc_t img_frame_48_delay_0_04s;
extern const lv_img_dsc_t img_frame_49_delay_0_04s;
extern const lv_img_dsc_t img_frame_50_delay_0_04s;
extern const lv_img_dsc_t img_frame_51_delay_0_04s;
extern const lv_img_dsc_t img_frame_52_delay_0_04s;
extern const lv_img_dsc_t img_frame_53_delay_0_04s;
extern const lv_img_dsc_t img_frame_54_delay_0_04s;
extern const lv_img_dsc_t img_frame_55_delay_0_04s;
extern const lv_img_dsc_t img_frame_56_delay_0_04s;
extern const lv_img_dsc_t img_frame_57_delay_0_04s;
extern const lv_img_dsc_t img_frame_58_delay_0_04s;
extern const lv_img_dsc_t img_frame_59_delay_0_08s;
extern const lv_img_dsc_t img_frame_60_delay_0_12s;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[71];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/