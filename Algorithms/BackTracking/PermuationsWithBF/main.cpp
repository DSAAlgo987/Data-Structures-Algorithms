#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Generate all the permutations 
 * Bounding Function: Two consecutive letters should not be in alpha betical order
 * IP: String s = "ABC"
 * OP: Return all possible combinations which satifies bounding function 
 * {"ACB", "BAC", "CBA"}
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
void permutations(string res, int j) {
    // BC
    if(j == n) {
        // push res -> ans 
        ans.push_back(res);
        return;
    }
    
    // Scan through selected vector to select char.
    for(int i = 0; i < n; i++) {
        // IF that letter is not selected 
        if(selected[i] == false) {
            // Bounding function 
            if(j > 0 && s[i] - res[j-1] == 1) {
                continue; // skip that iteration bcoz letters are in alphabetical order 
            }
            
            // Other wise 
            res[j] = s[i];
            selected[i] = true;
            
            // call for other letters 
            permutations(res, j + 1);
            
            // When it backtracks
            selected[i] = false;
            
            
        }
    }
}


int main()
{
    string res(n, '\0');
    permutations(res, 0);
    
    // Display all those permuations 
    for(auto x: ans) {
        cout << x << " ";
    }
    return 0;
}