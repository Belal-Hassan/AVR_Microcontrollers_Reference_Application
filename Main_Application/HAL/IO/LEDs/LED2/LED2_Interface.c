/*
 * LED2_Interface.c
 *
 * Created: 9/22/2023 9:09:06 AM
 *  Author: Belal Hassan
 */ 
#include <LED2_Private.h>

void LED2_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		DIO_SetPinDirection(LED2_PORT, LED2, LED2_Output);
		Initialized = true;
	}
}
void LED2_On(void)
{
	LED2_Initialize();
	DIO_SetPinValue(LED2_PORT, LED2, LED2_High);
}
void LED2_Off(void)
{
	LED2_Initialize();
	DIO_SetPinValue(LED2_PORT, LED2, LED2_Low);
}
void LED2_Toggle(void)
{
	LED2_Initialize();
	DIO_TogglePinValue(LED2_PORT, LED2);
}