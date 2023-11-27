/*
* DC_Interface.c
*
* Created: 11/26/2023 9:36:54 AM
*  Author: Belal
*/
#include <DC_Private.h>

void DC_Initialize(motor Motor)
{
	static bool Initialized1 = false;
	static bool Initialized2 = false;
	switch(Motor)
	{
		case DC1:
		if(!Initialized1)
		{
			DIO_SetPinDirection(DC_DIR_PORT, DC_IN12, DC_Output);
			DIO_SetPinValue(DC_DIR_PORT, DC_IN12, DC_Low);
			Timer0_FPWM_Initialize();
			Timer0_FPWM_Start(Timer0_PRE_64);
			Timer0_FPWM_SetDuty(PWM_NonInverting, 0);
			Initialized1 = true;
		}
		break;
		case DC2:
		if(!Initialized2)
		{
			DIO_SetPinDirection(DC_DIR_PORT, DC_IN12, DC_Output);
			DIO_SetPinValue(DC_DIR_PORT, DC_IN12, DC_Low);
			Timer0_FPWM_Initialize();
			Timer0_FPWM_Start(Timer0_PRE_64);
			Timer0_FPWM_SetDuty(PWM_NonInverting, 0);
			Initialized2 = true;
		}
		break;
		default:
		break;
	}
}
void DC_Stop(motor Motor)
{
	switch(Motor)
	{
		case DC1:
		Timer0_FPWM_Stop();
		break;
		case DC2:
		Timer0_FPWM_Stop();
		break;
		default:
		break;
	}
}
void DC_Speed(motor Motor, s8 Speed)
{
	switch(Motor)
	{
		case DC1:
		DC_Initialize(DC1);
		if(Speed > 0)
		{
			DIO_SetPinValue(DC_DIR_PORT, DC_IN12, DC_CW);
			Timer0_FPWM_Start(Timer0_PRE_64);
			Timer0_FPWM_SetDuty(PWM_NonInverting, Speed);
		}
		if(Speed < 0)
		{
			DIO_SetPinValue(DC_DIR_PORT, DC_IN12, DC_CCW);
			Timer0_FPWM_Start(Timer0_PRE_64);
			Timer0_FPWM_SetDuty(PWM_NonInverting, -Speed);
		}
		if(Speed == 0)
			DC_Stop(DC1);
		break;
		case DC2:
		DC_Initialize(DC2);
		if(Speed > 0)
		{
			DIO_SetPinValue(DC_DIR_PORT, DC_IN34, DC_CW);
			Timer0_FPWM_Start(Timer0_PRE_64);
			Timer0_FPWM_SetDuty(PWM_NonInverting, Speed);
		}
		else if(Speed < 0)
		{
			DIO_SetPinValue(DC_DIR_PORT, DC_IN34, DC_CCW);
			Timer0_FPWM_Start(Timer0_PRE_64);
			Timer0_FPWM_SetDuty(PWM_NonInverting, -Speed);
		}
		else
		DC_Stop(DC2);
		break;
		default:
		break;
	}
}