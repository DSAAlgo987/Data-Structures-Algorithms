#include <bits/stdc++.h>
using namespace std;

/**
* PS: Target Sum
*
* Problem:
* Given an array of integers, assign either '+' or '-' to each element
* such that the final expression evaluates to the given target sum.
* Count the number of valid ways.
*
* IP: vector<int> arr, int sum
* OP: int → number of valid expressions/subsets
*
* APPROACH:
* Bottom-Up Dynamic Programming (Tabulation)
*
* Mathematical Insight:
* * This problem can be transformed into
* "Count of Subsets with a Given Difference".
* * Which further reduces to
* "Count of Subset Sum".
*
* TC: O(n * sum)
* SC: O(n * sum)
*
* VARIATION:
* 1. Count no. of subsets with a given difference
* 2. Count subset sum
*
* LEARNING:
* * The core problem remains the same; only the way of asking changes.
* * Always try to map a new problem to a previously solved DP pattern.
* * Target Sum → Given Difference → Subset Sum Count.
* * Recognizing this transformation is the key DP learning here.
*/


// Aliases 
using v = vector<int>; 
using vv = vector<v>; 

// Subset Sum Count 
int subsetSumCount(v &arr, int sum) {
    int n = arr.size(); 

    // Step 1: DP Table 
    vv t(n + 1, v(sum + 1, 0)); // Initially INIT with 0 

    // Step 2: Initilaization t[i][0] = 1; 
    for(int i = 0; i < n + 1; i++) 
        t[i][0] = 1; 

    // Step 3: Start filling, i = 1, j = 1; 
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < sum + 1; j++) {
            if(arr[i-1] <= j) {
                t[i][j] = t[i-1][j - arr[i-1]] + t[i-1][j]; 
            } else {
                t[i][j] = t[i-1][j]; 
            }
        }
    }

    // Step 4: Return the final ans 
    return t[n][sum]; 
}

// Target sum
int targetSum(v &arr, int sum) {
    // Step 1: Caculate sum of array 
    int sumOfArry = accumulate(arr.begin(), arr.end(), 0); 
    
    // Step 2: Check the edge cases 
    if((sum + sumOfArry) % 2 != 0 || sum > sumOfArry) return 0; 

    // Step 3: Calculate sum1 with derived formula 
    int sum1 = (sum + sumOfArry) / 2; 

    // Step 4: Final call subset sum count to obtain the final ans 
    return subsetSumCount(arr, sum1); 
}

int main(){
    v arr = {1, 1, 2, 3}; 
    int sum = 1; 

    cout << "Count: " << targetSum(arr, sum) << endl;
    
    return 0;
}