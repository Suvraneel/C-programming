#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

int main ()
{
	int midx, midy, i, j, roof, floor, rtwall, ltwall, gd = DETECT, gm;
	initgraph ( &gd, &gm, "C:\\TURBOC3\\BGI");

	midx   = getmaxx()/2    ;
	midy   = getmaxy()/2    ;
	roof   = -200+20    ;
	floor  = +200-20    ;
	rtwall = +300-20    ;
	ltwall = -300+20    ;

	setcolor(YELLOW);
	settextstyle (TRIPLEX_FONT, HORIZ_DIR, 5);
	settextjustify (CENTER_TEXT, CENTER_TEXT);
	outtextxy ( midx, midy, "BOUNCING BALL SIMULATION");

	setcolor(CYAN);
	settextstyle (GOTHIC_FONT, HORIZ_DIR, 3);
	settextjustify (CENTER_TEXT, CENTER_TEXT);
	outtextxy ( midx+80, midy+50, "by Suvraneel Bhuin");



	getch ();
	clrscr();

	graphdefaults();
	cleardevice ();

	// movement for bounce motion //
	for ( i=0, j=0; i<= rtwall && j<= floor; ++i, ++j)
	{
		setcolor (15);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (5);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 5);
		floodfill (midx+i, midy+j, 5);
		delay (10);
		cleardevice();
	}

	LOOP:
	//floor collision//
	for ( j= floor ; i<= rtwall && j>= roof; ++i, --j)
	{
		setcolor (5);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (3);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 3);
		floodfill (midx+i, midy+j, 3);
		delay (10);
		cleardevice();
	}

	//rtwall collision//
	for ( i=rtwall; i>= ltwall && j>= roof; --i, --j)
	{       setcolor (3);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (1);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 1);
		floodfill (midx+i, midy+j, 1);
		delay (10);
		cleardevice();
	}

	//roof collision//
	for ( j=roof; i>= ltwall && j<= floor; --i, ++j)
	{       setcolor (1);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (2);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 2);
		floodfill (midx+i, midy+j, 2);
		delay (10);
		cleardevice();
	}

	//ltwall collision//
	for ( i=ltwall; i<= rtwall && j<= floor; ++i, ++j)
	{
		setcolor (2);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (14);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 14);
		floodfill (midx+i, midy+j, 14);
		delay (10);
		cleardevice();
	}

	//floor collision2//
	for ( j= floor ; i<= rtwall && j>= roof; ++i, --j)
	{
		setcolor (14);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (12);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 12);
		floodfill (midx+i, midy+j, 12);
		delay (10);
		cleardevice();
	}

	//roof collision2//
	for ( j=roof; i<= rtwall && j<= floor; ++i, ++j)
	{
		setcolor (12);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (4);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 4);
		floodfill (midx+i, midy+j, 4);
		delay (10);
		cleardevice();
	}

	//rtwall collision2//
	for ( i=rtwall; i>= ltwall && j<= floor; --i, ++j)
	{
		setcolor (4);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (6);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 6);
		floodfill (midx+i, midy+j, 6);
		delay (10);
		cleardevice();
	}

	//floor collision3//
	for ( j= floor ; i>= ltwall && j>= roof; --i, --j)
	{
		setcolor (6);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (9);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 9);
		floodfill (midx+i, midy+j, 9);
		delay (10);
		cleardevice();
	}


	//ltwall collision2//
	for ( i=ltwall; i<= rtwall && j>= roof; ++i, --j)
	{
		setcolor (9);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (13);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 13);
		floodfill (midx+i, midy+j, 13);
		delay (10);
		cleardevice();
	}

	//roof collision3//
	for ( j=roof; i<= rtwall && j<= floor; ++i, ++j)
	{
		setcolor (13);
		line ( midx-300, midy-200, midx+300, midy-200);
		line ( midx-300, midy+200, midx+300, midy+200);
		line ( midx-300, midy-200, midx-300, midy+200);
		line ( midx+300, midy-200, midx+300, midy+200);

		setcolor (5);
		circle ( midx+i, midy+j, 20);
		setfillstyle(SOLID_FILL, 5);
		floodfill (midx+i, midy+j, 5);
		delay (10);
		cleardevice();
	}

	//goto LOOP;
	//Remove (//) from above command line to make the program continuous...

	getch ();
	closegraph();
	return 0;
}
