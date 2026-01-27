#include <bits/stdc++.h>
using namespace std;

/**
 * PS: MX Subarray sum of size k 
 * PROBLEM: You are given an array. 
 * Your task is to find mx subarray sum of size k. 
 * 
 * IP: vector<int> A, int k; 
 * OP: Mx subarray sum -> (int)
 * 
 * APPROACHES: 
 *  1. BRUTE FORCE : TC: O(n^2) SC: O(1)
 *  2. Sliding Window: TC: O(n) SC: O(1)
 * 
 * LEARNING: 
 *  - How to do this with brute force approach
 *  - How to identify redundency 
 *  - Convert it into optimized soln by minimizing time complexity 
 */

// Aliases 
using v = vector<int>;

// Brute force approach 
int solve(v &A, int k) { 
    int mx = INT_MIN; 
    int n = A.size(); 
    
    // Step 1: Generate possible subarrays -> n - k + 1
    for(int i = 0; i < n - k + 1; i++) { 
        int sum = 0; 
        
        // Step 2: While generating subarrays, calculate sum 
        for(int j = i; j < i + 3; j++) { 
            sum += A[j]; 
        }
        
        // Step 3: After sum identify max sum 
        mx = max(mx, sum); 
    }

    // Step 4: Return the final mx 
    return mx; 
}

// Sliding window approach 
int subarraySum(v &A, int k) { 
    int n = A.size();
    
    int mx = INT_MIN, sum = 0;
    int i = 0, j = 0; 
    
    // Sliding window 
    while(j < n) { 
        // Calc 
        sum += A[j];
        
        // Achieving WS 
        if(j - i + 1 < k) j++; 
        
        // Hit WS 
        else if (j - i + 1) { 
            // Calc -> mxSum 
            mx = max(mx, sum);
            
            // Maintain Window Size 
            sum -= A[i]; 
            i++; 
            j++; 
        }
    }
    
    // Return the final ans 
    return mx; 
}


int main() { 
    v A = {1, 2, 3, 4, 5};
    int k = 3; 

    cout << solve(A, k) << endl; 
    cout << subarraySum(A, k) << endl;

    return 0; 
}