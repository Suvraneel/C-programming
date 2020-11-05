#include <stdio.h>
#include <conio.h>

int main ()

{
       //This program performs all basic operations and acts as a simple calculator//

       char operator ;
       double firstno, secondno ;


	printf ("Enter required operation (among +,-,*,/)  :        ");
	scanf ("%c" , &operator) ;

		printf ("						");
		printf ("						");
		printf ("Enter the two operands :         ");
		scanf  ("%lf %lf", &firstno, &secondno);


	switch (operator)

		{

			case '+' :
				printf ("%.1lf + %.1lf  =  %.1lf", firstno, secondno, firstno + secondno);
				break ;



			case '-' :
				printf ("%.1lf -  %.1lf  =  %.1lf", firstno, secondno, firstno - secondno);
				break ;



			case '*' :
				printf ("%.1lf * %.1lf  =  %.2lf", firstno, secondno, firstno * secondno);
				break ;



			case '/' :
				printf ("%.1lf / %.1lf  =  %.2lf", firstno, secondno, firstno / secondno);
				break ;



			default :
				printf ("Error , Invalid operator entered !!! ");


			}

		printf ("						");
		printf ("						");
		printf ("						");
		printf (" Press any key to terminate program");


		printf ("						");
		printf ("						");
		printf ("						");



		getch () ;
		return 0 ;

	}
