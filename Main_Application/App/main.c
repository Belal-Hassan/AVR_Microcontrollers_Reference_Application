/*
* main_files.c
*
* Created: 9/14/2023 3:12:58 PM
* Author : Belal Hassan
*/
#include <main.h>

int main(void)
{
	while (1)
	{
		for(int i = 20; i >= 0; i--)
		{
			if(i == 20)
			{
				LED0_Off();
				LED1_Off();
				LED2_On();
			}
			else if(i == 5)
			{
				LED0_Off();
				LED1_On();
				LED2_Off();
			}
			else if(i == 0)
			{
				LED0_On();
				LED1_Off();
				LED2_Off();
			}
			for(int j = 0; j <= 500; j+=10)
				SevenSegment_Display_Number(i);
		}
		for(int i = 20; i >= 0; i--)
			for(int j = 0; j <= 500; j+=10)
				SevenSegment_Display_Number(i);
	}
}

