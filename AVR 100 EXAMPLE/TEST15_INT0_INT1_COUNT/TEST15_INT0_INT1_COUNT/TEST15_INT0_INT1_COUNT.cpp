/*
 * TEST15_INT0_INT1_COUNT.cpp
 *
 * Created: 2014/3/4 21:29:30
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>
#include <E:\kuaipan\EDEN\avr\system\lib_external_interrupt.h>


uchar DISPLAY_INT0_BUFFER[] = {0,0};

uchar DISPLAY_INT1_BUFFER[] = {0,0};

uchar INT0_COUNT = 0;

uchar INT1_COUNT = 0;

ISR(INT0_vect)
{
	INT0_COUNT ++;
	
	if (INT0_COUNT == 100)
	{
		INT0_COUNT = 0;
	}
	
	DISPLAY_INT0_BUFFER[1] = INT0_COUNT / 10;
	
	DISPLAY_INT0_BUFFER[0] = INT0_COUNT % 10;
	
}

ISR(INT1_vect)
{
	INT1_COUNT ++;
	
	if (INT1_COUNT == 100)
	{
		INT1_COUNT = 0;
	}
	
	DISPLAY_INT1_BUFFER[1] = INT1_COUNT / 10;
	
	DISPLAY_INT1_BUFFER[0] = INT1_COUNT % 10;
	
}


int main(void)
{
	EXTERNAL_INTERRUPT0_INIT_M16();
	
	EXTERNAL_INTERRUPT1_INIT_M16();
	
	
	NIXIE_4BIT_INIT();
	
	sei();
	
    while(1)
    {
       NIXIE_4BIT_SHOW(DISPLAY_INT1_BUFFER[1],DISPLAY_INT1_BUFFER[0],DISPLAY_INT0_BUFFER[1],DISPLAY_INT0_BUFFER[0]);
	   
	   
	   //NIXIE_4BIT_SHOW(0,0,0,0);
	   
    }
}