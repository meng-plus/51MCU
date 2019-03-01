#include <REG52.H>
#include <stdio.h>
#include "KeyBoard.h"
#include "UART.h"
#include "SystemClock.h"

char KeyNum ;

void main(void)
{
	unsigned char state=0;
	InitUART();//初始化串口用于调试
	InitTimer();//初始化系统时钟用于延时
	SendString("Open UART Successful\n");
	while(1)
	{
		Delayms(1);
		state|=KeyResults(&KeyNum)<<4;
		if((state&0x0f)!=(state>>4))
		//state=KeyResults(&KeyNum);
		//if(state==3)
		{
			state=state>>4;
			Delay10us(1);
			//sprintf(str,"\r\nreturnASCII: %c  \n ",Key2ASCII(KeyNum));
			sprintf(str,"\r\nreturn: %02x KeyNum:%02x \r\n ",(unsigned int )state,( int )KeyNum);
			SendString(str);
		}

	}


}