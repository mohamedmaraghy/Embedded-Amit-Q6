/*
 * UARTMAS.c
 *
 * Created: 6/21/2020 9:49:21 PM
 *  Author: Maraghy
 */ 
#include "UARTMAS.h"
#include <avr/io.h>
void UART_Init(){
	UBRRL=BAUD_EQ;
	UCSRB =(1<<RXEN)|(1<<TXEN);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);
}

void UART_Send(char data){
	
	while( !(UCSRA & (1<<UDRE)));
	UDR=data;
}

char UART_Receive(){
	while( !(UCSRA & (1<<RXC)));
	return UDR;
}
void UART_SendString(char *str){
	char i=0;
	while(str[i]!='\0'){
		UART_Send(str[i]);
		i++;
	}
}