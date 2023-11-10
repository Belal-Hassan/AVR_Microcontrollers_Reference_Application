/*
* Interrupt_Interface.c
*
* Created: 11/10/2023 6:56:39 PM
*  Author: Belal hassan
*/

#include <Interrupt_Private.h>

void External_Interrupt_Initialize(interrupt Interrupt, sense Sense)
{
	switch(Sense)
	{
		case Interrupt_Low:
		switch(Interrupt)
		{
			case Interrupt0:
			Clear_Bit(DDRD, 2);
			cli();
			Clear_Bit(MCUCR, ISC00);
			Clear_Bit(MCUCR, ISC01);
			Set_Bit(GICR, INT0);
			sei();
			break;
			case Interrupt1:
			Clear_Bit(DDRD, 3);
			cli();
			Clear_Bit(MCUCR, ISC10);
			Clear_Bit(MCUCR, ISC11);
			Set_Bit(GICR, INT1);
			sei();
			break;
			case Interrupt2:
			//#error "Interrupt 2 is an edge triggered interrupt."
			break;
			default:
			break;
		}
		break;
		case Interrupt_Any:
		switch(Interrupt)
		{
			case Interrupt0:
			Clear_Bit(DDRD, 2);
			cli();
			Set_Bit(MCUCR, ISC00);
			Clear_Bit(MCUCR, ISC01);
			Set_Bit(GICR, INT0);
			sei();
			break;
			case Interrupt1:
			Clear_Bit(DDRD, 3);
			cli();
			Set_Bit(MCUCR, ISC10);
			Clear_Bit(MCUCR, ISC11);
			Set_Bit(GICR, INT1);
			sei();
			break;
			case Interrupt2:
			//#error "Interrupt 2 is an edge triggered interrupt."
			break;
			default:
			break;
		}
		break;
		case Interrupt_Falling:
		switch(Interrupt)
		{
			case Interrupt0:
			Clear_Bit(DDRD, 2);
			cli();
			Clear_Bit(MCUCR, ISC00);
			Set_Bit(MCUCR, ISC01);
			Set_Bit(GICR, INT0);
			sei();
			break;
			case Interrupt1:
			Clear_Bit(DDRD, 3);
			cli();
			Clear_Bit(MCUCR, ISC10);
			Set_Bit(MCUCR, ISC11);
			Set_Bit(GICR, INT1);
			sei();
			break;
			case Interrupt2:
			Clear_Bit(DDRB, 2);
			cli();
			Clear_Bit(MCUCSR, ISC2);
			Set_Bit(GICR, INT2);
			sei();
			default:
			break;
		}
		break;
		case Interrupt_Rising:
		switch(Interrupt)
		{
			case Interrupt0:
			Clear_Bit(DDRD, 2);
			cli();
			Set_Bit(MCUCR, ISC00);
			Set_Bit(MCUCR, ISC01);
			Set_Bit(GICR, INT0);
			sei();
			break;
			case Interrupt1:
			Clear_Bit(DDRD, 3);
			cli();
			Set_Bit(MCUCR, ISC10);
			Set_Bit(MCUCR, ISC11);
			Set_Bit(GICR, INT1);
			sei();
			break;
			case Interrupt2:
			Clear_Bit(DDRB, 2);
			cli();
			Set_Bit(MCUCSR, ISC2);
			Set_Bit(GICR, INT2);
			sei();
			default:
			break;
		}
		break;
		default:
		break;
	}
}