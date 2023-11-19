/*
 * smart_home.c

 *
 *  Created on: Aug 25, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "util/delay.h"
#include "MDIO_interface.h"
#include "MGIE_interface.h"
#include "MTIMER_interface.h"
#include "MSPI_interface.h"

#include "HLED_interface.h"
#include "HStpper_interface.h"
#include "HServo_interface.h"
#include "H7SEG_interface.h"

#include "smart_home.h"
#include "comonFunctions.h"

extern u8 spiRecivedData;
u8 temprature 		= 63;
u8 counter 			= 0;

void displaySeg1Num(){
	H7SEG_voidWrite((temprature%10),DIO_PORTC);
	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_LOW);
		MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
}
void displaySeg2Num(){
	H7SEG_voidWrite((temprature/10),DIO_PORTC);
	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN2,DIO_LOW);
}

void ISR_TIMER0(void){
	counter ++;

	if (counter == 50){

			displaySeg1Num();
		}
	else if (counter == 100){
			counter = 0;
			displaySeg2Num();
		}
}

void ISR_SPI(void){
	spiRecivedData = MSPI_u8GetSPDR();
}

void initUsedPrefralsBeforeSPI(){
	Port_voidInit();

	MGIE_voidEnable();
	MSPI_voidInit();
	setCallBackSPI(ISR_SPI);
}

void initUsedPrefralsAfterSPI(){

	MTIMER0_voidInit();
	setCallBackTimer0(ISR_TIMER0);

	MTIMER1_voidInit(FAST_PWM_NON_INVERTING,TOP_FPWM_ICR1,DIV_8);
	MTIMER1_voidSetTopValue(20000,TOP_FPWM_ICR1);
}
void open_Home_Door(){
	HServo_voidSetAngle(180);

}
void close_Home_Door(){
	HServo_voidSetAngle(0);

}


void on_All_LEDS(){
	HLED_ErrorState_LEDOn(HLED_PORTA_P0);
	HLED_ErrorState_LEDOn(HLED_PORTA_P1);
	HLED_ErrorState_LEDOn(HLED_PORTA_P2);
	HLED_ErrorState_LEDOn(HLED_PORTA_P3);
	HLED_ErrorState_LEDOn(HLED_PORTA_P4);
	HLED_ErrorState_LEDOn(HLED_PORTA_P5);
	HLED_ErrorState_LEDOn(HLED_PORTA_P6);
	HLED_ErrorState_LEDOn(HLED_PORTA_P7);
}

void off_All_LEDS(){
	HLED_ErrorState_LEDOff(HLED_PORTA_P0);
	HLED_ErrorState_LEDOff(HLED_PORTA_P1);
	HLED_ErrorState_LEDOff(HLED_PORTA_P2);
	HLED_ErrorState_LEDOff(HLED_PORTA_P3);
	HLED_ErrorState_LEDOff(HLED_PORTA_P4);
	HLED_ErrorState_LEDOff(HLED_PORTA_P5);
	HLED_ErrorState_LEDOff(HLED_PORTA_P6);
	HLED_ErrorState_LEDOff(HLED_PORTA_P7);
}


void openGaragDoor(){
	Hstepper_rotate_CW(270);
	Hstepper_Stop();
}
void closeGaragDoor(){
	Hstepper_rotate_ACW(270);
	Hstepper_Stop();
}

void turnOnFan(){
	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN0,DIO_HIGH);
}

void turnOffFan(){
	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN0,DIO_LOW);
}





