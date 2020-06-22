/*
 * BITMATH.h
 *
 * Created: 6/21/2020 7:38:58 PM
 *  Author: Maraghy
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_


#define GET_BIT(var,bit)     ((var>>bit)&1)
#define SET_BIT(var,bit)     var|=(1<<bit)
#define CLEAR_BIT(var,bit)   var&=~(1<<bit)
#define TOGGLE(var,bit)      var^=(1<<bit)



#endif /* BITMATH_H_ */