#include "voltage.h"

/*
 *��ȡP1.X�ڵ�ѹֵ
 *chΪͨ����
 */
int get_voltage(uchar ch) 
{
	uchar AD_FIN=0; //�洢A/Dת����־
	ADC_CONTR=ADC_POWER|ADC_SPEEDLH|ADC_START|ch;
	while (AD_FIN ==0)
	{     //�ȴ�A/Dת������
    AD_FIN = (ADC_CONTR & 0x10); //0001 0000����A/Dת��������
  }	
	ADC_CONTR |=0XEF;//1110 1111 ���FLAGλ
	return (ADC_RES+ADC_RESL);//����A/Dת�������10λADC���ݸ�8λ��ADC_RES�У���2λ��ADC_RESL�У�
}
