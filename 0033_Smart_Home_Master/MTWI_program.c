/*
 * MTWI_program.c
 *
 *  Created on: Aug 19, 2023
 *      Author: Amr-a
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MTWI_interface.h"
#include "MTWI_private.h"
#include "MTWI_registers.h"
#include "MTWI_config.h"

void MTWI_voidInit(void){

	/*	Setting my adderss */
	TWAR = (MY_ADDRESS<<1);

	/*just two bits an other wil be set later*/
	/* setting prescaler value */
#if TWI_TWPS_PRESCALER == TWI_DIV_1
	TWSR = 0b00000000;
#elif TWI_TWPS_PRESCALER == TWI_DIV_4
	TWSR = 0b00000001;
#elif TWI_TWPS_PRESCALER == TWI_DIV_16
	TWSR = 0b00000010;
#elif TWI_TWPS_PRESCALER == TWI_DIV_64
	TWSR = 0b00000011;
#endif
	/* setting remaining of prescaler */
	TWBR = TWI_TWBR_PRESCALER;
	/* Enabling TWI by setting TWI Enable Bit */
	SET_BIT(TWCR,TWCR_TWEN);

}

void MTWI_voidStart(void){
	/*Set TWSTA to start condition*/
	SET_BIT(TWCR,TWCR_TWSTA);
	/* clearing flag by setting */
	SET_BIT(TWCR,TWCR_TWINT);
	/* Enabling TWI by setting TWI Enable Bit */
	SET_BIT(TWCR,TWCR_TWEN);
	/* busy wait on TWINT */
	while((GET_BIT(TWCR , TWCR_TWINT))==0);

}

void MTWI_voidWriteAddressWithOrder(u8 Copy_u7SlaveAddress,u8 copy_u8ReadOrWrite){
	if (copy_u8ReadOrWrite == MTWI_WRITE){
		/* Assiging value */
		/* clearing forst bit to enable Write */
		/* bouth are in one instruction */
		TWDR = Copy_u7SlaveAddress;
		TWDR = (TWDR << 1);
		CLR_BIT(TWDR,TWDR_TWD0);
	}
	else if(copy_u8ReadOrWrite == MTWI_READ) {

		/* Assiging value */
		/* clearing forst bit to enable Write */
		/* bouth are in one instruction */
		TWDR = Copy_u7SlaveAddress;
		TWDR = (TWDR << 1);
		SET_BIT(TWDR,TWDR_TWD0);
	}

	/* CLR start condition */
	CLR_BIT(TWCR,TWCR_TWSTA);

	/* clearing flag by setting */
	SET_BIT(TWCR,TWCR_TWINT);
	/* Enabling TWI by setting TWI Enable Bit */
	SET_BIT(TWCR,TWCR_TWEN);
	/* busy wait on TWINT */
	while((GET_BIT(TWCR , TWCR_TWINT))==0);

}

void MTWI_voidWriteData(u8 Copy_u8Data){
	/* Assiging value */
	TWDR = Copy_u8Data;
	/* CLR start condition */
	CLR_BIT(TWCR,TWCR_TWSTA);
	/* clearing flag by setting */
	SET_BIT(TWCR,TWCR_TWINT);
	/* Enabling TWI by setting TWI Enable Bit */
	SET_BIT(TWCR,TWCR_TWEN);
	/* busy wait on TWINT */
	while((GET_BIT(TWCR , TWCR_TWINT))==0);

}

u8 MTWI_u8ReadWithACK(void){
	/* CLR start condition */
	CLR_BIT(TWCR,TWCR_TWSTA);
	/* clearing flag by setting */
	SET_BIT(TWCR,TWCR_TWINT);
	/* Enabling TWI by setting TWI Enable Bit */
	SET_BIT(TWCR,TWCR_TWEN);
	/* busy wait on TWINT */
	while((GET_BIT(TWCR , TWCR_TWINT))==0);
	return TWDR;
}


void MTWI_voidStop(void){
	/* set to Make stop condition */
	SET_BIT(TWCR,TWCR_TWSTO);
	/* clearing flag by setting */
	SET_BIT(TWCR,TWCR_TWINT);
	/* Enabling TWI by setting TWI Enable Bit */
	SET_BIT(TWCR,TWCR_TWEN);


}

u8 MTWI_u8GetStatus(void){
	return (TWSR&0xF8);
}
