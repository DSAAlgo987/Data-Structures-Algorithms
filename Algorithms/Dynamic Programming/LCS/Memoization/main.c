#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001

/**
 * n <= 1001
 * m <= 1001
 */

int dp[MAX_LENGTH][MAX_LENGTH];


int max(int a,int b){
    return (a > b) ? a : b;
}

int LCS(char x[], char y[], int n , int m){
    // Base condition 
    if(n == 0 || m == 0){
        return 0;
    }
    
    // present or not 
    if(dp[n][m] != -1){
        return dp[n][m];
    }
    
    // Choice diagram
    if(x[n-1] == y[m-1]){
        dp[n][m] =  1 + LCS(x, y, n-1, m-1);
        
        return dp[n][m];
    }else {
        // choices
        int a = LCS(x, y, n, m-1);
        int b = LCS(x, y, n-1, m);
        return dp[n][m] = max(a, b);
    }
}

void PrintLCS(char x[], char y[], int n, int m){
    char lcs[MAX_LENGTH];
    int index = dp[n][m];
    
    lcs[index] = '\0';
    
    int i = n, j = m;
    
    while(i > 0 && j > 0){
        
        // char match
        if(x[i-1] == y[j-1]){
            lcs[index - 1] = x[i-1];
            i--; 
            j--;
            index--;
        }
        // Comapre diagonal elements of dp
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }else{
            j--;
        }
    }
    
    printf("\nLCS String: %s", lcs);
}

int main()
{
    char x[] = "abcdgh";
    char y[] = "abedfha";
    
    int n = strlen(x);
    int m = strlen(y);

    // Initialize dp as -1
    memset(dp, -1, sizeof(dp));
    
    printf("LCS Length: %d", LCS(x, y, n, m));
    
    PrintLCS(x, y, n, m);
    
    return 0;
}