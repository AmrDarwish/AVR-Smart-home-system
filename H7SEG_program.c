/***************************************************/
/********************	Auther	: Amr 		********/
/********************	Layer 	:  H7SEG	********/
/********************	Module	:  7sement	********/
/********************	Version : 1.00		********/
/********************	Date	:  3/8/2023	********/
/***************************************************/
/***************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"
#include "H7SEG_interface.h"
#include "H7SEG_private.h"
#include "H7SEG_config.h"

void void_SegWrite(u8 num, u8 SEG7_PORT){
	int values[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	MDIO_ErrorS_SetPortValue(SEG7_PORT,~values[num]);
}
void void_SegClear( u8 SEG7_PORT){
	MDIO_ErrorS_SetPortValue(SEG7_PORT,0xff);
}

