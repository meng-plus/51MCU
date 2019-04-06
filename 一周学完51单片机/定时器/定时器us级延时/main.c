#include <REGX52.H>
#include "Time.h"

void main()
{
    unsigned int Delay=500;
	//测试软件小延时
		P1_1=0;
	  Delay10us();
    P1_1=!P1_1;
    Delay10us();
    P1_1=!P1_1;
	
	//测试定时器小延时
		P1_1=0;
		T1Delayus(100);
		P1_1=1;
		T1_RUN(1);
		while(!TF1);
		P1_1=!P1_1;
		T1_Flag(0);
    while(1)
    {
    }
}