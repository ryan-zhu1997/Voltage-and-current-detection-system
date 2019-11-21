#ifndef _ADC_H_
#define _ADC.H_
#include "main.h"

#define FOSC 11520000L
#define BAUD 9600
/*
 *0 : 使用定时器2作为波特率发生器
 *1 : 使用定时器1模式0(16位自动重装) 作为波特率发生器
 *2 : 使用定时器1模式2（8位自动重装）作为波特率发生器
 */
#define URMD 0
#define ADC_POWER	  0X80	//ADC电源控制位
#define ADC_FLAG  	0X10  //ADC完成标志
#define ADC_START 	0X08  //ADC启动标志
#define ADC_SPEEDLL 0X00  //540个时钟
#define ADC_SPEEDL 	0X20  //360个时钟
#define ADC_SPEEDLH 0X40  //180个时钟
#define ADC_SPEEDHH 0X60  //90个时钟

void InitUart(void);
void SendData(uchar dat);
void InitADC(void);
#endif