/*
 * M16_ADC_TEST.cpp
 *
 * Created: 2014/1/15 23:49:41
 *  Author: Narcissus
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <E:\kuaipan\EDEN\avr\system\lib_delay.h>
#include <E:\kuaipan\EDEN\avr\function\lib_adc.h>
#include <E:\kuaipan\EDEN\avr\device\lib_lcd1602.h>

char LINE_ADC0[] = {48,49,50,32,32,32,32,32,32,32,32,32,32,32,32,32};
char LINE_ADC1[] = {51,52,53,32,32,32,32,32,32,32,32,32,32,32,32,32};
int result;
char hun,ten,one;
char select;

ISR(ADC_vect)

{
	if (select == 0)
	{
		delay_reduce(100);
		
		result= M16_ADC_CATCH(0);
		
		delay_reduce(500);
		
		hun = result / 100;
		
		ten = result / 10 % 10;
		
		one = result % 10;
		
		LINE_ADC0[0] = hun + 48;
		
		LINE_ADC0[1] = ten + 48;
		
		LINE_ADC0[2] = one + 48;
		
		LCD_SHOW_STRING(0,0,LINE_ADC0);
		
		delay_reduce(100);
		
		select = 1;
	}
	 
	 else
	 {
		 result= M16_ADC_CATCH(1);
		 
		 delay_reduce(500);
		 
		 hun = result / 100;
		 
		 ten = result / 10 % 10;
		 
		 one = result % 10;
		 
		 LINE_ADC1[0] = hun + 48;
		 
		 LINE_ADC1[1] = ten + 48;
		 
		 LINE_ADC1[2] = one + 48;
		 
		 LCD_SHOW_STRING(0,1,LINE_ADC1);
		 
		 delay_reduce(100);
		 
		 select = 0;
	 }
	 
}
 
int main(void)  
{
	M16_ADC_INIT();
	
	LCD_init();
	
	select = 0; 
	
	sei();
	
	//LCD_SHOW_STRING(0,0,"TEST TTTTTT EEEEE SSSSS TTTT");
	
	//LCD_SHOW_STRING(0,1,"TEST TTTTTT EEEEE SSSSS TTTT");
	//delay_second(80);
	
	//LCD_SHOW_STRING(0,0,LINE_ADC0);
	 
	//LCD_SHOW_STRING(0,1,LINE_ADC1);
    while(1)
    {   
		
		
    }
}