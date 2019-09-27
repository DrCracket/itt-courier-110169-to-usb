#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"


#define KEYMAP( \
    KA5, K06,   K05, K04, K03, K02, K01, K00, K17, K16, K15, K14, K13, K12, K11, K10,   K97, K96,   KC7, KC6, KC5, \
    K27, K26,   K25, K24, K23, K22, K21, K20, K37, K36, K35, K34, K33, K32, K31, K30,   K95, K94,   KC4, KC3, KC2, \
    K47, K46,   K45, K44, K43, K42, K41, K40, K57, K56, K55, K54, K53, K52, K51, K50,   K93, K92,   KC1, KC0, KE7, \
    K67, K66,   K65, K64, K63, K62, K61, K60, K77, K76, K75, K74, K73, K72, K71,        K91, K90,   KE6, KE5, KE4, \
    K87, K86,   K85,                     K83,                          K82, K80,        KA7, KA6                   \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_NO    }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17 }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27 }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37 }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47 }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53, KC_##K54, KC_##K55, KC_##K56, KC_##K57 }, \
    { KC_##K60, KC_##K61, KC_##K62, KC_##K63, KC_##K64, KC_##K65, KC_##K66, KC_##K67 }, \
    { KC_NO,    KC_##K71, KC_##K72, KC_##K73, KC_##K74, KC_##K75, KC_##K76, KC_##K77 }, \
    { KC_##K80, KC_NO,    KC_##K82, KC_##K83, KC_NO,    KC_##K85, KC_##K86, KC_##K87 }, \
    { KC_##K90, KC_##K91, KC_##K92, KC_##K93, KC_##K94, KC_##K95, KC_##K96, KC_##K97 }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_##KA5, KC_##KA6, KC_##KA7 }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
    { KC_##KC0, KC_##KC1, KC_##KC2, KC_##KC3, KC_##KC4, KC_##KC5, KC_##KC6, KC_##KC7 }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_##KE4, KC_##KE5, KC_##KE6, KC_##KE7 }, \
}
#endif
