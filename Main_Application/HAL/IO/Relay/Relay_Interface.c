/*
 * Relay_Interface.c
 *
 * Created: 9/22/2023 9:09:06 AM
 *  Author: Belal Hassan
 */ 
#include <Relay_Private.h>

void Relay_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		DIO_SetPinDirection(Relay_PORT, Relay, Relay_Output);
		Initialized = true;
	}
}
void Relay_On(void)
{
	Relay_Initialize();
	DIO_SetPinValue(Relay_PORT, Relay, Relay_High);
}
void Relay_Off(void)
{
	Relay_Initialize();
	DIO_SetPinValue(Relay_PORT, Relay, Relay_Low);
}
void Relay_Toggle(void)
{
	Relay_Initialize();
	DIO_TogglePinValue(Relay_PORT, Relay);
}