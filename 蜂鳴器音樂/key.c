#include <REGX51.H>
#include <delay.h>
#include <LED_LIGHT_LZH.h>
extern unsigned char FreqSelect;
unsigned int bpm;
unsigned int tempo;
unsigned int lowest;
int pitch;
int variable_bpm;
sbit buzzer=P1^3;
void key(unsigned int(x),unsigned int(y)) 
{
		TR0=1;
		tempo=y;
	if (P2_7 ==0) //if P2_7 ==0, P2_1 and P2_0 will change the pitch
	{
	  if (P2_1 == 0)
		{	
			TR0=0;
			while(P2_1 == 0);
			if (P2_1 == 1)
			{
				delay(25);
				pitch++;
				TR0=1;
				goto loop;
			}
		}	
		if (P2_0 == 0)
		{	
			TR0=0;
			while(P2_0 == 0);
			if (P2_0 == 1)
			{
				delay(25);
				pitch--;
				TR0=1;
				goto loop;
			}
		}
	}
	
		if (P2_6 == 0) //if P2_6 ==0, P2_1 and P2_0 will change the bpm
		{
				  if (P2_1 == 0)
		{	
			TR0=0;
			while(P2_1 == 0);
			if (P2_1 == 1)
			{
				delay(25);
				variable_bpm--;
				bpm=bpm-variable_bpm;
				TR0=1;
				goto loop;
			}
		}	
		if (P2_0 == 0)
		{	
			TR0=0;
			while(P2_0 == 0);
			if (P2_0 == 1)
			{
				delay(25);
				variable_bpm++;
				bpm=bpm+variable_bpm;
				TR0=1;
				goto loop;
			}
		}
		}
		loop:
		FreqSelect= (x+12+pitch);
		led_light(((x+12+pitch)-(lowest)));
		delay((bpm*tempo)*(0.95));
		TR0=0;
		delay((bpm*tempo)*(0.05));
		TR0=1;
}

void stop(unsigned int(z))
{
	TR0=0;
	led_light(0);
	tempo=z;
	delay(bpm*tempo);
}

void bpm_set(unsigned int(bpm_num))//This one is wrong word,the real meaning is 1/8 beat's time
{
	bpm=bpm_num;
}

void lowest_set(unsigned int(low))
{
	lowest=low+12+pitch;
}