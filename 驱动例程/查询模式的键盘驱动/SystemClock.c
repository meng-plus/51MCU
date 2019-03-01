// Header:  UART
// File Name: UART.c
// Author:  chengmengmegn
// Date:

#include "SystemClock.h"


unsigned int SysClock=0;
void Delayms(unsigned int time)//延时等待
{
	unsigned int timeNow=SysClock;
	while(time!=0)
	{
		if(timeNow!=SysClock)
		{
			timeNow=SysClock;
			time--;
		}
	}
}

void Delayus(void)   //Delay10us误差 -0.234375us 包含调用时间
{
	unsigned char i;

	_nop_();
	_nop_();
	_nop_();
	i = 24;
	while (--i);
}

void Delay10us(unsigned char time)
{
	while(time--)
	{
		Delayus();
	}
}
#ifdef Timer2
void InitTimer(void)//精度1ms
{
	RCAP2L = TL2 = T1MS;            //initial timer2 low byte
	RCAP2H = TH2 = T1MS >> 8;       //initial timer2 high byte
	TR2 = 1;                        //timer2 start running
	ET2 = 1;                        //enable timer2 interrupt
	EA = 1;                         //open global interrupt switch
}

void Timer2Interrupt(void) interrupt 5 using 1
{
	TF2 = 0;
	SysClock++;//每个1ms 加1 最大计数65536ms=65.536s
}
#else
void InitTimer(void)
{
#ifdef MODE1T
	AUXR = 0x80;                    //timer0 work in 1T mode
#endif
	TMOD = TMOD&0xf0 |0x01;      //set timer0 as mode1 (16-bit)
	TL0 = T1MS;                     //initial timer0 low byte
	TH0 = T1MS >> 8;                //initial timer0 high byte
	TR0 = 1;                        //timer0 start running
	ET0 = 1;                        //enable timer0 interrupt
	EA = 1;                         //open global interrupt switch

}
void tm0_isr() interrupt 1 using 1
{
	TL0 = T1MS;                     //reload timer0 low byte
	TH0 = T1MS >> 8;                //reload timer0 high byte
	SysClock++;//每个1ms 加1 最大计数65536ms=65.536s
}
#endif