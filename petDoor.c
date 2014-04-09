#define F_CPU 8000000UL

/*Atmega files*/
#include <avr/io.h>
#include <bit.h>
#include <stdio.h>
#include <lcd_8bit_task.h>
#include <keypad.h>
#include "scheduler.h"
#include <pwm32.h>
#include <avr/delay.h>
#include <usart_ATmega32.h>

/*State machine .h files*/
//#include "globalVariables.h" //Included from other includes
#include "LCD_SM.h"
#include "Key_SM.h"
#include "Time_SM.h"
#include "Electric_Lock_SM.h"
#include "Chipcorder_SM.h"
#include "USART_Follower_SM.h"

int main(void)
{	
	/************
	PORT SETTINGS
	*************
	DDRX = 0xFF; PORTX = 0x00; //Configures X for output and sets all pins to 0;
	DDRY = 0x00; PORTY = 0x11; //Configures Y for input and sets all pins to 1;*/
	
	DDRA = 0xFF; PORTA = 0x00; // LCD (A0-7)
	DDRB = 0xEB; PORTB = 0x14; //Electric lock (B7) and LCD ctrl (B5-6)
	DDRC = 0xF0; PORTC = 0x0F; //Keypad (C0-7)
	DDRD = 0xFF; PORTD = 0x60; //Chipcorder (D6 = play, D5 = ff), Buzzer (D7), PWM (D7)
	
	tasksNum = 7; // declare number of tasks
	task tsks[7]; // initialize the task array
	tasks = tsks; // set the task array

	unsigned char i=0; // task counter
	/*******
	TASKS
	********/
	tasks[i].state = -1;
	tasks[i].period = 1;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &LCDI_SMTick;
	++i;
	tasks[i].state = start_wait;
	tasks[i].period = 1;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &LCD_SM;
	++i;
	tasks[i].state = key_wait;
	tasks[i].period = 200;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &Key_SM;
	++i;
	tasks[i].state = time_wait;
	tasks[i].period = 1000;					//clock, so needs to tick every second
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &Time_SM;
	++i;
	tasks[i].state = -1; //to trigger values in default
	tasks[i].period = 300;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &Chipcorder_SM;
	++i;
	tasks[i].state = -1; //to trigger values in default
	tasks[i].period = 10;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &Electric_Lock_SM;
	++i;
	tasks[i].state = wait_UR;
	tasks[i].period = 1;
	tasks[i].elapsedTime = tasks[i].period;
	tasks[i].TickFct = &USART_Follower_SM;
		
	/*********
	Timer
	*********/
	TimerSet(1); //GCD of all the task periods
	TimerOn();
	
	init_PWM(); //Initiates PWM (pulse-width modulation used as buzzer sound for incorrect input)
	initUSART(); //Initializes USART
	while(1)
	{
		if(prompt1 == 0x01){
			set_PWM(MIDDLE_E);
			_delay_ms(200);
			set_PWM(MIDDLE_A);
			_delay_ms(200);
			set_PWM(0);
		}
		
		if(prompt2 == 0x01){
			set_PWM(MIDDLE_E);
			_delay_ms(200);
			set_PWM(MIDDLE_B);
			_delay_ms(200);
			set_PWM(0);
		}
		
		if(prompt3 == 0x01){
			set_PWM(MIDDLE_E);
			_delay_ms(200);
			set_PWM(MIDDLE_G);
			_delay_ms(200);
			set_PWM(0);
		}
		
	}
		
}//end main
