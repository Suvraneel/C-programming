#include <stdio.h>
#include <conio.h>

int main ()
{
	int a[1000], i, num, min, max, mean;
	printf ("Enter size of the array.\t");
	scanf ("%d", &num);
	printf("Enter the array elements :\t");

	for (i=0; i<num; i++)
	{ scanf ("%d", &a[i]);
	}

	min = a[0];
	for (i=0; i<num; i++)
	{ if (min > a[i])
		{min = a[i];}
	}

	max = a[0];
	for (i=0; i<num; i++)
	{ if (max < a[i])
		{max = a[i];}
	}

	mean = (min + max)/2;


	printf ("The mean of minimum and maximum elements of the array is: \t %d \n", mean);

getch();
return 0;
}
