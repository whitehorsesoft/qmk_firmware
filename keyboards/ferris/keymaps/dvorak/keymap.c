#include QMK_KEYBOARD_H

struct prev_keypress_struct {
    uint16_t keycode;
    uint16_t pressed_time;
};

struct prev_keypress_struct prev_keypress;

// Tap Dance declarations - ref
enum tapdances {
    TD_HOME,
    TD_END
};

enum custom_keycodes {
    // first keycode should always be set to SAFE_RANGE (ref https://docs.qmk.fm/#/custom_quantum_functions?id=defining-a-new-keycode)
    SS_GG = SAFE_RANGE,
    SS_00,
    SS_APPEND_SEMI
};

struct possibility {
    uint16_t main_keycode;
    uint16_t hold_keycode;
};

struct possibility possibilities[] = {
    { .main_keycode = KC_QUOTE, .hold_keycode = TG(4) },
    { .main_keycode = KC_COMMA, .hold_keycode = S(KC_SLASH) },
    { .main_keycode = KC_DOT, .hold_keycode = KC_SEMICOLON },
    { .main_keycode = KC_P, .hold_keycode = S(KC_QUOTE) },
    { .main_keycode = KC_A, .hold_keycode = KC_CAPS },
    { .main_keycode = KC_0, .hold_keycode = SS_00 },
    { .main_keycode = KC_I, .hold_keycode = KC_ESC },
    { .main_keycode = KC_D, .hold_keycode = KC_ESC },
    { .main_keycode = KC_G, .hold_keycode = KC_EQUAL },
    { .main_keycode = KC_C, .hold_keycode = KC_MINUS },
    { .main_keycode = KC_R, .hold_keycode = KC_BACKSLASH },
    { .main_keycode = KC_S, .hold_keycode = S(KC_2) },
    { .main_keycode = KC_GRAVE, .hold_keycode = KC_LGUI },
    { .main_keycode = KC_M, .hold_keycode = KC_SLASH },
    { .main_keycode = KC_W, .hold_keycode = S(KC_SEMICOLON) },
    { .main_keycode = KC_V, .hold_keycode = S(KC_GRAVE) },
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

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
    for (int i = 0; i < 16; i++) {
        if (possibilities[i].main_keycode == keycode) {
            if (record->event.pressed) {
                // pressed
                prev_keypress.keycode = keycode;
                prev_keypress.pressed_time = record->event.time;
                return false;
            } else {
                // released
                uint16_t now_time = record->event.time;
                if ((now_time - prev_keypress.pressed_time) < 200) {
                    keycode = process_keypress(possibilities[i].main_keycode);
                } else {
                    keycode = process_keypress(possibilities[i].hold_keycode);
                }

                matched_possibility = true;
            }
        }
    }

    tap_dance_action_t *action;

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
                SEND_STRING_DELAY("A;", 100);
            }
            return true;
            break;
        // tap dance hold
        case TD(TD_HOME):
        case TD(TD_END):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }

            break;
        default:
            if (matched_possibility) {
                tap_code16(keycode);
                return false;
            }

            break;
    }

    return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    // home on tap, ctrl+home on hold
    [TD_HOME] = ACTION_TAP_DANCE_TAP_HOLD(KC_HOME, C(KC_HOME)),
    // end on tap, ctrl+end on hold
    [TD_END] = ACTION_TAP_DANCE_TAP_HOLD(KC_END, C(KC_END))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base
	[0] = LAYOUT_split_3x5_2(
        KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y,
            KC_F, KC_G, KC_C, KC_R, KC_L,

        KC_A, ALT_T(KC_O), CTL_T(KC_E), SFT_T(KC_U), KC_I,
            KC_D, SFT_T(KC_H), CTL_T(KC_T), ALT_T(KC_N), KC_S,

        KC_GRAVE, KC_Q, LT(2,KC_J), LT(1,KC_K), KC_X,
            LT(3, KC_B), KC_M, KC_W, KC_V, KC_Z,

        KC_TAB, KC_ENTER ,
        KC_SPACE , KC_BACKSPACE
        ),
    // nav
	[1] = LAYOUT_split_3x5_2(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
            KC_TRANSPARENT , TD(TD_HOME), KC_UP, TD(TD_END), KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
            S(KC_I), KC_LEFT, KC_DOWN, KC_RIGHT, S(KC_A),

        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
            S(KC_5), KC_B, KC_W, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT,
            KC_TRANSPARENT, KC_TRANSPARENT
        ),
    // num
	[2] = LAYOUT_split_3x5_2(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
            KC_TRANSPARENT, KC_7, KC_8, KC_9, KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
            SS_GG, KC_4, KC_5, KC_6, KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
            KC_TRANSPARENT, KC_1, KC_2, KC_3, KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT,
            KC_DOT, KC_0
        ),
    // sym
    [3] = LAYOUT_split_3x5_2(
        KC_TRANSPARENT, KC_TRANSPARENT, S(KC_9), S(KC_0), KC_TRANSPARENT,
            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_LEFT_BRACKET, KC_RIGHT_BRACKET, S(KC_LEFT_BRACKET), S(KC_RIGHT_BRACKET), SS_APPEND_SEMI,
            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, S(KC_COMMA), S(KC_DOT), KC_TRANSPARENT,
            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT,
            KC_TRANSPARENT, KC_TRANSPARENT
        ),
    // clipboard
    [4] = LAYOUT_split_3x5_2(
        KC_TRANSPARENT, C(KC_A), C(KC_C), C(KC_V), KC_TRANSPARENT,
            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, C(S(KC_C)), C(S(KC_V)), KC_TRANSPARENT,
            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
            KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

        KC_TRANSPARENT, KC_TRANSPARENT,
            KC_TRANSPARENT, KC_TRANSPARENT
        )
};