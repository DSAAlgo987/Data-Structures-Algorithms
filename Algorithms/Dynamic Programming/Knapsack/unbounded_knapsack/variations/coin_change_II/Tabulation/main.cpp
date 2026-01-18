#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Coin Change II (Minimum Number of Coins)
 *
 * Problem:
 *   Given a set of coin denominations and a target sum,
 *   find the minimum number of coins required to make
 *   the given sum.
 *   Each coin can be used unlimited times.
 *
 * IP:
 *   - vector<int> coins → available coin denominations
 *   - int sum           → target sum
 *
 * OP:
 *   - int → minimum number of coins required
 *     (if not possible, result will be large / INF)
 *
 * APPROACH:
 *   - Dynamic Programming (Bottom-Up / Tabulation)
 *   - This is an Unbounded Knapsack problem
 *   - For every coin, we have two choices:
 *       1. Include the coin (stay on same index)
 *       2. Exclude the coin (move to previous coins)
 *
 * DP STATE:
 *   - t[i][j] → minimum number of coins required
 *               to make sum j using first i coins
 *
 * INITIALIZATION:
 *   - t[0][0] = 0        → 0 coins needed to make sum 0
 *   - t[0][j] = INF      → impossible to make sum > 0 with 0 coins
 *
 * TRANSITION:
 *   if (coins[i-1] <= j):
 *       t[i][j] = min(
 *           1 + t[i][j - coins[i-1]],  // include coin (unbounded)
 *           t[i-1][j]                  // exclude coin
 *       )
 *   else:
 *       t[i][j] = t[i-1][j]
 *
 * TC:
 *   - O(n × sum)
 *
 * SC:
 *   - O(n × sum)
 *
 * LEARNING:
 *   - Difference between "count of ways" and "minimum coins"
 *   - Why base case sum = 0 returns 0 (0 coins needed)
 *   - How impossible states are handled using INF
 *   - Clear understanding of Unbounded Knapsack pattern
 *   - Strong DP pattern recognition
 */


// Aliases 
using v = vector<int>; 
using vv = vector<v>; 

int coinChange(vector<int> &coins, int sum){
    int n = coins.size(); 

    // Step 1: DP Table 
    vv t(n + 1, v(sum + 1, 0)); // Initially, INIT with 0 

    // Step 2: Initialization, t[0][1->sum] = INF 
    for(int j = 1; j < sum + 1; j++) 
        t[0][j] = INT_MAX - 1; 

    // Step 3: Start filling, i = 1, j = 1;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < sum + 1; j++) {
            if(coins[i-1] <= j) {
                t[i][j] = min(
                    1 + t[i][j - coins[i-1]], 
                    t[i-1][j]
                ); 
            } else {
                t[i][j] = t[i-1][j]; 
            }
        }
    }

    // Step 4: Return the final ans 
    return t[n][sum];
}

int main(){
    vector<int> coins = {1, 2, 3};
    int sum = 5;

    cout << coinChange(coins, sum) << endl;
    
    return 0;
}