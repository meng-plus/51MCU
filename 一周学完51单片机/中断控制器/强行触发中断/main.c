// Header: 
// File Name: 中断控制器-你不得不知道的内部外设
// Author: 蒙蒙plus
// Date: 2019年4月7日
//version: v1_0

#include <REGX52.H>

/**
  * @brief  非常规的中断触发方式理解 中断控制器 的真面目
  * @note  本程序没有实际应用价值，但是又很大的理解学习意义
  * @retval 
  */
void main()
{
//逐个测试中断信号
	IE=0x0ff;//打开所有中断
//	EX2 =1;
//	EX3 =1;
	//开始进行中断测试
	P3_2=0;
	P3_2=1;
	TF0=1;
	TF0=0;
	P3_3=0;
	P3_3=1;
	TF1=1;
	TF1=0;
	RI=1;
	RI=0;
	TI=1;
	TI=0;
	TF2=1;
	TF2=0;
//	EXTF2=1;
//	EXTF2=0;
//	IE2=1;
//	IE2=0;
//	IE3=1;
//	IE3=0;
	while(1);
}

void Int0_Routline(void) interrupt 0
{
	P1_1=!P1_1;
}
void Time0_Routline(void) interrupt 1
{
	P1_1=!P1_1;
}
void Int1_Routline(void) interrupt 2
{
	P1_1=!P1_1;
}
void Time1_Routline(void) interrupt 3
{
	P1_1=!P1_1;
}
void UART0_Routline(void) interrupt 4
{
	P1_1=!P1_1;
}
void Time2_Routline(void) interrupt 5
{
	P1_1=!P1_1;
}
void Int2_Routline(void) interrupt 6
{
	P1_1=!P1_1;
}
void Int3_Routline(void) interrupt 7
{
	P1_1=!P1_1;
}