/*
 * LCD_interface.h
 *
 *  Created on: Aug 25, 2021
 *      Author: ahmad
 */

#ifndef LCD_LCD_INTERFACE_H_
#define LCD_LCD_INTERFACE_H_
#include "../LIB/stdtypes.h"



void LCD_SendCommand(u8 Com);
void LCD_SendChar(u8 Com);

void LCD_Init(void);

void LCD_PrintNum(s32 num);

void LCD_SetCursorPos(u8 y, u8 x);

void LCD_SaveCustChar(u8 index, u8 arr[]);
void LCD_PrintString(s8 * str);
#endif /* LCD_LCD_INTERFACE_H_ */
