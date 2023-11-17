#include <avr/io.h>
#include "timer.h"
#include "LCD.h"
#include "keypad_driver.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>

volatile int flag1=0,flag2=0;

int main(void)
{
	int x;
	keypad_vInit();
	LCD_vInit();
	LCD_vSend_string("3+?=8");
	timer_CTC_init_interrupt();
	
   
	    do{		
			   if(flag1>=1000)
			   {
				   flag2=1;
			   }
		       x=keypad_u8check_press();
			   _delay_ms(200);
			   
		   }while(x==NOTPRESSED && flag2==0 );			
			
			if(x==NOTPRESSED)
			{
				LCD_clearscreen();
				LCD_movecursor(2,4);
				LCD_vSend_string("Time over");
			}				
			else if (x=='5')
			{
				LCD_clearscreen();
				LCD_movecursor(2,4);
				LCD_vSend_string("Well done");
			}
			else
			{
				LCD_clearscreen();
				LCD_movecursor(2,3);
				LCD_vSend_string("Wrong answer");
			}			 
}


ISR(TIMER0_COMP_vect)
{
	flag1++;
}



