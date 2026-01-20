#include <bits/stdc++.h> 
using namespace std; 

/**
 * PS: Shortest Common Supersequence (SCS)
 * Problem: You are given two strings a, b and you have to find the SCS length 
 * IP: String a, b; 
 * OP: Return SCS length (int) 
 * APPROACH: Bottom up/ Tabulation 
 * TC: O(m * n) 
 * SC: O(m * n) 
 * VARIATION: LCS
 * LEARNING: 
 *  - Depth understanding about sequence 
 *  - How it is related with LCS Pattern 
 *  - In sequence -> order matters + discontinuity 
 */

// Aliases
using v = vector<int>; 
using vv = vector<v>; 

// Longest Common Subsequence 
int LCS(string &x, string &y, int m, int n) { 
    // Step 1: DP Table with INIT 
    vv t(m + 1, v(n + 1, 0)); 

    // Step 2: Start filling , i = 1, j = 1;    
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) { 
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

    // Step 3: Return the final ans 
    return t[m][n];
}

// Shortest Common Supersequence 
int SCS(string &a, string &b) { 
    int m = a.size(); 
    int n = b.size();

    return m + n - LCS(a, b, m, n);
}

int main() { 
    string a = "AGGTAB";
    string b = "GXTXAYB";

    cout << "SCS Length: " << SCS(a, b); 

    return 0;
}