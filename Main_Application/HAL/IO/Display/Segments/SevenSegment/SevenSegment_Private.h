/*
 * SevenSegment_Private.h
 *
 * Created: 9/24/2023 5:17:56 PM
 *  Author: Belal hassan
 */ 


#ifndef SEVENSEGMENT_PRIVATE_H_
#define SEVENSEGMENT_PRIVATE_H_

#define _SEVENSEGMENT_BCD_

#ifdef _SEVENSEGMENT_BCD_
	#include <SevenSegment_BCD_Private.h>
#elif _SEVENSEGMENT_CATHODE_
	#include <SevenSegment_Cathode_Private.h>
#elif _SEVENSEGMENT_ANODE_
	#include <SevenSegment_Anode_Private.h>
#else
	#error	"Seven Segment type is not defined."
#endif

#endif /* SEVENSEGMENT_PRIVATE_H_ */