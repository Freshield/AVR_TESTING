/*
 * TEST9_MATRIX_KEYBOARD_NIXIE.cpp
 *
 * Created: 2014/2/22 17:23:04
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
#include <E:\kuaipan\EDEN\avr\device\lib_matrix_keyboard.h>

int main(void)
{
	
	NIXIE_INIT();
	
    while(1)
    {
       if (NORMAL_KEY_DOWN() == 1)
       {
		   delay_reduce(100);
		   
		   if (NORMAL_KEY_DOWN() == 1)
		   {
			   
			   NIXIE_SHOW(NORMAL_KEY_READ());
			   
			   
		   }
		   
		   
		   
		   
		   
		   
       }
    }
}