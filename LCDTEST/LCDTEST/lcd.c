/*
 * lcd.c
 *
 * Created: 4/10/2020 7:01:15 PM
 *  Author: Maraghy
 */ 
#include "lcd.h"


void LCD_Init (void)  
{
	LCD_Dir = 0xF0;		
	LCD_Dir_Control=0x0E; 
	LCD_Port_Control &= ~(1<<2);
	_delay_ms(20);		
	
	LCD_Command(0x33);
	LCD_Command(0x32);	
	LCD_Command(0x28);	
	LCD_Command(0x0c);	
	LCD_Command(0x06);	
	LCD_Command(0x01);	
}

void LCD_Command( unsigned char cmnd )
{
	LCD_Port = (LCD_Port & 0x0F) | (cmnd & 0xF0);
	LCD_Port_Control &= ~ (1<<RS);		
	LCD_Port_Control |= (1<<EN);		
	_delay_us(10);
	LCD_Port_Control &= ~ (1<<EN);
	_delay_ms(2);
	LCD_Port = (LCD_Port & 0x0F) | (cmnd << 4);
	LCD_Port_Control |= (1<<EN);
	_delay_us(1);
	LCD_Port_Control &= ~ (1<<EN);
	_delay_ms(2);
}


void LCD_Char( unsigned char data )
{
	LCD_Port = (LCD_Port & 0x0F) | (data & 0xF0);
	LCD_Port_Control |= (1<<RS);  
	LCD_Port_Control|= (1<<EN);
	_delay_us(10);
	LCD_Port_Control &= ~ (1<<EN);
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (data << 4);  
	LCD_Port_Control |= (1<<EN);
	_delay_us(10);
	LCD_Port_Control &= ~ (1<<EN);
	_delay_ms(7);
}


void LCD_String (char *str)		

{
	int i;
	for(i=0;str[i]!=0;i++)		
	
	{
		LCD_Char (str[i]);
	}
}
/*
*/
void LCD_String_xy (char row, char pos, char *str)	
{
	if (row == 0 && pos<16)
	LCD_Command((pos & 0x0F)|0x80);	
	else if (row == 1 && pos<16)
	LCD_Command((pos & 0x0F)|0xC0);	
	LCD_String(str);		
}
/*
*/
void LCD_Clear()
{
	LCD_Command (0x01);		
	_delay_ms(2);
	LCD_Command (0x80);		
}
void LCD_Custom_Char(unsigned char loc, unsigned char *msg)
{
	unsigned char i;
	if(loc<8)
	{
		LCD_Command (0x40 + (loc*8));	/* Command 0x40 and onwards forces the device to point CGRAM address */
		for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		LCD_Char(msg[i]);
	}
}