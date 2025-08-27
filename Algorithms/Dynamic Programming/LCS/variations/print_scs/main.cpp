#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement: Print SCS 
 * 
 * ip:
 * string a, b;
 * 
 * op:
 * print SCS (string)
 */

vector<vector<int>> t; // Global declaration

void LCS(string a, string b) {
    int m = a.size();
    int n = b.size();

    // assign() → pura vector reset
    // resize() → sirf size adjust

    t.assign(m + 1, vector<int>(n+1, 0)); // Initialization done 

    // Start filling the remaining cells: i -> m, j -> n
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            // Matches 
            if(a[i-1] == b[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            }
            // Not Matches 
            else {
                t[i][j] = max(
                    t[i-1][j],
                    t[i][j-1]
                );
            }
        }
    }
}

// Time complexity: O(m * n)
string printSCS(string a, string b) {
    int m = a.size();
    int n = b.size();
    // Fill dp table 
    LCS(a, b);

    // Now start printing SCS 
    int i = m, j = n;
    string s = "";

    // Iterate until one of the strings becomes empty 
    while(i > 0 && j > 0) {
        // Matches 
        if(a[i-1] == b[j-1]) {
            s.push_back(a[i-1]);
            i--;
            j--;
        } 
        // Not matches
        else {
            // Move toward max diagonal element and store that char too
            if(t[i][j-1] > t[i-1][j]){
                s.push_back(b[j-1]);
                j--;
            } else {
                s.push_back(a[i-1]);
                i--;
            }
        }
    }

    // Get remaining chars of a 
    while(i > 0) {
        s.push_back(a[i-1]);
        i--;
    }

    // Get remaining chars of b 
    while(j > 0) {
        s.push_back(b[j-1]);
        j--;
    }

    // reverse string s to get the exact scs
    reverse(s.begin(), s.end());

    return s;
}



int main(){
    string a = "acbcf";
    string b = "abcdaf";

    cout << printSCS(a, b) << endl;
    return 0;
}