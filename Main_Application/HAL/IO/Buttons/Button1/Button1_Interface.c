/*
 * Button1_Interface.c
 *
 * Created: 9/30/2023 1:53:18 AM
 *  Author: Belal hassan
 */ 
#include <Button1_Private.h>

void Button1_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		DIO_SetPinDirection(Button1_PORT, Button1_PIN, Button1_Input);
		Initialized = true;	
	}
}
bool Button1_Read(void)
{
	Button1_Initialize();
	return DIO_GetPinValue(Button1_PORT, Button1_PIN);
}