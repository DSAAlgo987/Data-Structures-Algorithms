#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Coin Change II (MN # of coins)  
 * Problem: 
 * 
 * IP: vector<int> coins, int sum; 
 * OP: Return min # of coins 
 * APPROACH: Top down/ Memoization 
 * TC: O(n * sum) 
 * SC: O(n * sum) 
 * LEARNING: 
 *  - IF you get stuck in tabular then make it in memoize
 *  - How it can be converted into tabular 
 *  - How it is similar to unbounded knapsack 
 */

// Aliases 
using v = vector<int>; 
using vv = vector<v>; 


// Coin Change II 
int coinChange(v &coins, int sum, int n, vv &t) { 
    // BC 
    if(sum == 0) { 
        return 0;  
    }
    if(n == 0) { 
        return INT_MAX - 1;
    }

    // Present or not 
    if(t[n][sum] != -1) return t[n][sum]; 

    // Choice Diagram 
    if(coins[n-1] <= sum) { 
        return t[n][sum] = min( 
            1 + coinChange(coins, sum - coins[n-1], n, t), 
                coinChange(coins, sum, n - 1, t)
        );
    } 
    return t[n][sum] = coinChange(coins, sum, n - 1, t);
}

int main(){
    v coins = {1, 2, 3}; 
    int sum = 5; 
    int n = coins.size(); 
    vv t(n + 1, v(sum + 1, -1));

    cout << "MN # of coins: " << coinChange(coins, sum, n, t);
    
    return 0;
}