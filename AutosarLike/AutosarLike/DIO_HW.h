/*
 * DIO_HW.h
 *
 * Created: 4/9/2020 4:33:29 PM
 *  Author: Maraghy
 */ 


#ifndef DIO_HW_H_
#define DIO_HW_H_
#include "STD_Types.h"
#define DDRA_REG *((volatile uint8*)0X3A)
#define DDRB_REG *((volatile uint8*)0X37)
#define DDRC_REG *((volatile uint8*)0X34)
#define DDRD_REG *((volatile uint8*)0X31)

#define PORTA_REG *((volatile uint8*)0X3B)
#define PORTB_REG *((volatile uint8*)0X38)
#define PORTC_REG *((volatile uint8*)0X35)
#define PORTD_REG *((volatile uint8*)0X32)

#define PINA_REG  *((const volatile uint8*)0X39)
#define PINB_REG  *((const volatile uint8*)0X36)
#define PINC_REG  *((const volatile uint8*)0X33)
#define PIND_REG  *((const volatile uint8*)0X30)

#endif /* DIO_HW_H_ */