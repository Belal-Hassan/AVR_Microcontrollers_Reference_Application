/*
 * Button2_Interface.c
 *
 * Created: 9/30/2023 1:53:18 AM
 *  Author: Belal hassan
 */ 
#include <Button2_Private.h>

void Button2_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		DIO_SetPinDirection(Button2_PORT, Button2_PIN, Button2_Input);
		Initialized = true;	
	}
}
bool Button2_Read(void)
{
	Button2_Initialize();
	return DIO_GetPinValue(Button2_PORT, Button2_PIN);
}