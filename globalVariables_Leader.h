/*
 * globalVariables_Leader.h
 */ 


#ifndef GLOBALVARIABLES_LEADER_H_
#define GLOBALVARIABLES_LEADER_H_

/*flag used to determine if pet is in/outside*/
unsigned int petInside = 0;

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


#endif /* GLOBALVARIABLES_LEADER_H_ */
