#include "STC8G_USER.H"
#include "Uart1.h"
#include "TM4_STC8.h"
#include "Uart3_STC8G.H"
#include "MultiSystem_UART.h"
//#include "SelSignal.h"
char *pstr="Hello Uart3!\r\n";
      
void Delay100ms()		//@11.0592MHz
{
  unsigned char i, j, k;

  i = 6;
  j = 157;
  k = 59;
  do
  {
    do
    {
      while (--k);
    }
    while (--j);
  }
  while (--i);
}
DelayTypedef deltm;
char str[16];
char recFlag;
void main()
{
  Uart1Init();
  Uart3Init();
  MultiSysInit();
  Uart1SendStr(pstr);
  Uart3SendStr(pstr);
  deltm.DelayMs=3000;
  deltm.State=Tm4_Start;
  while(1)
  {
    recFlag=GetMultiSysFlag();
    if(recFlag==0x03)
    {
      char*iPtr,iDataLen;
      GetMultiDataPtr(&iPtr,&iDataLen);
      
      Uart3SendArray(iPtr,iDataLen);
      MultiStart();
    }
    if(str[15]!=recFlag)
    {
      str[15]=recFlag;
       sprintf(str,"flag0x%bx ",recFlag);
      Uart1SendStr(str); 
    }  
    
    DelayNonBlocking(&deltm);
     if(deltm.State== Tm4_Ok)
     {
      deltm.State=Tm4_Start;

       sprintf(str,"flag0x%bx \r\n",recFlag);
       Uart1SendStr(str);
     }
  }
}
