#include <stdio.h>
#include <limits.h>
#include <string.h>

/**
 *  n <= 1000 
 */
int dp[1001][1001];
int bracket[1001][1001]; // to store split point

int solve(int arr[], int i, int j){
    // Base condition
    if(i >= j){
        return 0;
    }
    
    // Presnet or not 
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int min = INT_MAX;
    // k loop
    for(int k = i; k <= j-1; k++){
        // temp ans 
        int tempAns = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];
        
        // Idenitfy min cost from temp ans 
        if(tempAns < min){
            min = tempAns;
            bracket[i][j]= k;
        }
    }
    
    return dp[i][j] = min;
}

void printParenthesis(int i, int j, char *name){
    // base condition 
    if(i == j){
        printf("%c", (*name)++);
        return;
    }
    printf("(");
    printParenthesis(i, bracket[i][j], name);
    printParenthesis(bracket[i][j] + 1, j, name);
    printf(")");
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Initialize dp as -1 
    memset(dp, -1, sizeof(dp));
    printf("Min Cost: %d", solve(arr, 1, n-1));

    char name = 'A';
    printf("Optimal Parenthesization: \n");
    printParenthesis(1, n - 1, &name);
    printf("\n");


    return 0;
}