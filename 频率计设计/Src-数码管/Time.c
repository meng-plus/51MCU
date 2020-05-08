
#include "Time.h"

//#message "Time.h将使用REGX52.H头文件"
#include <REGX52.H>

#define FOSC 12000000L      //System frequency
//#message Time.h设定的晶振频率为 12000000L
//---TMOD工作设置---//
#define  T0NoReload13B 0x00
#define  T0NoReload16B 0x01
#define  T0Reload8B    0x10
#define  T0dual8B      0x11
#define  T0Count       0x04
#define  T0GATE        0x08

#define  T1NoReload13B 0x00
#define  T1NoReload16B 0x01
#define  T1Reload8B    0x10
#define  T1UnUsed8B    0x11
#define  T1Count       0x40
#define  T1GATE        0x80

//---TCON工作设置---//

//定时器重载值
unsigned int T0Reload,T1Reload;

//全局系统时钟
unsigned int SystemTick =0;

/****************************
//Function Name:  定时器
//Input : FOSC 晶振频率
          Reload 重载频率 频率范围(100~100000)
//Output: void
//Description:  定时器初始化集中配置定时器
//
//***************************/
void T0Init()
{
  T0_RUN(0);//关定时器
  //设定工作模式
  TMOD &=0xf0;
  TMOD |= T0NoReload16B;
  TMOD &= ~T0Count;
  IT0=0;//低电平触发
  //初始值设定
  SystemTick=0;

  T0Reload=(65536-FOSC/12/1000)+9; //设置重载值 非自动重载补偿9
  TH0=T0Reload>>8;
  TL0=T0Reload;
  EA=1;//开总中断
  T0_EnIT(1);//开定时器0中断

}
void T1Init()
{
  T1_RUN(0);//关定时器
  TMOD &=0x0f;
  TMOD |= T1NoReload16B;
  TMOD &= ~T1Count;
  T1Reload=(65536-FOSC/12/100)+9; //设置重载值 非自动重载补偿9
  TH1=T1Reload>>8;
  TL1=T1Reload;
  T1_EnIT(1);//开定时器1中断
  T1_RUN(1);//关定时器
}
/****************************
//Function Name:  定时器0中断函数
//Input : void
//Output: void
//Description:
//
//***************************/
void Time0() interrupt 1
{
  TH0=T0Reload>>8;
  TL0=T0Reload;
  T0_ClearFlag(0);
  SystemTick++;

}

//数码管动态刷新
void MulDigPlay();
void Time1() interrupt 3
{
  TH1=T1Reload>>8;
  TL1=T1Reload;
  T1_ClearFlag(0);
  MulDigPlay();
}
void StartTime()
{
//T0Init();
  T0_RUN(1);//开定时器
}
unsigned int GetTime()
{

  return SystemTick;
}

void EndTime(TimeVal* val)
{
  T0_RUN(0);//关定时器
  val->ms=SystemTick;
  val->us=((TH0<<8)+TL0)-T0Reload;
}