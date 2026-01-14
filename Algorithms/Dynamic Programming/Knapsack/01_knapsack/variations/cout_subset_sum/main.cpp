#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Count Subsets with Given Sum
 *
 * Problem:
 *   Given an array of integers and a target sum,
 *   count the number of subsets whose elements
 *   add up exactly to the given sum.
 *
 * IP:
 *   - vector<int> arr  → input array
 *   - int sum          → target sum
 *
 * OP:
 *   - int → number of subsets having sum = target
 *
 * APPROACH:
 *   - Dynamic Programming (Bottom-Up / Tabulation)
 *   - This is a variation of the Subset Sum problem.
 *   - Instead of storing boolean (possible or not),
 *     we store the count of ways to form the sum.
 *
 * DP STATE:
 *   - t[i][j] → number of subsets using first i elements
 *               with total sum equal to j
 *
 * BASE CASE:
 *   - t[i][0] = 1
 *       → There is exactly 1 subset (empty subset)
 *         that forms sum = 0 for any i
 *   - t[0][j] = 0 (j > 0)
 *       → No elements cannot form a positive sum
 *
 * TRANSITION:
 *   - If arr[i-1] ≤ j:
 *       t[i][j] =
 *           t[i-1][j - arr[i-1]]   // include element
 *         + t[i-1][j]              // exclude element
 *
 *   - Else:
 *       t[i][j] = t[i-1][j]
 *
 * TC:
 *   - O(n × sum)
 *     (each DP state is computed once)
 *
 * SC:
 *   - O(n × sum)
 *     (DP table storage)
 *
 * VARIATION:
 *   - Subset Sum
 *   - 0/1 Knapsack (counting version)
 *
 * LEARNING:
 *   - How changing DP value type (bool → int)
 *     changes the nature of the problem
 *   - Clear understanding of:
 *       feasibility DP  vs  counting DP
 *   - Importance of correct base initialization
 *   - Strengthened intuition of include/exclude pattern
 */

// Aliases 
using v = vector<int>; 
using vv = vector<v>; 

// Subset Sum 
int subsetSum(v &arr, int sum) {
    int n = arr.size(); 

    // DP Table 
    vv t(n + 1, v(sum + 1, 0)); // Initially initialize with 0 

    // Initialization set t[i][0] = 1; 
    for(int i = 0; i < n + 1; i++) 
        t[i][0] = 1; 

    // Start filling from i = 1, j = 1 
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < sum + 1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    // Return ans 
    return t[n][sum]; 
}

int main(){
    v arr = {2, 3, 5, 6, 8, 10};
    int sum = 10; 

    cout << subsetSum(arr, sum) << endl;
    
    return 0;
}