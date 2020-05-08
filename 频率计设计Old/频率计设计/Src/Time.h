// Header: 8051内核单片机通用定时器T0 T1头文件
// File Name: Time.h
// Author: 蒙蒙plus
// Date: 2019年4月6日
// Version: V1.0

#ifndef  __TIME_H_
#define  __TIME_H_

typedef struct 
{
  unsigned int ms;
  unsigned int us;
} TimeVal;
#define T0_RUN(State) (TR0=State)
#define T1_RUN(State) (TR1=State)
#define T0_ClearFlag(State) (TF0=State)
#define T1_ClearFlag(State) (TF1=State)
#define T0_EnIT(State)  (ET0=State)
#define T1_EnIT(State)  (ET1=State)
//定时器初始化函数 Reload 重载频率 频率范围约(100~100000)
void TimeInit();

//获取当前时间;
unsigned int GetTime();
/*下面功能与上面功能冲突只能单独使用*/
void StartTime();
void EndTime(TimeVal* val);

#endif