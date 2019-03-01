// Header:  UART
// File Name: UART.c
// Author:  chengmengmegn
// Date:

#include "UART.h"


bit busy;
char str[32]="";


void InitUART(void)
{
#if (PARITYBIT == NONE_PARITY)
	SCON = 0x50;            //8-bit variable UART
#elif (PARITYBIT == ODD_PARITY) || (PARITYBIT == EVEN_PARITY) || (PARITYBIT == MARK_PARITY)
	SCON = 0xda;            //9-bit variable UART, parity bit initial to 1
#elif (PARITYBIT == SPACE_PARITY)
	SCON = 0xd2;            //9-bit variable UART, parity bit initial to 0
#endif

	TMOD = 0x20;            //Set Timer1 as 8-bit auto reload mode
	TH1 = TL1 = -(FOSC/12/32/BAUD); //Set auto-reload vaule
	TR1 = 1;                //Timer1 start run
	ES = 1;                 //Enable UART interrupt
	EA = 1;                 //Open master interrupt switch

}

/*----------------------------
UART interrupt service routine
----------------------------*/
void Uart_Isr() interrupt 4 using 1
{
	if (RI)
	{
		RI = 0;             //Clear receive interrupt flag
		//SBUF;          //UART data 
	}
	if (TI)
	{
		TI = 0;             //Clear transmit interrupt flag
		busy = 0;           //Clear transmit busy flag
	}
}

/*----------------------------
Send a byte data to UART
Input: dat (data to be sent)
Output:None
----------------------------*/
void SendData(BYTE dat)
{
	while (busy);           //Wait for the completion of the previous data is sent
	ACC = dat;              //Calculate the even parity bit P (PSW.0)
	if (P)                  //Set the parity bit according to P
	{
#if (PARITYBIT == ODD_PARITY)
		TB8 = 0;            //Set parity bit to 0
#elif (PARITYBIT == EVEN_PARITY)
		TB8 = 1;            //Set parity bit to 1
#endif
	}
	else
	{
#if (PARITYBIT == ODD_PARITY)
		TB8 = 1;            //Set parity bit to 1
#elif (PARITYBIT == EVEN_PARITY)
		TB8 = 0;            //Set parity bit to 0
#endif
	}
	busy = 1;
	SBUF = ACC;             //Send data to UART buffer
}

/*----------------------------
Send a string to UART
Input: s (address of string)
Output:None
----------------------------*/
void SendString(char *s)
{
	while (*s)              //Check the end of the string
	{
		SendData(*s++);     //Send current char and increment string ptr
	}
}

