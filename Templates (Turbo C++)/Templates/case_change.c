#include <stdio.h>
#include <conio.h>

int main ()
{
	char alp;
	printf ("Enter any alphabet.");
	scanf ("%c", &alp);
	printf("The character in Upper case is :");
	alp = alp - 32;
	printf ("%c \n \n", alp);
	printf ("Press any key to exit program. \n \nl");

	//COURTESY : el_diablo //

getch();
return 0;
}
