
#include "MultiSystem_UART.h"
#include "Uart1.h"
#include "TM4_STC8.h"
#include <STRING.H>
#include "STC8G_USER.H"

MultiSysStruct afxMultiSysData;
void addData(char nRx);
void clearData();
char GetMultiSysFlag()
{
  int i16ms;
  if(afxMultiSysData.iWorkFlag==0x01)
  {
         i16ms=SubTime(&afxMultiSysData.tm);
        if(i16ms>FRAME_TIME)
        {
           afxMultiSysData.iWorkFlag=0x02;
          S3CON |= S3RI;
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
    afxMultiSysData.wptr=(afxMultiSysData.wptr+1)%(BUFF_LEN-1);
}
void clearData()
{
    memset(&afxMultiSysData,0,sizeof(afxMultiSysData));
}
//RTU模式
//【地址】【功能码】【数据量】【数据1】【…】【数据n】【CRC低字节】【CRC高字节】
static uint16_t RTU_CalcCrc(const uint8_t *chData,uint8_t uNo)/*数据长度*/
{
    uint16_t crc = 0xffff;
    uint16_t i, j;
    for (i = 0; i < uNo; i++)
    {
        crc ^= chData[i];
        for (j = 0; j < 8; j++)
        {
            if (crc & 1)
            {
                crc >>= 1;
                crc ^= 0xA001;
            }
            else
                crc >>= 1;
        }
    }
    return (crc);
}
char AnalysisData()
{
    uint8_t* pCmd = afxMultiSysData.buffer;
    uint8_t len =afxMultiSysData.wptr;
    uint16_t crc = RTU_CalcCrc(pCmd, len - 2);
    uint8_t crcl = pCmd[len - 2];//crc低位
    uint8_t crch = pCmd[len - 1];//crc高位
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
    case 0x02://Analysis data
        if(AnalysisData())
        {
            afxMultiSysData.iWorkFlag=0x03;
        }
        else
        {
          clearData();
        }
        break;
    case 0x03:// Waiting for processing

        break;
    default:
        clearData();
        break;
    }

}