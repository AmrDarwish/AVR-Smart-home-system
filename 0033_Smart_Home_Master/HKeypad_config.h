/*
 * HKeypad_config.h
 *
 *  Created on: Aug 5, 2023
 *      Author: Amr-a
 */

#ifndef _HKEY_CONFIG_H
#define _HKEY_CONFIG_H

#define KEYPAD_ROW_PORT		DIO_PORTC
#define KEYPAD_R0			DIO_PIN5
#define KEYPAD_R1			DIO_PIN4
#define KEYPAD_R2			DIO_PIN3
#define KEYPAD_R3			DIO_PIN2

#define KEYPAD_COL_PORT		DIO_PORTD
#define KEYPAD_C0			DIO_PIN4
#define KEYPAD_C1			DIO_PIN5
#define KEYPAD_C2			DIO_PIN6
#define KEYPAD_C3			DIO_PIN7

#define COL_SIZE			4
#define ROW_SIZE			4


#define KEYPAD_TYPE	 {{'#','0','=','+'},\
					  {'1','2','3','-'},\
					  {'4','5','6','*'},\
					  {'7','8','9','/'}}


#endif
