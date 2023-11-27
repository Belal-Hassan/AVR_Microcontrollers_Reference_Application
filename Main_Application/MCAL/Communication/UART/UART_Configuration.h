/*
 * UART_Configuration.h
 *
 * Created: 11/26/2023 4:42:17 PM
 *  Author: Belal
 */ 


#ifndef UART_CONFIGURATION_H_
#define UART_CONFIGURATION_H_

#include <UART_Addresses.h>

#define FREQ	160000
#define I		7	

typedef enum
{
	UART_9600 = 96,
	UART_38400 = 384,
	UART_115200 = 1152
}baudrate;

typedef enum
{
	UART_Asynchronous = 0,
	UART_Synchronous
}mode;

typedef enum
{
	UART_Disabled = 0,
	UART_Even,
	UART_Odd
}parity;

typedef enum
{
	UART_1_Bit = 0,
	UART_2_Bits
}stopbits;

typedef enum
{
	UART_5_Bits = 0,
	UART_6_Bits,
	UART_7_Bits,
	UART_8_Bits,
	UART_9_Bits
}datalength;

typedef enum
{
	UART_NOK = 0,
	UART_OK = 1
}status;

typedef enum
{
	UART_Interrupt = 0,
	UART_NoInterrupt
}istatus;

#define Istatus UART_Interrupt

#endif /* UART_CONFIGURATION_H_ */