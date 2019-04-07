#include <REGX52.H>
#include "Time.h"

void main()
{
    //测试软件小延时
    P1_1=0;
    Delay10us();//软件延时
    P1_1=!P1_1;
    Delay10us();
    P1_1=!P1_1;

    //测试定时器小延时
    P1_1=0;
    //调整调用顺序也能解决问题
    T1Delayus(100);
	T1_RUN(1);//定时器延时
    P1_1=1;
    while(!TF1);
    P1_1=!P1_1;
	T1_RUN(0);
    T1_Flag(0);


    while(1)
    {
    }
}