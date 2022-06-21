/*
 * UART_interface.h
 *
 *  Created on: Oct 5, 2021
 *      Author: ahmad
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_

#define _8_MHz		8000000
#define _1_MHz		1000000

#define PM_Disabled		0
#define PM_Enabled		1

#define ENABLE			1
#define DISABLE			0

void UART_voidInit(void);
void UART_voidTransmitAsynchronous( u8 Copy_u8Data );
u8 UART_u8ReceiveAsynchronous(void);
void UART_voidReceiveString(u8 *str);
void UART_voidTransmitString(u8 *str);


#endif /* MCAL_UART_UART_INTERFACE_H_ */
