#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Subset Sum Problem
 *
 * Problem:
 *   Given a set of integers, determine whether there exists
 *   a subset whose sum is equal to a given target sum.
 *   Each element can be chosen at most once.
 *
 * IP:
 *   - vector<int> arr  → input set of numbers
 *   - int sum          → target sum
 *
 * OP:
 *   - true  → if a subset with given sum exists
 *   - false → otherwise
 *
 * APPROACH:
 *   - Dynamic Programming (Bottom-Up / Tabulation)
 *   - For each element, decide whether to:
 *       1. Include it in the subset
 *       2. Exclude it from the subset
 *   - Store results of subproblems in a DP table
 *
 * DP STATE:
 *   - t[i][j] → true if a subset with sum j can be formed
 *               using the first i elements
 *
 * BASE CASE (Initialization):
 *   - t[i][0] = true   → sum 0 is always possible (empty subset)
 *   - t[0][j] = false  → no elements cannot form positive sum
 *
 * TRANSITION:
 *   - If arr[i-1] ≤ j:
 *       t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j]
 *   - Else:
 *       t[i][j] = t[i-1][j]
 *
 * TC:
 *   - O(n × sum)
 *
 * SC:
 *   - O(n × sum)  → DP table
 *
 * VARIATION:
 *   - 0/1 Knapsack (Boolean version)
 *
 * LEARNING:
 *   - How Subset Sum is a direct variation of 0/1 Knapsack
 *   - Mapping:
 *       arr[] → weights
 *       sum   → knapsack capacity
 *   - Difference between value-maximization (Knapsack)
 *     and feasibility checking (Subset Sum)
 *   - Understanding DP initialization for boolean problems
 *   - Translating recursive include/exclude choices
 *     into iterative DP logic
 */

// Aliases 
using v = vector<int>;
using vv = vector<v>;

// Subset Sum Function 
bool subsetSum(v &arr, int sum) {
    int n = arr.size();
    // DP 
    vv t(n + 1, v(sum + 1, false));

    // Initialization of (0th column = true)
    for(int i = 0; i < n + 1; i++) {
        t[i][0] = true;
    }
        
    // Iterative code: Start filling with i = 1, j = 1 
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < sum + 1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    // Return ans 
    return t[n][sum];
}

int main(){
    v arr = {2, 3, 7, 8, 10};
    int sum = 11; 

    cout << (subsetSum(arr, sum) ? "TRUE" : "FALSE") << endl;

    return 0;
}