/*
 * TESTEXTRA1_PHOTORESISTOR.cpp
 *
 * Created: 2014/5/3 1:09:09
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <string.h> 
#include <stdio.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_photoresistor.h>

int main(void)
{
	DDRA = 0XFF; 
	
	PORTA = 0X00;
	
	PHOTORESISTOR_INIT();
	
    while(1)
    {
		switch(PHOTORESISTOR_VALUE()) 
		{
			case PHOTORESISTOR_LIGHT: PORTA = 0x01;
			break;
			  
			case PHOTORESISTOR_DARK: PORTA = 0x02;
			break;
		}
		
		
		//(1 << PHOTORESISTOR_IO)//~(1 << PHOTORESISTOR_IO)//(1 << PHOTORESISTOR_IO)//&  0X01//| 0X00//PHOTORESISTOR_PIN
		
		//light = PHOTORESISTOR_VALUE();
		
        //if (light != PHOTORESISTOR_LIGHT)
        //{
		//	PORTA = 0x01;
        //}
         //else
		 //{ 
		//	 PORTA = 0x02;
		// }			
		//PHOTORESISTOR_VALUE()
		
		
    }
	}	