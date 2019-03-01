/*--------------------------------------------------------------------------
KeyBoard.h
	Matrix Keyboard Drivers, Designed for 5x5 Matrix 5IO Circuit Drivers.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef __SYSTEMCLOCK_H__
#define __SYSTEMCLOCK_H__

#include <REG52.H>

/* define constants */
#define FOSC 11059200L

#define T1MS (65536-FOSC/12/1000)   //1ms timer calculation method in 12T mode
#define Timer0
extern unsigned int SysClock;//最大计数65536ms=65.536s
void InitTimer(void);//定时器初始化
void Delayms(unsigned int time);//延时等待
void Delay10us(unsigned char time); 

#endif
