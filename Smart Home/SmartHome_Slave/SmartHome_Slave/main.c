/*
 * SmartHome_Slave.c
 *
 * Created: 6/21/2020 7:31:32 PM
 * Author : Maraghy
 */ 

#include <avr/io.h>
#include "SPI.h"
#define F_CPU 16000000
#include <util/delay.h>
int main(void)
{
	SPI_Init();
	SET_BIT(DDRC,0);
	SET_BIT(DDRC,1);
    /* Replace with your application code */
    while (1) 
    { unsigned char Recivedbyte =SPI_Recive();
		_delay_ms(1000);
		switch(Recivedbyte){
		case 'A':SET_BIT(PORTC,0);
		break;
		case 'B':CLEAR_BIT(PORTC,0);
		break;
		case 'C':SET_BIT(PORTC,1);
	    break;
		case 'D':CLEAR_BIT(PORTC,1);
		break;
		
		
		}
    }
}

