#include "key.h"
#include "main.h"

uchar mode;
uchar mode_flag=0;
uchar index[4]={0,1,2,3};//ģʽ��ʾ����ܡ���ѹ������������л�����
uchar para[][]={ul1,nl1,op}
int ul1=0;//��ѹ����
int nl1=0;//��ѹ����
int op=0;//��ŵ�ʱ��
char mode_tab[8][2]={"u1","u2","u3","u4","u5","u6","a7","a8"};
int get_keyvalue(void)
{
	uchar i;
	int aver;
	for(i=0;i<5;i++)
	{
		keyvalue[i]=get_voltage(3);//��ȡADCֵ
		delay(10);
	}
	//�����ΰ���ƽ����ѹֵ
	aver=(keyvalue[2]+keyvalue[3]+keyvalue[4])/3;
	
	if((aver>496)&(aver<528))//512��16
	return 1;//moshi
	
	else if((aver>665)&(aver<697))//681��16
	return 2;//+
	
	else if((aver>752)&(aver<794)) //768��16
	return 3;//-	
		
	else return 0;
		
}

void key_action(void)
{
	uchar i,j,k=0;
	uchar mode_flag,para_flag,value_flag=0;
	i=get_keyvalue();
	switch(i)
	{
		case 0: break;
		case 1: /*mode_flag=1;//��������ģʽ
						if(mode_flag==1) mode_flag=0;//�ٴΰ���ȷ��*/
						if(k<4)
							index[k]=index[k+1];
						else 
							index[k]=index[0];
						switch(index[k])
						{
							case 0://ȷ��״̬����������ܲ���˸
											mode_flag=0;para_flag=0;value_flag=0;
							case 1://����ܢ���˸(��MODE��ʾ�����),��ʱ��+-���ö�Ӧ����ģʽ
											mode_flag=1;break;
							
							case 2://����ܢ���˸(����ѹ�����)����ʱѡ������õĲ��������ѹ�����ޡ����ʱ��
											para_flag=1;break;
							
							case 3:	//����ܢ���˸(�����������),��ʱ�ɶԲ���ֵ+ -,����������
											value_flag=1;break;
						}						
						
		case 2: 
						if(mode_flag)
						{
							mode_tab[j][2]=mode_tab[j+1][2];
							if(j>7) j=0;
						}
						if(para_flag)
						{
							switch(mode_tab[j][2])
							{
								case 0://u1
								case 1:
								case 2:
												if(get_keyvalue()==2)
												{
													delay(5);
													if(get_keyvalue()==2)
													{
														
													}
												}
								case 3:
								case 4:
								case 5://u6
								case 6:break;//a7
								case 7:break;//a8
								
							}				
						}
						if(value_flag)	
						{}
										
					
								
						
		case 3: 
						if(mode_flag)
						{							
							mode_tab[j][2]=mode_tab[j-1][2];
							if(j<1) j=8;
						}
						if(para_flag)
						{}
						if(value_flag)	
						{}break;
	}
}