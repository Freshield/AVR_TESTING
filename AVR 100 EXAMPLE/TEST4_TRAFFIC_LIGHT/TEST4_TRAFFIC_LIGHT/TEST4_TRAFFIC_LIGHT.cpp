/*
 * TEST4_TRAFFIC_LIGHT.cpp
 *
 * Created: 2014/3/14 17:43:43
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_led.h>
//--------------------NORTH---------------------------------
#define RED_NORTH_ON PORTA |= 1 << 0;
#define RED_NORTH_OFF PORTA &= ~(1 << 0);

#define YELLOW_NORTH_ON PORTA |= 1 << 1;
#define YELLOW_NORTH_OFF PORTA &= ~(1 << 1);

#define GREEN_NORTH_ON PORTA |= 1 << 2;
#define GREEN_NORTH_OFF PORTA &= ~(1 << 2);
//--------------------EAST---------------------------------
#define RED_EAST_ON PORTA |= 1 << 3;
#define RED_EAST_OFF PORTA &= ~(1 << 3);

#define YELLOW_EAST_ON PORTA |= 1 << 4;
#define YELLOW_EAST_OFF PORTA &= ~(1 << 4);

#define GREEN_EAST_ON PORTA |= 1 << 5;
#define GREEN_EAST_OFF PORTA &= ~(1 << 5);
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


int main(void)
{
	LED_INIT();
	
	
    while(1)
    {
       switch (MODEL)
       {
		   //-----------------------------------------------------------
       case 0:
	   
	   RED_NORTH_ON;YELLOW_NORTH_OFF;GREEN_NORTH_OFF;
	   
	   RED_WEST_OFF;YELLOW_WEST_OFF;GREEN_WEST_ON;
	   
	   delay_second(100);
	   
	   MODEL = 1;
	   
       	break;
		//-----------------------------------------------------------   
		case 1:
		
		for (uchar i = 0;i < 10;i ++)
		{
			RED_NORTH_ON;YELLOW_NORTH_OFF;GREEN_NORTH_OFF;
			
			RED_WEST_OFF;YELLOW_WEST_ON;GREEN_WEST_ON;
			
			delay_second(5);
			
			RED_NORTH_ON;YELLOW_NORTH_OFF;GREEN_NORTH_OFF;
			
			RED_WEST_OFF;YELLOW_WEST_OFF;GREEN_WEST_ON;
			
			delay_second(5);
			
			
		}
		
		
		
		FLASH_COUNT = 0;
		
		MODEL = 2;
		
		break;
		//-----------------------------------------------------------
		case 2:
		
		RED_NORTH_OFF;YELLOW_NORTH_OFF;GREEN_NORTH_ON;
		
		RED_WEST_ON;YELLOW_WEST_OFF;GREEN_WEST_OFF;
		
		delay_second(100);
		
		MODEL = 3;
		
		break;
		//-----------------------------------------------------------
		case 3:
		
		for (uchar i = 0;i < 10;i ++)
		{
			RED_NORTH_OFF;YELLOW_NORTH_ON;GREEN_NORTH_ON;
			
			RED_WEST_ON;YELLOW_WEST_OFF;GREEN_WEST_OFF;
			
			delay_second(5);
			
			RED_NORTH_OFF;YELLOW_NORTH_OFF;GREEN_NORTH_ON;
			
			RED_WEST_ON;YELLOW_WEST_OFF;GREEN_WEST_OFF;
			
			delay_second(5);
			
			
		}
		
		
		
		FLASH_COUNT = 0;
		
		MODEL = 0;
		
		break;
		//-----------------------------------------------------------
		
       }
    }
}