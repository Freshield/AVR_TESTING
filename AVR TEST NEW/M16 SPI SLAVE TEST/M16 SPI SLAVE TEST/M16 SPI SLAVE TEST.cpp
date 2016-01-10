/*
 * M16_SPI_SLAVE_TEST.cpp
 *
 * Created: 2014/1/18 23:15:33
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_spi.h>
#include <E:\kuaipan\EDEN\avr\device\lib_nixie.h>

char get = 0;

ISR(SPI_STC_vect)
{
	
	get = SPDR;
	
	nixie_show(get);
	
}

int main(void)
{
	SPI_SLAVE_M16_init();
	
	nixie_init();
	
	sei();
	
	nixie_show(get);
	
    while(1)
    {
        
    }
}