#ifndef     __STC8G_USER_H_
#define     __STC8G_USER_H_

/////////////////////////////////////////////////

//包含本头文件后,不用另外再包含"REG51.H"

sfr         P0          =           0x80;
sbit        P00         =           P0^0;
sbit        P01         =           P0^1;
sbit        P02         =           P0^2;
sbit        P03         =           P0^3;
sbit        P04         =           P0^4;
sbit        P05         =           P0^5;
sbit        P06         =           P0^6;
sbit        P07         =           P0^7;
sfr         SP          =           0x81;
sfr         DPL         =           0x82;
sfr         DPH         =           0x83;
sfr         S4CON       =           0x84;
#define S4SM0       0x80
#define S4ST4       0x40
#define S4SM2       0x20
#define S4REN       0x10
#define S4TB8       0x08
#define S4RB8       0x04
#define S4TI        0x02
#define S4RI        0x01
sfr         S4BUF       =           0x85;
sfr         PCON        =           0x87;
#define SMOD        0x80
#define SMOD0       0x40
#define LVDF        0x20
#define POF         0x10
#define GF1         0x08
#define GF0         0x04
#define PD          0x02
#define IDL         0x01
sfr         TCON        =           0x88;
sbit        TF1         =           TCON^7;
sbit        TR1         =           TCON^6;
sbit        TF0         =           TCON^5;
sbit        TR0         =           TCON^4;
sbit        IE1         =           TCON^3;
sbit        IT1         =           TCON^2;
sbit        IE0         =           TCON^1;
sbit        IT0         =           TCON^0;
sfr         TMOD        =           0x89;
#define T1_GATE     0x80
#define T1_CT       0x40
#define T1_M1       0x20
#define T1_M0       0x10
#define T0_GATE     0x08
#define T0_CT       0x04
#define T0_M1       0x02
#define T0_M0       0x01
sfr         TL0         =           0x8A;
sfr         TL1         =           0x8B;
sfr         TH0         =           0x8C;
sfr         TH1         =           0x8D;
sfr         AUXR        =           0x8E;
#define T0x12       0x80
#define T1x12       0x40
#define UART_M0x6   0x20
#define T2R         0x10
#define T2_CT       0x08
#define T2x12       0x04
#define EXTRAM      0x02
#define S1ST2       0x01
sfr         INTCLKO     =           0x8F;
#define EX4         0x40
#define EX3         0x20
#define EX2         0x10
#define T2CLKO      0x04
#define T1CLKO      0x02
#define T0CLKO      0x01
sfr         P1          =           0x90;
sbit        P10         =           P1^0;
sbit        P11         =           P1^1;
sbit        P12         =           P1^2;
sbit        P13         =           P1^3;
sbit        P14         =           P1^4;
sbit        P15         =           P1^5;
sbit        P16         =           P1^6;
sbit        P17         =           P1^7;
sfr         P1M1        =           0x91;
sfr         P1M0        =           0x92;
sfr         P0M1        =           0x93;
sfr         P0M0        =           0x94;
sfr         P2M1        =           0x95;
sfr         P2M0        =           0x96;
sfr         SCON        =           0x98;
sbit        SM0         =           SCON^7;
sbit        SM1         =           SCON^6;
sbit        SM2         =           SCON^5;
sbit        REN         =           SCON^4;
sbit        TB8         =           SCON^3;
sbit        RB8         =           SCON^2;
sbit        TI          =           SCON^1;
sbit        RI          =           SCON^0;
sfr         SBUF        =           0x99;
sfr         S2CON       =           0x9A;
#define S2SM0       0x80
#define S2ST4       0x40
#define S2SM2       0x20
#define S2REN       0x10
#define S2TB8       0x08
#define S2RB8       0x04
#define S2TI        0x02
#define S2RI        0x01
sfr         S2BUF       =           0x9B;
sfr         IRCBAND     =           0x9D;
sfr         LIRTRIM     =           0x9E;
sfr         IRTRIM      =           0x9F;
sfr         P2          =           0xA0;
sbit        P20         =           P2^0;
sbit        P21         =           P2^1;
sbit        P22         =           P2^2;
sbit        P23         =           P2^3;
sbit        P24         =           P2^4;
sbit        P25         =           P2^5;
sbit        P26         =           P2^6;
sbit        P27         =           P2^7;
sfr         P_SW1       =           0xA2;
sfr         IE          =           0xA8;
sbit        EA          =           IE^7;
sbit        ELVD        =           IE^6;
sbit        EADC        =           IE^5;
sbit        ES          =           IE^4;
sbit        ET1         =           IE^3;
sbit        EX1         =           IE^2;
sbit        ET0         =           IE^1;
sbit        EX0         =           IE^0;
sfr         SADDR       =           0xA9;
sfr         WKTCL       =           0xAA;
sfr         WKTCH       =           0xAB;
#define WKTEN       0x80
sfr         S3CON       =           0xAC;
#define S3SM0       0x80
#define S3ST3       0x40
#define S3SM2       0x20
#define S3REN       0x10
#define S3TB8       0x08
#define S3RB8       0x04
#define S3TI        0x02
#define S3RI        0x01
sfr         S3BUF       =           0xAD;
sfr         TA          =           0xAE;
sfr         IE2         =           0xAF;
#define ET4         0x40
#define ET3         0x20
#define ES4         0x10
#define ES3         0x08
#define ET2         0x04
#define ESPI        0x02
#define ES2         0x01
sfr         P3          =           0xB0;
sbit        P30         =           P3^0;
sbit        P31         =           P3^1;
sbit        P32         =           P3^2;
sbit        P33         =           P3^3;
sbit        P34         =           P3^4;
sbit        P35         =           P3^5;
sbit        P36         =           P3^6;
sbit        P37         =           P3^7;
sfr         P3M1        =           0xB1;
sfr         P3M0        =           0xB2;
sfr         P4M1        =           0xB3;
sfr         P4M0        =           0xB4;
sfr         IP2         =           0xB5;
#define PI2C        0x40
#define PCMP        0x20
#define PX4         0x10
#define PPWMFD      0x08
#define PPWM        0x04
#define PSPI        0x02
#define PS2         0x01
sfr         IP2H        =           0xB6;
#define PI2CH       0x40
#define PCMPH       0x20
#define PX4H        0x10
#define PPWMFDH     0x08
#define PPWMH       0x04
#define PSPIH       0x02
#define PS2H        0x01
sfr         IPH         =           0xB7;
#define PPCAH       0x80
#define PLVDH       0x40
#define PADCH       0x20
#define PSH         0x10
#define PT1H        0x08
#define PX1H        0x04
#define PT0H        0x02
#define PX0H        0x01
sfr         IP          =           0xB8;
sbit        PPCA        =           IP^7;
sbit        PLVD        =           IP^6;
sbit        PADC        =           IP^5;
sbit        PS          =           IP^4;
sbit        PT1         =           IP^3;
sbit        PX1         =           IP^2;
sbit        PT0         =           IP^1;
sbit        PX0         =           IP^0;
sfr         SADEN       =           0xB9;
sfr         P_SW2       =           0xBA;
#define EAXFR       0x80
sfr         ADC_CONTR   =           0xBC;
#define ADC_POWER   0x80
#define ADC_START   0x40
#define ADC_FLAG    0x20
sfr         ADC_RES     =           0xBD;
sfr         ADC_RESL    =           0xBE;
sfr         P4          =           0xC0;
sbit        P40         =           P4^0;
sbit        P41         =           P4^1;
sbit        P42         =           P4^2;
sbit        P43         =           P4^3;
sbit        P44         =           P4^4;
sbit        P45         =           P4^5;
sbit        P46         =           P4^6;
sbit        P47         =           P4^7;
sfr         WDT_CONTR   =           0xC1;
#define WDT_FLAG    0x80
#define EN_WDT      0x20
#define CLR_WDT     0x10
#define IDL_WDT     0x08
sfr         IAP_DATA    =           0xC2;
sfr         IAP_ADDRH   =           0xC3;
sfr         IAP_ADDRL   =           0xC4;
sfr         IAP_CMD     =           0xC5;
#define IAP_IDL     0x00
#define IAP_READ    0x01
#define IAP_WRITE   0x02
#define IAP_ERASE   0x03
sfr         IAP_TRIG    =           0xC6;
sfr         IAP_CONTR   =           0xC7;
#define IAPEN       0x80
#define SWBS        0x40
#define SWRST       0x20
#define CMD_FAIL    0x10
sfr         P5          =           0xC8;
sbit        P50         =           P5^0;
sbit        P51         =           P5^1;
sbit        P52         =           P5^2;
sbit        P53         =           P5^3;
sbit        P54         =           P5^4;
sbit        P55         =           P5^5;
sbit        P56         =           P5^6;
sbit        P57         =           P5^7;
sfr         P5M1        =           0xC9;
sfr         P5M0        =           0xCA;
sfr         SPSTAT      =           0xCD;
#define SPIF        0x80
#define WCOL        0x40
sfr         SPCTL       =           0xCE;
#define SSIG        0x80
#define SPEN        0x40
#define DORD        0x20
#define MSTR        0x10
#define CPOL        0x08
#define CPHA        0x04
sfr         SPDAT       =           0xCF;
sfr         PSW         =           0xD0;
sbit        CY          =           PSW^7;
sbit        AC          =           PSW^6;
sbit        F0          =           PSW^5;
sbit        RS1         =           PSW^4;
sbit        RS0         =           PSW^3;
sbit        OV          =           PSW^2;
sbit        F1          =           PSW^1;
sbit        P           =           PSW^0;
sfr         T4T3M       =           0xD1;
#define T4R         0x80
#define T4_CT       0x40
#define T4x12       0x20
#define T4CLKO      0x10
#define T3R         0x08
#define T3_CT       0x04
#define T3x12       0x02
#define T3CLKO      0x01
sfr         T4H         =           0xD2;
sfr         T4L         =           0xD3;
sfr         T3H         =           0xD4;
sfr         T3L         =           0xD5;
sfr         T2H         =           0xD6;
sfr         T2L         =           0xD7;
sfr         CCON        =           0xD8;
sbit        CF          =           CCON^7;
sbit        CR          =           CCON^6;
sbit        CCF2        =           CCON^2;
sbit        CCF1        =           CCON^1;
sbit        CCF0        =           CCON^0;
sfr         CMOD        =           0xD9;
#define CIDL        0x80
#define ECF         0x01
sfr         CCAPM0      =           0xDA;
#define ECOM0       0x40
#define CCAPP0      0x20
#define CCAPN0      0x10
#define MAT0        0x08
#define TOG0        0x04
#define PWM0        0x02
#define ECCF0       0x01
sfr         CCAPM1      =           0xDB;
#define ECOM1       0x40
#define CCAPP1      0x20
#define CCAPN1      0x10
#define MAT1        0x08
#define TOG1        0x04
#define PWM1        0x02
#define ECCF1       0x01
sfr         CCAPM2      =           0xDC;
#define ECOM2       0x40
#define CCAPP2      0x20
#define CCAPN2      0x10
#define MAT2        0x08
#define TOG2        0x04
#define PWM2        0x02
#define ECCF2       0x01
sfr 		CCAPM3      =           0xdd;
#define ECOM3       0x40
#define CCAPP3      0x20
#define CCAPN3      0x10
#define MAT3        0x08
#define TOG3        0x04
#define PWM3        0x02
#define ECCF3       0x01
sfr         ADCCFG      =           0xDE;
#define ADC_RESFMT  0x20
sfr         IP3         =           0xDF;
sfr         ACC         =           0xE0;
sfr         DPS         =           0xE3;
sfr         DPL1        =           0xE4;
sfr         DPH1        =           0xE5;
sfr         CMPCR1      =           0xE6;
#define CMPEN       0x80
#define CMPIF       0x40
#define PIE         0x20
#define NIE         0x10
#define PIS         0x08
#define NIS         0x04
#define CMPOE       0x02
#define CMPRES      0x01
sfr         CMPCR2      =           0xE7;
#define INVCMPO     0x80
#define DISFLT      0x40
sfr         CL          =           0xE9;
sfr         CCAP0L      =           0xEA;
sfr         CCAP1L      =           0xEB;
sfr         CCAP2L      =           0xEC;
sfr         IP3H        =           0xEE;
sfr         AUXINTIF    =           0xEF;
#define INT4IF      0x40
#define INT3IF      0x20
#define INT2IF      0x10
#define T4IF        0x04
#define T3IF        0x02
#define T2IF        0x01
sfr         B           =           0xF0;
sfr         PWMSET      =           0xF1;
sfr         PCA_PWM0    =           0xF2;
sfr         PCA_PWM1    =           0xF3;
sfr         PCA_PWM2    =           0xF4;
sfr         IAP_TPS     =           0xF5;
sfr         PWMCFG01    =           0xF6;
sfr         PWMCFG23    =           0xF7;
sfr         CH          =           0xF9;
sfr         CCAP0H      =           0xFA;
sfr         CCAP1H      =           0xFB;
sfr         CCAP2H      =           0xFC;
sfr         PWMCFG45    =           0xFE;
sfr         RSTCFG      =           0xFF;

