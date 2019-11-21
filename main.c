#include<STC15F2K60S2.h>
#include<intrins.h>
#include "main.h"

uchar m;

uchar keyvalue[]={0,0,0,0,0};
void main(void)
{
	timer_init();//timer initialization
	init();
	InitUart();
	InitADC();
	
	while(1)
	{		
		switch(mode)//判断工作模式
		{
			case 0:action1();break;
			case 1:action2();break;
			case 2:action3();break;
			case 3:action4();break;
			case 4:action5();break;
			case 5:action6();break;
			
			case 6:action7();break;		
			case 7:action8();break;					
		}
	}
}
//对参数初始化
void init(void)
{
	
}
	
void timer_init()
{
	TMOD|=0X11;
	TH0=(65535-50000)/256;
	TL0=(65535-50000)%256;
	TH1=(65535-100)/256;//10MS读一次ADC值
	TL1=(65535-100)%256;
	EA=1;
	ET0=1;TR0=1;
	ET1=1;TR1=1;
	//AUXR|=0X00;
	EADC=1;//使能ADC中断
}

void int0() interrupt 0 using 0
{

}	

void timer1() interrupt 1 using 1      //0.0358 3800
{		
	uchar i;
	i++;
	if(i>=20)
	{
		i=0;
		m++;
		if(m>=60)
		{
			m=0;
		}
	}
	
}

void timer2() interrupt 5 using 3
{
	
}
