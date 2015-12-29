/*
 * LED_FLOW_TEST.cpp
 *
 * Created: 2014/1/3 21:43:15
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>

int main(void)
{
	
    while(1) 
    {    
       led_flow();    
    }
}