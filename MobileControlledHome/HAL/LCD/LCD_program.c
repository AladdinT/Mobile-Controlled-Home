/*
 * LCD_program.c
 *
 *  Created on: Aug 25, 2021
 *      Author: ahmad
 */
#include <util/delay.h>
#include "../LIB/stdtypes.h"
#include "LCD_config.h"
#include "../MCAL/DIO/DIO_interface.h"
#include  "LCD_private.h"
#include "../LIB/bitmath.h"

#if  (INSTALL == 8)
void LCD_SendCommand(u8 Com){


	DIO_SetPinValue( RS_PIN , 0);//RS
	DIO_SetPinValue( RW_PIN , 0);//RW


	DIO_SetPortValue( DATA_PORT , Com);//D0-7;

	_delay_ms(1);
	DIO_SetPinValue( EN_PIN , 1);//EN
	_delay_ms(1);
	DIO_SetPinValue( EN_PIN , 0);//EN


}
void LCD_SendChar(u8 Com){

	DIO_SetPinValue ( RS_PIN , 1);//RS
	DIO_SetPinValue ( RW_PIN , 0);//RW
	_delay_ms(1);
	DIO_SetPortValue( DATA_PORT , Com);//D0-7;

	_delay_ms(1);
	DIO_SetPinValue( EN_PIN , 1);//EN
	_delay_ms(1);
	DIO_SetPinValue( EN_PIN , 0);//EN
	_delay_ms(1);
}

void LCD_Init(void){
	//DIO_SetPortDirection(DIO_DDRB,0b00000111);
	DIO_SetPinDirection( RS_PIN , 1);
	DIO_SetPinDirection( RW_PIN , 1);
	DIO_SetPinDirection( EN_PIN , 1);

	DIO_SetPortDirection( DATA_PORT ,0xff);

	_delay_ms(40);//Function Set
	LCD_SendCommand(0b00111000);//D=0011NFxx



	_delay_ms(1);//Display ON/OFF Control
	LCD_SendCommand(0b00001100);//D=0b00001DCB

	_delay_ms(1);//Display Clear
	LCD_SendCommand(1);//D=1

	_delay_ms(2);//Entry Mode Set
	LCD_SendCommand(0b00000110);//D=000001(I/D)(SH)

}
#elif (INSTALL == 4)
void LCD_SendCommand(u8 Com){



	DIO_SetPinValue( RS_PIN , 0);//RS
	DIO_SetPinValue( RW_PIN , 0);//RW


	DIO_SetPinValue( D7_PIN , GET_BIT( Com , 7) ); //D7-4
	DIO_SetPinValue( D6_PIN , GET_BIT( Com , 6) );
	DIO_SetPinValue( D5_PIN , GET_BIT( Com , 5) );
	DIO_SetPinValue( D4_PIN , GET_BIT( Com , 4) );

	_delay_ms(1);
	DIO_SetPinValue( EN_PIN , 1);//EN
	_delay_ms(1);
	DIO_SetPinValue( EN_PIN , 0);//EN


}
void LCD_SendChar(u8 Com){

	DIO_SetPinValue ( RS_PIN , 1);//RS
	DIO_SetPinValue ( RW_PIN , 0);//RW
	_delay_ms(1);
	DIO_SetPinValue( D7_PIN , GET_BIT( Com , 7) ); //D7-4
	DIO_SetPinValue( D6_PIN , GET_BIT( Com , 6) );
	DIO_SetPinValue( D5_PIN , GET_BIT( Com , 5) );
	DIO_SetPinValue( D4_PIN , GET_BIT( Com , 4) );

	_delay_ms(1);
	DIO_SetPinValue( EN_PIN , 1);//EN
	_delay_ms(1);
	DIO_SetPinValue( EN_PIN , 0);//EN
	_delay_ms(1);
}

void LCD_Init(void){
	//DIO_SetPortDirection(DIO_DDRB,0b00000111);
	DIO_SetPinDirection( RS_PIN , 1);
	DIO_SetPinDirection( RW_PIN , 1);
	DIO_SetPinDirection( EN_PIN , 1);

	DIO_SetPinDirection( D7_PIN , 1);
	DIO_SetPinDirection( D6_PIN , 1);
	DIO_SetPinDirection( D5_PIN , 1);
	DIO_SetPinDirection( D4_PIN , 1);



	_delay_ms(40);//Function Set
	LCD_SendCommand(0b00100000);//D=0010xxxx
	LCD_SendCommand(0b00100000);//D=0010xxxx
	LCD_SendCommand(0b10000000);//D=NFxxxxxx



	_delay_ms(1);//Display ON/OFF Control
	LCD_SendCommand(0b00000000);//D=0b0000xxxx
	LCD_SendCommand(0b11000000);//D=0b1DCBxxxx

	_delay_ms(1);//Display Clear
	LCD_SendCommand(0);//D=1
	LCD_SendCommand(0b00010000);//D=0b0001xxxx


	_delay_ms(2);//Entry Mode Set
	LCD_SendCommand(0);//D=0000xxxx
	LCD_SendCommand(0b01000000);//D=01(I/D)(SH)xxxx

}

#endif

void LCD_PrintNum(s32 num){
	s32 reversed = 0 ;
	u8 flag = 0;
	if(num < 0){
		LCD_SendChar('-');
		s32 post_num = ( num + (-2*num) );
		LCD_PrintNum( post_num );
	}

	if(num == 0){
		LCD_SendChar('0');
	}else if(num % 10 == 0){
		num++;
		flag=1;
	}
	while(num>0){

		reversed = reversed * 10 + num % 10;
		num /= 10;
	}

	while(reversed > 0){

		LCD_SendChar('0'+(reversed%10));
		reversed /= 10;
		if(reversed == 1){
			if(flag == 1){
				LCD_SendChar('0');
				reversed = 0;
			}
		}
	}


}

void LCD_SetCursorPos(u8 y, u8 x){

	LCD_SendCommand(0b10000000 + x + (64*y) );
}

void LCD_SaveCustChar(u8 index, u8 arr[]){
	LCD_SendCommand(0b01000000 + (8*index)); // Set CG RAM
	for(int i=0; i<8 ; i++){
		LCD_SendChar(arr[i]);
	}
	LCD_SetCursorPos(0,0);//Display Origin(Set DD RAM)
}

void LCD_PrintString(s8 * str)
{

	for(int i=0 ; *(str+i)!='\0' ; i++){
		LCD_SendChar(*(str+i));
	}

}
