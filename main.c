/*
 * main.c
 *
 *  Created on: Aug 9, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <util/delay.h>
#include "H7SEG_interface.h"
#include "MDIO_interface.h"
#include "MTIMER_interface.h"
#include "MGIE_interface.h"

volatile u8 sec = 0;
u8 min = 0;
u8 hrs = 0;
u16 counter = 0;
int main (){

	u8 sec1 	= sec%10;
	u8 sec2 	= sec/10 ;
	u8 min1 	= min%10;
	u8 min2 	= min/10;
	u8 hrs1 	= hrs%10;
	u8 hrs2 	= hrs/10;
	u16 locslC	= 0;
	u8 digit	= 1;
	MTIMER0_voidInit();
	MGIE_voidEnable();
//	MTIMER0_voidSetPreload(192);
	Port_voidInit();

	while (1){
		sec1 	= sec%10;
		sec2 	= sec/10 ;
		min1 	= min%10;
		min2 	= min/10;
		hrs1 	= hrs%10;
		hrs2 	= hrs/10;

		if (counter - locslC >= 4 ){
			if (digit == 1){
				MDIO_ErrorS_TogPinValue(DIO_PORTD,DIO_PIN0);
				void_SegWrite(hrs1, DIO_PORTC);
				MDIO_ErrorS_TogPinValue(DIO_PORTD,DIO_PIN1);
				void_SegWrite(sec2, DIO_PORTA);
				MDIO_ErrorS_TogPinValue(DIO_PORTD,DIO_PIN2);
				void_SegWrite(min1, DIO_PORTB);
				digit = 2;
			}
			else if (digit == 2) {
				MDIO_ErrorS_TogPinValue(DIO_PORTD,DIO_PIN0);
				void_SegWrite(hrs2, DIO_PORTC);
				MDIO_ErrorS_TogPinValue(DIO_PORTD,DIO_PIN1);
				void_SegWrite(sec1, DIO_PORTA);
				MDIO_ErrorS_TogPinValue(DIO_PORTD,DIO_PIN2);
				void_SegWrite(min2, DIO_PORTB);
				digit = 1;
			}
			else {

			}
			locslC = counter;
		}
		else {

		}

	}
}

void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	void_SegClear(DIO_PORTA);
	void_SegClear(DIO_PORTB);
	void_SegClear(DIO_PORTC);
	counter++;

	if (counter == 4000)
	{
		sec++;
		counter = 0;
		if (sec == 60)
		{
			sec = 0;
			min++;
		}

		if (min == 60)
		{
			min = 0;
			hrs++;
		}
	}


}
