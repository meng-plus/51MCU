#ifndef __LCD1602_H_
#define	__LCD1602_H_


#define LCD1602_DB  P0      //data bus 数据总线

sbit LCD1602_RS = P2^6;
sbit LCD1602_RW = P2^5;
sbit LCD1602_EN = P2^7;	 

void InitLcd1602();
void LcdShowStr(unsigned char x,unsigned char y,unsigned char *str);


#endif //_LCD1602_H_