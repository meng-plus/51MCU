#ifndef __UART3_STC8G_H_
#define __UART3_STC8G_H_


 
//extern char Uart3_wptr;
//extern char Uart3_rptr;
//extern unsigned char  Uart3_buffer[16];
void Uart3Init();
void Uart3Send(char dat);
void Uart3SendStr(char *p);
void Uart3SendArray(char *p,char len);
/*多机通信专用操作*/
//void Uart3Sendaddr(char val);
//void Uart3SendData(char val);
#endif