/*
 * M16_TWI_SLAVE_TEST.cpp
 *
 * Created: 2014/2/17 16:24:58
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_twi.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>

uchar show = 0;

ISR(TWI_vect)
{
	
	
	show = M16_TWI_SLAVE_RESERVE();
	
	if (show == 255)
	{
		delay_reduce(10);
	}
	else
	{ 
		nixie_show(show);
	}
	
	
	
}
 

int main(void)
{
	M16_TWI_SLAVE_INIT();
	
	nixie_init();
	
	sei();
	
	nixie_show(show);
	
    while(1)
    {
       
         
    }
}