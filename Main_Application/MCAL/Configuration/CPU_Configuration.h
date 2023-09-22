/*
 * CPU_config.h
 *
 * Created: 9/15/2023 10:48:56 AM
 *  Author: Belal Hassan
 */ 


#ifndef CPU_CONFIGURATION_H_
#define CPU_CONFIGURATION_H_

#include "STD_Types.h"
#include "Bit_Math.h"

//#define __AVR_ATmega32__
#undef F_CPU
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#endif /* CPU_CONFIGURATION_H_ */