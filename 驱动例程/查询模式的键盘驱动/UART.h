/*--------------------------------------------------------------------------
KeyBoard.h
	Serial port common driver written for AT89S52
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef __UART_H__
#define __UART_H__

#include <REG52.H>
#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned int WORD;

/*You need Set it only. */

#ifndef FOSC
#define FOSC 11059200L      //System frequency
#endif

#ifndef BAUD
#define BAUD 9600           //UART baudrate
#endif


/*Define UART parity mode*/
#define NONE_PARITY     0   //None parity
#define ODD_PARITY      1   //Odd parity
#define EVEN_PARITY     2   //Even parity
#define MARK_PARITY     3   //Mark parity
#define SPACE_PARITY    4   //Space parity

#define PARITYBIT NONE_PARITY   //Testing even parity

extern char str[32];
void SendData(BYTE dat);
void SendString(char *s);
void InitUART();
#endif

