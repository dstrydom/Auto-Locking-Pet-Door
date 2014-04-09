/*
 * Chipcorder_SM.h
 */ 


#ifndef CHIPCORDER_SM_H_
#define CHIPCORDER_SM_H_

#include "globalVariables.h"

#define numRecordings 10 //numbers 0 - 9

enum Chipcorder_States{wait_chip, ff_off, ff, play, play_off, reset1, reset0};
int Chipcorder_SM(int state){	
	static unsigned int countC;
	
	//Transitions
	switch(state){
		case wait_chip:
			if( (speech == 0x01) && (countC == 0) ) 
				state = ff_off;
		break;
		
		case ff_off:
			if(countC < index)
				state = ff;
			else //countC >= index
				state = play;
		break;
		
		case ff:
			state = ff_off;
		break;
		
		case play:
			state = play_off;
		break;
		
		case play_off:
			if(countC == 0)
				state = wait_chip;
			else
				state = reset1;
		break;
		
		case reset1:
			if(countC < numRecordings)
				state = reset0;
			else //countC >= numRecordings
				state = wait_chip;
		break;
		
		case reset0:
			state = reset1;
		break;
		
		default:
			state = wait_chip;
		break;
	}
	
	//Actions
	switch(state){
		case wait_chip:
			countC = 0;
			//PORTD = PORTD | 0x20; //0010 0000
			PORTD = PORTD | 0x60; //0110 0000
		break;
		
		case ff_off:
			PORTD = PORTD | 0x20; //0010 0000
		break;
		
		case ff:
			PORTD = PORTD & 0xDF; //1101 1111
			++countC;
		break;
		
		case play:
			PORTD = PORTD & 0xBF; //1011 1111
		break;
		
		case play_off:
			PORTD = PORTD | 0x40; //0100 0000
		break;
		
		case reset1:
			PORTD = PORTD | 0x20; //0010 0000
		break;
		
		case reset0:
			PORTD = PORTD & 0xDF; //1101 1111
			++countC;
		break;
		
		default:
			countC = 0;
			PORTD = PORTD | 0x60; //0110 0000
		break;
	}
	return state;
}


#endif /* CHIPCORDER_SM_H_ */
