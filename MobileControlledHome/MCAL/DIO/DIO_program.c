/*
 * DIO_program.c
 *
 *  Created on: Aug 23, 2021
 *      Author: ahmad
 */
#include "../../LIB/BitMath.h"
#include "../../LIB/StdTypes.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_SetPinValue(u8 Port ,u8 Pin , u8 value){
	if(value == 1){
		switch(Port){
		case 0 :
			SET_BIT(PORTA,Pin);
			break;

		case 1:
			SET_BIT(PORTB,Pin);
			break;

		case 2:
			SET_BIT(PORTC,Pin);
			break;

		case 3:
			SET_BIT(PORTD,Pin);
			break;

		}
	}else{
		switch(Port){

		case 0:
			CLR_BIT(PORTA,Pin);
			break;

		case 1:
			CLR_BIT(PORTB,Pin);
			break;

		case 2:
			CLR_BIT(PORTC,Pin);
			break;

		case 3:
			CLR_BIT(PORTD,Pin);
			break;

		}
	}

}
void DIO_SetPortValue(u8 Port, u8 value){
	switch(Port){
	case 0:
		PORTA = value;
		break;
	case 1:
		PORTB = value;
		break;
	case 2:
		PORTC = value;
		break;
	case 3:
		PORTD = value;
		break;
	}
}
void DIO_TogglePinValue(u8 Port ,u8 Pin){
	switch(Port){
		case 0:
			TOG_BIT(PORTA,Pin);
			break;
		case 1:
			TOG_BIT(PORTB,Pin);
			break;
		case 2:
			TOG_BIT(PORTC,Pin);
			break;
		case 3:
			TOG_BIT(PORTD,Pin);
			break;
		}
}

u8 DIO_GetPinValue(u8 Port,u8 Pin){
	u8 ret = 0 ;
	switch(Port){
	case 0:
		ret = GET_BIT(PINA,Pin);
		break;
	case 1:
		ret = GET_BIT(PINB,Pin);
		break;
	case 2:
		ret = GET_BIT(PINC,Pin);
		break;
	case 3:
		ret = GET_BIT(PIND,Pin);
		break;
	}
	return ret;

}
u8 DIO_GetPortValue(u8 Port){
	u8 ret = 0;
	switch(Port){
	case 0:
		ret = PINA;
		break;
	case 1:
		ret = PINB;
		break;
	case 2:
		ret = PINC;
		break;
	case 3:
		ret = PIND;
		break;
	}
	return ret ;
}

void DIO_SetPinDirection(u8 Direct, u8 Pin, u8 value){
	if(value == 1){
		switch(Direct){
		case 0 :
			SET_BIT(DDRA,Pin);
			break;

		case 1:
			SET_BIT(DDRB,Pin);
			break;

		case 2:
			SET_BIT(DDRC,Pin);
			break;

		case 3:
			SET_BIT(DDRD,Pin);
			break;

		}
	}else{
		switch(Direct){

		case 0:
			CLR_BIT(DDRA,Pin);
			break;

		case 1:
			CLR_BIT(DDRB,Pin);
			break;

		case 2:
			CLR_BIT(DDRC,Pin);
			break;

		case 3:
			CLR_BIT(DDRD,Pin);
			break;

		}
	}


}
void DIO_SetPortDirection(u8 Direct , u8 value){
	switch(Direct){
	case 0:
		DDRA = value;
		break;
	case 1:
		DDRB = value;
		break;
	case 2:
		DDRC = value;
		break;
	case 3:
		DDRD = value;
		break;
	}
}

