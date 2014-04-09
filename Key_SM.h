/*
 * Key_SM.h
 */ 

#ifndef KEY_SM_H_
#define KEY_SM_H_

#define F_CPU 8000000UL
#include "globalVariables.h"

enum Key_States{key_wait, getHr1CT, waitHr1CT, getHr2CT, waitHr2CT, 
				getMin1CT, waitMin1CT, getMin2CT, waitMin2CT, getSec1CT, 
				waitSec1CT, getSec2CT, waitSec2CT, getHr1LT, waitHr1LT, 
				getHr2LT, waitHr2LT, getMin1LT, waitMin1LT, getMin2LT, 
				waitMin2LT, getSec1LT, waitSec1LT, getSec2LT, waitSec2LT,
				getHr1UT, waitHr1UT, getHr2UT, waitHr2UT, getMin1UT, 
				waitMin1UT, getMin2UT, waitMin2UT, getSec1UT, waitSec1UT, 
				getSec2UT, waitSec2UT, petCheck};
				
int Key_SM(int state){	
	static unsigned char x; //holds entered char
	static unsigned char previousX; //holds previous char
	
	/********************************
	TRANSITIONS
	********************************/
	switch(state){
		
		case key_wait: //Hr1CT input
			//if button is pressed (recall: '\0' means no button pressed)
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '2') )
					state = key_wait;
				else
					state = getHr1CT; 
			}				
		break;
		
		case getHr1CT: //Hr1CT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitHr1CT;
		break;
		
		case waitHr1CT: //Hr2CT input
			if( (x = GetKeypadKey()) != '\0' ){
				if(previousX == '2'){
					if( (x < '0') | (x > '4') )
						state = waitHr1CT;
					else
						state = getHr2CT;
				}
				else if(previousX == '1'){
					if( (x < '0') | (x > '9') )
						state = waitHr1CT;
					else
						state = getHr2CT;
				}
				else if(previousX == '0'){
					if( (x < '0') | (x > '9') )
						state = waitHr1CT;
					else
						state = getHr2CT;
				}
			}
		break;
		
		case getHr2CT: //Hr2CT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitHr2CT;
		break;
		
		case waitHr2CT: //Min1CT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '5') )
					state = waitHr2CT;
				else
					state = getMin1CT;
			}
		break;
		
		case getMin1CT: //Min1CT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitMin1CT;
		break;
		
		case waitMin1CT: //Min2CT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '9') )
					state = waitMin1CT;
				else
					state = getMin2CT;
			}
		break;
		
		case getMin2CT: //Min2CT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitMin2CT;
		break;
		
		case waitMin2CT: //Sec1CT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '5') )
					state = waitMin2CT;
				else
					state = getSec1CT;
			}
		break;
		
		case getSec1CT: //Sec1CT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitSec1CT;
		break;
		
		case waitSec1CT: //Sec2CT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '9') )
					state = waitSec1CT;
				else
					state = getSec2CT;
			}
		break;
		
		case getSec2CT: //Sec2CT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitSec2CT;
		break;
		
		case waitSec2CT: //Hr1LT input
		if( (x = GetKeypadKey()) != '\0' ){
			if( (x < '0') | (x > '2') )
				state = waitSec2CT;
			else
				state = getHr1LT;
		}				
		break;
		
		case getHr1LT: //Hr1LT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitHr1LT;
		break;
		
		case waitHr1LT: //Hr2LT input
			if( (x = GetKeypadKey()) != '\0' ){
				if(previousX == '2'){
					if( (x < '0') | (x > '4') )
						state = waitHr1LT;
					else
						state = getHr2LT;
				}
				else if(previousX == '1'){
					if( (x < '0') | (x > '9') )
						state = waitHr1LT;
					else
						state = getHr2LT;
				}
				else if(previousX == '0'){
					if( (x < '0') | (x > '9') )
						state = waitHr1LT;
					else
						state = getHr2LT;
				}
			}
		break;
		
		case getHr2LT: //Hr2LT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitHr2LT;
		break;
		
		case waitHr2LT: //Min1LT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '5') )
					state = waitHr2LT;
				else
					state = getMin1LT;
			}				
		break;
		
		case getMin1LT: //Min1LT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitMin1LT;
		break;
		
		case waitMin1LT: //Min2LT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '9') )
					state = waitMin1LT;
				else
					state = getMin2LT;
			}
		break;
		
		case getMin2LT: //Min2LT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitMin2LT;
		break;
		
		case waitMin2LT: //Sec1LT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '5') )
					state = waitMin2LT;
				else
					state = getSec1LT;
			}
		break;
		
		case getSec1LT: //Sec1LT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitSec1LT;
		break;
		
		case waitSec1LT: //Sec2LT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '9') )
					state = waitSec1LT;
				else
					state = getSec2LT;
			}
		break;
		
		case getSec2LT: //Sec2Lt computation
			if( (GetKeypadKey()) == '\0' )
				state = waitSec2LT;
		break;
		
		case waitSec2LT: //Hr1UT input
		if( (x = GetKeypadKey()) != '\0' ){
			if( (x < '0') | (x > '2') )
				state = waitSec2LT;
			else
				state = getHr1UT;
		}
		break;
		
		case getHr1UT: //Hr1UT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitHr1UT;
		break;
		
		case waitHr1UT: //Hr2UT input
			if( (x = GetKeypadKey()) != '\0' ){
				if(previousX == '2'){
					if( (x < '0') | (x > '4') )
						state = waitHr1UT;
					else
						state = getHr2UT;
				}
				else if(previousX == '1'){
					if( (x < '0') | (x > '9') )
						state = waitHr1UT;
					else
						state = getHr2UT;
				}
				else if(previousX == '0'){
					if( (x < '0') | (x > '9') )
						state = waitHr1UT;
					else
						state = getHr2UT;
				}
			}
		break;
		
		case getHr2UT: //Hr2UT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitHr2UT;
		break;
		
		case waitHr2UT: //Min1UT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '5') )
					state = waitHr2UT;
				else
					state = getMin1UT;
			}
		break;
		
		case getMin1UT: //Min1UT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitMin1UT;
		break;
		
		case waitMin1UT: //Min2UT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '9') )
					state = waitMin1UT;
				else
					state = getMin2UT;
			}
		break;
		
		case getMin2UT: //Min2UT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitMin2UT;
		break;
		
		case waitMin2UT: //Sec1UT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '5') )
					state = waitMin2UT;
				else
					state = getSec1UT;
			}
		break;
		
		case getSec1UT: //Sec1UT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitSec1UT;
		break;
		
		case waitSec1UT: //Sec2UT input
			if( (x = GetKeypadKey()) != '\0' ){
				if( (x < '0') | (x > '9') )
					state = waitSec1UT;
				else
					state = getSec2UT;
			}
		break;
		
		case getSec2UT: //Sec2UT computation
			if( (GetKeypadKey()) == '\0' )
				state = waitSec2UT;
		break;
		
		//****************************************************
		case waitSec2UT:
			if( (x = GetKeypadKey()) != '\0' ){
				if(x == 'D')
					state = petCheck;
			}
		break;
		
		case petCheck:
			state = waitSec2UT;
		break;
		
		default:
			state = key_wait;
		break;
	}//end Transitions

	
	
	/*******************************
	ACTIONS
	*******************************/
	switch(state){
		case key_wait: //Hr1CT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '2')) ){ //24-hr clck so largest digit can be 2
				//turn on buzzer
				set_PWM(MIDDLE_C);
			}				
			else{
				//turn off buzzer			
				set_PWM(0);
			}
			
		break;
		
		case getHr1CT: //Hr1CT computation
			set_PWM(0);
			speech = 0x01; //flag to turn on chipcorder SM
			index = (x - 48);
			previousX = x;
			
			current_time_display[0] = x;
			current_hour1 = x;
			current_hour1 -= 48;
			current_hour1 *= 10;
			
			gotHr1CT = 1;
		break;
		
		case waitHr1CT: //Hr2CT input
			speech = 0x00;
			
			if(previousX == '2'){
				if( (x != '\0') && ((x < '0') | (x > '4')) )
					set_PWM(MIDDLE_C);
				else{
					set_PWM(0);
				}					
			}
			else if(previousX == '1'){
				if( (x != '\0') && ((x < '0') | (x > '9')) )
					set_PWM(MIDDLE_C);
				else{
					set_PWM(0);
				}					
			}
			else if(previousX == '0'){
				if( (x != '\0') && ((x < '0') | (x > '9')) )
					set_PWM(MIDDLE_C);					
				else{
					set_PWM(0);
				}					
			}
		break;
		
		case getHr2CT: //Hr2CT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			current_time_display[1] = x;
			current_hour2 = x;
			current_hour2 -= 48;
			
			gotHr2CT = 1;
		break;
		
		case waitHr2CT: //Min1CT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '5')) ){ //Largest 10's minute can be 5
				set_PWM(MIDDLE_C);
			}				
			else{
				set_PWM(0);
			}				
		break;
		
		case getMin1CT: //Min1CT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			current_time_display[2] = x;
			current_min1 = x;
			current_min1 -= 48;
			current_min1 *= 10;
			
			gotMin1CT = 1;
		break;
		
		case waitMin1CT: //Min2CT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '9')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getMin2CT: //Min2CT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			current_time_display[3] = x;
			current_min2 = x;
			current_min2 -= 48;
			
			gotMin2CT = 1;
		break;
		
		case waitMin2CT: //Sec1Ct input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '5')) ){ //Largest 10's sec can be 5
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);				
			}
		break;
			
		case getSec1CT: //Sec1CT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			current_time_display[4] = x;
			current_sec1 = (x-48)*10;
			
			gotSec1CT = 1;
		break;
		
		case waitSec1CT: // Sec2CT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '9')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getSec2CT: //Sec2CT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			current_time_display[5] = x;
			current_sec2 = x-48;
			
			gotSec2CT = 1;
		break;
		
		case waitSec2CT: //Hr1LT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '2')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getHr1LT: //Hr1LT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			lock_time_display[0] = x;
			lock_hour1 = x;
			lock_hour1 -= 48;
			lock_hour1 *= 10;
			
			gotHr1LT = 1;
		break;
		
		case waitHr1LT: //Hr2LT input
			speech = 0x00;
			
			if(previousX == '2'){
				if( (x != '\0') && ((x < '0') | (x > '4')) )
					set_PWM(MIDDLE_C);
				else{
					set_PWM(0);
				}
			}
			else if(previousX == '1'){
				if( (x != '\0') && ((x < '0') | (x > '9')) )
					set_PWM(MIDDLE_C);
				else{
					set_PWM(0);
				}
			}
			else if(previousX == '0'){
				if( (x != '\0') && ((x < '0') | (x > '9')) )
					set_PWM(MIDDLE_C);
				else{
					set_PWM(0);
				}
			}
		break;
		
		case getHr2LT: //Hr2LT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			lock_time_display[1] = x;
			lock_hour2 = x;
			lock_hour2 -= 48;	
			
			gotHr2LT = 1;
		break;
		
		case waitHr2LT: //Min1LT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '5')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getMin1LT: //Min1LT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			lock_time_display[2] = x;
			lock_min1 = x;
			lock_min1 -= 48;
			lock_min1 *= 10;
			
			gotMin1LT = 1;
		break;
		
		case waitMin1LT: //Min2LT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '9')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getMin2LT: //Min2LT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			lock_time_display[3] = x;
			lock_min2 = x;
			lock_min2 -= 48;
			
			gotMin2LT = 1;
		break;
		
		case waitMin2LT: //Sec1LT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '5')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
			
		case getSec1LT: //Sec1LT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			lock_time_display[4] = x;
			lock_sec1 = (x-48)*10;
			
			gotSec1LT = 1;
		break;
		
		case waitSec1LT: //Sec2LT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '9')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getSec2LT: //Sec2LT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			lock_time_display[5] = x;
			lock_sec2 = x-48;
			
			gotSec2LT = 1;
		break;
		
		case waitSec2LT: //Hr1UT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '2')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getHr1UT: //Hr1UT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			unlock_time_display[0] = x;
			unlock_hour1 = x;
			unlock_hour1 -= 48;
			unlock_hour1 *= 10;
			
			gotHr1UT = 1;
		break;
		
		case waitHr1UT: //Hr2UT input
			speech = 0x00;
			
			if(previousX == '2'){
				if( (x != '\0') && ((x < '0') | (x > '4')) )
					set_PWM(MIDDLE_C);
				else{
					set_PWM(0);
				}
			}
			else if(previousX == '1'){
				if( (x != '\0') && ((x < '0') | (x > '9')) )
					set_PWM(MIDDLE_C);
				else{
					set_PWM(0);
				}
			}
			else if(previousX == '0'){
				if( (x != '\0') && ((x < '0') | (x > '9')) )
					set_PWM(MIDDLE_C);
				else{
					set_PWM(0);
				}
			}
		break;
		
		case getHr2UT: //Hr2UT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			unlock_time_display[1] = x;
			unlock_hour2 = x;
			unlock_hour2 -= 48;
			
			gotHr2UT = 1;
		break;
		
		case waitHr2UT: //Min1UT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '5')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getMin1UT: //Min1UT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			unlock_time_display[2] = x;
			unlock_min1 = x;
			unlock_min1 -= 48;
			unlock_min1 *= 10;
			
			gotMin1UT = 1;
		break;
		
		case waitMin1UT: //Min2UT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '9')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getMin2UT: //Min2UT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			unlock_time_display[3] = x;
			unlock_min2 = x;
			unlock_min2 -= 48;
			
			gotMin2UT = 1;
		break;
		
		case waitMin2UT: //Sec1UT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '5')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getSec1UT: //Sec1UT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			unlock_time_display[4] = x;
			unlock_sec1 = (x-48)*10;
			
			gotSec1UT = 1;
		break;
		
		case waitSec1UT: //Sec2UT input
			speech = 0x00;
			
			if( (x != '\0') && ((x < '0') | (x > '9')) ){
				set_PWM(MIDDLE_C);
			}
			else{
				set_PWM(0);
			}
		break;
		
		case getSec2UT: //Sec2UT computation
			set_PWM(0);
			speech = 0x01;
			index = (x - 48);
			previousX = x;
			
			unlock_time_display[5] = x;
			unlock_sec2 = x-48;
			
			gotSec2UT = 1;
		break;
		
		case waitSec2UT:
			set_PWM(0);
			speech = 0x00;
		break;
		
		case petCheck:
			if(petInside == 0x01)
				set_PWM(MIDDLE_E);
			else
				set_PWM(0);
		break;
		
		default:
		break;
	} //end Actions
	return state;
}//end Key_SM



#endif /* KEY_SM_H_ */
