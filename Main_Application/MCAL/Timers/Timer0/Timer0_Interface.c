/*
* Timer0_Interface.c
*
* Created: 11/17/2023 9:45:01 AM
*  Author: Belal
*/
#include <Timer0_Private.h>

u32 Overflow_Cycle = 0, CTC_Cycle = 0;

void Timer0_OVF_WithoutInterrupt_Initialize(void)
{
	Clear_Bit(TCCR0, PWM0);
	Clear_Bit(TCCR0, CTC0);
	Clear_Bit(TCCR0, COM00);
	Clear_Bit(TCCR0, COM01);
	Clear_Bit(TIMSK, TOIE0);
}
void Timer0_OVF_WithoutInterrupt_Start(prescale Prescale)
{
	switch(Prescale)
	{
		case Timer0_NO_Clock:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		Overflow_Cycle = 0;
		break;
		case Timer0_NO_PRE:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		Overflow_Cycle = 1/System_FREQ;
		break;
		case Timer0_PRE_8:
		Clear_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		Overflow_Cycle = 8 / System_FREQ;
		break;
		case Timer0_PRE_64:
		Set_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		Overflow_Cycle = 64 / System_FREQ;
		break;
		case Timer0_PRE_256:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		Overflow_Cycle = 256 / System_FREQ;
		break;
		case Timer0_PRE_1024:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		Overflow_Cycle = 1024 / System_FREQ;
		break;
		default:
		break;
	}
}
void Timer0_OVF_WithoutInterrupt_Stop(void)
{
	Clear_Bit(TCCR0, CS00);
	Clear_Bit(TCCR0, CS01);
	Clear_Bit(TCCR0, CS02);
	Overflow_Cycle = 0;
}
void Timer0_OVF_WithoutInterrupt_SetDelay(u32 Delay)
{
	u32 Counter = 0, Count = Delay/Overflow_Cycle, Overflows = (Count/Timer0_Bits) + 1;
	TCNT0 = Timer0_Bits - (Count % Timer0_Bits);
	while(Counter != Overflows)
	{
		while(!Get_Bit(TIFR, TOV0));
		Clear_Bit(TIFR, TOV0);
		Counter++;
	}
}
void Timer0_OVF_WithInterrupt_Initialize(void)
{
	Clear_Bit(TCCR0, PWM0);
	Clear_Bit(TCCR0, CTC0);
	Clear_Bit(TCCR0, COM00);
	Clear_Bit(TCCR0, COM01);
	Set_Bit(TIMSK, TOIE0);
	Set_Bit(SREG, I);
}
void Timer0_OVF_WithInterrupt_Start(prescale Prescale)
{
	switch(Prescale)
	{
		case Timer0_NO_Clock:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		Overflow_Cycle = 0;
		break;
		case Timer0_NO_PRE:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		Overflow_Cycle = 1/System_FREQ;
		break;
		case Timer0_PRE_8:
		Clear_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		Overflow_Cycle = 8/System_FREQ;
		break;
		case Timer0_PRE_64:
		Set_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		Overflow_Cycle = 64/System_FREQ;
		break;
		case Timer0_PRE_256:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		Overflow_Cycle = 256/System_FREQ;
		break;
		case Timer0_PRE_1024:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		Overflow_Cycle = 1024/System_FREQ;
		break;
		default:
		break;
	}
}
void Timer0_OVF_WithInterrupt_Stop(void)
{
	Clear_Bit(TCCR0, CS00);
	Clear_Bit(TCCR0, CS01);
	Clear_Bit(TCCR0, CS02);
	Overflow_Cycle = 0;
}
void Timer0_OVF_WithInterrupt_SetDelay(u32 Delay)
{
	u32 Count = Delay/Overflow_Cycle, Overflows = (Count/Timer0_Bits) + 1;
	TCNT0 = Timer0_Bits - (Count % Timer0_Bits);
}

