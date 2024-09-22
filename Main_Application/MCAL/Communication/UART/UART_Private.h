/*
 * UART_Private.h
 *
 * Created: 7/26/2024 11:36:40 PM
 *  Author: Belal
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#include <UART_Configuration.h>

void UARTinitialize(u32 Baudrate, syncmode SyncMode, transmode Transmode, datasize Datasize, parity Parity, 
stopbits StopBits, interrupt Interrupt, transmitAfter TransmitAfter, callbackInterrupts CallbackInterrupts);
void UARTsetBaudrate(u32 Baudrate, syncmode SyncMode);
void UARTsetTransmissionMode(transmode Transmode);
void UARTsetSyncMode(syncmode SyncMode);
void UARTsetDataSize(datasize Datasize);
void UARTsetParity(parity Parity);
void UARTsetStopSize(stopbits StopBits);
void UARTsetupInterrupts(interrupt Interrupt, transmitAfter TransmitAfter, callbackInterrupts CallbackInterrupts);
void UARTsendByte(u8 Byte);
void UARTsendString(u8 String[], u8 Datasize);
void UARTsendStruct(void* Data, u8 Datasize);
error UARTreceiveByte(u8 *Byte); 
void (*RxCallback)(void);
void (*TxCallback)(void);
void (*EmptyCallback)(void);

#endif /* UART_PRIVATE_H_ */