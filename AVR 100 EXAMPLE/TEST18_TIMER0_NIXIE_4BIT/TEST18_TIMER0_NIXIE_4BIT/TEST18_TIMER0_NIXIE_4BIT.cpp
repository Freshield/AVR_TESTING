/*
 * TEST18_TIMER0_NIXIE_4BIT.cpp
 *
 * Created: 2014/3/6 16:00:44
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>

uchar LIST_NIXIE = 0;

ISR(TIMER0_OVF_vect)
{
	cli();
	
	TIMER0_NORMAL_PWM_TCNT0_set(0.004);
	
	switch(LIST_NIXIE)
	
	{
		case 0: NIXIE_4BIT_SHOW_L1(1,3,1,4);
		
		        sei();
				
				LIST_NIXIE = 1;
				
				break;
		
		
		case 1: NIXIE_4BIT_SHOW_L2(1,3,1,4);
		
		sei();
		
		LIST_NIXIE = 2;
		
		break;
		
		 
		case 2: NIXIE_4BIT_SHOW_L3(1,3,1,4);
		
		sei();
		
		LIST_NIXIE = 3;
		
		break;
		
		
		case 3: NIXIE_4BIT_SHOW_L4(1,3,1,4);
		
		sei();
		
		LIST_NIXIE = 0;
		
		break;
		
		
	}
	
}
 
 
int main(void)
{ 
	TIMER0_NORMAL_PWM_INIT();
	
	NIXIE_4BIT_INIT();
	
	TIMER0_NORMAL_PWM_TCNT0_set(0.004);
	 
	  
	sei();
	
	 
	
    while(1)
    { 
      // NIXIE_4BIT_SHOW(1,3,1,4);
    }
}