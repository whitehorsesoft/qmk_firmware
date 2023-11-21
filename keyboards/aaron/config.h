// Copyright 2023 aaron (@aaron)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
/* Split keyboard settings */
#define SERIAL_USART_TX_PIN GP28
#define SPLIT_HAND_PIN GP0

/* RGB settings */
#ifdef RGB_MATRIX_ENABLE
#    define WS2812_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral
#    define SPLIT_TRANSPORT_MIRROR
//#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
//#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_REACTIVE // Sets the default mode, if none has been set
//#    define RGB_MATRIX_DEFAULT_HUE 240 // Sets the default hue value, if none has been set
//#    define RGB_MATRIX_DEFAULT_SAT 128 // Sets the default saturation value, if none has been set
//#    define RGB_MATRIX_DEFAULT_SPD 50
//#    define RGB_MATRIX_DEFAULT_VAL 128
//#    define RGB_DISABLE_WHEN_USB_SUSPENDED
//#    define RGB_MATRIX_KEYPRESSES
//#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#endif

/* Double-tap reset button parameters */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

#define USB_VBUS_PIN GP27
