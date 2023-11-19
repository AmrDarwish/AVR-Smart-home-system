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

#define GHARASH_ON_BLUETOOTH		161
#define GHARASH_OFF_BLUETOOTH		162
#define SLAVE_START					163
#define NO_DATA						164

void initUsedPrefralsBeforeSPI();
void initUsedPrefralsAfterSPI();

void on_All_LEDS();
void off_All_LEDS();
void openGaragDoor();
void closeGaragDoor();
void close_Home_Door();
void open_Home_Door();
void turnOnFan();
void turnOffFan();

void displaySeg1Num();
void displaySeg2Num();

void gettingMode ();
void selectioScreen();


void displayTemp();


#endif /* SMART_HOME_H_ */
