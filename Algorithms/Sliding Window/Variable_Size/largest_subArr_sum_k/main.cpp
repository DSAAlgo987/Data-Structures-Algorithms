#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Longest Subarray of sum k 
 * 
 * Problem: You are given an array and a sum k.
 * Your task is to find out longest subarray having sum k.
 * 
 * IP: vector<int> A, int k (sum);
 * OP: (int) -> longest subarr size;
 * 
 * APPROACH: Brute force: TC:O(n^2) SC: O(1)
 *           Sliding window: TC:O(n) SC: O(1)
 * 
 * LEARNING: 
 *  - Known the difference between fixed and variable sliding window 
 *  - Identification of variable sliding window
 */
 
// Aliases 
using v = vector<int>;

// Longest subarray of sum k 
int solve(v &A, int k) { 
    int sum = 0, mx = INT_MIN; 
    int n = A.size();
    
    int i = 0, j = 0; 
    
    while(j < n) { 
        // Calc 
        sum += A[j]; 
        
        // < condition (Achieve condition)
        if(sum < k) j++; 
        
        // hit condition 
        else if(sum == k) {
            // ans <- calc 
            mx = max(mx, j - i + 1); 
            
            // slide window 
            sum -= A[i];
            i++;
            j++;
        }
        
        // > condition
        else if(sum > k) { 
            // Remove ith calculations 
            while(sum > k) { 
                sum -= A[i];
                i++;
            }
            
            // again hit conditin 
            if(sum == k) {
                // ans <- calc 
                mx = max(mx, j - i + 1); 
                
                // slide window 
                sum -= A[i];
                i++;
                j++;
            }
        }
    }
    
    // Return the ans 
    return mx == INT_MIN ? 0: mx; 
}

int main()
{
    v A = {1, 2, 3, 2, 2};
    int k = 5; 
    
    cout << "Longest Subarray Size: " << solve(A, k) << endl;
    return 0;
}