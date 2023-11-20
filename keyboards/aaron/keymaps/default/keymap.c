// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    CKC_Y_ESC = SAFE_RANGE,
    CKC_F_ESC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base
    [0] = LAYOUT_manuform(
        // row 1
        KC_NO, KC_QUOTE, KC_COMMA, KC_DOT, KC_P, CKC_Y_ESC, /**/ CKC_F_ESC, KC_G, KC_C, KC_R, KC_L, KC_NO,
        // row 2
        KC_CAPS_LOCK, KC_A, ALT_T(KC_O), CTL_T(KC_E), SFT_T(KC_U), LT(4, KC_I), /**/ LT(4, KC_D), SFT_T(KC_H), CTL_T(KC_T), ALT_T(KC_N), KC_S, KC_NO,
        // row 3
        KC_NO, KC_GRAVE, LT(3, KC_Q), LT(2, KC_J), LT(1, KC_K), KC_X, /**/ KC_B, KC_M, KC_W, KC_V, KC_Z, KC_NO,
        // row 4 & some of thumb
        LGUI(KC_DOWN), LGUI(KC_UP), LGUI(KC_TAB), KC_LGUI, KC_ENT, KC_TAB, LCTL(KC_A), /**/ LCTL(KC_BSPC), KC_BSPC, KC_SPC, KC_NO, KC_NO, KC_NO, RGB_TOG,
        // remainder of thumb
        LCTL(KC_C), LCS(KC_C), KC_NO, /**/ KC_DEL, LCS(KC_V), LCTL(KC_V)),

    // nav
    [1] = LAYOUT_manuform(
        // row 1
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_HOME, KC_UP, KC_END, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 2
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 3
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ LSFT(KC_5), KC_B, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 4 & some of thumb
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        // remainder of thumb
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT)

//    // template
//    [0] = LAYOUT_manuform(
//        // row 1
//        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//        // row 2
//        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//        // row 3
//        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//        // row 4 & some of thumb
//        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
//        // remainder of thumb
//        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CKC_F_ESC:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_F); // Send on tap
            }
            else if (record->event.pressed) {
                tap_code16(KC_ESC); // send on hold
            }
            return false;        // Return false to ignore further processing of key
        case CKC_Y_ESC:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_Y); // Send on tap
            }
            else if (record->event.pressed) {
                tap_code16(KC_ESC); // send on hold
            }
            return false;        // Return false to ignore further processing of key
    }
    return true;
}
