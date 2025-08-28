#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statment: Sequence Pattern Matching (Is subsequence)
 * 
 * Ip:
 * String a, b;
 * 
 * Op:
 * Boolean T/F
 */

int LCS(string a, string b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> t(m+1, vector<int>(n+1, 0));

    // Start filling remaining cells: i -> m, j -> n
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            // Matches 
            if(a[i-1] == b[j-1]) {
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

// Time complexit: O(m * n)
int sequenceMatching(string a, string b) {
    return LCS(a, b) == a.length() ? 1 : 0;
}

// Two poitner approach: O(M + N)
int isSubsequence(string a, string b) {
    int i = 0;

    for(int j = 0; j < b.size(); j++) {
        if(i < a.size() && a[i] == b[j]) {
            i++;
        }
    }

    return i == a.size() ? 1 : 0;
}

int main(){
    string a = "AXYZ";
    string b = "ADXCPY";

    cout << (isSubsequence(a, b) ? "TRUE": "FALSE") << endl;
    
    return 0;
}