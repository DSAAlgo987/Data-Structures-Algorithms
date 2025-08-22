#include <bits/stdc++.h>
using namespace std; 

string printLCS(string a, string b) {
    int m = a.size();
    int n = b.size();

    vector<vector<int>> t(m+1, vector<int>(n+1,0)); // Declaration with initialization

    // Filling the table: i -> m, j -> n
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            // Match
            if(a[i-1] == b[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else { 
                t[i][j] = max(
                    t[i-1][j],
                    t[i][j-1]
                );
            }
        }
    }

    // Print LCS 
    int i = m, j = n;
    string s = "";

    // Iterate all possible ways until the strings becomes empty 
    while(i > 0 && j > 0) {
        // Match 
        if(a[i-1] == b[j-1]) {
            s.push_back(a[i-1]); // Store that char
            i--;
            j--;
        } else { // Not match 
            // Check max diagonal elements 
            if(t[i-1][j] > t[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    // Reverse string 
    reverse(s.begin(), s.end());

    return s;
}

int main() {
    string a = "acbcf";
    string b = "abcdaf";

    cout << printLCS(a, b) << endl; // OP: abcf

    return 0;
}