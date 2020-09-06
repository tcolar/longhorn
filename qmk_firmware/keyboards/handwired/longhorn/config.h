
#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0x2B10
#define PRODUCT_ID 0x2256
#define DEVICE_VER 0x0100
#define MANUFACTURER tcolar
#define PRODUCT Longhorn
#define DESCRIPTION Split keyboard 6*4 + thumbs


/* key matrix size */
// This is kinda confusing, I think it should be called MATRIX_ROWS_LENGTH
// We have 5 cols on each hand, so row length is 10
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// Wiring of each half
// See pro-micro pinout: https://golem.hu/article/pro-micro-pinout/
#define MATRIX_ROW_PINS \
    { B6, B2, B3, B1, F7 }
    
#define MATRIX_COL_PINS \
    { B4, B5, E6, D7, C6, D4 }

// we use serail communication on pin D0 betwen the 2 halves (via TRRS cable)
#define SOFT_SERIAL_PIN D0
#define SELECT_SOFT_SERIAL_SPEED 1

// Does not seem to have effect ...
#define SPLIT_HAND_PIN F4

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

// Without this Hold/Tap keys are flaky for me (rollovers)
#define IGNORE_MOD_TAP_INTERRUPT
