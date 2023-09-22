/*
 * LED0_Interface.c
 *
 * Created: 9/22/2023 9:09:06 AM
 *  Author: Belal Hassan
 */ 
#include <LED0_Private.h>

void LED0_Init(void)
{
	DIO_SetPinDirection(LED0_PORT, LED0, LED0_Output);
}
void LED0_ON(void)
{
	DIO_SetPinValue(LED0_PORT, LED0, LED0_High);
}
void LED0_OFF(void)
{
	DIO_SetPinValue(LED0_PORT, LED0, LED0_Low);
}
void LED0_TGL(void)
{
	DIO_TogglePinValue(LED0_PORT, LED0);
}