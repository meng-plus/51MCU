/*********************************/
/*接线说明
切换按键 sbit Key1=P3^1;
*/
/*LCD1602显示接线
#define LCD1602_DB  P0      //data bus 数据总线
sbit LCD1602_RS = P2^6;
sbit LCD1602_RW = P2^5;
sbit LCD1602_EN = P2^7;
*/
/*ADC XPT2046接线说明
//---定义使用的IO口---//
sbit CLK  = P3^6;	  //时钟
sbit CS   = P3^5;	  //片选
sbit DIN  = P3^4;	  //输入
sbit DOUT = P3^7;	  //输出
*/
//注意 如需修改接线请到对应 驱动文件修改
/********************************/
#include <REGX52.H>
#include <stdio.h>
#include "LCD1602.h"
#include "Time.h"
#include "keyBoard.h"
#include"XPT2046.h"
sbit InPutSign=P3^2;
unsigned char *Mode = "Mode:";
unsigned char *Freq = "Freq:";
unsigned char *ModeStr[]= {"Sin","Tri","Squ"};
typedef enum {ZhengXian,SanJiao,FangBo} SingleMode;

KeyStruct keyVal;
TimeVal   timeCycle[3];
unsigned int ADCMaxVal;
char str[20];
SingleMode checkMode();
void CalcFreq();
void CalcFreqSine();
void CaleFreqSqu();
void main()
{
  SingleMode SGmode;
  InitLcd1602();
  LcdShowStr(0, 0, Mode);
  LcdShowStr(0, 1, Freq);
  LcdShowStr(5,0,ModeStr[SGmode]);

  while (1)
  {
    if(key_scan(&keyVal)==KeyFallEdge)
    {
      SGmode =(SGmode+1)%3;
      LcdShowStr(5,0,ModeStr[SGmode]);
    }

    switch(SGmode)
    {
    case ZhengXian:
      CalcFreqSine();

      if(timeCycle[2].ms>100)
      {
        sprintf(str," %.3f",1000.0/timeCycle[2].ms);
      }
      else
      {
        sprintf(str," %.3f",1000.0/(timeCycle[2].ms+timeCycle[2].us*0.001));
      }

      LcdShowStr(5,1,str);
      sprintf(str,"%.3f",(ADCMaxVal*5.0/0xFFF)*2);
      LcdShowStr(9,0,str);
      break;

    case SanJiao:
			CalcFreqSine();
      if(timeCycle[2].ms>100)
      {
        sprintf(str," %.3f",1000.0/timeCycle[2].ms);
      }
      else
      {
        sprintf(str," %.3f",1000.0/(timeCycle[2].ms+timeCycle[2].us*0.001));
      }

      LcdShowStr(5,1,str);
      sprintf(str,"%.3f",(ADCMaxVal*5.0/0xFFF)*2);
      LcdShowStr(9,0,str);
      break;

    case FangBo:
      CaleFreqSqu();

      if(timeCycle[2].ms>100)
      {
        sprintf(str," %.3f",1000.0/timeCycle[2].ms);
      }
      else
      {
        sprintf(str," %.3f",1000.0/(timeCycle[2].ms+timeCycle[2].us*0.001));
      }

      LcdShowStr(5,1,str);
      sprintf(str,"%.3f",timeCycle[1].ms*1.0/timeCycle[2].ms);
      LcdShowStr(9,0,str);
      break;

    default:
      break;
    }


  }
}
//分析方波
void CaleFreqSqu()
{
  uint ADCMax,ADCMin,Val,AveVal;
  TimeInit();
  T0_RUN(1);//开定时器
  ADCMin=ADCMax=	Read_AD_Data(0xE4);

  //获得方波的最大最小范围
  while(GetTime()<500)
  {
    Val=Read_AD_Data(0xE4);

    if(Val>ADCMax)ADCMax=Val;
    else if(Val<ADCMin)ADCMin=Val;
  }

  AveVal=(ADCMin+ADCMax)/2;
    TimeInit();
  if(Val>AveVal)
  {
    //高电平区间
    while(Read_AD_Data(0xE4)>AveVal);

    T0_RUN(1);//开定时器

    while(Read_AD_Data(0xE4)<AveVal)
    {
      if(GetTime()>1000)
      {
        T0_RUN(0);
        return;
      }
    }

    EndTime(timeCycle);
    T0_RUN(1);//开定时器

    while(Read_AD_Data(0xE4)>AveVal)
    {
      if(GetTime()>1000)
      {
        T0_RUN(0);
        return;
      }
    }

    EndTime(timeCycle+2);
    timeCycle[1].ms=timeCycle[2].ms-timeCycle[0].ms;
  }
  else
  {
    //低电平区间
    while(Read_AD_Data(0xE4)<AveVal);

    T0_RUN(1);//开定时器

    while(Read_AD_Data(0xE4)>AveVal)
    {
      if(GetTime()>1000)
      {
        T0_RUN(0);
        return;
      }
    }

    EndTime(timeCycle+1);
    T0_RUN(1);//开定时器

    while(Read_AD_Data(0xE4)<AveVal)
    {
      if(GetTime()>1000)
      {
        T0_RUN(0);
        return;
      }
    }

    EndTime(timeCycle+2);
    timeCycle[0].ms=timeCycle[2].ms-timeCycle[1].ms;
  }
}
//分析正弦波频率
void CalcFreqSine()
{
  TimeInit();
  ADCMaxVal=GetMaxADCVal();
  T0_RUN(1);//开定时器
  ADCMaxVal=GetMaxADCVal();
  EndTime(timeCycle+2);
}
void CalcFreq()
{
  InPutSign=1;
  TimeInit();
  T0_RUN(1);//开定时器

  if(InPutSign==0)
  {
    //等高电平边缘
    while(InPutSign==0)
    {
      if(GetTime()>2000)
      {
        T0_RUN(0);
        return;
      }
    }

    TimeInit();
    T0_RUN(1);

//统计高电平时间
    while(InPutSign==1)
    {
      if(GetTime()>2000)
      {
        T0_RUN(0);
        return;
      }
    }

    EndTime(timeCycle+1);
    //统计所有时间
    T0_RUN(1);

    while(InPutSign==0)
    {
      if(GetTime()>2000)
      {
        T0_RUN(0);
        return;
      }
    }

    EndTime(timeCycle+2);
    timeCycle[0].ms=timeCycle[2].ms-timeCycle[1].ms;
  }
  else
  {
    //度过高电平 寻找低电平
    while(InPutSign==1)
    {
      if(GetTime()>2000)
      {
        T0_RUN(0);
        return;
      }
    }

//计时低电平时间
    TimeInit();
    T0_RUN(1);

    while(InPutSign==0)
    {
      if(GetTime()>2000)
      {
        T0_RUN(0);
        return;
      }
    }

    EndTime(timeCycle);
    //继续计时高电平时间
    T0_RUN(1);

    while(InPutSign==1)
    {
      if(GetTime()>2000)
      {
        T0_RUN(0);
        return;
      }
    }

    EndTime(timeCycle+2);
    timeCycle[1].ms=timeCycle[2].ms-timeCycle[0].ms;
  }
}