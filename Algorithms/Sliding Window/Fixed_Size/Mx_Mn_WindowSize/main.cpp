#include <iostream>
#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Mx of Mn for every window size
 * 
 * Problem: You are given an array. 
 * Your task is to find mx of mn for every window size. 
 * 
 * IP: vector<int> A; 
 * OP: vector<int> mxMn; 
 * 
 * Approaches: 
 *  1. Better/sliding window: TC: O(n^2)  SC: O(n)
 *  2. Stack:                 TC: O(n)    SC: O(n) -> will do it stack pattern
 * 
 * Learning: 
 *  - How to approach a problem thoroughly 
 *  - How to find redundancy
 ** - Focus on each element’s influence range
 */

// Aliases 
using v = vector<int>;

// Display 
void displayV(v A) { 
    cout << "[ ";
    for(auto x: A) {
        if(x == INT_MIN) continue;
        
        cout << x << " ";
    }
    
    cout << "]";
}

// Better/Sliding window 
v solve(v &A) { 
    int n = A.size(); 
    
    v mxMn(n + 1, INT_MIN);
    
    // S1: generate all possible window size 
    for(int i = 0; i < n; i++) { 
        // S2: While generating ws identify mn
        int mn = INT_MAX;
        for(int j = i; j < n; j++) { 
            mn = min(mn, A[j]); 
            
            int len = j - i + 1; 
            
            mxMn[len] = max(mxMn[len], mn); 
        }
    }
    
    return mxMn;     
}



int main()
{
    v A = {10, 30, 40, 10}; 
    
    displayV(solve(A)); 

    return 0;
}