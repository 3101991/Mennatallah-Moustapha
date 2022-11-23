/* This is a documentation for my First 
project ,The following represents the draft 
of main c program ,I will begin with generic scheme 
at the begining then I shall work thought it step by step
The task is to make a blinking led without using predefined 
functions and implicitly use PWM and overflow
After search I discovered that I should use systick timer to generate 
interrupt*/
#include "MyFirstProject.h"
#include<stdio.h>

int x =3599999999 ;
int y =3599999999;

#define x onTime,
#define y offtime,

void GPIOdriver()
		{
			
  SYSCTL->RCGCGPIO |= 0x01; // turn on bus clock for GPIOA by adding the offset address to the base address from the data sheet
  GPIOA->DIR       |= 0x08; //set GREEN pin as a digital output pin
  GPIOA->DEN       |= 0x08;  // Enable PA3 pin as a digital pin
	}
	void TimerDriver()// in this function an interrupt occurs once the timer reaches a certain value
	{
	SysTick->LOAD = 0; // I initialized the timer with zero but the value changes during the program
	SysTick->CTRL = 7 ; // enable counter, interrupt and select system bus clock 
	SysTick->VAL  = 0; //initialize current value register 
	}


int main()
{
	GPIOdriver();
	TimerDriver();
   
	while (1)
	{
		//do nothing here
	}
}

// this routine will execute after every one second
// The following function works as a pwm but on a longer rate
void delayON(x)
	{
		SysTick->LOAD = x;
}

void delayOFF(y)
{
SysTick->LOAD = y;
}
	
void SysTick_Handler(void)
	
{
	GPIOA ->DATA  =0b00000000;
	delayON(x);
   GPIOA ->DATA  ^= 8;  //toggle PA3 pin
  delayOFF(y);
}


