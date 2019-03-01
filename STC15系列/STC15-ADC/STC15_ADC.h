// Header: STC15_ADC
// File Name: 
// Author:	chengmeng2018
// Date: 2019年3月1日
#ifndef __STC15_ADC_H_
#define __STC15_ADC_H_


#define ADC_POWER     0x80
#define ADC_SPEEDMASK 0x60
#define ADC_SPEED90   0x60
#define ADC_SPEED180  0x40
#define ADC_SPEED360  0x20
#define ADC_SPEED540  0x00
#define ADC_FLAG      0x10
#define ADC_START     0x08   

//ADC初始化函数
void ADCInit(unsigned char ADC_Pins);
void ADCDeInit();
unsigned int ADCRead(unsigned char ADC_CHS);
void ADCSetSpeed(unsigned char  ADC_SPEED);

/////////////////////////////////////////////////

#endif
