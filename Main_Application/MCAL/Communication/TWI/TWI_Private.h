/*
 * TWI_Private.h
 *
 * Created: 11/27/2023 3:58:38 PM
 *  Author: Belal
 */ 


#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#include <TWI_Configuartion.h>

void TWI_Initialize(mode Mode, address Address, prescale Prescale);
void TWI_Slave_Address_Operation(address Address, operation Operation);
void TWI_Transmit_Character(address Address, u8 Character);
void TWI_Receive_Character(address Address, u8 *Character);
void TWI_Transmit_String(address Address, u8 *String);
void TWI_Receive_String(address Address, u8 *String);

#endif /* TWI_PRIVATE_H_ */