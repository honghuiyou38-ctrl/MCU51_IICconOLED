#ifndef _MAIN_H
#define _MAIN_H
#include "reg52.h"

typedef unsigned int uint;
typedef unsigned char uchar;

extern uchar recv;

//¬„ª˙51≈‰÷√£∫
sbit LED1 = P1^0;
sbit LED2 = P1^1;
sbit LED3 = P1^2;
sbit LED4 = P1^3;
sbit KEY1 = P3^2;
sbit KEY2 = P3^3;
sbit BEEP=P1^6;
sbit SUN=P3^7;

//IIC≥ı º≈‰÷√:
sbit IIC_SCL=P1^5;
sbit IIC_SDA=P1^4;


#endif