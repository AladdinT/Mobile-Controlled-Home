/*
 * LCD_config.h
 *
 *  Created on: Aug 25, 2021
 *      Author: ahmad
 */

#ifndef LCD_LCD_CONFIG_H_
#define LCD_LCD_CONFIG_H_


// LCD SIZE
#define RS_PIN     DIO_PORTB, 0
#define RW_PIN     DIO_PORTB, 1
#define EN_PIN     DIO_PORTB, 2

#define DATA_PORT  DIO_PORTC

#define INSTALL    _8BIT
#define D7_PIN		DIO_PORTC, 7
#define D6_PIN		DIO_PORTC, 6
#define D5_PIN		DIO_PORTC, 5
#define D4_PIN		DIO_PORTC, 4

#endif /* LCD_LCD_CONFIG_H_ */
