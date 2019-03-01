/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC15F4K60S4 系列 AD转换查询方式举例----------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966-------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.GXWMCU.com --------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序        */
/* 如果要在文章中应用此代码,请在文章中注明使用了STC的资料及程序        */
/*---------------------------------------------------------------------*/

//本示例在Keil开发环境下请选择Intel的8058芯片型号进行编译
//若无特别说明,工作频率一般为11.0592MHz


#include "reg51.h"
#include "intrins.h"

#define FOSC    11059200L
#define BAUD    9600

typedef unsigned char BYTE;
typedef unsigned int WORD;

#define     URMD    0           //0:使用定时器2作为波特率发生器
//1:使用定时器1的模式0(16位自动重载模式)作为波特率发生器
//2:使用定时器1的模式2(8位自动重载模式)作为波特率发生器

sfr T2H   = 0xd6;               //定时器2高8位
sfr T2L   = 0xd7;               //定时器2低8位

sfr P1M1 = 0x91;    //PxM1.n,PxM0.n     =00--->Standard,    01--->push-pull
sfr P1M0 = 0x92;    //                  =10--->pure input,  11--->open drain
sfr P0M1 = 0x93;
sfr P0M0 = 0x94;
sfr P2M1 = 0x95;
sfr P2M0 = 0x96;
sfr P3M1 = 0xB1;
sfr P3M0 = 0xB2;
sfr P4M1 = 0xB3;
sfr P4M0 = 0xB4;
sfr P5M1 = 0xC9;
sfr P5M0 = 0xCA;
sfr P6M1 = 0xCB;
sfr P6M0 = 0xCC;
sfr P7M1 = 0xE1;
sfr P7M0 = 0xE2;

sfr  AUXR       =   0x8e;       //辅助寄存器

sfr ADC_CONTR   =   0xBC;           //ADC控制寄存器
sfr ADC_RES     =   0xBD;           //ADC高8位结果
sfr ADC_LOW2    =   0xBE;           //ADC低2位结果
sfr P1ASF       =   0x9D;           //P1口第2功能控制寄存器

#define ADC_POWER   0x80            //ADC电源控制位
#define ADC_FLAG    0x10            //ADC完成标志
#define ADC_START   0x08            //ADC起始控制位
#define ADC_SPEEDLL 0x00            //540个时钟
#define ADC_SPEEDL  0x20            //360个时钟
#define ADC_SPEEDH  0x40            //180个时钟
#define ADC_SPEEDHH 0x60            //90个时钟

void InitUart();
void InitADC();
void SendData(BYTE dat);
BYTE GetADCResult(BYTE ch);
void Delay(WORD n);
void ShowResult(BYTE ch);

void main()
{
	P0M0 = 0x00;
	P0M1 = 0x00;
	P1M0 = 0x00;
	P1M1 = 0x00;
	P2M0 = 0x00;
	P2M1 = 0x00;
	P3M0 = 0x00;
	P3M1 = 0x00;
	P4M0 = 0x00;
	P4M1 = 0x00;
	P5M0 = 0x00;
	P5M1 = 0x00;
	P6M0 = 0x00;
	P6M1 = 0x00;
	P7M0 = 0x00;
	P7M1 = 0x00;

	InitUart();                     //初始化串口
	InitADC();                      //初始化ADC
	while (1)
	{
		ShowResult(0);              //显示通道0
		ShowResult(1);              //显示通道1
		ShowResult(2);              //显示通道2
		ShowResult(3);              //显示通道3
		ShowResult(4);              //显示通道4
		ShowResult(5);              //显示通道5
		ShowResult(6);              //显示通道6
		ShowResult(7);              //显示通道7
	}
}

/*----------------------------
发送ADC结果到PC
----------------------------*/
void ShowResult(BYTE ch)
{
	SendData(ch);                   //显示通道号
	SendData(GetADCResult(ch));     //显示ADC高8位结果

//    SendData(ADC_LOW2);           //显示低2位结果
}

/*----------------------------
读取ADC结果
----------------------------*/
BYTE GetADCResult(BYTE ch)
{
	ADC_CONTR = ADC_POWER | ADC_SPEEDLL | ch | ADC_START;
	_nop_();                        //等待4个NOP
	_nop_();
	_nop_();
	_nop_();
	while (!(ADC_CONTR & ADC_FLAG));//等待ADC转换完成
	ADC_CONTR &= ~ADC_FLAG;         //Close ADC

	return ADC_RES;                 //返回ADC结果
}

/*----------------------------
初始化串口
----------------------------*/
void InitUart()
{
	SCON = 0x5a;                //设置串口为8位可变波特率
#if URMD == 0
	T2L = 0xd8;                 //设置波特率重装值
	T2H = 0xff;                 //115200 bps(65536-18432000/4/115200)
	AUXR = 0x14;                //T2为1T模式, 并启动定时器2
	AUXR |= 0x01;               //选择定时器2为串口1的波特率发生器
#elif URMD == 1
	AUXR = 0x40;                //定时器1为1T模式
	TMOD = 0x00;                //定时器1为模式0(16位自动重载)
	TL1 = 0xd8;                 //设置波特率重装值
	TH1 = 0xff;                 //115200 bps(65536-18432000/4/115200)
	TR1 = 1;                    //定时器1开始启动
#else
	TMOD = 0x20;                //设置定时器1为8位自动重装载模式
	AUXR = 0x40;                //定时器1为1T模式
	TH1 = TL1 = 0xfb;           //115200 bps(256 - 18432000/32/115200)
	TR1 = 1;
#endif
}

/*----------------------------
初始化ADC
----------------------------*/
void InitADC()
{
	P1ASF = 0xff;                   //设置P1口为AD口
	ADC_RES = 0;                    //清除结果寄存器
	ADC_CONTR = ADC_POWER | ADC_SPEEDLL;
	Delay(2);                       //ADC上电并延时
}

/*----------------------------
发送串口数据
----------------------------*/
void SendData(BYTE dat)
{
	while (!TI);                    //等待前一个数据发送完成
	TI = 0;                         //清除发送标志
	SBUF = dat;                     //发送当前数据
}

/*----------------------------
软件延时
----------------------------*/
void Delay(WORD n)
{
	WORD x;

	while (n--)
	{
		x = 5000;
		while (x--);
	}
}

