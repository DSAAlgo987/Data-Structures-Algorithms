#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Longest Increasing Subsequence (LIS)
 * Problem: You are given an array of integer.
 * Your task is to find the length of LIS.
 * 
 * IP: vector<int> nums; 
 * OP: (int) => Length of LIS;
 * 
 * APPROACH: Bottom up/ Tabulation 
 * OPTIMAL APPROACH: Binary Search (nlogn)
 * 
 * VARIATION: LCS 
 * 
 * TC: O(n^2);
 * SC: O(n^2);
 * 
 * LEARNING: 
 *  - Identification of LCS 
 *  - Similarities with LCS 
 *  - How it different with naive LCS 
 *  - Handling of edge cases
 * 
 * METHODS: 
 * 1. Unique():
 * unique(b.begin(), b.end());
 * It does NOT delete elements
 * It moves unique elements to the front
 * It returns an iterator pointing to the new logical end.
 * 
 * 2. arr.erase():
 * b.erase(it, b.end());
 * Physically removes elements from the vector
 * Shrinks vector size
 * Shifts memory left
 */

// Aliases 
using v = vector<int>; 
using vv = vector<v>;

// Remove Duplicates
void removeDuplicates(v &b) { 
   sort(b.begin(), b.end());
   a.erase(unique(b.begin(), b.end()), b.end());
}

// LIS 
int LIS(v &a) { 
    int m = a.size(); 

    // Step 1: Derive b vector 
    v b = a;
    removeDuplicates(b);
    int n = b.size();

    // Step 2: LIS DP Table 
    vv t(m + 1, v(n + 1, 0)); // Initially, INIT with all 0s
    
    // Step 3: Start filling, i = 1, j = 1; 
    for(int i = 1; i < m + 1; i++) { 
        for(int j = 1; j < n + 1; j++) { 
            if(a[i-1] == b[j-1]) { 
                t[i][j] = 1 + t[i-1][j-1];
            } else { 
                t[i][j] = max(
                    t[i][j-1],
                    t[i-1][j]
                );
            }
        }
    }

    // Step 4: Return the max Length 
    return t[m][n];
}


int main() { 
    v nums = {3, 10, 3, 2, 1, 20};

    cout << "LIS Length: " << LIS(nums) << endl;
}