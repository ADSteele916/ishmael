/*
 * ishmael.c
 *
 *  Created on: Jan. 18, 2022
 *      Author: Alex Steele
 */

#include <msp430.h>

#include "ishmael.h"



void toggle_strobe() {
    P1OUT ^= 1;
}

void double_toggle_strobe() {
    __delay_cycles (DOUBLE_TOGGLE_CYCLE_DELAY);
    toggle_strobe();
    __delay_cycles (DOUBLE_TOGGLE_CYCLE_DELAY);
    toggle_strobe();
    __delay_cycles (DOUBLE_TOGGLE_CYCLE_DELAY);
}

void set_strobe(unsigned char state) {
    unsigned char out = P1OUT;
    out &= 0b11111110;
    out |= state;
    P1OUT = out;
}


void set_index(unsigned char idx) {
    unsigned char out = P1OUT;
    out &= 0b11111001;
    out |= (idx << 1);
    P1OUT = out;
}

void set_digit(unsigned char dig) {
    unsigned char out = P1OUT;
    out &= 0b00001111;
    out |= (dig << 4);
    P1OUT = out;
}

void set_digit_at_index(unsigned char dig, unsigned char idx) {
    set_index(idx);
    set_digit(dig);
    double_toggle_strobe();
}

void set_display_from_nums(unsigned char digits[4]) {
    int i;
    for (i = 0; i < 4; i++) {
        set_digit_at_index(digits[i], 3 - i);
    }
}

void set_display_from_str(char digits[4]) {
    unsigned int i;
    unsigned char display_bytes[4];

    for (i = 0; i < 4; i++) {
        if ((48 <= digits[i]) && (digits[i] <= 57)) {
            display_bytes[i] = digits[i] - 48;
        } else if ((65 <= digits[i]) && (digits[i] <= 70)) {
            display_bytes[i] = digits[i] - 55;
        } else if ((97 <= digits[i]) && (digits[i] <= 102)) {
            display_bytes[i] = digits[i] - 87;
        } else {
            return;
        }
    }

    for (i = 4; i > 0; i--) {
        set_digit_at_index(display_bytes[4 - i], i - 1);
    }
}
