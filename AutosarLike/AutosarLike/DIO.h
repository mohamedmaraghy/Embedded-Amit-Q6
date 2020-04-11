/*
 * DIO.h
 *
 * Created: 4/9/2020 5:15:06 PM
 *  Author: Maraghy
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "STD_Types.h"
#include "DIO_Types.h"

void Dio_WriteChannel(Dio_ChannelType channelId,STD_levelType level);
void Dio_WritePort(Dio_PortType portId,uint8 value);
void Dio_FlipChannel(Dio_ChannelType channelId);
void Dio_FlipPort(Dio_PortType portId);

STD_levelType Dio_ReadChannel(Dio_ChannelType channelId);
uint8 Dio_ReadPort(Dio_PortType portId);




#endif /* DIO_H_ */