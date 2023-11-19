/*
 * HStpper_program.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Amr-a
 */
#include <util/delay.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"
#include "HStpper_config.h"
#include "HStpper_interface.h"
#include "HStpper_private.h"
void Hstepper_rotate_CW (u16 deg){

	deg *= 10;
	deg /= 7 ;

	u16 i = 0;
	for (;i < deg;i++){

		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_BLUE_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_PINK_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_YELLOW_PIN, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_ORANGE_PIN, DIO_HIGH);
		_delay_ms(2);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_BLUE_PIN 	, DIO_HIGH);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_PINK_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_YELLOW_PIN, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_ORANGE_PIN, DIO_LOW);
		_delay_ms(2);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_BLUE_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_PINK_PIN 	, DIO_HIGH);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_YELLOW_PIN, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_ORANGE_PIN, DIO_LOW);
		_delay_ms(2);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_BLUE_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_PINK_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_YELLOW_PIN, DIO_HIGH);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_ORANGE_PIN, DIO_LOW);
		_delay_ms(2);
	}

}

void Hstepper_rotate_ACW (u16 deg){
	deg *= 10;
	deg /= 7 ;
	u16 i = 0;
	for (;i < deg;i++){

		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_BLUE_PIN 	, DIO_HIGH);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_PINK_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_YELLOW_PIN, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_ORANGE_PIN, DIO_LOW);
		_delay_ms(2);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_BLUE_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_PINK_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_YELLOW_PIN, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_ORANGE_PIN, DIO_HIGH);
		_delay_ms(2);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_BLUE_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_PINK_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_YELLOW_PIN, DIO_HIGH);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_ORANGE_PIN, DIO_LOW);
		_delay_ms(2);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_BLUE_PIN 	, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_PINK_PIN 	, DIO_HIGH);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_YELLOW_PIN, DIO_LOW);
		MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_ORANGE_PIN, DIO_LOW);
		_delay_ms(2);
	}

}


void Hstepper_Stop (){

	MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_BLUE_PIN 	, DIO_LOW);
	MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_PINK_PIN 	, DIO_LOW);
	MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_YELLOW_PIN, DIO_LOW);
	MDIO_ErrorS_SetPinValue(HSTPPER_Port, HSTPPER_ORANGE_PIN, DIO_LOW);
}
