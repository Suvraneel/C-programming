#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void main ()
{
	int gdriver = DETECT, gmode;
	clrscr();

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");

	setcolor(CYAN);

	rectangle(100,100,200,200);
	getch();
	closegraph();
}
