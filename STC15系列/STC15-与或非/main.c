#include <STC15F2K60S2.H>
#include <stdio.h>

char str1[32];
sbit P04 = P0^4;//不是异或操作
//P04 =1; 正确  bool型操作
//P0^4 =1; 错误 异或操作
void main()
{
//	P1M1 P1口的M1位的集合xxx0 x1xxB
//	P1M0 P1口的M0位的集合xxx1 x1xxB 
//		P1.4 推挽
//    P1.2 开漏
//引脚配置方式
	//配置P1.4
	//xxxx xxxxB
	//1110 1111B
	//xxx0 xxxxB
	//P1M1 &~(1<<4)-》P1M1 & ~0x10-》=P1M1 & 0xEF
	P1M1 =P1M1 &~(1<<4);//与操作清零使用
	P1M0 =P1M0 &~(1<<4);
	
	P1M1 =P1M1 |(0<<4);//或操作置一使用
	P1M0 =P1M0 |(1<<4);//==P1M0 |0x10;只修改指定位
	//P1.2 开漏
	P1M1 =P1M1 |(1<<2);
	P1M0 =P1M0 |(1<<2);

//位操作的时候 先清零 再置位	
//可读性第一 执行效率才是第二
    while(1);

}