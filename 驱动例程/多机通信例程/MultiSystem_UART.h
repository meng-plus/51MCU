#ifndef  __MULTISYSTEM_UART_H_
#define  __MULTISYSTEM_UART_H_

#include "afx.h"
#include "TM4_STC8.h"

void MultiSysInit();
void UartCallBackRx(char nRx);
char GetMultiSysFlag();
void GetMultiDataPtr(char** nPtr,char *nLen);
void MultiStart();

#endif