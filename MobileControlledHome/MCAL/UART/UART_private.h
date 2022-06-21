/*
 * UART_private.h
 *
 *  Created on: Oct 5, 2021
 *      Author: ahmad
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#define PARITY_MASK			0b11001111


/*USART I/O Data Register – UDR*/
/*$0C ($2C) UDR USART I/O Data Register*/
#define UDR		( *((volatile u8*) (0x2C)   ))

/*USART Control and Status Register A – UCSRA*/
/*$0B ($2B) UCSRA */
#define UCSRA	( * ( (volatile u8*) (0x2B) )   )

/*USART Control and Status Register B – UCSRB*/
/*$0A ($2A) UCSRB */
#define UCSRB	( *((volatile u8*) (0x2A)   ))

/*USART Control and Status Register C – UCSRC*/
/*$20 ($40) UCSRC */
#define UCSRC	( *((volatile u8*) (0x40)   ))

/*USART Baud Rate Registers – UBRRL and UBRRH*/
/*$20 ($40) UBRRH */
#define UBRRH	( *((volatile u8*) (0x40)   ))

/*$09 ($29) UBRRL USART Baud Rate Register Low Byte*/
#define UBRRL	( *((volatile u8*) (0x29)   ))

/*UCSRA: RXC TXC UDRE FE DOR PE U2X MPCM */
#define UCSRA_RXC		7
#define UCSRA_TXC		6
#define UCSRA_UDRE		5
#define UCSRA_FE		4
#define UCSRA_DOR		3
#define UCSRA_PE		2
#define UCSRA_U2X		1
#define UCSRA_MPCM		0

/*UCSRB: RXCIE TXCIE UDRIE RXEN TXEN UCSZ2 RXB8 TXB8*/
#define UCSRB_RXCIE 			7
#define UCSRB_TXCIE 			6
#define UCSRB_UDRIE 			5
#define UCSRB_RXEN 				4
#define UCSRB_TXEN 				3
#define UCSRB_UCSZ2 			2
#define UCSRB_RXB8 				1
#define UCSRB_TXB8 				0

/*UCSRC: URSEL UMSEL UPM1 UPM0 USBS UCSZ1 UCSZ0 UCPOL */
#define UCSRC_URSEL 			7
#define UCSRC_UMSEL 			6
#define UCSRC_UPM1	 			5
#define UCSRC_UPM0	 			4
#define UCSRC_USBS	 			3
#define UCSRC_UCSZ1 			2
#define UCSRC_UCSZ0				1
#define UCSRC_UCPOL 			0

/*UBRRH: URSEL – – – UBRR[11:8]*/
#define UBRRH_URSEL 			7

#endif /* MCAL_UART_UART_PRIVATE_H_ */
