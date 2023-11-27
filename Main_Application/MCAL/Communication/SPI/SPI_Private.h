/*
 * SPI_Private.h
 *
 * Created: 11/27/2023 7:10:58 AM
 *  Author: Belal
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include <SPI_Configuration.h>

void SPI_Initialize(mode Mode, istatus Interrupt, freq Frequency);
void SPI_Transmit_Character(u8 Character);
void SPI_Receive_Character(u8 *Character);
void SPI_TranCeive_Character(u8 TCharacter, u8* RCharacter);
void SPI_Transmit_String(u8* String);
void SPI_Reveive_String(u8 *String);
void SPI_Slave_Select(slave Slave);

#endif /* SPI_PRIVATE_H_ */