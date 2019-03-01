#include "STC15F2K60S2.H"
#include "STC15_ADC.h"
void main()
{
	unsigned int ADC_value=0;
	ADCInit(0x01);//初始化ADC
	while(1)
	{
		ADC_value = ADCRead(0);//读取0通道引脚ADC数值
		P2 = ADC_value& 0x00ff;
	}
}

