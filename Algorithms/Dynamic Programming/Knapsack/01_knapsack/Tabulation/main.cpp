#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: 0/1 Knapsack Problem
 *
 * Problem:
 *   Given N items, each having a weight and a value,
 *   put items into a knapsack of capacity W such that
 *   the total value is maximized.
 *   Each item can be taken at most once (0/1 choice).
 *
 * IP:
 *   - vector<int> wt   → weights of items
 *   - vector<int> val  → values of items
 *   - int W            → knapsack capacity
 *   - int n            → number of items
 *
 * OP:
 *   - Maximum achievable profit (int)
 *
 * APPROACH:
 *   - Dynamic Programming (Bottom-Up / Tabulation)
 *   - Build the solution iteratively using a DP table
 *   - For every item i and capacity j, we have two choices:
 *       1. Include the item (if wt[i-1] ≤ j)
 *       2. Exclude the item
 *   - Choose the option that gives maximum profit
 *
 * DP STATE:
 *   - t[i][j] → maximum profit using first i items
 *               with knapsack capacity j
 *
 * BASE CASE (Initialization):
 *   - t[0][j] = 0  → No items → no profit
 *   - t[i][0] = 0  → Zero capacity → no profit
 *
 * TRANSITION:
 *   - If wt[i-1] ≤ j:
 *       t[i][j] = max(
 *           val[i-1] + t[i-1][j - wt[i-1]],   // Include
 *           t[i-1][j]                          // Exclude
 *         )
 *   - Else:
 *       t[i][j] = t[i-1][j]
 *
 * TC:
 *   - O(n × W)
 *     (Each DP state is computed exactly once)
 *
 * SC:
 *   - O(n × W)  → DP table
 *
 * LEARNING:
 *   - How exponential recursion is optimized using DP
 *   - How to convert recursion → memoization → tabulation
 *   - Mapping recursion variables to DP dimensions:
 *       n → i (items)
 *       W → j (capacity)
 *   - Understanding base cases as DP initialization
 *   - Translating choice diagram into iterative DP logic
 *   - Clear difference between brute-force recursion and DP
 */


// ALiases 
using v = vector<int>;
using vv = vector<v>;

// 0/1 Knapsack Function 
int Knapsack(v &wt, v &val, int W, int n) {
    // Initilization 
    vv t(n + 1, v(W + 1, 0));

    // Start filling with i = 1, j = 1 
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < W + 1; j++) {
            if(wt[i-1] <= j) {
                t[i][j] = max(
                    val[i-1] + t[i-1][j - wt[i-1]], 
                    t[i-1][j]
                );
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    // Return Ans 
    return t[n][W];
}


int main()
{
    v wt = {1, 3, 4, 5};
    v val = {1, 4, 5, 7};
    int W = 7; 
    int n = wt.size();
    
    int ans = Knapsack(wt, val, W, n);
    
    cout << "Mx Profit: " << ans << endl;
    return 0;
}