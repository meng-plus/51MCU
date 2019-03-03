

#include "systemclock.h"

/*Defining global variables*/
unsigned int T10ms=0;//0~65535  ->655.35s

void Timer0Init()		//Timer0Init()
{
	TMOD &= 0x0F0;		//Set timer mode
	TMOD |= 0x01;
	TL0 = 0x0F0;		//Set the initial value of the timing
	TH0 = 0x0D8;		//Set the initial value of the timing
	TF0 = 0;		//Clear TF0 flag
	TR0 = 1;		//Timer 0 starts timing
	ET0 = 1;        //Open Interrupt1
	EA  = 1;        //Open total interruption
}

unsigned int GetTime()//获取当前时间
{
	return T10ms;
}

void Timer0Interrupt(void) interrupt 1
{
//Overload 10ms timer
	TL0 = 0x0F0;//TL0=(0x10000-10000)
	TH0 = 0x0D8;//TH0=(0x10000-10000)>>8;

	/*Cumulative timing*/
	T10ms++;
}