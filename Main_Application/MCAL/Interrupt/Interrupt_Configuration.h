/*
 * Interrupt_Configuration.h
 *
 * Created: 11/10/2023 6:56:06 PM
 *  Author: Belal hassan
 */ 


#ifndef INTERRUPT_CONFIGURATION_H_
#define INTERRUPT_CONFIGURATION_H_

#include <Interrput_Addresses.h>

typedef enum
{
	Interrupt_Low = 0,
	Interrupt_Any,
	Interrupt_Falling,
	Interrupt_Rising	
}sense;

typedef enum
{
	Interrupt0 = 0,
	Interrupt1,
	Interrupt2
}interrupt;
/*
enum
{
	ISC00 = 0,
	ISC01,
	ISC10,
	ISC11
};
*/
#endif /* INTERRUPT_CONFIGURATION_H_ */