#include <REGX51.H>
#include <INTRINS.h>

sbit buzzer=P1^3;

void Delay500us(void)	//@11.0592MHz
{
	unsigned char data i;

	_nop_();
	i = 227;
	while (--i);
}

void Buzzer_Time(unsigned int (x))
{
	unsigned int j;
	for (j=0;j<x*2;j++)
	{
		buzzer=!buzzer;
		Delay500us();
		
	}
}