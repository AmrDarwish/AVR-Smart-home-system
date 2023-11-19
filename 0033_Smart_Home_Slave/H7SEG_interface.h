/***************************************************/
/********************	Auther	: Amr 		********/
/********************	Layer 	:  H7SEG	********/
/********************	Module	:  7sement	********/
/********************	Version : 1.00		********/
/********************	Date	:  3/8/2023	********/
/***************************************************/
/**************************************************/

#ifndef _H7SEG_INTERFACE_H
#define _H7SEG_INTERFACE_H
#include "STD_TYPES.h"
void H7SEG_voidWrite(u8 num, u8 SEG7_PORT);
void H7SEG_voidWriteOnTwo(u8 num, u8 SEG7_DATA_PORT, u8 SEG7_CONTROL_PORT, u8 SEG7_CONTROL_PIN);
void H7SEG_voidClear( u8 SEG7_PORT);
#endif
