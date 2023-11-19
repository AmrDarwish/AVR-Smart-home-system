/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "util/delay.h"
#include "MSPI_interface.h"
#include "smart_home.h"
extern u8 temprature;
u8 spiRecivedData = NO_DATA;
u8 flag			  = 0 ;

int main (){
	initUsedPrefralsBeforeSPI();

	while (spiRecivedData!= SLAVE_START);

	initUsedPrefralsAfterSPI();

	while(1){

		if ( spiRecivedData > 2 && spiRecivedData < 150){
			temprature = spiRecivedData%100;

		}

		else if (spiRecivedData == FAN_ON_TEMP){
			turnOnFan();
		}
		else if (spiRecivedData == FAN_ON_BLUETOOTH){
			turnOnFan();
		}
		else if (spiRecivedData == FAN_OFF_TEMP){
			turnOffFan();
		}
		else if (spiRecivedData == FAN_OFF_BLUETOOTH){
			turnOnFan();
		}

		else if (spiRecivedData == DOOR_ON_BLUETOOTH){
			open_Home_Door();
			spiRecivedData = NO_DATA;
		}
		else if (spiRecivedData == DOOR_OFF_BLUETOOTH){
			close_Home_Door();
			spiRecivedData = NO_DATA;
		}

		else if (spiRecivedData == GHARASH_ON_BLUETOOTH){
			openGaragDoor();
			spiRecivedData = NO_DATA;
		}
		else if (spiRecivedData == GHARASH_OFF_BLUETOOTH){
			closeGaragDoor();
			spiRecivedData = NO_DATA;
		}

		else if (spiRecivedData == LIGHT_ON_LUX){
			on_All_LEDS();
			spiRecivedData = NO_DATA;
		}
		else if (spiRecivedData == LIGHT_OFF_LUX){
			off_All_LEDS();
			spiRecivedData = NO_DATA;
		}
		else if (spiRecivedData == LIGHT_ON_BLUETOOTH){
			on_All_LEDS();
			spiRecivedData = NO_DATA;
		}
		else if (spiRecivedData == LIGHT_OFF_BLUETOOTH){
			off_All_LEDS();
			spiRecivedData = NO_DATA;
		}
		else {

		}

	}

}
