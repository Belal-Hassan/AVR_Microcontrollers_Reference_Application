/*
 * SevenSegment_Anode_Private.h
 *
 * Created: 9/24/2023 6:26:41 PM
 *  Author: Belal hassan
 */ 


#ifndef SEVENSEGMENT_ANODE_PRIVATE_H_
#define SEVENSEGMENT_ANODE_PRIVATE_H_

#include <SevenSegment_Anode_Configuration.h>

void SevenSegment_Initialize(void);
void SevenSegment_Enable_DP(void);
void SevenSegment_Disable_DP(void);
void SevenSegment_Display_Number(u8 number);
void SevenSegment_Display_Character(u8 character);

#endif /* SEVENSEGMENT_ANODE_PRIVATE_H_ */