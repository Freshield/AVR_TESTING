/*
 * TEST7_NIXIE_4BIT_SHOW.cpp
 *
 * Created: 2014/2/21 22:00:21
 *  Author: Narcissus
 */ 

 
#include <avr/io.h> 
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
 
int main(void)
{    
	NIXIE_4BIT_INIT();     
	  
    while(1)       
    {    
       NIXIE_4BIT_SHOW(16,5,2,0); 
    }   
}    