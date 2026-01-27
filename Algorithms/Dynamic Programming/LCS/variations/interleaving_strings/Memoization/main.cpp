#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Interleaving Strings 
 * Problem: You are given three strings. 
 * s1, s2, and s3. 
 * 
 * IP: string s1, s2, s3; 
 * OP: Return true/false; 
 * 
 * APPROACH: Recursion + Memoize 
 * 
 * TC: O(m * n)
 * SC: O(m + n) + O(m * n) 
 * 
 * LEARNING: 
 *  - How to solve it with recursion
 *  - How to convert it into memoize approach 
 */
 
// Aliases 
using v = vector<int>;
using vv = vector<v>;

// Global vars 
string s1 = "aabcc";
string s2 = "dbbca";
string s3 = "aadbbcbcac";

int m = s1.length();
int n = s2.length();

// DP table 
vv t(m + 1, v(n + 1, -1)); // Initially, INIT with false 

// Interleaving Strings 
bool solve(int i, int j) { 
    // BC 
    if(i == m && j == n) return true; 
    
    // Presnet -> dp?
    if(t[i][j] != -1) return t[i][j];
    
    bool ans = false;
    
    // Choice diagram 
    // First match with s1 char
    if(i < m && s1[i] == s3[i+j]) {
        // go with i + 1 char
        ans = solve(i + 1, j);
    }
    
    // If not mathcing with s1, then go with s2 
    if(!ans && j < n && s2[j] == s3[i + j]) {
        // go with j + 1 char 
        ans = solve(i, j + 1);
    }
    ans = false; 
    return t[i][j] = ans; 
}

int main()
{
    cout << (solve(0, 0) ? "TRUE" : "FALSE") << endl;
    return 0;
}