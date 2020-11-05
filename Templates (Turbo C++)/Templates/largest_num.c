#include <stdio.h>
#include <conio.h>

int main ()
{
	//This program determines the largest number among the 3 provided ones//

	double no1, no2, no3 ;

	printf ("Enter 3 different numbers:      ");
	scanf ("%lf %lf %lf", &no1, &no2, &no3);

	if     (no1>=no2 && no1>=no3)
		printf ("%.2f is the largest number.", no1) ;

	if     (no2>=no1 && no2>=no3)
		printf ("%.2f is the largest number.", no2) ;

	if     (no3>=no1 && no3>=no2)
		printf ("%.2f is the largest number.", no3) ;

		printf ("		   	      ");
		printf ("	     	 	      ");
		printf ("			      ");
		printf (" Press any key to terminate program");


		printf ("				       ");
		printf ("				       ");
		printf ("	      			       ");


	getch ();
	return 0;

}
