/* OLED START */
#ifdef OLED_ENABLE
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"
#include "enums.h"

static void print_status_narrow(void) {
    oled_set_cursor(0, 0);
    oled_write("M4J0R", false);

    oled_set_cursor(0, 2);

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write("QWRTY", false);
            break;
        case _MIRYOKU_BASE:
            oled_write("MRYKU", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0, 4);

    /* Print current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0, 5);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
        case _MIRYOKU_BASE:
            oled_write("Base ", false);
            break;
        case _UPPER:
            oled_write("Upper", false);
            break;
        case _LOWER:
            oled_write("Lower", false);
            break;
        case _ADJUST:
            oled_write("Adjst", false);
            break;
        case _MIRYOKU_NAV:
            oled_write("MKNav", false);
            break;
        case _MIRYOKU_SYM:
            oled_write("MKSym", false);
            break;
        case _MIRYOKU_NUM:
            oled_write("MKNum", false);
            break;
        case _MIRYOKU_MOUSE:
            oled_write("MKMse", false);
            break;
        case _MIRYOKU_MEDIA:
            oled_write("MKMda", false);
            break;
        case _MIRYOKU_FUN:
            oled_write("MKFun", false);
            break;
        default:
            oled_write("Undef", false);
    }

    oled_set_cursor(0, 7);
    /* wpm counter */
    oled_write(get_u8_str(get_current_wpm(), ' '), false);
    oled_set_cursor(0, 8);
    oled_write(" wpm", false);

    /* KEYBOARD XOMT RENDER START */
    # ifdef ADOPT_XOMT
    render_xomt(0, 10);
    # endif 
    /* KEYBOARD XOMT RENDER ENDER */

    /* KEYBOARD PET RENDER START */
    # ifdef ADOPT_LUNA 
    render_luna(0, 13);
    # endif 
    /* KEYBOARD PET RENDER END */

}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    /* KEYBOARD PET VARIABLES START */
    # ifdef ADOPT_LUNA 
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();
    /* KEYBOARD PET VARIABLES END */
    # endif 

    print_status_narrow();
    return false;
}

#endif
/* OLED END */

