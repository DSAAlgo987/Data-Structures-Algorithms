#include <bits/stdc++.h>
using namespace std;

/**

* PS: Count(#) of subsets with a given difference.
*
* Problem:
* Given an array of integers, count the number of subsets such that
* the difference between the sum of two subsets is equal to `diff`.
*
* IP: vector<int> arr, int diff
* OP: int (count of valid subsets)
*
* APPROACH:
* Bottom-Up Dynamic Programming (Tabulation)
*
* Mathematical reduction:
* sum(S1) - sum(S2) = diff
* sum(S1) + sum(S2) = totalSum
*
* => sum(S1) = (diff + totalSum) / 2
*
* The problem reduces to counting the number of subsets
* with sum = (diff + totalSum) / 2.
*
* TC: O(n * sum)
* SC: O(n * sum)
*
* VARIATION:
* * Count of Subset Sum
*
* LEARNING:
* * This problem looks different but is a direct variation of subset sum.
* * The key learning is identifying how to convert a new problem
* *into a previously solved DP problem.
* * Once the transformation is clear, the implementation becomes straightforward.
* * Pattern recognition in DP is more important than memorizing solutions.
    */

// Aliases 
using v = vector<int>; 
using vv = vector<v>; 

// # subset sum 
int countSubsetSum(v &arr, int sum) {
    int n = arr.size(); 

    // Step 1: DP Table 
    vv t(n + 1, v(sum + 1, 0)); // INIT with 0 initially 

    // Step 2: Initialization: t[i][0] = 1; 
    for(int i = 0; i < n + 1; i++) 
        t[i][0] = 1; 
    
    // Step 3: Start filling table, i = 1, j = 1; 
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < sum + 1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    // Step 4: Return final ans 
    return t[n][sum]; 
}

// Count no of subsets with a given difference 
int countNoSubsets(v &arr, int diff) {
    // Step 1: First identify sum1 = diff + sum(arr) / 2
    int sumOfArr = accumulate(arr.begin(), arr.end(), 0); 

    int sum1 = (diff + sumOfArr) / 2; 

    // Step 2: Check the edge cases 
    if((diff + sumOfArr) % 2 != 0 || diff > sumOfArr) return 0; 

    // Step 3: Final step # subset sum with a calculated sum1 
    return countSubsetSum(arr, sum1);
}

int main(){
    v arr = {1, 1, 2, 3}; 
    int diff = 1; 

    cout << "Count of Subset Sum With A Given Diff(1): " << countNoSubsets(arr, diff) << endl;
    
    return 0;
}