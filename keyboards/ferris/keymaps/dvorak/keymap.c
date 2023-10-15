#include QMK_KEYBOARD_H

// Tap Dance declarations - ref
enum {
    TD_ESC,
    TD_HOME,
    TD_END,
    TD_ZERO,
    SS_GG = SAFE_RANGE,
    SS_00
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case SS_GG:
            if (record->event.pressed) {
                SEND_STRING("gg");
            } else {
                // when released
            }
            return true;
            break;
        case SS_00:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_0) SS_TAP(X_0));
            } else {
                // when released
            }
            return true;
            break;
        case TD(TD_ESC):
        case TD(TD_HOME):
        case TD(TD_END):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
            break;
        case TD(TD_ZERO):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            return true;
            break;
        default:
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
    // h on tap, esc on hold
    [TD_ESC] = ACTION_TAP_DANCE_TAP_HOLD(SFT_T(KC_H), KC_ESC),
    // home on tap, ctrl+home on hold
    [TD_HOME] = ACTION_TAP_DANCE_TAP_HOLD(KC_HOME, C(KC_HOME)),
    // end on tap, ctrl+end on hold
    [TD_END] = ACTION_TAP_DANCE_TAP_HOLD(KC_END, C(KC_END)),
    // 0 on tap, 00 on hold
    [TD_ZERO] = ACTION_TAP_DANCE_TAP_HOLD(KC_0, SS_00),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base
	[0] = LAYOUT_split_3x5_2(
        KC_QUOTE, KC_COMMA, KC_DOT, KC_P, KC_Y,
            KC_F, KC_G, KC_C, KC_R, KC_L,

        KC_A, ALT_T(KC_O), CTL_T(KC_E), SFT_T(KC_U), KC_I,
            KC_D, TD(TD_ESC), CTL_T(KC_T), ALT_T(KC_N), KC_S,

        KC_SEMICOLON, KC_Q, LT(2,KC_J), LT(1,KC_K), KC_X,
            KC_B, KC_M, KC_W, KC_V, KC_Z,

        KC_ENTER , KC_TAB,
            KC_BACKSPACE , KC_SPACE
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
            KC_DOT, TD(TD_ZERO)
        )
};