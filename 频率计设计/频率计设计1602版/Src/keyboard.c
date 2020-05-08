
#include <REGX52.H>
#include "keyBoard.h"


void delay2ms(void)   //延时函数
{
    unsigned char i,j;
    for(i=133; i>0; i--)
        for(j=6; j>0; j--);
}

sbit Key1=P3^1;
//sbit Key2=P1^2;
unsigned char IndependentKeyboard()
{
    unsigned char keyValue=0;
    keyValue=!Key1;
   // keyValue<<=1;
    //keyValue|=!Key2;
    return keyValue;
}
//按键检测
unsigned char key_scan(KeyStruct* KeyNum)
{
    unsigned char keyValue=0;
    unsigned char State=KeyNum->State;
    unsigned char KeyTemp=KeyNum->Value;
    /*******矩阵键盘读取操作******/
    keyValue =	IndependentKeyboard();//独立按键检测
//  keyValue==0表示没有按键按下
    /*******矩阵键盘读取操作***
    	keyValue=GetMatrixKeyboard()
        keyValue==17表示没有按键按下
    如果变更键盘注意修改 CheckKey分支判断条件
    *************************/
    switch(State)
    {
    case CheckKey:
        if(keyValue !=0)
        {
            KeyTemp=keyValue;
            State=DelayKey;
        }
        break;
    case DelayKey:
        delay2ms();
        State= KeyTemp==keyValue ? KeyFallEdge:CheckKey;
        break;
    case KeyFallEdge:
        State=KeyDown;
        break;
    case KeyDown:
        if(KeyTemp != keyValue)
        {
            State=KeyRisEdge;
            KeyNum->lastValue= KeyTemp;
        }
        break;
    case KeyRisEdge:
        State=CheckKey;
        break;
    default:
        break;
    }
    KeyNum->State=State;
    KeyNum->Value=keyValue;
    return State;
}
