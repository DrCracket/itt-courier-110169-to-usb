#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"


/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void select_row(uint8_t row);


void matrix_init(void)
{
    // initialize row, col
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
        _delay_us(30);  // without this wait read unstable value.
        matrix[i] = read_cols();
    }

    return 1;
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

static void  init_cols(void)
{
    DDRC &= 0b10111111;
    DDRD &= 0b11110000;
    DDRB &= 0b01110011;
}

static matrix_row_t read_cols(void)
{
    return (PINC & (1<<6) ? 0 : (1<<0)) |
           (PIND & (1<<3) ? 0 : (1<<1)) |
           (PIND & (1<<2) ? 0 : (1<<2)) |
           (PIND & (1<<1) ? 0 : (1<<3)) |
           (PIND & (1<<0) ? 0 : (1<<4)) |
           (PINB & (1<<7) ? 0 : (1<<5)) |
           (PINB & (1<<3) ? 0 : (1<<6)) |
           (PINB & (1<<2) ? 0 : (1<<7));
}

static void select_row(uint8_t row)
{
    // Output in binary as input to demultiplexer to select
    DDRD |= 0b11000000;
    DDRB |= 0b00110000;
    if (row == 11 || row == 13) return;
    if (row & (1<<0)) PORTD |= (1<<6); else PORTD &= ~(1<<6);
    if (row & (1<<1)) PORTD |= (1<<7); else PORTD &= ~(1<<7);
    if (row & (1<<2)) PORTB |= (1<<4); else PORTB &= ~(1<<4);
    if (row & (1<<3)) PORTB |= (1<<5); else PORTB &= ~(1<<5);
}

void led_set(uint8_t usb_led)
{
    // keyboard doesn't have leds
}
