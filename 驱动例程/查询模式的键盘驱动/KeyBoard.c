// Header:        KeyBoard.h
// File Name:    KeyBoard Drivers
// Author:          chengmengmeng
// Date:             2018-4-16
#include "KeyBoard.h"
#include "SystemClock.h"
#include "UART.h"

void KeyValueJudgment(unsigned char *KeyT, unsigned char *KeyDataNow)
{
	KeyT[1] |= (1<<KeyT[0]);
	while(KeyT[1]&0x01)//判断最低位是否为0 (即被按下)
	{
		KeyT[1]>>=1;//仍掉最后一位
		(*KeyDataNow)++;
	}
	(*KeyDataNow)|=(KeyT[0]<<4);//坐标拼接高4位表示行 第四位为列
}
//返回按键是否弹起，输入按键地址存储区
//
// return  0:NULL  1:Down 3: UP
unsigned char KeyResults(char *KeyIndex)
{
	unsigned char KeyT[2];//[0]保存地位 [1]保存高位
	char KeyOutput;//传入Key的数据临时存储
	static char KeyDataNow=0;//当前按键数据
	static char State=0;//按键状态机跳转
	static char KeyDelayTime;
	if(State!=1)
	{
		for(KeyT[0]=0; KeyT[0]<6; KeyT[0]++)
		{
			KeyOutput=~(1<<KeyT[0])&0x1f;//只操控低5位
			KeyInput=KeyInput &0xE0 | KeyOutput;
			Delay10us(1);//让电平稳定
			KeyT[1]=KeyInput&0x1f;
			if(KeyT[1] != KeyOutput)  //检测到按键
			{
				if(State==0)State=1;
				KeyDataNow=0;
				KeyValueJudgment(KeyT,&KeyDataNow);
			}
		}
	}
	
	//State machine jump
	switch(State)
	{
	//case 0: //无按键操作
    //
	//	break;
	case 1://初次按下
		KeyDelayTime=SysClock/256;
		*KeyIndex=KeyDataNow;//最新按键状态保存
		KeyDataNow=~KeyDataNow;//清除暂存键值
		State=2;
		break;
	case 2: //延时消抖
		if(SysClock/256 != KeyDelayTime)//消抖256ms
		{
			State=3;
		}
		break;
	case 3://判断按键是否一致
		if(KeyDataNow==*KeyIndex)
		{
			KeyDataNow=~KeyDataNow;//清除暂存键值
			State=4;
			return 1;
		}
		else
		{
			State=0;
		}
		break;
	case 4://等待抬起
		if(KeyDataNow==*KeyIndex)
		{
			KeyDataNow=~KeyDataNow;//清除暂存键值
			return 1;
		}
		else
		{
			State=0;
			return 3;
		}
		break;
	default:
		break;
	}
	return 0;
}
//将按键数值转换为自定义的ASCII码值

char  Key2ASCII(char KeyNum)
{
	switch(KeyNum)
	{
	case 0x01:
		return '+';
	case 0x02:
		return '>';//右移
	case 0x03:
		return '<';//左移
	case 0x04:
		return 'P';//power
	case 0x10:
		return 127;//del
	case 0x12:
		return '9';
	case 0x13:
		return '8';
	case 0x14:
		return '7';
	case 0x20:
		return 27;//esc=clear
	case 0x21:
		return '-';
	case 0x23:
		return '5';
	case 0x24:
		return '4';
	case 0x25:
		return '%';
	//	case 0x30:
	//	return ' ';
	case 0x31:
		return '*';
	case 0x32:
		return '6';
	case 0x34:
		return '1';
	case 0x35:
		return '(';
	//case 0x40:
	//	return ')';
	case 0x41:
		return '/';
	case 0x42:
		return '3';
	case 0x43:
		return '2';
	//case 0x50:
	//	return '/';
	//case 0x51:
	//	return '';
	case 0x52:
		return '=';
	case 0x53:
		return '0';
	case 0x54:
		return '.';
	default:
		break;
	}
	return 0xff;
}