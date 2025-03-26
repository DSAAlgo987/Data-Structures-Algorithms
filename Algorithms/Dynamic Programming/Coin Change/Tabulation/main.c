#include <stdio.h>
#define I 1000000

int minCoins( int coins[], int n, int w){
    int dp[w+1];
    
    // Initialize DP as Infinity
    for(int i = 0 ;i <= w ; i++){
        dp[i] = I;
    }

    dp[0] = 0; // Base case: 0 Coins required for amount 0

    // Fill table using given coins 
    for(int i = 0; i < n ; i++){    // For each coins 
        for(int j = coins[i] ; j <= w; j++){ // For each amount from coin to w
            if(dp[j - coins[i]] != I){ // If amount is possible 
                // Select the min coins 
                int sum = 1 + dp[j- coins[i]];
                dp[j] = (dp[j] < sum) ? dp[j] : sum;
            }
        }
    }
    
    return (dp[w] == I)? -1 : dp[w]; // If dp is I, return -1 (not possible)
}

int main(){
    // int coins[] = {1, 5, 6, 9};
    // int coins[] = {7, 5, 1};
    int coins[] = {1};
    int n = sizeof(coins) / sizeof(coins[0]);
    int w = 0;

    int ans = minCoins(coins, n, w);
    if(ans == -1){
        printf("No possible way to form amount.\n");
    }else{
        printf("Minimum coins required: %d\n", ans);
    }

    return 0;
}