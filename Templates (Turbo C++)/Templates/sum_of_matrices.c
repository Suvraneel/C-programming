#include <stdio.h>
#include <conio.h>

int main ()
{
	//This program finds sum of any 2 matrices of any order//
	//El Diablo's 1st program utilising ARRAYS//

	int r, c, a[100][100], b[100][100], sum[100][100], i, j;

	printf ("Enter number of rows (between 1 and 100) :      \n");
	scanf ("%d", &r);

	printf ("Enter number of columns (between 1 and 100):    \n");
	scanf ("%d", &c);

	printf ("You have selected sum for matrices of order %d X %d.\n", r, c);
	printf ("Press any key to continue.\n");
	getch ();

	for ( i = 0; i < r; ++i)
		for ( j = 0; j < c; ++j)
			{

			printf ("\n 1st matrix: \n");
			printf ("Enter the entry of a%d%d:    ", i+1, j+1);
			scanf ("%d", &a[i][j]);
			}

	for ( i = 0; i < r; ++i)
		for ( j = 0; j < c; ++j)
			{
			printf ("\n 2nd matrix: \n");
			printf ("Enter the entry of b%d%d:    ", i+1, j+1);
			scanf ("%d", &b[i][j]);
			}


	for ( i = 0; i < r; ++i)
		for ( j = 0; j < c; ++j)
			{
			sum[i][j] = a[i][j] + b[i][j] ;
			}

		printf ("\n Sum of above entered matrices is: \n");

		for ( i = 0; i < r; ++i)
		for ( j = 0; j < c; ++j)
			{
			printf ("%d   ", sum[i][j]);

			if (j == c - 1)
			printf (" \n \n ");
			}

printf (" Press any key to terminate program.\n\n\n");
getch ();
return 0;
}
