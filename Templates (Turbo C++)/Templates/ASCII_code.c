#include <stdio.h>
#include <conio.h>
int main ()
{
	//This program determines the ASCII value for any character entered.//


	char randomcharacter ;
	printf ("Enter a character:        ");
	scanf ("%c", &randomcharacter);

	printf ("ASCII value of %c  =     %d ", randomcharacter, randomcharacter);
	printf ("                                        ");
	printf ("                                        ");
	printf ("Press any key to exit program");

	//COURTESY : el_diablo //

	getch ();
	return 0;

}
