/*
 * MTIMER_program.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Amr-a
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MTIMER_interface.h"
#include "MTIMER_regesters.h"
#include "MTimer_config.h"
#include "MTIMER_private.h"


void MTIMER0_voidInit(void){
#if TIMER0_MODE == TIMER0_NORMAL

	/*selecting  wave generation mode as normal mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	/* enable timer 0 interrupt SIE */
	SET_BIT(TIMSK,TIMSK_TOIE0);

#elif TIMER0_MODE == TIMER0_CTC
	/*selecting  wave generation mode as CTC mode */
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	/* set out compare mat reg */
	OCR0 = COMPARE_MATCH_VALUE;
	/* Enable ctc ISR */
	SET_BIT(TIMSK , TIMSK_OCIE0);
#endif

	/* selecting timer 0 prescaler as dev by 8*/
	CLR_BIT(TCCR0,TCCR0_CS00);
	SET_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);

	/* setting preload value */
	//TCNT0 = PRELOAD_VALUE;



}
void MTIMER0_voidDisable(void){
	/*No clock source */
	CLR_BIT(TCCR0,TCCR0_CS00);
	CLR_BIT(TCCR0,TCCR0_CS01);
	CLR_BIT(TCCR0,TCCR0_CS02);


}
void MTIMER0_voidSetPreload(u8 Copy_u8Preload){
	TCNT0 = Copy_u8Preload;

}
