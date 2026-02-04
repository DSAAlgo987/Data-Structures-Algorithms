#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Flip Game
 * 
 * IP: vector<int> A; 
 * OP: Return Maximumal Number of 1s after applying flipping operation
 *
 * APPROACH: 
 *  - Kadane's Algorithm: 
 *      TC: O(n) 
 *      SC: O(1) 
 * 
 * LEARNING: 
 *  - Identification of kadane's algorithm 
 *  - Kadane's algorithm : Prefix sum + Condition 
 */
 
// Aliases 
using v = vector<int>; 

// Flip Game 
int solve(v &A) { 
    int n = A.size(); 
    int countOnes = 0; 
    
    // Count Ones 
    for(int i = 0; i < n; i++) { 
        if(A[i] == 1) countOnes++; 
    }
    
    // Invert A 
    for(int i = 0; i < n; i++) { 
        if(A[i] == 1) A[i] = -1; 
        else A[i] = 1; 
    }
    
    // Applying Kadane's Algorithm 
    int mxSum = INT_MIN; 
    
    // If negative then store 0 on 0th index 
    if(A[0] < 0) {
        A[0] = 0;
        mxSum = max(mxSum, A[0]); 
    }
    
    for(int i = 1; i < n; i++) {
        A[i] = A[i-1] + A[i]; 
        mxSum = max(mxSum, A[i]); 
    }
    
    return countOnes + mxSum; 
}

int main()
{
    v A = {1 , 0, 0, 1, 0}; 
    
    cout << "Mx Number of 1's: " << solve(A) << endl;
    return 0;
}