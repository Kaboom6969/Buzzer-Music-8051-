#include <REGX51.H>
#include <INTRINS.h>
void Timer1_Init()		//@11.0592MHz
{			
	TMOD &= 0xF0;			
	TMOD |= 0x01;			
	TL1 = 0x66;				
	TH1 = 0xFC;				
	TF1 = 0;				
	TR1 = 1;	
	ET1 = 1;
	EA  = 1;
	PT1 = 0;
}
/*
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TL0 = 0xCD;
	TH0 = 0xD4;
	T0Count++;
	if (T0Count>=1000)
		{
			T0Count=0;
		}
}
*/