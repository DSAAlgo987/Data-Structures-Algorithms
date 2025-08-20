#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Longest common subsequence 
 * 
 * Ip:
 * string x, y;
 * 
 * Op:
 * Display Length of LCS 
 */

// Tabular approach: O(n * m)
int LCS(string x, string y, int m, int n) {
    vector<vector<int>> t(n + 1,vector(m + 1, 0)); // Initialization with 0s

    // Start filling, remaining cells(sub-problems): i -> n, j -> m
    for(int i = 1; i < n + 1; i ++) {
        for(int j = 1; j < m + 1; j++) {
            // Matching 
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

    return t[n][m];
}

int main() {
    string x = "abcdgh";
    string y = "abedfhr";

    cout << LCS(x, y, x.size(), y.size()) << endl; // op: 4 (abdh)
    
    return 0;
}