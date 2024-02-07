#include QMK_KEYBOARD_H
#include <stdio.h>
#include "quantum.h"
#include "enums.h" 

/* layers */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |MRYOKU|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                                KC_6,     KC_7,    KC_8,    KC_9,     KC_0,   DF(_MIRYOKU_BASE),
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,       KC_BSPC,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN,     KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,           KC_NO,      KC_N,     KC_M,   KC_COMM, KC_DOT,   KC_SLSH,     KC_RSFT,
                  KC_LGUI,  KC_LALT, KC_LCTL,   MO(_LOWER), KC_SPC,      KC_ENT,  MO(_UPPER),   KC_RCTL, KC_RALT, KC_RGUI
),


[_UPPER] = LAYOUT(
  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11, 
  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_F12, 
  _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_PIPE, 
  _______,  KC_EQL,   KC_MINS,  KC_PLUS,  KC_LCBR,  KC_RCBR, _______,        _______,   KC_LBRC,  KC_RBRC,  KC_SCLN,  KC_COLN,  KC_NUHS,  _______, 
                      _______,  _______,  _______,   _______, _______,      _______,  _______,      _______, _______, _______
),

[_LOWER] = LAYOUT(
  _______,  _______,     _______,     _______,    _______,    _______,                             _______,    _______,      _______,     _______,      _______,     _______, 
  _______,  KC_INS,      KC_PSCR,     KC_APP,      KC_NO,     KC_NO,                               KC_PGUP,  LCTL(KC_LEFT),  KC_UP,    LCTL(KC_RGHT), LCTL(KC_BSPC), KC_BSPC, 
  _______,  KC_NO,       KC_LALT,     KC_LCTL,    KC_LSFT,    KC_CAPS,                             KC_PGDN,    KC_LEFT,      KC_DOWN,     KC_RGHT,      KC_DEL,      KC_BSPC, 
  _______,  LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V),   KC_NO,    _______,         _______,  KC_NO,      KC_HOME,      KC_NO,       KC_END,        KC_NO,      _______, 
                         _______,     _______,    _______,     _______,  _______,       _______,  _______,     _______,      _______,     _______
),

[_ADJUST] = LAYOUT(
  KC_NO,    KC_NO,  KC_NO,    KC_NO, KC_NO,  KC_NO,                      KC_NO, KC_NO,   KC_NO,    KC_NO,  KC_NO, KC_NO, 
  QK_BOOT,  KC_NO,  DF(4),   CG_TOGG,KC_NO,  KC_NO,                      KC_NO, KC_NO,   KC_NO,    KC_NO,  KC_NO, KC_NO,
  KC_NO,    KC_NO,  CG_TOGG,  KC_NO, KC_NO,  KC_NO,                      KC_NO, KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO, 
  KC_NO,    KC_NO,  KC_NO,    KC_NO, KC_NO,  KC_NO,  KC_NO,      KC_NO,  KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, 
                _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),

/*
 * MIRYOKU_BASE/ColemakDH - customised to make use of all available keys (for better or worse?)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |QWERTY|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `¬  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |  '"  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  \|  | g(A) | a(R) | c(S) | s(T) |   G  |-------.    ,-------|   M  | s(N) | c(E) | a(I) | g(O) |  #~  |
 * |------+------+------+------+------+------|  PLAY |    |  PLAY |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |  ,<  |  .>  |  /?  |  ;:  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | Esc  |Space | /  Tab  /       \Enter \  | Bspc | Del  | RAlt | RGUI |
 *            |      |      |MEDIA | NAV  |/ MOUSE /         \ SYM  \ |  NUM | FUN  |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_MIRYOKU_BASE] = LAYOUT(
  KC_ESC,       KC_1,         KC_2,         KC_3,         KC_4,     KC_5,                                                         KC_6,     KC_7,       KC_8,           KC_9,        KC_0,    DF(_QWERTY), 
  KC_GRV,       KC_Q,         KC_W,         KC_F,         KC_P,     KC_B,                                                         KC_J,     KC_L,       KC_U,           KC_Y,       KC_QUOT,    KC_BSPC, 
  KC_NUBS,  LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G,                                                         KC_M, LSFT_T(KC_N), LCTL_T(KC_E), LALT_T(KC_I), RGUI_T(KC_O), KC_NUHS, 
  KC_LSFT,      KC_Z,         KC_X,         KC_C,         KC_D,     KC_V,   KC_MPLY,                                    KC_MPLY,  KC_K,     KC_H,      KC_COMM,        KC_DOT,     KC_SLSH,    KC_SCLN, 
                            KC_LGUI,      KC_LALT,    LT(8, KC_ESC), LT(6, KC_SPC), LT(9, KC_TAB),      LT(10, KC_ENT), LT(5, KC_BSPC), LT(7, KC_DEL), KC_RALT,        KC_RGUI
),

/* 
*  NB: ALL OTHER _MIRYOKU_* LAYERS SHOULD BE 1:1 with https://github.com/manna-harbour/miryoku/tree/master/docs/reference
*  EXCEPT FOR PRESERVING LAYER TOGGLE 
*  AND MISSING SOME BLUETOOTH/EXT POWER ONES AND REDO
*  ALSO DID NOT IMPLEMENT EXTRAS (ADDITIONAL FEATURES, BUTTON LAYER)
*/

