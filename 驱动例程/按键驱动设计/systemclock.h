// Header:
// File Name: systemclock.h
// Author: XXXX
// Date: 2019Äê1ÔÂ7ÈÕ

#ifndef __SYSTEMCLOCK_H_
#define __SYSTEMCLOCK_H_

/*Contains the necessary header files*/
#include <REGX52.H>
#include "systemclock.h"
/*Defining global variables*/
extern unsigned int T10ms;
/*Define input and output ports*/

#define Time100ms 10
#define Time1s 100

/*Declare internal functions*/
void Timer0Init(); //Initialize Time0 as the system clock
//void delay10ms(unsigned int times);//10ms unit delay 10*times
unsigned int GetTime();

#endif
