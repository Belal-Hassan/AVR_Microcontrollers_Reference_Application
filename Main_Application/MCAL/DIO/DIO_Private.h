/*
 * DIO.h
 *
 * Created: 9/15/2023 2:53:42 AM
 *  Author: Belal Hassan
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#include <DIO_Configuration.h>

/*--------------------PINS--------------------*/
void DIO_SetPinDirection(port Port, pin Pin, state State);
void DIO_SetPinValue(port Port, pin Pin, status Status);
void DIO_TogglePinValue(port Port, pin Pin);
u8 DIO_GetPinValue(port port, pin Pin);
void DIO_SetPinPullUp(port Port, pin Pin);
/*-------------------NIBBLES-------------------*/
void DIO_SetNibbleDirection(port Port, nibble Nibble, state State);
void DIO_SetNibbleValue(port Port, nibble Nibble, status Status);
void DIO_WriteNibbleDirection(port Port, nibble Nibble, pin StartPin, pin EndPin, u8 Data);
void DIO_WriteNibbleValue(port Port, nibble Nibble, pin StartPin, pin EndPin, u8 Data);
void DIO_ToggleNibbleValue(port Port, nibble Nibble);
u8 DIO_GetNibbleValue(port Port, nibble Nibble);
void DIO_SetNibblePullUp(port Port, nibble Nibble);
void DIO_WriteNibblePullUp(port Port, nibble Nibble, pin StartPin, pin EndPin);
/*--------------------PORTS--------------------*/
void DIO_SetPortDirection(port Port, state State);
void DIO_SetPortValue(port Port, status Status);
void DIO_WritePortDirection(port Port, pin StartPin, pin EndPin, u8 Data);
void DIO_WritePortValue(port Port, pin StartPin, pin EndPin, u8 Data);
void DIO_TogglePortValue(port Port);
u8 DIO_GetPortValue(port Port);
void DIO_SetPortPullUp(port Port);
void DIO_WritePortPullUp(port Port, pin StartPin, pin EndPin);

#endif /* DIO_PRIVATE_H_ */