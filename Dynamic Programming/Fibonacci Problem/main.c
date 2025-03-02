#include <stdio.h>

int fibonacci(int n){
    if(n <= 1){ // base case
        return n;
    }
    
    int F[n+1];

    F[0] = 0; F[1] = 1;

    for(int i = 2; i <= n; i++){
        F[i] = F[i-2] + F[i-1];
    }

    return F[n];
}

int main(){
    int n;
    printf("Enter the no to find Fibonacci: ");
    scanf("%d", &n);

    int fibNo = fibonacci(n);

    printf("\n%d" , fibNo);

    return 0;
}