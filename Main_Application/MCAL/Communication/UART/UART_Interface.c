/*
 * UART_Interface.c
 *
 * Created: 11/26/2023 4:42:44 PM
 *  Author: Belal
 */ 
#include <UART_Private.h>

void UART_Initialize(istatus Interrupt, baudrate Baudrate, mode Mode, parity Parity, datalength Length, stopbits Bits)
{
	u16 UBRR = 0;
	switch(Interrupt)
	{
		case UART_Interrupt:
		cli();
		Set_Bit(DDRD, PD0);
		Clear_Bit(DDRD, PD1);
		Set_Bit(SREG, I);
		Clear_Bit(UCSRA, U2X);
		Set_Bit(UCSRB, RXCIE);
		Set_Bit(UCSRB, TXCIE);
		Set_Bit(UCSRB, UDRIE);
		Set_Bit(UCSRB, RXEN);
		Set_Bit(UCSRB, TXEN);
		switch(Length)
		{
			case UART_5_Bits:
			Clear_Bit(UCSRC, UCSZ0);
			Clear_Bit(UCSRC, UCSZ1);
			Clear_Bit(UCSRB, UCSZ2);
			break;
			case UART_6_Bits:
			Set_Bit(UCSRC, UCSZ0);
			Clear_Bit(UCSRC, UCSZ1);
			Clear_Bit(UCSRB, UCSZ2);
			break;
			case UART_7_Bits:
			Clear_Bit(UCSRC, UCSZ0);
			Set_Bit(UCSRC, UCSZ1);
			Clear_Bit(UCSRB, UCSZ2);
			break;
			case UART_8_Bits:
			Set_Bit(UCSRC, UCSZ0);
			Set_Bit(UCSRC, UCSZ1);
			Clear_Bit(UCSRB, UCSZ2);
			break;
			case UART_9_Bits:
			Set_Bit(UCSRC, UCSZ0);
			Set_Bit(UCSRC, UCSZ1);
			Set_Bit(UCSRB, UCSZ2);
			break;
			default:
			break;
		}
		switch(Mode)
		{
			case UART_Asynchronous:
			Clear_Bit(UCSRC, UMSEL);
			break;
			case UART_Synchronous:
			Set_Bit(UCSRC, UMSEL);
			break;
			default:
			break;
		}
		switch(Parity)
		{
			case UART_Disabled:
			Clear_Bit(UCSRC, UPM0);
			Clear_Bit(UCSRC, UPM1);
			break;
			case UART_Even:
			Clear_Bit(UCSRC, UPM0);
			Set_Bit(UCSRC, UPM1);
			break;
			case UART_Odd:
			Set_Bit(UCSRC, UPM0);
			Set_Bit(UCSRC, UPM1);
			break;
			default:
			break;
		}
		switch(Bits)
		{
			case UART_1_Bit:
			Clear_Bit(UCSRC, USBS);
			break;
			case UART_2_Bits:
			Set_Bit(UCSRC, USBS);
			break;
			default:
			break;
		}
		UBRR = (FREQ / (16 * Baudrate)) - 1;
		UBRRL = UBRR;
		UBRRH = UBRR >> 8;
		sei();
		break;
		case UART_NoInterrupt:
		#define Istatus UART_NoInterrupt
		Set_Bit(DDRD, PD0);
		Clear_Bit(DDRD, PD1);
		Clear_Bit(UCSRA, U2X);
		Set_Bit(UCSRB, RXEN);
		Set_Bit(UCSRB, TXEN);
		switch(Length)
		{
			case UART_5_Bits:
			Clear_Bit(UCSRC, UCSZ0);
			Clear_Bit(UCSRC, UCSZ1);
			Clear_Bit(UCSRB, UCSZ2);
			break;
			case UART_6_Bits:
			Set_Bit(UCSRC, UCSZ0);
			Clear_Bit(UCSRC, UCSZ1);
			Clear_Bit(UCSRB, UCSZ2);
			break;
			case UART_7_Bits:
			Clear_Bit(UCSRC, UCSZ0);
			Set_Bit(UCSRC, UCSZ1);
			Clear_Bit(UCSRB, UCSZ2);
			break;
			case UART_8_Bits:
			Set_Bit(UCSRC, UCSZ0);
			Set_Bit(UCSRC, UCSZ1);
			Clear_Bit(UCSRB, UCSZ2);
			break;
			case UART_9_Bits:
			Set_Bit(UCSRC, UCSZ0);
			Set_Bit(UCSRC, UCSZ1);
			Set_Bit(UCSRB, UCSZ2);
			break;
			default:
			break;
		}
		switch(Mode)
		{
			case UART_Asynchronous:
			Clear_Bit(UCSRC, UMSEL);
			break;
			case UART_Synchronous:
			Set_Bit(UCSRC, UMSEL);
			break;
			default:
			break;
		}
		switch(Parity)
		{
			case UART_Disabled:
			Clear_Bit(UCSRC, UPM0);
			Clear_Bit(UCSRC, UPM1);
			break;
			case UART_Even:
			Clear_Bit(UCSRC, UPM0);
			Set_Bit(UCSRC, UPM1);
			break;
			case UART_Odd:
			Set_Bit(UCSRC, UPM0);
			Set_Bit(UCSRC, UPM1);
			break;
			default:
			break;
		}
		switch(Bits)
		{
			case UART_1_Bit:
			Clear_Bit(UCSRC, USBS);
			break;
			case UART_2_Bits:
			Set_Bit(UCSRC, USBS);
			break;
			default:
			break;
		}
		UBRR = (FREQ / (16 * Baudrate)) - 1;
		UBRRL = UBRR;
		UBRRH = UBRR >> 8;
		break;
		default:
		break;
	}
}
void UART_Transmit_Character(u8 Character)
{
	if(Istatus == UART_NoInterrupt)
	{
		while (!Get_Bit(UCSRA, UDRE));
		UDR = Character;
		while (!Get_Bit(UCSRA, TXC));
	}
	else
		UDR = Character;
}
void UART_Receive_Character(u8 *Character)
{
	if(Istatus == UART_NoInterrupt)
	{
		while (!Get_Bit(UCSRA, RXC));
		*Character = UDR;	
	}
	else
		*Character = UDR;
}
void UART_Transmit_String(u8* String)
{
	u8 i = 0;
	while(String[i] != '\0')
		UART_Transmit_Character(String[i++]);
}
void UART_Receive_String(u8* String)
{
	u8 i = 0;
	do
	{
		UART_Receive_String((String + i));
	} while (String[i++] != '\0');
}