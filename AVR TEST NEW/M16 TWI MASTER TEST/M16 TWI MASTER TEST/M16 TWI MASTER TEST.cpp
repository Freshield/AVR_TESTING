/*
 * M16_TWI_MASTER_TEST.cpp
 *
 * Created: 2014/2/12 23:04:21
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_twi.h>

int main(void)
{
	M16_TWI_MASTER_INIT();
	
	
    while(1)
    {
		for (uchar i = 0;i < 16;i ++)
		{
			M16_TWI_MASTER_SEND(i);
			
			delay_second(8);
		}
        
    }
}