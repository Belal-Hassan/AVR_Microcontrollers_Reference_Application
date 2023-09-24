/*
 * Buzzer_Interface.c
 *
 * Created: 9/22/2023 9:09:06 AM
 *  Author: Belal Hassan
 */ 
#include <Buzzer_Private.h>

void Buzzer_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		DIO_SetPinDirection(Buzzer_PORT, Buzzer, Buzzer_Output);
		Initialized = true;
	}
}
void Buzzer_On(void)
{
	Buzzer_Initialize();
	DIO_SetPinValue(Buzzer_PORT, Buzzer, Buzzer_High);
}
void Buzzer_Off(void)
{
	Buzzer_Initialize();
	DIO_SetPinValue(Buzzer_PORT, Buzzer, Buzzer_Low);
}
void Buzzer_Toggle(void)
{
	Buzzer_Initialize();
	DIO_TogglePinValue(Buzzer_PORT, Buzzer);
}