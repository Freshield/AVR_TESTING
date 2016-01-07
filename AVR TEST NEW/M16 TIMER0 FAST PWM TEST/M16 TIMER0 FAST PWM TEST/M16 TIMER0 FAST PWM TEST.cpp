/*
 * M16_TIMER0_FAST_PWM_TEST.cpp
 *
 * Created: 2014/1/7 0:54:01
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>

uchar count;

uchar condition; 

  
ISR(TIMER0_OVF_vect)
{
	
}


ISR(TIMER0_COMP_vect)

{
	
	
}

int main(void)
{
	TIMER0_FASTPWM_OCR0_init();
	
	count = 0;
	
	condition = 0;
	
	sei();
	
	
    while(1) 
    {
        if (condition == 0)
        {
			
			count ++;
			
			if (count >= 250)
			{
				condition = 1;
				
			}
        }
		else
		{
			count --;
			
			if (count == 0)
			{
				condition = 1;
			}
		}
		
		OCR0 = count;
		
		delay_second(3); 
		
		
    } 
}



