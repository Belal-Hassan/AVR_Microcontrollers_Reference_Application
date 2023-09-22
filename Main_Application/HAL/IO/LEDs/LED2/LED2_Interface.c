/*
 * LED2_Interface.c
 *
 * Created: 9/22/2023 9:09:06 AM
 *  Author: Belal Hassan
 */ 
#include <LED2_Private.h>

void LED2_Init(void)
{
	DIO_SetPinDirection(LED2_PORT, LED2, LED2_Output);
}
void LED2_ON(void)
{
	DIO_SetPinValue(LED2_PORT, LED2, LED2_High);
}
void LED2_OFF(void)
{
	DIO_SetPinValue(LED2_PORT, LED2, LED2_Low);
}
void LED2_TGL(void)
{
	DIO_TogglePinValue(LED2_PORT, LED2);
}