/*
 * TEST20_TIMER1_TIMER2_NIXIE_4BIT_SHOWTIME.cpp
 *
 * Created: 2014/3/6 21:42:49
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>

uchar TIME[] = {0,0,0,0};

uchar TIME_NOW = 0;

uchar SECOND,MINUTE = 0;

uchar LIST_NIXIE = 0;

ISR(TIMER2_OVF_vect)
{
	cli();
	
	TIMER2_NORMAL_PWM_set(0.004);
	
	switch(LIST_NIXIE)
	
	{
		case 0: NIXIE_4BIT_SHOW_L1(TIME[3],TIME[2],TIME[1],TIME[0]);
		
		sei();
		
		LIST_NIXIE = 1;
		
		break;
		
		
		case 1: NIXIE_4BIT_SHOW_L2(TIME[3],TIME[2],TIME[1],TIME[0]);
		
		sei();
		
		LIST_NIXIE = 2;
		
		break;
		
		
		case 2: NIXIE_4BIT_SHOW_L3(TIME[3],TIME[2],TIME[1],TIME[0]);
		
		sei();
		
		LIST_NIXIE = 3;
		
		break;
		
		
		case 3: NIXIE_4BIT_SHOW_L4(TIME[3],TIME[2],TIME[1],TIME[0]);
		
		sei();
		
		LIST_NIXIE = 0;
		
		break;
		
		
	}
	
}



ISR(TIMER1_OVF_vect)
{
	TIMER1_NORMAL_PWM_set(1);
	
	++ TIME_NOW;
	
	MINUTE = TIME_NOW / 60;
	
	SECOND = TIME_NOW % 60;
	
	TIME[0] = SECOND % 10;
	
	TIME[1] = SECOND / 10;
	
	TIME[2] = MINUTE % 10;
	
	TIME[3] = MINUTE / 10;
	
	if (TIME_NOW == 3600)
	{
		TIME_NOW = 0;
	}
	
}


int main(void)
{
	
	TIMER2_NORMAL_PWM_INIT();
	
	TIMER2_NORMAL_PWM_set(0.004);
	
	TIMER1_NORMAL_PWM_INIT();
	
	TIMER1_NORMAL_PWM_set(1);
	
	NIXIE_4BIT_INIT();
	
	
	
	sei();
	
    while(1)
    {
        
    }
}