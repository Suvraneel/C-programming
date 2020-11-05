#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main ()
{
	int gd = DETECT, gm;    int i;
	initgraph (&gd, &gm, "c:\\TURBOC3\\BGI");
	clrscr ();

	for (i=0; i < 300; ++i)
	{
		setcolor(i);
		circle(300,250,50+i);
		delay (30);
		cleardevice();
	}
	getch();
	closegraph();
}
