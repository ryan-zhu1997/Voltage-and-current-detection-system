#include "key.h"
#include "main.h"

uchar mode;
uchar mode_flag=0;
int ul1;//电压上限
int nl1;//电压下限
int op;//充放电时间
char mode_tab[8][2]={"u1","u2","u3","u4","u5","u6","a7","a8"};
int get_keyvalue(void)
{
	uchar i;
	int aver;
	for(i=0;i<5;i++)
	{
		keyvalue[i]=get_voltage(3);//读取ADC值
		delay(10);
	}
	//后三次按键平均电压值
	aver=(keyvalue[2]+keyvalue[3]+keyvalue[4])/3;
	
	if((aver>496)&(aver<528))//512±16
	return 1;//moshi
	
	else if((aver>665)&(aver<697))//681±16
	return 2;//+
	
	else if((aver>752)&(aver<794)) //768±16
	return 3;//-	
		
	else return 0;
		
}

void key_action(void)
{
	uchar i,j=0;
	i=get_keyvalue();
	switch(i)
	{
		case 0: break;
		case 1: mode_flag=1;//进入设置模式
						if(mode_flag==1) mode_flag=0;//再次按下确认
						break;
		case 2: 
			mode_tab[j][2]=mode_tab[j+1][2];if(j>7) j=0;
					if(mode_flag==1)
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
						
						break;
		case 3: break;
	}
}