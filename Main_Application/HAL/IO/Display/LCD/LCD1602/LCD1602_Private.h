/*
 * LCD1602_Private.h
 *
 * Created: 9/28/2023 5:10:20 PM
 *  Author: Belal hassan
 */ 


#ifndef LCD1602_PRIVATE_H_
#define LCD1602_PRIVATE_H_

#define _LCD1602_4BIT_ 0
#define _LCD1602_8BIT_ 1
#define _LCD1602_MODE_ _LCD1602_4BIT_

#if	_LCD1602_MODE_ == _LCD1602_4BIT_
	#include <LCD1602_4Bit_Private.h>
#elif _LCD1602_MODE_ == _LCD1602_8BIT_
	#include <LCD1602_8Bit_Private.h>
#else 
	#error "LCD 16*2 Mode is not defined."
#endif

#endif /* LCD1602_PRIVATE_H_ */