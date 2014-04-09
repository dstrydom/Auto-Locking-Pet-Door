/*Atmega files*/
#include <avr/io.h>
#include <bit.h>
#include <stdio.h>
#include "scheduler.h"
#include <usart_ATmega32.h>

/*.h files for SMs*/
//#include "globalVariables.h" //Included from other includes
#include "Inside_Sonar_SM.h"
#include "Outside_Sonar_SM.h"
#include "USART_Leader_SM.h"

int main(void)
{
	/************
	PORT SETTINGS
	*************
	DDRX = 0xFF; PORTX = 0x00; //Configures X for output and sets all pins to 0;
	DDRY = 0x00; PORTY = 0x11; //Configures Y for input and sets all pins to 1;*/
	
	DDRA = 0x00; PORTA = 0x00; //ADC
	DDRB = 0xEB; PORTB = 0x14; //Sonar sensors
	DDRD = 0xFF; PORTD = 0xC0; //USART
	
	tasksNum = 3; // declare number of tasks
	task tsks[3]; // initialize the task array
	tasks = tsks; // set the task array

	
	unsigned char i=0; // task counter
	/*******
	TASKS
	********/
	tasks[i].state = -1; //to trigger values in default
	tasks[i].period = 300;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &Inside_Sonar_SM;
	++i;
	tasks[i].state = -1; //to trigger values in default
	tasks[i].period = 100;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &Outside_Sonar_SM;
	++i;
	tasks[i].state = wait_UL;
	tasks[i].period = 100;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &USART_Leader_SM;

	/*********
	Timer
	*********/
	TimerSet(1); //GCD of all the task periods
	TimerOn();
	
		
	//ADC_init(); //initializes analog to digital conversion setup
	initUSART(); //Initializes usart
	while(1)
	{
		//Debug sonar
		if(petInside == 1)
			PORTB = (PORTB | 0x01);
		else
			PORTB = (PORTB & 0xFE);
	}
}
