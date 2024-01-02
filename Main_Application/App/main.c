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
	int i = -100;
	while (1)
	{
		for (i = -100; i <= 100; i++)
		{
			DC_Speed(DC1, i);
			_delay_ms(2);
		}
		for (i = 100; i >= -100; i--)
		{
			DC_Speed(DC1, i);
			_delay_ms(2);
		}
	}
}