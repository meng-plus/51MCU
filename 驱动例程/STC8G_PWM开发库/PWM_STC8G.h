#ifndef  __PWM_STC8G_H_
#define  __PWM_STC8G_H_
#include "afx.h"

/*PWM0 2 4 */
typedef struct _PWMEVENSTRUCT
{
	unsigned  int  volatile  C;
	unsigned  char  volatile  CKS;
    unsigned  int  volatile  TADC;
	unsigned  char  volatile  IF;
	unsigned  char  volatile  FDCR;	
}*PWMEvenTypedef;
/*PWM1 3 5 */
typedef struct _PWMODDSTRUCT
{
	unsigned  int  volatile  C;
	unsigned  char  volatile  CKS;
	unsigned  char  volatile  IF;
	unsigned  char  volatile  FDCR;
}*PWMOddTypedef;
/*PWM0~5 MINI*/
typedef struct _PWMMINISTRUCT
{
	unsigned  int  volatile  C;
	unsigned  char  volatile  CKS;
}*PWMMiniTypedef;

typedef struct _PWMPINSTRUCT
{
	unsigned  int  volatile  T1;
	unsigned  int  volatile  T2;
    unsigned  char  volatile  CR;
	unsigned  char  volatile  HLD;
}*PWMPinTypedef;

void PWMInit();
char PWMSetC(uint8_t  id ,uint16_t nVal);
char PWMSetT1(uint8_t  id ,uint16_t nVal);
char PWMSetT2(uint8_t  id ,uint16_t nVal);
char PWMSetCR(uint8_t  id ,char nVal);
char PWMSetHLD(uint8_t  id ,char nVal);

char PWMSetHLDS(uint16_t nVal);
uint16_t PWMGetHLDS();//获取开关
//void  SetPWM_ON(unsigned int ON);//设定开关
uint16_t GetPWMC(uint8_t  id);//获取周期
uint16_t GetPWMT1(uint8_t  id);//获取低电平时间点
uint16_t GetPWMT2(uint8_t  id);//获取高电平时间点

#endif