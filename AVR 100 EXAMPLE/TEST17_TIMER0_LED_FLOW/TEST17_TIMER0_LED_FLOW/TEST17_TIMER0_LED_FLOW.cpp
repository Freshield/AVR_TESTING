/*
 * TEST17_TIMER0_LED_FLOW.cpp
 *
 * Created: 2014/3/6 15:09:53
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>

uchar TIME_COUNT = 0;


int main(void)
{
	TIMER0_NORMAL_PWM_INIT();
	
	LED_INIT();
	
	LED_PORT = 0X01;
	
	TIMER0_NORMAL_PWM_TCNT0_set(0.01);
	
    while(1)
    {
       TIMER0_NORMAL_PWM_SEARCH();
	   
	   TIMER0_NORMAL_PWM_TCNT0_set(0.01);
	   
	   ++ TIME_COUNT;
	   
	   if (TIME_COUNT == 50)
	   {
		   TIME_COUNT = 0;
		    
		   LED_PORT = LED_PORT << 1;
		   
		   if (LED_PORT == 0X00)
		   {
			   LED_PORT = 0X01;
		   }
		  
	   }
	   
	   
    }
}