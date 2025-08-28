#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Min # of insertion in a string to make a palindrome.
 * 
 * Ip:
 * String a;
 * 
 * Op:
 * return Min # of insertions
 * 
 * This Question similar with Min # deletions in a string to make a palindrome
 * 
 * Min # of insertions == Min # of deletions
 */

int LPS(string a, string b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> t(m + 1, vector<int>(n+1, 0));

    // Start filling remaining celss
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            // Matches
            if(a[i-1] == b[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            // Not matchees 
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
int minInsertions(string a) {
    // B string is a hidden 
    string b = a;

    reverse(b.begin(), b.end());

    return a.length() - LPS(a, b);
}

int main(){
    string s = "zzazz";

    cout << minInsertions(s) << endl;
    return 0;
}