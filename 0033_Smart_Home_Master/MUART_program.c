/*
 * MUART_program.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MUART_interface.h"
#include "MUART_registers.h"
#include "MUART_config.h"
#include "MUART_private.h"


void MUART_voidInit()
{
	u8 Temp=0 ;
	/*Enable Transmitter & Receiver*/
	SET_BIT(UCSRB,UCSRB_RXEN);
	SET_BIT(UCSRB,UCSRB_TXEN);
	/*8-bit*/
	SET_BIT(Temp,UCSRC_UCSZ0);
	SET_BIT(Temp,UCSRC_UCSZ1);
	CLR_BIT(UCSRB,UCSRB_UCSZ2);
	/*Select UCSRC Register*/
	SET_BIT(Temp,UCSRC_URSEL);
	/*ASynch*/
	CLR_BIT(Temp,UCSRC_UMSEL);

	/*Stop Bits*/
#if MUART_STOP_BITS == MUART_1_STOP_BIT
	/*Stop bit is 1 i-bit */
	CLR_BIT(Temp,UCSRC_USBS);
#elif  MUART_STOP_BITS == MUART_2_STOP_BIT
	SET_BIT(Temp,UCSRC_USBS);
#endif

#if MUART_PARITY == MUART_ODD_PARITY
	/* Enable parity */
	SET_BIT(UCSRA,UCSRA_PE);
	/* Setting parity to odd*/
	SET_BIT(Temp,UCSRC_UPM0);
	SET_BIT(Temp,UCSRC_UPM1);

#elif MUART_PARITY == MUART_EVEN_PARITY
	/* Enable parity */
	SET_BIT(UCSRA,UCSRA_PE);
	/* Setting parity to odd*/
	CLR_BIT(Temp,UCSRC_UPM0);
	SET_BIT(Temp,UCSRC_UPM1);
#endif

	/*Select BaudRate*/
	UCSRC=Temp ;
	UBRRL = 51;
}

void MUART_voidTransmitByte(u8 Copy_u8Data){
	/* checking if udr buffer is free */
	while( !GET_BIT(UCSRA,UCSRA_UDRE) );
	UDR=Copy_u8Data ;
}

void MUART_voidTransmitString(s8* Copy_ptData){
	while(*Copy_ptData!= '\0'){
		MUART_voidTransmitByte(*Copy_ptData);
		Copy_ptData++;
	}
}


u8   MUART_u8ReciveByte(void){
	while (GET_BIT(UCSRA,UCSRA_RXC)==0);
	return UDR;
}

u8   MUART_u8IsRecivedData(void){
	u8 flag_Case = 0;

	if (GET_BIT(UCSRA,UCSRA_RXC)!=0){
		flag_Case = 1 ;
	}

	return flag_Case;
}
u8   MUART_u8ReciveByteWithoutBooling(void){
	return UDR;
}
