#include <REGX51.H>

/*Define input and output ports*/
#define LED P2  //
#define GPIO_KEY P1

#define Time100ms 10
#define Time1s 100

/*Defining global variables*/
unsigned int T10ms=0;
unsigned char LEDPWM=0;  //占空比
unsigned char LEDPWMH=20;
unsigned char LEDPWML=0;
unsigned char LEDIndex=0;//灯地址
    unsigned int PWMcycle=500;
    unsigned int LastTime;

/*Declare internal functions*/
void Timer0Init(); //Initialize Time0 as the system clock
void delay10ms(unsigned int times);//10ms unit delay 10*times
unsigned int GetTime();
void PWMTime1Init();
char KeyScanf(char *Keynum);//按键检测
unsigned char  addLEDPWM();
unsigned char  delLEDPWM();
void main()
{
    /*Defining local variables*/
    unsigned char Keynum;
    unsigned char State;
    unsigned char PWMChangeState=0;

    /*Defining local variables*/
    PWMTime1Init();//PWM Freq=100
    Timer0Init();//InitTime 10ms
    while(1)
    {
        if(4 == KeyScanf(&Keynum))
        {
            State=Keynum;
        }
        switch(State)
        {
        case 0x01:
            LEDPWMH = LEDPWMH<20 ? LEDPWMH+1 : 20;
            break;
        case 0x02:
            LEDPWMH = LEDPWMH>LEDPWML ? LEDPWMH-1 :LEDPWML;
            break;
        case 0x03:
            LEDPWML = LEDPWML<LEDPWMH ? LEDPWML+1 : LEDPWMH;
            break;
        case 0x04:
            LEDPWML = LEDPWML>0 ? LEDPWMH-1 :0;
            break;
        case 0x05:
            PWMcycle = PWMcycle<400 ? 500 :PWMcycle+100;
            break;
        case 0x06:
            PWMcycle = PWMcycle<200 ? 200 :PWMcycle-100;
            break;
        default:
            break;
        }
        if ( (PWMcycle/2/(LEDPWMH-LEDPWML))-1<GetTime()-LastTime)
        {
            LastTime = GetTime();
            switch(PWMChangeState)
            {
            case 0:
                PWMChangeState=addLEDPWM() ? PWMChangeState :1;
                break;
            case 1:
                PWMChangeState=delLEDPWM() ? PWMChangeState :0;
                   if(PWMChangeState==0) 
                        LEDIndex=(LEDIndex+1)%8;
                break;
            default:
                break;

            }
        }
    }

}
unsigned char  addLEDPWM()
{
    LEDPWM= LEDPWM<LEDPWMH ?LEDPWM+1 : LEDPWMH;
    return LEDPWM<LEDPWMH;
}

unsigned char  delLEDPWM()
{
    LEDPWM= LEDPWM>LEDPWML ?LEDPWM-1 : LEDPWML;
    return LEDPWM>LEDPWML;
}
/****************************
//Function Name:  delay10ms
//Input : times
//Output: void
//Description: //10ms unit delay
//   delay time = 10*times
//***************************/
void delay10ms(unsigned int times)
{
    unsigned int LastTime=GetTime();
    while(times)
    {
        if (LastTime != GetTime())
        {
            LastTime = GetTime();
            times--;
        }
    }
}
/****************************
//Function Name:  GetTime
//Input : void
//Output: current time T10ms
//Description:
//
//***************************/
unsigned int GetTime()
{
    return T10ms;
}



//--------------------
//函数名 KeyScanf
//传入*Keynum 按键键值存储指针
//返回: 按键状态 具体看下面
//-------------------
char KeyScanf(char *Keynum)//按键检测
{
    //局部静态变量
    static State=0,KeynumLastTemp;
    static unsigned int TimeLast;//保存按下时间
    char KeyTemp;
    //按键检测部分
			//测试列
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyTemp=0;break;
				case(0X0b):	KeyTemp=4;break;
				case(0X0d): KeyTemp=8;break;
				case(0X0e):	KeyTemp=12;break;
			}
			//测试行
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyTemp=KeyTemp+3;break;
				case(0Xb0):	KeyTemp=KeyTemp+2;break;
				case(0Xd0): KeyTemp=KeyTemp+1;break;
				case(0Xe0):	KeyTemp=KeyTemp;break;
			}
    //状态机写法返回按键状态
    switch(State)
    {
    case 0://等待按键按下
        State =      !KeyTemp;
        KeynumLastTemp = KeyTemp;
        TimeLast = GetTime();
        break;
    case 1://度过延时消抖
        State += (GetTime()-TimeLast)>Time100ms;
        break;
    case 2://再次判断按键是否一致
        State =(KeynumLastTemp == KeyTemp) ? State + 1 : 0;
        break;
    case 3://等待松手
        State =(KeynumLastTemp == KeyTemp) ? State : State+1;
        break;
    default:
        State=0;
        break;
    }
    *Keynum=KeyTemp;
    return State;
}

/****************************
//Function Name:Timer0Init()
//Input : void
//Output: void
//Description:Timer0Init()
//***************************/
void Timer0Init()		//Timer0Init()
{
    TMOD &= 0xF0;		//Set timer mode
    TMOD |= 0x01;
    TL0 = 0x0F0;		//Set the initial value of the timing
    TH0 = 0x0D8;		//Set the initial value of the timing
    TF0 = 0;		//Clear TF0 flag
    TR0 = 1;		//Timer 0 starts timing
    ET0 = 1;        //Open Interrupt0
    EA  = 1;        //Open total interruption
}

/****************************
//Function Name:  PWMTime1Init()
//Input : void
//Output: void
//Description: Creat PWMFreq=100
//***************************/
void PWMTime1Init()//1ms
{
    TMOD &= 0x0F;		//Set timer mode
    TMOD |= 0x10;
    TH1 = 0x0FE; //0.5ms
    TL1 = 0x0C;

//    TL1 = 0x0FC;		//Set the initial value of the timing
//    TH1 = 0x018;		//Set the initial value of the timing
    TF1 = 0;		//Clear TF1 flag
    TR1 = 1;		//Timer 1 starts timing
    ET1 = 1;        //Open Interrupt3
    EA  = 1;        //Open total interruption
}

/****************************
//Function Name: Timer0Interrupt
//Input : void
//Output: void
//Description:
//***************************/
void Timer0Interrupt(void) interrupt 1
{
    //Overload 10ms timer
    TH0 = 0x0D8;
    TL0 = 0x0F0;

    /*Cumulative timing*/
    T10ms++;
}

/****************************
//Function Name: Timer0Interrupt
//Input : void
//Output: void
//Description: Generate PWMFreq= 100
//***************************/
void Timer1Interrupt(void) interrupt 3
{
    static unsigned char  Time500us=0;
    //Overload 500us timer
    TH1 = 0x0FE; //0.5ms
    TL1 = 0x0C;
    //add your code here!
    Time500us=(Time500us+1)%20;
    if (LEDPWM > Time500us)
        LED=0x01<<LEDIndex;//LEDIndex==(0~7);
    else
        LED=0x00;
}