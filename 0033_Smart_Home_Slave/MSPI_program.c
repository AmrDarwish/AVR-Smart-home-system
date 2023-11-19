/*
 * MSPI_program.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Amr-a
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSPI_registers.h"
#include "MSPI_interface.h"
#include "MSPI_private.h"
#include "MSPI_config.h"
void MSPI_voidInit(){

	/* selecting my device is master or slave from config */
#if SPI_MASTER_OR_SLAVE == SPI_MASTER
	SET_BIT(SPCR,SPCR_MSTR);
	/* selecting prescaler (frequancy) */
#if SPI_CLK_DIVIDER		== SPI_SYS_CLK_DIV_2
	/* selecting prescaler (frequancy) as dev bt 2 */
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_DIVIDER	== SPI_SYS_CLK_DIV_4
	/* selecting prescaler (frequancy) as dev bt 4 */
	CLR_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_DIVIDER	== SPI_SYS_CLK_DIV_8
	/* selecting prescaler (frequancy) as dev bt 8 */
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_DIVIDER	== SPI_SYS_CLK_DIV_16
	/* selecting prescaler (frequancy) as dev bt 16 */
	SET_BIT(SPCR,SPCR_SPR0);
	CLR_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_DIVIDER	== SPI_SYS_CLK_DIV_32
	/* selecting prescaler (frequancy) as dev bt 32 */
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	SET_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_DIVIDER	== SPI_SYS_CLK_DIV_64
	/* selecting prescaler (frequancy) as dev bt 64 */
	CLR_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#elif SPI_CLK_DIVIDER	== SPI_SYS_CLK_DIV_128
	/* selecting prescaler (frequancy) as dev bt 128 */
	SET_BIT(SPCR,SPCR_SPR0);
	SET_BIT(SPCR,SPCR_SPR1);
	CLR_BIT(SPSR,SPSR_SPI2X);
#else
#warning "invalid input"
#endif

#elif SPI_MASTER_OR_SLAVE == SPI_SLAVE
	CLR_BIT(SPCR,SPCR_MSTR);
#else
#warning "invalid input"
#endif

	/* select data order  */
#if SPI_DATA_ORDER	== SPI_LSB_FIRST
	/* select data order : least significant */
	SET_BIT(SPCR,SPCR_DORD);
#elif SPI_DATA_ORDER == SPI_MSB_FIRST
	/* select data order : most significant */
	CLR_BIT(SPCR,SPCR_DORD);
#else
#warning "invalid input"
#endif

	/* choosispcrng clk polarity */
#if SPI_CLK_POLARITY	== SPI_RISING_FIRST
	/* choosispcrng clk polarity as: leading edge is rising */
	CLR_BIT(SPCR,SPCR_CPOL);
#elif SPI_CLK_POLARITY	== SPI_FALLING_FIRST
	/* choosispcrng clk polarity as: leading edge is falling */
	SET_BIT(SPCR,SPCR_CPOL);
#else
#warning "invalid input"
#endif

	/* seceting clock phase setup:write, samole:read */
#if SPI_CLK_PHASE == SPI_WRITE_FIRST
	/* seceting clock phase as: leading edge is setup "Write" */
	SET_BIT(SPCR,SPCR_CPHA);
#elif  SPI_CLK_PHASE == SPI_READ_FIRST
	/* seceting clock phase as: leading edge is Sample "read" */
	CLR_BIT(SPCR,SPCR_CPHA);
#else
#warning "invalid input"
#endif
#if SPI_INTERRUPT	 == SPI_EABLE_INTERRUPT
	/* enable spi interrupt */
	SET_BIT(SPCR,SPCR_SPIE);
#elif SPI_INTERRUPT == SPI_DISABLE_INTERRUPT
#else
#warning
#endif
	/* enable spi */
	SET_BIT(SPCR,SPCR_SPE);

}
u8 MSPI_u8TransciveByte(u8 Copy_u8Data){
	SPDR = Copy_u8Data;
	/*read SPSR_SPIF then read SPDR*/
	while(GET_BIT(SPSR,SPSR_SPIF)==0);

	SET_BIT(SPSR,SPSR_SPIF);
	return SPDR;
}
u8 MSPI_u8GetSPDR(){
	return SPDR;
}


void (*callBackSPI) (void);
void setCallBackSPI(void (*fp)(void)){
	callBackSPI = fp;
}
void __vector_12(void) __attribute__((signal));
void __vector_12(void) {
	callBackSPI();
}

