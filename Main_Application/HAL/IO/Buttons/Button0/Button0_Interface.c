/*
 * Button0_Interface.c
 *
 * Created: 9/30/2023 1:53:18 AM
 *  Author: Belal hassan
 */ 
#include <Button0_Private.h>

void Button0_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		DIO_SetPinDirection(Button0_PORT, Button0_PIN, Button0_Input);
		Initialized = true;	
	}
}
bool Button0_Read(void)
{
	Button0_Initialize();
	return DIO_GetPinValue(Button0_PORT, Button0_PIN);
}