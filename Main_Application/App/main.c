/*
* main_files.c
*
* Created: 9/14/2023 3:12:58 PM
* Author : Belal Hassan
*/
#include <main.h>

int main(void)
{
	DC_Initialize(DC1);
	while (1)
	{
		for (int i = 0; i <= 100; i++)
		{
			DC_Speed(DC1, i);
			_delay_ms(1);
		}
		for (int i = 100; i >= 0; i--)
		{
			DC_Speed(DC1, i);
			_delay_ms(1);
		}
		for (int i = 0; i >= -100; i--)
		{
			DC_Speed(DC1, i);
			_delay_ms(1);
		}
		for (int i = -100; i <= 0; i++)
		{
			DC_Speed(DC1, i);
			_delay_ms(1);
		}
	}
}