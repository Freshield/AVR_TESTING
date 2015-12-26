/*
 * TEST12_ALARM_KEY.cpp
 *
 * Created: 2014/3/2 20:37:18
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_keyboard.h>
#include <E:\kuaipan\EDEN\avr\device\lib_alarm.h>

int main(void)
{
	ALARM_INIT();
	
	KEYBOARD_INIT_M16();
	
	//DDRA = 0XFF;
		
    while(1) 
    { 
        
         if (KEY_DOWN() == 1) 
        {  
		    
			//PORTA = 0xff;
			ALARM(3); 
			
        }
		else
		{
			//PORTA = 0x00;
			CLEAR_ALARM();
			
		}			
    }
}