/*
 * DC_Private.h
 *
 * Created: 11/26/2023 9:37:06 AM
 *  Author: Belal
 */ 


#ifndef DC_PRIVATE_H_
#define DC_PRIVATE_H_

#include <DC_Configuration.h>

void DC_Initialize(motor Motor);
void DC_Speed(motor Motor, s8 Speed);
void DC_Stop(motor Motor);

#endif /* DC_PRIVATE_H_ */