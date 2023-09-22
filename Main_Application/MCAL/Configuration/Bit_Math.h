/*
 * macro.h
 *
 * Created: 9/14/2023 3:15:49 PM
 *  Author: Belal Hassan
 */ 


#ifndef	BITMATH_H_
#define BITMATH_H_

#define Set_Bit(reg, bit) reg|=(1<<bit)
#define Clear_Bit(reg, bit) reg&=~(1<<bit)
#define Get_Bit(reg, bit) reg&(1<<bit)
#define Toggle_Bit(reg, bit) reg^=1<<bit

#endif /* BITMATH_H_ */