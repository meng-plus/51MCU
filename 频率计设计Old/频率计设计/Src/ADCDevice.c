#include <REGX52.H>
#include "ADCDevice.h"

void Delay100us(); //@12.000MHz
void ADCInit()
{
  ADCDP = 0XFF; //ADC数据接收脚
  CS = 1;       //ADC控制引脚为产生起始时序，初始化给高电平
  ADC_RD = 1;       //ADC控制引脚为产生起始时序，初始化给高电平
  NTR = 1;      //ADC控制引脚为产生起始时序，初始化给高电平
}
void ADCEnd()
{

  ADC_RD = 1;   //将ADC通讯引脚重新初始化到高电平状态
  CS = 1;     //将ADC通讯引脚重新初始化到高电平状态
  NTR = 1; //将ADC通讯引脚重新初始化到高电平状态
  ADC_WR = 1;     //将ADC通讯引脚重新初始化到高电平状态
  Delay100us();
}
unsigned char ReadAdc()
{
	unsigned char ADCVal;
//  LE = 1;
  CS = 0;
  Delay100us();
  ADC_WR = 0;
  Delay100us();

  //等待ADC转换结束
  while (NTR == 0); 
  CS = 0;
  Delay100us();
  ADC_RD = 0;
  Delay100us();
//  LE = 0;
  ADCVal = ADCDP; //对ADC转换结果进行取值
  ADCEnd();
  return ADCVal;
}
void Delay100us() //@12.000MHz
{
  unsigned char i;
  i = 47;
  while (--i);
}
unsigned char  GetMaxADCVal()
{
	unsigned char SVal,SValOld;
	char i=0;
	SVal=SValOld=ReadAdc();
	//度过下降区间
  while(SVal<=SValOld)
  {
		SValOld=SVal;
    SVal=ReadAdc();
  }	
	//寻找最高点
  while(SVal>=SValOld)
  {
    SValOld=SVal;
    SVal=ReadAdc();
  }
	//返回最大值
return SValOld;
}