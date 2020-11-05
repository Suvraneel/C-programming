#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i, count[10];
    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
       int len = strlen(s);
        for (i = 0; i < 10; i++) {
            count[i] = 0;
        }
 
      for (i = 0; i < len; i++) {
            
          if (s[i] >= '0'  && s[i] <= '9') {
           count[(int)(s[i] - '0')]++ ;
        }

    }
    
    for (i = 0; i < 10; i++) {
    printf("%d ", count[i]);
    }
    
    return 0;
}
