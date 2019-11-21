#include "voltage.h"

/*
 *读取P1.X口电压值
 *ch为通道号
 */
int get_voltage(uchar ch) 
{
	uchar AD_FIN=0; //存储A/D转换标志
	ADC_CONTR=ADC_POWER|ADC_SPEEDLH|ADC_START|ch;
	while (AD_FIN ==0)
	{     //等待A/D转换结束
    AD_FIN = (ADC_CONTR & 0x10); //0001 0000测试A/D转换结束否
  }	
	ADC_CONTR |=0XEF;//1110 1111 清除FLAG位
	return (ADC_RES+ADC_RESL);//返回A/D转换结果（10位ADC数据高8位在ADC_RES中，低2位在ADC_RESL中）
}
