/*
 * MSPI_config.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Amr-a
 */

#ifndef MSPI_CONFIG_H_
#define MSPI_CONFIG_H_
/*
 * selcet master or slave
 *
 * */
/*in master >> ss input high
 *in SLave >> ss input LOW
 *
 * */
#define SPI_MASTER_OR_SLAVE		SPI_SLAVE

#define SPI_CLK_POLARITY		SPI_RISING_FIRST
#define SPI_CLK_PHASE			SPI_WRITE_FIRST

#define SPI_DATA_ORDER			SPI_LSB_FIRST

#define SPI_CLK_DIVIDER			SPI_SYS_CLK_DIV_16
#define SPI_INTERRUPT			SPI_EABLE_INTERRUPT


#endif /* MSPI_CONFIG_H_ */
