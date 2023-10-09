/*
 * LCD1602_8Bit_Configuration.h
 *
 * Created: 9/28/2023 5:09:12 PM
 *  Author: Belal hassan
 */ 


#ifndef LCD1602_8BIT_CONFIGURATION_H_
#define LCD1602_8BIT_CONFIGURATION_H_

#include <Peripheral_Libraries.h>

// Renaming PORTs
#define LCD1602_Control_PORT			DIO_PORTB
#define LCD1602_Data_PORT				DIO_PORTA
// Renaming PINs
#define LCD1602_RS_PIN					DIO_PIN1
#define LCD1602_RW_PIN					DIO_PIN2
#define LCD1602_Enable_PIN				DIO_PIN3
#define LCD1602_PIN_D0					DIO_PIN0
#define LCD1602_PIN_D1					DIO_PIN1
#define LCD1602_PIN_D2					DIO_PIN2
#define LCD1602_PIN_D3					DIO_PIN3
#define LCD1602_PIN_D4					DIO_PIN4
#define LCD1602_PIN_D5					DIO_PIN5
#define LCD1602_PIN_D6					DIO_PIN6
#define LCD1602_PIN_D7					DIO_PIN7
// Renaming States
#define LCD1602_Output					DIO_Output
#define LCD1602_Control_PORT_Output		0b00001110
// Renaming Status
#define LCD1602_High					DIO_High
#define LCD1602_Low						DIO_Low

#endif /* LCD1602_8BIT_CONFIGURATION_H_ */