/*
 * SPI_Private.h
 *
 * Created: 11/3/2023 11:15:41 AM
 *  Author: Belal hassan
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

#include <SPI_Configuration.h>

status SPI_Master_Initialize(void);
status SPI_Slave_Initialize(void);

status SPI_Transmit_Character(u8 Character);
status SPI_Receive_Character(u8* Character);

status 

#endif /* SPI_PRIVATE_H_ */