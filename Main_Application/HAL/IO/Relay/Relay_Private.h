/*
 * Relay_Private.h
 *
 * Created: 9/22/2023 9:08:46 AM
 *  Author: Belal Hassan
 */ 


#ifndef RELAY_PRIVATE_H_
#define RELAY_PRIVATE_H_

#include <Relay_Configuration.h>

void Relay_Initialize(void);
void Relay_On(void);
void Relay_Off(void);
void Relay_Toggle(void);

#endif /* RELAY_PRIVATE_H_ */