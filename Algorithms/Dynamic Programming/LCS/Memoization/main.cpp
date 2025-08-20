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

vector<vector<int>> t; // Dp Declaration 

// Memoized approach : O(n * m)
int LCS(string x, string y, int n, int m){
    // Base condition 
    if(n == 0 || m == 0) { 
        return 0;
    }

    // Present in t?
    if(t[n][m] != -1) {
        return t[n][m];
    }
    
    // Choice diagram 
    if(x[n-1] == y[m-1]) { 
        return t[n][m] = 1 + LCS(x, y, n-1, m-1);
    } else {
        return t[n][m] = max(
            LCS(x, y, n, m-1),
            LCS(x, y, n-1, m)
        );
    }
}

int main(){
    string x = "abcdgh";
    string y = "abedfhr";
    int n = x.size();
    int m = y.size();

    t.resize(n + 1, vector<int>(m + 1, -1)); // Initialization with -1 

    cout << LCS(x, y, n, m) << endl; // op: 4 (abdh)
    return 0;
}