void Timer0_CTC_WithoutInterrupt_Initialize(void)
{
	Clear_Bit(TCCR0, PWM0);
	Set_Bit(TCCR0, CTC0);
	Clear_Bit(TCCR0, COM00);
	Clear_Bit(TCCR0, COM01);
	Clear_Bit(TIMSK, OCIE0);
}
void Timer0_CTC_WithoutInterrupt_Start(prescale Prescale)
{
	switch(Prescale)
	{
		case Timer0_NO_Clock:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		CTC_Cycle = 0;
		break;
		case Timer0_NO_PRE:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		CTC_Cycle = 1/System_FREQ;
		break;
		case Timer0_PRE_8:
		Clear_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		CTC_Cycle = 8/System_FREQ;
		break;
		case Timer0_PRE_64:
		Set_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		CTC_Cycle = 64/System_FREQ;
		break;
		case Timer0_PRE_256:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		CTC_Cycle = 256/System_FREQ;
		break;
		case Timer0_PRE_1024:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		CTC_Cycle = 1024/System_FREQ;
		break;
		default:
		break;
	}
}
void Timer0_CTC_WithoutInterrupt_Stop(void)
{
	Clear_Bit(TCCR0, CS00);
	Clear_Bit(TCCR0, CS01);
	Clear_Bit(TCCR0, CS02);
	CTC_Cycle = 0;
}
void Timer0_CTC_WithoutInterrupt_SetDelay(u32 Delay , u8 OCR)
{
	u32 Counter = 0, Count = Delay/CTC_Cycle, CTCs = (Count/OCR) + 1;
	OCR0 = OCR;
	TCNT0 = OCR - (Count % OCR);
	while(Counter != CTCs)
	{
		while(!Get_Bit(TIFR, OCF0));
		Clear_Bit(TIFR, OCF0);
		Counter++;
	}
}
void Timer0_CTC_WithInterrupt_Initialize(void)
{
	Clear_Bit(TCCR0, PWM0);
	Set_Bit(TCCR0, CTC0);
	Clear_Bit(TCCR0, COM00);
	Clear_Bit(TCCR0, COM01);
	Set_Bit(TIMSK, OCIE0);
	Set_Bit(SREG, I);
}
void Timer0_CTC_WithInterrupt_Start(prescale Prescale)
{
	switch(Prescale)
	{
		case Timer0_NO_Clock:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		CTC_Cycle = 0;
		break;
		case Timer0_NO_PRE:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		CTC_Cycle = 1/System_FREQ;
		break;
		case Timer0_PRE_8:
		Clear_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		CTC_Cycle = 8/System_FREQ;
		break;
		case Timer0_PRE_64:
		Set_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		CTC_Cycle = 64/System_FREQ;
		break;
		case Timer0_PRE_256:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		CTC_Cycle = 256/System_FREQ;
		break;
		case Timer0_PRE_1024:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		CTC_Cycle = 1024/System_FREQ;
		break;
		default:
		break;
	}
}
void Timer0_CTC_WithInterrupt_Stop(void)
{
	Clear_Bit(TCCR0, CS00);
	Clear_Bit(TCCR0, CS01);
	Clear_Bit(TCCR0, CS02);
	CTC_Cycle = 0;
}
void Timer0_CTC_WithInterrupt_SetDelay(u32 Delay, u8 OCR)
{
	u32 Count = Delay/CTC_Cycle, CTCs = (Count/OCR) + 1;
	OCR0 = OCR;
	TCNT0 = OCR - (Count % OCR);
}

void Timer0_FPWM_Initialize(void)
{
	Set_Bit(DDRB, OC0);
	Set_Bit(TCCR0, PWM0);
	Set_Bit(TCCR0, CTC0);
}
void Timer0_FPWM_Start(prescale Prescale)
{
	switch(Prescale)
	{
		case Timer0_NO_Clock:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		break;
		case Timer0_NO_PRE:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		break;
		case Timer0_PRE_8:
		Clear_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		break;
		case Timer0_PRE_64:
		Set_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		break;
		case Timer0_PRE_256:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		break;
		case Timer0_PRE_1024:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		break;
		default:
		break;
	}
}
void Timer0_FPWM_Stop(void)
{
	Clear_Bit(TCCR0, CS00);
	Clear_Bit(TCCR0, CS01);
	Clear_Bit(TCCR0, CS02);
}
void Timer0_FPWM_SetDuty(pinmode Pinmode, u8 Dutycycle)
{
	switch(Pinmode)
	{
		case PWM_Disconnected:
		Clear_Bit(TCCR0, COM00);
		Clear_Bit(TCCR0, COM01);
		break;
		case PWM_NonInverting:
		Clear_Bit(TCCR0, COM00);
		Set_Bit(TCCR0, COM01);
		OCR0 = ((Timer0_Bits * Dutycycle) / 100) - 1;
		break;
		case PWM_Inverting:
		Set_Bit(TCCR0, COM00);
		Set_Bit(TCCR0, COM01);
		OCR0 = Timer0_Bits - (((Timer0_Bits * Dutycycle) / 100) - 1);
		break;
		default:
		break;
	}
}

void Timer0_PPWM_Initialize(void)
{
	Set_Bit(DDRB, OC0);
	Set_Bit(TCCR0, PWM0);
	Clear_Bit(TCCR0, CTC0);
}
void Timer0_PPWM_Start(prescale Prescale)
{
	switch(Prescale)
	{
		case Timer0_NO_Clock:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		break;
		case Timer0_NO_PRE:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		break;
		case Timer0_PRE_8:
		Clear_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		break;
		case Timer0_PRE_64:
		Set_Bit(TCCR0, CS00);
		Set_Bit(TCCR0, CS01);
		Clear_Bit(TCCR0, CS02);
		break;
		case Timer0_PRE_256:
		Clear_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		break;
		case Timer0_PRE_1024:
		Set_Bit(TCCR0, CS00);
		Clear_Bit(TCCR0, CS01);
		Set_Bit(TCCR0, CS02);
		break;
		default:
		break;
	}
}
void Timer0_PPWM_Stop(void)
{
	Clear_Bit(TCCR0, CS00);
	Clear_Bit(TCCR0, CS01);
	Clear_Bit(TCCR0, CS02);
}
void Timer0_PPWM_SetDuty(pinmode Pinmode, u8 Dutycycle)
{
	switch(Pinmode)
	{
		case PWM_Disconnected:
		Clear_Bit(TCCR0, COM00);
		Clear_Bit(TCCR0, COM01);
		break;
		case PWM_NonInverting:
		Clear_Bit(TCCR0, COM00);
		Set_Bit(TCCR0, COM01);
		OCR0 = ((Timer0_Bits * Dutycycle)/100) - 1;
		break;
		case PWM_Inverting:
		Set_Bit(TCCR0, COM00);
		Set_Bit(TCCR0, COM01);
		OCR0 = Timer0_Bits - (((Timer0_Bits * Dutycycle)/100) - 1);
		break;
		default:
		break;
	}
}