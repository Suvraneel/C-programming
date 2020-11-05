#include <graphics.h>
#include <stdio.h>
#include <conio.h>

void main ()
{
	int gdriver = DETECT, gmode;
	int x1 = 200, y1 = 200;
	int x2 = 300, y2 = 300;
	clrscr();

	initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
	line(x1, y1, x2, y2);
	getch();
	closegraph();
}
