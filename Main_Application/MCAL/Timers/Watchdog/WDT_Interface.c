/*
* WDT_Interface.c
*
* Created: 11/27/2023 8:53:30 PM
*  Author: Belal
*/
#include <WDT_Private.h>

void WDT_Initialization(void)
{
	Set_Bit(WDTCR, WDTOE);
	Set_Bit(WDTCR, WDE);
}

void WDT_Start(voltage Voltage, prescale3v Prescale3V, prescale5v Prescale5V)
{
	switch (Voltage)
	{
		case WDT_3V:
		switch (Prescale3V)
		{
			case WDT_17ms:
			Clear_Bit(WDTCR, WDP2);
			Clear_Bit(WDTCR, WDP1);
			Clear_Bit(WDTCR, WDP0);
			break;
			case WDT_34ms:
			Clear_Bit(WDTCR, WDP2);
			Clear_Bit(WDTCR, WDP1);
			Set_Bit(WDTCR, WDP0);
			break;
			case WDT_68ms:
			Clear_Bit(WDTCR, WDP2);
			Set_Bit(WDTCR, WDP1);
			Clear_Bit(WDTCR, WDP0);
			break;
			case WDT_140ms:
			Clear_Bit(WDTCR, WDP2);
			Set_Bit(WDTCR, WDP1);
			Set_Bit(WDTCR, WDP0);
			break;
			case WDT_270ms:
			Set_Bit(WDTCR, WDP2);
			Clear_Bit(WDTCR, WDP1);
			Clear_Bit(WDTCR, WDP0);
			break;
			case WDT_550ms:
			Set_Bit(WDTCR, WDP2);
			Clear_Bit(WDTCR, WDP1);
			Set_Bit(WDTCR, WDP0);
			break;
			case WDT_1100ms:
			Set_Bit(WDTCR, WDP2);
			Set_Bit(WDTCR, WDP1);
			Clear_Bit(WDTCR, WDP0);
			break;
			case WDT_2200ms:
			Set_Bit(WDTCR, WDP2);
			Set_Bit(WDTCR, WDP1);
			Set_Bit(WDTCR, WDP0);
			break;
		}
		break;
		case WDT_5V:
		switch (Prescale5V)
		{
			case WDT_16ms:
			Clear_Bit(WDTCR, WDP2);
			Clear_Bit(WDTCR, WDP1);
			Clear_Bit(WDTCR, WDP0);
			break;
			case WDT_32ms:
			Clear_Bit(WDTCR, WDP2);
			Clear_Bit(WDTCR, WDP1);
			Set_Bit(WDTCR, WDP0);
			break;
			case WDT_65ms:
			Clear_Bit(WDTCR, WDP2);
			Set_Bit(WDTCR, WDP1);
			Clear_Bit(WDTCR, WDP0);
			break;
			case WDT_130ms:
			Clear_Bit(WDTCR, WDP2);
			Set_Bit(WDTCR, WDP1);
			Set_Bit(WDTCR, WDP0);
			break;
			case WDT_260ms:
			Set_Bit(WDTCR, WDP2);
			Clear_Bit(WDTCR, WDP1);
			Clear_Bit(WDTCR, WDP0);
			break;
			case WDT_520ms:
			Set_Bit(WDTCR, WDP2);
			Clear_Bit(WDTCR, WDP1);
			Set_Bit(WDTCR, WDP0);
			break;
			case WDT_1000ms:
			Set_Bit(WDTCR, WDP2);
			Set_Bit(WDTCR, WDP1);
			Clear_Bit(WDTCR, WDP0);
			break;
			case WDT_2100ms:
			Set_Bit(WDTCR, WDP2);
			Set_Bit(WDTCR, WDP1);
			Set_Bit(WDTCR, WDP0);
			break;
		}
		break;
	}
}
void WDT_Timer_Refresh(void)
{
	asm("WDR");
}