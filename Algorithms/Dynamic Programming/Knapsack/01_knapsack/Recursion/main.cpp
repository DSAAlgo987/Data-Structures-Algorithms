#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: 0/1 Knapsack Problem
 *
 * Problem:
 *   Given N items, each with a weight and a value,
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
 *   - Recursion (Backtracking style: include / exclude)
 *   - For every item, we have two choices:
 *       1. Include the item (if weight allows)
 *       2. Exclude the item
 *   - Choose the option that gives maximum profit
 *
 * TC:
 *   - O(2^n)  (each item has 2 choices)
 *
 * SC:
 *   - O(n)  (recursion stack)
 *
 * LEARNING:
 *   - How decision-based problems lead to exponential recursion
 *   - Include / Exclude pattern in backtracking-style problems
 *   - Relation between recursion, memoization, and tabulation
 *   - Why overlapping subproblems make DP optimization necessary
 */

 
// ALiases 
using v = vector<int>;

// Knapsack Problem Function 
int Knapsack(v &wt, v &val, int W, int n) {
    // BC 
    if(W == 0 || n == 0) {
        return 0; // Profit 
    }
    
    // Item Checking condition
    if(wt[n-1] <= W) {
        // Include and Exclude based on mx proft 
        
        return max(
                // Include & add val[n-1] -> profit 
                val[n-1] + Knapsack(wt, val, W - wt[n-1], n - 1),
                // Exclude 
                Knapsack(wt, val, W, n - 1)
            );
    }
    
    // O/w Exclude that item 
    return Knapsack(wt, val, W, n - 1);
}

int main()
{
    v wt = {1, 3, 4, 5};
    v val = {1, 4, 5, 7};
    int W = 7; 
    
    int ans = Knapsack(wt, val, W, wt.size());
    
    cout << "Mx Profit: " << ans << endl;
    return 0;
}