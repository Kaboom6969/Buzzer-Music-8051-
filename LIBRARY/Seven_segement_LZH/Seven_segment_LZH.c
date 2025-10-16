#include <REGX51.H>
void seven_write (unsigned int(x))
{
	if (x > 16)
	{
		x= x-(16*(x/16));
	}
	if (x == 0)
	{
		P0 = 0xC0;
	}
	if (x == 1)
	{
		P0 = 0xF9;
	}
	if (x == 2)
	{
		P0 = 0xA4;
	}
	if (x == 3)
	{
		P0 = 0xB0;
	}
	if (x == 4)
	{
		P0 = 0x99;
	}
	if (x == 5)
	{
		P0 = 0x92;
	}
	if (x == 6)
	{
		P0 = 0x82;
	}
	if (x == 7)
	{
		P0 = 0xF8;
	}
	if (x == 8)
	{
		P0 = 0x80;
	}
	if (x == 9)
	{
		P0 = 0x90;
	}
	if (x == 10) //A
	{
		P0 = 0x88;
	}
	if (x == 11) //b
	{
		P0 = 0x83;
	}
	if (x == 12) //C
	{
		P0 = 0xC6;
	}
	if (x == 13) //d
	{
		P0 = 0xA1;
	}
	if (x == 14) //E
	{
		P0 = 0x86;
	}
	if (x == 15) //F
	{
		P0 = 0x8E;
	}
	if (x == 16) //0
	{
		P0 = 0xC0;
	}

	
}

void seven_clear()
{
	P0 = 0xFF;
}
