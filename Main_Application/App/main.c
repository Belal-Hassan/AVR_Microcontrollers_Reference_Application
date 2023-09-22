/*
* main_files.c
*
* Created: 9/14/2023 3:12:58 PM
* Author : Belal Hassan
*/

#include <main.h>

int main(void)
{
	LED0_Init();
	LED1_Init();
	LED2_Init();
	while (1)
	{
		LED0_ON();
		LED1_OFF();
		LED2_OFF();
		_delay_ms(500);
		LED0_OFF();
		LED1_ON();
		LED2_OFF();
		_delay_ms(500);
		LED0_ON();
		LED1_ON();
		LED2_OFF();
		_delay_ms(500);
		LED0_OFF();
		LED1_OFF();
		LED2_ON();
		_delay_ms(500);
		LED0_ON();
		LED1_OFF();
		LED2_ON();
		_delay_ms(500);
		LED0_OFF();
		LED1_ON();
		LED2_ON();
		_delay_ms(500);
		LED0_ON();
		LED1_ON();
		LED2_ON();
		_delay_ms(500);
		LED0_OFF();
		LED1_OFF();
		LED2_OFF();
		_delay_ms(500);
	}
}

