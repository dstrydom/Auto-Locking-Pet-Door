/*
 * Inside_Sonar_SM.h
 */ 

#define  F_CPU 8000000UL //8MHz

#ifndef INSIDE_SONAR_SM_H_
#define INSIDE_SONAR_SM_H_

#include "globalVariables.h"
#include "util/delay.h"

enum Inside_Sonar_States{inside_wait, check_inside};
int Inside_Sonar_SM(int state){
	static unsigned int insideTimer;
	static unsigned int cameInside;
	static unsigned int duration, inches;
	
	//Transitions
	switch(state){
		case inside_wait:
			//if((petInside == 0) && (doorMotion == 1))
			if(petInside == 0)
				state = check_inside;
		break;
		
		case check_inside:
			if( (insideTimer >= 50) | (cameInside == 1) )
				state = inside_wait;
		break;
		
		default:
			state = inside_wait;
		break;
	}//end transitions
	
	// Actions
	switch (state) {
		case inside_wait:
			insideTimer = 0;
			cameInside = 0;
		break;
		
		case check_inside:
			++insideTimer;
			
			duration = 0;
			inches = 0;
			
			PORTB = (PORTB & 0xEF); /*sets B4 (sonar1 echo) to 0*/
			
			PORTB = (PORTB & 0xF7); /*Set sonar1 trigger pin B3 low*/
			_delay_us(2);
			PORTB = (PORTB | 0x08);	/*Set sonar1 trigger pin B3 high for 10us*/
			_delay_us(10);
			PORTB = (PORTB & 0xF7); /*Reset trigger pin low*/
			
			while((PINB & 0x10) == 0);
			while((PINB & 0x10) == 0x10){
				++duration;
				_delay_us(1);
			}
			/*calculate distance from sensor in inches*/
			inches = microsecondsToInches(duration);
			
			if(inches < 12){
				//PORTA = (PORTA | 0x01);
				//PORTA = (PORTA & 0xFD);
				petInside = 1;
				cameInside = 1;
			}
			else{
				//PORTA = (PORTA | 0x02);
				//PORTA = (PORTA & 0xFE);
			}				
		break;
		
		default:
			insideTimer = 0;
			cameInside = 0;
		break;
	}//end actions
	
	return state;
}//end Inside_Sonar_SM


#endif /* INSIDE_SONAR_SM_H_ */
