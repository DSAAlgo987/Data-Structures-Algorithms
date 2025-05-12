#include <stdio.h>
#include <string.h>

int dp[1001][1001];

int max(int a, int b){
    return (a > b) ? a : b;
}

int LCS(char x[], char y[], int n, int m){
    // Base condition 
    if(n == 0 || m == 0){
        return 0;
    }

    // Present or not 
    if(dp[n][m] != -1){
        return dp[n][m];
    }

    // Choice diagram
    // If char matches 
    if(x[n-1] == y[m-1]){
        return dp[n][m]= 1 + LCS(x, y, n-1, m-1);
    }
    // not matches
    else{
        int a = LCS(x, y, n, m-1);
        int b = LCS(x, y, n-1, m);
        return dp[n][m] = max(a, b);
    }
}

void printLCS(char x[], char y[], int n, int m){
    char lcs[1001];

    int index = dp[n][m];

    lcs[index] = '\0';
    int i = n , j = m;

    while( i > 0 && j > 0){
        if(x[i - 1] == y[j - 1]){
            lcs[index -1] = x[i - 1];
            i--;
            j--;
            index--;
        }else if(dp[i-1][j] > dp[i][j-1] ){
            i--;
        }else {
            j--;
        }
    }
    printf("\nLCS string: %s", lcs);
}

int main(){
    char x[] = "abcdgh";
    char y[] = "abedfgr";

    int n = strlen(x);
    int m = strlen(y);

    memset(dp, -1, sizeof(dp));
    printf("LCS Len: %d", LCS(x, y, n, m));

    printLCS(x, y, n, m);

    return 0;
}