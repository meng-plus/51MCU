#include <STC15F2K60S2.H>

void GPIOInit();
void main()
{
	GPIOInit();
	//XXXInit();
	while(1)
	{
	
	}
	
}	
void GPIOInit()
{
	//P1口8个LED 高电平点亮 推挽 增加输出能力
	P1M1 =0x00;
	P1M0 =0xff;
	//P2口8个LED 低电平点亮 开漏 增加输入能力
	P2M1 =0xff;
	P2M0 =0xff;
	//P3口8个LED 4高电平点亮 4低电平 
	P3M1 =0x0f;
	P3M0 =0xff;
}