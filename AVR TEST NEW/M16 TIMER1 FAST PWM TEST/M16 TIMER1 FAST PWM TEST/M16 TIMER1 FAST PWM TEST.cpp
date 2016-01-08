/*
 * M16_TIMER1_FAST_PWM_TEST.cpp
 *
 * Created: 2014/1/13 16:22:08
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>

ISR(TIMER1_COMPA_vect)
{
	
	
}

ISR(TIMER1_OVF_vect)
{
	 
}


 
int main(void)
{
	
	TIMER1_PHASE_CORRECTION_10_init();
	
	sei(); 
	
    while(1)
    {
      
	 for (uchar i = 0;i <10;i ++)
	   {
		   delay_second(30);
		   
		   OCR1A = i * 128;
		   
		   delay_second(30);
	   }
	 
    }
}