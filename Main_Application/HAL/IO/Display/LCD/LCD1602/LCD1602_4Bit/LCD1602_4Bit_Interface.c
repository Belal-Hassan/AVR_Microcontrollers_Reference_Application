/*
 * LCD1602_4Bit_Interface.c
 *
 * Created: 9/28/2023 5:08:17 PM
 *  Author: Belal hassan
 */ 
#include <LCD1602_Private.h>

#if _LCD1602_MODE_ == _LCD1602_4BIT_
void LCD_Enable(void)
{
	DIO_SetPinValue(LCD_Control_PORT, LCD_EN_PIN, LCD_High);
	_delay_ms(1);
	DIO_SetPinValue(LCD_Control_PORT, LCD_EN_PIN, LCD_Low);
}
void LCD_Send_Command(u8 Command)
{
	DIO_SetPinValue(LCD_Control_PORT, LCD_RS_PIN, LCD_Low);
	DIO_SetPinValue(LCD_Control_PORT, LCD_RW_PIN, LCD_Low);
	DIO_SetPinValue(LCD_Control_PORT, LCD_EN_PIN, LCD_Low);
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, (Command & 0xF0));
	LCD_Enable();
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, ((Command & 0x0F) << 4));
	LCD_Enable();
	_delay_us(100);
	if(Command == LCD_Command_IncrementCursor || Command == LCD_Command_DisplayLeft)
		CursorDirection = false;
	if(Command == LCD_Command_DecrementCursor || Command == LCD_Command_DisplayRight)
		CursorDirection = true;
}
void LCD_HomeScreen(void)
{
	LCD_Send_Command(0x02);
	_delay_us(1900);
	Character_Counter = 0;
}
void LCD_ClearScreen(void)
{
	LCD_Send_Command(0x01);
	LCD_HomeScreen();
	_delay_us(1900);
}
void LCD_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		DIO_WritePortDirection(LCD_Control_PORT, LCD_RS_PIN, LCD_EN_PIN, LCD_Control_PORT_Output);
		DIO_WritePortDirection(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, LCD_Data_PORT_Output);
		_delay_ms(15);
		LCD_Send_Command(LCD_Command_8BitInitialize);
		LCD_Send_Command(LCD_Command_4BitInitialize);
		LCD_Send_Command(LCD_Command_4Bit2Line);
		LCD_Send_Command(LCD_Command_DisplayOnCursorOn);
		LCD_Send_Command(LCD_Command_IncrementCursor);
		LCD_ClearScreen();
		Initialized = true;
	}
}
void LCD_LineCheck(void)
{
	if(Character_Counter % 32 == 0)
	{
		LCD_ClearScreen();
		LCD_Send_Command(LCD_Command_1stLine);
	}
	else if(Character_Counter % 16 == 0)
		LCD_Send_Command(LCD_Command_2ndLine);
}
void LCD_Display_Character(u8 Character)
{
	LCD_Initialize();
	LCD_LineCheck();
	DIO_SetPinValue(LCD_Control_PORT, LCD_RS_PIN, LCD_High);
	DIO_SetPinValue(LCD_Control_PORT, LCD_RW_PIN, LCD_Low);
	DIO_SetPinValue(LCD_Control_PORT, LCD_EN_PIN, LCD_Low);
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, (Character & 0xF0));
	LCD_Enable();
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, ((Character & 0x0F) << 4));
	LCD_Enable();
	_delay_us(100);
	if(CursorDirection)
		Character_Counter--;
	else
		Character_Counter++;
}
void LCD_Display_String(u8 String[])
{
	u8 Counter = 0;
	while(String[Counter] != '\0')
		LCD_Display_Character(String[Counter++]);
}
void LCD_Reverse_String(u8 String[], u8 Length)
{
	u8 Counter = 0, temp;
	Length--;
	while(Counter < Length)
	{
		temp = String[Counter];
		String[Counter++] = String[Length];
		String[Length--] = temp;
	}
}
u8 LCD_IntToString(u32 Number, u8 String[], u8 Length)
{
	u8 Counter = 0;
	while (Number)
	{
		String[Counter++] = (Number % 10) + '0';
		Number /= 10;
	}
	while (Counter < Length)
		String[Counter++] = '0';
	LCD_Reverse_String(String, Counter);
	String[Counter] = '\0';
	return Counter;
}
void LCD_Display_Number(u32 Number)
{
	u8 String[33];
	LCD_IntToString(Number, String, 0);
	LCD_Display_String(String);
}
void LCD_FloatToString(f32 Number, u8 String[], u8 AfterPoint)
{
	u32 int_part = (u32)Number;
	f32 float_part = Number - (f32)int_part;
	u8 Counter = LCD_IntToString(int_part, String, 0);
	String[Counter] = '.';
	float_part *= pow(10, AfterPoint);
	LCD_IntToString((u64)float_part, String + Counter + 1, AfterPoint);
}
void LCD_Display_FloatNumber(f32 Number, u8 AfterPoint)
{
	u8 String[33];
	LCD_FloatToString(Number, String, AfterPoint);
	LCD_Display_String(String);
}
void LCD_Display_Location(u8 xAxis, u8 yAxis)
{
	LCD_Initialize();
	u8 RowAddress[2] = {0x80, 0xC0};
	LCD_Send_Command(RowAddress[yAxis] + xAxis);
	Character_Counter = (yAxis * 16) + (xAxis + 1);
}
void LCD_Send_Special(u8 Character)
{
	LCD_Initialize();
	DIO_SetPinValue(LCD_Control_PORT, LCD_RS_PIN, LCD_High);
	DIO_SetPinValue(LCD_Control_PORT, LCD_RW_PIN, LCD_Low);
	DIO_SetPinValue(LCD_Control_PORT, LCD_EN_PIN, LCD_Low);
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, (Character & 0xF0));
	LCD_Enable();
	DIO_WritePortValue(LCD_Data_PORT, LCD_PIN_D4, LCD_PIN_D7, ((Character & 0x0F) << 4));
	LCD_Enable();
	_delay_us(100);
}
void LCD_Store_Special(u8 Character[], u8 Address)
{
	LCD_Send_Command(LCD_Command_CGRAM + (Address*8));
	for(int i = 0; i < 8; i++)
		LCD_Send_Special(Character[i]);
	LCD_Display_Location(Character_Counter % 16, Character_Counter / 16);
}
#endif