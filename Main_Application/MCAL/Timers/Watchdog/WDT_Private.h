/*
 * WDT_Private.h
 *
 * Created: 11/27/2023 8:53:18 PM
 *  Author: Belal
 */ 


#ifndef WDT_PRIVATE_H_
#define WDT_PRIVATE_H_

#include <WDT_Configuration.h>

void WDT_Initialization(void);
void WDT_Start(voltage Voltage, prescale3v Prescale3V, prescale5v Prescale5V);
void WDT_Timer_Refresh(void);

#endif /* WDT_PRIVATE_H_ */