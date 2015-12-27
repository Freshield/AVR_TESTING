/*
 * gift.cpp
 *
 * Created: 2013/12/20 20:12:49
 *  Author: Narcissus
 */ 


#include <avr/io.h>

void DELAY(int i)
{
	int j;
	for(;i!=0;i--)
	{
		for(j=65535;j!=0;j--);
		{
			asm volatile ("nop");
		}

	}
	
}

int main(void)
{
	DDRB = 0XFF;
    while(1)
    {
		PORTB = 0X00;
		
        for(int i = 0;i < 128;i ++)
		{
			PORTB = PORTB ++;
			
			DELAY(5);
			
		}
		
		PORTB = 0XFF;
		
		DELAY(5);
		
		PORTB = 0X00;
		
		DELAY(5);
				
		PORTB = 0XFF;
		
		DELAY(5);
		
		PORTB = 0X00;
		
		DELAY(5);
		
		PORTB = 0XFF;
		
		DELAY(5);
		
		PORTB = 0X00;
		
		DELAY(5);
		
		PORTB = 0XFF;
		
		DELAY(5);
		
		PORTB = 0X00;
		
		DELAY(5);
		
		PORTB = 0XFF;
		
		DELAY(5);
		
		PORTB = 0X00;
		
		DELAY(5);			
		
		PORTB = 0XFF;
		
		DELAY(5);
		
		PORTB = 0X00;
		
		DELAY(5);
		
		PORTB = 0XFF;
		
		DELAY(5);
		
		PORTB = 0X00;
		
		DELAY(5);
		
		PORTB = 0XFF;
		
		DELAY(5);
		
		PORTB = 0X00;
		
		DELAY(5);
		
		PORTB = 0XFF;
		
		DELAY(5);
		
		PORTB = 0X00;
		
		DELAY(5);
		
		PORTB = 0XFF;
		
		DELAY(5);
		
		PORTB = 0X00;
		
		DELAY(5);
    }
}