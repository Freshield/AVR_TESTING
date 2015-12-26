/*
 * TEST11_RELAY_BUMB.cpp
 *
 * Created: 2014/2/22 20:14:10
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_keyboard.h>

int main(void)
{
	KEYBOARD_INIT_M16();
	
	DDRA = 0xff;
	
	PORTA = 0xff;
	
	delay_second(5);
	
	//PORTA = 0x00;
	
	uchar FUN = 0;
	
	
    while(1)
    {
		
		/*
		
        if (KEY_DOWN() == 1)
        {
						
			while(KEY_DOWN());
			
			PORTA = ~PORTA;
			
			delay_reduce(20);
				
				
				
				
			}
			*/
			
			
        
    }
}