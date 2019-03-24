#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
 


#define RED  0XFF00
#define GREEN 0XFF0000
#define BLUE 0xff
#define SHUTOFF 0X000000

void Delay(u32 count)         //  Delay subrouting generate some time delay by looping   1000 0000 equals to 1 second
{
	u32 i;
	for (i=0;i<count;i++);
}


void RGB_Set_Up(void)
{
	GPIOB->BSRR = 1<<7;
	Delay(3);
	GPIOB->BRR = 1<<7;
	Delay(0);	                  //  I have measure it through the osciloscope
}	

void RGB_Set_Down(void)
{
	GPIOB->BSRR = 1<<7;
	Delay(0);
	GPIOB->BRR = 1<<7;
	Delay(3);	
}	

void RGB_Set(u32 rgb_Value)
{
	int i;
	u8 byte=0;
	for(i=23;i>=0;i--)
	{
		byte= ((rgb_Value>>i)&0x01);
		{
			if(byte==1)
			{
				RGB_Set_Up();
			}
			else
			{
				RGB_Set_Down();
			}
		}
	}
}	


void RGB_Reset(void)      
{
	GPIOB->BRR = 1<<7;
  Delay(60000000);	
}	


 int main(void)
 {	
	 int i;
//	delay_init();	    //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
	while(1)
	{
//		LED0=0;//		LED0=1;

		LED1=0;		
		RGB_Reset();
		for(i=0;i<28;i++)
		{
			RGB_Set(RED);
		}
		

		Delay(60000000);
//	  delay_ms(1000);
		

		
    for(i=0;i<28;i++)
		{
			RGB_Set(GREEN);
		}
		Delay(60000000);
//		LED1=1;		
//		delay_ms(1000);
	}
 }



