/*
 * TEST23_ALARM_FLOW_LED.cpp
 *
 * Created: 2014/3/8 13:26:30
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>
#include <E:\kuaipan\EDEN\avr\system\lib_external_interrupt.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>
#include <E:\kuaipan\EDEN\avr\device\lib_alarm.h>

uchar ON_OFF = 0;

volatile uchar FRQ = 0X00;

ISR(INT0_vect)
{
	 
	
	if (ON_OFF) 
	{
		TIMSK |= (1 << TOIE0) | (1 << TOIE1);
		
		LED_PORT = 0X01;
		
		FRQ = 0X00; 
		
	}
	
	else
	{
		
		TIMSK = 0X00;
		
		LED_PORT = 0X00;
		
		CLEAR_ALARM();
		
	}
	
	
	
	ON_OFF = !ON_OFF;
}

ISR(TIMER0_OVF_vect)
{
	TIMER0_NORMAL_PWM_TCNT0_set(0.2);
	
	 
	  
	LED_LEFT_CIRCLE();
	
	 
}

ISR(TIMER1_OVF_vect)
{
	TCNT1 = 61758 + FRQ;
	
	RE_TURE_SOUND();
	
	
	
}




int main(void)
{
	LED_INIT();
	
	EXTERNAL_INTERRUPT0_INIT_M16();
	
	TIMER0_NORMAL_PWM_INIT();
	
	TIMER1_NORMAL_PWM_INIT();
	
	TIMER0_NORMAL_PWM_TCNT0_set(0.1);
	
	TCNT1 = 61758;
	
	TIMSK = 0X00;
	
	sei();
	 
    while(1)
    {
        FRQ ++;
		
		delay_reduce(3000); 
    }
}