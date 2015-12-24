/*
 * TEST10_KEYBOARD_CODE_NIXIE_4BIT_SHOW.cpp
 *
 * Created: 2014/2/22 18:05:52
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
#include <E:\kuaipan\EDEN\avr\device\lib_keyboard.h>

int main(void)
{
	NIXIE_4BIT_INIT();
	
	uchar num = 0;
	
	uchar BUFFER[] = {0,0,0};
	
	KEY_DDR = 0X00;
	
	KEY_PORT = 0X00;
	
    while(1)
    {
		
		
		num = KEY_PIN;
        
		BUFFER[0] = num / 100;
		
		BUFFER[1] = num / 10 % 10;
		
		BUFFER[2] = num % 10;
		
		NIXIE_4BIT_SHOW(16,BUFFER[2],BUFFER[1],BUFFER[0]);
		
		
    }
}