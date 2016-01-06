/*
 * M16_SLEEP_TEST.cpp
 *
 * Created: 2014/1/5 15:37:07
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\system\lib_external_interrupt.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
#include <E:\kuaipan\EDEN\avr\device\lib_keyboard.h>
#include <E:\kuaipan\EDEN\avr\system\lib_sleep.h>
uchar keyv;

ISR(INT0_vect)
{
   sleep_disable();
	
} 

 
int main(void)
{
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	nixie_init();
	KEYBOARD_INIT_M16();
	EXTERNAL_INTERRUPT0_INIT_M16();
	
	sei();
	
	
    while(1)
    {
		keyv = keyscan();
		
       if (keyv == 16)
       {
      
     
			sleep_enable();
			
			sleep_cpu();
			
			sleep_disable();
		 }	
		 
			 nixie_show(keyv);
		          	
    }
}