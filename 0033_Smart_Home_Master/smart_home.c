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
#include "MTWI_interface.h"
#include "MGIE_interface.h"
#include "MADC_interface.h"
#include "MUART_interface.h"
#include "MSPI_interface.h"
#include "MTIMER_interface.h"

#include "HLDR_interface.h"
#include "HLM53_interface.h"
#include "HEEPROM_interface.h"
#include "HLCD_interface.h"
#include "HKeyPad_interface.h"

#include "smart_home.h"
#include "comonFunctions.h"

extern u8 flag;

extern u16 newLux;
extern u16 currentLux;

extern u8 newTemprature;
extern u8 currentTemprature;
extern u8 slaveFanOrder ;
extern u8 slaveLightOrder ;
extern u8 slaveDoorOrder ;
extern u8 slaveGarageOrder ;
extern u8 bluetoothOrder ;

static u8 tries = 0;


void ISR_TIMER0(void){
	static u8 counter= 0;
	counter ++;
	if (counter == 32){
		/* ecah 1 sec */
		counter = 0;
		newLux = HLDR_u16GetRead();
		newTemprature = (u8)HLM35_s16GetRead();
		}
}

void initUsedPrefrals(){
	Port_voidInit();

	/*I2C init*/
	MTWI_voidInit();

	MADC_ErrorStateInit(ADC_VREF_VCC,ADC_PRESCALER_DIV32,ADC_RIGHT_ADJUSTMENT);
	MSPI_voidInit();
	HLCD_voidInit();
	MGIE_voidEnable();
	MTIMER0_voidInit();
	setCallBackTimer0(ISR_TIMER0);
	MUART_voidInit();
}

void welcomeScreen (){
	HLCD_voidSendString("   Welcome to");
	HLCD_voidSetCursorPosition(2,0);
	HLCD_voidSendString("   Smart Home");
	_delay_ms(2000);
	flag = 0;
}

void gettingMode (){
	tries = 0;
	u8 key = 0;
	while(1){
		key = HKeyPad_u8GetKey();
		if (key == '1'){
			flag = 1;
			break;
		}
		//		else if (key == '2'){
		//			flag = 2;
		//			break;
		//		}
		else if (key == '3'){
			flag = 3;
			break;
		}
	}
}

void selectioScreen(){
	HLCD_voidClearDisplay();
	HLCD_voidSetCursorPosition(0,0);
	HLCD_voidSendString(" 1:add new user");
	HLCD_voidSetCursorPosition(2,0);
	HLCD_voidSendString("2:editUsr 3:open");
	gettingMode ();
}

void gettingNameAndPass(u8* enterdNameAndPass){
	u8 tempK;
	u8 iterator = 0;
	u8 lcdLine = 1;
	while(1){
		tempK = HKeyPad_u8GetKey();
		if ( tempK != NO_KEY ){
			/* sending entered key to lcd */
			HLCD_voidSetCursorPosition(lcdLine,6+(iterator%4));
			HLCD_voidSendData(tempK);

			enterdNameAndPass[iterator] = tempK;
			tempK = NO_KEY;
			iterator++;

			if(iterator == 4){
				lcdLine = 2;
			}
			if(iterator == 8){
				enterdNameAndPass[iterator] = '\0';
				break;
			}
		}
	}
}
void nameAndPassScreen(){
	HLCD_voidClearDisplay();
	HLCD_voidSetCursorPosition(0,0);
	HLCD_voidSendString("Name:");
	HLCD_voidSetCursorPosition(2,0);
	HLCD_voidSendString("Pass:");

}

void enterUserData (){
	nameAndPassScreen();

	u8* savedNameAndPass  = (u8*) "NAMEPASS" ;
	u8* enterdNameAndPass = (u8*) "Amr00000" ;

	gettingNameAndPass(enterdNameAndPass);

	EEPROM_voidReadString(0x50,0x00,8,savedNameAndPass);

	//	HLCD_voidClearDisplay();
	//	HLCD_voidSendString((s8*)enterdNameAndPass);
	//	HLCD_voidSendString((s8*)savedNameAndPass);

	/* checking name pass */
	if(compareString(savedNameAndPass,enterdNameAndPass,8)){
		HLCD_voidClearDisplay();
		HLCD_voidSendString("     RGHT");
		_delay_ms(1500);
		flag = 4;
		MSPI_u8TransciveByte(SLAVE_START);
	}
	else{
		HLCD_voidClearDisplay();
		HLCD_voidSendString("     Wrong");
		_delay_ms(1500);
		HLCD_voidSetCursorPosition(2,0);
		HLCD_voidSendString("    Try Again");
		_delay_ms(1500);
		tries++;
		flag = 3;
		if (tries == 3){

			tries = 0;
			flag = 0;
		}
	}
}

void enterNewUserData(){
	nameAndPassScreen();
	u8* nameAndPass = (u8*)"NAMEPASS" ;
	gettingNameAndPass(nameAndPass);

	EEPROM_voidWriteString(nameAndPass,8,0x50,0x00);

	HLCD_voidClearDisplay();

	HLCD_voidSendString("  Done Entring  ");
	_delay_ms(1500);
	HLCD_voidSetCursorPosition(0,0);
	HLCD_voidSendString("   now enter    ");
	HLCD_voidSetCursorPosition(2,0);
	HLCD_voidSendString(" Name and Pass  ");
	_delay_ms(1500);
	enterUserData();

	//	HLCD_voidSetCursorPosition(2,0);
	//	HLCD_voidSendString((s8*)nameAndPass);
}

void displayLightAndTemp(){
	HLCD_voidClearDisplay();
	HLCD_voidSendString("Temprature:");
	HLCD_voidSendInt(currentTemprature%100);

	HLCD_voidSetCursorPosition(2,0);
	HLCD_voidSendString("Lumen:");
	HLCD_voidSendInt(currentLux);

}

void getDataFromBluetooth(){
	bluetoothOrder = MUART_u8ReciveByte();
	HLCD_voidSetCursorPosition(2,13);
	HLCD_voidSendInt(bluetoothOrder);
}

u8 IsRecivedFromBluetooth(){
	u8 data = MUART_u8IsRecivedData();
	return data;
}

void sendTempToSlave(){
	MSPI_u8TransciveByte(currentTemprature%151);
}

void sendFanOrderToSlave(){
	MSPI_u8TransciveByte(slaveFanOrder);
}

void sendLightOrderToSlave(){
	MSPI_u8TransciveByte(slaveLightOrder);
}

void sendDoorOrderToSlave(){
	MSPI_u8TransciveByte(slaveDoorOrder);
}
void sendGarageOrderToSlave(){
	MSPI_u8TransciveByte(slaveGarageOrder);
}


