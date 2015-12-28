/*
 * TEST19_TIMER1_TRAFFIC_LIGHT.cpp
 *
 * Created: 2014/3/14 21:28:10
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_pwm.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>


//--------------------NORTH---------------------------------
#define RED_NORTH_ON PORTA |= 1 << 0;
#define RED_NORTH_OFF PORTA &= ~(1 << 0);

#define YELLOW_NORTH_ON PORTA |= 1 << 1;
#define YELLOW_NORTH_OFF PORTA &= ~(1 << 1);

#define GREEN_NORTH_ON PORTA |= 1 << 2;
#define GREEN_NORTH_OFF PORTA &= ~(1 << 2);

#define YELLOW_NORTH_BLINK PORTA ^= 1 << 1;
//--------------------EAST---------------------------------
#define RED_EAST_ON PORTA |= 1 << 3;
#define RED_EAST_OFF PORTA &= ~(1 << 3);

#define YELLOW_EAST_ON PORTA |= 1 << 4;
#define YELLOW_EAST_OFF PORTA &= ~(1 << 4);

#define GREEN_EAST_ON PORTA |= 1 << 5;
#define GREEN_EAST_OFF PORTA &= ~(1 << 5);

#define YELLOW_EAST_BLINK PORTA ^= 1 << 4;
//-------------------SOUTH-----------------------------------
#define RED_SOUTH_ON PORTA |= 1 << 0;
#define RED_SOUTH_OFF PORTA &= ~(1 << 0);

#define YELLOW_SOUTH_ON PORTA |= 1 << 1;
#define YELLOW_SOUTH_OFF PORTA &= ~(1 << 1);

#define GREEN_SOUTH_ON PORTA |= 1 << 2;
#define GREEN_SOUTH_OFF PORTA &= ~(1 << 2);
//-------------------WEST-----------------------------------
#define RED_WEST_ON PORTA |= 1 << 3;
#define RED_WEST_OFF PORTA &= ~(1 << 3);

#define YELLOW_WEST_ON PORTA |= 1 << 4;
#define YELLOW_WEST_OFF PORTA &= ~(1 << 4);

#define GREEN_WEST_ON PORTA |= 1 << 5;
#define GREEN_WEST_OFF PORTA &= ~(1 << 5);
//-----------------------------------------------------------

uchar MODEL,FLASH_COUNT = 0;

ISR(TIMER1_OVF_vect)
{
	TIMER1_NORMAL_PWM_set(0.5);
	
	
	 switch (MODEL)
	 {
		 //-----------------------------------------------------------
		 case 0:
		 
		 RED_NORTH_ON;YELLOW_NORTH_OFF;GREEN_NORTH_OFF;
		 
		 RED_WEST_OFF;YELLOW_WEST_OFF;GREEN_WEST_ON;
		 
		 if (++ FLASH_COUNT != 10)break;
		 
		 MODEL = 1;
		 
		 FLASH_COUNT = 0;
		 
		 break;
		 //-----------------------------------------------------------
		 case 1:
		 
		 YELLOW_EAST_BLINK;
		 
		 if (++ FLASH_COUNT != 10)break;
		 
		 MODEL = 2;
		 
		 FLASH_COUNT = 0;
		 
		 break;
		 //-----------------------------------------------------------
		 case 2:
		 
		 RED_NORTH_OFF;YELLOW_NORTH_OFF;GREEN_NORTH_ON;
		 
		 RED_WEST_ON;YELLOW_WEST_OFF;GREEN_WEST_OFF;
		 
		 if (++ FLASH_COUNT != 10)break;
		 
		 MODEL = 3;
		 
		 FLASH_COUNT = 0;
		 
		 break;
		 //-----------------------------------------------------------
		 case 3:
		 
		 YELLOW_NORTH_BLINK;
		 
		 if (++ FLASH_COUNT != 10)break;
		 
		 MODEL = 0;
		 
		 FLASH_COUNT = 0;
		 
		 break;
		 //-----------------------------------------------------------
		 
	 }
 }
	
	
	
	


int main(void)
{
	LED_INIT();
	
	TIMER1_NORMAL_PWM_INIT();
	
	TIMER1_NORMAL_PWM_set(0.01);
	
	sei();
	
    while(1)
    {
		
       
    }
}