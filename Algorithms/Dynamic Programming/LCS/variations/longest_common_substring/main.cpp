#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Longest Common Substring
 *
 * Problem:
 *   Given two strings x and y, find the length of the
 *   longest substring common to both strings.
 *   A substring must be continuous.
 *
 * IP:
 *   - string x
 *   - string y
 *
 * OP:
 *   - int → length of the Longest Common Substring
 *
 * APPROACH:
 *   - Bottom Up Dynamic Programming (Tabulation)
 *
 * DP STATE:
 *   - t[i][j] → length of longest common substring
 *               ending at x[i-1] and y[j-1]
 *
 * TRANSITION:
 *   - If x[i-1] == y[j-1]:
 *       t[i][j] = 1 + t[i-1][j-1]
 *   - Else:
 *       t[i][j] = 0   (substring continuity breaks)
 *
 * KEY DIFFERENCE FROM LCS:
 *   - Substring → continuous → reset to 0 on mismatch
 *   - Subsequence → discontinuous → take max
 *
 * TC:
 *   - O(m × n)
 *
 * SC:
 *   - O(m × n)
 *
 * LEARNING:
 *   - Clear distinction between substring vs subsequence
 *   - Why answer is the maximum value in DP table
 *   - Importance of tracking global maximum
 *   - Strengthened DP pattern recognition
 **  - If you are confuse with bottom up approach then try to solve it with naive 
 ** Recursion approach
 */


// Aliases 
using v = vector<int>; 
using vv = vector<v>; 

// Longest Common Substring 
int LCSub(string &x, string &y) { 
    int m = x.size(); 
    int n = y.size(); 
    int mx = INT_MIN; 

    // Step 1: DP Table with INIT 
    vv t(m + 1, v(n + 1, 0)); 

    // Step 2: Start filling, i = 1, j = 1, (i -> m) (j -> n) 
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            // if char mathches (continuous nature)
            if(x[i-1] == y[j-1]) { 
                t[i][j] = 1 + t[i-1][j-1]; 
            } else { 
                // Not maches so length will be 0
                t[i][j] = 0; 
            }
            mx = max(mx, t[i][j]); // Track mx Length
        }
    }

    // Step 3: Return the final ans 
    return mx;
}

int main() { 
    string x = "abcde";
    string y = "abfce";

    cout << "LCSub Length: " << LCSub(x, y) << endl;
    return 0;
}