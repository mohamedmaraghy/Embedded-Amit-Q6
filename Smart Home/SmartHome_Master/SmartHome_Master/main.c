/*
 * SmartHome_Master.c
 *
 * Created: 6/21/2020 4:31:49 PM
 * Author : Maraghy
 */ 

#define F_CPU	16000000


#include <util/delay.h>

#include "BITMATH.h"
#include "SPI.h"
#include "UARTMAS.h"
#include <avr/interrupt.h>
ISR(USART_RXC_vect)
{
	
	//uartInit();
	char ReceivedByte ;
	ReceivedByte = UDR;  //data from bluetooth Module 
	switch(ReceivedByte)  
	{
		
		case 'A':   // SET LED0 on
		SS_ENABLE();
		unsigned char recvByte=SPI_SEND(0x0A);
		SS_DISABLE();
		_delay_ms(1000);
		
		break;
		//_____________________________________
		
		case 'B':         //SET LED0 off
		SS_ENABLE();
		         recvByte=SPI_SEND(0x0B);
		SS_DISABLE();
		_delay_ms(1000);
		break;
		
		//____________________________________
		case 'C':             //SET LED1  on
		SS_ENABLE();
		 recvByte=SPI_SEND(0x0C);
		SS_DISABLE();
		_delay_ms(1000);
		break;
		
		//__________________________________________
		
		case 'D':           //SET LED1  off
		SS_ENABLE();
	    recvByte=SPI_SEND(0x0D);
		SS_DISABLE();
		_delay_ms(1000);
		break;		  
	}
}



int main(void)
{
	
	_delay_ms(1000);
	UART_Init();
	SPI_Init();
	sei();
    while (1) 
    {
		SPI_SEND(0x0A);
		UART_SendString("SMART_HOME");
		_delay_ms(2000);

    }
}

