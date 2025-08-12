#include <stdio.h>
#define MAX_ITEMS 102
#define MAX_WEIGHT 1002
// constraints
/**
 * n <= 100
 * W <= 1000
 */


// static Dp
int dp[MAX_ITEMS][MAX_WEIGHT];


// Initialize DP as -1 
void init_dp() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        for (int j = 0; j < MAX_WEIGHT; j++) {
            dp[i][j] = -1;
        }
    }
}


int max(int a , int b){
    return (a > b )? a : b;
}



int knapsack(int wt[], int val[], int W, int n){
    // base conditioni 
    if(n == 0 || W == 0){
        return 0;   
    }
    
    // Dp present or not ? 
    if(dp[n][W] != -1){
        return dp[n][W];
    }
    
    // choice diagram 
    if(wt[n-1] <= W){
        // include 
        int a = val[n-1] + knapsack(wt, val, W-wt[n-1], n-1);
        // exclude
        int b = knapsack(wt, val, W, n-1);
        
        dp[n][W] = max(a, b);
        
        return dp[n][W];
    }
    
    if(wt[n-1] > W){
        dp[n][W] = knapsack(wt, val, W, n-1);
        
        return dp[n][W];
    }
}


int main(){
    
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    
    int n = sizeof(wt) / sizeof(wt[0]);
    
    
    init_dp();
    printf("Max Profit: %d", knapsack(wt, val, W, n));
    return 0;
}