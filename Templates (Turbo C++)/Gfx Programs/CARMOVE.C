#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

int main ()
{
	int i, j, gd = DETECT, gm;
	initgraph(&gd, &gm, "c:\\TURBOC3\\BGI");
	clrscr ();

	for (i=0; i<=500; ++i)
	{       setcolor (RED);
		line ( 60+i, 300, 80+i, 250 );
		line ( 200+i, 300,180+i, 250 );
		line ( 80+i, 250, 180+i, 250 );

		setcolor (RED);
		rectangle (60+i,300,240+i,350 );
		setfillstyle (SOLID_FILL, RED);
		floodfill (200+i, 325, RED);

		setcolor (BLUE);
		circle (100+i, 350, 20);
		circle (200+i, 350, 20);
		setfillstyle (SOLID_FILL, BLUE);
		floodfill (100+i, 350, BLUE);
		floodfill (200+i, 350, BLUE);

		setcolor (BLUE);
		rectangle (80+i, 265, 125+i, 290);
		setfillstyle (SLASH_FILL, BLUE);
		floodfill (120+i, 275, BLUE);

		setcolor (BLUE);
		rectangle (135+i, 265, 180+i, 290);
		setfillstyle (SLASH_FILL, BLUE);
		floodfill (170+i, 275, BLUE);

		setcolor(YELLOW);
		circle (240+i, 315, 5);
		setfillstyle(SOLID_FILL,YELLOW);
		floodfill(241+i, 315, YELLOW);

		setcolor(CYAN);
		settextstyle(SCRIPT_FONT,HORIZ_DIR,2);
		outtextxy(20,447,"Moving Car project by     ");

		setcolor(10);
		settextstyle(GOTHIC_FONT,HORIZ_DIR,2);
		outtextxy(240,451,"Suvraneel Bhuin");

		delay(10);
		cleardevice();
	}
	getch ();
	closegraph();
	return 0;
 }