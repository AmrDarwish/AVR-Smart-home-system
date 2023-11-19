/*
 * HEEPROM_program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MTWI_interface.h"
#include "HEEPROM_interface.h"

#include "util/delay.h"

void EEPROM_voidWrite(u8 Copy_u8Data, u8 Copy_u7EEPROMAddress,u8 Copy_u8DataAddress){
	/*start condition*/
	MTWI_voidStart();

	/* sending address 0b1010 000 with write*/
	MTWI_voidWriteAddressWithOrder(Copy_u7EEPROMAddress,MTWI_WRITE);

	/* sending address data location inside eeprom*/
	MTWI_voidWriteData(Copy_u8DataAddress);

	/* sending data inside eeprom*/
	MTWI_voidWriteData(Copy_u8Data);

	/* stop condition */
	MTWI_voidStop();
}

void EEPROM_voidRead(u8 Copy_u7EEPROMAddress,u8 Copy_u8DataAddress, s8* Copy_pt8Data){
	/*start condition*/
	MTWI_voidStart();

	/* sending address 0b1010 0000 with write */
	MTWI_voidWriteAddressWithOrder(Copy_u7EEPROMAddress,MTWI_WRITE);

	/* sending address mlocation inside eeprom*/
	MTWI_voidWriteData(Copy_u8DataAddress);

	/* Send repeated start */
	MTWI_voidStart();

	/*repeated start condition with read*/
	MTWI_voidWriteAddressWithOrder(Copy_u7EEPROMAddress,MTWI_READ);

	/* NOW I'm reading one btpe from eeprom*/
	*Copy_pt8Data =  MTWI_u8ReadWithACK();

	/* stop condition */
	MTWI_voidStop();
}
void EEPROM_voidWriteString(u8* Copy_u8Data,u8 Copy_u8DataSize, u8 Copy_u7EEPROMAddress,u8 Copy_u8DataStartAddress){
	for ( ; Copy_u8DataSize > 0 ; Copy_u8DataSize--){
		/*start condition*/
		MTWI_voidStart();

		/* sending address 0b1010 000 with write*/
		MTWI_voidWriteAddressWithOrder(Copy_u7EEPROMAddress,MTWI_WRITE);

		/* sending address data location inside eeprom*/
		/* startig from last data adders */
		MTWI_voidWriteData(Copy_u8DataStartAddress+Copy_u8DataSize-1);

		/* sending data inside eeprom*/
		/* startig from last char in the string */
		MTWI_voidWriteData(Copy_u8Data[Copy_u8DataSize-1]);
		/* stop condition */
		MTWI_voidStop();
		_delay_ms(15);
	}

}


void EEPROM_voidReadString(u8 Copy_u7EEPROMAddress,u8 Copy_u8DataStartAddress,u8 Copy_u8DataSize, u8* Copy_pt8Data){

	for (;Copy_u8DataSize > 0 ; Copy_u8DataSize-- ){
		/*start condition*/
		MTWI_voidStart();

		/* sending address 0b1010 0000 with write */
		MTWI_voidWriteAddressWithOrder(Copy_u7EEPROMAddress,MTWI_WRITE);

		/* sending address mlocation inside eeprom */
		/* starting from the end of wanted data */
		MTWI_voidWriteData(Copy_u8DataStartAddress+Copy_u8DataSize-1);

		/* Send repeated start */
		MTWI_voidStart();

		/*repeated start condition with read*/
		MTWI_voidWriteAddressWithOrder(Copy_u7EEPROMAddress,MTWI_READ);

		/* NOW I'm reading one btpe from eeprom*/
		/* starting from the last byte of wanted data */
		Copy_pt8Data[Copy_u8DataSize-1] =  MTWI_u8ReadWithACK();

		/* stop condition */
		MTWI_voidStop();
	}
}
