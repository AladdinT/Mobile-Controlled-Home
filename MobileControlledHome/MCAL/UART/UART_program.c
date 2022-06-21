/*
 * UART_program.c
 *
 *  Created on: Oct 5, 2021
 *      Author: ahmad
 */
#include "../../LIB/bitmath.h"
#include "../../LIB/stdtypes.h"

#include "../UART/UART_config.h"
#include "../UART/UART_interface.h"
#include "../UART/UART_private.h"


void UART_voidInit(void)
{
	UCSRC = 0b10000110;
	UCSRB = 0b00011000;
	CLR_BIT(UBRRL,UBRRH_URSEL);
	UBRRH =(u8) 0x00;
	UBRRL =(u8) 103;
	SET_BIT(UCSRA,UCSRA_U2X);

}

void UART_voidTransmitAsynchronous( u8 Copy_u8Data )
{

	/*Wait until the UDR is ready to be written*/
	while( GET_BIT(UCSRA , UCSRA_UDRE) == 0 );

	/*Transmit the data to UDR*/
	UDR = Copy_u8Data;

}


u8 UART_u8ReceiveAsynchronous(void)
{

	/*Wait until the reception is done*/
	while( GET_BIT(UCSRA , UCSRA_RXC) == 0 );

	return UDR;

}

void UART_voidReceiveString(u8 *str)
{
	u8 i = 0;
	str[i] = UART_u8ReceiveAsynchronous();
	while(str[i] != '#')
	{
		i++;
		str[i] = UART_u8ReceiveAsynchronous();
	}
	str[i] = '\0';
}


void UART_voidTransmitString(u8 *str)
{
	u8 i = 0;
	while(str[i] != '\0')
	{
		UART_voidTransmitAsynchronous(str[i]);
		i++;
	}
}
