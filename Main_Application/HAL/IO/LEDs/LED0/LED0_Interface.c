/*
 * LED0_Interface.c
 *
 * Created: 9/22/2023 9:09:06 AM
 *  Author: Belal Hassan
 */ 
#include <LED0_Private.h>

void LED0_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		DIO_SetPinDirection(LED0_PORT, LED0, LED0_Output);
		Initialized = true;
	}
}
void LED0_On(void)
{
	LED0_Initialize();
	DIO_SetPinValue(LED0_PORT, LED0, LED0_High);
}
void LED0_Off(void)
{
	LED0_Initialize();
	DIO_SetPinValue(LED0_PORT, LED0, LED0_Low);
}
void LED0_Toggle(void)
{
	LED0_Initialize();
	DIO_TogglePinValue(LED0_PORT, LED0);
}