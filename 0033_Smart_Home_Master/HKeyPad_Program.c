/*
 * HKeyPad_Program.c
 *
 *  Created on: Aug 5, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "MDIO_interface.h"
#include "HKeyPad_interface.h"
#include "HKeyPad_private.h"
#include "HKeyPad_config.h"


// loop on columns > set all and reset one pin
// loop on all ROWs > checking pins
// if one is pressed get its value
// else set the reseted column
// return the key
//
u8 HKeyPad_u8GetKey(void){
	u8 flag = 0;
	u8 Local_u8pressedKey 	= NO_KEY;
	u8 Local_u8keyIspressed = NOT_PRESSED;
	u8 Local_u8ColIterator = 0;
	u8 Local_u8RowIterator = 0;

	u8 Col_arr[COL_SIZE] = {
				KEYPAD_C0,
				KEYPAD_C1,
				KEYPAD_C2,
				KEYPAD_C3
		};
	u8 Row_arr[ROW_SIZE] = {
				KEYPAD_R0,
				KEYPAD_R1,
				KEYPAD_R2,
				KEYPAD_R3
		};

	u8 KeyPad_arr[ROW_SIZE][COL_SIZE] = KEYPAD_TYPE;


	for (Local_u8ColIterator = 0 ; Local_u8ColIterator < COL_SIZE ; Local_u8ColIterator++){

		MDIO_ErrorS_SetPinValue(KEYPAD_COL_PORT,Col_arr[Local_u8ColIterator], DIO_LOW);
		MDIO_ErrorS_SetPinValue(KEYPAD_COL_PORT,Col_arr[Local_u8ColIterator], DIO_LOW);
		MDIO_ErrorS_SetPinValue(KEYPAD_COL_PORT,Col_arr[Local_u8ColIterator], DIO_LOW);
		MDIO_ErrorS_SetPinValue(KEYPAD_COL_PORT,Col_arr[Local_u8ColIterator], DIO_LOW);

		for (Local_u8RowIterator = 0 ; Local_u8RowIterator < ROW_SIZE ; Local_u8RowIterator++){

			MDIO_ErrorS_GetPinValue(KEYPAD_ROW_PORT , Row_arr[Local_u8RowIterator] , &Local_u8keyIspressed);

			if (!Local_u8keyIspressed){
				while(!Local_u8keyIspressed){
					MDIO_ErrorS_GetPinValue(KEYPAD_ROW_PORT , Row_arr[Local_u8RowIterator] , &Local_u8keyIspressed);
				}
				Local_u8pressedKey = KeyPad_arr[Local_u8RowIterator][Local_u8ColIterator];
				flag = 1;

				break;
			}
			else {

			}
		}

		MDIO_ErrorS_SetPinValue(KEYPAD_COL_PORT,Col_arr[Local_u8ColIterator], DIO_HIGH);
		if (flag){
			break;
		}
		else {

		}

	}
	return Local_u8pressedKey;
}
