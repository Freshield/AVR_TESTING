/*
 * M16_SPI_MASTER_TEST.cpp
 *
 * Created: 2014/1/18 23:05:25
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_spi.h>

ISR(SPI_STC_vect)
{
	
}


int main(void)
{
	
	SPI_MASTER_M16_init();
	
	sei();
	
	
    while(1)
    {
        for (char i = 0;i < 10;i ++)
        {
			SPI_MasterTransmit(i);
			
			delay_second(30);
			
        }
    }
}