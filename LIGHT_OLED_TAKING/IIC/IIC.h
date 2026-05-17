#ifndef _IIC_H
#define _IIC_H
#include <main.h>

void IIC_Start();
void IIC_Stop();
void IIC_Send_byte(unsigned char IIC_byte);
unsigned char IIC_Recv_ACK();

#endif

