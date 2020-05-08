
#include <REGX52.H>
#include "keyBoard.h"


void delay2ms(void)   //ÑÓÊ±º¯Êý
{
    unsigned char i,j;
    for(i=133; i>0; i--)
        for(j=6; j>0; j--);
}
sbit Key0=P1^0;
sbit Key1=P1^1;
sbit Key2=P1^2;
unsigned char IndependentKeyboard()
{
    unsigned char keyValue=0;
    keyValue |=!Key0;
    keyValue<<=1; 
    keyValue |=!Key1;
    keyValue<<=1;
    keyValue|=!Key2;
    return keyValue;
}
//°´¼ü¼ì²â
unsigned char key_scan(KeyStruct* KeyNum)
{
    unsigned char keyValue=0;
    unsigned char State=KeyNum->State;
    unsigned char KeyTemp=KeyNum->Value;
    /*******¾ØÕó¼üÅÌ¶ÁÈ¡²Ù×÷******/
    keyValue =	IndependentKeyboard();//¶ÀÁ¢°´¼ü¼ì²â
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
