/*
 * keypad_driver.c
 *
 *  Author: BAYOUMII
 */ 
 #include "keypad_driver.h"
 void keypad_vInit()
 {
	 DIO_vsetPINDir('A',0,1);
	 DIO_vsetPINDir('A',1,1);
	 DIO_vsetPINDir('A',2,1);
	 DIO_vsetPINDir('A',3,1);
	 DIO_vsetPINDir('A',4,0);
	 DIO_vsetPINDir('A',5,0);
	 DIO_vsetPINDir('A',6,0);
	 DIO_vsetPINDir('A',7,0);
	 DIO_vconnectpullup('A',4,1);
	 DIO_vconnectpullup('A',5,1);
	 DIO_vconnectpullup('A',6,1);
	 DIO_vconnectpullup('A',7,1);
	  
 }
 char keypad_u8check_press()
 {
	 char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
	 char row,coloumn,x;
	 char returnval=NOTPRESSED;
	 for(row=0;row<4;row++)
	 {
	 DIO_write('A',0,1);
	 DIO_write('A',1,1);
	 DIO_write('A',2,1);
	 DIO_write('A',3,1);
	 DIO_write('A',row,0);
	
		for(coloumn=0;coloumn<4;coloumn++)
		{
		 x=DIO_u8read('A',(coloumn+4));
		 if(x==0)
			 {
			 returnval=arr[row][coloumn];
			 break;
			 }  
		}	
	 if(x==0)
		{
		 break;
		}
	 }	 
	 return returnval ;	 
 }