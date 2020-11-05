#include <stdio.h>
#include <conio.h>

int main ()
{

	//This program checks whether the number entered is even or odd//

	int number ;

	printf ("Enter an integer:                 ");
	scanf ("%d", &number);

	if (number % 2 == 0)
		printf ("%d is even.", number);

	else
		printf ("%d is odd.", number);

	printf (" 					");
	printf ("					");
	printf (" Press any key to terminate program.");
	printf (" 			        ");
	printf ("			        ");

	getch ();
	return 0;
}
