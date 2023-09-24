/*
 * LED1_Interface.c
 *
 * Created: 9/22/2023 9:09:06 AM
 *  Author: Belal Hassan
 */ 
#include <LED1_Private.h>

void LED1_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		DIO_SetPinDirection(LED1_PORT, LED1, LED1_Output);
		Initialized = true;
	}
}
void LED1_On(void)
{
	LED1_Initialize();
	DIO_SetPinValue(LED1_PORT, LED1, LED1_High);
}
void LED1_Off(void)
{
	LED1_Initialize();
	DIO_SetPinValue(LED1_PORT, LED1, LED1_Low);
}
void LED1_Toggle(void)
{
	LED1_Initialize();
	DIO_TogglePinValue(LED1_PORT, LED1);
}