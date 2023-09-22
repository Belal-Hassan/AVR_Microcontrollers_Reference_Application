/*
 * Relay_Interface.c
 *
 * Created: 9/22/2023 9:09:06 AM
 *  Author: Belal Hassan
 */ 
#include <Relay_Private.h>

void Relay_Init(void)
{
	DIO_SetPinDirection(Relay_PORT, Relay, Relay_Output);
}
void Relay_ON(void)
{
	DIO_SetPinValue(Relay_PORT, Relay, Relay_High);
}
void Relay_OFF(void)
{
	DIO_SetPinValue(Relay_PORT, Relay, Relay_Low);
}
void Relay_TGL(void)
{
	DIO_TogglePinValue(Relay_PORT, Relay);
}