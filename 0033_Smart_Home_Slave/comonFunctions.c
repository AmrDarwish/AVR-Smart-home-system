/*
 * comonFunctions.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Amr-a
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "comonFunctions.h"

u8 compareString(u8* s1 , u8* s2,u8 size){
	u8 result = 1;
	u8 i;
	for (i = 0 ; i < size ; i++){
		if (s1[i] == s2[i]){

		}
		else {
			result = 0;
		}

	}
	return result;
}
