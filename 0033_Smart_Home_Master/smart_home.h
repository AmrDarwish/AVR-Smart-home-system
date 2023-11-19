/*
 * smart_home.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Amr-a
 */

#ifndef SMART_HOME_H_
#define SMART_HOME_H_

#define FAN_ON_TEMP					151
#define FAN_OFF_TEMP				152
#define FAN_ON_BLUETOOTH			153
#define FAN_OFF_BLUETOOTH			154

#define LIGHT_ON_LUX				155
#define LIGHT_OFF_LUX				156
#define LIGHT_ON_BLUETOOTH			157
#define LIGHT_OFF_BLUETOOTH			158

#define DOOR_ON_BLUETOOTH			159
#define DOOR_OFF_BLUETOOTH			160

#define GARAGE_ON_BLUETOOTH			161
#define GARAGE_OFF_BLUETOOTH		162
#define SLAVE_START					163
#define NO_ORDER					164

#define BLUETOOTH_OPEN_DOOR			'1'
#define BLUETOOTH_CLOSE_DOOR		'2'
#define BLUETOOTH_OPEN_FAN			'3'
#define BLUETOOTH_CLOSE_FAN			'4'
#define BLUETOOTH_OPEN_GARAGE		'5'
#define BLUETOOTH_CLOSE_GARAGE		'6'
#define BLUETOOTH_OPEN_LIGHT		'7'
#define BLUETOOTH_CLOSE_LIGHT		'8'
void ISR_TIMER0(void);

void initUsedPrefrals();
void welcomeScreen ();


void gettingMode ();
void selectioScreen();


void nameAndPassScreen();
void gettingNameAndPass(u8* enterdNameAndPass);

void enterUserData ();
void enterNewUserData();


void displayLightAndTemp();

void sendTempToSlave();
void sendFanOrderToSlave();
void sendLightOrderToSlave();
void sendDoorOrderToSlave();
void sendGarageOrderToSlave();


void getDataFromBluetooth();
u8 IsRecivedFromBluetooth();

#endif /* SMART_HOME_H_ */
