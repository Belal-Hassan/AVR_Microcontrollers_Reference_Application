/*
 * DIO_CONFIGURATION.h
 *
 * Created: 9/14/2023 4:03:11 PM
 *  Author: Belal Hassan
 */ 


#ifndef DIO_CONFIGURATION_H_
#define DIO_CONFIGURATION_H_

#include <Peripheral_Libraries.h>
//#include <DIO_Addresses.h>

typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}port;

typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7 
}pin;

typedef enum
{
	DIO_Input = 0,
	DIO_Output
}state;

typedef enum
{
	DIO_Low = 0,	
	DIO_High
}status;

#define DIO_PORT_Input 0x00
#define DIO_PORT_Output 0xff
#define DIO_PORT_Low 0x00
#define DIO_PORT_High 0xff

#endif /* DIO_CONFIGURATION_H_ */