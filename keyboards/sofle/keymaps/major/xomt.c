/* KEYBOARD XOMT START */
#ifdef ADOPT_XOMT 
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"

void render_xomt(int XOMT_X, int XOMT_Y) {
    static const char PROGMEM xomt[] = {
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    };

    oled_set_cursor(XOMT_X, XOMT_Y);
    oled_write_raw_P(xomt, 8);
}
# endif 
/* KEYBOARD XOMT END */