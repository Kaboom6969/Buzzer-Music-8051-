#include <REGX52.H>
#include <delay.h>
extern unsigned int bpm;
extern unsigned int tempo;
void led_light(unsigned int (x))
{
		P1=0xFF<<x;
		P3=0xFF<<0;
		if (x >= 8)
		{
			P3=0xFF<<(x-8);
			P1=0xFF<<x;
		}
		delay((bpm*tempo)*(0.05));
		P1=0xFF;
		P3=0xFF;
		delay((bpm*tempo)*(0.05));
		P1=0xFF<<x;
		P3=0xFF<<0;
		if (x >= 8)
		{
			P3=0xFF<<(x-8);
			P1=0xFF<<x;
		}
}
