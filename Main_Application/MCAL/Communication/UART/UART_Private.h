/*
 * UART_Private.h
 *
 * Created: 11/26/2023 4:42:29 PM
 *  Author: Belal
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include <UART_Configuration.h>

void UART_Initialize(istatus Interrupt, baudrate Baudrate, mode Mode, parity Parity, datalength Length, stopbits Bits);
void UART_Transmit_Character(u8 Character);
void UART_Receive_Character(u8* Character);
void UART_Transmit_String(u8* String);
void UART_Receive_String(u8* String);

#endif /* UART_PRIVATE_H_ */