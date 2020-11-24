#ifndef  __MODBUSSLAVE_H_
#define  __MODBUSSLAVE_H_
#include "afx.h"
typedef struct _MODBUS
{
  char* iCmd;
  char iLen;
}CModBus;
uint16_t RTU_CalcCrc(const uint8_t *chData,uint8_t uNo);
void ModBusAnalysis(CModBus* lpmodbus);
#endif