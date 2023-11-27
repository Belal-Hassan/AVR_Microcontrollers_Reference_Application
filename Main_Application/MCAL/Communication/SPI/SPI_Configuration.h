/*
 * SPI_Configuration.h
 *
 * Created: 11/27/2023 7:10:36 AM
 *  Author: Belal
 */ 


#ifndef SPI_CONFIGURATION_H_
#define SPI_CONFIGURATION_H_

#include <SPI_Addresses.h>

#define MOSI 5
#define MISO 6
#define SCK	 7
#define SS	 4

typedef enum
{
	SPI_4 = 0,
	SPI_16,
	SPI_64,
	SPI_128,
	SPI_2,
	SPI_8,
	SPI_32,
}freq;

typedef enum
{
	SPI_Slave1 = 0,
	SPI_Slave2,
	SPI_Slave3
}slave;

typedef enum
{
	SPI_Master = 0,
	SPI_Slave = 1
}mode;

typedef enum
{
	SPI_Interrupt = 0,
	SPI_NoInterrupt
}istatus;

#define Istatus SPI_Interrupt

#endif /* SPI_CONFIGURATION_H_ */