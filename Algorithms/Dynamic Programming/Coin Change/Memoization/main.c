#include <stdio.h>

int minCoins(int amount , int A[] , int n,int dp[]){
    if(amount == 0){
        return 0;
    }
    
    if(dp[amount] != -1){
        return dp[amount];
    }

    int ans = 1000000;
    for(int i = 0; i < n; i ++){
        if(amount-A[i] >= 0){
            int subAns = minCoins(amount-A[i] , A , n, dp);
            
            if(subAns + 1 < ans){
                ans = subAns + 1;
            }
        }
    }
    return dp[amount] = ans;
}

int main() {
    int A[] = { 7 , 5 , 1};
    int n = sizeof(A) / sizeof(A[0]);
    int amount = 18;
    int dp[amount +1];

    // Initialize dp as -1
    for(int i = 0 ; i <=amount ;i++ ){
        dp[i] = -1;
    }
    dp[0] = 0; // For Amount 0 , 0 coins will be needed 
    printf("%d\n" , minCoins(amount, A, n, dp));

    for(int i = 0 ; i <= amount; i++){
        printf("%d ",dp[i]);
    }
    return 0;
}