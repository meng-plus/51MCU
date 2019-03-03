#include <REGX52.H>

#define T2_PWMout P2_0  //PWM输出引脚
#define PWMcycle  20000
unsigned int PWMTimes=499;//高电平时间 20000us

void T2_Init();
void SetMotoangle(float angle);
void main()
{
    T2_Init();
SetMotoangle(180);
    while(1)
    {


    }

}
void SetMotoangle(float angle)
{
    //防止越界而损伤电机
    if(angle > 175) angle = 175;
    if(angle <5) angle = 5;

		PWMTimes=500+angle*2000.0/180;//计算出高电平时间
}
void T2_Init()
{
    // unsigned int time=65536-20000;
    CP_RL2=0;
    C_T2 =0;
    TF2=0;
    RCAP2L = TL2 = PWMTimes;            //initial timer2 low byte
    RCAP2H = TH2 = PWMTimes >> 8;       //initial timer2 high byte
    TR2 = 1;                        //timer2 start running
    ET2 = 1;                        //enable timer2 interrupt
    EA = 1;                         //open global interrupt switch
}
/*****PWM参数说明************/
// 0xB1E0 = 65536-PWM周期(20ms)
// PWMTimes 为高电平持续时间
/* Timer2 interrupt routine */
void tm2_isr() interrupt 5 using 1//PWM控制定时器程序
{
    T2_PWMout=~T2_PWMout;
    TF2 = 0;//标志位清零
    if(T2_PWMout)
    {
        RCAP2L=-(PWMcycle - PWMTimes);
        RCAP2H=-(PWMcycle - PWMTimes)>>8;
    }
    else
    {
        RCAP2L = (0-PWMTimes);
        RCAP2H = (0-PWMTimes) >> 8;
    }
}