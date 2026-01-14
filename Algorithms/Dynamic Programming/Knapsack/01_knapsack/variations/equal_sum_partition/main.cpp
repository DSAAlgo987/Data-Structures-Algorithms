#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Equal Sum Partition Problem
 *
 * Problem:
 *   Given a set of integers, determine whether the set
 *   can be partitioned into two subsets such that the
 *   sum of elements in both subsets is equal.
 *
 * IP:
 *   - vector<int> arr  → input array of integers
 *
 * OP:
 *   - true  → if equal sum partition exists
 *   - false → otherwise
 *
 * APPROACH:
 *   - Dynamic Programming (Bottom-Up / Tabulation)
 *   - Key observation:
 *       If total sum is odd, equal partition is impossible.
 *   - Otherwise, the problem reduces to checking whether
 *     a subset with sum = (total_sum / 2) exists.
 *
 * VARIATION:
 *   - Subset Sum Problem
 *
 * DP STATE:
 *   - t[i][j] → true if a subset with sum j can be formed
 *               using the first i elements
 *
 * BASE CASE:
 *   - t[i][0] = true   → empty subset can form sum 0
 *   - t[0][j] = false → no elements cannot form positive sum
 *
 * TRANSITION:
 *   - If arr[i-1] ≤ j:
 *       t[i][j] = t[i-1][j - arr[i-1]] || t[i-1][j]
 *   - Else:
 *       t[i][j] = t[i-1][j]
 *
 * TC:
 *   - O(n × sum)  → DP computation
 *
 * SC:
 *   - O(n × sum)  → DP table
 *
 * LEARNING:
 *   - How a problem can be reduced to a known DP pattern
 *   - Importance of checking odd/even total sum early
 *   - How Equal Sum Partition is a direct application
 *     of Subset Sum
 *   - Proper use of STL:
 *       accumulate(begin, end, init) → O(n)
 *   - Strengthened understanding of boolean DP tables
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

// Equal sum partition function 
bool equalSumPartition(v &arr) {

    // Step 1: Cacluate sum of given arr 
    // int sum = 0; 
    // for(int i = 0; i < arr.size(); i++)
    //     sum += arr[i];
    int sum = accumulate(arr.begin(), arr.end(), 0); 

    // Step 2: Check if sum is odd then return false 
    if(sum % 2 != 0) {
        return false; 
    }

    // Step 3: If it is not then identify the set which is equal to the sum/2;
    return subsetSum(arr, sum / 2); 
}

int main() {
    v arr = {1, 5, 11, 5};

    cout << (equalSumPartition(arr) ? "TRUE" : "FALSE") << endl;

    return 0;
}