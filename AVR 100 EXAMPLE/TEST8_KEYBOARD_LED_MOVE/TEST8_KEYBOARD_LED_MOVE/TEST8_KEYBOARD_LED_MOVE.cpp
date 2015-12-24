/*
 * TEST8_KEYBOARD_LED_MOVE.cpp
 *
 * Created: 2014/2/22 16:36:42
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>
#include <E:\kuaipan\EDEN\avr\device\lib_keyboard.h>

int main(void)
{
	KEYBOARD_INIT_M16();
	
	
	
	 
    while(1)
    {
        KEYBOARD_MOVE_LED();
    }
}  