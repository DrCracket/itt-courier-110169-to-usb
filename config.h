#ifndef CONFIG_H
#define CONFIG_H


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    ITT
#define PRODUCT         Courier 110169
#define DESCRIPTION     t.m.k. keyboard firmware for ITT Courier 110169

/* key matrix size */
#define MATRIX_ROWS 15
#define MATRIX_COLS 8

/* Solenoid related stuff */
#define SOLENOID_DELAY 10

/* key combination for command */
#define IS_COMMAND()    ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)


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
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
