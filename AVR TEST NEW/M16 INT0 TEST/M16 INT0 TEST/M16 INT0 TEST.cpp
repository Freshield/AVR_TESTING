/*
 * M16_INT0_TEST.cpp
 *
 * Created: 2014/1/4 17:53:32
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\system\lib_external_interrupt.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>

uchar number = 0;
uchar read;


int main(void)
{
	EXTERNAL_INTERRUPT0_INIT_M16();
	nixie_init();
	
	sei();
	
    while(1)
    {
        nixie_show(number); 
    }
}

ISR(INT0_vect)
{
	delay_reduce(100000);
	
	read = PIND;
	
	read &= 0x04;
	 
	if (read == 0)
	{
	
	if (number < 16)
	{ 
		number ++;
	}
	else
	{
		number = 0;
	}
    }
}