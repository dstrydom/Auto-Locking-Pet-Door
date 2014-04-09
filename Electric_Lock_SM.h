/*
 * Electric_Lock_SM.h
 */ 


#ifndef ELECTRIC_LOCK_SM_H_
#define ELECTRIC_LOCK_SM_H_

#include "globalVariables.h"

enum Electric_Lock_States{lock_wait, lock, unLock};
int Electric_Lock_SM(int state){
	//Transitions
	switch(state){
		case lock_wait:
			if(doorLock == 1)
				state = lock;
		break;
		
		case lock:
			if(doorLock == 0){
				state = unLock;
			}
			//else stay in lock state
		break;
		
		case unLock:
			state = lock_wait;
		break;
		
		default:
			state = lock_wait;
		break;
	}//end transitions
	
	// Actions
	switch (state) {
		case lock_wait:
			//High voltage on pin7 to unlock.
			//Should remain unlocked when not in lock state.
			PORTB = (PORTB | 0x80);
		break; //no actions
		
		case lock:
			//Low voltage on pin7 to lock.
			PORTB = (PORTB & 0x7F);
		break;
		
		case unLock:
			//High voltage on pin7 to unlock
			PORTB = (PORTB | 0x80);
		break;
		
		default:
			//Default should be that door is unlocked.
			PORTB = (PORTB | 0x80);
		break;
	}//end actions
	
	return state;
}//end Electric_Lock_SM

#endif /* ELECTRIC_LOCK_SM_H_ */
