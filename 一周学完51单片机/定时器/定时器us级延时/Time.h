// Header: 8051内核单片机通用定时器T0 T1头文件
// File Name: Time.h
// Author: 蒙蒙plus
// Date: 2019年4月6日
// Version: V1.0

#ifndef  __TIME_H_
#define  __TIME_H_


enum DelayState{Start,Stop,Wait,Ok};
//定时器延时函数
typedef struct
{
    unsigned int DelayMs;//设定延时时间
    unsigned char State;
    unsigned int StartMs;//内部实用 初次设置时间
    unsigned int EndMs;  //内部实用 延时结束时间
} DelayTypedef;


#define T0_RUN(State) (TR0=State)
#define T1_RUN(State) (TR1=State)
#define T0_Flag(State) (TF0=State)
#define T1_Flag(State) (TF1=State)
#define T0_EnIT(State)  (ET0=State)
#define T1_EnIT(State)  (ET1=State)
//定时器初始化函数 Reload 重载频率 频率范围约(100~100000)
void TimeInit(unsigned int Reload);
//阻塞延时函数
void DelayNonBlocking(DelayTypedef* DelayStruct);
//非阻塞延时函数
void DelayBlocking(unsigned int Time);
//阻塞软延时
void Delay10us();
void T1Delayus(unsigned int time);
#endif