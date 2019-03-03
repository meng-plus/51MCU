#include <REGX52.H>
#include <stdio.h>
#include "Keyboard.h"


void main()
{
	unsigned char KeyState,Keynum;
	unsigned char str[32];
	Timer0Init();
	while(1)
	{
		KeyState = keyScanf(&Keynum);//°´¼ü¼ì²â
		sprintf(str,"KeyState:%d Keynum:%d \r\n ",(unsigned int)KeyState,(unsigned int)Keynum);
	}

}