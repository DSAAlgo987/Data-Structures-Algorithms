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
 *   - Bottom Up Dynamic Programming (Tabulation)
 *
 * DP STATE:
 *   - t[i][j] → length of LCS between
 *               x[0..i-1] and y[0..j-1]
 *
 * TRANSITION:
 *   - If x[i-1] == y[j-1]:
 *       t[i][j] = 1 + t[i-1][j-1]
 *   - Else:
 *       t[i][j] = max(t[i-1][j], t[i][j-1])
 *
 * TC:
 *   - O(n × m)
 *     Each DP state is computed exactly once
 *
 * SC:
 *   - O(n × m) → DP table
 *
 * LEARNING:
 *   - Conversion from Top Down (Memoization) to Bottom Up DP
 *   - Clear understanding of DP table construction
 *   - Importance of index shifting (i-1, j-1)
 */


// Aliases
using v = vector<int>;
using vv = vector<v>;

// LCS 
int LCS(string &x, string &y) { 
    int n = x.size(); 
    int m = y.size(); 

    // Step 1: DP Table 
    vv t(n + 1, v(m + 1, 0)); // Initially, INIT with 0

    // Step 2: Start filling, i = 1, j = 1; (i -> n) (j -> m) 
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            // Chars matches 
            if(x[i-1] == y[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else { 
                t[i][j] = max(
                    t[i-1][j],
                    t[i][j-1]
                );
            }
        }
    }

    // Step 3: Return ans 
    return t[n][m];
}


int main() {
    string x = "abcdgh";
    string y = "abedfhr";

    cout << "LCS Length: " << LCS(x, y) << endl; // op: 4 (abdh)
    
    return 0;
}