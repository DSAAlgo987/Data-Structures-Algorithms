#include <bits/stdc++.h>
using namespace std;

/**
 * PS: LCS (Longest Common Subsequence)
 * Problem:
 *
 * IP: string x, string y
 * OP: Return length of the Longest Common Subsequence
 *
 * APPROACH: Pure Recursion
 *
 * TC: O(2^(m + n))
 *  - At each step we branch into two recursive calls in worst case
 *
 * SC: O(m + n)
 *  - Due to recursion stack depth
 *
 * LEARNING:
 *  - How to break the problem using recursion
 *  - How character match reduces problem size diagonally
 *  - Why overlapping subproblems lead to exponential time
 *  - Motivation for DP (Memoization / Tabulation)
 */

// LCS 
int LCS(string &x, string &y, int n, int m) {
    // BC 
    if(n == 0 || m == 0) return 0; // lcs length 

    // Choice Diagram 
    // Char matches
    if(x[n-1] == y[m-1]) {
        return 1 + LCS(x, y, n - 1, m - 1);
    } else { 
        return max(
            LCS(x, y, n, m - 1), 
            LCS(x, y, n - 1, m)
        );
    }
}

int main() {
    string x = "abcdgh";
    string y = "abedfhr";

    cout << LCS(x, y, x.size(), y.size()) << endl; // op: 4 (abdh)
    
    return 0;
}