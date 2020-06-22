/*
 * SPI.c
 *
 * Created: 6/21/2020 7:40:05 PM
 *  Author: Maraghy
 */ 
#include "BITMATH.h"
#include "SPI.h"
#include <avr/io.h>
void SPI_Init(){
	
	DDRB|=(1<<MISO);
	DDRB&=~(1<<SS); //input pin
	SPCR|=(1<<SPE);
	
}
unsigned char SPI_Recive(){
	
	//SPDR =sendByte;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}
