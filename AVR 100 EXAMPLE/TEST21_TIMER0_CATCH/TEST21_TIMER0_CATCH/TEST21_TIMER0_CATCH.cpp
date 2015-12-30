/*
 * TEST21_TIMER0_CATCH.cpp
 *
 * Created: 2014/3/7 12:02:19
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>

uchar TIME_COUNT,TEN,BIT = 0;



ISR(TIMER0_OVF_vect)
{
	TCNT0 = 255; 
	
	++ TIME_COUNT;
	
	TEN = TIME_COUNT / 10;
	
	BIT = TIME_COUNT % 10;
	
	if (TIME_COUNT == 99)
	{
		TIME_COUNT = 0;
	}
	
	
}


int main(void)
{
	NIXIE_4BIT_INIT();
	
	TIMER0_CATCH_PWM_INIT();
	
	sei();
	
    while(1)
    {
        NIXIE_4BIT_SHOW(0,0,TEN,BIT);
    }
}