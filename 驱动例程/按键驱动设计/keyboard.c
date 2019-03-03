// Header:
// File Name:
// Author:chengmeng2018
// Date:2019年3月3日
// Version: 1.0

#include "Keyboard.h"

enum KeyState {keywait=0,keydelay,keycheck,KeyDown,keyWaitUp};
unsigned char GetKeyNumMatrixKeyboard();
unsigned char GetKeyNumIndependentButton();
//按键检测
unsigned char  keyScanf(unsigned char *Keynum)
{
	static unsigned char keyState=keywait;
	static unsigned char KeyLastTemp,LastTime;
	unsigned char KeyTemp=0;
	//检测按键
	KeyTemp = GetKeyNumIndependentButton();//读取独立按键
	//KeyTemp = GetKeyNumMatrixKeyboard();//读取矩阵键盘
	//KeyTemp==0 没有按键按下
	//KeyTemp!=0  有按键按下
	switch(keyState )
	{
	case keywait: //等待按键按下
		if (KeyTemp !=0)
		{
			keyState = keydelay;
			KeyLastTemp=KeyTemp;
			LastTime=GetTime();
		}
		break;
	case keydelay: //延时消抖
		if(LastTime+Time100ms<GetTime())
		{
			keyState = keycheck;
		}
		break;
	case keycheck://检查按键的一致性
		if( KeyLastTemp== KeyTemp)
		{
			keyState = KeyDown;
		}
		else
		{
			keyState = keywait;
		}
		break;
	case KeyDown://按键按下的状态
		keyState = keyWaitUp;
		break;
	case keyWaitUp://按键松手上升沿
		if( KeyLastTemp != KeyTemp)
		{
			keyState++;
		}

		break;
//case doublebutton: //再次检测到按键的按下 即双击事件

//break;
	default:
		keyState=keywait;
		KeyLastTemp=0x00;
		break;
	}
	*Keynum=KeyLastTemp;

	return keyState;
}
#define GPIO_KEY P1

unsigned char GetKeyNumMatrixKeyboard()
{
	unsigned char KeyValue;
//用来存放读取到的键值
	GPIO_KEY=0X0F;
// 			Delay10ms(1);
	switch(GPIO_KEY)
	{
	case(0X07):
		KeyValue=GPIO_KEY;
		break;
	case(0X0b):
		KeyValue=GPIO_KEY;
		break;
	case(0X0d):
		KeyValue=GPIO_KEY;
		break;
	case(0X0e):
		KeyValue=GPIO_KEY;
		break;
	case (0x0f):
		KeyValue=GPIO_KEY;
		break;
//				default:	KeyValue=17;	//检测出错回复17意思是把数码管全灭掉。
	}
	//测试行
	GPIO_KEY=0XF0;
//			Delay10ms(1);
	switch(GPIO_KEY)
	{
	case(0X70):
		KeyValue=GPIO_KEY+KeyValue;
		break;
	case(0Xb0):
		KeyValue=GPIO_KEY+KeyValue;
		break;
	case(0Xd0):
		KeyValue=GPIO_KEY+KeyValue;
		break;
	case(0Xe0):
		KeyValue=GPIO_KEY+KeyValue;
		break;
	case (0xf0):
		KeyValue=GPIO_KEY+KeyValue;
		break;
//				default:	KeyValue=17;
	}
	return ~KeyValue;
}

//独立按键模式 将每个按键状态拼接在一个寄存器里
unsigned char GetKeyNumIndependentButton()
{
	unsigned char KeyTemp=0;
	KeyTemp += (unsigned char)!key3;
	KeyTemp =  KeyTemp<<1;
	KeyTemp += (unsigned char)!key2;
	KeyTemp =  KeyTemp<<1;
	KeyTemp += (unsigned char)!key1;
	KeyTemp =  KeyTemp<<1;
	KeyTemp += (unsigned char)!key0;

	return KeyTemp;
}

