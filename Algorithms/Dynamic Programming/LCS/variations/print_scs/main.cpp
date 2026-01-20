#include <bits/stdc++.h> 
using namespace std; 

/**
 * PS: Print Shortest Common Supersequence (SCS)
 *
 * Problem:
 *   Given two strings a and b, print their
 *   Shortest Common Supersequence (SCS).
 *
 *   A supersequence contains both strings
 *   as subsequences and has minimum length.
 *
 * IP:
 *   - string a
 *   - string b
 *
 * OP:
 *   - string → Shortest Common Supersequence
 *
 * APPROACH:
 *   - Bottom Up Dynamic Programming (Tabulation)
 *   - First compute LCS DP table
 *   - Then backtrack to build SCS
 *
 * KEY IDEA:
 *   - If characters match → take once
 *   - If not → take from string having
 *     larger LCS value
 *   - Append remaining characters
 *
 * TC:
 *   - O(m × n) → DP table computation
 *
 * SC:
 *   - O(m × n) → DP table storage
 *
 * LEARNING:
 *   - SCS is derived directly from LCS
 *   - How DP table guides reconstruction
 *   - Difference between printing LCS vs SCS
 *   - Strengthened DP backtracking intuition
 */

// Aliases 
using v = vector<int>; 
using vv = vector<v>; 

// LCS 
void LCS(string &x, string &y, int m, int n, vv &t) { 
    // Start with filling, i = 1, j = 1; 
    for(int i = 1; i < m + 1; i++) { 
        for(int j = 1; j < n + 1; j++) { 
            if(x[i-1] == y[j-1]) { 
                t[i][j] = 1 + t[i-1][j-1];
            } else { 
                t[i][j] = max(
                    t[i][j-1], 
                    t[i-1][j]
                );
            }
        }
    }
}

// Print SCS 
string printSCS(string &a, string &b) { 
    int m = a.size();
    int n = b.size(); 

    // Step 1: Compute LCS DP Table 
    vv t(m + 1, v(n + 1, 0)); // INIT with all 0s 
    LCS(a, b, m, n, t);

    // Step 2: Start with displaying process 
    int i = m, j = n; 
    string s = "";

    while(i > 0 && j > 0) { 
        // Chars match
        if(a[i-1] == b[j-1]) { 
            s += a[i-1];
            i--; j--; // upper diagonal
        } else { 
            if(t[i - 1][j] > t[i][j - 1]) {
                s += a[i-1];
                i--; // upper cell 
            } else { 
                s += b[j-1];
                j--; // left cell
            }
        }
    }

    // Get remaining letters of a 
    while(i > 0) { 
        s += a[i-1];
        i--; 
    }

    // Get remaining letters of b 
    while(j > 0) { 
        s += b[j-1];
        j--; 
    }

    // Reverse the string s to obtain final scs
    reverse(s.begin(), s.end());

    // Step 3: Return final scs 
    return s;
}

int main() { 
    string a = "AGGTAB";
    string b = "GXTXAYB";

    cout << "SCS String: " << printSCS(a, b) << endl;
    return 0; 
}