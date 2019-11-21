#ifndef _main_H_
#define _main_H_
#include "STC15F2K60S2.H"
#include "delay.h"
#include "adc.h"
#include "intrins.h"
#include "key.h"
#include "voltage.h"
//#include "
#define uchar unsigned char
#define uint unsigned int
void	timer_init(void);
void init(void);
extern uchar ch;
extern uchar mode;
sbit MODE=P5^5;//模式切换，电压电流
sbit ENU=P2^6;
sbit ENI=P2^7;
sbit ST_CP1=P2^2;
sbit SH_CP1=P2^1;
sbit DS1=P2^0;
sbit ST_CP2=P2^5;
sbit SH_CP2=P2^4;
sbit DS2=P2^3;
sbit key=P1^3;
#endif