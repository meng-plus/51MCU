// Header:"Uart1.h"
// File Name: Uart1
// Author: cmm
// Date:20200821
// Description:  Uart0为下载端口 提供代码debug日志
#include "STC8G_USER.H"
//#include "intrins.h"


#include "MultiSystem_UART.h"
char Uart1_wptr;
char Uart1_rptr;
char Uart1_buffer[16];
bit Uart1_busy = 0;
void Uart1Init()
{
    /*Uart1工作模式配置*/
    SCON = 0x50;
    //    SM2=0;//允许多机通信控制位
    //    SM1=1;//模式1 可变8位
    //    SM0=0;
    //    REN=1;//允许接收
    //    TI=0;//清空标志位
    //    RI=0;
    //波特率设置
    T2L = 0xe6;                                 //65536-11059200/115200/4=0FFE8H
    T2H = 0xff;
    AUXR = 0x15;                                //启动定时器
    /*中断*/
    ES = 1;                                     //使能串口中断
    EA = 1;
}
void Uart1Send(char dat)
{

    while (Uart1_busy);
    Uart1_busy = 1;
    SBUF = dat;

}
void Uart1SendStr(const char* str)
{

    char strTmp = 0;

    if (str != 0)
    {
        strTmp = *str;
    }
    while (strTmp != 0)
    {
        Uart1Send(strTmp);
        str++;
        strTmp = *str;
    }
}
void UART1_Isr() interrupt 4
{
    if (TI)
    {
        TI = 0;                                 //清中断标志
        Uart1_busy = 0;

    }
    if (RI)
    {
        Uart1_buffer[Uart1_wptr++] = SBUF;
        Uart1_wptr &= 0x0f;
        RI = 0;                                 //清中断标志
    }
}
