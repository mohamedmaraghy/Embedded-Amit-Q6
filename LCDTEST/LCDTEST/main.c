/*
 * LCDTEST.c
 *
 * Created: 4/10/2020 7:00:04 PM
 * Author : Maraghy
 */ 

#include <avr/io.h>
#include "lcd.h"
unsigned char smileyFace[8] = {
	0x00,
	0x00,
	0x0A,
	0x00,
	0x11,
	0x0E,
	0x00,
	0x00
};
int main(void)
{
	
	
	 LCD_Init();			
	 
	 LCD_String("Mohamed Amr");	
	 _delay_ms(500);
	 LCD_Command(0xC0);		
	 LCD_String("AmitQ6");
	 _delay_ms(500);
	
	LCD_Custom_Char(0,smileyFace);
	LCD_Command(0XCF);
	LCD_Char(0);
	
    while (1) 
    {
    }
}

