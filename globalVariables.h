/*
 * globalVariables.h
 */ 


#ifndef GLOBALVARIABLES_H_
#define GLOBALVARIABLES_H_

/*used to display times*/
unsigned char current_time_display[6];		//current time entered
unsigned char lock_time_display[6];			//time door should auto-lock
unsigned char unlock_time_display[6]; 		//time door should auto-unlock

/*flags to indicate units of time have been input*/
unsigned int gotHr1CT = 0;		/*current time*/
unsigned int gotHr2CT = 0;
unsigned int gotMin1CT = 0;
unsigned int gotMin2CT = 0;
unsigned int gotSec1CT = 0;
unsigned int gotSec2CT = 0;

unsigned int gotHr1LT = 0;		/*lock time*/
unsigned int gotHr2LT = 0;
unsigned int gotMin1LT = 0;
unsigned int gotMin2LT = 0;
unsigned int gotSec1LT = 0;
unsigned int gotSec2LT = 0;

unsigned int gotHr1UT = 0;		/*unlock time*/
unsigned int gotHr2UT = 0;
unsigned int gotMin1UT = 0;
unsigned int gotMin2UT = 0;
unsigned int gotSec1UT = 0;
unsigned int gotSec2UT = 0;

/*numerical values of times input*/
unsigned int current_hour1;			//1st digit of current hour
unsigned int current_hour2;			//2nd digit of current hour
unsigned int current_min1;			//1st digit of current min
unsigned int current_min2;			//2nd digit of current min
unsigned int current_sec1;			//1st digit of current sec
unsigned int current_sec2;			//2nd digit of current sec

unsigned int lock_hour1;			/*lock time*/
unsigned int lock_hour2;
unsigned int lock_min1;
unsigned int lock_min2;
unsigned int lock_sec1;
unsigned int lock_sec2;

unsigned int unlock_hour1;			/*unlock time*/
unsigned int unlock_hour2;
unsigned int unlock_min1;
unsigned int unlock_min2;
unsigned int unlock_sec1;
unsigned int unlock_sec2;


/*flag used to lock/unlock door*/
unsigned int doorLock = 0;

/*flag used to determine if pet is in/outside*/
unsigned int petInside = 0;

/*flag used to choose from sound menu*/
unsigned int sound = 0x00;

/*flag used to turn on chipcorder sm*/
unsigned int speech = 0x00;

/*flag used to choose from chipcorder menu*/
unsigned int index = 0x00;

/*flag used as input prompt*/
unsigned int prompt1 = 0x00; //enter current time
unsigned int prompt2 = 0x00; //enter lock time
unsigned int prompt3 = 0x00; //enter unlock time

/*Sonar function to convert microseconds to inches*/
int microsecondsToInches(int microseconds)
{
	// According to Parallax's datasheet for the PING))), there are
	// 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
	// second).  This gives the distance travelled by the ping, outbound
	// and return, so we divide by 2 to get the distance of the obstacle.
	// See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
	return microseconds / 74;
}


#endif /* GLOBALVARIABLES_H_ */
