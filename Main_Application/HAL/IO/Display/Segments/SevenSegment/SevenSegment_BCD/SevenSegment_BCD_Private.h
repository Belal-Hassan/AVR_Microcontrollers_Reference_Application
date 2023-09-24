/*
 * SevenSegment_BCD_Private.h
 *
 * Created: 9/24/2023 5:17:01 PM
 *  Author: Belal hassan
 */ 


#ifndef SEVENSEGMENT_BCD_PRIVATE_H_
#define SEVENSEGMENT_BCD_PRIVATE_H_

#include <SevenSegment_BCD_Configuration.h>

void SevenSegment_Initialize(void);
void SevenSegment_Enable_1(void);
void SevenSegment_Disable_1(void);
void SevenSegment_Enable_2(void);
void SevenSegment_Disable_2(void);
void SevenSegment_Enable_DP(void);
void SevenSegment_Disable_DP(void);
void SevenSegment_Display_Number(u8 number);

#endif /* SEVENSEGMENT_BCD_PRIVATE_H_ */