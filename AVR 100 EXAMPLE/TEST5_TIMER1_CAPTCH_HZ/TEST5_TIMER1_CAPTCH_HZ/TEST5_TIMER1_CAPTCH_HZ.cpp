/*
 * TEST5_TIMER1_CAPTCH_HZ.cpp
 *
 * Created: 2014/3/8 21:16:11
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>

uchar TIME_COUNT = 0;

uchar THOUSAND,HUNDRED,TEN,BIT = 0;

uchar CAPA,CAPB = 0;

ISR(TIMER1_CAPT_vect)
{
	if (CAPA == 0)
	{
		
		CAPA = ICR1;
		
	}
	else
	{
		CAPB = ICR1 - CAPA;
		
		TIME_COUNT = F_CPU / CAPB;
		
		TIMSK = 0X00;
		
		THOUSAND = TIME_COUNT / 1000;
		
		HUNDRED = TIME_COUNT % 1000 / 100;
		
		TEN = TIME_COUNT % 100 / 10;
		
		BIT = TIME_COUNT % 10;
		
		
		
		
	}
	
	
}



int main(void)
{
	NIXIE_4BIT_INIT();
	
	TIMER1_CATCH_PWM_INIT();
	
	sei();
	
	
    while(1)
    {
        NIXIE_4BIT_SHOW(THOUSAND,HUNDRED,TEN,BIT);
    }
}