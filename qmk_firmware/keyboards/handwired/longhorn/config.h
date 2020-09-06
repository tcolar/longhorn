
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
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// wiring of each half
#define MATRIX_ROW_PINS \
    { B6, B2, B3, B1, F7 }
    
#define MATRIX_COL_PINS \
    { B4, B5, E6, D7, C6, D4 }

/*#define MATRIX_ROW_PINS_RIGHT \
    { B6, B2, B3, B1, F7 }

#define MATRIX_COL_PINS_RIGHT \
    { D4, C6, D7, E6, B5, B4 }*/


/* serial.c configuration for split keyboard */
#define SOFT_SERIAL_PIN D0
#define SELECT_SOFT_SERIAL_SPEED 1

// #define SPLIT_HAND_PIN F4

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

// Without this Hold/Tap keys are flaky
#define IGNORE_MOD_TAP_INTERRUPT
