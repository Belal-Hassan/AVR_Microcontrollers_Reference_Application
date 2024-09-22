/*
 * UART_Configuration.h
 *
 * Created: 7/26/2024 11:11:49 PM
 *  Author: Belal
 */ 


#ifndef UART_CONFIGURATION_H_
#define UART_CONFIGURATION_H_

//#include <UART_Addresses.h>
#include <Peripheral_Libraries.h>

bool receiveInterruptEnabled;
bool transmitInterruptEnabled;
bool dataSize9Bits;

typedef enum{
	receiver = 0,
	transmitter,
	transceiver
}transmode;

typedef enum{
	asyncronousNormal = 0,
	asyncronousDouble,
	syncronous
}syncmode;

typedef enum{
	disabledParity = 0,
	evenParity,
	oddParity
}parity;

typedef enum{
	stop1bit = 0,
	stop2bits
}stopbits;

typedef enum{
	size5bits = 0,
	size6bits,
	size7bits,
	size8bits,
	size9bits
}datasize;

typedef enum{
	noInterrupt = 0,
	receiveInterrupt,
	transmitInterrupt,
	emptyInterrupt,
	receiveTransmitInterrupt,
	receiveEmptyInterrupt,
	transmitEmptyInterrupt,
	allInterrupts
}interrupt;

typedef struct Interrupts{
	void (*RxCallbackPointer)(void);
	void (*TxCallbackPointer)(void);
	void (*EmptyCallbackPointer)(void);
}callbackInterrupts;

typedef enum{
	transmitManual = 0,
	transmitAfterInterrupt
}transmitAfter;

typedef enum{
	noError = 0,
	frameError,
	overRunError,
	parityError
}error;

#endif /* UART_CONFIGURATION_H_ */