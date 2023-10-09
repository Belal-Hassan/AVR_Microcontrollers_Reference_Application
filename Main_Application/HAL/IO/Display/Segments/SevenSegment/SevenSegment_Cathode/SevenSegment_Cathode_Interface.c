/*
 * SevenSegment_Cathode_Interface.c
 *
 * Created: 9/24/2023 6:25:57 PM
 *  Author: Belal hassan
 */ 
#include <SevenSegment_Private.h>

#if _SEVENSEGMENT_TYPE_ == _SEVENSEGMENT_CATHODE_
void SevenSegment_Initialize(void)
{
	static bool Initialized = false; 
	if (!Initialized)
	{
		DIO_SetPortDirection(SevenSegment_PORT, SevenSegment_Output);
		Initialized = true;
	}
}
void SevenSegment_Enable_DP(void)
{
	SevenSegment_Initialize();
	DIO_SetPinValue(SevenSegment_PORT, SevenSegment_PIN_DP, SevenSegment_High);
}
void SevenSegment_Disable_DP(void)
{
	SevenSegment_Initialize();
	DIO_SetPinValue(SevenSegment_PORT, SevenSegment_PIN_DP, SevenSegment_Low);
}
void SevenSegment_Display_Number(u8 number)
{
	SevenSegment_Initialize();
	switch(number)
	{
		case 0:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Number_0);
		break;
		case 1:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Number_1);
		break;
		case 2:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Number_2);
		break;
		case 3:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Number_3);
		break;
		case 4:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Number_4);
		break;
		case 5:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Number_5);
		break;
		case 6:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Number_6);
		break;
		case 7:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Number_7);
		break;
		case 8:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Number_8);
		break;
		case 9:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Number_9);
		break;
	}
}
void SevenSegment_Display_Character(u8 character)
{
	SevenSegment_Initialize();
	switch(character)
	{
		case 97:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Character_a);
		break;
		case 98:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Character_b);
		break;
		case 99:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Character_c);
		break;
		case 100:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Character_d);
		break;
		case 101:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Character_e);
		break;
		case 102:
		DIO_WritePortValue(SevenSegment_PORT, SevenSegment_Character_f);
		break;
		default:
		break;
	}
}
#endif