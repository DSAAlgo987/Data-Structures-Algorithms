#include <bits/stdc++.h>
using namespace std;

/**
 * PS: LCS (Longest Common Subsequence)
 *
 * Problem:
 *   Given two strings x and y, find the length of the
 *   Longest Common Subsequence (LCS) between them.
 *   A subsequence maintains relative order but
 *   characters need not be contiguous.
 *
 * IP:
 *   - string x
 *   - string y
 *
 * OP:
 *   - int → length of the Longest Common Subsequence
 *
 * APPROACH:
 *   - Top Down Dynamic Programming (Memoization)
 *   - Recursion + DP table to store overlapping subproblems
 *
 * DP STATE:
 *   - t[i][j] → length of LCS between
 *               x[0..i-1] and y[0..j-1]
 *
 * TC:
 *   - O(n × m)
 *     Each (n, m) state is computed once due to memoization
 *
 * SC:
 *   - O(n × m) → DP table
 *   - O(n + m) → recursion stack (worst case)
 *
 * LEARNING:
 *   - How recursion leads to overlapping subproblems
 *   - Why memoization reduces exponential time to polynomial
 *   - Clear identification of DP state and transitions
 *   - Difference between brute-force LCS and optimized DP LCS
 */

// Aliases: 
using v = vector<int>;
using vv = vector<v>;

// LCS function 
int LCS(string &x, string &y, int n, int m, vv &t) { 
    // BC
    if(n == 0 || m == 0) return 0; 

    // Preset -> t?
    if(t[n][m] != -1) return t[n][m];

    // Choice Diagram 
    // Chars matches
    if(x[n-1] == y[m-1]) {
        return t[n][m] = 1 + LCS(x, y, n - 1, m - 1, t);
    } else { 
        return t[n][m] = max(
            LCS(x, y, n, m - 1, t),
            LCS(x, y, n - 1, m, t)
        );
    }
}


int main(){
    string x = "abcdgh";
    string y = "abedfhr";
    int n = x.size();
    int m = y.size();

    // DP table 
    vv t(n + 1, v(m + 1, -1)); // Initially, INIT with -1
    
    cout << LCS(x, y, n, m, t) << endl; // op: 4 (abdh)
    return 0;
}