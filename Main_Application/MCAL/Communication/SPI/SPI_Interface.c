/*
 * SPI_Interface.c
 *
 * Created: 11/27/2023 7:11:12 AM
 *  Author: Belal
 */ 
#include <SPI_Private.h>

void SPI_Initialize(mode Mode, istatus Interrupt, freq Frequency)
{
	Set_Bit(SPCR, SPE);
	Clear_Bit(SPCR, DORD);
	Clear_Bit(SPCR, CPOL);
	Clear_Bit(SPCR, CPHA);
	switch(Mode)
	{
		case SPI_Master:
		Set_Bit(DDRB, MOSI);
		Clear_Bit(DDRB, MISO);
		Set_Bit(DDRB, SS);
		Set_Bit(DDRB, SCK);
		Set_Bit(SPCR, MSTR);
		switch(Interrupt)
		{
			case SPI_Interrupt:
			cli();
			Set_Bit(SPCR, SPIE);
			sei();
			break;
			case SPI_NoInterrupt:
			#define Istatus SPI_NoInterrupt
			break;
			default:
			break;
		}
		switch(Frequency)
		{
			case SPI_2:
			Clear_Bit(SPCR, SPR0);
			Clear_Bit(SPCR, SPR1);
			Set_Bit(SPSR, SPI2X);
			break;
			case SPI_8:
			Set_Bit(SPCR, SPR0);
			Clear_Bit(SPCR, SPR1);
			Set_Bit(SPSR, SPI2X);
			break;
			case SPI_32:
			Clear_Bit(SPCR, SPR0);
			Set_Bit(SPCR, SPR1);
			Set_Bit(SPSR, SPI2X);
			break;
			case SPI_4:
			Clear_Bit(SPCR, SPR0);
			Clear_Bit(SPCR, SPR1);
			Clear_Bit(SPSR, SPI2X);
			break;
			case SPI_16:
			Set_Bit(SPCR, SPR0);
			Clear_Bit(SPCR, SPR1);
			Clear_Bit(SPSR, SPI2X);
			break;
			case SPI_64:
			Clear_Bit(SPCR, SPR0);
			Set_Bit(SPCR, SPR1);
			Clear_Bit(SPSR, SPI2X);
			break;
			case SPI_128:
			Set_Bit(SPCR, SPR0);
			Set_Bit(SPCR, SPR1);
			Clear_Bit(SPSR, SPI2X);
			break;
			default:
			break;
		}
		break;
		case SPI_Slave:
		Clear_Bit(DDRB, MOSI);
		Set_Bit(DDRB, MISO);
		Clear_Bit(DDRB, SS);
		Clear_Bit(DDRB, SCK);
		Clear_Bit(SPCR, MSTR);
		switch(Interrupt)
		{
			case SPI_Interrupt:
			cli();
			Set_Bit(SPCR, SPIE);
			sei();
			break;
			case SPI_NoInterrupt:
			#define Istatus SPI_NoInterrupt
			break;
			default:
			break;
		}
		default:
		break;
	}
}
void SPI_Slave_Select(slave Slave)
{
	switch(Slave)
	{
		case SPI_Slave1:
		Clear_Bit(PORTB, SS);
		break;
		default:
		break;
	}
}
void SPI_Transmit_Character(u8 Character)
{
	if(Istatus == SPI_NoInterrupt)
	{
		SPDR = Character;
		while(!Get_Bit(SPSR, SPIF));
	}
	else
		SPDR = Character;
}
void SPI_Receive_Character(u8 *Character)
{
	if(Istatus == SPI_NoInterrupt)
	{
		while(!Get_Bit(SPSR, SPIF));
		*Character = SPDR;
	}
	else
		*Character = SPDR;
}
void SPI_TranCeive_Character(u8 TCharacter, u8* RCharacter)
{
	if(Istatus == SPI_NoInterrupt)
	{
		SPDR = TCharacter;
		while(!Get_Bit(SPSR, SPIF));
		*RCharacter = SPDR;
	}
}
void SPI_Transmit_String(u8* String)
{
	u8 i = 0;
	while(String[i] != '\0')
		SPI_Transmit_Character(String[i++]);
}
void SPI_Reveive_String(u8 *String)
{
	u8 i = 0;
	do 
	{
		SPI_Receive_Character((String + i));
	} while (String[i++] != '\0');
}