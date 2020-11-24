/***************************************************************
***Description:全局系统时钟，为系统提供时间依据
***
***
***Author:cmm
***Date:202008
***************************************************************/

#include "STC8G_USER.H"
#include "TM4_STC8.h"
ClockTypedef Clock_Tm4;
void TM4_Init()
{
  unsigned int T4_1MS = 65536 - 1000;
  Clock_Tm4.MS = 0;
  Clock_Tm4.S = 0;
  /*TM4设置*/
  T4T3M = T4T3M & ~T4R;//停止T4
  T4T3M = T4T3M & ~T4_CT;//用作定时器
  T4T3M = T4T3M & ~T4x12;//12分频
  //也就是说TM4的主频是1M
  T4L = T4_1MS;		//设置定时初值
  T4H = T4_1MS >> 8;		//设置定时初值
  T4T3M = T4T3M | T4R;//启动T4

  /*启动中断*/
  IE2 |= ET4;
  EA = 1;
}
void GetCurrentTime(ClockTypedef* time)
{
  if (time != (void*)0)
  {
    time->MS = Clock_Tm4.MS;
    time->S = Clock_Tm4.S;
  }
}
int SubTimeTi(ClockTypedef* time)
{
  int ms;
  ms=Clock_Tm4.S - time->S;
  if(ms<32&&ms>-1)
  {
    ms=ms*1000+(Clock_Tm4.MS - time->MS); 
  }
  else
  {
    ms=-1;
  }
  return ms;
}
int SubTime(ClockTypedef* time)
{
  int ms;
  ms=Clock_Tm4.S - time->S;
  if(ms<32&&ms>-1)
  {
    ms=ms*1000+(Clock_Tm4.MS - time->MS); 
  }
  else
  {
    ms=-1;
  }
  return ms;
}
/****************************
//Function Name:  非阻塞延时函数
//Input : void
//Output: 延时时间是否到了
//Description: 延时时间不到，不跳出函数
//
//***************************/
void DelayNonBlocking(DelayTypedef* DelayStruct)
{
  unsigned int SystemTick = Clock_Tm4.MS + Clock_Tm4.S * 1000;
  switch (DelayStruct->State)
  {
  case Tm4_Stop:
    return;
    break;
  case Tm4_Start:
    DelayStruct->StartMs = SystemTick;
    DelayStruct->EndMs = DelayStruct->StartMs + DelayStruct->DelayMs;
    DelayStruct->State = Tm4_Wait;
    break;
  case Tm4_Wait:
    if (DelayStruct->EndMs > DelayStruct->StartMs)
    {
      if (SystemTick > DelayStruct->EndMs)
      {
        DelayStruct->State = Tm4_Ok;
      }
      else
      {
        DelayStruct->State = Tm4_Wait;
      }
    }
    else
    {
      if (SystemTick<DelayStruct->StartMs && SystemTick > DelayStruct->EndMs)
      {
        DelayStruct->State = Tm4_Ok;
      }
      else
      {
        DelayStruct->State = Tm4_Wait;
      }
    }
    break;
  case Tm4_Ok:
    DelayStruct->State = Tm4_Stop;
    break;
  }
}

/****************************
//Function Name:  ms级延时函数
//Input : 延时时间
//Output: 延时完毕退出
//Description:
//
//***************************/
void DelayBlocking(unsigned int Time)
{
  unsigned int SystemTick = Clock_Tm4.MS;
  unsigned int CurrentTime = SystemTick;
  while (Time)
  {
    SystemTick = Clock_Tm4.MS;
    if (CurrentTime != SystemTick)
    {
      CurrentTime = SystemTick;
      Time--;
    }
  }
}
void TM4_Isr() interrupt 20
{

  //每1ms进入一次中断来进行计时
  AUXINTIF &= ~T4IF;
  Clock_Tm4.MS++;
  if (Clock_Tm4.MS > 999)
  {
    Clock_Tm4.MS = 0;
    Clock_Tm4.S++;
  }
  else
  {

  }
}