/*
 * Outside_Sonar_SM.h
 */ 

#define  F_CPU 8000000UL //8MHz

#ifndef OUTSIDE_SONAR_SM_H_
#define OUTSIDE_SONAR_SM_H_

#include "globalVariables.h"
#include "util/delay.h"

enum Outside_Sonar_States{outside_wait, check_outside};
int Outside_Sonar_SM(int state){
	static unsigned int outsideTimer;
	static unsigned int cameOutside;
	static unsigned int duration, inches;
	
	//Transitions
	switch(state){
		case outside_wait:
			//if((petInside == 1) && (doorMotion == 1))
			if(petInside == 1)
				state = check_outside;
		break;
		
		case check_outside:
			if( (outsideTimer >= 50) | (cameOutside == 1) )
				state = outside_wait;
		break;
		
		default:
			state = outside_wait;
		break;
	}//end transitions
	
	// Actions
	switch (state) {
		case outside_wait:
			outsideTimer = 0;
			cameOutside = 0;
		break;
		
		case check_outside:
			++outsideTimer;
			
			duration = 0;
			inches = 0;
			
			PORTB = (PORTB & 0xFB); /*sets B2 (sonar1 echo) to 0*/
			
			PORTB = (PORTB & 0xFD); /*Set sonar1 trigger pin B1 low*/
			_delay_us(2);
			PORTB = (PORTB | 0x02);	/*Set sonar1 trigger pin B1 high for 10us*/
			_delay_us(10);
			PORTB = (PORTB & 0xFD); /*Reset trigger pin low*/
			
			while((PINB & 0x04) == 0);
			while((PINB & 0x04) == 0x04){
				++duration;
				_delay_us(1);
			}
			/*calculate distance from sensor in inches*/
			inches = microsecondsToInches(duration);
			
			if(inches < 12){
				petInside = 0;
				cameOutside = 1;
			}
			else{
				
			}				
		break;
		
		default:
			outsideTimer = 0;
			cameOutside = 0;
		break;
	}//end actions
	
	return state;
}//end Outside_Sonar_SM



#endif /* OUTSIDE_SONAR_SM_H_ */
