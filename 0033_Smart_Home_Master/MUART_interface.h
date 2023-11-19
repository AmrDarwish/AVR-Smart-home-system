/*
 * MUART_interface.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Amr-a
 */

#ifndef MUART_INTERFACE_H_
#define MUART_INTERFACE_H_

#define MUART_EVEN_PARITY  	1
#define MUART_ODD_PARITY  	2
#define MUART_NO_PARITY  	3

#define MUART_1_STOP_BIT  	1
#define MUART_2_STOP_BIT  	2

#define MUART_5_BIT_DATA  	1
#define MUART_6_BIT_DATA  	2
#define MUART_7_BIT_DATA  	3
#define MUART_8_BIT_DATA  	4
#define MUART_9_BIT_DATA  	5



void MUART_voidInit(void);
void MUART_voidTransmitByte(u8 Copy_u8Data);
u8   MUART_u8ReciveByte(void);
u8   MUART_u8IsRecivedData(void);
u8   MUART_u8ReciveByteWithoutBooling(void);

void MUART_voidTransmitString(s8* Copy_ptData);

#endif /* MUART_INTERFACE_H_ */