//如下特殊功能寄存器位于扩展RAM区域
//访问这些寄存器,需先将P_SW2的BIT7设置为1,才可正常读写

#define     CKSEL       (*(unsigned char volatile xdata *)0xFE00)
#define     CLKDIV      (*(unsigned char volatile xdata *)0xFE01)
#define     HIRCCR      (*(unsigned char volatile xdata *)0xFE02)
#define     XOSCCR      (*(unsigned char volatile xdata *)0xFE03)
#define     IRC32KCR    (*(unsigned char volatile xdata *)0xFE04)
#define     MCLKOCR     (*(unsigned char volatile xdata *)0xFE05)
#define     IRCDB       (*(unsigned char volatile xdata *)0xFE06)

#define     P0PU        (*(unsigned char volatile xdata *)0xFE10)
#define     P1PU        (*(unsigned char volatile xdata *)0xFE11)
#define     P2PU        (*(unsigned char volatile xdata *)0xFE12)
#define     P3PU        (*(unsigned char volatile xdata *)0xFE13)
#define     P4PU        (*(unsigned char volatile xdata *)0xFE14)
#define     P5PU        (*(unsigned char volatile xdata *)0xFE15)
#define     P0NCS       (*(unsigned char volatile xdata *)0xFE18)
#define     P1NCS       (*(unsigned char volatile xdata *)0xFE19)
#define     P2NCS       (*(unsigned char volatile xdata *)0xFE1A)
#define     P3NCS       (*(unsigned char volatile xdata *)0xFE1B)
#define     P4NCS       (*(unsigned char volatile xdata *)0xFE1C)
#define     P5NCS       (*(unsigned char volatile xdata *)0xFE1D)
#define     P0SR        (*(unsigned char volatile xdata *)0xFE20)
#define     P1SR        (*(unsigned char volatile xdata *)0xFE21)
#define     P2SR        (*(unsigned char volatile xdata *)0xFE22)
#define     P3SR        (*(unsigned char volatile xdata *)0xFE23)
#define     P4SR        (*(unsigned char volatile xdata *)0xFE24)
#define     P5SR        (*(unsigned char volatile xdata *)0xFE25)
#define     P0DR        (*(unsigned char volatile xdata *)0xFE28)
#define     P1DR        (*(unsigned char volatile xdata *)0xFE29)
#define     P2DR        (*(unsigned char volatile xdata *)0xFE2A)
#define     P3DR        (*(unsigned char volatile xdata *)0xFE2B)
#define     P4DR        (*(unsigned char volatile xdata *)0xFE2C)
#define     P5DR        (*(unsigned char volatile xdata *)0xFE2D)
#define     P0IE        (*(unsigned char volatile xdata *)0xFE30)
#define     P1IE        (*(unsigned char volatile xdata *)0xFE31)
#define     P3IE        (*(unsigned char volatile xdata *)0xFE33)

