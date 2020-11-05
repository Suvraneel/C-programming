#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.

int find_nth_term(int n, int a, int b, int c) {
    int i;
    int s[n-1]; 
    s[0] = a;
    s[1] = b;
    s[2] = c;
    for (i = 3; i<= n-1; i++) {
    s[i]= s[i-1] + s[i-2] + s[i-3];
    }
    return s[n-1];
}

int main() {
    int n, a, b, c;
  
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d", ans); 
    return 0;
}
