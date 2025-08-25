#include <bits/stdc++.h>
using namespace std;
/**
 * Problem Statement: Min number of deletions to make it a palindrome.
 * 
 * ip:
 * string a;
 * 
 * op:
 * length of min # of deletion.
 */

int LCS(string a, string b) {
    int m = a.size();
    int n = b.size();

    // Declaration 
    vector<vector<int>> t(m+1, vector<int>(n+1, 0));

    // start filling main table: i-> m, j -> n
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            // Matches
            if(a[i-1] == b[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            // Not matches 
            else {
                t[i][j] = max(
                    t[i-1][j],
                    t[i][j-1]
                );
            }
        }
    }

    return t[m][n];
}

int minDeletions(string a) {
    /**
     * Min # deletion = len(a) - LCS(a, reverse(a))
     */

    int n = a.size();
    string b = a;

    reverse(b.begin(), b.end());
    return n - LCS(a, b);
}

int main(){
    string a = "aebcbda"; 

    cout << minDeletions(a) << endl; // Op: 2
    
    return 0;
}