// Header:舵机控制程序
// File Name:
// Author:程蒙蒙（QQ1058515967）
// Date:2018年9月12日
//Description：基于12T系列单片机且有T2定时器的单片机舵机控制程序
//，本程序控制精度高（1us），定时器自动控制舵机转动
/*------------------------------
硬件需求： 12T系列单片机（8051内核）
					 拥有T2定时器
					 12M时钟晶振
					 P2_0输出控制
					 舵机角度范围在0~180 高电平范围0.5ms~2.5ms 20ms周期
--------------------------------*/

#include <REGX52.H>

#define T2_PWMout P2_0  //舵机控制端
unsigned int PWMTimes=0;//高电平时间
unsigned char angle=0; //测试角度
void T2_Init();//初始化定时器2
void SetMotoangle(float angle);//设置舵机角度
void Delay100ms();		//@12.000MHz
void main()
{
    bit SWdir=0;
    T2_Init();//初始化定时器
    while(1)//演示程序，舵机左右摆动
    {
        if(angle>180)SWdir=0;
        else if(angle==0)SWdir=1;

        SetMotoangle(SWdir?angle++:angle--);
        Delay100ms();
    }
}

void T2_Init()
{
    unsigned int time=65536-20000;
    RCAP2L = TL2 = time;            //initial timer2 low byte
    RCAP2H = TH2 = time >> 8;       //initial timer2 high byte
    TR2 = 1;                        //timer2 start running
    ET2 = 1;                        //enable timer2 interrupt
    EA = 1;                         //open global interrupt switch
}
void SetMotoangle(float angle)
{
    //防止越界而损伤电机
    if(angle > 175) angle = 175;
    if(angle <5) angle = 5;

    PWMTimes=500+angle*2000.0/180;//计算出高电平时间


}
/* Timer2 interrupt routine */
void tm2_isr() interrupt 5 using 1
{
    static  bit SW=0;
    unsigned int T2count;
    TF2 = 0;//标志位清零
    SW=~SW;//状态取反
    T2_PWMout=SW;//更新输出
    if(SW)//低电平时间
    {
        T2count=0xB1E0+PWMTimes;//0xB1E0即为20ms中断用时
        RCAP2L=T2count;
        RCAP2H=T2count>>8;
    }
    else//高电平时间
    {
        T2count=0-PWMTimes;
        RCAP2L=T2count;
        RCAP2H=T2count>>8;
    }

}
void Delay100ms()		//@12.000MHz
{
    unsigned char i, j;

    i = 195;
    j = 138;
    do
    {
        while (--j);
    }
    while (--i);
}

