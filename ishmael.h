/*
 * ishmael.h
 *
 *  Created on: Jan. 18, 2022
 *      Author: Alex Steele
 */

#ifndef ISHMAEL_H_
#define ISHMAEL_H_

#define DOUBLE_TOGGLE_CYCLE_DELAY 10000

void toggle_strobe();

void double_toggle_strobe();

void set_strobe(unsigned char state);

void set_index(unsigned char idx);

void set_digit(unsigned char dig);

void set_digit_at_index(unsigned char dig, unsigned char idx);

void set_display_from_nums(unsigned char digits[4]);

void set_display_from_str(char digits[4]);

#endif /* ISHMAEL_H_ */
