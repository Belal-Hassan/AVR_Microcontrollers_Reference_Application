/*
 * ADC_Private.h
 *
 * Created: 11/14/2023 6:04:59 PM
 *  Author: Belal
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include <ADC_Configuration.h>

void ADC_Initialize(vref Voltage, prescaler Prescale);
u16	ADC_Read(channel Channel);

#endif /* ADC_PRIVATE_H_ */