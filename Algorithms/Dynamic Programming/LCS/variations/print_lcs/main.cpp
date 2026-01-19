#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Print LCS (Longest Common Subsequence)
 *
 * Problem:
 *   Given two strings x and y, print their
 *   Longest Common Subsequence (LCS).
 *
 * IP:
 *   - string x
 *   - string y
 *
 * OP:
 *   - string → Longest Common Subsequence
 *
 * APPROACH:
 *   - Bottom Up Dynamic Programming (Tabulation)
 *   - Followed by backtracking on the DP table
 *
 * DP STATE:
 *   - t[i][j] → length of LCS between
 *               x[0..i-1] and y[0..j-1]
 *
 * BACKTRACKING LOGIC:
 *   - If characters match → include character and move diagonally
 *   - Else move in the direction of the larger DP value
 *     (up or left)
 *
 * TC:
 *   - O(n × m) → DP table computation
 *
 * SC:
 *   - O(n × m) → DP table storage
 *
 * LEARNING:
 *   - How to reconstruct solution from DP table
 *   - Importance of correct DP indexing
 *   - Difference between computing length vs printing sequence
 *   - Strategic backtracking decisions
 */


// Aliases 
using v = vector<int>; 
using vv = vector<v>;

// LCS Table 
void LCS(string &x, string &y, int m, int n, vv &t) { 
    // Start filling, i = 1, j = 1
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(x[i-1] == y[j-1]) {
                t[i][j] = 1 + t[i-1][j-1];
            } else { 
                t[i][j] = max(
                    t[i-1][j],
                    t[i][j-1]
                );
            }
        }
    }
}

// Print LCS
string printLCS(string &x, string &y) { 
    int m = x.size();
    int n = y.size(); 

    // Step 1: Compute LCS Table 
    vv t(m + 1, v(n + 1, 0)); // INIT with 0s initially 
    LCS(x, y, m, n, t);

    // Step 2: Find LCS chars with the help of computed LCS table 
    int i = m, j = n; 
    string s = "";

    while(i > 0 && j > 0) {
        // chars matches then move to the up diagonal cell 
        if(x[i-1] == y[j-1]) { 
            s.push_back(x[i-1]);
            i--; j--; 
        } else {
            // not matches
            if(t[i-1][j] > t[i][j-1]) { 
                i--; // move up 
            } else {
                j--; // move left
            }
        }
    }

    // Reverse the string s 
    reverse(s.begin(), s.end());
    return s; 
}

int main(){
    string x = "acbcf";
    string y = "abcdaf";

    cout << "LCS String: " << printLCS(x, y) << endl;
    
    return 0;
}