/*
* TWI_Interface.c
*
* Created: 11/27/2023 3:58:51 PM
*  Author: Belal
*/
#include <TWI_Private.h>

void TWI_Initialize(mode Mode, address Address, prescale Prescale)
{
	switch(Mode)
	{
		case TWI_Master:
		TWBR = 0xC0;
		switch(Prescale)
		{
			case TWI_PRE_1:
			Clear_Bit(TWSR, TWPS0);
			Clear_Bit(TWSR, TWPS1);
			break;
			case TWI_PRE_4:
			Set_Bit(TWSR, TWPS0);
			Clear_Bit(TWSR, TWPS1);
			break;
			case TWI_PRE_16:
			Clear_Bit(TWSR, TWPS0);
			Set_Bit(TWSR, TWPS1);
			break;
			case TWI_PRE_64:
			Set_Bit(TWSR, TWPS0);
			Set_Bit(TWSR, TWPS1);
			break;
			default:
			break;
		}
		break;
		case TWI_Slave:
		TWAR = 0x00;
		TWAR |= (Address << 1);
		Set_Bit(TWAR, TWGCE);
		break;
		default:
		break;
	}
	Set_Bit(TWCR, TWEN);
}
void TWI_Slave_Address_Operation(address Address, operation Operation)
{
	switch(Operation)
	{
		case TWI_Write:
		TWDR |= ((1 << Address) | (0x00));
		Set_Bit(TWCR, TWEN);
		Set_Bit(TWCR, TWINT);
		while(!Get_Bit(TWCR, TWINT));
		while((TWSR & Status_Mask) != Slave_Add_Received_Write_REQ);
		break;
		case TWI_Read:
		TWDR |= ((1 << Address) | (0x01));
		Set_Bit(TWCR, TWEN);
		Set_Bit(TWCR, TWINT);
		while(!Get_Bit(TWCR, TWINT));
		while((TWSR & Status_Mask) != Slave_Add_Received_Read_REQ);
		break;
		default:
		break;
	}
}
void TWI_Transmit_Character(address Address, u8 Character)
{
	Set_Bit(TWCR, TWSTA);
	Set_Bit(TWCR, TWEN);
	Set_Bit(TWCR, TWINT);
	while(!Get_Bit(TWCR, TWINT));
	while((TWSR & Status_Mask) != Start_ACK);
	TWDR = Character;
	Set_Bit(TWCR, TWEN);
	Set_Bit(TWCR, TWINT);
	while(!Get_Bit(TWCR, TWINT));
	while((TWSR & Status_Mask) != Write_Byte_ACK);
	Set_Bit(TWCR, TWSTO);
	Set_Bit(TWCR, TWEN);
	Set_Bit(TWCR, TWINT);
	while(!Get_Bit(TWCR, TWINT));
	while((TWSR & Status_Mask) != Stop_ACK);
}
void TWI_Receive_Character(address Address, u8 *Character)
{
	u8 ownAddress = 0;
	ownAddress = (TWAR>>1);
	if(ownAddress == Address)
	{
		Set_Bit(TWCR, TWEN);
		Set_Bit(TWCR, TWINT);
		while(!Get_Bit(TWCR, TWINT));
		while((TWSR & Status_Mask) != Read_Byte_ACK);
		*Character = TWDR;
	}
}
void TWI_Transmit_String(address Address, u8 *String)
{
	u8 i = 0;
	while(String[i] != '\0')
		TWI_Transmit_Character(Address, String[i++]);
}
void TWI_Receive_String(address Address, u8 *String)
{
	u8 i = 0;
	do 
	{
		TWI_Receive_Character(Address, (String + i));
	} while (String[i++] != '\0');
}