/*
 * SPI.c
 *
 * Created: 6/21/2020 4:37:40 PM
 *  Author: Maraghy
 */ 
#include "BITMATH.h"
#include "SPI.h"
#include <avr/io.h>
void SPI_Init(){
	
	SET_BIT(DDRB,MOSI);
	SET_BIT(DDRB,SCK);
	SET_BIT(DDRC,CS);
	
	SET_BIT(SPCR,MSTR);
	SET_BIT(SPCR,SPE);
	SET_BIT(SPCR,SPR0);
	
}
unsigned char SPI_SEND(unsigned char sendByte){
	
	SPDR=sendByte;
	while(!(SPSR&(1<<SPIF)));
	return SPDR;
}