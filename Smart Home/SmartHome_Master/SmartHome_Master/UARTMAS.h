/*
 * UARTMAS.h
 *
 * Created: 6/21/2020 9:48:51 PM
 *  Author: Maraghy
 */ 


#ifndef UARTMAS_H_
#define UARTMAS_H_

#define F_CPU	16000000
#define BAUD   9600 //Baud of HC05 bluetooth module
#define BAUD_EQ		((F_CPU/(BAUD*16UL))-1)
void UART_Init();
char UART_Receive();
void UART_SendString(char *str);
void UART_Send(char data);



#endif /* UARTMAS_H_ */