#define     I2CCFG      (*(unsigned char volatile xdata *)0xFE80)
#define     I2CMSCR     (*(unsigned char volatile xdata *)0xFE81)
#define     I2CMSST     (*(unsigned char volatile xdata *)0xFE82)
#define     I2CSLCR     (*(unsigned char volatile xdata *)0xFE83)
#define     I2CSLST     (*(unsigned char volatile xdata *)0xFE84)
#define     I2CSLADR    (*(unsigned char volatile xdata *)0xFE85)
#define     I2CTXD      (*(unsigned char volatile xdata *)0xFE86)
#define     I2CRXD      (*(unsigned char volatile xdata *)0xFE87)
#define     I2CMSAUX    (*(unsigned char volatile xdata *)0xFE88)

#define     TM2PS       (*(unsigned char volatile xdata *)0xFEA2)
#define     TM3PS       (*(unsigned char volatile xdata *)0xFEA3)
#define     TM4PS       (*(unsigned char volatile xdata *)0xFEA4)
#define     ADCTIM      (*(unsigned char volatile xdata *)0xFEA8)

#define     PWM0C      (*(unsigned  int  volatile xdata *)0xFF00)
#define     PWM0CH      (*(unsigned char volatile xdata *)0xFF00)
#define     PWM0CL      (*(unsigned char volatile xdata *)0xFF01)
#define     PWM0CKS     (*(unsigned char volatile xdata *)0xFF02)
#define     PWM0TADCH   (*(unsigned char volatile xdata *)0xFF03)
#define     PWM0TADCL   (*(unsigned char volatile xdata *)0xFF04)
#define     PWM0IF      (*(unsigned char volatile xdata *)0xFF05)
#define     PWM0FDCR    (*(unsigned char volatile xdata *)0xFF06)
#define     PWM00T1H    (*(unsigned char volatile xdata *)0xFF10)
#define     PWM00T1L    (*(unsigned char volatile xdata *)0xFF11)
#define     PWM00T2H    (*(unsigned char volatile xdata *)0xFF12)
#define     PWM00T2L    (*(unsigned char volatile xdata *)0xFF13)
#define     PWM00CR     (*(unsigned char volatile xdata *)0xFF14)
#define     PWM00HLD    (*(unsigned char volatile xdata *)0xFF15)
#define     PWM01T1H    (*(unsigned char volatile xdata *)0xFF18)
#define     PWM01T1L    (*(unsigned char volatile xdata *)0xFF19)
#define     PWM01T2H    (*(unsigned char volatile xdata *)0xFF1A)
#define     PWM01T2L    (*(unsigned char volatile xdata *)0xFF1B)
#define     PWM01CR     (*(unsigned char volatile xdata *)0xFF1C)
#define     PWM01HLD    (*(unsigned char volatile xdata *)0xFF1D)
#define     PWM02T1H    (*(unsigned char volatile xdata *)0xFF20)
#define     PWM02T1L    (*(unsigned char volatile xdata *)0xFF21)
#define     PWM02T2H    (*(unsigned char volatile xdata *)0xFF22)
#define     PWM02T2L    (*(unsigned char volatile xdata *)0xFF23)
#define     PWM02CR     (*(unsigned char volatile xdata *)0xFF24)
#define     PWM02HLD    (*(unsigned char volatile xdata *)0xFF25)
#define     PWM03T1H    (*(unsigned char volatile xdata *)0xFF28)
#define     PWM03T1L    (*(unsigned char volatile xdata *)0xFF29)
#define     PWM03T2H    (*(unsigned char volatile xdata *)0xFF2A)
#define     PWM03T2L    (*(unsigned char volatile xdata *)0xFF2B)
#define     PWM03CR     (*(unsigned char volatile xdata *)0xFF2C)
#define     PWM03HLD    (*(unsigned char volatile xdata *)0xFF2D)
#define     PWM04T1H    (*(unsigned char volatile xdata *)0xFF30)
#define     PWM04T1L    (*(unsigned char volatile xdata *)0xFF31)
#define     PWM04T2H    (*(unsigned char volatile xdata *)0xFF32)
#define     PWM04T2L    (*(unsigned char volatile xdata *)0xFF33)
#define     PWM04CR     (*(unsigned char volatile xdata *)0xFF34)
#define     PWM04HLD    (*(unsigned char volatile xdata *)0xFF35)
#define     PWM05T1H    (*(unsigned char volatile xdata *)0xFF38)
#define     PWM05T1L    (*(unsigned char volatile xdata *)0xFF39)
#define     PWM05T2H    (*(unsigned char volatile xdata *)0xFF3A)
#define     PWM05T2L    (*(unsigned char volatile xdata *)0xFF3B)
#define     PWM05CR     (*(unsigned char volatile xdata *)0xFF3C)
#define     PWM05HLD    (*(unsigned char volatile xdata *)0xFF3D)
#define     PWM06T1H    (*(unsigned char volatile xdata *)0xFF40)
#define     PWM06T1L    (*(unsigned char volatile xdata *)0xFF41)
#define     PWM06T2H    (*(unsigned char volatile xdata *)0xFF42)
#define     PWM06T2L    (*(unsigned char volatile xdata *)0xFF43)
#define     PWM06CR     (*(unsigned char volatile xdata *)0xFF44)
#define     PWM06HLD    (*(unsigned char volatile xdata *)0xFF45)
#define     PWM07T1H    (*(unsigned char volatile xdata *)0xFF48)
#define     PWM07T1L    (*(unsigned char volatile xdata *)0xFF49)
#define     PWM07T2H    (*(unsigned char volatile xdata *)0xFF4A)
#define     PWM07T2L    (*(unsigned char volatile xdata *)0xFF4B)
#define     PWM07CR     (*(unsigned char volatile xdata *)0xFF4C)
#define     PWM07HLD    (*(unsigned char volatile xdata *)0xFF4D)
#define     PWM1C      (*(unsigned  int  volatile xdata *)0xFF50)
#define     PWM1CH      (*(unsigned char volatile xdata *)0xFF50)
#define     PWM1CL      (*(unsigned char volatile xdata *)0xFF51)
#define     PWM1CKS     (*(unsigned char volatile xdata *)0xFF52)
#define     PWM1IF      (*(unsigned char volatile xdata *)0xFF55)
#define     PWM1FDCR    (*(unsigned char volatile xdata *)0xFF56)
#define     PWM10T1H    (*(unsigned char volatile xdata *)0xFF60)
#define     PWM10T1L    (*(unsigned char volatile xdata *)0xFF61)
#define     PWM10T2H    (*(unsigned char volatile xdata *)0xFF62)
#define     PWM10T2L    (*(unsigned char volatile xdata *)0xFF63)
#define     PWM10CR     (*(unsigned char volatile xdata *)0xFF64)
#define     PWM10HLD    (*(unsigned char volatile xdata *)0xFF65)
#define     PWM11T1H    (*(unsigned char volatile xdata *)0xFF68)
#define     PWM11T1L    (*(unsigned char volatile xdata *)0xFF69)
#define     PWM11T2H    (*(unsigned char volatile xdata *)0xFF6A)
#define     PWM11T2L    (*(unsigned char volatile xdata *)0xFF6B)
#define     PWM11CR     (*(unsigned char volatile xdata *)0xFF6C)
#define     PWM11HLD    (*(unsigned char volatile xdata *)0xFF6D)
#define     PWM12T1H    (*(unsigned char volatile xdata *)0xFF70)
#define     PWM12T1L    (*(unsigned char volatile xdata *)0xFF71)
#define     PWM12T2H    (*(unsigned char volatile xdata *)0xFF72)
#define     PWM12T2L    (*(unsigned char volatile xdata *)0xFF73)
#define     PWM12CR     (*(unsigned char volatile xdata *)0xFF74)
#define     PWM12HLD    (*(unsigned char volatile xdata *)0xFF75)
#define     PWM13T1H    (*(unsigned char volatile xdata *)0xFF78)
#define     PWM13T1L    (*(unsigned char volatile xdata *)0xFF79)
#define     PWM13T2H    (*(unsigned char volatile xdata *)0xFF7A)
#define     PWM13T2L    (*(unsigned char volatile xdata *)0xFF7B)
#define     PWM13CR     (*(unsigned char volatile xdata *)0xFF7C)
#define     PWM13HLD    (*(unsigned char volatile xdata *)0xFF7D)
#define     PWM14T1H    (*(unsigned char volatile xdata *)0xFF80)
#define     PWM14T1L    (*(unsigned char volatile xdata *)0xFF81)
#define     PWM14T2H    (*(unsigned char volatile xdata *)0xFF82)
#define     PWM14T2L    (*(unsigned char volatile xdata *)0xFF83)
#define     PWM14CR     (*(unsigned char volatile xdata *)0xFF84)
#define     PWM14HLD    (*(unsigned char volatile xdata *)0xFF85)
#define     PWM15T1H    (*(unsigned char volatile xdata *)0xFF88)
#define     PWM15T1L    (*(unsigned char volatile xdata *)0xFF89)
#define     PWM15T2H    (*(unsigned char volatile xdata *)0xFF8A)
#define     PWM15T2L    (*(unsigned char volatile xdata *)0xFF8B)
#define     PWM15CR     (*(unsigned char volatile xdata *)0xFF8C)
#define     PWM15HLD    (*(unsigned char volatile xdata *)0xFF8D)
#define     PWM16T1H    (*(unsigned char volatile xdata *)0xFF90)
#define     PWM16T1L    (*(unsigned char volatile xdata *)0xFF91)
#define     PWM16T2H    (*(unsigned char volatile xdata *)0xFF92)
#define     PWM16T2L    (*(unsigned char volatile xdata *)0xFF93)
#define     PWM16CR     (*(unsigned char volatile xdata *)0xFF94)
#define     PWM16HLD    (*(unsigned char volatile xdata *)0xFF95)
#define     PWM17T1H    (*(unsigned char volatile xdata *)0xFF98)
#define     PWM17T1L    (*(unsigned char volatile xdata *)0xFF99)
#define     PWM17T2H    (*(unsigned char volatile xdata *)0xFF9A)
#define     PWM17T2L    (*(unsigned char volatile xdata *)0xFF9B)
#define     PWM17CR     (*(unsigned char volatile xdata *)0xFF9C)
#define     PWM17HLD    (*(unsigned char volatile xdata *)0xFF9D)
#define     PWM2C      (*(unsigned  int  volatile xdata *)0xFFA0)
#define     PWM2CH      (*(unsigned char volatile xdata *)0xFFA0)
#define     PWM2CL      (*(unsigned char volatile xdata *)0xFFA1)
#define     PWM2CKS     (*(unsigned char volatile xdata *)0xFFA2)
#define     PWM2TADCH   (*(unsigned char volatile xdata *)0xFFA3)
#define     PWM2TADCL   (*(unsigned char volatile xdata *)0xFFA4)
#define     PWM2IF      (*(unsigned char volatile xdata *)0xFFA5)
#define     PWM2FDCR    (*(unsigned char volatile xdata *)0xFFA6)
#define     PWM20T1H    (*(unsigned char volatile xdata *)0xFFB0)
#define     PWM20T1L    (*(unsigned char volatile xdata *)0xFFB1)
#define     PWM20T2H    (*(unsigned char volatile xdata *)0xFFB2)
#define     PWM20T2L    (*(unsigned char volatile xdata *)0xFFB3)
#define     PWM20CR     (*(unsigned char volatile xdata *)0xFFB4)
#define     PWM20HLD    (*(unsigned char volatile xdata *)0xFFB5)
#define     PWM21T1H    (*(unsigned char volatile xdata *)0xFFB8)
#define     PWM21T1L    (*(unsigned char volatile xdata *)0xFFB9)
#define     PWM21T2H    (*(unsigned char volatile xdata *)0xFFBA)
#define     PWM21T2L    (*(unsigned char volatile xdata *)0xFFBB)
#define     PWM21CR     (*(unsigned char volatile xdata *)0xFFBC)
#define     PWM21HLD    (*(unsigned char volatile xdata *)0xFFBD)
#define     PWM22T1H    (*(unsigned char volatile xdata *)0xFFC0)
#define     PWM22T1L    (*(unsigned char volatile xdata *)0xFFC1)
#define     PWM22T2H    (*(unsigned char volatile xdata *)0xFFC2)
#define     PWM22T2L    (*(unsigned char volatile xdata *)0xFFC3)
#define     PWM22CR     (*(unsigned char volatile xdata *)0xFFC4)
#define     PWM22HLD    (*(unsigned char volatile xdata *)0xFFC5)
#define     PWM23T1H    (*(unsigned char volatile xdata *)0xFFC8)
#define     PWM23T1L    (*(unsigned char volatile xdata *)0xFFC9)
#define     PWM23T2H    (*(unsigned char volatile xdata *)0xFFCA)
#define     PWM23T2L    (*(unsigned char volatile xdata *)0xFFCB)
#define     PWM23CR     (*(unsigned char volatile xdata *)0xFFCC)
#define     PWM23HLD    (*(unsigned char volatile xdata *)0xFFCD)
#define     PWM24T1H    (*(unsigned char volatile xdata *)0xFFD0)
#define     PWM24T1L    (*(unsigned char volatile xdata *)0xFFD1)
#define     PWM24T2H    (*(unsigned char volatile xdata *)0xFFD2)
#define     PWM24T2L    (*(unsigned char volatile xdata *)0xFFD3)
#define     PWM24CR     (*(unsigned char volatile xdata *)0xFFD4)
#define     PWM24HLD    (*(unsigned char volatile xdata *)0xFFD5)
#define     PWM25T1H    (*(unsigned char volatile xdata *)0xFFD8)
#define     PWM25T1L    (*(unsigned char volatile xdata *)0xFFD9)
#define     PWM25T2H    (*(unsigned char volatile xdata *)0xFFDA)
#define     PWM25T2L    (*(unsigned char volatile xdata *)0xFFDB)
#define     PWM25CR     (*(unsigned char volatile xdata *)0xFFDC)
#define     PWM25HLD    (*(unsigned char volatile xdata *)0xFFDD)
#define     PWM26T1H    (*(unsigned char volatile xdata *)0xFFE0)
#define     PWM26T1L    (*(unsigned char volatile xdata *)0xFFE1)
#define     PWM26T2H    (*(unsigned char volatile xdata *)0xFFE2)
#define     PWM26T2L    (*(unsigned char volatile xdata *)0xFFE3)
#define     PWM26CR     (*(unsigned char volatile xdata *)0xFFE4)
#define     PWM26HLD    (*(unsigned char volatile xdata *)0xFFE5)
#define     PWM27T1H    (*(unsigned char volatile xdata *)0xFFE8)
#define     PWM27T1L    (*(unsigned char volatile xdata *)0xFFE9)
#define     PWM27T2H    (*(unsigned char volatile xdata *)0xFFEA)
#define     PWM27T2L    (*(unsigned char volatile xdata *)0xFFEB)
#define     PWM27CR     (*(unsigned char volatile xdata *)0xFFEC)
#define     PWM27HLD    (*(unsigned char volatile xdata *)0xFFED)
#define     PWM3C       (*(unsigned int  volatile xdata *)0xFC00)
#define     PWM3CH      (*(unsigned char volatile xdata *)0xFC00)
#define     PWM3CL      (*(unsigned char volatile xdata *)0xFC01)
#define     PWM3CKS     (*(unsigned char volatile xdata *)0xFC02)
#define     PWM3IF      (*(unsigned char volatile xdata *)0xFC05)
#define     PWM3FDCR    (*(unsigned char volatile xdata *)0xFC06)
#define     PWM30T1H    (*(unsigned char volatile xdata *)0xFC10)
#define     PWM30T1L    (*(unsigned char volatile xdata *)0xFC11)
#define     PWM30T2H    (*(unsigned char volatile xdata *)0xFC12)
#define     PWM30T2L    (*(unsigned char volatile xdata *)0xFC13)
#define     PWM30CR     (*(unsigned char volatile xdata *)0xFC14)
#define     PWM30HLD    (*(unsigned char volatile xdata *)0xFC15)
#define     PWM31T1H    (*(unsigned char volatile xdata *)0xFC18)
#define     PWM31T1L    (*(unsigned char volatile xdata *)0xFC19)
#define     PWM31T2H    (*(unsigned char volatile xdata *)0xFC1A)
#define     PWM31T2L    (*(unsigned char volatile xdata *)0xFC1B)
#define     PWM31CR     (*(unsigned char volatile xdata *)0xFC1C)
#define     PWM31HLD    (*(unsigned char volatile xdata *)0xFC1D)
#define     PWM32T1H    (*(unsigned char volatile xdata *)0xFC20)
#define     PWM32T1L    (*(unsigned char volatile xdata *)0xFC21)
#define     PWM32T2H    (*(unsigned char volatile xdata *)0xFC22)
#define     PWM32T2L    (*(unsigned char volatile xdata *)0xFC23)
#define     PWM32CR     (*(unsigned char volatile xdata *)0xFC24)
#define     PWM32HLD    (*(unsigned char volatile xdata *)0xFC25)
#define     PWM33T1H    (*(unsigned char volatile xdata *)0xFC28)
#define     PWM33T1L    (*(unsigned char volatile xdata *)0xFC29)
#define     PWM33T2H    (*(unsigned char volatile xdata *)0xFC2A)
#define     PWM33T2L    (*(unsigned char volatile xdata *)0xFC2B)
#define     PWM33CR     (*(unsigned char volatile xdata *)0xFC2C)
#define     PWM33HLD    (*(unsigned char volatile xdata *)0xFC2D)
#define     PWM34T1H    (*(unsigned char volatile xdata *)0xFC30)
#define     PWM34T1L    (*(unsigned char volatile xdata *)0xFC31)
#define     PWM34T2H    (*(unsigned char volatile xdata *)0xFC32)
#define     PWM34T2L    (*(unsigned char volatile xdata *)0xFC33)
#define     PWM34CR     (*(unsigned char volatile xdata *)0xFC34)
#define     PWM34HLD    (*(unsigned char volatile xdata *)0xFC35)
#define     PWM35T1H    (*(unsigned char volatile xdata *)0xFC38)
#define     PWM35T1L    (*(unsigned char volatile xdata *)0xFC39)
#define     PWM35T2H    (*(unsigned char volatile xdata *)0xFC3A)
#define     PWM35T2L    (*(unsigned char volatile xdata *)0xFC3B)
#define     PWM35CR     (*(unsigned char volatile xdata *)0xFC3C)
#define     PWM35HLD    (*(unsigned char volatile xdata *)0xFC3D)
#define     PWM36T1H    (*(unsigned char volatile xdata *)0xFC40)
#define     PWM36T1L    (*(unsigned char volatile xdata *)0xFC41)
#define     PWM36T2H    (*(unsigned char volatile xdata *)0xFC42)
#define     PWM36T2L    (*(unsigned char volatile xdata *)0xFC43)
#define     PWM36CR     (*(unsigned char volatile xdata *)0xFC44)
#define     PWM36HLD    (*(unsigned char volatile xdata *)0xFC45)
#define     PWM37T1H    (*(unsigned char volatile xdata *)0xFC48)
#define     PWM37T1L    (*(unsigned char volatile xdata *)0xFC49)
#define     PWM37T2H    (*(unsigned char volatile xdata *)0xFC4A)
#define     PWM37T2L    (*(unsigned char volatile xdata *)0xFC4B)
#define     PWM37CR     (*(unsigned char volatile xdata *)0xFC4C)
#define     PWM37HLD    (*(unsigned char volatile xdata *)0xFC4D)
#define     PWM4C       (*(unsigned int volatile xdata *)0xFC50)
#define     PWM4CH      (*(unsigned char volatile xdata *)0xFC50)
#define     PWM4CL      (*(unsigned char volatile xdata *)0xFC51)
#define     PWM4CKS     (*(unsigned char volatile xdata *)0xFC52)
#define     PWM4TADCH   (*(unsigned char volatile xdata *)0xFC53)
#define     PWM4TADCL   (*(unsigned char volatile xdata *)0xFC54)
#define     PWM4IF      (*(unsigned char volatile xdata *)0xFC55)
#define     PWM4FDCR    (*(unsigned char volatile xdata *)0xFC56)
#define     PWM40T1H    (*(unsigned char volatile xdata *)0xFC60)
#define     PWM40T1L    (*(unsigned char volatile xdata *)0xFC61)
#define     PWM40T2H    (*(unsigned char volatile xdata *)0xFC62)
#define     PWM40T2L    (*(unsigned char volatile xdata *)0xFC63)
#define     PWM40CR     (*(unsigned char volatile xdata *)0xFC64)
#define     PWM40HLD    (*(unsigned char volatile xdata *)0xFC65)
#define     PWM41T1H    (*(unsigned char volatile xdata *)0xFC68)
#define     PWM41T1L    (*(unsigned char volatile xdata *)0xFC69)
#define     PWM41T2H    (*(unsigned char volatile xdata *)0xFC6A)
#define     PWM41T2L    (*(unsigned char volatile xdata *)0xFC6B)
#define     PWM41CR     (*(unsigned char volatile xdata *)0xFC6C)
#define     PWM41HLD    (*(unsigned char volatile xdata *)0xFC6D)
#define     PWM42T1H    (*(unsigned char volatile xdata *)0xFC70)
#define     PWM42T1L    (*(unsigned char volatile xdata *)0xFC71)
#define     PWM42T2H    (*(unsigned char volatile xdata *)0xFC72)
#define     PWM42T2L    (*(unsigned char volatile xdata *)0xFC73)
#define     PWM42CR     (*(unsigned char volatile xdata *)0xFC74)
#define     PWM42HLD    (*(unsigned char volatile xdata *)0xFC75)
#define     PWM43T1H    (*(unsigned char volatile xdata *)0xFC78)
#define     PWM43T1L    (*(unsigned char volatile xdata *)0xFC79)
#define     PWM43T2H    (*(unsigned char volatile xdata *)0xFC7A)
#define     PWM43T2L    (*(unsigned char volatile xdata *)0xFC7B)
#define     PWM43CR     (*(unsigned char volatile xdata *)0xFC7C)
#define     PWM43HLD    (*(unsigned char volatile xdata *)0xFC7D)
#define     PWM44T1H    (*(unsigned char volatile xdata *)0xFC80)
#define     PWM44T1L    (*(unsigned char volatile xdata *)0xFC81)
#define     PWM44T2H    (*(unsigned char volatile xdata *)0xFC82)
#define     PWM44T2L    (*(unsigned char volatile xdata *)0xFC83)
#define     PWM44CR     (*(unsigned char volatile xdata *)0xFC84)
#define     PWM44HLD    (*(unsigned char volatile xdata *)0xFC85)
#define     PWM45T1H    (*(unsigned char volatile xdata *)0xFC88)
#define     PWM45T1L    (*(unsigned char volatile xdata *)0xFC89)
#define     PWM45T2H    (*(unsigned char volatile xdata *)0xFC8A)
#define     PWM45T2L    (*(unsigned char volatile xdata *)0xFC8B)
#define     PWM45CR     (*(unsigned char volatile xdata *)0xFC8C)
#define     PWM45HLD    (*(unsigned char volatile xdata *)0xFC8D)
#define     PWM46T1H    (*(unsigned char volatile xdata *)0xFC90)
#define     PWM46T1L    (*(unsigned char volatile xdata *)0xFC91)
#define     PWM46T2H    (*(unsigned char volatile xdata *)0xFC92)
#define     PWM46T2L    (*(unsigned char volatile xdata *)0xFC93)
#define     PWM46CR     (*(unsigned char volatile xdata *)0xFC94)
#define     PWM46HLD    (*(unsigned char volatile xdata *)0xFC95)
#define     PWM47T1H    (*(unsigned char volatile xdata *)0xFC98)
#define     PWM47T1L    (*(unsigned char volatile xdata *)0xFC99)
#define     PWM47T2H    (*(unsigned char volatile xdata *)0xFC9A)
#define     PWM47T2L    (*(unsigned char volatile xdata *)0xFC9B)
#define     PWM47CR     (*(unsigned char volatile xdata *)0xFC9C)
#define     PWM47HLD    (*(unsigned char volatile xdata *)0xFC9D)
#define     PWM5C       (*(unsigned int  volatile xdata *)0xFCA0)
#define     PWM5CH      (*(unsigned char volatile xdata *)0xFCA0)
#define     PWM5CL      (*(unsigned char volatile xdata *)0xFCA1)
#define     PWM5CKS     (*(unsigned char volatile xdata *)0xFCA2)
#define     PWM5IF      (*(unsigned char volatile xdata *)0xFCA5)
#define     PWM5FDCR    (*(unsigned char volatile xdata *)0xFCA6)
#define     PWM50T1H    (*(unsigned char volatile xdata *)0xFCB0)
#define     PWM50T1L    (*(unsigned char volatile xdata *)0xFCB1)
#define     PWM50T2H    (*(unsigned char volatile xdata *)0xFCB2)
#define     PWM50T2L    (*(unsigned char volatile xdata *)0xFCB3)
#define     PWM50CR     (*(unsigned char volatile xdata *)0xFCB4)
#define     PWM50HLD    (*(unsigned char volatile xdata *)0xFCB5)
#define     PWM51T1H    (*(unsigned char volatile xdata *)0xFCB8)
#define     PWM51T1L    (*(unsigned char volatile xdata *)0xFCB9)
#define     PWM51T2H    (*(unsigned char volatile xdata *)0xFCBA)
#define     PWM51T2L    (*(unsigned char volatile xdata *)0xFCBB)
#define     PWM51CR     (*(unsigned char volatile xdata *)0xFCBC)
#define     PWM51HLD    (*(unsigned char volatile xdata *)0xFCBD)
#define     PWM52T1H    (*(unsigned char volatile xdata *)0xFCC0)
#define     PWM52T1L    (*(unsigned char volatile xdata *)0xFCC1)
#define     PWM52T2H    (*(unsigned char volatile xdata *)0xFCC2)
#define     PWM52T2L    (*(unsigned char volatile xdata *)0xFCC3)
#define     PWM52CR     (*(unsigned char volatile xdata *)0xFCC4)
#define     PWM52HLD    (*(unsigned char volatile xdata *)0xFCC5)
#define     PWM53T1H    (*(unsigned char volatile xdata *)0xFCC8)
#define     PWM53T1L    (*(unsigned char volatile xdata *)0xFCC9)
#define     PWM53T2H    (*(unsigned char volatile xdata *)0xFCCA)
#define     PWM53T2L    (*(unsigned char volatile xdata *)0xFCCB)
#define     PWM53CR     (*(unsigned char volatile xdata *)0xFCCC)
#define     PWM53HLD    (*(unsigned char volatile xdata *)0xFCCD)
#define     PWM54T1H    (*(unsigned char volatile xdata *)0xFCD0)
#define     PWM54T1L    (*(unsigned char volatile xdata *)0xFCD1)
#define     PWM54T2H    (*(unsigned char volatile xdata *)0xFCD2)
#define     PWM54T2L    (*(unsigned char volatile xdata *)0xFCD3)
#define     PWM54CR     (*(unsigned char volatile xdata *)0xFCD4)
#define     PWM54HLD    (*(unsigned char volatile xdata *)0xFCD5)
#define     PWM55T1H    (*(unsigned char volatile xdata *)0xFCD8)
#define     PWM55T1L    (*(unsigned char volatile xdata *)0xFCD9)
#define     PWM55T2H    (*(unsigned char volatile xdata *)0xFCDA)
#define     PWM55T2L    (*(unsigned char volatile xdata *)0xFCDB)
#define     PWM55CR     (*(unsigned char volatile xdata *)0xFCDC)
#define     PWM55HLD    (*(unsigned char volatile xdata *)0xFCDD)
#define     PWM56T1H    (*(unsigned char volatile xdata *)0xFCE0)
#define     PWM56T1L    (*(unsigned char volatile xdata *)0xFCE1)
#define     PWM56T2H    (*(unsigned char volatile xdata *)0xFCE2)
#define     PWM56T2L    (*(unsigned char volatile xdata *)0xFCE3)
#define     PWM56CR     (*(unsigned char volatile xdata *)0xFCE4)
#define     PWM56HLD    (*(unsigned char volatile xdata *)0xFCE5)
#define     PWM57T1H    (*(unsigned char volatile xdata *)0xFCE8)
#define     PWM57T1L    (*(unsigned char volatile xdata *)0xFCE9)
#define     PWM57T2H    (*(unsigned char volatile xdata *)0xFCEA)
#define     PWM57T2L    (*(unsigned char volatile xdata *)0xFCEB)
#define     PWM57CR     (*(unsigned char volatile xdata *)0xFCEC)
#define     PWM57HLD    (*(unsigned char volatile xdata *)0xFCED)

/////////////////////////////////////////////////

#endif

