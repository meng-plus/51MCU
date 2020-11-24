
#include "STC8G_USER.H"
#include "Uart3_STC8G.H"
#include "MultiSystem_UART.h"
bit Uart3_busy;
//char Uart3_wptr;
//char Uart3_rptr;
//unsigned char  Uart3_buffer[16];

sbit RxD3_2= P5^0;
sbit TxD3_2= P5^1;
void Uart3Init()
{
  /*Pin Config*/
//  P5M0 &=~(0x01);//RxD 高阻输入无法接收
//  P5M1 &=~(0x01);
//  P5M0 &=~(0x02);//开漏输出
//  P5M1 &=~(0x02);//
  P5M0 &=~0x03;
  P5M1 &=~0x03;
  P5PU |= 0x03;
//  RxD3_2=1;
//  TxD3_2=1;
  P_SW2 |=0x02;//切换ES3引脚
  /*与串口1公用定时器2作为波特率发生器*/
//	    //波特率设置#define BRT   (65536 - FOSC / 115200 / 4)
//    T2L = 0xe6;    //65536-11059200/115200/4=0FFE8H
//    T2H = 0xff;
//    AUXR = 0x15;                                //启动定时器
  S3CON=S3REN;//(~S3SM0)|(~S3ST3)|(~S3SM2)
  IE2 |=ES3;//启动串口中断
//  Uart3_wptr = 0x00;
//  Uart3_rptr = 0x00;
  Uart3_busy = 0;
}
/*多机通信专用操作*/
void Uart3Sendaddr(char val)
{
  S3CON |= S3TB8;
  Uart3Send(val);
}
void Uart3SendData(char val)
{
  S3CON &= ~S3TB8;
  Uart3Send(val);
}

void Uart3Isr() interrupt 17
{
  char TmpSBUF;
  TmpSBUF=S3BUF;
  if (S3CON & S3TI)
  {
    S3CON &= ~S3TI;
    Uart3_busy = 0;
  }
  if (S3CON & S3RI)
  {
    S3CON &= ~S3RI;
    UartCallBackRx(TmpSBUF);
//	Uart3_buffer[Uart3_wptr++] = TmpSBUF;
//	Uart3_wptr &= 0x0f;
//    TmpSBUF=S3BUF;
//    if(S3CON&S3RB8)
//    {
//      if(TmpSBUF ==	35)
//      {
//        S3CON &=~S3SM2;
//        Uart3_wptr=Uart3_rptr=0;
//        Uart3_buffer[Uart3_wptr++] = TmpSBUF;
//      }
//      else
//      {
//        S3CON |= S3SM2;
//      }
//    }
//    else
//    {
//      Uart3_buffer[Uart3_wptr++] = TmpSBUF;
//      Uart3_wptr &= 0x0f;
//    }

  }
}
void Uart3Send(char dat)
{
  while (Uart3_busy);
  Uart3_busy = 1;
  S3BUF = dat;
}
void Uart3SendArray(char *p,char len)
{
  char i;
  for(i=0; i<len; i++)
  {
    Uart3Send(p[i]);
  }
}

void Uart3SendStr(char *p)
{
  while (*p)
  {
    Uart3Send(*p++);
  }
}
