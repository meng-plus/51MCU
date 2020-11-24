#ifndef __TM4_8_H_
#define __TM4_8_H_

typedef struct
{//最大计时18H
    int MS;//rang[0,1000]
    int S; //rang[0,0x8000]
} ClockTypedef;
extern ClockTypedef Clock_Tm4;
typedef enum _DelayState {Tm4_Start,Tm4_Stop,Tm4_Wait,Tm4_Ok} DelayState;
//定时器延时函数
typedef struct
{
    unsigned int DelayMs;//设定延时时间
    DelayState 		State;
    unsigned int StartMs;//内部实用 初次设置时间
    unsigned int EndMs;  //内部实用 延时结束时间
} DelayTypedef;


void TM4_Init();
void GetCurrentTime(ClockTypedef* time);
int SubTime(ClockTypedef* time);
int SubTimeTi(ClockTypedef* time);
//非阻塞延时函数
void DelayNonBlocking(DelayTypedef* DelayStruct);
//阻塞延时函数
void DelayBlocking(unsigned int Time);
#endif