/*
 * UART_Addresses.h
 *
 * Created: 7/26/2024 11:12:04 PM
 *  Author: Belal
 */ 


#ifndef UART_ADDRESSES_H_
#define UART_ADDRESSES_H_

#define UDR		(*(volatile u8 *)0x2C)
#define UCSRA	(*(volatile u8 *)0x2B)
#define UCSRB	(*(volatile u8 *)0x2A)
#define UBRRH	(*(volatile u8 *)0x29)
#define UCSRC	(*(volatile u8 *)0x40)
#define UBRRH	(*(volatile u8 *)0x40)

#endif /* UART_ADDRESSES_H_ */