/*
* main_files.c
*
* Created: 9/14/2023 3:12:58 PM
* Author : Belal Hassan
*/
#include <main.h>

int main(void)
{
	u8 Heart[] = {
		0b00000,
		0b01010,
		0b10101,
		0b10001,
		0b01010,
		0b00100,
		0b00000,
		0b00000
	};
	LCD_Initialize();
	LCD_Display_String("After ");
	LCD_Display_FloatNumber(7393.97, 2);
	LCD_Display_Location(0, 1);
	LCD_Display_String("tries,I did it!");
	while (1)
	{
		LCD_Send_Command(LCD_Command_DisplayRight);
		_delay_ms(10);
		LCD_Send_Command(LCD_Command_DisplayLeft);
		_delay_ms(10);
	}
}

