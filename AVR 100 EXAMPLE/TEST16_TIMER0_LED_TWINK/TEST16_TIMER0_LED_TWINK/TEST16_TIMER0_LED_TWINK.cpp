/*
 * TEST16_TIMER0_LED_TWINK.cpp
 *
 * Created: 2014/3/5 20:10:12
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>

uchar TIME_COUNT = 0;


ISR(TIMER0_OVF_vect)
{
	TIMER0_NORMAL_PWMA_TCNT0_set(0.01);
	
	if (++ TIME_COUNT!= 50)return;
	
	TIME_COUNT = 0;
	 
	LED_TWINK(0);
	
}



int main(void)
{
	LED_INIT();
	
	TIMER0_NORMAL_PWM_INIT();
	
	TIMER0_NORMAL_PWMA_TCNT0_set(0.01);
	
	sei();
	
    while(1)
    {
        
    }
}