#ifndef  __SELSIGNAL_H_
#define  __SELSIGNAL_H_


void SelSignalInit();//信号选择器配置
//SelIDs 高低四位分别拆开 
//高位使能器件 低位选择IO
char GetSiganl1_10();
void SetSignal1_10(char SelID);
//char GetSiganl4_20();
//void SetSignal4_20(char SelIDs);
#endif