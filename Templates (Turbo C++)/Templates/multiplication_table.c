#include <stdio.h>
#include <conio.h>

int main ()
{
   //This program prints the multiplication table for entered integer//

	int n, i;

	printf ("Enter an integer :      ");
	scanf ("%d", &n);

	for (i=1; i<= 10; ++i)
	{
		printf("%d * %d = %d   \n", n, i, n*i);
	}

		printf ("			            ");
		printf ("			            ");
		printf ("			            ");
		printf (" Press any key to terminate program");


		printf ("						");
		printf ("						");
		printf ("						");


	getch ();
	return 0;
}
