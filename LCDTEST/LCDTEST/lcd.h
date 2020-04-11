/*
 * lcd.h
 *
 * Created: 4/10/2020 7:00:28 PM
 *  Author: Maraghy
 */ 


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 16000000UL			

#include <avr/io.h>			
#include <util/delay.h>			

#define LCD_Dir				  DDRA
			
#define LCD_Port			  PORTA	
		
#define LCD_Dir_Control		  DDRB	
		
#define LCD_Port_Control	  PORTB	
		
#define RS					  1		
#define EN					  3
#define RW					  2			

void LCD_Init (void) ;
void LCD_Command( unsigned char cmnd );
void LCD_Char( unsigned char data );
void LCD_String (char *str);
void LCD_String_xy (char row, char pos, char *str);
void LCD_Clear();
void LCD_Custom_Char(unsigned char loc, unsigned char *msg);




#endif /* LCD_H_ */