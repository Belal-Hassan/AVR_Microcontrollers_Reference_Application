/*
 * DC_Configuration.h
 *
 * Created: 11/26/2023 9:37:20 AM
 *  Author: Belal
 */ 


#ifndef DC_CONFIGURATION_H_
#define DC_CONFIGURATION_H_

#include <Peripheral_Libraries.h>

#define DC_DIR_PORT		DIO_PORTC
#define DC_IN12			DIO_PIN0
#define DC_IN34			DIO_PIN1

#define DC_Output		DIO_Output

#define DC_High			DIO_High
#define DC_Low			DIO_Low

typedef enum
{
	DC1 = 0,
	DC2
}motor;

enum
{
	DC_CW = 0,
	DC_CCW
};

#endif /* DC_CONFIGURATION_H_ */