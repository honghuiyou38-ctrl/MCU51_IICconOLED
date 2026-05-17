#include <IIC.h>
#include <main.h>
#include <delay.h>

void IIC_Start()
{
	IIC_SCL=1;
	IIC_SDA=1;
	Delay5us();
	IIC_SDA=0;
	Delay5us();
	IIC_SCL=0;
}

void IIC_Stop()
{
	IIC_SCL=1;
	IIC_SDA=0;
	Delay5us();
	IIC_SDA=1;
}

void IIC_Send_byte(unsigned char IIC_byte)
{
	char i;
	for(i=0;i<8;i++)
	{
		IIC_SDA=IIC_byte&(0x80>>i);
		IIC_SCL=1;
		Delay5us();
		IIC_SCL=0;
		Delay5us();
	}
}

unsigned char IIC_Recv_ACK()
{
	unsigned char ack;
	IIC_SDA=1;
	IIC_SCL=1;
	Delay5us();
	ack=IIC_SDA;
	IIC_SCL=0;
	Delay5us();
	
	return ack;
}