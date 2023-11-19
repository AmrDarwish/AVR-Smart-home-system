/*
 * MSPI_interface.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Amr-a
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_


#define SPI_MASTER 				1
#define SPI_SLAVE 				2

#define SPI_RISING_FIRST 		1
#define SPI_FALLING_FIRST  		2

#define	SPI_WRITE_FIRST			1
#define	SPI_READ_FIRST			2

#define SPI_MSB_FIRST			1
#define SPI_LSB_FIRST			2

#define SPI_SYS_CLK_DIV_2		1
#define SPI_SYS_CLK_DIV_4		2
#define SPI_SYS_CLK_DIV_8		3
#define SPI_SYS_CLK_DIV_16		4
#define SPI_SYS_CLK_DIV_32		5
#define SPI_SYS_CLK_DIV_64		6
#define SPI_SYS_CLK_DIV_128		7

#define SPI_EABLE_INTERRUPT		1
#define SPI_DISABLE_INTERRUPT	2


void MSPI_voidInit();
u8 MSPI_u8TransciveByte(u8 Copy_u8Data);
u8 MSPI_u8GetSPDR();

void setCallBackSPI(void (*fp)(void));
void ISR_SPI(void);

#endif /* MSPI_INTERFACE_H_ */
