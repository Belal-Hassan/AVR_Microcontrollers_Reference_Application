/*
* main_files.c
*
* Created: 9/14/2023 3:12:58 PM
* Author : Belal Hassan
*/
#include <main.h>

int main(void)
{
	LCD_Initialize();
	External_Interrupt_Initialize(Interrupt1, Interrupt_Rising);
	while(1)
	{
		for(u8 y = 'A'; y <= 'Z'; y++)
		{
			LCD_Display_Character(y);
			_delay_ms(10);
		}
		LCD_ClearScreen();
	}
}

ISR(INT1_vect)
{
	LCD_ClearScreen();
	for(u8 x = 'a'; x <= 'z'; x++)
	{
		LCD_Display_Character(x);
		_delay_ms(10);
	}
	LCD_ClearScreen();
}