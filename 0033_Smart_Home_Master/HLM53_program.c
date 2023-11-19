/*
 * HLM53_program.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MADC_interface.h"
#include "HLM53_interface.h"
#include "HLM53_private.h"
#include "HLM53_config.h"

s16 HLM35_s16GetRead(void){

	s16 temp 	= (s16)MADC_u16GetValue(HLM35_ADC_ChANNEL);
	temp		= MADC_s32Mapping(HLM35_MAX_TEMP,HLM35_MINI_TEMP,HLM35_MAX_DIGIT_VAL,HLM35_MINI_DIGIT_VAL,temp);
	return temp;
}
