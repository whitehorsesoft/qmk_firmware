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
        LGUI(KC_UP), KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y, /**/ KC_F, KC_G, KC_C, KC_R, KC_L, KC_NO,
        // row 2
        KC_CAPS_LOCK, KC_A, ALT_T(KC_O), CTL_T(KC_E), SFT_T(KC_U), LT(4, KC_I), /**/ LT(4, KC_D), SFT_T(KC_H), CTL_T(KC_T), ALT_T(KC_N), KC_S, KC_NO,
        // row 3
LGUI(KC_DOWN), KC_GRAVE, LT(3, KC_Q), LT(2, KC_J), LT(1, KC_K), KC_X, /**/ KC_B, KC_M, KC_W, KC_V, KC_Z, KC_NO,
        // row 4 & some of thumb
        KC_LGUI, QK_BOOT, LGUI(KC_TAB), KC_ESC, KC_ENT, KC_TAB, LCTL(KC_A), /**/ LCTL(KC_BSPC), KC_BSPC, KC_SPC, KC_ESC, KC_NO, QK_BOOT, RGB_TOG,
        // remainder of thumb
        LCTL(KC_C), LCTL(LSFT(KC_C)), LGUI(KC_TAB), /**/ KC_DEL, LCTL(LSFT(KC_V)), LCTL(KC_V)),

    // nav
    [1] = LAYOUT_manuform(
        // row 1
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_HOME, KC_UP, KC_END, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 2
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 3
        KC_TRANSPARENT, KC_TRANSPARENT, KC_LSFT, KC_LCTL, KC_NO, KC_TRANSPARENT, /**/ LSFT(KC_5), KC_B, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 4 & some of thumb
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        // remainder of thumb
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

    // numpad
    [2] = LAYOUT_manuform(
        // row 1
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_7, KC_8, KC_9, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 2
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_4, KC_5, KC_6, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 3
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_1, KC_2, KC_3, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 4 & some of thumb
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_0, KC_DOT, KC_TRANSPARENT, KC_TRANSPARENT,
        // remainder of thumb
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

    // f-keys
    [3] = LAYOUT_manuform(
        // row 1
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_F7, KC_F8, KC_F9, KC_F12, KC_TRANSPARENT,
        // row 2
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRANSPARENT,
        // row 3
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_F1, KC_F2, KC_F3, KC_F10, KC_TRANSPARENT,
        // row 4 & some of thumb
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        // remainder of thumb
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT),

    // sym
    [4] = LAYOUT_manuform(
        // row 1
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_LBRC), LSFT(KC_RBRC), KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 2
        KC_TRANSPARENT, KC_LBRC, KC_RBRC, LSFT(KC_9), LSFT(KC_0), KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
        // row 3
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_COMMA), LSFT(KC_DOT), KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
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
                tap_code16(KC_ESC); // Send on tap
            }
            else if (record->event.pressed) {
                tap_code16(KC_F); // send on hold
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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        // can't do this, because need to set the color back when done
//        rgb_matrix_sethsv_noeeprom(0, 250, 128);

        HSV red_hsv = {0, 255, 128}; // ref color.h
        RGB red_subdued_rgb = hsv_to_rgb(red_hsv);

        rgb_matrix_set_color_all(
                red_subdued_rgb.r,
                red_subdued_rgb.g,
                red_subdued_rgb.b
                );
//                rgb_matrix_set_color(0, RGB_RED);
//                rgb_matrix_set_color(1, RGB_GREEN);
//        rgb_matrix_set_color(2, RGB_BLUE);
    }

    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }
            }
        }
    }

    return false;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
    // this sets the base color
    rgb_matrix_sethsv_noeeprom(40, 100, 60);
//    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
//    rgb_matrix_sethsv_noeeprom(HSV_GOLD);
}
