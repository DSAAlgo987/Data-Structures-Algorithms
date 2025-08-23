#include <bits/stdc++.h>
using namespace std;
/**
 * Problem Statement: Shortest Common SuperSequence 
 * 
 * ip: 
 * string a;
 * string b;
 * 
 * op: 
 * Display length of shortest super sequence
 */
int LCS(string a, string b, int m, int n) {
    vector<vector<int>> t(m+1, vector<int>(n+1, 0)); // Declaration with 0 initialization

    // Start filling main table : i-> m, j -> n
    for(int i = 1; i < m +1; i++) {
        for(int j = 1; j < n + 1; j++) {
            // Match 
            if(a[i-1] == b[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else { // Not match
                t[i][j] = max(
                   t[i][j-1],
                   t[i-1][j]
                );
            }
        }
    }

    return t[m][n];
}

int shortestSuperSequence(string a, string b, int m, int n) {
    // 6 + 7 - Length of LCS 
    return m + n - LCS(a, b, m, n);
}


int main(){
    string a = "AGGTAB"; // 6
    string b = "GXTXAYB"; // 7 
    
    cout << shortestSuperSequence(a, b, a.size(), b.size()) << endl; //op: 13 - 4 = 9
    return 0;
}