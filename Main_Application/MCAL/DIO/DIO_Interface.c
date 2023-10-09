/*
* DIO.c
*
* Created: 9/15/2023 2:58:34 AM
*  Author: Belal Hassan
*/
#include <DIO_Private.h>

/*------------------------------PINS------------------------------*/
void DIO_SetPinDirection(port Port, pin Pin, state State)
{
	switch(Port)
	{
		case DIO_PORTA:
		if(State == DIO_Input)
		Clear_Bit(DDRA, Pin);
		else
		Set_Bit(DDRA, Pin);
		break;
		case DIO_PORTB:
		if(State == DIO_Input)
		Clear_Bit(DDRB, Pin);
		else
		Set_Bit(DDRB, Pin);
		break;
		case DIO_PORTC:
		if(State == DIO_Input)
		Clear_Bit(DDRC, Pin);
		else
		Set_Bit(DDRC, Pin);
		break;
		case DIO_PORTD:
		if(State == DIO_Input)
		Clear_Bit(DDRD, Pin);
		else
		Set_Bit(DDRD, Pin);
		break;
		defult:
		break;
	}
}
void DIO_SetPinValue(port Port, pin Pin, status Status)
{
	switch(Port)
	{
		case DIO_PORTA:
		if(Status == DIO_Low) Clear_Bit(PORTA, Pin);
		else
		Set_Bit(PORTA, Pin);
		break;
		case DIO_PORTB:
		if(Status == DIO_Low)
		Clear_Bit(PORTB, Pin);
		else
		Set_Bit(PORTB, Pin);
		break;
		case DIO_PORTC:
		if(Status == DIO_Low)
		Clear_Bit(PORTC, Pin);
		else
		Set_Bit(PORTC, Pin);
		break;
		case DIO_PORTD:
		if(Status == DIO_Low)
		Clear_Bit(PORTD, Pin);
		else
		Set_Bit(PORTD, Pin);
		break;
		defult:
		break;
	}
}
void DIO_TogglePinValue(port Port, pin Pin)
{
	switch(Port)
	{
		case DIO_PORTA:
		Toggle_Bit(PORTA, Pin);
		break;
		case DIO_PORTB:
		Toggle_Bit(PORTB, Pin);
		break;
		case DIO_PORTC:
		Toggle_Bit(PORTC, Pin);
		break;
		case DIO_PORTD:
		Toggle_Bit(PORTD, Pin);
		break;
		defult:
		break;
	}
}
u8 DIO_GetPinValue(port Port, pin Pin)
{
	switch(Port)
	{
		case DIO_PORTA:
		return Get_Bit(PINA, Pin);
		case DIO_PORTB:
		return Get_Bit(PINB, Pin);
		case DIO_PORTC:
		return Get_Bit(PINC, Pin);
		case DIO_PORTD:
		return Get_Bit(PIND, Pin);
		defult:
		return 0;
	}
	return 0;
}
void DIO_SetPinPullUp(port Port, pin Pin)
{
	switch(Port)
	{
		case DIO_PORTA:
		Set_Bit(PORTA, Pin);
		break;
		case DIO_PORTB:
		Set_Bit(PORTB, Pin);
		break;
		case DIO_PORTC:
		Set_Bit(PORTC, Pin);
		break;
		case DIO_PORTD:
		Set_Bit(PORTD, Pin);
		break;
		default:
		break;
	}
}
/*------------------------------PORTS------------------------------*/
void DIO_SetPortDirection(port Port, state State)
{
	switch(Port)
	{
		case DIO_PORTA:
		if(State == DIO_Input)
		DDRA = DIO_PORT_Input;
		else
		DDRA = DIO_PORT_Output;
		break;
		case DIO_PORTB:
		if(State == DIO_Input)
		DDRB = DIO_PORT_Input;
		else
		DDRB = DIO_PORT_Output;
		break;
		case DIO_PORTC:
		if(State == DIO_Input)
		DDRC = DIO_PORT_Input;
		else
		DDRC = DIO_PORT_Output;
		break;
		case DIO_PORTD:
		if(State == DIO_Input)
		DDRD = DIO_PORT_Input;
		else
		DDRD = DIO_PORT_Output;
		break;
		defult:
		break;
	}
}
void DIO_SetPortValue(port Port, status Status)
{
	switch(Port)
	{
		case DIO_PORTA:
		if(Status == DIO_Low)
		PORTA = DIO_PORT_Low;
		else
		PORTA = DIO_PORT_High;
		break;
		case DIO_PORTB:
		if(Status == DIO_Low)
		PORTB = DIO_PORT_Low;
		else
		PORTB = DIO_PORT_High;
		break;
		case DIO_PORTC:
		if(Status == DIO_Low)
		PORTC = DIO_PORT_Low;
		else
		PORTC = DIO_PORT_High;
		break;
		case DIO_PORTD:
		if(Status == DIO_Low)
		PORTD = DIO_PORT_Low;
		else
		PORTD = DIO_PORT_High;
		break;
		defult:
		break;
	}
}
void DIO_WritePortDirection(port Port, pin StartPin, pin EndPin, u8 Data)
{
	u8 Mask = ((1 << (EndPin - StartPin + 1)) - 1) << StartPin, PlaceHolder;
	switch(Port)
	{
		case DIO_PORTA:
		PlaceHolder = DDRA;
		PlaceHolder &= ~Mask;
		PlaceHolder |= Data & Mask;
		DDRA = PlaceHolder;
		break;
		case DIO_PORTB:
		PlaceHolder = DDRB;
		PlaceHolder &= ~Mask;
		PlaceHolder |= Data & Mask;
		DDRB = PlaceHolder;
		break;
		case DIO_PORTC:
		PlaceHolder = DDRC;
		PlaceHolder &= ~Mask;
		PlaceHolder |= Data & Mask;
		DDRC = PlaceHolder;
		break;
		case DIO_PORTD:
		PlaceHolder = DDRD;
		PlaceHolder &= ~Mask;
		PlaceHolder |= Data & Mask;
		DDRD = PlaceHolder;
		break;
		default:
		break;
	}
}
void DIO_WritePortValue(port Port, pin StartPin, pin EndPin, u8 Data)
{
	u8 Mask = ((1 << (EndPin - StartPin + 1)) - 1) << StartPin, PlaceHolder;
	switch(Port)
	{
		case DIO_PORTA:
		PlaceHolder = PORTA;
		PlaceHolder &= ~Mask;
		PlaceHolder |= Data & Mask;
		PORTA = PlaceHolder;
		break;
		case DIO_PORTB:
		PlaceHolder = PORTB;
		PlaceHolder &= ~Mask;
		PlaceHolder |= Data & Mask;
		PORTB = PlaceHolder;
		break;
		case DIO_PORTC:
		PlaceHolder = PORTC;
		PlaceHolder &= ~Mask;
		PlaceHolder |= Data & Mask;
		PORTC = PlaceHolder;
		break;
		case DIO_PORTD:
		PlaceHolder = PORTD;
		PlaceHolder &= ~Mask;
		PlaceHolder |= Data & Mask;
		PORTD = PlaceHolder;
		break;
		default:
		break;
	}
}
void DIO_TogglePortValue(port Port)
{
	switch(Port)
	{
		case DIO_PORTA:
		PORTA ^= DIO_PORT_High;
		break;
		case DIO_PORTB:
		PORTB ^= DIO_PORT_High;
		break;
		case DIO_PORTC:
		PORTC ^= DIO_PORT_High;
		break;
		case DIO_PORTD:
		PORTD ^= DIO_PORT_High;
		break;
		defult:
		break;
	}
}
u8 DIO_GetPortValue(port Port)
{
	switch(Port)
	{
		case DIO_PORTA:
		return PINA;
		case DIO_PORTB:
		return PINB;
		case DIO_PORTC:
		return PINC;
		case DIO_PORTD:
		return PIND;
		break;
		defult:
		return 0;
	}
	return 0;
}
void DIO_SetPortPullUp(port Port)
{
	switch(Port)
	{
		case DIO_PORTA:
		PORTA = DIO_PORT_High;
		break;
		case DIO_PORTB:
		PORTB = DIO_PORT_High;
		break;
		case DIO_PORTC:
		PORTC = DIO_PORT_High;
		break;
		case DIO_PORTD:
		PORTD = DIO_PORT_High;
		break;
		default:
		break;
	}
}