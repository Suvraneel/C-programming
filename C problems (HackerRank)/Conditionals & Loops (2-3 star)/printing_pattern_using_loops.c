#include <stdio.h>

int min (int n, int i, int j, int last){
    int k;
    if (i <= j && i <= last-i && i<= last-j) {
    k = i;
    }
    if (j <= i && j <= last-i && j<= last-j) {
    k = j;
    }
    if (last-i <= i && last-i <= j && last-i<= last-j) {
    k = last-i;
    }
    if (last-j <= i && last-j <= j && last-j<= last-i) {
    k = last-j;
    }
    return k;    
}

int main (){
    int n, i, j;
    scanf("%d", &n);
    int last = 2*n-2;

    for (i = 0; i <= last; i++ ) {
        for (j = 0; j <= last; j++) {

            if (min( n, i, j, last) == i) {
            printf("%d ", n-i);
            }
            else if (min( n, i, j, last) == j) {
            printf("%d ", n-j);
            }
            else if (min( n, i, j, last) == last-i) {
            printf("%d ", n-last+i);
            }
            else if (min( n, i, j, last) == last-j) {
            printf("%d ", n-last+j);
            }            
            if (j==last) {
            printf("\n");
            }
        }
    }
    return 0;
}
