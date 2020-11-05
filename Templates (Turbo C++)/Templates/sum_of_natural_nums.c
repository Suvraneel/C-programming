#include <stdio.h>
#include <conio.h>


int addNumbers(int n);



int main ()
{
   //This program finds Sum of natural numbers//

	int num;
	printf ("Enter a positive integer :          ");
	scanf ("%d", &num);
	printf ("Sum = %d", addNumbers(num));

		printf ("			            ");
		printf ("			            ");
		printf ("			            ");
		printf (" Press any key to terminate program");


		printf ("						");
		printf ("						");
		printf ("						");

	getch();
	return 0;
}

int addNumbers(int n)
{
	if (n != 0)
		return n + addNumbers (n-1);
	else
		return n;
}
