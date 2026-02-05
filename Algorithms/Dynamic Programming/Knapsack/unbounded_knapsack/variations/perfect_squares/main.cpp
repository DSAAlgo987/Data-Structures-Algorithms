#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Perfect Squares 
 * 
 * Problem: Given an integer n, return the least number 
 * of perfect square numbers that sum to n.
 * A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.
 * 
 * IP: int n; 
 * OP: Return least number of perfect square numbers taht sum to n(int); 
 * 
 * APPROACH: 
 *  - Recursion: 
 *      - TC: Exponential SC: O(n) mx depth 
 *  
 *  - Memoization: 
 *      - TC: O(n * root n) SC: O(n) 
 * 
 * PATTERN: 
 *  - Unbounded Knapsack 
 * 
 * LEARNING: 
 *  - Identification of recursion problem
 *  - Identification of dp and then unbounded knapsack 
 *  - Convert it into memoized version 
 */

class Solution {
public:
    using v = vector<int>;
    int solve(int n, v &t) { 
        // BC 
        if(n == 0) return 0; 

        // Present in dp?
        if(t[n] != -1) return t[n]; 

        // Traverse through perfect square numbers and find min numbers
        int mn = INT_MAX;
        for(int i = 1; i * i <= n; i++) {
            mn = min(mn, 1 + solve(n - i * i, t));
        }

        return t[n] = mn; 
    }

    int numSquares(int n) {
        v t(n + 1, -1); // DP, INIT with -1 
        return solve(n, t);
    }
};