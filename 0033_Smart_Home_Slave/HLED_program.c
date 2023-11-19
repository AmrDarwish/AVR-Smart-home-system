/*
 * HLED_program.c
 *
 *  Created on: Aug 13, 2023
 *      Author: Amr-a
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MDIO_interface.h"
#include "HLED_interface.h"
#include "HLED_private.h"
#include "HLED_config.h"

Error_State_t HLED_ErrorState_LEDOn(u8 copy_u8LED_num){
	Error_State_t errorState = return_Ok;
	switch(copy_u8LED_num){
	case HLED_PORTA_P0 :	MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN0, (LED_PORTA_P0_ACTIVE - 1) );	break;
	case HLED_PORTA_P1 :	MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN1, (LED_PORTA_P1_ACTIVE - 1) );	break;
	case HLED_PORTA_P2 :	MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN2, (LED_PORTA_P2_ACTIVE - 1) );	break;
	case HLED_PORTA_P3 :	MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN3, (LED_PORTA_P3_ACTIVE - 1) );	break;
	case HLED_PORTA_P4 :	MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN4, (LED_PORTA_P4_ACTIVE - 1) );	break;
	case HLED_PORTA_P5 :	MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN5, (LED_PORTA_P5_ACTIVE - 1) );	break;
	case HLED_PORTA_P6 :	MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN6, (LED_PORTA_P6_ACTIVE - 1) );	break;
	case HLED_PORTA_P7 :	MDIO_ErrorS_SetPinValue(DIO_PORTA,DIO_PIN7, (LED_PORTA_P7_ACTIVE - 1) );	break;

	case HLED_PORTB_P0 :	MDIO_ErrorS_SetPinValue(DIO_PORTB,DIO_PIN0, (LED_PORTB_P0_ACTIVE - 1) );	break;
	case HLED_PORTB_P1 :	MDIO_ErrorS_SetPinValue(DIO_PORTB,DIO_PIN1, (LED_PORTB_P1_ACTIVE - 1) );	break;
	case HLED_PORTB_P2 :	MDIO_ErrorS_SetPinValue(DIO_PORTB,DIO_PIN2, (LED_PORTB_P2_ACTIVE - 1) );	break;
	case HLED_PORTB_P3 :	MDIO_ErrorS_SetPinValue(DIO_PORTB,DIO_PIN3, (LED_PORTB_P3_ACTIVE - 1) );	break;
	case HLED_PORTB_P4 :	MDIO_ErrorS_SetPinValue(DIO_PORTB,DIO_PIN4, (LED_PORTB_P4_ACTIVE - 1) );	break;
	case HLED_PORTB_P5 :	MDIO_ErrorS_SetPinValue(DIO_PORTB,DIO_PIN5, (LED_PORTB_P5_ACTIVE - 1) );	break;
	case HLED_PORTB_P6 :	MDIO_ErrorS_SetPinValue(DIO_PORTB,DIO_PIN6, (LED_PORTB_P6_ACTIVE - 1) );	break;
	case HLED_PORTB_P7 :	MDIO_ErrorS_SetPinValue(DIO_PORTB,DIO_PIN7, (LED_PORTB_P7_ACTIVE - 1) );	break;

	case HLED_PORTC_P0 :	MDIO_ErrorS_SetPinValue(DIO_PORTC,DIO_PIN0, (LED_PORTC_P0_ACTIVE - 1) );	break;
	case HLED_PORTC_P1 :	MDIO_ErrorS_SetPinValue(DIO_PORTC,DIO_PIN1, (LED_PORTC_P1_ACTIVE - 1) );	break;
	case HLED_PORTC_P2 :	MDIO_ErrorS_SetPinValue(DIO_PORTC,DIO_PIN2, (LED_PORTC_P2_ACTIVE - 1) );	break;
	case HLED_PORTC_P3 :	MDIO_ErrorS_SetPinValue(DIO_PORTC,DIO_PIN3, (LED_PORTC_P3_ACTIVE - 1) );	break;
	case HLED_PORTC_P4 :	MDIO_ErrorS_SetPinValue(DIO_PORTC,DIO_PIN4, (LED_PORTC_P4_ACTIVE - 1) );	break;
	case HLED_PORTC_P5 :	MDIO_ErrorS_SetPinValue(DIO_PORTC,DIO_PIN5, (LED_PORTC_P5_ACTIVE - 1) );	break;
	case HLED_PORTC_P6 :	MDIO_ErrorS_SetPinValue(DIO_PORTC,DIO_PIN6, (LED_PORTC_P6_ACTIVE - 1) );	break;
	case HLED_PORTC_P7 :	MDIO_ErrorS_SetPinValue(DIO_PORTC,DIO_PIN7, (LED_PORTC_P7_ACTIVE - 1) );	break;

	case HLED_PORTD_P0 :	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN0, (LED_PORTD_P0_ACTIVE - 1) );	break;
	case HLED_PORTD_P1 :	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN1, (LED_PORTD_P1_ACTIVE - 1) );	break;
	case HLED_PORTD_P2 :	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN2, (LED_PORTD_P2_ACTIVE - 1) );	break;
	case HLED_PORTD_P3 :	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN3, (LED_PORTD_P3_ACTIVE - 1) );	break;
	case HLED_PORTD_P4 :	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN4, (LED_PORTD_P4_ACTIVE - 1) );	break;
	case HLED_PORTD_P5 :	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN5, (LED_PORTD_P5_ACTIVE - 1) );	break;
	case HLED_PORTD_P6 :	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN6, (LED_PORTD_P6_ACTIVE - 1) );	break;
	case HLED_PORTD_P7 :	MDIO_ErrorS_SetPinValue(DIO_PORTD,DIO_PIN7, (LED_PORTD_P7_ACTIVE - 1) );	break;
	default			  : errorState = return_Nok;
	}
	return errorState;

}

Error_State_t HLED_ErrorState_LEDOff(u8 copy_u8LED_num){
	Error_State_t errorState = return_Ok;

	switch(copy_u8LED_num){
	case HLED_PORTA_P0 :	disable(DIO_PORTA,DIO_PIN0,LED_PORTA_P0_ACTIVE);			break;
	case HLED_PORTA_P1 :	disable(DIO_PORTA,DIO_PIN1,LED_PORTA_P1_ACTIVE);	break;
	case HLED_PORTA_P2 :	disable(DIO_PORTA,DIO_PIN2,LED_PORTA_P2_ACTIVE);	break;
	case HLED_PORTA_P3 :	disable(DIO_PORTA,DIO_PIN3,LED_PORTA_P3_ACTIVE);	break;
	case HLED_PORTA_P4 :	disable(DIO_PORTA,DIO_PIN4,LED_PORTA_P4_ACTIVE);	break;
	case HLED_PORTA_P5 :	disable(DIO_PORTA,DIO_PIN5,LED_PORTA_P5_ACTIVE);	break;
	case HLED_PORTA_P6 :	disable(DIO_PORTA,DIO_PIN6,LED_PORTA_P6_ACTIVE);	break;
	case HLED_PORTA_P7 :	disable(DIO_PORTA,DIO_PIN7,LED_PORTA_P7_ACTIVE);	break;

	case HLED_PORTB_P0 :	disable(DIO_PORTB,DIO_PIN0,LED_PORTB_P0_ACTIVE);	break;
	case HLED_PORTB_P1 :	disable(DIO_PORTB,DIO_PIN1,LED_PORTB_P1_ACTIVE);	break;
	case HLED_PORTB_P2 :	disable(DIO_PORTB,DIO_PIN2,LED_PORTB_P2_ACTIVE);	break;
	case HLED_PORTB_P3 :	disable(DIO_PORTB,DIO_PIN3,LED_PORTB_P3_ACTIVE);	break;
	case HLED_PORTB_P4 :	disable(DIO_PORTB,DIO_PIN4,LED_PORTB_P4_ACTIVE);	break;
	case HLED_PORTB_P5 :	disable(DIO_PORTB,DIO_PIN5,LED_PORTB_P5_ACTIVE);	break;
	case HLED_PORTB_P6 :	disable(DIO_PORTB,DIO_PIN6,LED_PORTB_P6_ACTIVE);	break;
	case HLED_PORTB_P7 :	disable(DIO_PORTB,DIO_PIN7,LED_PORTB_P7_ACTIVE);	break;

	case HLED_PORTC_P0 :	disable(DIO_PORTC,DIO_PIN0,LED_PORTC_P0_ACTIVE);	break;
	case HLED_PORTC_P1 :	disable(DIO_PORTC,DIO_PIN1,LED_PORTC_P1_ACTIVE);	break;
	case HLED_PORTC_P2 :	disable(DIO_PORTC,DIO_PIN2,LED_PORTC_P2_ACTIVE);	break;
	case HLED_PORTC_P3 :	disable(DIO_PORTC,DIO_PIN3,LED_PORTC_P3_ACTIVE);	break;
	case HLED_PORTC_P4 :	disable(DIO_PORTC,DIO_PIN4,LED_PORTC_P4_ACTIVE);	break;
	case HLED_PORTC_P5 :	disable(DIO_PORTC,DIO_PIN5,LED_PORTC_P5_ACTIVE);	break;
	case HLED_PORTC_P6 :	disable(DIO_PORTC,DIO_PIN6,LED_PORTC_P6_ACTIVE);	break;
	case HLED_PORTC_P7 :	disable(DIO_PORTC,DIO_PIN7,LED_PORTC_P7_ACTIVE);	break;

	case HLED_PORTD_P0 :	disable(DIO_PORTD,DIO_PIN0,LED_PORTD_P0_ACTIVE);	break;
	case HLED_PORTD_P1 :	disable(DIO_PORTD,DIO_PIN1,LED_PORTD_P1_ACTIVE);	break;
	case HLED_PORTD_P2 :	disable(DIO_PORTD,DIO_PIN2,LED_PORTD_P2_ACTIVE);	break;
	case HLED_PORTD_P3 :	disable(DIO_PORTD,DIO_PIN3,LED_PORTD_P3_ACTIVE);	break;
	case HLED_PORTD_P4 :	disable(DIO_PORTD,DIO_PIN4,LED_PORTD_P4_ACTIVE);	break;
	case HLED_PORTD_P5 :	disable(DIO_PORTD,DIO_PIN5,LED_PORTD_P5_ACTIVE);	break;
	case HLED_PORTD_P6 :	disable(DIO_PORTD,DIO_PIN6,LED_PORTD_P6_ACTIVE);	break;
	case HLED_PORTD_P7 :	disable(DIO_PORTD,DIO_PIN7,LED_PORTD_P7_ACTIVE);	break;
	default			  : errorState = return_Nok;
	}
	return errorState;

}

void disable(u8 port,u8 pin_num, u8 led_active_type){
	if(led_active_type == LED_ACTIVE_H){
		MDIO_ErrorS_SetPinValue(port,pin_num,DIO_LOW);
	}
	else if (led_active_type == LED_ACTIVE_L){
		MDIO_ErrorS_SetPinValue(port,pin_num,DIO_HIGH);
	}
}

