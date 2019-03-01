// Header: STC15_ADC
// File Name:
// Author:	chengmeng2018
// Date: 2019年3月1日

#include "STC15_ADC.h"

#include "STC15F2K60S2.H"
/**
  * @brief  ADC引脚初始化函数
  * @note 	传入参数作为开启引脚参数
  * @retval NULL
  */
void ADCInit(unsigned char ADC_Pins)
{
	//P1 引脚设为复用功能后才能读取ADC
	P1ASF =ADC_Pins;
	ADC_CONTR =ADC_POWER|ADC_SPEED540;
	ADC_CONTR &=~ADC_FLAG;//清除转换完成标志位
	CLK_DIV &=~0x20;//设定数据格式
	//delay();可能这里需要点延时
}
/**
  * @brief  复位关闭ADC模块
  * @note 	清理初始化配置还原默认状态
  * @retval NULL
  */
void ADCDeInit()
{
	ADC_CONTR=0x00;
	P1ASF=0x00;
}
/**
  * @brief  读取AC数据
  * @note 	ADC_CHS数值范围在0~7;
  * @retval 
  */
unsigned int ADCRead(unsigned char ADC_CHS)
{
	unsigned int ADC_VAL=3;
	ADC_RES=0;//数据位清零
	ADC_RESL=0;
	ADC_CONTR =ADC_POWER |(ADC_CHS&0x07) |ADC_START;//通电 选择通道 开始转换
	while(ADC_VAL--);//简单等一会
	while(ADC_CONTR&ADC_FLAG ==0);//等待转换完成
	ADC_VAL=(ADC_RES<<2) |(ADC_RESL&0x03);//10位数据拼接保存
	return ADC_VAL;
}
/**
  * @brief  修改ADC模块速度配置
  * @note   一般在初始化之后不再修改
	* ADC_SPEED速度范围仅在下面几个选择 
	*             ADC_SPEED90 
	*             ADC_SPEED180
	*             ADC_SPEED360
  *             ADC_SPEED540
	* @retval NULL
  */
void ADCSetSpeed(unsigned char  ADC_SPEED)
{

	ADC_CONTR &= ~ADC_SPEEDMASK;//清除speed位
	ADC_CONTR |=(ADC_SPEED & ADC_SPEEDMASK);     //设置工作速度
}