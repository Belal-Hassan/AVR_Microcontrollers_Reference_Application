/*
 * Keypad_Configuration.h
 *
 * Created: 11/8/2023 12:36:07 PM
 *  Author: Belal hassan
 */ 


#ifndef KEYPAD_CONFIGURATION_H_
#define KEYPAD_CONFIGURATION_H_

#include <Peripheral_Libraries.h>

#define Keypad_PORT			DIO_PORTD

#define Keypad_Output0		DIO_PIN0
#define Keypad_Output1		DIO_PIN1
#define Keypad_Output2		DIO_PIN2
#define Keypad_Output3		DIO_PIN3

#define Keypad_Input0		DIO_PIN4
#define Keypad_Input1		DIO_PIN5
#define Keypad_Input2		DIO_PIN6
#define Keypad_Input3		DIO_PIN7

#define Keypad_Output		DIO_Output
#define Keypad_Input		DIO_Input

#define Keypad_Low			DIO_Low
#define Keypad_High			DIO_High

#define Keypad_PORT_Output	0b00001111
#define Keypad_PORT_Input	0b00000000
#define Keypad_PORT_High	0b00001111
#define Keypad_PORT_Low		0b00000000

#define StartRow			0
#define EndRow				3
#define StartColumn			4
#define EndColumn			7

#define Keypad_Pressed		0

#endif /* KEYPAD_CONFIGURATION_H_ */