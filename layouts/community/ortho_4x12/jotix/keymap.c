#include QMK_KEYBOARD_H

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUMPAD,
  _ADJUST,
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NUMPAD TG(_NUMPAD)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12 (
// ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    KC_ESC, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_BSPC,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    KC_TAB, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_ENT,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    KC_LCTL,KC_LGUI,KC_LALT,KC_RALT,LOWER,  KC_SPC, KC_SPC, RAISE,  KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT
// └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

[_LOWER] = LAYOUT_ortho_4x12 (
// ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   _______,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,KC_VOLD,KC_MUTE,KC_VOLU,KC_F13, KC_F14, KC_F15, KC_PSCR,KC_SCRL,KC_PAUS,_______,_______,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,KC_MPRV,KC_MPLY,KC_MNXT,KC_F16, KC_F17, KC_F18, KC_INS, _______,_______,_______,_______,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
// └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

[_RAISE] = LAYOUT_ortho_4x12 (
// ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    KC_TILD,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    KC_CAPS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_MINS,KC_EQL, KC_LBRC,KC_RBRC,KC_BSLS,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,_______,_______,KC_APP, ADJUST, _______,NUMPAD, _______,KC_HOME,KC_PGDN,KC_PGUP,KC_END
// └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

[_NUMPAD] = LAYOUT_ortho_4x12 (
// ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    NUMPAD, KC_BTN1,KC_MS_U,KC_BTN2,KC_WH_U,_______,_______,KC_P7,  KC_P8,  KC_P9,  KC_PMNS,_______,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,KC_MS_L,KC_MS_D,KC_MS_R,KC_WH_D,_______,_______,KC_P4,  KC_P5,  KC_P6,  KC_PPLS,_______,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,_______,_______,_______,_______,_______,KC_NUM, KC_P1,  KC_P2,  KC_P3,  KC_PSLS,KC_PENT,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,_______,_______,_______,_______,_______,_______,_______,KC_P0,  KC_PDOT,KC_PAST,_______
// └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),

[_ADJUST] = LAYOUT_ortho_4x12 (
// ┌───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┬───────┐
    _______,QK_BOOT,_______,_______,QK_RBT, _______,_______,_______,_______,_______,_______,_______,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,_______,_______,_______,_______,_______,_______,QK_MAKE,_______,_______,_______,_______,
// ├───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┼───────┤
    _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______
// └───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┴───────┘
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  #ifdef JOTANCK_LEDS
  writePin(JOTANCK_LED2, (IS_LAYER_ON_STATE(state, _NUMPAD)));
  #endif
  return state;
}

bool led_update_user(led_t led_state) {
  // NumLock allways on
  if (!led_state.num_lock) {
    tap_code(KC_NUM_LOCK);
  }
  #ifdef JOTANCK_LEDS
  writePin(JOTANCK_LED1, led_state.caps_lock);
  #endif
  return true;
}
