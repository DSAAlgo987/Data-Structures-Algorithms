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

// Recursive Approach: 2^(m + n)
int LCS(string x, string y, int m, int n) {
    // Base condition 
    if(n == 0 || m == 0) { 
        return 0;
    }

    // Choice diagram 
    if(x[m-1] == y[n-1]) {
        return 1 + LCS(x, y, m - 1, n - 1);
    } else {
        return max(
            LCS(x, y, m, n-1),
            LCS(x, y, m-1, n)
        );
    }
}

int main() {
    string x = "abcdgh";
    string y = "abedfhr";

    cout << LCS(x, y, x.size(), y.size()) << endl; // op: 4 (abdh)
    
    return 0;
}