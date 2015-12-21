/*
 * TEST50_DS1302_LCD1602_SHOW_TIME.cpp
 *
 * Created: 2014/4/25 20:37:12
 *  Author: Narcissus
 */ 

 
#include <avr/io.h>
#include <string.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\device\lib_ds1302.h>
#include <E:\kuaipan\EDEN\avr\device\lib_lcd1602.h>

char LCD_DS1302_BUFFER1[17],LCD_DS1302_BUFFER2[17];

int main(void)
{ 
	LCD_init();
	
	delay_reduce(100);
	
	
	
	DS1302_DDR_PORT_INIT();
	
	//DDRA = 0XFF;
	
	//PORTA = 0XFF;
	
	//DS1302_INIT(0x14,0x05,0x02,0x23,0x39,0x30);
	
		delay_second(10);
		
    while(1)  
    {   
       DS1302_GET_TIME();
	   
	   //sprintf(DS1302_BUFFER_DATE,"DATE:%02d-%02d-%02d%3s",DATETIME[6],DATETIME[4],DATETIME[3],WEEK[DATETIME[5]-1]);
	   
	  DS1302_BUFFER_1602_TRANSIT();
	   
	   LCD_SHOW_STRING(0,0,DS1302_BUFFER_DATE);
	   
	   LCD_SHOW_STRING(0,1,DS1302_BUFFER_TIME);
	   
	   delay_reduce(1000);
	   
    }
} 