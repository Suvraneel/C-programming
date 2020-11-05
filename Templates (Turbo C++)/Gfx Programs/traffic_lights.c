#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>

int main()
{
	int gd = DETECT, gm, midx, midy;

	initgraph( &gd, &gm, "C:\\TURBOC3\\BGI");

	setcolor (CYAN);
	settextstyle (TRIPLEX_FONT, HORIZ_DIR, 5);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy (260, 200, "Traffic Light Simulation");
	getch ();

	setcolor(12);
	settextstyle (SCRIPT_FONT, HORIZ_DIR, 3);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy (400, 400, "Press any key to start simulation...");
	getch ();
	clrscr ();

	midx = getmaxx()/2;
	midy = getmaxy()/2;

	graphdefaults ();
	cleardevice();
	setcolor (BLUE);
	rectangle (midx-60, midy-150, midx+60, midy+150);
	rectangle (midx-65, midy-155, midx+65, midy+155);
	setfillstyle (HATCH_FILL, BLUE);
	floodfill (midx-62, midy-152, BLUE);

	setcolor (RED);
	circle (midx, midy-100, 40);
	setfillstyle (SOLID_FILL, RED);
	floodfill (midx, midy-100, RED);
	circle (midx, midy-100, 43);

	setcolor (BLUE);
	settextstyle (SANS_SERIF_FONT, HORIZ_DIR, 3);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy (midx, midy-100, "STOP");
	delay (2000);
	graphdefaults ();
	cleardevice();

	setcolor (BLUE);
	rectangle (midx-60, midy-150, midx+60, midy+150);
	rectangle (midx-65, midy-155, midx+65, midy+155);
	setfillstyle (HATCH_FILL, BLUE);
	floodfill (midx-62, midy-152, BLUE);

	setcolor (YELLOW);
	circle (midx, midy, 40);
	setfillstyle (SOLID_FILL, YELLOW);
	floodfill (midx, midy, YELLOW);
	circle (midx, midy, 44);

	setcolor (BLUE);
	settextstyle (SANS_SERIF_FONT, HORIZ_DIR, 3);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy (midx, midy, "READY");
	delay (2000);
	graphdefaults ();
	cleardevice();

	setcolor (BLUE);
	rectangle (midx-60, midy-150, midx+60, midy+150);
	rectangle (midx-65, midy-155, midx+65, midy+155);
	setfillstyle (HATCH_FILL, BLUE);
	floodfill (midx-62, midy-152, BLUE);

	setcolor (GREEN);
	circle (midx, midy+100, 40);
	setfillstyle (SOLID_FILL, GREEN);
	floodfill (midx, midy+100, GREEN);
	circle (midx, midy+100, 44);

	setcolor (BLUE);
	settextstyle (SANS_SERIF_FONT, HORIZ_DIR, 3);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy (midx, midy+100, "GO");
	delay (2000);
	graphdefaults ();
	cleardevice();

	setcolor (5);
	settextstyle (GOTHIC_FONT, HORIZ_DIR, 3);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy (300, 300, "Simulation by Suvraneel Bhuin...");
	getch();

	setcolor (WHITE);
	settextstyle (SCRIPT_FONT, HORIZ_DIR, 3);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy (400, 400, "Press any key to terminate simulation...");


getch ();
return 0;
}
