/*
 * TEST14_INT0_COUNT.cpp
 *
 * Created: 2014/3/3 16:21:50
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
#include <E:\kuaipan\EDEN\avr\system\lib_external_interrupt.h>

uchar COUNT_NUM = 0;

ISR(INT0_vect)
{
	
	COUNT_NUM ++;
	
	if (COUNT_NUM == 16)
	{
		COUNT_NUM = 0;
	}
	
	
	
}

int main(void)
{
	NIXIE_INIT();
	
	EXTERNAL_INTERRUPT0_INIT_M16();
	
	sei();
	
    while(1)
    {
        NIXIE_SHOW(COUNT_NUM);
    }
}