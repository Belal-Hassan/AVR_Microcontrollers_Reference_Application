/*
 * Keypad_Interface.c
 *
 * Created: 11/8/2023 12:36:41 PM
 *  Author: Belal hassan
 */ 

#include <Keypad_Private.h>

const u8 Keypad_Characters[4][4] = {{'7','8','9','/'},
									{'4','5','6','*'},
									{'1','2','3','-'},
									{'C','0','=','+'}};
void Keypad_Initialize(void)
{
	static bool Initialized = false;
	if(!Initialized)
	{
		//Define direction as output
		DIO_WritePortDirection(Keypad_PORT, Keypad_Output0, Keypad_Output3, Keypad_PORT_Output);
		//Ensure that we are in initialize state
		DIO_WritePortValue(Keypad_PORT, Keypad_Output0, Keypad_Output3, Keypad_PORT_High);
		//Define direction as input
		DIO_WritePortDirection(Keypad_PORT, Keypad_Input0, Keypad_Input3, Keypad_PORT_Input);
		//Pull-Up activation
		DIO_WritePortPullUp(Keypad_PORT, Keypad_Input0, Keypad_Input3);
		Initialized = true;
	}
}
u8 Keypad_Read(void)
{
	Keypad_Initialize();
	u8 CurrentRow, CurrentColumn, Character = 0, Value = 0;
	for(CurrentRow = StartRow; CurrentRow <= EndRow; CurrentRow++)
	{
		DIO_SetPinValue(Keypad_PORT, CurrentRow, Keypad_Low);
		for(CurrentColumn = StartColumn; CurrentColumn <= EndColumn; CurrentColumn++)
		{
			Value = DIO_GetPinValue(Keypad_PORT, CurrentColumn);
			if(Value == Keypad_Pressed)
			{
				Character = Keypad_Characters[CurrentRow][CurrentColumn - StartColumn];
				while(Value == Keypad_Pressed)
					Value = DIO_GetPinValue(Keypad_PORT, CurrentColumn);
				_delay_ms(5);
			}
		}
		DIO_SetPinValue(Keypad_PORT, CurrentRow, Keypad_High);
	}
	return Character;
}