/* encoder */
#if defined(ENCODER_ENABLE)
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    // stop processing after this - avoids default volume behaviours from running simultaneously
    return false;
};

#endif // defined(ENCODER_ENABLE)
/* end encoder */
