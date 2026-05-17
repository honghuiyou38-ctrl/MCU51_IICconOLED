#include "reg52.h"
#include <intrins.h>
#include <delay.h>
#include <uart.h>
#include "oled.h"
#include <main.h>

uchar recv;
int p=0;

void main()
{
	OLED_Init();			//³õÊ¼»¯OLED  
	OLED_Clear();
	EX0=1;
	IT0=1;
	EX1=1;
	IT1=1;
	EA=1;
  while(1)
  {		
		if(p>0)
		{	OLED_Clear();
			BEEP=LED1=LED2=LED3=LED4=1;
			OLED_ShowCHinese(36+10,0,5);
			OLED_ShowCHinese(54+10,0,6);
			Delay_xms(500);
		}
		else
		{
			if(SUN==0)
			{
				BEEP=0;
				LED4=0;
				LED3=0;
				LED2=0;
				LED1=0;
			}
			else
			{	
				BEEP=1;
				LED4=1;
				LED3=1;
				LED2=1;
				LED1=1;
			}
			
			if(BEEP==0)
			{
				OLED_ShowCHinese(0+10,0,0);
				OLED_ShowCHinese(18+10,0,1);
				OLED_ShowCHinese(36+10,0,2);
				OLED_ShowCHinese(54+10,0,3);
				OLED_ShowCHinese(72+10,0,4);

				OLED_ShowString(48,6,"LEVEL:4",16);//ÏÔÊ¾ASCII×Ö·û	 
				
				Delay_xms(1000);
			}
			else{OLED_Clear();}
		}
	}
 
}

void EX0_Routine() interrupt 0
{
	p++;
}

void EX1_Routine() interrupt 2
{
	p=0;
}

