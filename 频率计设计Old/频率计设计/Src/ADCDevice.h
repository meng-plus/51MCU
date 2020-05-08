#ifndef __ADCDEVICE_H_
#define __ADCDEVICE_H_


#define ADCDP P1
sbit CS=P2^0;                  //ADC模块通讯信号CS
sbit ADC_RD=P2^1;                  //ADC模块通讯信号ADC_RD
sbit NTR=P2^3;          //ADC模块通讯信号INT
//sbit LE=P2^4;                  //ADC模块输入锁存器控制
sbit ADC_WR=P2^2;          //ADC模块通讯信号ADC_WR


void ADCInit();
unsigned char ReadAdc();
unsigned char  GetMaxADCVal();
#endif