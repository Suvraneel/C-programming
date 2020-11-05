#include <stdio.h>
#include <conio.h>

int main ()
{
    // This program yields value of factorials//

	int n, i;
	unsigned long long factorial = 1;

	printf("Enter an integer:      ");
	scanf ("%d", &n);

	if (n < 0)
		printf ("Error! Factorial of a negative number doesn't exist.");

	else
	{
		for (i = 1; i <= n; ++i)
		{
			factorial *= i;
		}
		printf ("Factorial of %d = %llu", n, factorial);

	}
		printf ("				");
		printf ("	     			");
		printf ("				");
		printf (" Press any key to terminate program");


		printf ("				");
		printf ("				");
		printf ("	      			");
	getch ();
	return 0;
    }
