#ifndef  __MULTISYSTEM_UART_H_
#define  __MULTISYSTEM_UART_H_

#include "afx.h"
#include "TM4_STC8.h"
#define BUFF_LEN 0x10
typedef struct MultiSys
{
    char iWorkFlag;
    ClockTypedef tm;
    char wptr;
//  char rptr;
    unsigned char buffer[BUFF_LEN];
} MultiSysStruct;
extern MultiSysStruct afxMultiSysData;
void MultiSysInit();
void UartCallBackRx(char nRx);
char GetMultiSysFlag();
void GetMultiDataPtr(char** nPtr,char *nLen);
void MultiStart();

#endif