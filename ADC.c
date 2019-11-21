#include "main.h"
#include "adc.h"

uchar ch;//ADC通道号

/*
 *初始化ADC
 */
void InitADC(void)
{
	P1ASF=0XFF;//设置P1为AD口
	ADC_RES=0;//清除结果寄存器
	ADC_CONTR=ADC_POWER|ADC_SPEEDLH|ADC_START|ch; //1100 1011
	delay(2);
}
/*
 *初始化串口
 */
void InitUart(void)	
{
	SCON = 0X5A;// 0101 1010  串口工作方式1（十位数据异步通信），点对点通信，允许接收
	#if URMD == 0
				T2L  = 0XD8;//设置串口为8位可变波特率	
				T2H  = 0XFF;//115200BPS(65536-11095200/4/115200)
				AUXR = 0X14;//T21T模式，并启动定时器2
				AUXR |= 0X01;//选择定时器2作为串口1波特率的发生器
	#elif URMD == 1
				AUXR = 0X40;/定时器1为1T模式
				TMOD = 0X00;//定时器1为模式0（16位自动重装）
				TL1  = 0XD8;//设置波特率重装值
				TH1  = 0XFF;//115200bps
	      TR1  = 1;		//定时器1启动
	#else 
		    TMOD = 0X20;//设置定时器1位八位自动重装模式
				AUXR = 0X40;//定时器1为1T模式
				THI1 = TL1 = 0XFB;//115200bps
				TR1  = 1;
	#endif
}
/*
 *发送串口数据
 */
void SengByte(uchar dat)
{
	while(!TI);	//等待前一个数据发送完成
	TI=0;//清楚发送标志
	SBUF=dat;	//发送当前数据
}
