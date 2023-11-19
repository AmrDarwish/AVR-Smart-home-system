/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "util/delay.h"
#include "HLM53_interface.h"
#include "MSPI_interface.h"
#include "MUART_interface.h"
#include "smart_home.h"
u8 bluetoothOrder		= NO_ORDER;
u8 slaveFanOrder 		= FAN_OFF_TEMP;
u8 slaveLightOrder 		= LIGHT_OFF_LUX;
u8 slaveDoorOrder		= DOOR_OFF_BLUETOOTH;
u8 slaveGarageOrder 	= GARAGE_OFF_BLUETOOTH;

u16 newLux 				= 0;
u16 currentLux 			= 0;
u8 newTemprature 		= 0;
u8 currentTemprature 	= 0;

u8 flag					= 0 ;


int main (){
	initUsedPrefrals();
	welcomeScreen();

	while(1){

		if (flag == 0){	//selection screen
			selectioScreen();
		}
		else if (flag == 1){
			//enter new user data and send to EEPROM;
			enterNewUserData();
		}
		else if(flag == 2){
			//changeUserData();
		}
		else if(flag == 3){
			// enter user data and confirm identity
			enterUserData();
		}
		else if(flag == 4){
			// you are now in the system
			//recive order from bluetooth
			while(1){
				if (IsRecivedFromBluetooth()){
					getDataFromBluetooth();
					MUART_voidTransmitString("AMr");
				}
				if (bluetoothOrder == BLUETOOTH_OPEN_FAN){
					slaveFanOrder = FAN_ON_BLUETOOTH;
					sendFanOrderToSlave();
					bluetoothOrder = NO_ORDER;
				}
				else if (bluetoothOrder == BLUETOOTH_CLOSE_FAN){
					slaveFanOrder = FAN_OFF_BLUETOOTH;
					sendFanOrderToSlave();
					bluetoothOrder = NO_ORDER;
				}
				else if (bluetoothOrder == BLUETOOTH_OPEN_DOOR){
					slaveDoorOrder = DOOR_ON_BLUETOOTH;
					sendDoorOrderToSlave();
					bluetoothOrder = NO_ORDER;
				}
				else if (bluetoothOrder == BLUETOOTH_CLOSE_DOOR){
					slaveDoorOrder = DOOR_OFF_BLUETOOTH;
					sendDoorOrderToSlave();
					bluetoothOrder = NO_ORDER;
				}

				else if (bluetoothOrder == BLUETOOTH_OPEN_GARAGE){
					slaveGarageOrder = GARAGE_ON_BLUETOOTH;
					sendGarageOrderToSlave();
					bluetoothOrder = NO_ORDER;
				}
				else if (bluetoothOrder == BLUETOOTH_CLOSE_GARAGE){
					slaveGarageOrder = GARAGE_OFF_BLUETOOTH;
					sendGarageOrderToSlave();
					bluetoothOrder = NO_ORDER;
				}
				else if (bluetoothOrder == BLUETOOTH_OPEN_LIGHT){
					slaveLightOrder = LIGHT_ON_BLUETOOTH;
					sendLightOrderToSlave();
					bluetoothOrder = NO_ORDER;
				}
				else if (bluetoothOrder == BLUETOOTH_CLOSE_LIGHT){
					slaveLightOrder = LIGHT_OFF_BLUETOOTH;
					sendLightOrderToSlave();
					bluetoothOrder = NO_ORDER;
				}

				if ((currentTemprature != newTemprature)){
					currentTemprature = newTemprature;
					displayLightAndTemp();
					sendTempToSlave();
				}

				if (currentLux != newLux){
					currentLux = newLux;
					displayLightAndTemp();
				}

				/*	handeling fan order with temp value  */
				if ((currentTemprature > 22) && (slaveFanOrder != FAN_ON_TEMP) && (slaveFanOrder != FAN_OFF_BLUETOOTH)){
					slaveFanOrder = FAN_ON_TEMP;
					sendFanOrderToSlave();
				}

				if ((currentTemprature < 19 ) && (slaveFanOrder != FAN_OFF_TEMP) && (slaveFanOrder != FAN_ON_BLUETOOTH)){
					slaveFanOrder = FAN_OFF_TEMP;
					sendFanOrderToSlave();
				}
				/* handeling Ligth order with lux value 1: prameter , 2: prevent repition ,3:bluetooth*/
				if ((currentLux > 1000) && (slaveLightOrder != LIGHT_OFF_LUX) && (slaveLightOrder != LIGHT_ON_BLUETOOTH)){
					slaveLightOrder = LIGHT_OFF_LUX;
					sendLightOrderToSlave();
				}

				if ((currentLux < 400 ) && (slaveLightOrder != LIGHT_ON_LUX) && (slaveLightOrder != LIGHT_OFF_BLUETOOTH)){
					slaveLightOrder = LIGHT_ON_LUX;
					sendLightOrderToSlave();
				}
			}
		}
	}
}



