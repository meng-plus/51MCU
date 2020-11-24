
#include "MultiSystem_UART.h"
#include "Uart1.h"
#include "TM4_STC8.h"
#include <STRING.H>
#include "STC8G_USER.H"
#include "ModBusSlave.h"
#define BUFF_LEN 0x20
typedef struct MultiSys
{
  char iWorkFlag;
  ClockTypedef tm;
  char wptr;
//  char rptr;
  unsigned char buffer[BUFF_LEN];
} MultiSysStruct;
MultiSysStruct afxMultiSysData;
void addData(char nRx);
void clearData();
char AnalysisData();
char GetMultiSysFlag()
{
  int i16ms;
  if(afxMultiSysData.iWorkFlag==0x01)
  {
    i16ms=SubTime(&afxMultiSysData.tm);
    if(i16ms>FRAME_TIME)
    {
      if(AnalysisData())
      {
        afxMultiSysData.iWorkFlag=0x02;
      }
      else
      {
        clearData();
      }
    }

   }
  return afxMultiSysData.iWorkFlag;
}
void GetMultiDataPtr(char** nPtr,char *nLen)
{
  *nPtr= afxMultiSysData.buffer;
  *nLen=afxMultiSysData.wptr;
}
void MultiStart()
{
  clearData();
}
void addData(char nRx)
{
  afxMultiSysData.buffer[afxMultiSysData.wptr]=nRx;
  afxMultiSysData.wptr=(afxMultiSysData.wptr+1)%(BUFF_LEN);
}
void clearData()
{
  memset(&afxMultiSysData,0,sizeof(afxMultiSysData));
}

char AnalysisData()
{
  uint8_t* pCmd = afxMultiSysData.buffer;
  uint8_t len =afxMultiSysData.wptr;
  uint16_t crc = RTU_CalcCrc(pCmd, len - 2);
  uint8_t crcl = pCmd[len - 2];//crcµÍÎ»
  uint8_t crch = pCmd[len - 1];//crc¸ßÎ»
  if ((crc & 0xff) == crcl &&
      ((crc >> 8) & 0xFF) == crch)
  {
    return 1;
  }
  return 0;
}

void MultiSysInit()
{
  clearData();
  TM4_Init();
}
void UartCallBackRx(char nRx)
{
  int i16ms;
  switch(afxMultiSysData.iWorkFlag)
  {
  case 0x00://wait DevID
    if(nRx==MCU_ID)
    {
      addData(nRx);
      afxMultiSysData.iWorkFlag=0x01;
      GetCurrentTime(&afxMultiSysData.tm);
    }
    break;
  case 0x01://Rec Data
    i16ms=SubTimeTi(&afxMultiSysData.tm);
    if(i16ms>FRAME_TIME)
    {
      afxMultiSysData.iWorkFlag=0x02;
    }
    else if(i16ms>-1)
    {
      addData(nRx);
      GetCurrentTime(&afxMultiSysData.tm);
    }
    else
    {
      clearData();
    }
    break;
  case 0x02:// Waiting for processing

    break;
  default:
    clearData();
    break;
  }
}
