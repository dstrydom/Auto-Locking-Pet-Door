/*
 * USART_Follower_SM.h
 */ 


#ifndef USART_FOLLOWER_SM_H_
#define USART_FOLLOWER_SM_H_

enum USART_Follower_States{wait_UR, received, clear};
int USART_Follower_SM(int state){	
	//Transitions
	switch(state){
		case wait_UR:
			if(USART_HasReceived())
				state = received;
			break;
			
		case received:
			state = clear;
			break;
			
		case clear:
			state = wait_UR;
			break;
			
		default:
			state = wait_UR;
			break;
	}
	
	//Actions
	switch(state){
		case wait_UR:
			break;
			
		case received:
			petInside = USART_Receive();				
		break;
			
		case clear:
			USART_Flush();
			break;
			
		default:
			break;
	}
	return state;
}


#endif /* USART_FOLLOWER_SM_H_ */
