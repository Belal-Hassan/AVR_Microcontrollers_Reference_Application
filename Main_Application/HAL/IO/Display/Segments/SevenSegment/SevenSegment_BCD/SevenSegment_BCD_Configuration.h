/*
 * SevenSegment_BCD_Configuration.h
 *
 * Created: 9/24/2023 5:16:46 PM
 *  Author: Belal hassan
 */ 


#ifndef SEVENSEGMENT_BCD_CONFIGURATION_H_
#define SEVENSEGMENT_BCD_CONFIGURATION_H_

#include <Peripheral_Libraries.h>

// Renaming PORTs
#define SevenSegment_Control_PORT			DIO_PORTB
#define SevenSegment_Data_PORT				DIO_PORTA
// Renaming PINs
#define SevenSegment_Enable_1_PIN			DIO_PIN1
#define SevenSegment_Enable_2_PIN			DIO_PIN2
#define SevenSegment_Enable_DP_PIN			DIO_PIN3
#define SevenSegment_PIN_A					DIO_PIN4
#define SevenSegment_PIN_B					DIO_PIN5
#define SevenSegment_PIN_C					DIO_PIN6
#define SevenSegment_PIN_D					DIO_PIN7
// Renaming States
#define SevenSegment_Output					DIO_Output
#define SevenSegment_Control_PORT_Output	0b00001110
#define SevenSegment_Data_PORT_Output		0b11110000
// Renaming Status 
#define SevenSegment_High					DIO_High
#define SevenSegment_Low					DIO_Low

#endif /* SEVENSEGMENT_BCD_CONFIGURATION_H_ */