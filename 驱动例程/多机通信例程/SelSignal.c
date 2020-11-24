
#include "STC8G_USER.H"
#include "SelSignal.h"
/*1/10Signal Pin*/
sbit SD=P1^3;
sbit SC=P1^4;
sbit SB=P1^5;
sbit SA=P1^6;

////0x80为悬空引脚
//char code Signal1_10[]= {0x01,0x00,0x08,0x07,0x04,
//                         0x0B,0x0D,0x0F,0x0C,0x0E,0x08
//                        };
//char mSelIDs;
///*4/20Signal Pin*/
//sbit S1=P1^4;
//sbit S2=P1^3;
//sbit S3=P1^2;
//sbit S4=P1^1;
//sbit D1A=P1^5;
//sbit D1B=P1^6;
//sbit D1C=P1^7;
////0x80为悬空引脚
//char code Signal4_20[]= {0x00,0x01,0x03,0x04,0x06};
char mSelID ;
char GetSiganl1_10()
{
  return  mSelID;
}
//char GetSiganl4_20()
//{
//  return mSelIDs;
//}
void SetSignal1_10(char SelID)
{
  if(SelID<11)
  {
    mSelID=SelID;
    SA=(SelID&0x01)!=0;
    SB=(SelID&0x02)!=0;
    SC=(SelID&0x04)!=0;
    SD=(SelID&0x08)!=0;
  }

//  if(SelID>sizeof(Signal1_10)-1)return ;
//  mSelID=SelID;
//  SelID=Signal1_10[SelID];
//  SA=(SelID&0x01)!=0;
//  SB=(SelID&0x02)!=0;
//  SC=(SelID&0x04)!=0;
//  SD=(SelID&0x08)!=0;
}

//SelIDs 高低四位分别拆开
//高位使能器件 低位选择IO
//void SetSignal4_20(char SelIDs)
//{
//  char Sel=SelIDs>>4;
//  D1A =(Sel&0x01)!=0;
//  D1B =(Sel&0x02)!=0;
//  D1C =(Sel&0x04)!=0;
//  if(SelIDs>sizeof(Signal4_20)-1)return ;
//  mSelIDs=SelIDs;
//  Sel =Signal4_20[SelIDs&0x0F];
//  S1=(Sel&0x01)!=0;
//  S2=(Sel&0x02)!=0;
//  S3=(Sel&0x04)!=0;
//}
void SelSignalInit()
{
  /*1/10Signal configure*/
  P1M1 &=~0x78;
  P1M0 |=0x78;
  SetSignal1_10(10);

  /*4/20 configure */
//  P1M1 &=~0xFE;
//  P1M0 |=0xFE;
//  SetSignal4_20(0xF0);

}