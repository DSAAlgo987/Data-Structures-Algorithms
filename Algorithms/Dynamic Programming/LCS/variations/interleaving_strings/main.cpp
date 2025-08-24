#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Statement : Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
 * 
 * ip: 
 * string s1, s2, s3;
 * 
 * op:
 * True/False
 */

// Bottom Up Approach: O(m * n * o)
bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size();
    int n = s2.size();
    int o = s3.size();

    // Edge case 
    if(m + n != o) return false;

    // Delcaration of 3D dp and initlization with false
    vector<vector<vector<bool>>> t(m+1, vector<vector<bool>>(n+1, vector<bool>(o+1,false)));

    // Intiliaze first cell as TRUE 
    t[0][0][0] = true;

    // Filling the main table: i-> m, j->n, k->o
    for(int i = 0; i < m + 1; i++) {
        for(int j = 0; j < n + 1; j++) {
            for(int k = 0; k < o + 1; k++) {
                // matches with s1 & till both string becomes empty
                if(i > 0 && k > 0 && s1[i-1] == s3[k-1] ) {
                    // Check that prev cell is true?
                    t[i][j][k] = t[i][j][k] || t[i-1][j][k-1];
                }
                // matches with s2 & till both string becomes empty
                if(j > 0 && k > 0 && s2[j-1] == s3[k-1]) {
                    // Check that prev cell is true?
                    t[i][j][k] = t[i][j][k] || t[i][j-1][k-1];
                }
            }
        }
    }

    // Return the final ans 
    return  t[m][n][o];
}

// Bottom Up Approach Optimized: O(m * n)
bool isInterleave2D(string s1, string s2, string s3) {
    int m = s1.size();
    int n = s2.size();
    int o = s3.size();

    // Edge case 
    if(m + n != o) return false;

    // Declaration of 2D & initlization with false;
    vector<vector<bool>> t(m+1, vector<bool>(n+1, false));
    
    // Initialize first cell as true 
    t[0][0] = true;

    // Fill first row (when s1 empty, only s2 can match)
    for (int j = 1; j < n + 1; j++) {
        t[0][j] = t[0][j-1] && s2[j-1] == s3[j-1];
    }

    // Fill first col (when s2 empty, only s1 can match)
    for (int i = 1; i < m + 1; i++) {
        t[i][0] = t[i-1][0] && s1[i-1] == s3[i-1];
    }

    // Start filling, main table (k = i+j) , i -> m,j -> n
    for(int i = 0; i < m + 1; i++) {
        for(int j = 0; j < n + 1; j++) { 
            // s1 matches with s3 until both becomes empty 
            if(i > 0 && s1[i-1] == s3[i+j-1]) { 
                // Check that prev cell is true? 
                t[i][j] = t[i-1][j] || t[i][j];
            }

            // s2 matches with s3 until both becomes empty 
            if(j > 0 && s2[j-1] == s3[i+j-1]) {
                // Check that prev cell is true?
                t[i][j] = t[i][j-1] || t[i][j];
            }
        }
    }
    

    // Return the final ans 
    return  t[m][n];
}

int main(){
    string s1 = "ac";
    string s2 = "bd";

    string s3 = "abcd";

    // cout << (isInterleave(s1, s2, s3) ? "TRUE" : "FALSE") << endl;
    cout << (isInterleave2D(s1, s2, s3) ? "TRUE" : "FALSE") << endl;
    
    return 0;
}