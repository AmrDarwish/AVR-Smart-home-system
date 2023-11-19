/***************************************************/
/********************	Auther	: Amr 		********/

/********************	Layer 	:  HLCD		********/
/********************	Module	:  LCD		********/
/********************	Version : 11.00		********/
/********************	Date	:  3/8/2023	********/
/***************************************************/
/***************************************************/


#ifndef _HLCD_CONFIG_H
#define _HLCD_CONFIG_H

#define LCD_MODE			HLCD_MODE_4

#define LCD_PORT_DATA 		DIO_PORTA
#define LCD_D4		 		DIO_PIN2
#define LCD_D5		 		DIO_PIN3
#define LCD_D6		 		DIO_PIN4
#define LCD_D7		 		DIO_PIN5

#define LCD_PORT_CTRL 		DIO_PORTB
#define LCD_RS 				0
#define LCD_RW 				1
#define LCD_EN	 			3


#endif
