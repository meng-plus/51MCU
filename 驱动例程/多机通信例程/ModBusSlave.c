
#include "ModBusSlave.h"
#include "Uart3_STC8G.H"
//与接收缓存区对应
#define BUFF_LEN 0x20
typedef enum enumFunCode
{
  //功能码
  Enum_BroadCast = 0x00,
  //bit
  Enum_ROStat = 0x01,/*读输出量状态*/
  Enum_RIDis = 0x02,/*读输入离散量*/
  Enum_WSOut = 0x05,/*写单个输出量*/
  Enum_WMOut = 0x0F,/*写多个输出量*/
  //byte
  Enum_RIReg = 0x04,/*读输入寄存器*/
  Enum_ROReg = 0x03,/*读输出寄存器*/
  Enum_WSReg = 0x06,/*写单个寄存器*/
  Enum_WMReg = 0x10,/*写多个寄存器*/
  //Enum_RWReg = 0x17,/*读 / 写寄存器*/
  Enum_MWReg = 0x16,/*屏蔽写寄存器*/
  //Other
  Enum_GCECout = 0x0B,/*获取通信事件计数*/
} FunCode;


typedef struct _MODBUS_ROREG
{
  char iDevID;
  char iCmd;
  uint16_t iAddr;
  uint16_t iNum;
  uint8_t  CrcL;
  uint8_t  CrcH;
} *LpRoReg;
typedef struct _MODBUS_ROREG_RES
{
  char iDevID;
  char iCmd;
  uint8_t iByteNum;
  uint16_t RegData[(BUFF_LEN-3)/2];
//  uint8_t  CrcL;
//  uint8_t  CrcH;
} *LpRoRegRes;

char ReadHoldRegs(LpRoReg lpData);
void ModBusAnalysis(CModBus* lpmodbus)
{
  char iRec;
  switch(lpmodbus->iCmd[1])
  {
  case Enum_ROReg://在一个或多个保持寄存器中取得当前的二进制值
    iRec=ReadHoldRegs((LpRoReg)lpmodbus->iCmd);
    break;
  case Enum_WSReg:
    break;
  }
}
	//RTU模式
	//【地址】【功能码】【数据量】【数据1】【…】【数据n】【CRC低字节】【CRC高字节】
	uint16_t RTU_CalcCrc(const uint8_t *chData,uint8_t uNo)/*数据长度*/
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
//开关	U39	0x03,0x06	0x0000
//周期	U39	0x03,0x06	0x0001
//脉宽	U39	0x03,0x06	0x0007
//10选1	U39	0x03,0x06	0x000D

char ReadHoldRegs(LpRoReg lpData)
{//多字节数据读取 测试代码  测试通过
  char tab[BUFF_LEN],ilen;
  LpRoRegRes response=tab;
  char irec=0,i;
  uint16_t iCurAddr;
  char* lpTmp8u;
  response->iDevID=lpData->iDevID;
  response->iCmd=lpData->iCmd;
  response->iByteNum=0;
  for(i=0; i<lpData->iNum; i++)
  {
    iCurAddr=lpData->iAddr+i;
    if(iCurAddr==0x0000)
    {
     response->RegData[i]=i;
    }
    else if(iCurAddr<0x0007)
    {
    response->RegData[i]=i;
    }
    else if(iCurAddr<0x000D)
    {
     response->RegData[i]=i;
    }
    else if(iCurAddr==0x000D)
    {
     response->RegData[i]=i;
    }
    else
    {
      irec=0x04;
    }
  }
  response->iByteNum=i;//装载数据长度
  //response->RegData[i]=0;
  ilen=(char*)(&response->RegData[i])-(char*)response;//分析已用数据长度
  iCurAddr=RTU_CalcCrc((char*)response,ilen);//数据校验
  lpTmp8u=(char*)(&response->RegData[i]);//拿到装载crc的地址
  lpTmp8u[0]=iCurAddr&0xff;
  lpTmp8u[1]=(iCurAddr>>8)&0xff;
  ilen=ilen+2;//数据总长度
  Uart3SendArray((char*)response,ilen);
  Uart3Send(ilen);
  return irec;
}