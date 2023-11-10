/*
* SPI_Configuration.h
*
* Created: 11/3/2023 11:15:20 AM
*  Author: Belal hassan
*/


#ifndef SPI_CONFIGURATION_H_
#define SPI_CONFIGURATION_H_

#include <SPI_Address.h>
//Pins
#define MOSI	PB5
#define MISO	PB6
#define SCK		PB7
#define SS		PB4
typedef enum
{
	SPI_Slave_1 = 0,
	SPI_Slave_2,
	SPI_Slave_3,
	SPI_Slave_4,
	SPI_Slave_5,
	SPI_Slave_6,
	SPI_Slave_7,
	SPI_Slave_8,
	SPI_Slave_9,
	SPI_Slave_10,
	SPI_Slave_11,
	SPI_Slave_12,
	SPI_Slave_13,
	SPI_Slave_14,
	SPI_Slave_15,
	SPI_Slave_16,
	SPI_Slave_17,
	SPI_Slave_18,
	SPI_Slave_19,
	SPI_Slave_20,
	SPI_Slave_21,
	SPI_Slave_22,
	SPI_Slave_23,
	SPI_Slave_24,
	SPI_Slave_25,
	SPI_Slave_26,
	SPI_Slave_27,
	SPI_Slave_28,
	SPI_Slave_29
}slave;
typedef enum
{
	SPI_OK = 0,
	SPI_NON
}status;

#endif /* SPI_CONFIGURATION_H_ */