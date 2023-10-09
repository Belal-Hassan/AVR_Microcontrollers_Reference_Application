/*
 * SevenSegment_BCD_Interface.c
 *
 * Created: 9/24/2023 5:17:18 PM
 *  Author: Belal hassan
 */
#include <SevenSegment_Private.h>

#if _SEVENSEGMENT_TYPE_ == _SEVENSEGMENT_BCD_
void SevenSegment_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		DIO_WritePortDirection(SevenSegment_Control_PORT, SevenSegment_Enable_1_PIN, SevenSegment_Enable_DP_PIN, SevenSegment_Control_PORT_Output);
		DIO_WritePortDirection(SevenSegment_Data_PORT, SevenSegment_PIN_A, SevenSegment_PIN_D, SevenSegment_Data_PORT_Output);
		Initialized = true;
	}
}
void SevenSegment_Enable_1(void)
{
	SevenSegment_Initialize();
	DIO_SetPinValue(SevenSegment_Control_PORT, SevenSegment_Enable_1_PIN, SevenSegment_High);
}
void SevenSegment_Disable_1(void)
{
	SevenSegment_Initialize();
	DIO_SetPinValue(SevenSegment_Control_PORT, SevenSegment_Enable_1_PIN, SevenSegment_Low);
}
void SevenSegment_Enable_2(void)
{
	SevenSegment_Initialize();
	DIO_SetPinValue(SevenSegment_Control_PORT, SevenSegment_Enable_2_PIN, SevenSegment_High);	
}
void SevenSegment_Disable_2(void)
{
	SevenSegment_Initialize();
	DIO_SetPinValue(SevenSegment_Control_PORT, SevenSegment_Enable_2_PIN, SevenSegment_Low);
}
void SevenSegment_Enable_DP(void)
{
	SevenSegment_Initialize();
	DIO_SetPinValue(SevenSegment_Control_PORT, SevenSegment_Enable_DP_PIN, SevenSegment_High);
}
void SevenSegment_Disable_DP(void)
{
	SevenSegment_Initialize();
	DIO_SetPinValue(SevenSegment_Control_PORT, SevenSegment_Enable_DP_PIN, SevenSegment_Low);
}
void SevenSegment_Display_Number(u8 number)
{
	SevenSegment_Initialize();
	u8 units = (number % 10) << 4;
	u8 tenth = (number / 10) << 4;
	DIO_WritePortValue(SevenSegment_Data_PORT, SevenSegment_PIN_A, SevenSegment_PIN_D, units);
	SevenSegment_Enable_1();
	SevenSegment_Disable_2();
	_delay_ms(5);
	DIO_WritePortValue(SevenSegment_Data_PORT, SevenSegment_PIN_A, SevenSegment_PIN_D, tenth);
	SevenSegment_Enable_2();
	SevenSegment_Disable_1();
	_delay_ms(5);
}
#endif