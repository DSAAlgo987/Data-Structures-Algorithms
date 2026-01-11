#include <bits/stdc++.h>
using namespace std; 

/**
 * PS: Word Break
 *
 * Problem:
 *   Given a string s and a dictionary of words,
 *   determine if s can be segmented into a sequence
 *   of dictionary words.
 *
 * IP:
 *   - string s
 *   - vector<string> wordDict
 *
 * OP:
 *   - true / false
 *
 * APPROACH:
 *   - Backtracking (DFS on string index)
 *   - At every index, try all possible cuts (substrings)
 *   - If a prefix exists in dictionary, recurse on remaining string
 *   - If any path reaches end of string → return true
 *
 * TC:
 *   - Exponential ~ O(2^n) (worst case)
 *
 * SC:
 *   - O(n)  (recursion stack)
 *
 * LEARNING:
 *   - String partitioning using backtracking
 *   - Difference between substring(find) search vs dictionary lookup(count)
 *   - unordered_set::count() -> O(1) bcoz it uses hash table internally 
 *       → returns 1 if word exists, else 0
 */

// Aliases 
using v = vector<string>;

// Global vars 
string s = "applepineapple";

v wordDict = {
    "apple"
};

unordered_set<string> dict = {"apple"};


// Word Break function 
bool solve(int p, string s) {
    // BC 
    if(p == s.size()) return true;

    string temp = "";

    // Backtracking Working: Iterate over each char 
    for(int i = p; i < s.size(); i++) {
        temp.push_back(s[i]);
        // Check it is present -> dict
        if(dict.count(temp)) {
            // Partition: (different paths): 
            // * Only True Recrusive will allowed if it false then it will go to line no 71 (false)
            if(solve(i + 1, s)) {
                return true;
            }
        }
    }

    return false; 
}


int main() {
    cout << (solve(0, s) ? "TRUE" : "FALSE") << endl;

    return 0;
}