/*
 * HLED_interface.h
 *
 *  Created on: Aug 13, 2023
 *      Author: Amr-a
 */
#ifndef HLED_INTERFACE_H_
#define HLED_INTERFACE_H_
/*copy_u8LEDnum:
			 * LED_PORTA_P1
			 * ...
			 * LED_PORTB_P1
			 * ...
			 * LED_PORTC_P1
			 * ...
			 * LED_PORTD_P1
			 * ...
			 *
 * */
Error_State_t HLED_ErrorState_LEDOn(u8 copy_u8LED_num);

Error_State_t HLED_ErrorState_LEDOff(u8 copy_u8LED_num);

#define HLED_PORTA_P0	1
#define HLED_PORTA_P1	2
#define HLED_PORTA_P2	3
#define HLED_PORTA_P3	4
#define HLED_PORTA_P4	5
#define HLED_PORTA_P5	6
#define HLED_PORTA_P6	7
#define HLED_PORTA_P7	8

#define HLED_PORTB_P0	9
#define HLED_PORTB_P1	10
#define HLED_PORTB_P2	11
#define HLED_PORTB_P3	12
#define HLED_PORTB_P4	13
#define HLED_PORTB_P5	14
#define HLED_PORTB_P6	15
#define HLED_PORTB_P7	16

#define HLED_PORTC_P0	17
#define HLED_PORTC_P1	18
#define HLED_PORTC_P2	19
#define HLED_PORTC_P3	20
#define HLED_PORTC_P4	21
#define HLED_PORTC_P5	22
#define HLED_PORTC_P6	23
#define HLED_PORTC_P7	24

#define HLED_PORTD_P0	25
#define HLED_PORTD_P1	26
#define HLED_PORTD_P2	27
#define HLED_PORTD_P3	28
#define HLED_PORTD_P4	29
#define HLED_PORTD_P5	30
#define HLED_PORTD_P6	31
#define HLED_PORTD_P7	32

#endif /* HLED_INTERFACE_H_ */
