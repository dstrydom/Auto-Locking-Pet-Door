/*
 * LCD_SM.h
 */ 


#ifndef LCD_SM_H_
#define LCD_SM_H_

#include "globalVariables.h"

enum LCD_States {start_wait, welcome, welcome_wait, prompt1CT, prompt1CT_wait, prompt2CT, prompt2CT_wait, hour1CT, hour2CT, min1CT, min2CT, sec1CT, sec2CT,
													prompt1LT, prompt1LT_wait, prompt2LT, prompt2LT_wait, hour1LT, hour2LT, min1LT, min2LT, sec1LT, sec2LT,
													prompt1UT, prompt1UT_wait, prompt2UT, prompt2UT_wait, hour1UT, hour2UT, min1UT, min2UT, sec1UT, sec2UT, accept};
int LCD_SM(LCD_States){
	static unsigned int timer;
	
	switch(LCD_States){
		case start_wait:
			LCD_go_g = 0;
			LCD_States = welcome;
		break;
			
		case welcome:	
			LCD_go_g = 0;
			if(LCD_rdy_g){
				strcpy(LCD_string_g, "    Welcome!                     ");
				LCD_go_g = 1;
				LCD_States = welcome_wait;
			}
		break;
		
		case welcome_wait:
			if(timer < 1000)
				++timer;
			else{
				timer = 0;
				LCD_States = prompt1CT;
			}
		break;
		
		case prompt1CT:
			LCD_go_g = 0;
			if(LCD_rdy_g){
				strcpy(LCD_string_g, "Enter current   time starting   ");
				LCD_go_g = 1;
				LCD_States = prompt1CT_wait;
			}
		break;
		
		case prompt1CT_wait:
			if(timer < 2000)
				++timer;
			else{
				timer = 0;
				LCD_States = prompt2CT;
			}
		break;
		
		case prompt2CT:
			LCD_go_g = 0;
			if(LCD_rdy_g){
				prompt1 = 0x01;
				strcpy(LCD_string_g, "with hours:             hh:mm:ss");
				LCD_go_g = 1;
				LCD_States = prompt2CT_wait;
			}
		break;
		
		case prompt2CT_wait:
		if(timer < 2000){
			if(timer >= 200)	
				prompt1 = 0x00;
			++timer;
		}			
		else{
			timer = 0;
			LCD_States = hour1CT;
		}
		break;
				
		case hour1CT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotHr1CT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //hour digit one
				LCD_string_g[24] = current_time_display[0];
				LCD_go_g = 1;
				LCD_States = hour2CT;
			}
		break;
			
		case hour2CT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotHr2CT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //hour digit two
				LCD_string_g[24] = current_time_display[0];
				LCD_string_g[25] = current_time_display[1];
				LCD_go_g = 1;
				LCD_States = min1CT;
			}
		break;
		
		case min1CT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotMin1CT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //minute digit one
				LCD_string_g[24] = current_time_display[0];
				LCD_string_g[25] = current_time_display[1];
				LCD_string_g[27] = current_time_display[2];
				LCD_go_g = 1;
				LCD_States = min2CT;
			}
		break;
		
		case min2CT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotMin2CT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //minute digit two
				LCD_string_g[24] = current_time_display[0];
				LCD_string_g[25] = current_time_display[1];
				LCD_string_g[27] = current_time_display[2];
				LCD_string_g[28] = current_time_display[3];
				LCD_go_g = 1;
				LCD_States = sec1CT;
			}
		break;
		
		case sec1CT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotSec1CT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //second digit one
				LCD_string_g[24] = current_time_display[0];
				LCD_string_g[25] = current_time_display[1];
				LCD_string_g[27] = current_time_display[2];
				LCD_string_g[28] = current_time_display[3];
				LCD_string_g[30] = current_time_display[4];
				LCD_go_g = 1;
				LCD_States = sec2CT;
			}
		break;
					
		case sec2CT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotSec2CT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //second digit two
				LCD_string_g[24] = current_time_display[0];
				LCD_string_g[25] = current_time_display[1];
				LCD_string_g[27] = current_time_display[2];
				LCD_string_g[28] = current_time_display[3];
				LCD_string_g[30] = current_time_display[4];
				LCD_string_g[31] = current_time_display[5];
				LCD_go_g = 1;
				LCD_States = prompt1LT;
			}
		break;
		
		case prompt1LT:
			LCD_go_g = 0;
			if(LCD_rdy_g){
				strcpy(LCD_string_g, "Enter auto lock time starting   ");
				//strcpy(LCD_string_g, "Enter current   time starting   ");
				LCD_go_g = 1;
				LCD_States = prompt1LT_wait;
			}
		break;
		
		case prompt1LT_wait:
			if(timer < 2000)
				++timer;
			else{
				timer = 0;
				LCD_States = prompt2LT;
			}
		break;
		
		case prompt2LT:
			LCD_go_g = 0;
			if(LCD_rdy_g){
				prompt2 = 0x01;
				strcpy(LCD_string_g, "with hours:             hh:mm:ss");
				LCD_go_g = 1;
				LCD_States = prompt2LT_wait;
			}
		break;
		
		case prompt2LT_wait:
		if(timer < 2000){
			if(timer >= 200)
				prompt2 = 0x00;
			++timer;
		}			
		else{
			timer = 0;
			LCD_States = hour1LT;
		}
		break;
				
		case hour1LT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotHr1LT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //hour digit one
				LCD_string_g[24] = lock_time_display[0];
				LCD_go_g = 1;
				LCD_States = hour2LT;
			}
		break;
			
		case hour2LT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotHr2LT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //hour digit two
				LCD_string_g[24] = lock_time_display[0];
				LCD_string_g[25] = lock_time_display[1];
				LCD_go_g = 1;
				LCD_States = min1LT;
			}
		break;
		
		case min1LT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotMin1LT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //minute digit one
				LCD_string_g[24] = lock_time_display[0];
				LCD_string_g[25] = lock_time_display[1];
				LCD_string_g[27] = lock_time_display[2];
				LCD_go_g = 1;
				LCD_States = min2LT;
			}
		break;
		
		case min2LT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotMin2LT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //minute digit two
				LCD_string_g[24] = lock_time_display[0];
				LCD_string_g[25] = lock_time_display[1];
				LCD_string_g[27] = lock_time_display[2];
				LCD_string_g[28] = lock_time_display[3];
				LCD_go_g = 1;
				LCD_States = sec1LT;
			}
		break;
		
		case sec1LT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotSec1LT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //second digit one
				LCD_string_g[24] = lock_time_display[0];
				LCD_string_g[25] = lock_time_display[1];
				LCD_string_g[27] = lock_time_display[2];
				LCD_string_g[28] = lock_time_display[3];
				LCD_string_g[30] = lock_time_display[4];
				LCD_go_g = 1;
				LCD_States = sec2LT;
			}
		break;
					
		case sec2LT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotSec2LT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //second digit two
				LCD_string_g[24] = lock_time_display[0];
				LCD_string_g[25] = lock_time_display[1];
				LCD_string_g[27] = lock_time_display[2];
				LCD_string_g[28] = lock_time_display[3];
				LCD_string_g[30] = lock_time_display[4];
				LCD_string_g[31] = lock_time_display[5];
				LCD_go_g = 1;
				LCD_States = prompt1UT; 
			}
		break;
	
		case prompt1UT:
			LCD_go_g = 0;
			if(LCD_rdy_g){
				strcpy(LCD_string_g, "Enter unlock    time starting   ");
				LCD_go_g = 1;
				LCD_States = prompt1UT_wait;
			}
		break;
		
		case prompt1UT_wait:
			if(timer < 2000)
				++timer;
			else{
				timer = 0;
				LCD_States = prompt2UT;
			}
		break;
		
		case prompt2UT:
			LCD_go_g = 0;
			if(LCD_rdy_g){
				prompt3 = 0x01;
				strcpy(LCD_string_g, "with hours:             hh:mm:ss");
				LCD_go_g = 1;
				LCD_States = prompt2UT_wait;
			}
		break;
		
		case prompt2UT_wait:
		if(timer < 2000){
			if(timer >= 200)
				prompt3 = 0x00;
			++timer;
		}			
		else{
			timer = 0;
			LCD_States = hour1UT;
		}
		break;
				
		case hour1UT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotHr1UT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //hour digit one
				LCD_string_g[24] = unlock_time_display[0];
				LCD_go_g = 1;
				LCD_States = hour2UT;
			}
		break;
			
		case hour2UT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotHr2UT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //hour digit two
				LCD_string_g[24] = unlock_time_display[0];
				LCD_string_g[25] = unlock_time_display[1];
				LCD_go_g = 1;
				LCD_States = min1UT;
			}
		break;
		
		case min1UT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotMin1UT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //minute digit one
				LCD_string_g[24] = unlock_time_display[0];
				LCD_string_g[25] = unlock_time_display[1];
				LCD_string_g[27] = unlock_time_display[2];
				LCD_go_g = 1;
				LCD_States = min2UT;
			}
		break;
		
		case min2UT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotMin2UT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //minute digit two
				LCD_string_g[24] = unlock_time_display[0];
				LCD_string_g[25] = unlock_time_display[1];
				LCD_string_g[27] = unlock_time_display[2];
				LCD_string_g[28] = unlock_time_display[3];
				LCD_go_g = 1;
				LCD_States = sec1UT;
			}
		break;
		
		case sec1UT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotSec1UT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //second digit one
				LCD_string_g[24] = unlock_time_display[0];
				LCD_string_g[25] = unlock_time_display[1];
				LCD_string_g[27] = unlock_time_display[2];
				LCD_string_g[28] = unlock_time_display[3];
				LCD_string_g[30] = unlock_time_display[4];
				LCD_go_g = 1;
				LCD_States = sec2UT;
			}
		break;
					
		case sec2UT:
			LCD_go_g = 0;
			if(LCD_rdy_g && gotSec2UT){
				strcpy(LCD_string_g, "                        hh:mm:ss"); //second digit two
				LCD_string_g[24] = unlock_time_display[0];
				LCD_string_g[25] = unlock_time_display[1];
				LCD_string_g[27] = unlock_time_display[2];
				LCD_string_g[28] = unlock_time_display[3];
				LCD_string_g[30] = unlock_time_display[4];
				LCD_string_g[31] = unlock_time_display[5];
				LCD_go_g = 1;
				LCD_States = accept; //***************************************TODO change to accept or redo
			}
		break;
		
		case accept:
			LCD_go_g = 0;
			if(LCD_rdy_g){
				strcpy(LCD_string_g, "Time set.                       ");
				LCD_string_g[24] = current_time_display[0];
				LCD_string_g[25] = current_time_display[1];
				LCD_string_g[27] = current_time_display[2];
				LCD_string_g[28] = current_time_display[3];
				LCD_string_g[30] = current_time_display[4];
				LCD_string_g[31] = current_time_display[5];
				LCD_go_g = 1;
				LCD_States = accept; //***************************************TODO change to input new time
			}
		break;
		
		default:
			LCD_States = welcome;
		break;
	}
	return LCD_States;
}//end




#endif /* LCD_SM_H_ */
