/*
 * TEST1_BLINK_LED.cpp
 *
 * Created: 2014/2/20 15:21:17
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>


int main(void)
{
	
	
    while(1)
    {
        LED_BLINK(3,3);
    }
}