#include <uart.h>
#include "reg52.h"

void UART_send(uchar send_byte)
{
	SBUF=send_byte;
	while(TI==0);
	TI=0;
}

void UART_str(uchar *uart_str)
{
	while(*uart_str!='\0')
	{
		UART_send(*uart_str++);
	}
}

void UART_INit()
{
	SCON=0x50;
	TCON&=0x7f;
	TMOD&=0x0f;
	TMOD|=0x20;
	TL1=0xFD;
	TH1=0xFD;
	TR1=1;
}