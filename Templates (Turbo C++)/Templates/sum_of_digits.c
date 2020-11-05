#include <stdio.h>
#include <conio.h>

int main()
{
	int no;
	printf ("Enter any 3 digit number.");
	scanf("%d", &no);
	int x = no/100       ;
	int y = (no%100)/10  ;
	int z = (no%100)%10  ;
	int sumd = x + y + z ;
	printf ("Sum of the 3 digits of the entered number is = %d.\n\n",sumd);
	getch ();
	return 0;
}
