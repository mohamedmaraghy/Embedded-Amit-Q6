/*
 * DIO.c
 *
 * Created: 4/9/2020 7:01:24 PM
 *  Author: Maraghy
 */ 
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_Types.h"
#include "DIO_HW.h"
#include "DIO.h"

void Dio_WriteChannel(Dio_ChannelType channelId,STD_levelType level){
	 Dio_PortType portx=channelId/8;
	 Dio_ChannelType channelPos=channelId%8;
	switch(portx){
		case Dio_PortA: if(level==High){
			SET_BIT(PORTA_REG,channelPos);
		}
		else {
			CLR_BIT(PORTA_REG,channelPos);
		}
		break;
		
		case Dio_PortB: if(level==High){
			SET_BIT(PORTB_REG,channelPos);
		}
		else {
			CLR_BIT(PORTB_REG,channelPos);
		}break;
		case Dio_PortC: if(level==High){
			SET_BIT(PORTC_REG,channelPos);
		}
		else {
			CLR_BIT(PORTC_REG,channelPos);
		}break;
		case Dio_PortD:  if(level==High){
				SET_BIT(PORTD_REG,channelPos);
				}
				else {CLR_BIT(PORTD_REG,channelPos);
		}break;	
	}
}


void Dio_WritePort(Dio_PortType portId,uint8 value){
	switch(portId){
		case Dio_PortA:PORTA_REG=value;
		break;
		case Dio_PortB:PORTB_REG=value;
		break;
		case Dio_PortC:PORTC_REG=value;
		break;
		case Dio_PortD:PORTD_REG=value;
		break;	
	}
}


void Dio_FlipChannel(Dio_ChannelType channelId){
	 Dio_PortType portx=channelId/8;
	 Dio_ChannelType channelPos=channelId%8;
	 switch(portx){
		 case Dio_PortA: TOGGLE_BIT(PORTA_REG,channelPos);
		 break;
		 case Dio_PortB: TOGGLE_BIT(PORTB_REG,channelPos);
		 break;
		 case Dio_PortC: TOGGLE_BIT(PORTC_REG,channelPos);
		 break;
		 case Dio_PortD: TOGGLE_BIT(PORTD_REG,channelPos);
		 break;	
	 }
}

void Dio_FlipPort(Dio_PortType portId){
	switch(portId){
		case Dio_PortA: Dio_WritePort(portId,~PORTA_REG);
		break;
		case Dio_PortB: Dio_WritePort(portId,~PORTB_REG);
		break;
		case Dio_PortC: Dio_WritePort(portId,~PORTC_REG);
		break;
		case Dio_PortD: Dio_WritePort(portId,~PORTD_REG);
		break;
	}
}




STD_levelType Dio_ReadChannel(Dio_ChannelType channelId){
	 Dio_PortType portx=channelId/8;
	 Dio_ChannelType channelPos=channelId%8;
	switch(portx){
		case Dio_PortA:return GET_BIT(PINA_REG,channelPos);
		break;
		case Dio_PortB:return GET_BIT(PINB_REG,channelPos);
		break;
		case Dio_PortC:return GET_BIT(PINC_REG,channelPos);
		break;
		case Dio_PortD:return GET_BIT(PIND_REG,channelPos);
		break;	
	}
return 3;
}
uint8 Dio_ReadPort(Dio_PortType portId){
	switch(portId){
		case Dio_PortA:return PINA_REG;
		break;
		case Dio_PortB:return PINB_REG;
		break;
		case Dio_PortC:return PINC_REG;
		break;
		case Dio_PortD:return PIND_REG;
		break;	
	}
return 0;	
}
