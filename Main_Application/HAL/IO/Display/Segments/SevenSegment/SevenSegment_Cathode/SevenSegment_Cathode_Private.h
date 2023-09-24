/*
 * SevenSegment_Cathode_Private.h
 *
 * Created: 9/24/2023 6:25:37 PM
 *  Author: Belal hassan
 */ 


#ifndef SEVENSEGMENT_CATHODE_PRIVATE_H_
#define SEVENSEGMENT_CATHODE_PRIVATE_H_

#include <SevenSegment_Cathode_Configuration.h>

void SevenSegment_Initialize(void);
void SevenSegment_Enable_DP(void);
void SevenSegment_Disable_DP(void);
void SevenSegment_Display_Number(u8 number);
void SevenSegment_Display_Character(u8 character);

#endif /* SEVENSEGMENT_CATHODE_PRIVATE_H_ */