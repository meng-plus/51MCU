
#ifndef __KEYBOARD_H__
#define __KEYBOARD_H__

#include <REGX52.H>

#include "systemclock.h"
sbit key0=P1^0;
sbit key1=P1^1;
sbit key2=P1^2;
sbit key3=P1^3;



unsigned char keyScanf(unsigned char *Keynum);//°´¼ü¼ì²â


#endif
