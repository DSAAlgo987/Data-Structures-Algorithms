#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Longest Palindromic Subsequence (LPS) 
 * Problem: You are given one string a as an input. 
 * Your task is to find the length of LPS.
 * 
 * IP: String a;
 * OP: Return Length of LPS (int);
 * 
 * APPROACH: Bottom up/ Tabulation 
 * 
 * TC: O(n * n) -> DP table computation 
 * SC: O(n * n) -> DP table storage 
 * 
 * VARIATION: LCS
 * 
 * LEARNING: 
 *  - LPS is subset of LCS 
 *  - Identification of LCS
 *  - Similarities with LCS 
 *  - Code Variation  
 */

int LCS(string a, string b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> t(m+1, vector<int>(n+1, 0)); // Declaration and initilization with 0s

    // Start, filling main table: i -> m, j -> n
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            // Matches
            if(a[i-1] == b[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else { // Not matches
                t[i][j] = max(
                    t[i][j-1],
                    t[i-1][j]
                );
            }
        }
    }

    return t[m][n];
}

int LPS(string a) {

    // Reverse a string and store in b string
    string b = a;

    // Reverse b string string
    reverse(b.begin(), b.end());

    return LCS(a, b);
}


int main(){
    string a = "agbcba";

    cout << LPS(a) << endl; // OP: 5
    
    return 0;
}