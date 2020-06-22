/*
 * SPI.h
 *
 * Created: 6/21/2020 7:39:45 PM
 *  Author: Maraghy
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "BITMATH.h"
void SPI_Init();
unsigned char SPI_Recive();
#define MOSI	5
#define MISO	6
#define SCK		7
#define CS		0
#define SS_ENABLE()		CLEAR_BIT(PORTC,CS)
#define SS_DISABLE()	SET_BIT(PORTC,CS)
#define SS 4




#endif /* SPI_H_ */