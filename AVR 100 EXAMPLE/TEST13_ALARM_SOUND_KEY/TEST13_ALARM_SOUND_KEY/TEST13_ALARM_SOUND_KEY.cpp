/*
 * TEST13_ALARM_SOUND_KEY.cpp
 *
 * Created: 2014/3/3 15:03:44
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
	
	
    while(1)
    {
       if (KEY_DOWN() == 1)
       {
		   uchar SOUND_NUM = keyscan();
		   
		   ALARM(SOUND_NUM);
		   
		  
		   
       }
	   else
	   {
		   CLEAR_ALARM();
		   
	   }
	  
	   
    }
}