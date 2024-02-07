/* RGB matrix */
#ifdef RGB_MATRIX_ENABLE
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"
#include "enums.h"

#    define min(a, b)               \
        ({                          \
            __typeof__(a) _a = (a); \
            __typeof__(b) _b = (b); \
            _a < _b ? _a : _b;      \
        })

void set_indicator_underglow_layer(uint8_t hue, uint8_t sat, uint8_t val) {
    HSV hsv = {.h = hue, .s = sat, .v = min(RGB_MATRIX_MAXIMUM_BRIGHTNESS, val)};
    RGB rgb = hsv_to_rgb(hsv);
    // for the indicator, we actually want to fix the value to e.g. 50 for reduced brightness of "naked" LED
    HSV hsv_indicator = {.h = hue, .s = sat, .v = RGB_MATRIX_MAXIMUM_BRIGHTNESS_INDICATOR};
    RGB rgb_indicator = hsv_to_rgb(hsv_indicator);

    // first 7 LEDs are 1xindicator + 6xunderglow
    // also add 36 to ensure we modify appropriately on nonmaster side
    rgb_matrix_set_color(0, rgb_indicator.r, rgb_indicator.g, rgb_indicator.b);
    rgb_matrix_set_color(36, rgb_indicator.r, rgb_indicator.g, rgb_indicator.b);
    for (uint8_t i = 1; i < 7; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        rgb_matrix_set_color(36 + i, rgb.r, rgb.g, rgb.b);
    };
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _MIRYOKU_BASE:
            set_indicator_underglow_layer(HSV_TEAL);
            break;
        case _LOWER:
        case _MIRYOKU_NAV:
            set_indicator_underglow_layer(HSV_WHITE);
            break;
        case _UPPER:
        case _MIRYOKU_SYM:
            set_indicator_underglow_layer(HSV_PURPLE);
            break;
        case _ADJUST:
        case _MIRYOKU_NUM:
            set_indicator_underglow_layer(HSV_GOLD);
            break;
        default:
            set_indicator_underglow_layer(HSV_GREEN);
    }
    return true;
};

// not quite sure why i need to give this function a nudge - but this allows RGBMatrix
// to _actually_ do its bootstrapping on init
void keyboard_post_init_user(void) {
    eeconfig_update_rgb_matrix_default();
};

#endif
/* END RGB matrix*/
