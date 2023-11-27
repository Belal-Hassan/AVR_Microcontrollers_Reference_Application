/*
 * Timer0_Private.h
 *
 * Created: 11/17/2023 9:44:44 AM
 *  Author: Belal
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_

#include <Timer0_Configuration.h>

void Timer0_OVF_WithoutInterrupt_Initialize(void);
void Timer0_OVF_WithoutInterrupt_Start(prescale Prescale);
void Timer0_OVF_WithoutInterrupt_Stop(void);
void Timer0_OVF_WithoutInterrupt_SetDelay(u32 Delay);
void Timer0_OVF_WithInterrupt_Initialize(void);
void Timer0_OVF_WithInterrupt_Start(prescale Prescale);
void Timer0_OVF_WithInterrupt_Stop(void);
void Timer0_OVF_WithInterrupt_SetDelay(u32 Delay);

void Timer0_CTC_WithoutInterrupt_Initialize(void);
void Timer0_CTC_WithoutInterrupt_Start(prescale Prescale);
void Timer0_CTC_WithoutInterrupt_Stop(void);
void Timer0_CTC_WithoutInterrupt_SetDelay(u32 Delay , u8 OCR);
void Timer0_CTC_WithInterrupt_Initialize(void);
void Timer0_CTC_WithInterrupt_Start(prescale Prescale);
void Timer0_CTC_WithInterrupt_Stop(void);
void Timer0_CTC_WithInterrupt_SetDelay(u32 Delay, u8 OCR);

void Timer0_FPWM_Initialize(void);
void Timer0_FPWM_Start(prescale Prescale);
void Timer0_FPWM_Stop(void);
void Timer0_FPWM_SetDuty(pinmode Pinmode, u8 Dutycycle);

void Timer0_PPWM_Initialize(void);
void Timer0_PPWM_Start(prescale Prescale);
void Timer0_PPWM_Stop(void);
void Timer0_PPWM_SetDuty(pinmode Pinmode, u8 Dutycycle);

#endif /* TIMER0_PRIVATE_H_ */