#include <REGX52.H>
#include <stdio.h>
#include "Time.h"//定时器配置文件
#include "MulDigitalTube.h" //数码管显示驱动
sbit InPutSign=P3^2;//信号输入引脚

TimeVal   timeCycle;//脉冲宽度统计时间
void CalcFreq();

void main()
{
  MulDigInit();
  T1init();

  while (1)
  {
    CalcFreq();

    if(timeCycle.ms>100)
    {
      float var=1000.0/timeCycle.ms;
      DigSetFData((unsigned int)var);
    }
    else
    {
      float var=timeCycle.ms+timeCycle.us*0.001;
      var=1000.0/var;
      DigSetFData((unsigned int)var);
    }
  }
}


void CalcFreq()
{
  InPutSign=1;
  T0Init();

  while(InPutSign==0);

  T0_RUN(1);//开定时器

  while(InPutSign==1)
  {
    if(GetTime()>2000)
    {
      EndTime(&timeCycle);
      return;
    }
  }

  while(InPutSign==1)
  {
    if(GetTime()>2000)
    {
      EndTime(&timeCycle);
      return;
    }
  }

  EndTime(&timeCycle);
}