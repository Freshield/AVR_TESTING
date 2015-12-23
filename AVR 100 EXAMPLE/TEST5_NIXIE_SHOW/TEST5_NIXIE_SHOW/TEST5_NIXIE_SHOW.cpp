/*
 * TEST5_NIXIE_SHOW.cpp
 *
 * Created: 2014/2/21 18:00:43
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
 
int main(void)
{
	NIXIE_INIT();
	
    while(1)
    {
        NIXIE_FLOW();  
    }
}