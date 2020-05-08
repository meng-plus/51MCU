/********时钟程序********/
/*功能描述*/
//6位数码管显示时分秒
/*******硬件配置*********/
//AT89C52 12M晶振



#include <REGX52.H>
//段选
#define smg_data    P0//定义数码管数据口

//数码管位选
//sbit    dis_bit1 = P2 ^ 5; //定义数码管控制口
//sbit    dis_bit2 = P2 ^ 4; //定义数码管控制口
//sbit    dis_bit3 = P2 ^ 3; //定义数码管控制口
//sbit    dis_bit4 = P2 ^ 2; //定义数码管控制口
//sbit    dis_bit5 = P2 ^ 1; //定义数码管控制口
//sbit    dis_bit6 = P2 ^ 0; //定义数码管控制口
#define smg_Pgs P2
//共阴数码管断码表
unsigned char code tabl1[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
                                0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
                               };

typedef struct
{
    unsigned char Value;
    unsigned char State;
    unsigned char lastValue;
} KeyStruct;
enum KeyState {CheckKey,DelayKey,KeyFallEdge,KeyDown,KeyRisEdge};

                            
typedef struct
{
  unsigned char hour;
  unsigned char min;
  unsigned char sec;
  unsigned char  SetFlag; 
} Time;
//初始化时间
Time DateTime = {12, 0, 0};
//全局心跳时钟 10ms
unsigned char systemTick = 0;
unsigned char DipBuff[6];
void time0Init();
void Display();
//按键检测
unsigned char key_scan(KeyStruct* KeyNum);
void Control (unsigned char keyValue);
void main()
{
  KeyStruct key_SetTime;
  //硬件初始化
  time0Init();

  while (1)
  {
    Display();
    if (key_scan (&key_SetTime) == KeyFallEdge)
    {
      Control (key_SetTime.Value);
    }
  }
}
void Control (unsigned char keyValue)
{
  switch (keyValue)
  {
  case 0x01://设置按键
    DateTime.SetFlag++;
    DateTime.SetFlag = DateTime.SetFlag% 4;
    break;

  case 0x02://数值减
    switch (DateTime.SetFlag)
    {
    case 1:
      DateTime.sec = DateTime.sec > 0 ? --DateTime.sec : 59;
      break;

    case 2:
      DateTime.min = DateTime.min > 0 ? --DateTime.min : 59;
      break;

    case 3:
      DateTime.hour = DateTime.hour > 0 ? --DateTime.hour : 23;
      break;
    }

    break;

  case 0x04:
    switch (DateTime.SetFlag)
    {
    case 1:
      DateTime.sec++;
      DateTime.sec = DateTime.sec % 60;
      break;

    case 2:
      DateTime.min++;
      DateTime.min = DateTime.min% 60;
      break;

    case 3:
      DateTime.hour++;
      DateTime.hour = DateTime.hour % 24;
      break;
    }

    break;
  }
}
void Display()
{
  char i, j;
  DipBuff[0] = tabl1[DateTime.hour / 10 % 10];
  DipBuff[1] = tabl1[DateTime.hour % 10]|((DateTime.SetFlag ==3)?0x80:0x00 );
  DipBuff[2] = tabl1[DateTime.min / 10 % 10];
  DipBuff[3] = tabl1[DateTime.min % 10]|((DateTime.SetFlag ==2)?0x80:0x00 );
  DipBuff[4] = tabl1[DateTime.sec / 10 % 10];
  DipBuff[5] = tabl1[DateTime.sec % 10]|((DateTime.SetFlag ==1)?0x80:0x00 );

  for (i = 0; i < 6; i++)
  {
    smg_data = 0xff;
    smg_Pgs = ~ (0x01 << i);
    smg_data = DipBuff[i];

    j = 100;
    while (j--);
    smg_Pgs = 0xff;
  }

}



void delay2ms(void)   //延时函数
{
    unsigned char i,j;
    for(i=133; i>0; i--)
        for(j=6; j>0; j--);
}
sbit Key0=P1^0;
sbit Key1=P1^1;
sbit Key2=P1^2;
unsigned char IndependentKeyboard()
{
    unsigned char keyValue=0;
    keyValue |=!Key0;
    keyValue<<=1; 
    keyValue |=!Key1;
    keyValue<<=1;
    keyValue|=!Key2;
    return keyValue;
}
//按键检测
unsigned char key_scan(KeyStruct* KeyNum)
{
    unsigned char keyValue=0;
    unsigned char State=KeyNum->State;
    unsigned char KeyTemp=KeyNum->Value;
    /*******矩阵键盘读取操作******/
    keyValue =	IndependentKeyboard();//独立按键检测
    switch(State)
    {
    case CheckKey:
        if(keyValue !=0)
        {
            KeyTemp=keyValue;
            State=DelayKey;
        }
        break;
    case DelayKey:
        delay2ms();
        State= KeyTemp==keyValue ? KeyFallEdge:CheckKey;
        break;
    case KeyFallEdge:
        State=KeyDown;
        break;
    case KeyDown:
        if(KeyTemp != keyValue)
        {
            State=KeyRisEdge;
            KeyNum->lastValue= KeyTemp;
        }
        break;
    case KeyRisEdge:
        State=CheckKey;
        break;
    default:
        break;
    }
    KeyNum->State=State;
    KeyNum->Value=keyValue;
    return State;
}

void time0Init()
{
  TR0 = 0; //关定时器
  TF0 = 0;
  TMOD = TMOD & 0xf0 | 0x01; //设定T0定时器工作模式1
  TH0 = (-10000) >> 8;
  TL0 = (-10000) & 0xff;
  ET0 = 1;  //开中断
  EA = 1; //开总中断
  TR0 = 1; //开定时器
}

void t0() interrupt 1
{
  //定时重载
  TH0 = (-10000) >> 8;
  TL0 = (-10000) & 0xff;
  systemTick++;

  if (systemTick > 99)
  {
    systemTick = 0;
    DateTime.sec++;

    if (DateTime.sec > 59)
    {
      DateTime.sec = 0;
      DateTime.min++;

      if (DateTime.min > 59)
      {
        DateTime.min = 0;
        DateTime.hour++;
      }
    }
  }
}