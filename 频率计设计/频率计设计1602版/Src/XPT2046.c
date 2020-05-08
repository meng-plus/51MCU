
//---包含头文件---//
#include<reg51.h>
#include<intrins.h>
#include"XPT2046.h"


	//	temp = Read_AD_Data(0x94);		//   AIN0 电位器
	//	temp = Read_AD_Data(0xD4);		//   AIN1 热敏电阻
	//	temp = Read_AD_Data(0xA4);		//   AIN2 光敏电阻
	//	temp = Read_AD_Data(0xE4);		//   AIN3 外部输入
/****************************************************************************
*函数名：TSPI_Start
*输  入：无
*输  出：无
*功  能：初始化触摸SPI
****************************************************************************/

void SPI_Start(void)
{
	CLK = 0;
	CS  = 1;
	DIN = 1;
	CLK = 1;
	CS  = 0;		
}
/****************************************************************************
*函数名：SPI_Write
*输  入：dat：写入数据
*输  出：无
*功  能：使用SPI写入数据
****************************************************************************/

void SPI_Write(uchar dat)
{
	uchar i;
	CLK = 0;
	for(i=0; i<8; i++)
	{
		DIN = dat >> 7;  	//放置最高位
		dat <<= 1;
		CLK = 0;			//上升沿放置数据

		CLK = 1;

	}
}
/****************************************************************************
*函数名：SPI_Read
*输  入：无
*输  出：dat：读取 到的数据
*功  能：使用SPI读取数据
****************************************************************************/

uint SPI_Read(void)
{
	uint i, dat=0;
	CLK = 0;
	for(i=0; i<12; i++)		//接收12位数据
	{
		dat <<= 1;

		CLK = 1;
		CLK = 0;

		dat |= DOUT;

	}
	return dat;	
}

/****************************************************************************
*函数名：Read_AD_Data
*输  入：cmd：读取的X或者Y
*输  出：endValue：最终信号处理后返回的值
*功  能：读取触摸数据
****************************************************************************/
uint Read_AD_Data(uchar cmd)
{
	uchar i;
	uint AD_Value;
	CLK = 0;
	CS  = 0;
	SPI_Write(cmd);
	for(i=6; i>0; i--); 	//延时等待转换结果
	CLK = 1;	  //发送一个时钟周期，清除BUSY
	_nop_();
	_nop_();
	CLK = 0;
	_nop_();
	_nop_();
	AD_Value=SPI_Read();
	CS = 1;
	return AD_Value;	
}
uint GetMaxADCVal()
{
	unsigned int SVal,SValOld;
	char i=0;
	SVal=SValOld=Read_AD_Data(0xE4);
	//度过下降区间
  while(SVal<=SValOld)
  {
		SValOld=SVal;
    SVal=Read_AD_Data(0xE4);
  }	
	//寻找最高点
  while(SVal>=SValOld)
  {
    SValOld=SVal;
    SVal=Read_AD_Data(0xE4);
  }
	//返回最大值
return SValOld;
}
