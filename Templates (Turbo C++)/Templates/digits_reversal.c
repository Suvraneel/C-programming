#include <stdio.h>
#include <conio.h>

int main()
{
	int no, x, y, z, newno;
	printf ("Enter any 3 digit number.");
	scanf("%d", &no);
	x = no/100       ;
	y = (no%100)/10  ;
	z = (no%100)%10  ;
	newno = x + 10*y + 100*z ;
	printf ("New number after reversal of digits = %d.\n\n",newno);
	getch ();
	return 0;
}
