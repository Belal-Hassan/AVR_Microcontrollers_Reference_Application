/*
 * ADC_Configuration.h
 *
 * Created: 11/14/2023 6:04:42 PM
 *  Author: Belal
 */ 


#ifndef ADC_CONFIGURATION_H_
#define ADC_CONFIGURATION_H_

#include <ADC_Addresses.h>

typedef enum 
{
	ADC_AREF = 0,
	ADC_AVCC,
	ADC_Internal
}vref;

typedef enum
{
	ADC_0 = 0,
	ADC_1 = 1,
	ADC_2 = 2,
	ADC_3 = 3,
	ADC_4 = 4,
	ADC_5 = 5,
	ADC_6 = 6,
	ADC_7 = 7
	
}channel;

typedef enum
{
	ADC_PRE_0 = 0,
	ADC_PRE_2 = 1,
	ADC_PRE_4 = 2,
	ADC_PRE_8 = 3,
	ADC_PRE_16 = 4,
	ADC_PRE_32 = 5,
	ADC_PRE_64 = 6,
	ADC_PRE_128 = 7
}prescaler;

#endif /* ADC_CONFIGURATION_H_ */