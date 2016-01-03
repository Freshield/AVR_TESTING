/*
 * M16_KEYBOARD_NIXIE_SHOW.cpp
 *
 * Created: 2014/1/3 23:31:25
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
#include <E:\kuaipan\EDEN\avr\device\lib_keyboard.h>
 
int main(void)
{ 
	nixie_init(); 
	 
    while(1) 
    {   
		uchar keyv = keyscan(); 
		 
        nixie_show(keyv);    
    }
}