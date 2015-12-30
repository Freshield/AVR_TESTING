/*
 * TEST22_TIMER1_BEEP_DING_DONG.cpp
 *
 * Created: 2014/3/7 13:24:24
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>
#include <E:\kuaipan\EDEN\avr\device\lib_keyboard.h> 
#include <E:\kuaipan\EDEN\avr\device\lib_alarm.h>

float SOUND_HZ = 65536 - 5161;

ISR(TIMER1_OVF_vect)
{
	RE_TURE_SOUND(); 
	 
	TCNT1 = SOUND_HZ;
	
}


int main(void) 
{
	ALARM_INIT();
	
	KEYBOARD_INIT_M16();
	
	TCCR1B = 0x01;
	
	TIMSK = 0X00;
	
	TCNT1 = 65536 - 5161;
	
	sei();
	
    while(1)
    {
        if (KEY_DOWN() == 1)
        {
			TIMSK = 1 << TOIE1;
			
			SOUND_HZ = 65536 -5161;
			 
			delay_second(3); 
			
			SOUND_HZ = 65536 - 7373;
			
			delay_second(5);
			
			CLEAR_ALARM();
			
			TIMSK = 0X00;
			
        }
    }
}