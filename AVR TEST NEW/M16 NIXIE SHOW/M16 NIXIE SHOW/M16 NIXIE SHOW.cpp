/*
 * M16_NIXIE_SHOW.cpp
 *
 * Created: 2014/1/3 22:27:21
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>

int main(void)
{
    while(1) 
    {
        nixie_flow(); 
    }
}