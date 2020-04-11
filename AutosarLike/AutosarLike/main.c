/*AutosarLike.c
 *STD_Types.h
 *dio_hw.h 
 *bitmath.h
 *dio_types.h
 *dio.h
 *dio.c
 *dio_cfg.h
 *dio_cfg.c
*/ 
#define F_CPU 1000000
#include "BIT_MATH.h"
#include "DIO_HW.h"
#include "STD_Types.h"
#include "DIO.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"
#include <util/delay.h>
int main(void)
{
Dio_init();
Dio_WriteChannel(Dio_Channel_A0,High);
    while (1)
    {
		if(Dio_ReadChannel(Dio_Channel_A0)==Low)
		{
			     int i;
				 for(i=0;i<8;i++){
				   _delay_ms(100);
			        Dio_WriteChannel(Dio_Channel_C0+i,Low);
			        _delay_ms(200);
			        Dio_WriteChannel(Dio_Channel_C0+i,High);
			        _delay_ms(200);
			       /* Dio_WriteChannel(Dio_Channel_C1,Low);
			        _delay_ms(200);
			        Dio_WriteChannel(Dio_Channel_C1,High);
			        _delay_ms(200);
				    Dio_WriteChannel(Dio_Channel_C2,Low);
				    _delay_ms(200);
				    Dio_WriteChannel(Dio_Channel_C2,High);
				    _delay_ms(200);
					Dio_WriteChannel(Dio_Channel_C3,Low);
					_delay_ms(200);
					Dio_WriteChannel(Dio_Channel_C3,High);
					_delay_ms(200);
					Dio_WriteChannel(Dio_Channel_C4,Low);
					_delay_ms(200);
					Dio_WriteChannel(Dio_Channel_C4,High);
					_delay_ms(200);
					Dio_WriteChannel(Dio_Channel_C5,Low);
					_delay_ms(200);
					Dio_WriteChannel(Dio_Channel_C5,High);
					_delay_ms(200);
					Dio_WriteChannel(Dio_Channel_C6,Low);
					_delay_ms(200);
					Dio_WriteChannel(Dio_Channel_C6,High);
					_delay_ms(200);
					Dio_WriteChannel(Dio_Channel_C7,Low);
					_delay_ms(200);
					Dio_WriteChannel(Dio_Channel_C7,High);
					_delay_ms(200);*/
				   
				 }
		}
		
	else{
		Dio_WritePort(Dio_PortC,0XFF);
		}
		
    }
}

