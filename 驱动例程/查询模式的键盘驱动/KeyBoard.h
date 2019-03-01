/*--------------------------------------------------------------------------
KeyBoard.h
	Matrix Keyboard Drivers, Designed for 5x5 Matrix 5IO Circuit Drivers.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <REG52.H>

#define KeyInput P1 //

//返回按键是否弹起，输入按键地址存储区
//
// return  0:NULL  1:Down 3: UP
unsigned char KeyResults(char *KeyIndex);

//将按键数值转换为自定义的ASCII码值
char  Key2ASCII(char KeyNum);
#endif

