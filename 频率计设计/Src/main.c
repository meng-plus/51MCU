#include <REGX52.H>
#include <stdio.h>
#include "LCD1602.h"
#include "Time.h"

sbit InPutSign=P3^2;
unsigned char *Mode = "MODE:Auto";
unsigned char *Freq = "Freq:";
//unsigned char *ModeStr[]= {"Sin","Tri","Squ"};
typedef enum {ZhengXian,SanJiao,FangBo} SingleMode;

TimeVal   timeCycle;
char str[20];
SingleMode checkMode();
void CalcFreq();
void main()
{
//  SingleMode SGmode;

  InitLcd1602();
  LcdShowStr(0, 0, Mode);
  LcdShowStr(0, 1, Freq);
 // LcdShowStr(5,0,ModeStr[SGmode]);

  while (1)
  {
    CalcFreq();

    if(timeCycle.ms>100)
    {
			float var =1000.0/timeCycle.ms;
      sprintf(str," %0.3f",var);
    }
    else
    {
			float var=timeCycle.ms+timeCycle.us*0.001;
			var=1000.0/var;
      sprintf(str," %0.3f",var);
    }

    LcdShowStr(5,1,str);

  }
}

void CalcFreq()
{
  InPutSign=1;
  TimeInit();

  while(InPutSign==0);

  T0_RUN(1);//¿ª¶¨Ê±Æ÷

  while(InPutSign==1)
  {
    if(GetTime()>2000)
    {
      EndTime(&timeCycle);
      return;
    }
  }
  while(InPutSign==0)
  {
    if(GetTime()>2000)
    {
      EndTime(&timeCycle);
      return;
    }
  }
  EndTime(&timeCycle);
}