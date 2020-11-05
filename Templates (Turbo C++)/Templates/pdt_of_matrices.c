#include <stdio.h>
#include <conio.h>

int main ()
{
	//This program finds product of any 2 matrices of any order//
	//El Diablo's 2nd program utilising ARRAYS//

	int a[10][10], b[10][10], pdt[10][10], i, j, k, r1, r2, c1, c2;

	token :
	printf ("Enter number of rows and columns (between 1 and 10) :      \n");
	scanf ("%d %d", &r1, &c1);

	printf ("Enter number of rows and columns (between 1 and 10):    \n");
	scanf ("%d %d", &r2, &c2);

		if ( c2 != r1 )				//Error Handling (using goto)
		{
		printf ("Error! The no. of rows of 1st matrix is not equal to the no. of columns of 2nd matrix \n");
		goto token ;
		}

	printf ("Press any key to continue.\n");
	getch ();
	//display user requested operation
	for ( i = 0; i < r1; ++i)
		for ( j = 0; j < c1; ++j)
			{
			printf ("\n 1st matrix: \n");
			printf ("Enter the entry of a%d%d:    ", i+1, j+1);
			scanf ("%d", &a[i][j]);
			}

	for ( i = 0; i < r2; ++i)
		for ( j = 0; j < c2; ++j)
			{
			printf ("\n 2nd matrix: \n");
			printf ("Enter the entry of b%d%d:    ", i+1, j+1);
			scanf ("%d", &b[i][j]);
			}		
	for ( i = 0; i < r1; ++i)			//initialisation (optional)
		for ( j = 0; j < c2; ++j)
		{
			pdt[i][j] = 0;
		}
	//matrix pdt fx
	for ( i = 0; i < r1; ++i)
		for ( j = 0; j < c2; ++j)
			for ( k = 0; k < c1; ++k)
			{
			pdt[i][j] += a[i][k] * b[k][j] ;
			}

	//print
	printf ("\n Product of above entered matrices is: \n");

	for ( i = 0; i < r1; ++i)
		for ( j = 0; j < c2; ++j)
		{
			printf ("%d   ", pdt[i][j]);

			if (j == c1 - 1)
			printf (" \n \n ");
		}

printf ("\n Press any key to terminate program.\n\n\n");
getch ();
return 0;
}
