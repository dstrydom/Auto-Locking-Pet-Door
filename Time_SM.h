/*
 * Time_SM.h
 */ 


#ifndef TIME_SM_H_
#define TIME_SM_H_

#include "globalVariables.h"

enum Time_States{time_wait, set_times, start};
int Time_SM(int state){	
	static int lock_seconds;
	static int lock_minutes;
	static int lock_hours;
	static int unlock_seconds;
	static int unlock_minutes;
	static int unlock_hours;
	
	static int seconds = 0;
	static int minutes = 0;
	static int hours = 0;
	
	//Transitions
	switch(state){
		case time_wait:
			if(gotSec2UT == 1)
				state = set_times;
		break;
		
		case set_times:
			state = start;
		break;
		
		case start:
			state = start;
		break;
		
		default:
			state = time_wait;
		break;
	}//end Transitions
	
	//Actions
	switch(state){
		case time_wait:
		break;
		
		
		case set_times:
			seconds = current_sec1 + current_sec2;
			minutes = current_min1 + current_min2;
			hours = current_hour1 + current_hour2;
			
			lock_seconds = lock_sec1 + lock_sec2;
			lock_minutes = lock_min1 + lock_min2;
			lock_hours = lock_hour1 + lock_hour2;
			
			unlock_seconds = unlock_sec1 + unlock_sec2;
			unlock_minutes = unlock_min1 + unlock_min2;
			unlock_hours = unlock_hour1 + unlock_hour2;
		break;
		
		case start:
			//check time to lock_time
			if( (seconds == lock_seconds) && (minutes == lock_minutes) && (hours == lock_hours) )
			{
				doorLock = 1; //sets flag to lock door
			}
			
			//check time to unlock_time
			if( (seconds == unlock_seconds) && (minutes == unlock_minutes) && (hours == unlock_hours) )
			{
				doorLock = 0; //sets flag to unlock door
			}
			
			//CLOCK DISPLAYED IN REAL TIME
			current_time_display[0] = (hours / 10) + 48;
			current_time_display[1] = (hours % 10) + 48;
			
			current_time_display[2] = (minutes / 10) + 48;
			current_time_display[3] = (minutes % 10) + 48;
			
			current_time_display[4] = (seconds / 10) + 48;
			current_time_display[5] = (seconds % 10) + 48;
			
			//increases time
			++seconds;
			
			if(seconds > 59)
			{
				seconds = 0;
				++minutes;
				
				if(minutes > 59)
				{
					minutes = 0;
					++hours;
					
					if(hours > 24)
					{
						hours = 0;
					}
				}
			}
			
		break;	
	}//end Actions
	
	return state;
}//end Time_SM



#endif /* TIME_SM_H_ */
