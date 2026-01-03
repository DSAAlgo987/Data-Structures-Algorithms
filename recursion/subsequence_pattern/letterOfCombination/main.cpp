#include <bits/stdc++.h>
using namespace std;

/**
 * PS: Letter of Combination
 * You are given a string str of digits from 2-9. You have to find all the possible letter combinations that the number could represent.
 * The mapping of digits to letters is given as follows:
 * 2 -> "abc"
 * 3 -> "def"
 * 4 -> "ghi"
 * 5 -> "jkl"
 * 6 -> "mno"
 * 7 -> "pqrs"
 * 8 -> "tuv"
 * 9 -> "wxyz"
 * Note: 1 does not map to any letters.
 * 
 * TC: O(4^n)
 * SC: O(n)
 * 
 * Example:
 * Input: str = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 */

// Aliases
using v = vector<string>;

v ans;

// Alphabet arr
v alpha = {
    "",
    "",
    "abc",
    "def",
    "ghi",
    "jkl",
    "mno",
    "pqrs",
    "tuv",
    "wxyz"
};

// Letter of combination function
void solve(string digit, int idx, int i, string s) {
    // BC 
    if(idx == digit.size()) {
        ans.push_back(s);
        return;
    }

    // convert string to int 
    int d = digit[idx] - '0';

    // Prunning condition 
    if(i >= alpha[d].size()) return;

    // Push letter to s 
    s.push_back(alpha[d][i]);

    // Again Recursive call
    solve(digit, idx + 1, 0, s);

    // When it reaches to leaf node then backtrack 
    // Then pop from s 
    s.pop_back();

    // Now call for i + 1
    solve(digit, idx, i + 1, s);
}

int main(){
    string digit = "34";
    string s = "";

    solve(digit, 0, 0, s);

    // Display ans 
    for(auto x: ans) {
        cout << x << " ";
    }
    
    return 0;
}