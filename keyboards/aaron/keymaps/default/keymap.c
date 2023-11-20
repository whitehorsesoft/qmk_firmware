// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_manuform(
        KC_NO, KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y,                                KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_NO,
        KC_CAPS_LOCK, KC_A,   ALT_T(KC_O),  CTL_T(KC_E),  SFT_T(KC_U),   LT(4, KC_I),                                LT(4, KC_D), SFT_T(KC_H), CTL_T(KC_T), ALT_T(KC_N), KC_S, KC_NO,
        KC_NO, KC_GRAVE,    LT(3, KC_Q),  LT(2, KC_J), LT(1, KC_K), KC_X                                KC_B,    KC_M,    KC_W, KC_V,  KC_Z, KC_NO,
        LGUI(KC_DOWN), LGUI(KC_UP), LGUI(KC_TAB), KC_LGUI, KC_ENT, KC_TAB, LCTL(KC_A),           LCTL(KC_BSPC),  KC_BSPC,  KC_SPC, KC_NO,  KC_NO, KC_NO, RGB_TOG,
        LCTL(KC_C),    LCS(KC_C), KC_NO, KC_DEL, LCS(KC_V),  LCTL(KC_V)
        )
//[0] = LAYOUT_manuform(
//    KC_NO, KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y,                                KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_NO,
//    KC_CAPS_LOCK, KC_A,   KC_O,  KC_E,  KC_U,   KC_I,                                KC_D, KC_H, KC_T, KC_N, KC_S, KC_NO,
//    KC_NO, KC_GRAVE,    KC_Q,  KC_J, KC_K, KC_X,                                KC_B,    KC_M,    KC_W, KC_V,  KC_Z, KC_NO,
//        KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G,                                KC_H, KC_I, KC_J, KC_K, KC_L, KC_M, KC_N,
//        KC_O, KC_P, KC_Q,                                                        KC_R, KC_S, KC_T
//)
};