[_MIRYOKU_NAV] = LAYOUT(
  _______, _______, _______, _______, _______,  _______,                            _______, _______, _______, _______, _______,  DF(0),
  _______, _______, _______, _______, _______,  _______,                            _______, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  _______,                            KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,
  _______, _______, _______, _______, _______,  _______, _______,         _______,  KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                    _______, _______, _______,   _______, _______,       KC_ENTER, KC_BSPC,  KC_DEL, _______, _______
),

[_MIRYOKU_MOUSE] = LAYOUT(
  _______, _______, _______, _______, _______,  _______,                             _______, _______, _______, _______, _______,  DF(0),
  _______, _______, _______, _______, _______,  _______,                             _______, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO, _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  _______,                             _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  _______, _______, _______, _______, _______,  _______, _______,          _______,  _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
                    _______, _______, _______,   _______, _______,        KC_BTN2, KC_BTN1,   KC_BTN3, _______, _______
),

[_MIRYOKU_MEDIA] = LAYOUT(
  _______, _______, _______, _______, _______,  _______,                            _______, _______, _______, _______, _______,  DF(0),
  _______, _______, _______, _______, _______,  _______,                            RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,
  _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT,  _______,                            _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, _______, _______, _______, _______,  _______, _______,         _______,  _______, _______, _______, _______, _______, _______,
                    _______, _______, _______,   _______, _______,       KC_MSTP, KC_MPLY,   KC_MUTE, _______, _______
),

[_MIRYOKU_SYM] = LAYOUT(
  _______, _______, _______, _______, _______,  _______,                          _______, _______, _______, _______, _______,  DF(0),
  _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RCBR,                          _______, _______, _______, _______, _______, _______,
  _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC,  KC_PLUS,                          _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
  _______, KC_TILD, KC_EXLM,  KC_AT,  KC_HASH,  KC_PIPE, _______,       _______,  _______, _______, _______, _______, _______, _______,
                    _______, _______, KC_LPRN,   KC_RPRN, KC_UNDS,     _______, _______,   _______, _______, _______
),

[_MIRYOKU_NUM] = LAYOUT(
  _______, _______, _______, _______, _______,  _______,                              _______, _______, _______, _______, _______,  DF(0),
  _______, KC_LBRC,   KC_7,    KC_8,    KC_9,   KC_RBRC,                              _______,   KC_7,    KC_8,    KC_9,  _______, _______,
  _______, KC_SCLN,   KC_4,    KC_5,    KC_6,   KC_EQL,                               _______,   KC_4,    KC_5,    KC_6,  KC_LGUI, _______,
  _______, KC_GRV,    KC_1,    KC_2,    KC_3,   KC_NUBS, _______,           _______,  _______,   KC_1,    KC_2,    KC_3,  _______, _______,
                     KC_DOT,   KC_0,  KC_MINS,   _______, _______,         _______, _______,   _______,   KC_0,   _______
),


[_MIRYOKU_FUN] = LAYOUT(
  _______, _______, _______, _______, _______,  _______,                        EE_CLR, _______, _______, _______, _______,  DF(0),
  _______,  KC_F12,   KC_F7,   KC_F8,   KC_F9,  KC_PSCR,                        _______, _______, _______, _______, _______, _______,
  _______,  KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_SCRL,                        _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,
  _______,  KC_F10,   KC_F1,   KC_F2,   KC_F3,  KC_PAUS, _______,     _______,  _______, _______, _______, _______, _______, _______,
                    _______, _______, _______,   KC_SPC,   KC_TAB,   _______, _______,   _______, _______, _______
),

[_TRANSPARENT] = LAYOUT(
  _______, _______, _______, _______, _______,  _______,                            _______, _______, _______, _______, _______,  DF(0),
  _______, _______, _______, _______, _______,  _______,                            _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,  _______,                            _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,  _______, _______,         _______,  _______, _______, _______, _______, _______, _______,
                    _______, _______, _______,   _______, _______,       _______, _______,   _______, _______, _______
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _UPPER, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* KEYBOARD PET STATUS START */
        # ifdef ADOPT_LUNA
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                isSneaking = true;
            } else {
                isSneaking = false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
                isJumping  = true;
                showedJump = false;
            } else {
                isJumping = false;
            }
            break;
        # endif 
        /* KEYBOARD PET STATUS END */
    }
    return true;
}

/* end layers */
