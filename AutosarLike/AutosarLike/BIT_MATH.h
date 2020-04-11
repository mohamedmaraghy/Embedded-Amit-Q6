/*
 * BIT_MATH.h
 *
 * Created: 4/9/2020 4:45:57 PM
 *  Author: Maraghy
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define GET_BIT(var,bit) ((var>>bit)&1)
#define SET_BIT(var,bit) var|=(1<<bit)
#define CLR_BIT(var,bit) var&=~(1<<bit)
#define TOGGLE_BIT(var,bit) var^=(1<<bit)




#endif /* BIT_MATH_H_ */