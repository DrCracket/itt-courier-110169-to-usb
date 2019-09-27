#include "keymap_common.h"

bool use_solenoid = false;

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: default */
    KEYMAP(
    STOP,NO,    GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSPC,  HOME,END,   F1,  F2,  F3,  \
    PAUS,NO,    TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,ESC,   INS, DEL,   F4,  F5,  F6,  \
    SLCK,NO,    CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,NUHS,ENT,   UP,  DOWN,  F7,  F8,  F9,  \
    PSCR,FN0,   LSFT,NUBS,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,RSFT,       LEFT,RGHT,    F10, F11, F12, \
    LCTL,LGUI,  LALT,                    SPC,                          RALT,RCTL,       PGUP,PGDN
    ),
};

const action_t PROGMEM fn_actions[] = {
    [0] = ACTION_FUNCTION(0),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (record->event.pressed) {
        use_solenoid = !use_solenoid;
    }
}

void hook_late_init(void)
{
    // initialize solenoid
    DDRF |= (1<<6);
    PORTF |= (1<<6);
}

void hook_matrix_change(keyevent_t event)
{
    // only use solenoid for key press events, not key release events.
    if (use_solenoid && event.pressed)
    {
        PORTF &= ~(1<<6); 
        _delay_ms(SOLENOID_DELAY);
        PORTF |= (1<<6);
    }
}
