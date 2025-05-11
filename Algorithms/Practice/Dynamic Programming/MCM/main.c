#include <stdio.h>
#include <limits.h>
#include <string.h>

int dp[1001][1001];

int solve(int arr[], int i, int j){
    // Base condition 
    if( i >= j){
        return 0;
    }

    // present or not 
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int min = INT_MAX;

    // Move k to j-1
    for(int k = i; k <= j-1; k++){
        int tempAns = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1] * arr[k] * arr[j];

        if(tempAns < min){
            min = tempAns;
        }
    }
    return dp[i][j]= min;
}

int main(){
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr)/ sizeof(arr[0]);
    memset(dp, -1, sizeof(dp));

    printf("cost: %d", solve(arr, 1, n-1));




    return 0;
}