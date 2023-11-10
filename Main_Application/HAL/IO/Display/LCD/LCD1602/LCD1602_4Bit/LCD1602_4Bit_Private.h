/*
* LCD1602_4Bit_Private.h
*
* Created: 9/28/2023 5:07:46 PM
*  Author: Belal hassan
*/


#ifndef LCD1602_4BIT_PRIVATE_H_
#define LCD1602_4BIT_PRIVATE_H_

#include <LCD1602_4Bit_Configuration.h>

u32 Character_Counter;
bool CursorDirection;
void LCD_Enable(void);
void LCD_Send_Command(u8 Command);
void LCD_HomeScreen(void);
void LCD_ClearScreen(void);
void LCD_Initialize(void);
void LCD_Display_Character(u8 Character);
void LCD_Display_String(u8 String[]);
void LCD_Reverse_String(u8 String[], u8 Length);
u8 LCD_IntToString(u32 Number, u8 String[], u8 Length);
void LCD_Display_Number(u32 Number);
void LCD_FloatToString(f32 Number, u8 String[], u8 AfterPoint);
void LCD_Display_FloatNumber(f32 Number, u8 AfterPoint);
void LCD_Display_Location(u8 xAxis, u8 yAxis);
void LCD_Send_Special(u8 Character);
void LCD_Store_Special(u8 Character[], u8 Address);

#endif /* LCD1602_4BIT_PRIVATE_H_ */