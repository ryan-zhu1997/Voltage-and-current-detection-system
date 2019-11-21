#ifndef _ADC_H_
#define _ADC.H_
#include "main.h"

#define FOSC 11520000L
#define BAUD 9600
/*
 *0 : ʹ�ö�ʱ��2��Ϊ�����ʷ�����
 *1 : ʹ�ö�ʱ��1ģʽ0(16λ�Զ���װ) ��Ϊ�����ʷ�����
 *2 : ʹ�ö�ʱ��1ģʽ2��8λ�Զ���װ����Ϊ�����ʷ�����
 */
#define URMD 0
#define ADC_POWER	  0X80	//ADC��Դ����λ
#define ADC_FLAG  	0X10  //ADC��ɱ�־
#define ADC_START 	0X08  //ADC������־
#define ADC_SPEEDLL 0X00  //540��ʱ��
#define ADC_SPEEDL 	0X20  //360��ʱ��
#define ADC_SPEEDLH 0X40  //180��ʱ��
#define ADC_SPEEDHH 0X60  //90��ʱ��

void InitUart(void);
void SendData(uchar dat);
void InitADC(void);
#endif