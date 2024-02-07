/* RGB lighting */
// forks rgb_default, using corrected LED addresses for 1 (ind) + 6 (und) + 29(per) = 36 lights per side
#ifdef RGBLIGHT_ENABLE
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"
#include "enums.h"


#    define INDICATOR_BRIGHTNESS 30

#    define HSV_OVERRIDE_HELP(h, s, v, Override) h, s, Override
#    define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv, Override)

#    define SET_INDICATORS(hsv)                                     \
        {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, {     \
            36 + 0, 6, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS) \
        }

#    define SET_UNDERGLOW(hsv) \
        {1, 6, hsv}, {         \
            36 + 1, 6, hsv     \
        }

#    define SET_NUMROW(hsv)                                                               \
        {12, 1, hsv}, {21, 2, hsv}, {31, 2, hsv}, {36 + 12, 1, hsv}, {36 + 21, 2, hsv}, { \
            36 + 31, 2, hsv                                                               \
        }

#    define SET_THUMBCLUSTER(hsv)                                                       \
        {7, 1, hsv}, {16, 2, hsv}, {26, 2, hsv}, {36 + 7, 1, hsv}, {36 + 16, 2, hsv}, { \
            36 + 26, 2, hsv                                                             \
        }

#    define SET_LAYER_ID(hsv)                                                                                                           \
        {0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, {36 + 0, 6, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, {1, 6, hsv}, { \
            36 + 1, 6, hsv                                                                                                              \
        }

// build our "layer" array
char layer_state_str[72];

// qwerty = teal
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_TEAL));

// colemakdh = pink
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_PINK));

// upper = purple
const rgblight_segment_t PROGMEM layer_upper_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_PURPLE));

// lower = white
const rgblight_segment_t PROGMEM layer_lower_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_WHITE));

// adj = orange
const rgblight_segment_t PROGMEM layer_adjust_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_ORANGE));

// miryoku-fun  =
const rgblight_segment_t PROGMEM layer_mkfun_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_RED));

// miryoku-sym  =
const rgblight_segment_t PROGMEM layer_mksym_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_ORANGE));

// miryoku-num  =
const rgblight_segment_t PROGMEM layer_mknum_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_YELLOW));

// miryoku-nav  =
const rgblight_segment_t PROGMEM layer_mknav_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_GREEN));

// miryoku-mda  =
const rgblight_segment_t PROGMEM layer_mkmda_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_BLUE));

// miryoku-mse  =
const rgblight_segment_t PROGMEM layer_mkmse_lights[] = RGBLIGHT_LAYER_SEGMENTS(SET_LAYER_ID(HSV_VIOLET));

// configure layers
const rgblight_segment_t *const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(layer_qwerty_lights, layer_colemakdh_lights, layer_upper_lights, layer_lower_lights, layer_adjust_lights, layer_mkfun_lights, layer_mksym_lights, layer_mknum_lights, layer_mknav_lights, layer_mkmda_lights, layer_mkmse_lights, );

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
    rgblight_set_layer_state(1, layer_state_cmp(state, _MIRYOKU_BASE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _UPPER));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
    rgblight_set_layer_state(5, layer_state_cmp(state, _MIRYOKU_FUN));
    rgblight_set_layer_state(6, layer_state_cmp(state, _MIRYOKU_SYM));
    rgblight_set_layer_state(7, layer_state_cmp(state, _MIRYOKU_NUM));
    rgblight_set_layer_state(8, layer_state_cmp(state, _MIRYOKU_NAV));
    rgblight_set_layer_state(9, layer_state_cmp(state, _MIRYOKU_MDA));
    rgblight_set_layer_state(10, layer_state_cmp(state, _MIRYOKU_MSE));
    return update_tri_layer_state(state, _LOWER, _UPPER, _ADJUST);
};

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

    rgblight_mode(10);
};

#endif

