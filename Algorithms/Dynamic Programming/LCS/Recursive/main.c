#include <stdio.h>
#include <string.h>

int max(int a,int b){
    return (a > b) ? a : b;
}

int LCS(char x[], char y[], int n , int m){
    // Base condition 
    if(n == 0 || m == 0){
        return 0;
    }
    
    // Choice diagram
    if(x[n-1] == y[m-1]){
        return 1 + LCS(x, y, n-1, m-1);
    }else {
        // choices
        int a = LCS(x, y, n, m-1);
        int b = LCS(x, y, n-1, m);
        return max(a, b);
    }
}

int main()
{
    char x[] = "abcdgh";
    char y[] = "abedfha";
    
    int n = strlen(x);
    int m = strlen(y);
    
    printf("LCS Length: %d", LCS(x, y, n, m));
    
    return 0;
}