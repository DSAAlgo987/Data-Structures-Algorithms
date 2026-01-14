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
 *   - Dynamic Programming (Top-Down / Memoization)
 *   - At each item, we have two choices:
 *       1. Include the item (if wt[n-1] ≤ W)
 *       2. Exclude the item
 *   - Store results of subproblems in a DP table
 *     to avoid recomputation (overlapping subproblems)
 *
 * DP STATE:
 *   - t[n][W] → maximum profit using first n items
 *               with capacity W
 *
 * TC:
 *   - O(n × W)
 *     (each state (n, W) is computed once)
 *
 * SC:
 *   - O(n × W)  → DP table
 *   - O(n)      → recursion stack
 *
 * LEARNING:
 *   - How overlapping subproblems cause exponential recursion
 *   - How memoization optimizes recursion to polynomial time
 *   - How to identify DP dimensions from changing variables (n, W)
 *   - Difference between brute-force recursion and DP optimization
 */

// ALiases 
using v = vector<int>;
using vv = vector<v>;


// Knapsack Problem Function 
int Knapsack(v &wt, v &val, int W, int n, vv &t) {
    // BC 
    if(W == 0 || n == 0) {
        return 0; // Profit 
    }

    // Present ? 
    if(t[n][W] != -1) {
        return t[n][W];
    }

    // Item Checking condition
    if(wt[n-1] <= W) {
        // Include and Exclude based on mx proft 
        
        return t[n][W] = max(
                // Include & add val[n-1] -> profit 
                val[n-1] + Knapsack(wt, val, W - wt[n-1], n - 1, t),
                // Exclude 
                Knapsack(wt, val, W, n - 1, t)
            );
    }
    
    // O/w Exclude that item 
    return t[n][W] = Knapsack(wt, val, W, n - 1, t);
}

int main()
{
    v wt = {1, 3, 4, 5};
    v val = {1, 4, 5, 7};
    int W = 7; 
    int n = wt.size();
    
    // DP: Initially intialize with -1 
    vv t(n + 1, v(W + 1, -1));

    int ans = Knapsack(wt, val, W, n, t);
    
    cout << "Mx Profit: " << ans << endl;
    return 0;
}