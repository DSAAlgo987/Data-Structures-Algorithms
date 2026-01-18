#include <bits/stdc++.h>
using namespace std; 

/**

* PS: Coin Change I (Count Maximum Number of Ways)
*
* Problem:
* Given a set of coin denominations and a target sum,
* determine the total number of distinct ways to
* make the sum using unlimited coins.
*
* IP:
* * vector<int> coin → available coin denominations
* * int sum          → target sum
*
* OP:
* * int → total number of valid combinations
*
* APPROACH:
* Bottom-Up Dynamic Programming (Tabulation)
*
* TC:
* * O(n * sum)
*
* SC:
* * O(n * sum)
*
* VARIATION:
* * Subset Sum (Count)
* * Unbounded Knapsack
*
* KEY IDEA:
* * Each coin can be used multiple times.
* * Order of coins does NOT matter (combinations).
* * When a coin is chosen, stay on the same index to allow reuse.
*
* LEARNING:
* * Identified Coin Change as an Unbounded Knapsack problem.
* * Reused Subset Sum (count) DP pattern with slight modification.
* * Understood the importance of problem mapping.
* * Reinforced the habit of reducing new problems to already solved DP patterns.
  */

// Aliases 
using v = vector<int>; 
using vv = vector<v>; 

// Coin Change I 
int coinChange(v &coin, int sum) {
    int n = coin.size(); 

    // Step 1: DP Table 
    vv t(n + 1, v(sum + 1, 0)); // Initially, INIT with 0 

    // Step 2: Initialization, t[i][0] = 1; 
    for(int i = 0; i < n + 1; i++) 
        t[i][0] = 1; 

    // Step 3: Start filling, i = 1, j = 1; 
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < sum + 1; j++) {
            if(coin[i-1] <= j) {
                t[i][j] = t[i][j-coin[i-1]] + t[i-1][j]; // Here # possible ways 
            } else {
                t[i][j] = t[i-1][j]; 
            }
        }
    }

    // Step 4: Return final ans 
    return t[n][sum]; 
}


int main() { 
    v coin = {1, 2, 3};
    int sum = 5; 

    cout << "Mx # of ways: " << coinChange(coin, sum) << endl; 

    return 0;
}