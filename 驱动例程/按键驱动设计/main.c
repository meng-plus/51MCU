#include <REGX52.H>
#include <stdio.h>
#include "Keyboard.h"


void main()
{
    KeyStruct KeyNum;
    unsigned char KeyState;
    unsigned char str[32];
    while(1)
    {
        KeyState = key_scan(&KeyNum);//°´¼ü¼ì²â
        if(KeyState==KeyFallEdge)
        {
            sprintf(str,"KeyState:%d Keynum:%d \r\n ",(unsigned int)KeyState,(unsigned int)(KeyNum.Value));
        }
    }

}