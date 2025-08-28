#include <bits/stdc++.h>
using namespace std;

/**
    Problem Statement: Find longest repeating subsequence(LRS).

    Ip:
    String s;

    op:
    Display length of LRS.
*/

int LRS(string a, string b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> t(m + 1, vector<int>(n + 1, 0)); // Declaration & initialization

    // Start Identifying LCS with restriction (i != j) : i -> m, j -> n
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            // matches and i!= j
            if(a[i-1] == b[j-1] && i != j) {
                t[i][j] = 1 + t[i-1][j-1];
            } 
            // Not matches 
            else {
                t[i][j] = max(
                    t[i][j-1],
                    t[i-1][j]
                );
            }
        }
    }

    return t[m][n];
}

int main() {
    string s = "AABEBCDD";

    cout << LRS(s, s) << endl; // op: 3
    return 0;
}