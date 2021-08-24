#include <stdio.h>

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  

int max(int a, int b){
    if (a<=b) return b;
    return a;
}

int min(int a, int b){
    if(a<=b) return a;
    return b;
}

int distribute(int arr[], int n)  
{  
    int a = 0;
    int b = 0;
    for (int i=n-1; i >= 0; i--){
    if (min(a, b)==a)
    a += arr[i];
    else if (min(a, b)==b)
    b += arr[i];
    }
    return a;
}

int main() {
    int t, n, res;
	scanf("%d", &t);
	while (t--){
	    scanf("%d", &n);
	    int d[n];
	    int i=0;
	    while (n--){
	        scanf("%d", &d[i]);
	        printf("%d ", d[i]);
	        i++;
	    }
	    
	bubbleSort(d, n);
	res = distribute(d, n);
    printf("\n%d\n", res);
	}
	return 0;
}
