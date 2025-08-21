#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Identify longest common substring within two strings.
 * 
 * Ip:
 * string a;
 * string b;
 * 
 * Op:
 * return max len substring.
 */

// TC: O(m*n) 
int solve(string a, string b) {
    int m = a.size();
    int n = b.size();

    int mx = 0; // To identify max len 

    vector<vector<int>> t(m + 1, vector<int>(n + 1, 0)); // Initilization same as LCS 

    // Variation: i -> m, j -> n
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            // Match
            if(a[i-1] == b[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            // Not match
            else { 
                t[i][j] = 0; // Length will become 0
            }
            // Now identify max len substring 
            mx = max(mx, t[i][j]);
        }
    }

    return mx;
}


int main(){
    string a = "abcef";
    string b = "abcfe";

    cout << solve(a, b) << endl; // op: 3
    return 0;
}