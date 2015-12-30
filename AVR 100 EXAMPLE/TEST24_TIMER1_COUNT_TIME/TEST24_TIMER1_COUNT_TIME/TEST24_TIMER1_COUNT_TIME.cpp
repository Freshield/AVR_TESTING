/*
 * TEST24_TIMER1_COUNT_TIME.cpp
 *
 * Created: 2014/3/8 15:13:29
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>
#include <E:\kuaipan\EDEN\avr\system\lib_external_interrupt.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>

unsigned int TIME_COUNT = 0;

uchar TEN,BIT,DECILE,PRECENTILE = 0;

uchar DIRECTION = 0;

ISR(TIMER1_OVF_vect)
{
	TIMER1_NORMAL_PWM_set(0.01);
	
	++ TIME_COUNT;
	
	TEN = TIME_COUNT / 1000;
	
	BIT = TIME_COUNT % 1000 / 100;
	
	DECILE = TIME_COUNT % 100 / 10;
	
	PRECENTILE = TIME_COUNT % 10;
	
	if (TIME_COUNT == 9999)
	{
		TIME_COUNT = 0;
	}
	 
	
	
	
}

ISR(INT0_vect)
{
	   
	   delay_reduce(10);
	   
	   if ( (PIND & (1 << INT0_FOOT)) == 0X00)
	   {
		   
		   switch(DIRECTION)
		   
		   {
			   case 0:  TIMSK |= 1 << TOIE1;
			   
			   DIRECTION = 1;
			   
			   break;
			   
			   
			   case 1:  TIMSK = 0X00;
			   
			   DIRECTION = 2;
			   
			   break;
			   
			   case 2:  TIME_COUNT = 0;
			   
			   TEN = 0;
			   
			   BIT = 0;
			   
			   DECILE = 0;
			   
			   PRECENTILE = 0;
			   
			   DIRECTION = 0;
			   
			   break;
			   
		   }
		   
	   }
	
		
		
		
	
	
}



int main(void)
{
	NIXIE_4BIT_INIT();
	
	EXTERNAL_INTERRUPT0_INIT_M16();
	
	TIMER1_NORMAL_PWM_INIT();
	
	TIMER1_NORMAL_PWM_set(0.01);
	
	TIMSK = 0X00;
	
	sei(); 
	  
	
    while(1)
    {
        NIXIE_4BIT_SHOW(TEN,BIT + 17,DECILE,PRECENTILE);
    }
}