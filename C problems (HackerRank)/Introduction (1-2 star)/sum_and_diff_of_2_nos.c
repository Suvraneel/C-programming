#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int a, b;
    float c, d;
    scanf("%d %d", &a, &b);
    scanf("%f %f", &c, &d);
    int sumi = a+b ;
    int diffi = a-b ;
    float difff = c-d ;
    float sumf = c+d ;
    printf ("%d %d \n", sumi, diffi);
    printf("%.1f %.1f", sumf, difff);
	
    
    return 0;
}
