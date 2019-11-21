#include "main.h"
#include "adc.h"

uchar ch;//ADCͨ����

/*
 *��ʼ��ADC
 */
void InitADC(void)
{
	P1ASF=0XFF;//����P1ΪAD��
	ADC_RES=0;//�������Ĵ���
	ADC_CONTR=ADC_POWER|ADC_SPEEDLH|ADC_START|ch; //1100 1011
	delay(2);
}
/*
 *��ʼ������
 */
void InitUart(void)	
{
	SCON = 0X5A;// 0101 1010  ���ڹ�����ʽ1��ʮλ�����첽ͨ�ţ�����Ե�ͨ�ţ��������
	#if URMD == 0
				T2L  = 0XD8;//���ô���Ϊ8λ�ɱ䲨����	
				T2H  = 0XFF;//115200BPS(65536-11095200/4/115200)
				AUXR = 0X14;//T21Tģʽ����������ʱ��2
				AUXR |= 0X01;//ѡ��ʱ��2��Ϊ����1�����ʵķ�����
	#elif URMD == 1
				AUXR = 0X40;/��ʱ��1Ϊ1Tģʽ
				TMOD = 0X00;//��ʱ��1Ϊģʽ0��16λ�Զ���װ��
				TL1  = 0XD8;//���ò�������װֵ
				TH1  = 0XFF;//115200bps
	      TR1  = 1;		//��ʱ��1����
	#else 
		    TMOD = 0X20;//���ö�ʱ��1λ��λ�Զ���װģʽ
				AUXR = 0X40;//��ʱ��1Ϊ1Tģʽ
				THI1 = TL1 = 0XFB;//115200bps
				TR1  = 1;
	#endif
}
/*
 *���ʹ�������
 */
void SengByte(uchar dat)
{
	while(!TI);	//�ȴ�ǰһ�����ݷ������
	TI=0;//������ͱ�־
	SBUF=dat;	//���͵�ǰ����
}
