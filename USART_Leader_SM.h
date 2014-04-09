/*
 * USART_Leader_SM.h
 */ 


#ifndef USART_LEADER_SM_H_
#define USART_LEADER_SM_H_

enum USART_Leader_States{wait_UL, send, transmitting};
int USART_Leader_SM(int state){	
	//Transitions
	switch(state){
		case wait_UL:
			if(USART_IsSendReady())
				state = send;
			break;
			
		case send:
			state = transmitting;
			break;
			
		case transmitting:
			if(USART_HasTransmitted())
				state = wait_UL;
			break;
			
		default:
			state = wait_UL;
			break;
	}
	
	//Actions
	switch(state){
		case wait_UL:
			break;
			
		case send:
			USART_Send(petInside);
			
			break;
			
		case transmitting:
			break;
			
		default:
			break;
	}
	return state;
}


#endif /* USART_LEADER_SM_H_ */
