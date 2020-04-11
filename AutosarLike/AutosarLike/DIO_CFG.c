/*
 * DIO_CFG.c
 *
 * Created: 4/10/2020 2:00:08 PM
 *  Author: Maraghy
 */ 
#include "DIO_CFG.h"
#include "DIO_HW.h"
#include "BIT_MATH.h"

const Dio_pin_configType Dio_pin_config[]={
	/*PA0*/		{Input,High},
	/*PA1*/		{Output,Low},
	/*PA2*/		{Output,Low},
	/*PA3*/		{Output,Low},
	/*PA4*/		{Output,Low},
	/*PA5*/		{Output,Low},
	/*PA6*/	   	{Output,Low},
	/*PA7*/		{Output,Low},
	/*PB0*/		{Output,Low},
	/*PB1*/		{Output,Low},
	/*PB2*/		{Output,Low},
	/*PB3*/		{Output,Low},
	/*PB4*/		{Output,Low},
	/*PB5*/		{Output,Low},
	/*PB6*/		{Output,Low},
	/*PB7*/		{Output,Low},
	/*PC0*/		{Output,High},
	/*PC1*/		{Output,High},
	/*PC2*/		{Output,High},
	/*PC3*/		{Output,High},
	/*PC4*/		{Output,High},
	/*PC5*/		{Output,High},
	/*PC6*/		{Output,High},
	/*PC7*/		{Output,High},
	/*PD0*/		{Output,Low},
	/*PD1*/		{Output,Low},
	/*PD2*/		{Output,Low},
	/*PD3*/		{Output,Low},
	/*PD4*/		{Output,Low},
	/*PD5*/		{Output,Low},
	/*PD6*/		{Output,Low},
	/*PD7*/		{Output,Low},
};

void Dio_init(void)
{
	uint8 counter;
	uint8 currentPin ;
	uint8 currentPort;
	for(counter =Dio_Channel_A0; counter <PINCOUNT ; counter++)
	{
		currentPin = counter % 8;
		currentPort = counter /8;
		if(Dio_pin_config[counter].pinDirection ==Output)
		{
			switch (currentPort)
			{
				case Dio_PortA:
				SET_BIT(DDRA_REG,currentPin);
				break;
				case Dio_PortB:
				SET_BIT(DDRB_REG,currentPin);
				break;
				case Dio_PortC:
				SET_BIT(DDRC_REG,currentPin);
				break;
				case Dio_PortD:
				SET_BIT(DDRD_REG,currentPin);
				break;
			}//switch
		}//if
		else
		{
			switch (currentPort)
			{
				case Dio_PortA:
				CLR_BIT(DDRA_REG,currentPin);
				break;
				case Dio_PortB:
				CLR_BIT(DDRB_REG,currentPin);
				break;
				case Dio_PortC:
				CLR_BIT(DDRC_REG,currentPin);
				break;
				case Dio_PortD:
				CLR_BIT(DDRD_REG,currentPin);
				break;
			}//switch
			
		}//else
	}//for
}//func