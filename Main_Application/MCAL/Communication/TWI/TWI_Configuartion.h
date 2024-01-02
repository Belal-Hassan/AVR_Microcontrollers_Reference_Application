/*
 * TWI_Configuartion.h
 *
 * Created: 11/27/2023 3:57:50 PM
 *  Author: Belal
 */ 


#ifndef TWI_CONFIGUARTION_H_
#define TWI_CONFIGUARTION_H_

#include <TWI_Addresses.h>

#define TWGCE 0

typedef enum
{
	TWI_Slave = 0,
	TWI_Master
}mode;

typedef enum
{
	TWI_PRE_1 = 0,
	TWI_PRE_4,
	TWI_PRE_16,
	TWI_PRE_64
}prescale;

typedef enum
{
	TWI_Write = 0,
	TWI_Read = 1
}operation;

typedef enum
{
	TWI_General = 0,
	TWI_Slave_1,
	TWI_Slave_2,
	TWI_Slave_3,
	TWI_Slave_4,
	TWI_Slave_5
}address;

#define Status_Mask						0xF8
#define Start_ACK						0x08 // Start has been transmitted
#define REP_Start_ACK					0x10 // Repeated start has been transmitted
#define Stop_ACK						0xA0 // Stop has been transmitted
#define Slave_Add_Write_ACK				0x18 // Slave address + Write transmitted acknowledgment has been received
#define Slave_Add_Write_NOACK			0x20 // Slave address + Write transmitted acknowledgment has not been received
#define Slave_Add_Read_ACK				0x40 // Slave address + Read transmitted acknowledgment has been received
#define Slave_Add_Read_NOACK			0x48 // Slave address + Read transmitted acknowledgment has not been received
#define Write_Byte_ACK					0x28 // Data byte + Write transmitted acknowledgment has been received
#define Write_Byte_NOACK				0x30 // Data byte + Write transmitted acknowledgment has not been received
#define Read_Byte_ACK					0x50 // Data byte + Write transmitted acknowledgment has been received
#define Read_Byte_NOACK					0x58 // Data byte + Write transmitted acknowledgment has not been received
#define Slave_Add_Received_Write_REQ    0x60 // Slave received + Write own address acknowledgment has been received
#define Slave_Add_Received_Read_REQ     0xA8 // Slave received + Read own address acknowledgment has been received
#define Slave_Data_Received_ACK			0x80 // Slave received data sent by master with acknowledgment
#define Slave_Data_Received_NOACK		0x88 // Slave received data sent by master with no acknowledgment
#define Slave_Data_Transmitted_ACK		0xB8 // Slave transmitted data received by master with acknowledgment
#define Slave_Data_Transmitted_NOACK	0xC0 // Slave transmitted data received by master with no acknowledgment

#endif /* TWI_CONFIGUARTION_H_ */