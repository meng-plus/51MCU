
#include "STC8G_USER.H"
#include "PWM_STC8G.h"
#include "SGM3002.h"
//0 2 4   PWM的PWM分成两组 寄存器不一样 然后分开定义
//code PWMEvenTypedef PWMEventPort[3]= {&PWM0C,&PWM2C,&PWM4C};
//1 3 5
//code PWMOddTypedef PWMOddPort[3]= {&PWM1C,&PWM3C,&PWM5C};
code PWMMiniTypedef PwmMiniPort[]= {&PWM5C,&PWM1C,&PWM0C,&PWM4C};
//这里是我的项目需求用到这些引脚并且是这个顺序
code PWMPinTypedef PWMPin[]= {&PWM52T1H,&PWM12T1H,&PWM03T1H,&PWM46T1H};
#define  PWMPORTLEN (sizeof(PwmMiniPort)/sizeof(PwmMiniPort[0]))
#define  PWMPINLEN (sizeof(PWMPin)/sizeof(PWMPin[0]))

void PWMPinInit();
void PWMInit()
{
  char i;
  P1M1 &=~0x04;
  P1M0 &=~0x04;
  P5M1 &=~0x04;
  P5M0 &=~0x04;
  P0M1 &=~0x08;
  P0M0 &=~0x08;
  P4M1 &=~0x40;
  P4M0 &=~0x40;


  /*work mode*/
  PWMSET=0x3F;//需要先使能PWM模块 否则设置无效 全局统一使用PWMCFG01中PWM0的配置
  P_SW2 |= 0x80;//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写
  for(i=0; i<PWMPORTLEN; i++)
  {
    PwmMiniPort[i]->C=999;
    PwmMiniPort[i]->CKS=11;
  }
  PWMCFG01 =0x11;//开始计数
  PWMCFG23 =0x11;
  PWMCFG45 =0x11;

  P_SW2 &= ~0x80;
  PWMPinInit();
  SG3002Init();//模拟开关初始化配置
}
void PWMPinInit()
{
  char i;
  //16 PWM10
  //17 PWM52
  //18 PWM04
  //19 PWM46
  //22 PWM37
  //23 PWM27

  /*设置周期1k*/
  for(i=0; i<PWMPINLEN; i++)
  {
    PWMSetT1(i,499);
    PWMSetT2(i,0);
    PWMSetHLD(i,0x01);
    PWMSetCR(i,0x80);
  }
}

char PWMSetC(uint8_t  id ,uint16_t nVal)
{
  //8 PWM04
  //9 PWM46
  //10 PWM27
  //11 PWM37
  //20 PWM52
  //21 PWM10
  char irec=0;
  if(id<PWMPORTLEN)
  {
    if((nVal&0x8000)==0)
    {
      P_SW2 |= 0x80;
      PwmMiniPort[id]->C=nVal;
      P_SW2 &= ~0x80;
    }
    else
    {
      irec= 0x04;
    }
  }
  else
  {
    irec= 0x02;
  }
  return irec;
}
uint16_t GetPWMC(uint8_t  id)
{
  uint16_t  nVal;
  if(id<PWMPORTLEN)
  {
    P_SW2 |= 0x80;
    nVal=PwmMiniPort[id]->C;
    P_SW2 &= ~0x80;
    return nVal;
  }
  else
  {
    return -1;
  }
}
char PWMSetT1(uint8_t id ,uint16_t nVal)
{
  char irec=0;
  P_SW2 |= 0x80;
  if(id<PWMPINLEN)
  {
    PWMPin[id]->T1=nVal;
  }
  else
  {
    irec= 2;
  }
  P_SW2 &= ~0x80;
  return irec;
}
uint16_t GetPWMT1(uint8_t  id)
{
  uint16_t  nVal;
  P_SW2 |= 0x80;
  if(id  <PWMPINLEN)
  {
    nVal= PWMPin[id]->T1;
  }
  else
  {
    nVal=-1;
  }
  return nVal;
}
char PWMSetT2(uint8_t id ,uint16_t nVal)
{
  char irec=0;
  P_SW2 |= 0x80;
  if(id<PWMPINLEN)
  {
    PWMPin[id]->T2=nVal;
  }
  else
  {
    irec= 2;
  }
  P_SW2 &= ~0x80;
  return irec;
}
uint16_t GetPWMT2(uint8_t  id)
{
  uint16_t  nVal;
  P_SW2 |= 0x80;
  if(id  <PWMPINLEN)
  {
    nVal= PWMPin[id]->T2;
  }
  else
  {
    nVal=-1;
  }
  return nVal;

}
char PWMSetCR(uint8_t id ,uint8_t nVal)
{
  char irec=0;

  if(nVal&0x7F)
  {
    irec= 0x04;
  }
  else
  {
    P_SW2 |= 0x80;
    if(id<PWMPINLEN)
    {
      PWMPin[id]->CR=nVal;
    }
    else
    {
      irec= 2;
    }
    P_SW2 &= ~0x80;
  }

  return irec;
}
char PWMSetHLD(uint8_t id ,uint8_t nVal)
{
  char irec=0;
  if((nVal&~0x03)!=0 ||nVal==0x03)
  {
    return 0x04;
  }
  else
  {
    P_SW2 |= 0x80;
    if(id<PWMPINLEN)
    {
      PWMPin[id]->HLD=nVal;
    }
    else
    {
      irec= 2;
    }
    P_SW2 &= ~0x80;
  }
  return irec;
}

char PWMSetHLDS(uint16_t nVal)
{
  //数据是12位拼接

  if((nVal&0xf000)==0)
  {
    char i,iVal;
    P_SW2 |= 0x80;
    for(i=0; i<PWMPINLEN; i++)
    {
      iVal=nVal&0x03;
      nVal=nVal>>2;
      //iVal=PWMSetHLD(i,iVal);
      PWMPin[i]->HLD=iVal;
    }
    P_SW2 &= ~0x80;
    return 0x00;
  }
  return 0x04;
}
uint16_t PWMGetHLDS()
{
  uint16_t nVal=0x0000;
  char i,iVal;
  P_SW2 |= 0x80;
  for(i=0; i<PWMPINLEN; i++)
  {
    iVal= PWMPin[i]->HLD;
    nVal=  nVal  | ((iVal&(0x03))<<2*i);
  }
  P_SW2 &= ~0x80;
  return nVal;
}