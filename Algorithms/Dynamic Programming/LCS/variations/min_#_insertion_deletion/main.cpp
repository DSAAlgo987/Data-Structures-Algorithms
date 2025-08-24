#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Min. no of insertion and deletion to convert a -> b.
 * 
 * ip: 
 * string a, b;
 * 
 * op:
 * # of insertion + # of deletion 
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

// Time complexity: O(m * n)
int solve(string a, string b) {

    /**
     * # of deletion = a.size() - LCS(a,b);
     * # of insertion = b.size() - LCS(a,b);
     */
    
    int lcsLength = LCS(a,b);
    int noDeletion = a.size() - lcsLength;
    int noInsertion = b.size() - lcsLength;
    return noDeletion + noInsertion;
}

int main(){
    string a = "heap";
    string b = "pea";

    cout << solve(a, b) << endl; // op: 2 deletion and 1 insertion = 3

    
    return 0;
}