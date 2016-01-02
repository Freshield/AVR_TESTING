/*
 * TEST26_TIMER2_CLOCK.cpp
 *
 * Created: 2014/4/10 23:08:03
 *  Author: Narcissus
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>

unsigned int TIMER2_COUNT,TIME_COUNT = 0;

uchar MINUTE_TEN,MINUTE_BIT,SECOND_TEN,SECOND_BIT = 0;

uchar DIRECTION = 0;

ISR(TIMER2_OVF_vect)
{
	TIMER2_NORMAL_PWM_set(0.01);
	
	TIMER2_COUNT ++;
	
	if (TIMER2_COUNT == 100)
	{
		TIMER2_COUNT = 0;
		
		TIME_COUNT ++;
		
		
		MINUTE_TEN = TIME_COUNT / 60 / 10;
		
		MINUTE_BIT = TIME_COUNT / 60 % 10;
		
		SECOND_TEN = TIME_COUNT % 60 / 10;
		
		SECOND_BIT = TIME_COUNT % 60 % 10;
		
		if (TIME_COUNT == 3600)
		{
			TIME_COUNT = 0;
		}
		
		
	}
}

ISR(TIMER1_OVF_vect)
{
	TIMER1_NORMAL_PWM_set(0.001);
	
	
	switch (DIRECTION)
	{
		
	case 0:NIXIE_4BIT_SHOW_L1(MINUTE_TEN,MINUTE_BIT,SECOND_TEN,SECOND_BIT);
	
	    DIRECTION = 1;
	
		break;
		
	case 1:NIXIE_4BIT_SHOW_L2(MINUTE_TEN,MINUTE_BIT,SECOND_TEN,SECOND_BIT);
	
	DIRECTION = 2;
	
	break;	
		
		case 2:NIXIE_4BIT_SHOW_L3(MINUTE_TEN,MINUTE_BIT,SECOND_TEN,SECOND_BIT);
		
		DIRECTION = 3;
		
		break;
			
			case 3:NIXIE_4BIT_SHOW_L4(MINUTE_TEN,MINUTE_BIT,SECOND_TEN,SECOND_BIT);
			
			DIRECTION = 0;
			
			break;
				
		
	}
	
	
}


int main(void)
{
	TIMER2_NORMAL_PWM_INIT();
	 
	TIMER2_NORMAL_PWM_set(0.01);
	
	TIMER1_NORMAL_PWM_INIT();
	
	TIMER1_NORMAL_PWM_set(0.001);
	
	NIXIE_4BIT_INIT();
	
	NIXIE_4BIT_SHOW(MINUTE_TEN,MINUTE_BIT,SECOND_TEN,SECOND_BIT);
	
	sei();
	
	
    while(1)
    {
         
    }
}