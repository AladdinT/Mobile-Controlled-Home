/*
 * main.c
 *
 *  Created on: May 30, 2022
 *      Author: ahmad
 */
#define F_CPU 8000000UL

#include"../MCAL/DIO/DIO_interface.h"
#include "../MCAL/UART/UART_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../LIB/bitmath.h"
#include "../LIB/stdtypes.h"
#include <util/delay.h>

typedef struct {
	u16 password;
	u8 name[10];
}user;

u16 string_to_int (u8 str[] ){
	u16 num = 0;
	//cast it into an integer
	for(int j = 0 ; str[j] != '\0' ; j++){

		num = (str[j] - '0') + (num*10) ;//0b0000 0001
	}

	return num;
}

void ImplementAction( u8 Action , u8* ptr_Access )
{
	if(Action == '0')
	{
		//Turn on lights
		DIO_SetPinValue(DIO_PORTA , DIO_PIN1 , DIO_HIGH );

	}
	if(Action == '1')
	{
		//Turn off lights
		DIO_SetPinValue(DIO_PORTA , DIO_PIN1 , DIO_LOW );
	}
	if(Action == '2')
	{
		//Unlock the door
		DIO_SetPinValue(DIO_PORTA , DIO_PIN2 , DIO_LOW );
	}
	if(Action == '3')
	{
		//lock the door
		DIO_SetPinValue(DIO_PORTA , DIO_PIN2 , DIO_HIGH );
	}
	if(Action == '9')
	{
		//lock the door
		UART_voidTransmitString("Signed Out Successfully \n");
		*ptr_Access = 0;
	}
}

void AlarmImplementation (void)
{
	LCD_SendCommand(1);
	LCD_PrintString("ImpostorAmongUs");
	_delay_ms(500);
	//RED LED goes on
	DIO_SetPinValue(DIO_PORTA , DIO_PIN3 , DIO_HIGH);
	//DIO Alarm pin goes high
	DIO_SetPinValue(DIO_PORTA , DIO_PIN0 , DIO_HIGH);
	_delay_ms(10000);

	DIO_SetPinValue(DIO_PORTA , DIO_PIN0 , DIO_LOW);
	DIO_SetPinValue(DIO_PORTA , DIO_PIN3 , DIO_LOW);

}

int main (void)
{
	UART_voidInit();
	LCD_Init();

	DIO_SetPortDirection(DIO_DDRA , 0xff);


	user user_arr[10];
	user ahmad      = {0000 , "ahmad" };
	user amr        = {1111 , "amr" };
	user gedawy     = {2222 , "gedawy" };
	user mohamed    = {3333 , "mohamed" };
	user abdullah   = {4444 , "abdullah" };
	user yosry      = {5555 , "yosry" };
	user shamel     = {6666 , "shamel" };
	user mazen      = {7777 , "mazen"};
	user mahmoud    = {8888 , "mahmoud" };
	user alaa       = {9999 , "alaa" };


	user_arr[0] = ahmad;
	user_arr[1] = amr ;
	user_arr[2] = gedawy ;
	user_arr[3] = mohamed ;
	user_arr[4] = abdullah ;
	user_arr[5] = yosry ;
	user_arr[6] = shamel ;
	user_arr[7] = mazen;
	user_arr[8] = mahmoud ;
	user_arr[9] = alaa ;

	u8 Access;
	Access = 0;

	u8 AlarmCounter;
	AlarmCounter = 0 ;

	u8 ReceivedUsername[10];
	u8 ReceivedPassword[10];

	u8 ReceivedAction ;
	ReceivedAction = 0;

	u8 CorrectUsername = 0;
	u8 MatchingChar = 0;
	u8 j;
	while(1)
	{
		if( Access == 0 )
		{
			LCD_SendCommand(1);
			LCD_PrintString("Username : ");
			UART_voidTransmitString("Send Username\n");
			UART_voidReceiveString( ReceivedUsername );
			LCD_SetCursorPos(1,0);
			LCD_PrintString( ReceivedUsername );
			_delay_ms(500);

			LCD_SendCommand(1);
			LCD_PrintString("Password : ");
			UART_voidTransmitString("Send Password\n");
			UART_voidReceiveString( ReceivedPassword );
			LCD_SetCursorPos(1,0);
			LCD_PrintString( ReceivedPassword );
			_delay_ms(500);

			j = 0;
			for( u8 i = 0 ; ReceivedUsername[i] != '\0' ; )
			{

				if( ReceivedUsername[i] == user_arr[j].name[i] )
				{
					i++;
					MatchingChar++;
					CorrectUsername = j ;
				} else {
					j++;
					i = 0;
					MatchingChar = 0;
					if(j==10)
					{
						break;
					}
				}

			}
			if( MatchingChar != 0) //Check If its a correct username
			{

				if( string_to_int(ReceivedPassword ) == user_arr[CorrectUsername].password )
				{
					LCD_SendCommand(1);
					LCD_PrintString("Access Granted");
					UART_voidTransmitString("Access Granted\n");
					_delay_ms(500);
					Access = 1;
					AlarmCounter = 0;
				}else{
					AlarmCounter++;
					LCD_SendCommand(1);
					LCD_PrintString("Incorrect");
					UART_voidTransmitString("Incorrect ");
					LCD_SetCursorPos(1,0);
					LCD_PrintNum((s32) (3-AlarmCounter) );
					UART_voidTransmitAsynchronous('0'+(3-AlarmCounter));
					LCD_SetCursorPos(1,4);
					LCD_PrintString("Tries Left");
					UART_voidTransmitString(" Tries Left\n");

					_delay_ms(500);
				}
			} else {
				AlarmCounter++;
				LCD_SendCommand(1);
				LCD_PrintString("Incorrect");
				UART_voidTransmitString("Incorrect ");
				LCD_SetCursorPos(1,0);
				LCD_PrintNum((s32) (3-AlarmCounter) );
				UART_voidTransmitAsynchronous('0'+(3-AlarmCounter));
				LCD_SetCursorPos(1,4);
				LCD_PrintString("Tries Left");
				UART_voidTransmitString(" Tries Left\n");

				_delay_ms(500);
			}


		}

		if (AlarmCounter == 3)
		{
			AlarmImplementation();
			AlarmCounter = 0;
		}

		if( Access == 1 )
		{
			LCD_SendCommand(1);
			LCD_PrintString("Lights On/Off");
			LCD_SetCursorPos(1,0);
			LCD_PrintString("Door Look");
			ReceivedAction = UART_u8ReceiveAsynchronous();

			ImplementAction( ReceivedAction , &Access);

		}



	}

}
