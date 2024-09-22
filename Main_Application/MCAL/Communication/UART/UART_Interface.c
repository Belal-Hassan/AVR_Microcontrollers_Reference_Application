/*
 * UART_Interface.c
 *
 * Created: 7/26/2024 11:11:32 PM
 *  Author: Belal
 */ 
#include <UART_Private.h>

void UARTinitialize(u32 Baudrate, syncmode SyncMode, transmode Transmode, datasize Datasize, parity Parity, 
stopbits StopBits, interrupt Interrupt, transmitAfter TransmitAfter, callbackInterrupts CallbackInterrupts)
{
	UARTsetBaudrate(Baudrate, SyncMode);								//Set Baudrate according to the synchronization mode.
	UARTsetTransmissionMode(Transmode);									//Select the communication mode.
	UARTsetSyncMode(SyncMode);											//Select the synchronization mode.
	UARTsetDataSize(Datasize);											//Select the data size.
	UARTsetParity(Parity);												//Select the parity mode.
	UARTsetStopSize(StopBits);											//Selecting the number of stop bits.
	UARTsetupInterrupts(Interrupt, TransmitAfter, CallbackInterrupts);	//Setup the interrupts. 
}
void UARTsetBaudrate(u32 Baudrate, syncmode SyncMode)
{
	Set_Bit(UCSRC, URSEL);																				//Select to write to UBRR.
	u16 UBRR_value = 0;
	if(SyncMode == asyncronousDouble || SyncMode == asyncronousNormal)
		UBRR_value = round(((float)F_CPU / (8.0 * (2.0 - (float)SyncMode) * (float)Baudrate)) - 1.0);	//Calculating and setting the required UBRR value based on the desired baudrate in asyncronous modes.
	else
		UBRR_value = round(((float)F_CPU / (2.0 * (float)Baudrate)) - 1.0);								//Calculating and setting the required UBRR value based on the desired baudrate in syncronous mode.
	UBRRL |= UBRR_value;
	UBRRH |= UBRR_value >> 8;
}
void UARTsetTransmissionMode(transmode Transmode)
{
	switch(Transmode)
	{
		case receiver:
		Set_Bit(UCSRB, RXEN);
		Clear_Bit(UCSRB, TXEN);
		break;
		case transmitter:
		Clear_Bit(UCSRB, RXEN);
		Set_Bit(UCSRB, TXEN);
		break;
		case transceiver:
		Set_Bit(UCSRB, RXEN);
		Set_Bit(UCSRB, TXEN);
		break;
		default:
		break;
	}
}
void UARTsetSyncMode(syncmode SyncMode)
{
	Set_Bit(UCSRC, URSEL); //Select to Write to UCSRC.
	UCSRA &= 0b11100011; //Clears the FE, DOR, and PE bits to be able to write to UCSRA. 
	switch(SyncMode)
	{
		case asyncronousNormal:
		Clear_Bit(UCSRC, UMSEL);
		Clear_Bit(UCSRA, U2X);
		break;
		case asyncronousDouble:
		Clear_Bit(UCSRC, UMSEL);
		Set_Bit(UCSRA, U2X);
		break;
		case syncronous:
		Set_Bit(UCSRC, UMSEL);
		Clear_Bit(UCSRA, U2X);
		break;
		default:
		break;
	}
}
void UARTsetDataSize(datasize Datasize)
{
	Set_Bit(UCSRC, URSEL);	//Select to Write to UCSRC.
	dataSize9Bits = 0;
	switch(Datasize)
	{
		case size5bits:
		Clear_Bit(UCSRC, UCSZ0);
		Clear_Bit(UCSRC, UCSZ1);
		Clear_Bit(UCSRB, UCSZ2);
		break;
		case size6bits:
		Set_Bit(UCSRC, UCSZ0);
		Clear_Bit(UCSRC, UCSZ1);
		Clear_Bit(UCSRB, UCSZ2);
		break;
		case size7bits:
		Clear_Bit(UCSRC, UCSZ0);
		Set_Bit(UCSRC, UCSZ1);
		Clear_Bit(UCSRB, UCSZ2);
		break;
		case size8bits:
		Set_Bit(UCSRC, UCSZ0);
		Set_Bit(UCSRC, UCSZ1);
		Clear_Bit(UCSRB, UCSZ2);
		break;
		case size9bits:
		Set_Bit(UCSRC, UCSZ0);
		Set_Bit(UCSRC, UCSZ1);
		Set_Bit(UCSRB, UCSZ2);
		dataSize9Bits = 1;
		break;
		default:
		break;
	}
}
void UARTsetParity(parity Parity)
{
	Set_Bit(UCSRC, URSEL);	//Select to Write to UCSRC.
	switch(Parity)
	{
		case disabledParity:
		Clear_Bit(UCSRC, UPM0);
		Clear_Bit(UCSRC, UPM1);
		break;
		case evenParity:
		Clear_Bit(UCSRC, UPM0);
		Set_Bit(UCSRC, UPM1);
		break;
		case oddParity:
		Set_Bit(UCSRC, UPM0);
		Set_Bit(UCSRC, UPM1);
		break;
		default:
		break;
	}
}
void UARTsetStopSize(stopbits StopBits)
{
	Set_Bit(UCSRC, URSEL); //Select to Write to UCSRC.
	if (StopBits)
		Set_Bit(UCSRC, USBS);
	else
		Clear_Bit(UCSRC, USBS);
}
void UARTsetupInterrupts(interrupt Interrupt, transmitAfter TransmitAfter, callbackInterrupts CallbackInterrupts)
{
	/*__________Enabling selected interrupts__________*/
	if(TransmitAfter == transmitAfterInterrupt)
		transmitInterruptEnabled = 1;
	else
		transmitInterruptEnabled = 0;
	cli();
	switch(Interrupt)
	{
		case noInterrupt:
		Clear_Bit(UCSRB, RXCIE);
		Clear_Bit(UCSRB, TXCIE);
		Clear_Bit(UCSRB, UDRIE);
		receiveInterruptEnabled = 0;
		transmitInterruptEnabled = 0;
		break;
		case receiveInterrupt:
		Set_Bit(UCSRB, RXCIE);
		Clear_Bit(UCSRB, TXCIE);
		Clear_Bit(UCSRB, UDRIE);
		receiveInterruptEnabled = 1;
		transmitInterruptEnabled = 0;
		break;
		case transmitInterrupt:
		Clear_Bit(UCSRB, RXCIE);
		Set_Bit(UCSRB, TXCIE);
		Clear_Bit(UCSRB, UDRIE);
		receiveInterruptEnabled = 0;
		break;
		case emptyInterrupt:
		Clear_Bit(UCSRB, RXCIE);
		Clear_Bit(UCSRB, TXCIE);
		Set_Bit(UCSRB, UDRIE);
		receiveInterruptEnabled = 0;
		break;
		case receiveEmptyInterrupt:
		Set_Bit(UCSRB, RXCIE);
		Clear_Bit(UCSRB, TXCIE);
		Set_Bit(UCSRB, UDRIE);
		receiveInterruptEnabled = 1;
		break;
		case transmitEmptyInterrupt:
		Clear_Bit(UCSRB, RXCIE);
		Set_Bit(UCSRB, TXCIE);
		Set_Bit(UCSRB, UDRIE);
		receiveInterruptEnabled = 0;
		break;
		case receiveTransmitInterrupt:
		Set_Bit(UCSRB, RXCIE);
		Set_Bit(UCSRB, TXCIE);
		Clear_Bit(UCSRB, UDRIE);
		receiveInterruptEnabled = 1;
		break;
		case allInterrupts:
		Set_Bit(UCSRB, RXCIE);
		Set_Bit(UCSRB, TXCIE);
		Set_Bit(UCSRB, UDRIE);
		receiveInterruptEnabled = 1;
		break;
		default:
		break;
	}
	sei();
	/*__________Setting interrupt callback functions__________*/
	RxCallback = CallbackInterrupts.RxCallbackPointer;
	TxCallback = CallbackInterrupts.TxCallbackPointer;
	EmptyCallback = CallbackInterrupts.EmptyCallbackPointer;
}
void UARTsendByte(u8 Byte)
{
	if(!transmitInterruptEnabled)
		while (!Get_Bit(UCSRA, UDRE)); //Waits for empty transmit buffer.
	UDR = Byte;
}
void UARTsendString(u8 String[], u8 Datasize)
{
	for(u8 counter = 0; counter < Datasize; counter++)
	{
		UARTsendByte(String[counter]); //send each byte of the string of a given size.
		_delay_ms(1); //added for simulation purposes and should be removed in hardware prototypes. 
	}
}
void UARTsendStruct(void* Data, u8 Datasize)
{
	u8 buffer[Datasize + 1]; //create a buffer to cast the void data inside it.
	memcpy(buffer, Data, Datasize); //copy the data.
	UARTsendString(buffer, Datasize); //send the buffer.
}
error UARTreceiveByte(u8 *Byte)
{
	if(Get_Bit(UCSRA, FE))
		return frameError; //Returns frame error if the FE bit is set.
	if(Get_Bit(UCSRA, DOR))
		return overRunError; //Returns frame error if the FE bit is set.
	if (Get_Bit(UCSRA, PE))
		return frameError; //Returns frame error if the FE bit is set.
	if(!receiveInterruptEnabled)
		while (!Get_Bit(UCSRA, RXC)); //Waits until the data is received.
	*Byte = UDR; 
	return noError;
}

/*__________UART Interrupt service routines__________*/
ISR(USART_RXC_vect)
{
	if(RxCallback != NULL)
		RxCallback();
}
ISR(USART_TXC_vect)
{
	if(TxCallback != NULL)
		TxCallback();
}
ISR(USART_UDRE_vect)
{
	if(EmptyCallback != NULL)
		EmptyCallback();
}