/*
 * SevenSegment_Anode_Configuration.h
 *
 * Created: 9/24/2023 6:26:21 PM
 *  Author: Belal hassan
 */ 


#ifndef SEVENSEGMENT_ANODE_CONFIGURATION_H_
#define SEVENSEGMENT_ANODE_CONFIGURATION_H_

#include <Peripheral_Libraries.h>

// Renaming PORTs
#define SevenSegment_PORT			DIO_PORTA
// Renaming PINs
#define SevenSegment_PIN_A			DIO_PIN0
#define SevenSegment_PIN_B			DIO_PIN1
#define SevenSegment_PIN_C			DIO_PIN2
#define SevenSegment_PIN_D			DIO_PIN3
#define SevenSegment_PIN_E			DIO_PIN4
#define SevenSegment_PIN_F			DIO_PIN5
#define SevenSegment_PIN_G			DIO_PIN6
#define SevenSegment_PIN_DP 		DIO_PIN7
// Renaming States
#define SevenSegment_Output			DIO_Output
// Renaming Status
#define SevenSegment_High			DIO_Low
#define SevenSegment_Low			DIO_High
#define SevenSegment_Number_0		~0b00111111
#define SevenSegment_Number_1		~0b00000110
#define SevenSegment_Number_2		~0b01011011
#define SevenSegment_Number_3		~0b01001111
#define SevenSegment_Number_4		~0b01100110
#define SevenSegment_Number_5		~0b01101101
#define SevenSegment_Number_6		~0b01111101
#define SevenSegment_Number_7		~0b00000111
#define SevenSegment_Number_8		~0b01111111
#define SevenSegment_Number_9		~0b01101111
#define SevenSegment_Character_a	~0b01011111
#define SevenSegment_Character_b	~0b01111100
#define SevenSegment_Character_c	~0b00111100
#define SevenSegment_Character_d	~0b01011110
#define SevenSegment_Character_e	~0b01111011
#define SevenSegment_Character_f	~0b01110001

#endif /* SEVENSEGMENT_ANODE_CONFIGURATION_H_ */