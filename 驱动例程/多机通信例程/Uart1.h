#ifndef __UART1_H_
#define __UART1_H_
#include <stdio.h>
extern char Uart1_wptr;
extern char Uart1_rptr;
extern char Uart1_buffer[16];

void Uart1Init();
void Uart1Send(char dat);
void Uart1SendStr(const char*);

#endif