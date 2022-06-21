/*
 * DIO_interface.h
 *
 *  Created on: Aug 23, 2021
 *      Author: ahmad
 */
#include "../../LIB/stdtypes.h"
#ifndef DIO_DIO_INTERFACE_H_
#define DIO_DIO_INTERFACE_H_


#define DIO_PORTA 	(0)
#define DIO_PORTB 	(1)
#define DIO_PORTC 	(2)
#define DIO_PORTD 	(3)

#define DIO_PINA 	(0)
#define DIO_PINB 	(1)
#define DIO_PINC 	(2)
#define DIO_PIND 	(3)

#define DIO_DDRA 	(0)
#define DIO_DDRB 	(1)
#define DIO_DDRC 	(2)
#define DIO_DDRD 	(3)


#define DIO_PIN0 	(0)
#define DIO_PIN1 	(1)
#define DIO_PIN2 	(2)
#define DIO_PIN3 	(3)
#define DIO_PIN4 	(4)
#define DIO_PIN5 	(5)
#define DIO_PIN6 	(6)
#define DIO_PIN7 	(7)

#define DIO_HIGH  		 (1)
#define DIO_LOW  		 (0)
#define DIO_OUTPUT	 		1
#define DIO_INPUT			0

#define DIO_PULL_UP			1
#define DIO_FLOATING		0

void DIO_SetPinValue(u8 Port ,u8 Pin , u8 value);
void DIO_SetPortValue(u8 Port, u8 value);
void DIO_TogglePinValue(u8 Port ,u8 Pin);
u8 DIO_GetPinValue(u8 Port,u8 Pin);
u8 DIO_GetPortValue(u8 Port);
void DIO_SetPinDirection(u8 Direct, u8 Pin, u8 value);
void DIO_SetPortDirection(u8 Direct , u8 value);

#endif /* DIO_DIO_INTERFACE_H_ */
