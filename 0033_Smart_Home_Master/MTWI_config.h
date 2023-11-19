/*
 * MTWI_config.h
 *
 *  Created on: Aug 19, 2023
 *      Author: Amr-a
 */

#ifndef MTWI_CONFIG_H_
#define MTWI_CONFIG_H_
/*to calculate frequency
 *
 * 			(CPU clk)
 * CLK = --------------
 * 		 16+2(TWBR)*4^TWPS
 * */


/*prescaler
 * 			TWI_DIV_1	1
 * 			TWI_DIV_1	4
 * 			TWI_DIV_1	16
 * 			TWI_DIV_1	64
 *		Value in function numnator Power
 * */
#define TWI_TWPS_PRESCALER 				TWI_DIV_1
/* Value in function numnator */
#define  	TWI_TWBR_PRESCALER 			2
#define 	MY_ADDRESS					0x02
#endif /* MTWI_CONFIG_H_ */
