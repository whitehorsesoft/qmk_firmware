// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    // first keycode should always be set to SAFE_RANGE (ref https://docs.qmk.fm/#/custom_quantum_functions?id=defining-a-new-keycode)
    SS_GG = SAFE_RANGE,
    SS_00,
    SS_APPEND_SEMI,
    SS_RDARW,
    SS_LDARW,
    SS_RSARW,
    SS_APPEND,
};

struct prev_keypress_struct {
    uint16_t keycode;
    uint16_t pressed_time;
};

struct possibility {
    uint16_t main_keycode;
    uint16_t hold_keycode;
};

struct possibility possibilities[] = {
        { .main_keycode = KC_COMMA, .hold_keycode = S(KC_SLASH) },
        { .main_keycode = KC_DOT, .hold_keycode = KC_SEMICOLON },
        { .main_keycode = KC_P, .hold_keycode = S(KC_QUOTE) },
        { .main_keycode = KC_F, .hold_keycode = KC_ESC },
        { .main_keycode = KC_Y, .hold_keycode = KC_ESC },
        { .main_keycode = KC_A, .hold_keycode = KC_CAPS },
        { .main_keycode = KC_0, .hold_keycode = SS_00 },
        { .main_keycode = KC_G, .hold_keycode = KC_EQUAL },
        { .main_keycode = KC_C, .hold_keycode = KC_MINUS },
        { .main_keycode = KC_R, .hold_keycode = KC_BACKSLASH },
        { .main_keycode = KC_S, .hold_keycode = S(KC_2) },
        { .main_keycode = KC_M, .hold_keycode = KC_SLASH },
        { .main_keycode = KC_W, .hold_keycode = S(KC_SEMICOLON) },
        { .main_keycode = KC_V, .hold_keycode = S(KC_GRAVE) },
};

struct prev_keypress_struct prev_keypress;

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
        KC_TRANSPARENT, KC_LBRC, KC_RBRC, LSFT(KC_9), LSFT(KC_0), SS_APPEND_SEMI, /**/ KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_2), KC_TRANSPARENT,
        // row 3
        KC_TRANSPARENT, SS_LDARW, SS_RDARW, LSFT(KC_COMMA), LSFT(KC_DOT), KC_TRANSPARENT, /**/ KC_TRANSPARENT, KC_SLASH, LSFT(KC_SEMICOLON), LSFT(KC_GRAVE), KC_TRANSPARENT, KC_TRANSPARENT,
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

uint16_t process_keypress(uint16_t keycode) {
    if (get_mods() == MOD_MASK_SHIFT) {
        keycode = S(keycode);
    }

    if (get_mods() == MOD_MASK_ALT) {
        keycode = A(keycode);
    }

    if (get_mods() == MOD_MASK_CTRL) {
        keycode = C(keycode);
    }

    return keycode;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool matched_possibility = false;
    // check possibilities
    for (int i = 0; i < 14; i++) {
        if (possibilities[i].main_keycode == keycode) {
            if (record->event.pressed) {
                // pressed
                prev_keypress.keycode = keycode;
                prev_keypress.pressed_time = record->event.time;
                return false;
            } else {
                // released
                uint16_t now_time = record->event.time;
                if ((now_time - prev_keypress.pressed_time) < 300) {
                    keycode = process_keypress(possibilities[i].main_keycode);
                } else {
                    keycode = process_keypress(possibilities[i].hold_keycode);
                }

                matched_possibility = true;
            }
        }
    }

    switch (keycode) {
        case SS_GG:
            if (record->event.pressed) {
                SEND_STRING("gg");
            }
            return false;
            break;
        case SS_00:
            if (!record->event.pressed) {
                SEND_STRING("00");
            }
            return false;
            break;
        case SS_APPEND_SEMI:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_TAP(X_ESC) "A;" SS_TAP(X_ESC), 100);
            }
            return true;
            break;
        case SS_RDARW:
            if (record->event.pressed) {
                SEND_STRING_DELAY("=>", 100);
            }
            return true;
            break;
        case SS_LDARW:
            if (record->event.pressed) {
                SEND_STRING_DELAY("<=", 100);
            }
            return true;
            break;
        case SS_RSARW:
            if (record->event.pressed) {
                SEND_STRING_DELAY("->", 100);
            }
            return true;
            break;
        case SS_APPEND:
            if (record->event.pressed) {
                SEND_STRING_DELAY(SS_TAP(X_ESC) "A", 100);
            }
            return true;
            break;
            // tap dance hold
//        case TD(TD_HOME):
//        case TD(TD_END):
//            action = &tap_dance_actions[TD_INDEX(keycode)];
//            if (!record->event.pressed && action->state.count && !action->state.finished) {
//                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
//                tap_code16(tap_hold->tap);
//            }
//
//            break;
        default:
            if (matched_possibility) {
                tap_code16(keycode);
                return false;
            }

            break;
    }

    return true;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        // can't do this, because need to set the color back when done
//        rgb_matrix_sethsv_noeeprom(0, 250, 128);

        HSV red_hsv = {0, 255, 63}; // ref color.h
        RGB red_subdued_rgb = hsv_to_rgb(red_hsv);

        rgb_matrix_set_color_all(
                red_subdued_rgb.r,
                red_subdued_rgb.g,
                red_subdued_rgb.b
                );

//                rgb_matrix_set_color(0, RGB_RED);
//                rgb_matrix_set_color(1, RGB_GREEN);
//        rgb_matrix_set_color(2, RGB_BLUE);

//        rgb_matrix_mode_noeeprom(RGB_MATRIX_CYCLE_OUT_IN);
    }
//    else {
//        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_REACTIVE);
        // this sets the base color
//        rgb_matrix_sethsv_noeeprom(40, 100, 60);
//    }

    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        int hue = 360 / 5 * layer;
        HSV layer_hue = {hue, 255, 128};
        RGB layer_rgb = hsv_to_rgb(layer_hue);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED) {
                    if (keymap_key_to_keycode(layer, (keypos_t) {col, row}) > KC_TRNS) {
                        rgb_matrix_set_color(index, layer_rgb.r, layer_rgb.b, layer_rgb.g);
                    } else {
                        rgb_matrix_set_color(index, RGB_BLACK);
                    }
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
