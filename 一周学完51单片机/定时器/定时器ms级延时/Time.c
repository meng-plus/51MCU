// Header: 8051内核单片机通用定时器T0 T1头文件
// File Name: Time.h
// Author: 蒙蒙plus
// Date: 2019年4月6日
// Version: V1.0

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
void TimeInit(unsigned int Reload)
{
    T0_RUN(0);//关定时器
    //设定工作模式
    TMOD &=0xf0;
    TMOD |= T0NoReload16B;
    TMOD &= ~T0Count;
    //初始值设定
    T0Reload=(65536-FOSC/12/Reload)+9; //设置重载值 非自动重载补偿9
    TH0=T0Reload>>8;
    TL0=T0Reload;
    EA=1;//开总中断
    T0_EnIT(1);//开定时器0中断
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
    if(DelayStruct->State ==Start)
    {
        DelayStruct->StartMs=SystemTick;
        DelayStruct->EndMs = DelayStruct->StartMs+DelayStruct->DelayMs;
    }
    if( DelayStruct->EndMs > DelayStruct->StartMs)
    {
        if( SystemTick > DelayStruct->EndMs)
        {
            DelayStruct->State=Ok;
        }
        else
        {
            DelayStruct->State=Wait;
        }
    }
    else
    {
        if( SystemTick<DelayStruct->StartMs && SystemTick > DelayStruct->EndMs)
        {
            DelayStruct->State=Ok;
        }
        else
        {
            DelayStruct->State=Wait;
        }
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
    unsigned int CurrentTime=SystemTick;
    while(Time)
    {
        if(CurrentTime!=SystemTick)
        {
            CurrentTime=SystemTick;
            Time--;
        }
    }
}
/****************************
//Function Name:  定时器0中断函数
//Input : void
//Output: void
//Description:
//
//***************************/
void Time0(void) interrupt 1
{
    TH0=T0Reload>>8;
    TL0=T0Reload;
    T0_ClearFlag(0);
    SystemTick++;

}
/****************************
//Function Name:  定时器1中断函数
//Input : void
//Output: void
//Description:
//
//***************************/
void Time1(void) interrupt 3
{

}