/*
 * M16_LCD1602_SHOW.cpp
 *
 * Created: 2014/1/4 0:50:20
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_lcd1602.h>


int main(void)
{    
 
	   
	LCD_init(); 
	delay_reduce(100); 
	char fuck[] = "I    LOVE   YOU  VIVI";
        
    while(1)   
    {  
		LCD_SHOW_STRING(0,1,fuck);  
    }   
}