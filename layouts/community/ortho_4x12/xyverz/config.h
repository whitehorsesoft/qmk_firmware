#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#define MIDI_BASIC

#define EE_HANDS

#undef RGBLED_NUM
#if defined(KEYBOARD_planck_rev5)
  #define RGBLED_NUM 10
  #define WS2812_DI_PIN D1
#elif defined(KEYBOARD_keebio_levinson_rev2)
  #define RGBLED_NUM 12
#elif defined(KEYBOARD_lets_split_rev2)
  #define RGBLED_NUM 8
#elif defined(KEYBOARD_jj40)
  #define RGBLED_NUM 5
#else
  #define RGBLED_NUM 1
#endif

#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8

#undef BACKLIGHT_LEVELS
#define BACKLIGHT_LEVELS 8

#endif
