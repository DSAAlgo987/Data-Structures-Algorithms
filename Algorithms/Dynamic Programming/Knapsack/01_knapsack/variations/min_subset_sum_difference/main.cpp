#include <bits/stdc++.h> 
using namespace std; 

/**
 * PS: Minimum Subset Sum Difference
 *
 * Problem:
 *   Given an array of positive integers, partition it
 *   into two subsets such that the absolute difference
 *   between their sums is minimum.
 *
 * IP:
 *   - vector<int> arr → input array
 *
 * OP:
 *   - int → minimum possible subset sum difference
 *
 * APPROACH:
 *   - Dynamic Programming (Bottom-Up / Tabulation)
 *   - This problem is a direct variation of the
 *     Subset Sum problem.
 *
 * KEY IDEA:
 *   - Let total sum = range
 *   - If one subset has sum = s1,
 *     the other subset sum = range - s1
 *   - Difference = |range - 2*s1|
 *   - To minimize the difference, we only need to
 *     check valid subset sums up to range / 2
 *
 * DP STATE:
 *   - t[i][j] → true if a subset using first i elements
 *               can achieve sum j
 *
 * STEPS:
 *   1. Compute total sum (range)
 *   2. Build subset sum DP table
 *   3. Collect all valid subset sums ≤ range / 2
 *   4. Compute minimum of |range - 2*s1|
 *
 * TC:
 *   - O(n × range)
 *
 * SC:
 *   - O(n × range)
 *
 * VARIATION:
 *   - Subset Sum
 *   - Equal Sum Partition
 *
 * LEARNING:
 *   - How multiple DP problems are interconnected
 *   - How Subset Sum DP can be reused to solve
 *     optimization problems
 *   - Why checking only up to range/2 is sufficient
 *   - Clear transition from feasibility DP to
 *     optimization DP
 *   - Strengthened DP pattern recognition
 */


// Aliases 
using v = vector<bool>;
using vv = vector<v>; 

// Subset Sum 
void subsetSum(vector<int> &arr, int sum, int n, vv &t) {
    // Initialization set t[i][0] = true
    for(int i = 0; i < n + 1; i++) 
        t[i][0] = true; 
        
    // Start filling i = 1; j = 1; 
    // i -> n , j -> sum 
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < sum + 1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
}

// Min Subset Sum Difference 
int minSubsetSum(vector<int> &arr) {
    int n = arr.size(); 
    
    // Step 1: Calculate Range(Summation)
    int range = accumulate(arr.begin(), arr.end(), 0); 
    
    // Step 2: Compute Subset Sum DP Table 
    vv t(n + 1, v(range + 1, false)); 
    
    subsetSum(arr, range, n, t);
    
    // Step 3: First fill s1 vector (only include true candidates)
    vector<int> s1; 
    
    for(int j = 0; j < range/2; j++){
        if(t[n][j] == true)
            s1.push_back(j); 
    }
    
    // Step 4: Identify minized subsetsum difference 
    int mn = INT_MAX; 
    for(int i = 0; i < range/2; i++) {
        mn = min(mn, abs(range - (2 * s1[i]))); 
    }
        
    // Step 5: Return minized ans 
    return mn; 
}

int main()
{
    vector<int> arr = {1, 2, 7};
    
    cout << "Min subset sum diff: " << minSubsetSum(arr) << endl; 
    
    return 0;
}