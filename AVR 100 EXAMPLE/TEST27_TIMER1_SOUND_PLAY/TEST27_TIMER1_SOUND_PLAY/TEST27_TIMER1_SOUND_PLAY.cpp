/*
 * TEST27_TIMER1_SOUND_PLAY.cpp
 *
 * Created: 2014/4/13 13:53:30
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>
#include <E:\kuaipan\EDEN\avr\device\lib_alarm.h>
#include <E:\kuaipan\EDEN\avr\device\lib_keyboard.h>

#define ENABLE_OCIE() (TIMSK |= 1 << OCIE1A);
#define DISABLE_OCIE() (TIMSK &= ~(1 << OCIE1A));

const int TONE_FRQ[] = {262,294,330,349,392,440,494,523,587,659,698,784,880,1046};

ISR(TIMER1_COMPA_vect)
{
	RE_TURE_SOUND();
}


int main(void)
{
	ALARM_INIT();
	
	KEYBOARD_INIT_M16();
	
	DDRA = 0XFF;PORTA = 0X00;
	
	TIMER1_CTC_OCR1A_INIT();
	
	DISABLE_OCIE();
	
	uchar i = 0;
	
	sei();
	
	
    while(1) 
    {
		
       
	   
	   KEY_ACCURATE();
	   
	   PORTA = ~PORTA;
	   
	   
	   
		   OCR1A = F_CPU / 2 / TONE_FRQ[i];
		   
		   TCNT1 = 0;
		   
		   ENABLE_OCIE();
		   
		   delay_second(5);
		   
		   DISABLE_OCIE();
		   
		   
		   CLEAR_ALARM();
		   
		   delay_second(2);
		   
	i ++;	   
    
	if (i == 14)
	{
		i = 0;
	}
	
    }
	
	
	
	
}