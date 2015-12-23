/*
 * TEST3_FLOW_ARRAY_LED.cpp
 *
 * Created: 2014/2/21 15:41:32
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>


int main(void)
{
	 LED_DDR = 0XFF;
	 
    while(1)
    {
       for (uchar i = 0;i < 32;i ++) 
       {
		  
		   LED_PORT = LED_ARRAY[i];
		   
		   delay_second(5);
		   
       }
	   
	   
    }
}