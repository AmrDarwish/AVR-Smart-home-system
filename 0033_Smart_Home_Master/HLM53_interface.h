/*
 * HLM53_interface.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Amr-a
 */

#ifndef HLM53_INTERFACE_H_
#define HLM53_INTERFACE_H_

/*
 * thees values must be same as what in MADC_interface
 * */
#define HLM35_ADC_ChANNEL0			0
#define HLM35_ADC_ChANNEL1			1
#define HLM35_ADC_ChANNEL2			2
#define HLM35_ADC_ChANNEL3			3
#define HLM35_ADC_ChANNEL4			4
#define HLM35_ADC_ChANNEL5			5
#define HLM35_ADC_ChANNEL6			6
#define HLM35_ADC_ChANNEL7			7

s16 HLM35_s16GetRead(void);


#endif /* HLM53_INTERFACE_H_ */
