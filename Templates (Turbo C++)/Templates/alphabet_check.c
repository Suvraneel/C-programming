#include <stdio.h>
#include <conio.h>

int main()
{
	//This program determines whether the entered character is an alphabet //

	char c ;
	printf ("Enter a character:      ");
	scanf ("%c", &c);

	if ( (c>= 'a' && c<= 'z')  || (c>= 'A'  && c<= 'Z' ))
		printf ("%c is an alphabet.",c);

	else
		printf ("%c is not an alphabet.",c);

		printf ("				");
		printf ("	     			");
		printf ("				");
		printf (" Press any key to terminate program");


		printf ("				");
		printf ("				");
		printf ("	      			");


	getch () ;
	return 0  ;
}
