#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n, a, b, c, d, e, sum;
    scanf("%d", &n);
    a = n/10000;
    b = (n%10000)/1000;
    c = ((n%10000)%1000)/100;
    d = (((n%10000)%1000)%100)/10;
    e = ((((n%10000)%1000)%100)%10);
    sum = (a + b + c + d + e);
    printf ("%d",sum);
    //Complete the code to calculate the sum of the five digits on n.
    return 0;
}
