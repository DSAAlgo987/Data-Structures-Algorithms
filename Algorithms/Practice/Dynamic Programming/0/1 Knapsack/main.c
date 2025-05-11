#include <stdio.h>
#include <string.h>

#define MAX_ITEM 102
#define MAX_WT 1002

int dp[MAX_ITEM][MAX_WT];

int max(int a, int b){
    return (a  > b) ? a : b;
}

int Knapsack(int val[], int wt[], int n, int W){
    // Base condition 
    if(W == 0 || n == 0){
        return 0;
    }

    // Present or not ?
    if(dp[n][W] != -1){
        return dp[n][W];
    }

    // Choice diagram
    // If weight less than equal knapsack capacity 
    if(wt[n-1] <= W){
        // Include 
        int a = val[n-1] + Knapsack(val, wt, n-1 , W - wt[n-1]);

        // Exclude
        int b = Knapsack(val, wt, n-1 , W);

        return dp[n][W] = max(a,b);

    }else {
        // Exclude
        return dp[n][W] = Knapsack(val, wt, n-1, W);
    }
}

int main(){
    int val[] = {1, 4, 5, 7};
    int wt[] = {1, 3, 4, 5};
    int W = 7;

    int n = sizeof(wt) / sizeof(wt[0]);

    memset(dp, -1, sizeof(dp));

    printf("Max profit: %d", Knapsack(val, wt, n, W));

}