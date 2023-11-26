/*
 * ADC_Interface.c
 *
 * Created: 11/14/2023 6:05:14 PM
 *  Author: Belal
 */ 

#include <ADC_Private.h>

void ADC_Initialize(vref Voltage, prescaler Prescale)
{
	Set_Bit(ADCSRA, ADEN);
	Clear_Bit(ADMUX, ADLAR);
	switch(Voltage)
	{
		case ADC_AREF:
		Clear_Bit(ADMUX, REFS0);
		Clear_Bit(ADMUX, REFS1);
		break;
		case ADC_AVCC:
		Set_Bit(ADMUX, REFS0);
		Clear_Bit(ADMUX, REFS1);
		break;
		case ADC_Internal:
		Set_Bit(ADMUX, REFS0);
		Set_Bit(ADMUX, REFS1);
		break;
		default:
		break;
	}
	switch(Prescale)
	{
		case ADC_PRE_0:
		Clear_Bit(ADCSRA, ADPS0);
		Clear_Bit(ADCSRA, ADPS1);
		Clear_Bit(ADCSRA, ADPS2);
		break;
		case ADC_PRE_2:
		Set_Bit(ADCSRA, ADPS0);
		Clear_Bit(ADCSRA, ADPS1);
		Clear_Bit(ADCSRA, ADPS2);
		case ADC_PRE_4:
		Clear_Bit(ADCSRA, ADPS0);
		Set_Bit(ADCSRA, ADPS1);
		Clear_Bit(ADCSRA, ADPS2);
		case ADC_PRE_8:
		Set_Bit(ADCSRA, ADPS0);
		Set_Bit(ADCSRA, ADPS1);
		Clear_Bit(ADCSRA, ADPS2);
		case ADC_PRE_16:
		Clear_Bit(ADCSRA, ADPS0);
		Clear_Bit(ADCSRA, ADPS1);
		Set_Bit(ADCSRA, ADPS2);
		case ADC_PRE_32:
		Set_Bit(ADCSRA, ADPS0);
		Clear_Bit(ADCSRA, ADPS1);
		Set_Bit(ADCSRA, ADPS2);
		case ADC_PRE_64:
		Clear_Bit(ADCSRA, ADPS0);
		Set_Bit(ADCSRA, ADPS1);
		Set_Bit(ADCSRA, ADPS2);
		case ADC_PRE_128:
		Set_Bit(ADCSRA, ADPS0);
		Set_Bit(ADCSRA, ADPS1);
		Set_Bit(ADCSRA, ADPS2);
		default:
		break;
	}
}
u16	ADC_Read(channel Channel)
{
	u16 Value = 0;
	switch(Channel)
	{
		case ADC_0:
		Clear_Bit(ADMUX, MUX0);
		Clear_Bit(ADMUX, MUX1);
		Clear_Bit(ADMUX, MUX2);
		Clear_Bit(DDRA, ADC_0);
		case ADC_1:
		Set_Bit(ADMUX, MUX0);
		Clear_Bit(ADMUX, MUX1);
		Clear_Bit(ADMUX, MUX2);
		Clear_Bit(DDRA, ADC_1);
		case ADC_2:
		Clear_Bit(ADMUX, MUX0);
		Set_Bit(ADMUX, MUX1);
		Clear_Bit(ADMUX, MUX2);
		Clear_Bit(DDRA, ADC_2);
		case ADC_3:
		Set_Bit(ADMUX, MUX0);
		Set_Bit(ADMUX, MUX1);
		Clear_Bit(ADMUX, MUX2);
		Clear_Bit(DDRA, ADC_3);
		case ADC_4:
		Clear_Bit(ADMUX, MUX0);
		Clear_Bit(ADMUX, MUX1);
		Set_Bit(ADMUX, MUX2);
		Clear_Bit(DDRA, ADC_4);
		case ADC_5:
		Set_Bit(ADMUX, MUX0);
		Clear_Bit(ADMUX, MUX1);
		Set_Bit(ADMUX, MUX2);
		Clear_Bit(DDRA, ADC_5);
		case ADC_6:
		Clear_Bit(ADMUX, MUX0);
		Set_Bit(ADMUX, MUX1);
		Set_Bit(ADMUX, MUX2);
		Clear_Bit(DDRA, ADC_6);
		case ADC_7:
		Set_Bit(ADMUX, MUX0);
		Set_Bit(ADMUX, MUX1);
		Set_Bit(ADMUX, MUX2);
		Clear_Bit(DDRA, ADC_7);
		break;
		default:
		break;
	}
	Set_Bit(ADCSRA, ADSC);
	while(Get_Bit(ADCSRA, ADSC));
	_delay_us(10);
	Value = ADCL | (ADCH << 8);
	return Value;
}