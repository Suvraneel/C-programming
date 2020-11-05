#include <stdio.h>
#include <conio.h>
#include <math.h>

int main ()

{
	//This program determines root(s) for any given quadratic equation//

	double a, b, c, discriminant, root1, root2, realpart, imgpart;

	printf ("Enter the coefficients a, b, and c of the quadratic equation:     ");
	scanf ("%lf %lf %lf", &a,&b,&c);

	discriminant = b*b - 4*a*c ;

	if     (discriminant > 0)
	{
	root1 = (-b+sqrt(discriminant))/(2*a);
	root2 = (-b-sqrt(discriminant))/(2*a);

	printf ("First root=%.2lf and Second root=%.2lf", root1, root2);
	}

	else if (discriminant == 0)
	{
		root1=root2= -b/(2*a) ;
		printf ("First root = Second root = %.2lf", root1 );
	}

	else
	{
		realpart = -b/(2*a);
		imgpart = sqrt(-discriminant)/(2*a);
		printf ("root1 = %.2lf + %.2lf i and root2 = %.2lf - %.2lf i ", realpart, imgpart, realpart, imgpart);
	}

		printf ("					");
		printf ("					");
		printf ("					");
		printf (" Press any key to terminate program");


		printf ("					");
		printf ("				        ");
		printf ("			     	        ");

	getch ();
	return 0;
}
