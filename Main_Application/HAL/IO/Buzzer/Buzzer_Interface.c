/*
 * Buzzer_Interface.c
 *
 * Created: 9/22/2023 9:09:06 AM
 *  Author: Belal Hassan
 */ 
#include <Buzzer_Private.h>

void Buzzer_Init(void)
{
	DIO_SetPinDirection(Buzzer_PORT, Buzzer, Buzzer_Output);
}
void Buzzer_ON(void)
{
	DIO_SetPinValue(Buzzer_PORT, Buzzer, Buzzer_High);
}
void Buzzer_OFF(void)
{
	DIO_SetPinValue(Buzzer_PORT, Buzzer, Buzzer_Low);
}
void Buzzer_TGL(void)
{
	DIO_TogglePinValue(Buzzer_PORT, Buzzer);
}