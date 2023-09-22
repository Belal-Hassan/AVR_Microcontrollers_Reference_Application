/*
 * LED1_Interface.c
 *
 * Created: 9/22/2023 9:09:06 AM
 *  Author: Belal Hassan
 */ 
#include <LED1_Private.h>

void LED1_Init(void)
{
	DIO_SetPinDirection(LED1_PORT, LED1, LED1_Output);
}
void LED1_ON(void)
{
	DIO_SetPinValue(LED1_PORT, LED1, LED1_High);
}
void LED1_OFF(void)
{
	DIO_SetPinValue(LED1_PORT, LED1, LED1_Low);
}
void LED1_TGL(void)
{
	DIO_TogglePinValue(LED1_PORT, LED1);
}