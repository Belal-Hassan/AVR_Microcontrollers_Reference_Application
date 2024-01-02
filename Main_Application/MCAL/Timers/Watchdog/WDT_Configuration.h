/*
 * WDT_Configuration.h
 *
 * Created: 11/27/2023 8:53:08 PM
 *  Author: Belal
 */ 


#ifndef WDT_CONFIGURATION_H_
#define WDT_CONFIGURATION_H_

#include <WDT_Addresses.h>

typedef enum
{
	WDT_3V = 0,
	WDT_5V
}voltage;

typedef enum
{
	WDT_17ms = 0,
	WDT_34ms,
	WDT_68ms,
	WDT_140ms,
	WDT_270ms,
	WDT_550ms,
	WDT_1100ms,
	WDT_2200ms
}prescale3v;

typedef enum
{
	WDT_16ms = 0,
	WDT_32ms,
	WDT_65ms,
	WDT_130ms,
	WDT_260ms,
	WDT_520ms,
	WDT_1000ms,
	WDT_2100ms
}prescale5v;

#endif /* WDT_CONFIGURATION_H_ */