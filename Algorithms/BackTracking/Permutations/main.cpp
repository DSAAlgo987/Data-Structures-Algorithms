#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Generate all the permutations
 * IP: String s = "ABC"
 * OP: Return all possible combinations
 * {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"}
 * APPROACH: Backtracking
 * TC: O(n^n)
 * SC: O(n)
 */

string s = "ABC";
int n = s.length();
vector<string> ans;

// Select array for checking which letter is selected and which are not 
vector<bool> selected(n, false);

// Permuation function
void permutations(string res) {
    // BC
    if(res.length() == n) {
        // push res -> ans 
        ans.push_back(res);
        return;
    }
    
    // Scan through selected vector to select char.
    for(int i = 0; i < n; i++) {
        // IF that letter is not selected 
        if(selected[i] == false) {
            // add that letter -> res 
            res += s[i];
            // make that letter is selected(TRUE)
            selected[i] = true; 
            
            // Call for other letters
            permutations(res);
            
            // When it reaches to leaf node 
            // Remove that letter from res 
            res.pop_back();
            
            // Make selected letter as false bcoz it backtracks
            selected[i] = false;
            
            
        }
    }
}


int main()
{
    string res = "";
    permutations(res);
    
    // Display all those permuations 
    for(auto x: ans) {
        cout << x << " ";
    }
    return 0;
}